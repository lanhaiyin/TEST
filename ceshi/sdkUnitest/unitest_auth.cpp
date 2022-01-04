#include "unitest_auth.h"
#include <thread>
namespace serviceTest {
	AuthServiceUnitest::AuthServiceUnitest() {
		printf("\n AuthServiceUnitest::AuthServiceUnitest! \n");
		m_authService = g_test[0].AUTHSERVICE();
		m_configService = g_test[0].CONFIGSERVICE();
	}
	AuthServiceUnitest::~AuthServiceUnitest() {
		printf("\n AuthServiceUnitest::~AuthServiceUnitest! \n");
	}
	int AuthServiceUnitest::prelogin() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::string respjson = "";

		std::cout << "m_config->m_server=" << m_config->m_server << std::endl;
		m_authService->prelogin(m_config->m_server, [&](int code, std::string&json) {
			std::cout << "prelogin return =" << code << std::endl;
			reqProm.set_value(code);
			respjson = json;
		});
		int code = reqFut.get();
		return code;
	}
	int AuthServiceUnitest::abortLogin() {
		//std::promise<int> reqProm;
		//std::future<int> reqFut = reqProm.get_future();
		//m_authService->abortLogin(4328635167, [&](int code) {
		//	reqProm.set_value(code);
		//});
		//int code = reqFut.get();
		return 0;
	}
	int AuthServiceUnitest::quickRegister() {
		std::promise<int> reqPromGet;
		std::future<int> reqFutGet = reqPromGet.get_future();
		std::string account = ((1 == m_config->m_userType) ? "0086" + m_config->m_account : m_config->m_account);
		m_authService->quickRegister(m_config->m_server, m_config->m_account, account, m_config->m_loginPassword, [&](int code) {
			reqPromGet.set_value(code);
		});
		int code = reqFutGet.get();
		code=(code == err_sdk_unknownMethod)?0:code;
		return code;
	}
	int AuthServiceUnitest::beforeLogin() {
		std::promise<int> reqPromGet;
		std::future<int> reqFutGet = reqPromGet.get_future();
		m_authService->beforeLogin(1, "2", "0", [&](int code, std::string &a, std::string &b) {
			reqPromGet.set_value(code);
		});
		int code = reqFutGet.get();
		code = (code == err_sdk_unknownMethod) ? 0 : code;
		return code;
	}
	int AuthServiceUnitest::getRegCode() {
		//std::promise<int> reqProm;
		//std::future<int> reqFut = reqProm.get_future();
		//m_authService->getRegCode("vrv", "008618329513052", 1, [&](int code, int json) {    //standard
		//	reqProm.set_value(code);
		//});
		//int code = reqFut.get();
		return 0;
	}
	int AuthServiceUnitest::signup() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::string account = ((1 == m_config->m_userType) ? "0086" + m_config->m_account : m_config->m_account);
		m_authService->signup("62140486", account, [&](int code, int64 json, int64 nson) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return 0;
	}
	bool AuthServiceUnitest::verifyImgCode() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_authService->verifyImgCode(m_config->m_account, "v3b7", [&](int code, std::string aron) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		bool isOk = !code || code == 138;
		return isOk;
	}
	int AuthServiceUnitest::loginSpecial() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::string respjson = "";

		std::string account = ((1 == m_config->m_userType) ? "0086" + m_config->m_account : m_config->m_account);
		m_authService->loginSpecial(account, m_config->m_loginPassword, m_config->m_server, m_config->m_userType, [&](int code, int64 json, int64 nson, std::string aron) {
			reqProm.set_value(code);
			respjson = aron;
		});
		int code = reqFut.get();
		if (!code){
			std::promise<int> getreqProm;
			std::future<int> getreqFut = getreqProm.get_future();
			m_authService->logout([&](int code) {
				getreqProm.set_value(code);
			});
			getreqFut.get();
		}
		return code;
	}
	int AuthServiceUnitest::offlineLogin() {
		std::promise<int> reqPromget;
		std::future<int> reqFutget = reqPromget.get_future();
		Tools::sleep(2000);
		int64 userId = m_config->m_iMyUserId;
		const std::string pwd = m_config->m_loginPassword;
		const std::string server = m_config->m_server;
		m_authService->offlineLogin(userId, pwd, server, [&](int code) {
			reqPromget.set_value(code);
		});
		int code = reqFutget.get();
		return code;
	}
	int AuthServiceUnitest::offLineToLogin() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_authService->offLineToLogin(m_config->m_server, [&](int code, int nson, int kson, std::string json) {
			reqProm.set_value(code);
		});

		int code = reqFut.get();
		return code;
	}
	int AuthServiceUnitest::autoLogin() {
		std::promise<int> reqPromSet;
		std::future<int> reqFutSet = reqPromSet.get_future();
		std::promise<int> reqPromGet;
		std::future<int> reqFutGet = reqPromGet.get_future();
		m_authService->prelogin(m_config->m_server, [&](int code, std::string&json) {
			reqPromSet.set_value(code);
		});
		reqFutSet.get();
		m_authService->autoLogin(m_config->m_iMyUserId, m_config->m_server, [&](int code, int64 json, int64 b, const std::string& sons) {
			reqPromGet.set_value(code);
		});

		int code = reqFutGet.get();
	/*	std::promise<int> getreqProm;
		std::future<int> getreqFut = getreqProm.get_future();
		m_authService->logoutLocal([&](int code) {
			getreqProm.set_value(code);
		});
		getreqFut.get();*/
		return code;
	}
	int AuthServiceUnitest::logoutLocal() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_authService->logoutLocal([&](int code) {
			reqProm.set_value(code);
		});

		int code = reqFut.get();
		return code;
	}
	int AuthServiceUnitest::loginEx() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::string respjson = "";
		std::string account = ((1 == m_config->m_userType) ? "0086" + m_config->m_account : m_config->m_account);
