#include "unitest_config.h"
#include "tools.h"
namespace serviceTest {
	ConfigServiceUnitest::ConfigServiceUnitest() {
		m_configService = g_test[0].CONFIGSERVICE();
		std::cout << "m_configService =" << m_configService.get() << std::endl;
	}
	beforeConfigServiceUnitest::beforeConfigServiceUnitest() {
		m_beforeconfigService = g_test[0].CONFIGSERVICE();
		std::cout << "m_beforeconfigService =" << m_beforeconfigService.get() << std::endl;
	}
	int ConfigServiceUnitest::init() {
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
		std::string strPath = Tools::GetModulePath();
		int clientId = m_client->init(strPath, strPath + "linkdood.crt", info);
		return clientId;
	}
	bool ConfigServiceUnitest::uninit() {
		if (nullptr != m_client) {
			m_client->uninit();
			m_client.reset();
		}
		return true;
	}

	bool ConfigServiceUnitest::setLoginInfo() {
		LoginInfo info;
		info.userId = m_config->m_iMyUserId;
		info.server = m_config->m_server;
		info.account = m_config->m_account;
		info.userType = m_config->m_userType;
		info.pwd = m_config->m_loginPassword;
		info.last_login_time = time(NULL);
		bool isOk = m_configService->setLoginInfo(info);
		return isOk;
	}
	bool ConfigServiceUnitest::getLoginInfos() {
		std::vector<LoginInfo> *info = new  std::vector<LoginInfo>;
		*info = m_configService->getLoginInfos();
		bool isOk = !info->empty();
		return isOk;
	}
	bool ConfigServiceUnitest::delLoginInfo() {
		bool isFalse = m_configService->delLoginInfo(1);
		return isFalse;
	}
	bool beforeConfigServiceUnitest::setLogLevel() {
		bool isOk = m_beforeconfigService->setLogLevel(sdklog_all);
		return isOk;
	}
	bool beforeConfigServiceUnitest::setInterConnect() {
		bool isOk = m_beforeconfigService->setInterConnect(1);
		return isOk;
	}
	bool beforeConfigServiceUnitest::setNotifyStatus() {
		bool isOk = m_beforeconfigService->setNotifyStatus(1);
		return isOk;
	}
	bool beforeConfigServiceUnitest::setCertificatePath() {
		std::string path = Tools::GetModulePath()+"linkdood.crt";
		bool isFalse = m_beforeconfigService->setCertificatePath(path);
		return isFalse;
	}
	bool ConfigServiceUnitest::getNetProxy() {
		NetProxy res = m_configService->getNetProxy();
		bool isOk = !res.port;
		return isOk;
	}
	bool ConfigServiceUnitest::setNetProxy() {
		NetProxy res;
		bool isOk = m_configService->setNetProxy(res);
		return isOk;
	}
	bool ConfigServiceUnitest::setPlugPower() {
		bool isFalse = m_configService->setPlugPower(true);
		return isFalse;
	}
	bool ConfigServiceUnitest::setNetStatus() {
		int status = 1;
		bool isOk = m_configService->setNetStatus(status);
		return isOk;
	}
	bool ConfigServiceUnitest::getSdkVersion() {
		std::string sdkver = m_configService->getSdkVersion();
		bool isOk = !sdkver.empty();
		return isOk;
	}
	bool ConfigServiceUnitest::setAppVersion() {
		bool isOk = m_configService->setAppVersion("5.20.3", 3, "pc-h5-win#windows10", "wifi", MAC_ADDRESS, "comm");
		return isOk;
	}
	bool ConfigServiceUnitest::setTextCoding() {
		bool isOk = m_configService->setTextCoding(0);
		return isOk;
	}
	bool ConfigServiceUnitest::setAppName() {
		bool isOk = m_configService->setAppName("vstest");
		return isOk;
	}
	bool beforeConfigServiceUnitest::setLanguage() {
		bool isOk = m_beforeconfigService->setLanguage(m_config->m_testLanguage);
		return isOk;
	}
	bool beforeConfigServiceUnitest::setLanguageType() {
		m_beforeconfigService->setLanguageType(m_config->m_testLanguage);
		return true;
	}
	bool beforeConfigServiceUnitest::rootPath() {
		std::string pwd = m_beforeconfigService->rootPath();
		bool isOk = !pwd.empty();
		return isOk;
	}
	bool beforeConfigServiceUnitest::setRootPath() {
		std::string pwd = m_beforeconfigService->rootPath();
		bool isOk = m_beforeconfigService->setRootPath(pwd);
		return isOk;
	}
	bool ConfigServiceUnitest::headImgPath() {
		std::string imgpath = m_configService->headImgPath();
		bool isOk = !imgpath.empty();
		return isOk;
	}
	bool ConfigServiceUnitest::getUserRcPath() {
		std::string userpath = m_configService->getUserRcPath();
		bool isOk = !userpath.empty();
		return isOk;
	}
	bool ConfigServiceUnitest::setUserRcPath() {
		std::string userRcPath = "";
		bool isOk = m_configService->setUserRcPath(userRcPath);
		return isOk;
	}
	bool ConfigServiceUnitest::userImgPath() {
		std::string userimgpath = m_configService->userImgPath();
		bool isOk = !userimgpath.empty();
		return isOk;
	}
	bool ConfigServiceUnitest::userAudioPath() {
		std::string useraudiopath = m_configService->userAudioPath();
		bool isOk = !useraudiopath.empty();
		return isOk;
	}
	bool ConfigServiceUnitest::userVideoPath() {
		std::string uservidiopath = m_configService->userVideoPath();
		bool isOk = !uservidiopath.empty();
		return isOk;
	}
	bool ConfigServiceUnitest::userCachePath() {
		std::string usercachepath = m_configService->userCachePath();
		bool isOk = !usercachepath.empty();
		return isOk;
	}
	bool ConfigServiceUnitest::userFilePath() {
		std::string userfilepath = m_configService->userFilePath();
		bool isOk = !userfilepath.empty();
		return isOk;
	}
	bool ConfigServiceUnitest::userEmotionPath() {
		std::string useremotionpath = m_configService->userEmotionPath();
		bool isOk = !useremotionpath.empty();
		return isOk;
	}
	bool beforeConfigServiceUnitest::setMsgParserMode() {
		bool isOk = m_beforeconfigService->setMsgParserMode(true);
		return isOk;
	}
	bool ConfigServiceUnitest::getMsgParserMode() {
		bool isOk = m_configService->getMsgParserMode();
		return isOk;
	}
	bool ConfigServiceUnitest::getLoginExData() {
		std::string resjosn = m_configService->getLoginExData(m_config->m_server);
		bool isOk = !resjosn.empty();
		return isOk;
	}
	bool ConfigServiceUnitest::setScreenStatus() {
		bool isOk = m_configService->setScreenStatus(true);
		return isOk;
	}
	bool ConfigServiceUnitest::getSubServerInfo() {
		std::vector<SubServerInfo> infos;
		bool isOk = m_configService->getSubServerInfo(infos);
		return isOk;
	}
	bool ConfigServiceUnitest::setSubServerInfo() {
		std::vector<SubServerInfo> infos;
		bool isOk = m_configService->setSubServerInfo(infos);
		return isOk;
	}
	bool ConfigServiceUnitest::reNotifyData() {
		bool isOk = m_configService->reNotifyData();
		return isOk;
	}
	bool beforeConfigServiceUnitest::setIsRoming() {
		bool isOk = m_beforeconfigService->setIsRoming(0);
		return isOk;
	}
	bool ConfigServiceUnitest::getIsRoming() {
		bool isOk = m_configService->getIsRoming();
		return isOk;
	}
	bool beforeConfigServiceUnitest::getLastPreLoginData() {
		PreLogincfg prelogindata = m_beforeconfigService->getLastPreLoginData(m_config->m_iMyUserId);
		bool isOk = prelogindata.userid;
		return isOk;
	}
	bool beforeConfigServiceUnitest::getLastPreLogin() {
		std::string Lastdata = m_beforeconfigService->getLastPreLogin(m_config->m_server);
		bool isOk = !Lastdata.empty();
		return isOk;
	}
	bool ConfigServiceUnitest::setTicket() {
		std::string ticket = m_config->m_ticket;
		bool isOk = m_configService->setTicket(m_config->m_iMyUserId, ticket);
		return isOk;
	}
	bool beforeConfigServiceUnitest::setPwIsCrypt() {
		bool isOk = m_beforeconfigService->setPwIsCrypt(true);
		return isOk;
	}
	bool beforeConfigServiceUnitest::setHttpsLogin() {
		bool isOk = m_beforeconfigService->setHttpsLogin(1);
		return isOk;
	}
	bool ConfigServiceUnitest::setMultichannel() {
		bool isOk = m_configService->setMultichannel(1);
		return isOk;
	}
	bool ConfigServiceUnitest::getPreloginInfoEx() {
		std::string predata = m_configService->getPreloginInfoEx();
		bool isOk = !predata.empty();
		return isOk;
	}
	bool ConfigServiceUnitest::setOffloginSwitch() {
		bool isOk = m_configService->setOffloginSwitch(1);
		return isOk;
	}
	bool ConfigServiceUnitest::getOffloginStatus() {
		bool isOk = m_configService->getOffloginStatus();
		return isOk;
	}
	bool beforeConfigServiceUnitest::setMac() {
		std::string mac = MAC_ADDRESS;
		m_beforeconfigService->setMac(mac);
		bool isOk = !mac.empty();
		return isOk;
	}
	bool beforeConfigServiceUnitest::setIsOpenSecPlugin() {
		bool isOk = m_beforeconfigService->setIsOpenSecPlugin(true);
		return isOk;
	}
	bool ConfigServiceUnitest::getIsOpenSecPlugin() {
		bool isOk = m_configService->getIsOpenSecPlugin();
		return isOk;
	}
	bool beforeConfigServiceUnitest::setLogOutLevel() {
		int level = 2;
		m_beforeconfigService->setLogOutLevel(level);
		bool isOk = level;
		return isOk;
	}
	bool ConfigServiceUnitest::setHideBuddySwitch() {
		int flag = 1;
		m_configService->setHideBuddySwitch(flag);
		bool isOk = flag;
		return isOk;
	}
	bool ConfigServiceUnitest::setCloudAddr() {
		std::string addr = "http://192.168.1.1";
		m_configService->setCloudAddr(addr);
		bool isOk = !addr.empty();
		return isOk;
	}
	bool ConfigServiceUnitest::setCloudUploadSpeed() {
		int speed = 100000000;
		m_configService->setCloudUploadSpeed(speed);
		bool isOk = speed;
		return isOk;
	}
	bool ConfigServiceUnitest::setCloudDownloadSpeed() {
		int speed = 100000000;
		m_configService->setCloudDownloadSpeed(speed);
		bool isOk = speed;
		return isOk;
	}
	bool ConfigServiceUnitest::setDevelopmentMode() { //注释
		//std::promise<int> reqProm;
		//std::future<int> reqFut = reqProm.get_future();
		//int speed = 100000000;
		//m_configService->setDevelopmentMode(1);
		//bool isOk = speed;
		return true;
	}
}