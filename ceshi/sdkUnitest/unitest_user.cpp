#include "unitest_user.h"
namespace serviceTest {
	UserServiceUnitest::UserServiceUnitest() {
		m_userService = g_test[0].USERSERVICE();
		m_AuthService = g_test[0].AUTHSERVICE();
	}

	int UserServiceUnitest::getAccountInfo() {
		//******************获取账户信息，同步接口**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		Account  info;
		info.birthday = 19960115;
		m_userService->getAccountInfo(info);
		return m_config->m_iMyUserId==info.id.value()?0:1;
	}

	int UserServiceUnitest::updateAccountInfo() {
		//******************更新用户信息**************
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
		//******************设置账号设置项**************
		std::promise<int> reqProm;							/*type = 1: 设置是否显示在线信息 flag : 0显示 1不显示 默认0
															*  type = 3 : 设置豆豆号查找 flag : 0允许 1不允许 默认0
															*  type = 4 : 设置手机号查找 flag : 0允许 1不允许 默认0
															*  type = 5 : 设置邮箱号查找 flag : 0允许 1不允许 默认0
															*  type = 6 : 设置分享更新   flag : 0提示更新 1不提示更新 默认0
															*  type = 7 : 新消息通知是否提醒 flag : 0提醒 1不提醒 默认0
															*  type = 12 : 多服务新消息通知是否提醒 flag : 0不始终提示 1始终提示 默认0
															*  type = 13 : 多服务设置V标好友始终提醒 flag : 0不始终提示 1始终提示 默认0
															*  type = 14 : 多服务设置设置@相关人始终提醒 flag : 0不始终提示 1始终提示 默认0
															*  type = 20 : 设置新朋友查找 flag : 0允许 1不允许 默认0
															*  type = 22 : 设置昵称查找 flag : 0允许 1不允许 默认0   */
		std::future<int> reqFut = reqProm.get_future();


		m_userService->setSetting(0, 1, [&](int code) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getSetting() {
		//******************获取账号设置项**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_userService->getSetting(1, [&](int code, model::UserSetting &user) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getHiddenTarget() {
		//******************通过密码获取隐藏对象(好友或群)**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_userService->getHiddenTarget(m_config->m_loginPassword, [&](int code, std::vector<int64> a, bool b) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::setHiddenTarget() {
		//******************设置隐藏对象(好友或群)**************
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
		//******************删除隐藏对象(好友或群)**************
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
		//******************更改隐藏密码**************
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
		//******************获取全局勿扰模式（旧版）**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->getGlobalNoDisturbMode([&](int code, int32 a, int32 b, bool c) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::setGolbalNoDisturbMode() {
		//******************设置全局勿扰模式（旧版）**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_userService->setGolbalNoDisturbMode(8, 12, 1, [&](int code) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getGlobalNoDisturbListMode() {
		//******************获取全局勿扰模式(新版)**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_userService->getGlobalNoDisturbListMode([&](int code, std::vector<globalNoDisturbModeInfo> a) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::setGolbalNoDisturbListMode() {
		//******************设置全局勿扰模式(新版)**************
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
		//******************获取针对目标用户的勿扰模式**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->getUserNoDisturbMode(00630045, [&](int code, int64 a, int8 b) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::setUserNoDisturbMode() {
		//******************设置针对目标用户的勿扰模式**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_userService->setUserNoDisturbMode(m_config->m_testFriendUserId2, 1, [&](int code) {
			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getMsgNotifyMode() {
		//******************获取针对目标消息的通知模式**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->getMsgNotifyMode(00630045, [&](int code, int64 a, int8 b) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::setMsgNotifyMode() {
		//******************设置针对目标消息的通知模式**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->setMsgNotifyMode(m_config->m_testFriendUserId2, 1, [&](int code) {
			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getServerTime() {
		//******************获取服务器时间**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->getServerTime([&](int code, int64 time) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	bool UserServiceUnitest::getServerTimeSync() {
		//******************获取服务器时间(同步接口)**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		int64 serverTime = 8;

		bool code = m_userService->getServerTimeSync(serverTime);
		return code;
	}

	bool UserServiceUnitest::addLocalSetting() {
		//******************增加本地配置，以键值对方式保存**************
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
		//******************增加本地配置，以键值对方式保存(同步接口)**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::vector<LocalSetting> items = {};

		bool code = m_userService->addLocalSettingSync(items);
		return code;
	}

	int UserServiceUnitest::getLocalSetting() {
		//******************获取本地配置**************
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
		//******************获取本地配置(同步接口)**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::vector<std::string> keys = {};
		std::vector<LocalSetting> result = {};
		bool code = m_userService->getLocalSettingSync(keys, result);
		return code;
	}

	int UserServiceUnitest::updateLocalSetting() {
		//******************更新本地配置**************
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
		//******************更新本地配置(同步接口)**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::vector<LocalSetting> newItems = {};


		bool code = m_userService->updateLocalSettingSync(newItems);
		return code;
	}

	int UserServiceUnitest::setLocalSetting() {
		//******************设置本地配置**************
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
		//******************设置本地配置(同步接口)**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::vector<LocalSetting> newItems = {};


		bool code = m_userService->setLocalSettingSync(newItems);
		return code;
	}

	int UserServiceUnitest::deleteLocalSetting() {
		//******************删除本地配置************** 
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
		//******************删除本地配置(同步接口)**************
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
		//******************设置个人设置项**************
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
		//******************获取个人设置项**************
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
		//******************通过应用ID获取应用信息**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_userService->getAppInfo(4328615498, [&](int code, EntAppinfo a) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::queryMarketApplication() {
		//******************查询应用市场应用信息**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		QueryMarketApplication qData;
		qData.pageNum = 1;
		qData.pageSize = 1;
		qData.appName = "会务管理";

		m_userService->queryMarketApplication(qData, [&](int code, SmallMarketAppPage a) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::sendTrackInfo() {
		//******************查询应用轨迹位置信息**************
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
		//******************删除添加应用**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->addOrDeleteApplication(4, 4328615498, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getInstalledApplication() {
		//******************获取已安装的应用**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->getInstalledApplication(2, [&](int code, std::vector<SmallMarketAppInfo> a) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::QueryEmoticonPackageByLabel() {
		//******************通过标签查询表情包************** 
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->QueryEmoticonPackageByLabel("查询表情包测试", [&](int code, std::vector<EmoticonPackage> a) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::queryEmoticon() {
		//******************单个表情查询、根据表情包标识查询表情，查询用户自定义表情**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->queryEmoticon(1, "e922caf7-7d55-4597-98e2-c2f29eb267ff", [&](int code, std::vector<Emoticon> a) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::singleQueryEmoticonPackage() {
		//******************查询单个表情包**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->singleQueryEmoticonPackage("e922caf7-7d55-4597-98e2-c2f29eb267ff", [&](int code, EmoticonPackage a) {
			reqProm.set_value(code);

		});


		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::pageQueryEmoticon() {
		//******************分页查询表情包**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->pageQueryEmoticon(1, 32,32, [&](int code, PageQueryEmoticon a) {
			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::addOrDeleteCustomEmoticon() {
		//******************增删自定义表情**************
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
		//******************查选单个表情包内的单个表情************** 
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_userService->queryEmotionInPackage("489be7b0-b4dc-4829-9b2c-f6727237cafd", "md5", [&](int code, singleEmoticonResult a) {
			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}*/

	int UserServiceUnitest::transLocalData() {
		//******************本地数据导入导出**************
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
		//******************设置自定义提示音**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		transferLocalData req = {};


		m_userService->setUserDefineVoice(0, "测试自定义提示音", [&](int code) {
			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getUserDefineVoice() {
		//******************获取用户自定义提示音**************
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
		//******************通过账号名获取用户ID**************
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
		//******************设置在线状态**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->setOnlineState(1,1 ,"23",[&](int code) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}


	int UserServiceUnitest::setToken() {
		//******************IOS设置Token**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->setToken("iphone", "测试token", "测试cloudtoken", 1, [&](int code) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::setOnlineStatus() {
		//******************设置后台在线状态**************
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
		//******************设置当前人的会话对象ID（中电科）**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->setSessionPeerId(m_config->m_testUserTarget, [&](int code) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::setTokens() {
		//******************批量设置token **************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::string appId = "XiaoMi";
		std::string token = "测试token";
		std::string deviceType = "2";

		m_userService->setTokens(appId, token, deviceType, [&](int code) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::setPushSwitch() {
		//******************ios设置是否推送 **************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_userService->setPushSwitch(true, [&](int code) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::setUnReadCount() {
		//******************ios设置客户端消息未读数量 **************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::string appId = "XiaoMi";
		std::string token = "测试token";
		std::map<std::string, int32> entUnread = {};



		m_userService->setUnReadCount(1, appId, token, entUnread, [&](int code) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getInstallDays() {
		//******************获取用户应用安装天数 **************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();




		m_userService->getInstallDays([&](int code, int32 a) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getEntAppInfo() {
		//******************根据用户id分页获取企业号或应用号 **************
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
		//******************朋友圈接口 **************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::string loginfoPath = "D:\\Frindcircle";


		m_userService->circleOfFriend("获取朋友圈测试", loginfoPath, [&](int code, std::string& json) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::queryUserIDByAccount() {
		//******************根据用户账号批量获取userID
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
		//******************新增更新或者删除在线扩展信息**************
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
		//******************查询在线扩展信息，不需要入参，返回所有设备设置的在线拓展信息**************
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
		//******************透传JSON格式请求**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->queryJson("测试请求json串", 2, [&](int code, const std::string& json) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::feedBack() {
		//******************意见反馈**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		IssueFeedBack feedBackParam;
		feedBackParam.questionID = 5;
		feedBackParam.questionName = "测试问题";
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
		//******************获取工作台轮播图**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->getWorkBenchBanners(10086, [&](int code, std::vector<WorkbenchBanner>& json) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getHelpSystemInfo() {
		//******************获取帮助系统信息**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->getHelpSystemInfo(10086, 0, [&](int code, std::vector<HelpSystemInfo>& json) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::updateExtendInfo() {
		//******************设置用户扩展信息**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_userService->updateExtendInfo(m_config->m_account, 6, 1, 0, "测试mark", [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::queryUserIsExistList() {
		//******************判断目标用户是否在用户设置名单中(黑名单, 或者白名单)**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->queryUserIsExistList(1, m_config->m_testFriendUserId, m_config->m_iMyUserId, [&](int code, int8 b) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}	

	int UserServiceUnitest::getOauthCode() {
		//******************授权登录接口**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->getOauthCode(2, 3, 4328615498, "测试二维码", [&](int code, OAuthResult& json) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::createAppRoom() {
		//******************创建工作台应用房间**************
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
		//******************工作台房间信息更新**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_userService->updateAppRoomInfo(g_sta_workRoom, "测试房间", "0", [&](int code) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::updateAppRoomMem() {
		//******************工作台应用房间成员更新**************
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
		//******************设置工作台排序信息**************
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
		//******************获取工作台已安装应用排好序(没有设置过排序信息, 则时未排序的bool标识)**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_userService->getInstalledApplicationSorted(1, [&](int code, bool a, std::vector<MarketAppGroup>& json) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	bool UserServiceUnitest::addLocalApp() {
		//******************添加本地应用**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		LocalAppInfo info;
		info.appId = 4328615498;
		info.name = "会务管理";
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
		//******************删除本地应用**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();





		m_userService->deleteLocalApp(10086, [&](int code) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getLocalAppList() {
		//******************获取本地应用列表**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();





		m_userService->getLocalAppList([&](int code, std::vector<LocalAppInfo>& json) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getDeviceLoginRecord() {
		//******************获取登录设备记录**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();





		m_userService->getDeviceLoginRecord([&](int code, std::vector<DeviceLoginRecord>& json) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::deleteDeviceLoginRecord() {
		//******************删除登录设备记录**************
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
		//******************安卓事件通知**************
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
		//******************拉取待办事项列表**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();





		m_userService->getAgencyList([&](int code, std::vector<agencymsg>& json) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getLoginClientRecord() {
		//******************根据用户ID集合查询用户的设备信息,豆豆版本**************
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
		//******************获取客户端应用浏览器的应用服务开关总值**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();




		m_userService->getSmallAppHelpFlagValue(4328615498, [&](int code, int32 json) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	int UserServiceUnitest::getSmallAppHelpList() {
		//******************获取客户端应用浏览器的帮助获取帮助列表**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();




		m_userService->getSmallAppHelpList(4328615498, 4328615498, [&](int code, std::vector<SmallAppHelp>& json) {

			reqProm.set_value(code);

		});

		int code = reqFut.get();
		return code;
	}

	bool UserServiceUnitest::backupDB() {
		//******************备份数据库**************
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
		//获取应用市场应用分类集合（注释）
		/*std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_userService->getMarketAppSort([&](int code) {

			reqProm.set_value(code);

		}, [&](int32 extra_req, int32 process, const std::string& title) {});

		int code = reqFut.get();*/

		return 0;
	}


}
