
#include "sdk_unitest.h"
#include "Environment.h"
#include "memory.hpp"
int64  g_sta_groupid = 0;
int64  g_sta_workRoom = 0;
#ifdef SDK_FOR_ANDROID
volatile bool g_isExitAndriodRspThd = false;
void* g_handle = nullptr;
#endif
std::map<std::string, CommABInfo> sdkUniTest::m_mapSemper;
std::mutex sdkUniTest::m_mutex;
sdkUniTest::sdkUniTest() {
	m_waitUpdate = false;
	m_client = Tools::getServiceClient();
	//初始化客户端，需要传入版本号，mac,设备类型等必要信息
	AppInfo info;
	info.appVersion = "5.20.3";
	info.appName = "vstest";
#ifdef SDK_FOR_ANDROID
	info.verifyInfo.signature = "9B:D9:09:F3:A7:01:55:79:AD:26:BA:39:5F:93:6F:32:1B:17:B8:D1";
	info.deviceType = 2;
	info.mac = MAC_ADDRESS_PHONE;
	info.devMode = 0;//调试模式跳过校验
	info.deviceInfo = "mobile-android";
#else
	info.mac = MAC_ADDRESS;
	info.deviceInfo = "pc-h5-win:Windows 10#10.0.18363#zh-CN";
	info.deviceType = 3; //3就不会把手机和PC挤下来，本来是2
#endif
	info.verifyInfo.issuer = "Beijing VRV Software Corporation Limited.";
	info.netType = "wifi";
	info.mark = "comm";
	// 客户端使用前需要进行初始化，如初始化失败，不能调用后续方法。
	std::string strPath = Tools::GetModulePath();
	m_configPtr = CTestConfig::GetInstance(strPath);
	std::string configPath = strPath + "xmlconfig/config.xml";
	std::cout << "configPath=" << configPath << std::endl;
	m_configPtr->LoadConfig(configPath.c_str());
	std::cout << "init strPath=" << strPath << "g_Client=" << m_client.get() << std::endl;
	std::cout << "info.appname=" << info.appName << std::endl;
	int clientId = m_client->init(strPath, strPath + "linkdood.crt", info);
	m_configPtr->sdkId = clientId;
	if (clientId <= 0) {
		printf("init failed");
		exit(0);
	}
}
sdkUniTest::~sdkUniTest() {
#ifdef SDK_FOR_ANDROID
	//退出andriod线程
	g_isExitAndriodRspThd = true;
	if (nullptr != g_handle) {
		dlclose(g_handle);
		g_handle = nullptr;
	}
#endif
}
CommABInfo sdkUniTest::makeSemperUuid() {
	std::string uuid = Tools::getGUID();
	CommABInfo info;
	info.uuid = uuid;
	m_mapSemper[uuid] = info;
	return info;
}
CommABInfo sdkUniTest::getSemperUuid(const std::string&uuid){
	return m_mapSemper[uuid];
}
void sdkUniTest::initCallBack() {
	m_lddservice = EXTSERVICE();
	m_chatservice = CHATSERVICE();
	m_fileservice = FILESERVICE();
	m_configservice = CONFIGSERVICE();
	m_configservice->setMsgParserMode(true);
	m_chatservice->regMsgNoticeCb(SBind(&sdkUniTest::msgNotifyCallBack,this,std::placeholders::_1));
	m_lddservice->regEntUpdateFinishCb(SBind(&sdkUniTest::msgUpdateFinishCallBack, this, std::placeholders::_1));
}
void sdkUniTest::clearCllBack(){

	m_chatservice->regMsgNoticeCb(nullptr);
	m_lddservice->regEntUpdateFinishCb(nullptr);

	m_chatservice.reset();
	m_configservice.reset();
	m_lddservice.reset();
}
void sdkUniTest::msgNotifyCallBack(SSharedPtr<Msg> msg) {
	std::string uuid = Tools::prasonGUIDJson(msg->preDefined);
	if (!uuid.empty()) {
		std::unique_lock<std::mutex> locker(m_mutex);
		CommABInfo resp = sdkUniTest::getSemperUuid(uuid);
		resp.sendTime = msg->time;
		resp.RecvTime = Tools::get_mill_sec();
		resp.semer->post();
		if (nullptr != resp.semer) {
			delete resp.semer;
			resp.semer = nullptr;
		}
	}
}
void sdkUniTest::msgUpdateFinishCallBack(int code){
	if (1 == code && m_waitUpdate) {
	   m_reqProm.set_value(code);
	   m_waitUpdate = false;
	}
}
int sdkUniTest::loginByIndex(const int index) {
	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	std::string respjson = "";
	std::string account = ((1 == m_config->getAccountInfo(index).m_userType) ? "0086" + m_config->getAccountInfo(index).m_account : m_config->getAccountInfo(index).m_account);
	std::shared_ptr<IAuthService> authService = AUTHSERVICE();
	std::shared_ptr<IConfigService> configService = CONFIGSERVICE();
	m_waitUpdate = true;
	initCallBack();
#ifdef SDK_FOR_ANDROID
	configService->setDevelopmentMode(0);
#endif
	m_reqFut = m_reqProm.get_future();
	const std::string& pwd = m_config->getAccountInfo(index).m_loginPassword;
	const std::string& server = m_config->getAccountInfo(index).m_server;
	int8 userType = m_config->getAccountInfo(index).m_userType;

	authService->loginEx(account, pwd, server, userType, "", [&](int code, int64 userId, int64 locktime, const std::string& codepath) {
		cout << userId;
		reqProm.set_value(code);
	});
	int code = reqFut.get();
	m_reqFut.get();
	return code;
}
int sdkUniTest::loginOutByIndex(const int index) {
	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	std::shared_ptr<IAuthService> authService = AUTHSERVICE();

	authService->logout([&](int code) {
		reqProm.set_value(code);
	});
	int code = reqFut.get();
	return code;
}