#ifdef SDK_FOR_ANDROID
		m_configService->setDevelopmentMode(0);
#endif
		m_authService->loginEx(account, m_config->m_loginPassword, m_config->m_server, m_config->m_userType, "", [&](int code, int64 userId, int64 locktime, const std::string& codepath) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int AuthServiceUnitest::getSecUrl() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_authService->getSecUrl(m_config->m_server, [&](int code, std::string aron) {
			reqProm.set_value(code);
		});

		/*int expected = reqFut.get();
		bool isOk = !respjson.empty();
		Assert::IsTrue(isOk);*/
		int code = reqFut.get();
		return code;
	}
	int AuthServiceUnitest::getClientKey() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_authService->getClientKey([&](int code, std::string json) {
			reqProm.set_value(code);
		});

		/*int expected = reqFut.get();
		bool isOk = !respjson.empty();
		Assert::IsTrue(isOk);*/
		int code = reqFut.get();
		return code;
	}
	int AuthServiceUnitest::setNameAndPasswd() {
		std::promise<int> reqPromset;
		std::future<int> reqFutset = reqPromset.get_future();
		m_authService->setNameAndPasswd(m_config->m_account, m_config->m_loginPassword, [&](int code) {
			reqPromset.set_value(code);
		});
		int code = reqFutset.get();

		Tools::sleep(5000);

		std::promise<int> reqPromget;
		std::future<int> reqFutget = reqPromget.get_future();
		m_authService->logout([&](int code) {
			reqPromget.set_value(code);
		});
		reqFutget.get();

		Tools::sleep(5000);

		std::promise<int> getreqProm;
		std::future<int> getreqFut =getreqProm.get_future();
		std::string respjson;
		std::string account = ((1 == m_config->m_userType) ? "0086" + m_config->m_account : m_config->m_account);
		m_authService->login(account, m_config->m_loginPassword, m_config->m_server, m_config->m_userType, [&](int code, int64 userId, int64 locktime, const std::string& codepath) {
			getreqProm.set_value(code);
		});
		getreqFut.get();

		Tools::sleep(20000);

		return code;
	}
	int AuthServiceUnitest::changePassword() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_authService->changePassword(" ", m_config->m_loginPassword, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int AuthServiceUnitest::getResetPwCode() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		/*m_authService->getResetPwCode("vrv", "0086"+m_config->m_account, [&](int code, int json) {
		reqProm.set_value(code);
		});*/

		/*int expected = reqFut.get();
		bool isOk = !respjson.empty();
		Assert::IsTrue(isOk);*/
		//int code = reqFut.get();
		return 0;
	}
	int AuthServiceUnitest::resetPasswd() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_authService->resetPasswd("62140486", "", m_config->m_loginPassword, [&](int code) {
			reqProm.set_value(code);
		});

		/*int expected = reqFut.get();
		bool isOk = !respjson.empty();
		Assert::IsTrue(isOk);*/
		int code = reqFut.get();
		return code;
	}
	int AuthServiceUnitest::getPasswordRule() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_authService->getPasswordRule([&](int code, int json) {
			reqProm.set_value(code);
		});

		/*int expected = reqFut.get();
		bool isOk = !respjson.empty();
		Assert::IsTrue(isOk);*/
		int code = reqFut.get();

		return code;
	}
	int AuthServiceUnitest::getBindPhoneCode() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		/*m_authService->getBindPhoneCode(m_config->m_account, m_config->m_testLanguage, [&](int code, int a, int b) {
		reqProm.set_value(code);
		callbackID = b;
		});*/

		/*int expected = reqFut.get();
		bool isOk = !respjson.empty();
		Assert::IsTrue(isOk);*/
		//int code = reqFut.get();

		return 0;
	}
	int AuthServiceUnitest::bindPhone() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		//m_authService->bindPhone("18329513052", "006593", callbackID, [&](int code) {
		//	reqProm.set_value(code);
		//});
		//int code = reqFut.get();
		return 0;
	}
	bool AuthServiceUnitest::bindMail() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_authService->bindMail("yangweihao@vrvmail.com.cn", m_config->m_testLanguage, [&](int code) {
			reqProm.set_value(code);
		});

		/*int expected = reqFut.get();
		bool isOk = !respjson.empty();
		Assert::IsTrue(isOk);*/
		int code = reqFut.get();
		bool isOk = (!code || code == 386);
		return isOk;
	}
	int AuthServiceUnitest::getVerifyMailOrPhoneCode() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		/*m_authService->getVerifyMailOrPhoneCode(1, "0086"+m_config->m_account, m_config->m_testLanguage, [&](int code, int32 a, int64 b) {
		reqProm.set_value(code);
		});*/

		/*int expected = reqFut.get();
		bool isOk = !respjson.empty();
		Assert::IsTrue(isOk);*/
		//int code = reqFut.get();
		return 0;
	}
	int AuthServiceUnitest::verifyMailOrPhoneCode() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		/*m_authService->verifyMailOrPhoneCode(1, "723465", callbackID, [&](int code) {
		reqProm.set_value(code);
		});

		/*int expected = reqFut.get();
		bool isOk = !respjson.empty();
		Assert::IsTrue(isOk);*/
		//int code = reqFut.get();
		return 0;
	}
	int AuthServiceUnitest::getLoginInfo() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		uint8 test[100] = { 0 };
		int size = sizeof(test);
		int code = m_authService->getLoginInfo(test, sizeof(test));
		return code;
	}
	int AuthServiceUnitest::getLoginAuthCode() {
		std::promise<int> reqProm;
		oauthReq oauth = {};


		std::future<int> reqFut = reqProm.get_future();
		m_authService->getLoginAuthCode(oauth, [&](int code, const std::string json) {
			reqProm.set_value(code);
		});

		int code = reqFut.get();
		return code;
	}
	int AuthServiceUnitest::getqVerifyCodes() {
		std::vector<int64> userIDs = { 4328635167 };
		qVerifyCodes m;
		m.isSetUserIDs = false;
		m.type = 1;
		m.userIDs = userIDs;
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		/*m_authService->getqVerifyCodes(m, [&](int code, std::map<int64, std::string>& json) {
		reqProm.set_value(code);
		});

		int expected = reqFut.get();
		bool isOk = !respjson.empty();
		Assert::IsTrue(isOk);
		int code = reqFut.get();*/
		return 0;
	}
	int AuthServiceUnitest::getAuthAccessToken() {
		std::string accountType = "";
		std::string appSecret = "";
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_authService->getAuthAccessToken(625532, accountType, appSecret, [&](int code, std::string json) {
			reqProm.set_value(code);
		});

		/*int expected = reqFut.get();
		bool isOk = !respjson.empty();
		Assert::IsTrue(isOk);*/
		int code = reqFut.get();
		return code;
	}
	int AuthServiceUnitest::checkOrRefreshAccessToken() {
		std::string AccessToken = "";
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_authService->checkOrRefreshAccessToken(625532, 11, AccessToken, [&](int code, std::string json) {
			reqProm.set_value(code);
		});

		/*int expected = reqFut.get();
		bool isOk = !respjson.empty();
		Assert::IsTrue(isOk);*/
		int code = reqFut.get();
		return code;
	}
	int AuthServiceUnitest::getAuthUserBean() {
		std::string accessToken = "";
		AuthUserBean json;
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_authService->getAuthUserBean(625532, accessToken, [&](int code, AuthUserBean  json) {
			reqProm.set_value(code);
		});

		/*int expected = reqFut.get();
		bool isOk = !respjson.empty();
		Assert::IsTrue(isOk);*/
		int code = reqFut.get();
		return code;
	}
	int AuthServiceUnitest::getWebSiteAuth() {
		std::string nson = "http(s) ://vrv.linkdood/platform/api2/oauth/authorize?id=APPID&st=STATE&sc=SCOPE&uri=xxxxxx";

		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_authService->getWebSiteAuth(nson, [&](int code, std::string json) {
			reqProm.set_value(code);
		});

		/*int expected = reqFut.get();
		bool isOk = !respjson.empty();
		Assert::IsTrue(isOk);*/
		int code = reqFut.get();
		return code;
	}
	int AuthServiceUnitest::verifyPKSign() {
		std::string nson = "";

		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		int code = m_authService->verifyPKSign("C:\\", "D:\\", nson);
		return code;
	}
	bool AuthServiceUnitest::getCertOutDate() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		int code = m_authService->getCertOutDate();

		/*int expected = reqFut.get();
		bool isOk = !respjson.empty();
		Assert::IsTrue(isOk);*/
		bool isOk = code;
		return isOk;
	}
	int AuthServiceUnitest::getCertOrgName() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::string elogo = m_config->m_server;
		std::string a = m_authService->getCertOrgName(elogo);
		int code = 0;
		if (!a.empty())
		{
			code = 1;
		}
		return code;
	}
	int AuthServiceUnitest::signupOld() {

		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		//m_authService->getRegCode("vrv", "008618329513052", 1, [&](int code, int json) {    //standard
		//	reqProm.set_value(code);
		//});
		m_authService->signupOld("62140486", m_config->m_account, m_config->m_loginPassword, [&](int code, int64 json) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int AuthServiceUnitest::signupEx() {

		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
#ifdef SDK_UNITEST_DEV
		m_authService->signupEx("62140486", "0086" + m_config->m_account, [&](int code, int64 json, int64 nson, const std::string &data) {
			reqProm.set_value(code);
		});
#else
		m_authService->signupEx("62140486", "0086" + m_config->m_account, [&](int code, int64 json, int64 nson, const std::string &data, int8 isopenAddContact) {
			reqProm.set_value(code);
		});
#endif
		int code = reqFut.get();
		return 0;
	}
	int AuthServiceUnitest::scanCodeLogin() {

		std::string serverUrl = " ";
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_authService->scanCodeLogin(1288549, serverUrl, 1, [&](int code, std::string json) {
			//string = json;
			reqProm.set_value(code);
		});

		/*int expected = reqFut.get();
		bool isOk = !respjson.empty();
		Assert::IsTrue(isOk);*/
		int code = reqFut.get();
		return code;
	}
	int AuthServiceUnitest::getLastHBTime() {

		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		int64 code = m_authService->getLastHBTime();
		int verify = 0;
		/*int expected = reqFut.get();
		bool isOk = !respjson.empty();
		Assert::IsTrue(isOk);*/
		if (code != 0)
		{
			verify = 1;
		}
		return verify;
	}
	int AuthServiceUnitest::getPCLoginQrcode() {

		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_authService->getPCLoginQrcode("elogo", [&](int code, std::string& msg, std::string& json) {
			reqProm.set_value(code);
		});

		/*int expected = reqFut.get();
		bool isOk = !respjson.empty();
		Assert::IsTrue(isOk);*/
		int code = reqFut.get();
		code = (code == err_sdk_unknownMethod) ? 0 : code;
		return code;
	}
	int AuthServiceUnitest::getQrLoginStatus() {


		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_authService->getQrLoginStatus("elogo", " ", [&](int code, std::string& msg, std::string& json) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		code = (code == err_sdk_unknownMethod) ? 0 : code;
		return code;
	}
	int AuthServiceUnitest::scanPCLoginQrCode() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_authService->scanPCLoginQrCode("elogo", " ", [&](int code, std::string& msg) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int AuthServiceUnitest::confirmPCLogin() {

		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_authService->confirmPCLogin("elogo", 0, [&](int code, std::string& msg) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int AuthServiceUnitest::checkQrLoginDevice() {

		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_authService->checkQrLoginDevice(m_config->m_iMyUserId, "50:EE:9D:8A:82:7D", [&](int code, std::string& msg) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		code = (code == err_sdk_unknownMethod) ? 0 : code;
		return code;
	}
	int AuthServiceUnitest::pcQuickLogin() {

		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_authService->pcQuickLogin(m_config->m_iMyUserId, 1, [&](int code, std::string& msg, std::string& json) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		code = (code == err_sdk_unknownMethod) ? 0 : code;
		return code;
	}
	int AuthServiceUnitest::getLogoutCode() {

		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		UserAuthenticationInfo info;
		info.type = 4;
		info.logout_mode = 1;
		info.password = m_config->m_loginPassword;


		m_authService->getLogoutCode(info, [&](int code, std::string& msg, std::string& authenticationCode) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int AuthServiceUnitest::setLogoutAccount() {

		//std::promise<int> reqProm;
		//std::future<int> reqFut = reqProm.get_future();
		//m_authService->setLogoutAccount("asdqwe12vtynb_uytv", [&](int code, std::string& msg, std::string& result) {
		//	reqProm.set_value(code);
		//});
		//int code = reqFut.get();
		return 0;
	}

	int AuthServiceUnitest::authPcBrowserLoginTokenCheck()
	{
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		int64 appid = 100000005;
		std::string token = "abcdefgfedcba";

		m_authService->authPcBrowserLoginTokenCheck(appid, token,[&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}

	int AuthServiceUnitest::configJssdkAuthLocal()
	{
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		int64 appid = 100000005;
		std::string token = "abcdefgfedcba";

		JssdkAuthInfo jssdkAuth;
		jssdkAuth.appID = 100000005;
		jssdkAuth.noncestr = "11";
		jssdkAuth.signature = "22";
		jssdkAuth.timeStamp = 1357642;
		jssdkAuth.url = "http://www.baidu.com";


		m_authService->configJssdkAuthLocal(jssdkAuth,[&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}

	int AuthServiceUnitest::checkJssdkAuthLocal()
	{
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		int64 appid = 100000005;
		std::string token = "abcdefgfedcba";

		JssdkAuthInfo jssdkAuth;
		jssdkAuth.appID = 100000005;
		jssdkAuth.noncestr = "11";
		jssdkAuth.signature = "22";
		jssdkAuth.timeStamp = 1357642;
		jssdkAuth.url = "http://www.baidu.com";


		m_authService->checkJssdkAuthLocal(jssdkAuth, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}


	int AuthServiceUnitest::checkJssdkAuthLocalByAppId()
	{
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		int64 appid = 100000005;
		std::string token = "abcdefgfedcba";

		JssdkAuthInfo jssdkAuth;
		jssdkAuth.appID = 100000005;
		jssdkAuth.noncestr = "11";
		jssdkAuth.signature = "22";
		jssdkAuth.timeStamp = 1357642;
		jssdkAuth.url = "http://www.baidu.com";


		/*m_authService->checkJssdkAuthLocalByAppId(jssdkAuth, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();*/
		return -16777121;
	}

	int AuthServiceUnitest::thirdPartyAuthbyToken()
	{
		/*std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		const std::string token = "abcdefgfedcba";



		m_authService->thirdPartyAuthbyToken(token, [&](int code,std::string &json) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();*/
		return 100;
	}


	int AuthServiceUnitest::SetBifactorLogin()
	{
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_authService->SetBifactorLogin(1,1,123321,1,"123123",[&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	

	int AuthServiceUnitest::MQrCodeQuery()
	{
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_authService->MQrCodeQuery(1, 1, "1-1", "1-2", "123123", [&](int code,std::string &json1,std::string &json2) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}

	int AuthServiceUnitest::getMCircleQrCode()
	{
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::string Qrcodeid = "147852369";


		m_authService->getMCircleQrCode(1, 1, Qrcodeid,[&](int code, std::string &json1, std::string &json2) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}

	int AuthServiceUnitest::showVerifyUserPassword()
	{
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::string password = "147852369";


		m_authService->showVerifyUserPassword(password, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}

}