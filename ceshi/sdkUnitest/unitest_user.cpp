#include "unitest_user.h"
namespace serviceTest {
	UserServiceUnitest::UserServiceUnitest() {
		m_userService = g_test[0].USERSERVICE();
		m_AuthService = g_test[0].AUTHSERVICE();
	}

	int UserServiceUnitest::getAccountInfo() {
		//******************��ȡ�˻���Ϣ��ͬ���ӿ�**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		Account  info;
		info.birthday = 19960115;
		m_userService->getAccountInfo(info);
		return m_config->m_iMyUserId==info.id.value()?0:1;
	}

	int UserServiceUnitest::updateAccountInfo() {
		//******************�����û���Ϣ**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		Account  user = {};

		m_userService->updateAccountInfo(user, [&](int code) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::setSetting() {
		//******************�����˺�������**************
		std::promise<int> reqProm;							/*type = 1: �����Ƿ���ʾ������Ϣ flag : 0��ʾ 1����ʾ Ĭ��0
															*  type = 3 : ���ö����Ų��� flag : 0���� 1������ Ĭ��0
															*  type = 4 : �����ֻ��Ų��� flag : 0���� 1������ Ĭ��0
															*  type = 5 : ��������Ų��� flag : 0���� 1������ Ĭ��0
															*  type = 6 : ���÷������   flag : 0��ʾ���� 1����ʾ���� Ĭ��0
															*  type = 7 : ����Ϣ֪ͨ�Ƿ����� flag : 0���� 1������ Ĭ��0
															*  type = 12 : ���������Ϣ֪ͨ�Ƿ����� flag : 0��ʼ����ʾ 1ʼ����ʾ Ĭ��0
															*  type = 13 : ���������V�����ʼ������ flag : 0��ʼ����ʾ 1ʼ����ʾ Ĭ��0
															*  type = 14 : �������������@�����ʼ������ flag : 0��ʼ����ʾ 1ʼ����ʾ Ĭ��0
															*  type = 20 : ���������Ѳ��� flag : 0���� 1������ Ĭ��0
															*  type = 22 : �����ǳƲ��� flag : 0���� 1������ Ĭ��0   */
		std::future<int> reqFut = reqProm.get_future();


		m_userService->setSetting(0, 1, [&](int code) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getSetting() {
		//******************��ȡ�˺�������**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_userService->getSetting(1, [&](int code, model::UserSetting &user) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getHiddenTarget() {
		//******************ͨ�������ȡ���ض���(���ѻ�Ⱥ)**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_userService->getHiddenTarget(m_config->m_loginPassword, [&](int code, std::vector<int64> a, bool b) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::setHiddenTarget() {
		//******************�������ض���(���ѻ�Ⱥ)**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::vector<int64> a = { m_config->m_testFriendUserId2 };

		m_userService->setHiddenTarget(m_config->m_loginPassword, a, [&](int code) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::delHiddenTarget() {
		//******************ɾ�����ض���(���ѻ�Ⱥ)**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::vector<int64> a = { m_config->m_testFriendUserId2 };

		m_userService->delHiddenTarget(m_config->m_loginPassword, a, [&](int code) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	bool UserServiceUnitest::changeHiddenPasswd() {
		//******************������������**************
		std::promise<int> reqPromSet;
		std::future<int> reqFutSet = reqPromSet.get_future();
		std::promise<int> reqPromGet;
		std::future<int> reqFutGet = reqPromGet.get_future();
		std::vector<int64> a = { m_config->m_testFriendUserId2 };

		m_userService->setHiddenTarget(m_config->m_loginPassword, a, [&](int code) {
			reqPromSet.set_value(code);

		});
		reqFutSet.get();
		m_userService->changeHiddenPasswd(m_config->m_loginPassword, m_config->m_loginPassword, [&](int code) {
			reqPromGet.set_value(code);

		});


		int code = reqFutGet.get();
		bool isOk = (code == 0 || code == 1);
		return isOk;
	}

	int UserServiceUnitest::getGlobalNoDisturbMode() {
		//******************��ȡȫ������ģʽ���ɰ棩**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->getGlobalNoDisturbMode([&](int code, int32 a, int32 b, bool c) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::setGolbalNoDisturbMode() {
		//******************����ȫ������ģʽ���ɰ棩**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_userService->setGolbalNoDisturbMode(8, 12, 1, [&](int code) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getGlobalNoDisturbListMode() {
		//******************��ȡȫ������ģʽ(�°�)**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_userService->getGlobalNoDisturbListMode([&](int code, std::vector<globalNoDisturbModeInfo> a) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::setGolbalNoDisturbListMode() {
		//******************����ȫ������ģʽ(�°�)**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::vector<globalNoDisturbModeInfo> items = {};

		m_userService->setGolbalNoDisturbListMode(items, [&](int code) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getUserNoDisturbMode() {
		//******************��ȡ���Ŀ���û�������ģʽ**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->getUserNoDisturbMode(00630045, [&](int code, int64 a, int8 b) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::setUserNoDisturbMode() {
		//******************�������Ŀ���û�������ģʽ**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_userService->setUserNoDisturbMode(m_config->m_testFriendUserId2, 1, [&](int code) {
			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getMsgNotifyMode() {
		//******************��ȡ���Ŀ����Ϣ��֪ͨģʽ**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->getMsgNotifyMode(00630045, [&](int code, int64 a, int8 b) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::setMsgNotifyMode() {
		//******************�������Ŀ����Ϣ��֪ͨģʽ**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->setMsgNotifyMode(m_config->m_testFriendUserId2, 1, [&](int code) {
			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getServerTime() {
		//******************��ȡ������ʱ��**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->getServerTime([&](int code, int64 time) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	bool UserServiceUnitest::getServerTimeSync() {
		//******************��ȡ������ʱ��(ͬ���ӿ�)**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		int64 serverTime = 8;

		bool code = m_userService->getServerTimeSync(serverTime);
		return code;
	}

	bool UserServiceUnitest::addLocalSetting() {
		//******************���ӱ������ã��Լ�ֵ�Է�ʽ����**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		LocalSetting localset;
		localset.key = " ";
		localset.val = " ";


		std::vector<LocalSetting> items = { localset };

		m_userService->addLocalSetting(items, [&](int code) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();

		bool isOk = (code == 0 || code == -16777150);
		return isOk;
	}

	bool UserServiceUnitest::addLocalSettingSync() {
		//******************���ӱ������ã��Լ�ֵ�Է�ʽ����(ͬ���ӿ�)**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::vector<LocalSetting> items = {};

		bool code = m_userService->addLocalSettingSync(items);
		return code;
	}

	int UserServiceUnitest::getLocalSetting() {
		//******************��ȡ��������**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::vector<std::string> keys = {};

		m_userService->getLocalSetting(keys, [&](int code, std::vector<LocalSetting> b) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	bool UserServiceUnitest::getLocalSettingSync() {
		//******************��ȡ��������(ͬ���ӿ�)**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::vector<std::string> keys = {};
		std::vector<LocalSetting> result = {};
		bool code = m_userService->getLocalSettingSync(keys, result);
		return code;
	}

	int UserServiceUnitest::updateLocalSetting() {
		//******************���±�������**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::vector<LocalSetting> newItems = {};

		m_userService->updateLocalSetting(newItems, [&](int code) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	bool UserServiceUnitest::updateLocalSettingSync() {
		//******************���±�������(ͬ���ӿ�)**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::vector<LocalSetting> newItems = {};


		bool code = m_userService->updateLocalSettingSync(newItems);
		return code;
	}

	int UserServiceUnitest::setLocalSetting() {
		//******************���ñ�������**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::vector<LocalSetting> newItems = {};

		m_userService->setLocalSetting(newItems, [&](int code) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	bool UserServiceUnitest::setLocalSettingSync() {
		//******************���ñ�������(ͬ���ӿ�)**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::vector<LocalSetting> newItems = {};


		bool code = m_userService->setLocalSettingSync(newItems);
		return code;
	}

	int UserServiceUnitest::deleteLocalSetting() {
		//******************ɾ����������************** 
		std::promise<int> reqPromSet;
		std::future<int> reqFutSet = reqPromSet.get_future();

		std::promise<int> reqPromGet;
		std::future<int> reqFutGet = reqPromGet.get_future();

		std::vector<std::string> keys = { "test" };
		std::vector<LocalSetting> newItems;
		LocalSetting set;
		set.key = "test";
		set.val = "true";
		newItems.push_back(set);
		m_userService->setLocalSetting(newItems, [&](int code) {
			reqPromSet.set_value(code);

		});
		reqFutSet.get();

		m_userService->deleteLocalSetting(keys, [&](int code) {
			reqPromGet.set_value(code);

		});
		int code = reqFutGet.get();
		return code;
	}

	bool UserServiceUnitest::deleteLocalSettingSync() {
		//******************ɾ����������(ͬ���ӿ�)**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::vector<std::string> keys = {" "};
		//std::vector<LocalSetting> newItems = {};
		//m_userService->setLocalSetting(newItems, [&](int code) {
		//	reqProm.set_value(code);

		//});

		bool code = m_userService->deleteLocalSettingSync(keys);
		return code;
	}

	int UserServiceUnitest::setPersonalData() {
		//******************���ø���������**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::vector<PersonalData> items{ {1,1},{4,1},{5,1},{6,1},{7,1},{24,1} };
		m_userService->setPersonalData(items, [&](int code) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getPersonalData() {
		//******************��ȡ����������**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::vector<int16> types = {};

		m_userService->getPersonalData(types, [&](int code, std::vector<PersonalData> a) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}


	int UserServiceUnitest::getAppInfo() {
		//******************ͨ��Ӧ��ID��ȡӦ����Ϣ**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_userService->getAppInfo(4328615498, [&](int code, EntAppinfo a) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::queryMarketApplication() {
		//******************��ѯӦ���г�Ӧ����Ϣ**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		QueryMarketApplication qData;
		qData.pageNum = 1;
		qData.pageSize = 1;
		qData.appName = "�������";

		m_userService->queryMarketApplication(qData, [&](int code, SmallMarketAppPage a) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::sendTrackInfo() {
		//******************��ѯӦ�ù켣λ����Ϣ**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::string posMessage = "https://bxy.linkdood.cn:10669/platform/api2/oauth/authorize?id=21256822736&st=STATE&sc=getBase&uri=https://bxyapp.linkdood.cn:10669/attend&lang=zh-CN";

		m_userService->sendTrackInfo(21256822736, posMessage, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::addOrDeleteApplication() {
		//******************ɾ�����Ӧ��**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->addOrDeleteApplication(4, 4328615498, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getInstalledApplication() {
		//******************��ȡ�Ѱ�װ��Ӧ��**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->getInstalledApplication(2, [&](int code, std::vector<SmallMarketAppInfo> a) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::QueryEmoticonPackageByLabel() {
		//******************ͨ����ǩ��ѯ�����************** 
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->QueryEmoticonPackageByLabel("��ѯ���������", [&](int code, std::vector<EmoticonPackage> a) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::queryEmoticon() {
		//******************���������ѯ�����ݱ������ʶ��ѯ���飬��ѯ�û��Զ������**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->queryEmoticon(1, "e922caf7-7d55-4597-98e2-c2f29eb267ff", [&](int code, std::vector<Emoticon> a) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::singleQueryEmoticonPackage() {
		//******************��ѯ���������**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->singleQueryEmoticonPackage("e922caf7-7d55-4597-98e2-c2f29eb267ff", [&](int code, EmoticonPackage a) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::pageQueryEmoticon() {
		//******************��ҳ��ѯ�����**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->pageQueryEmoticon(1, 32,32, [&](int code, PageQueryEmoticon a) {
			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::addOrDeleteCustomEmoticon() {
		//******************��ɾ�Զ������**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		Emoticon emot;
		m_userService->addOrDeleteCustomEmoticon(4, emot, [&](int code) {
			reqProm.set_value(code);
		});

		int code = reqFut.get();
		return code;
	}
	/*
	int UserServiceUnitest::queryEmotionInPackage() {
		//******************��ѡ����������ڵĵ�������************** 
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_userService->queryEmotionInPackage("489be7b0-b4dc-4829-9b2c-f6727237cafd", "md5", [&](int code, singleEmoticonResult a) {
			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}*/

	int UserServiceUnitest::transLocalData() {
		//******************�������ݵ��뵼��**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		transferLocalData req;
		req.day = 1;
		req.mon = 1;
		req.filePath = "C:\\";
		req.type = 0;


		m_userService->transLocalData(req, [&](int code) {reqProm.set_value(code); }, [&](int32 a, int32 b, std::string json) {});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::setUserDefineVoice() {
		//******************�����Զ�����ʾ��**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		transferLocalData req = {};


		m_userService->setUserDefineVoice(0, "�����Զ�����ʾ��", [&](int code) {
			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getUserDefineVoice() {
		//******************��ȡ�û��Զ�����ʾ��**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		transferLocalData req = {};


		m_userService->getUserDefineVoice(0, [&](int code, const std::string a) {
			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getIdByAccount() {
		//******************ͨ���˺�����ȡ�û�ID**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		std::vector<std::string> accounts = { m_config->m_account };


		m_userService->getIdByAccount(accounts, [&](int code, std::map<std::string, int64> a) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}


	int UserServiceUnitest::setOnlineState() {
		//******************��������״̬**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->setOnlineState(1,1 ,"23",[&](int code) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}


	int UserServiceUnitest::setToken() {
		//******************IOS����Token**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->setToken("iphone", "����token", "����cloudtoken", 1, [&](int code) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::setOnlineStatus() {
		//******************���ú�̨����״̬**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		/*std::promise<int> reqProm2;
		std::future<int> reqFut2 = reqProm2.get_future();
		std::promise<int> reqProm3;
		std::future<int> reqFut3 = reqProm3.get_future();*/

		/*m_AuthService->logout([&](int code) {

			reqProm2.set_value(code);

		});
		reqFut2.get();
		std::string account = ((1 == m_config->m_userType) ? "0086" + m_config->m_account : m_config->m_account);
		m_AuthService->loginEx(account, m_config->m_loginPassword, m_config->m_server, m_config->m_userType, "", [&](int code, int64 userId, int64 locktime, const std::string& codepath) {
			reqProm3.set_value(code);
		});
		reqFut3.get();*/

		m_userService->setOnlineStatus(false, true, [&](int code) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::setSessionPeerId() {
		//******************���õ�ǰ�˵ĻỰ����ID���е�ƣ�**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->setSessionPeerId(m_config->m_testUserTarget, [&](int code) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::setTokens() {
		//******************��������token **************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::string appId = "XiaoMi";
		std::string token = "����token";
		std::string deviceType = "2";

		m_userService->setTokens(appId, token, deviceType, [&](int code) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::setPushSwitch() {
		//******************ios�����Ƿ����� **************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_userService->setPushSwitch(true, [&](int code) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::setUnReadCount() {
		//******************ios���ÿͻ�����Ϣδ������ **************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::string appId = "XiaoMi";
		std::string token = "����token";
		std::map<std::string, int32> entUnread = {};



		m_userService->setUnReadCount(1, appId, token, entUnread, [&](int code) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getInstallDays() {
		//******************��ȡ�û�Ӧ�ð�װ���� **************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();




		m_userService->getInstallDays([&](int code, int32 a) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getEntAppInfo() {
		//******************�����û�id��ҳ��ȡ��ҵ�Ż�Ӧ�ú� **************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		reqEntAppInfo req;
		req.pageNum = 1;
		req.pageSize = 2;
		req.type = 1;


		m_userService->getEntAppInfo(req, [&](int code, int64 a, int64 b, std::vector<model::EntAppinfo> c) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::circleOfFriend() {
		//******************����Ȧ�ӿ� **************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::string loginfoPath = "D:\\Frindcircle";


		m_userService->circleOfFriend("��ȡ����Ȧ����", loginfoPath, [&](int code, std::string& json) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::queryUserIDByAccount() {
		//******************�����û��˺�������ȡuserID
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::vector<std::string> accounts = { "008615055034326" };


		m_userService->queryUserIDByAccount(accounts, 1, 1, 0, [&](int code, std::map<std::string, int64>& json) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::operOnlineExt() {
		//******************�������»���ɾ��������չ��Ϣ**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::string str = " ";


		m_userService->operOnlineExt(4, str, [&](int code) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::queryOnlineExt() {
		//******************��ѯ������չ��Ϣ������Ҫ��Σ����������豸���õ�������չ��Ϣ**************
		std::promise<int> reqPromSet;
		std::future<int> reqFutSet = reqPromSet.get_future();
		std::promise<int> reqPromGet;
		std::future<int> reqFutGet = reqPromGet.get_future();

		m_userService->operOnlineExt(4, "ceshi", [&](int code) {

			reqPromSet.set_value(code);

		});
		reqFutSet.get();
		m_userService->queryOnlineExt([&](int code, std::map<std::string, std::string>& json) {

			reqPromGet.set_value(code);

		});

		int code = reqFutGet.get();
		return code;
	}

	int UserServiceUnitest::queryJson() {
		//******************͸��JSON��ʽ����**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->queryJson("��������json��", 2, [&](int code, const std::string& json) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::feedBack() {
		//******************�������**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		IssueFeedBack feedBackParam;
		feedBackParam.questionID = 5;
		feedBackParam.questionName = "��������";
		feedBackParam.questionDescription = "ceshiwenti";
		feedBackParam.isNecessary = 2;
		feedBackParam.operatingSystem = 3;
		feedBackParam.feedbackPersonID = m_config->m_iMyUserId;
		feedBackParam.clientVersion = "1.1.1.1";
		feedBackParam.feedbackPersonName = "ceshi";
		feedBackParam.feedbackPersonOrg = "ceshi";
		feedBackParam.createDate = "00:00";
		feedBackParam.logUrl = " ";
		feedBackParam.operatingSystemVersion = "1.1.1.1";




		m_userService->feedBack(feedBackParam, [&](int code) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getWorkBenchBanners() {
		//******************��ȡ����̨�ֲ�ͼ**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->getWorkBenchBanners(10086, [&](int code, std::vector<WorkbenchBanner>& json) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getHelpSystemInfo() {
		//******************��ȡ����ϵͳ��Ϣ**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->getHelpSystemInfo(10086, 0, [&](int code, std::vector<HelpSystemInfo>& json) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::updateExtendInfo() {
		//******************�����û���չ��Ϣ**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_userService->updateExtendInfo(m_config->m_account, 6, 1, 0, "����mark", [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::queryUserIsExistList() {
		//******************�ж�Ŀ���û��Ƿ����û�����������(������, ���߰�����)**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->queryUserIsExistList(1, m_config->m_testFriendUserId, m_config->m_iMyUserId, [&](int code, int8 b) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}	

	int UserServiceUnitest::getOauthCode() {
		//******************��Ȩ��¼�ӿ�**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->getOauthCode(2, 3, 4328615498, "���Զ�ά��", [&](int code, OAuthResult& json) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::createAppRoom() {
		//******************��������̨Ӧ�÷���**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		AppRoomInfo info;

		m_userService->createAppRoom(info, [&](int code, int64 json) {

			reqProm.set_value(code);
			g_sta_workRoom = json;

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::updateAppRoomInfo() {
		//******************����̨������Ϣ����**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->updateAppRoomInfo(g_sta_workRoom, "���Է���", "0", [&](int code) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::updateAppRoomMem() {
		//******************����̨Ӧ�÷����Ա����**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::vector<int64> memIds = { m_config->m_testFriendUserId2 };

		m_userService->updateAppRoomMem(g_sta_workRoom, 1, memIds, [&](int code) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::setAppOrder() {
		//******************���ù���̨������Ϣ**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::vector<AppOrderInfo> orderInfo = {};

		m_userService->setAppOrder(orderInfo, [&](int code) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getInstalledApplicationSorted() {
		//******************��ȡ����̨�Ѱ�װӦ���ź���(û�����ù�������Ϣ, ��ʱδ�����bool��ʶ)**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_userService->getInstalledApplicationSorted(1, [&](int code, bool a, std::vector<MarketAppGroup>& json) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	bool UserServiceUnitest::addLocalApp() {
		//******************��ӱ���Ӧ��**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		LocalAppInfo info;
		info.appId = 4328615498;
		info.name = "�������";
		info.icon = "at014_0_publicpf_20200320_2140_a_vJNH_44e4000061745196";
		info.url = "http://meeting.linkdood.cn/MeetingAssit/index.html";


		m_userService->addLocalApp(info, [&](int code, int64 json) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		bool flag = (code == 0 || code == -1);
		return flag;
	}

	int UserServiceUnitest::deleteLocalApp() {
		//******************ɾ������Ӧ��**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();





		m_userService->deleteLocalApp(10086, [&](int code) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getLocalAppList() {
		//******************��ȡ����Ӧ���б�**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();





		m_userService->getLocalAppList([&](int code, std::vector<LocalAppInfo>& json) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getDeviceLoginRecord() {
		//******************��ȡ��¼�豸��¼**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();





		m_userService->getDeviceLoginRecord([&](int code, std::vector<DeviceLoginRecord>& json) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::deleteDeviceLoginRecord() {
		//******************ɾ����¼�豸��¼**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		std::vector<std::string> macAddrs = { "50:FF:9D:8A:82:7D" };


		m_userService->deleteDeviceLoginRecord(macAddrs, [&](int code) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::wakeUp() {
		//******************��׿�¼�֪ͨ**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		std::vector<std::string> macAddrs = { "50:FF:8E:8A:82:7D" };


		m_userService->wakeUp([&](int code) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getAgencyList() {
		//******************��ȡ���������б�**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();





		m_userService->getAgencyList([&](int code, std::vector<agencymsg>& json) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getLoginClientRecord() {
		//******************�����û�ID���ϲ�ѯ�û����豸��Ϣ,�����汾**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::vector<int64> userIDVt = { m_config->m_iMyUserId };



		m_userService->getLoginClientRecord(userIDVt, [&](int code, std::map<int64, std::vector<LoginClientRecord> >& json) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getSmallAppHelpFlagValue() {
		//******************��ȡ�ͻ���Ӧ���������Ӧ�÷��񿪹���ֵ**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();




		m_userService->getSmallAppHelpFlagValue(4328615498, [&](int code, int32 json) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getSmallAppHelpList() {
		//******************��ȡ�ͻ���Ӧ��������İ�����ȡ�����б�**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();




		m_userService->getSmallAppHelpList(4328615498, 4328615498, [&](int code, std::vector<SmallAppHelp>& json) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	bool UserServiceUnitest::backupDB() {
		//******************�������ݿ�**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();




		m_userService->backupDB([&](int code) {

			reqProm.set_value(code);

		}, [&](int32 extra_req, int32 process, const std::string& title) {});

		int code = reqFut.get();
		bool flag = (code == -16777205 || code == 15);
		return flag;
	}

	int UserServiceUnitest::getMarketAppSort() {
		//��ȡӦ���г�Ӧ�÷��༯�ϣ�ע�ͣ�
		/*std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_userService->getMarketAppSort([&](int code) {

			reqProm.set_value(code);

		}, [&](int32 extra_req, int32 process, const std::string& title) {});

		int code = reqFut.get();*/

		return 0;
	}


}
