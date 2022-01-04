#include "Environment.h"
namespace serviceTest {
	class UserServiceUnitest /*:public testing::Test*/ {
	public:
		UserServiceUnitest();
	int getAccountInfo();						//******************获取账户信息，同步接口**************
	int updateAccountInfo();					//******************更新用户信息**************
	int setSetting();							//******************设置账号设置项**************
	int getSetting();							//******************获取账号设置项**************
	int getHiddenTarget();						//******************通过密码获取隐藏对象(好友或群)**************
	int setHiddenTarget();						//******************设置隐藏对象(好友或群)**************
	int delHiddenTarget();						//******************删除隐藏对象(好友或群)**************
	bool changeHiddenPasswd();					//******************更改隐藏密码**************                       
	int getGlobalNoDisturbMode();				//******************获取全局勿扰模式（旧版）**************
	int setGolbalNoDisturbMode();				//******************设置全局勿扰模式（旧版）**************
	int getGlobalNoDisturbListMode();			//******************获取全局勿扰模式(新版)**************
	int setGolbalNoDisturbListMode();			//******************设置全局勿扰模式(新版)**************
	int getUserNoDisturbMode();					//******************获取针对目标用户的勿扰模式**************
	int setUserNoDisturbMode();					//******************设置针对目标用户的勿扰模式**************
	int getMsgNotifyMode();						//******************获取针对目标消息的通知模式**************
	int setMsgNotifyMode();						//******************设置针对目标消息的通知模式**************
	int getServerTime();						//******************获取服务器时间**************
	bool getServerTimeSync();					//******************获取服务器时间(同步接口)**************
	bool addLocalSetting();						//******************增加本地配置，以键值对方式保存**************
	bool addLocalSettingSync();					//******************增加本地配置，以键值对方式保存(同步接口)**************
	int getLocalSetting();						//******************获取本地配置**************
	bool getLocalSettingSync();					//******************获取本地配置(同步接口)**************
	int updateLocalSetting();					//******************更新本地配置**************
	bool updateLocalSettingSync();				//******************更新本地配置(同步接口)**************
	int setLocalSetting();						//******************设置本地配置**************
	bool setLocalSettingSync();					//******************设置本地配置(同步接口)**************
	int deleteLocalSetting();					//******************删除本地配置**************                           
	bool deleteLocalSettingSync();				//******************删除本地配置(同步接口)**************
	int setPersonalData();						//******************设置个人设置项**************
	int getPersonalData();						//******************获取个人设置项**************
	int getAppInfo();							//******************通过应用ID获取应用信息**************
	int queryMarketApplication();				//******************查询应用市场应用信息**************
	int sendTrackInfo();						//******************查询应用轨迹位置信息**************  error =  100 PC无法定位
	int addOrDeleteApplication();				//******************删除添加应用**************
	int getInstalledApplication();				//******************获取已安装的应用**************
	int QueryEmoticonPackageByLabel();			//******************通过标签查询表情包**************   100001801  vrv服务器还没实现该接口    bxy通过
	int queryEmoticon();						//******************单个表情查询、根据表情包标识查询表情，查询用户自定义表情**************100001801  服务器还没实现该接口
	int singleQueryEmoticonPackage();			//******************查询单个表情包**************        100001801  服务器还没实现该接口
	int pageQueryEmoticon();					//******************分页查询表情包**************		100001801  服务器还没实现该接口
	int addOrDeleteCustomEmoticon();			//******************增删自定义表情**************		100001801  服务器还没实现该接口
	//#define test_queryEmotionInPackage		//******************查选单个表情包内的单个表情**************		
	int transLocalData();						//******************本地数据导入导出**************
	int setUserDefineVoice();					//******************设置自定义提示音**************
	int getUserDefineVoice();					//******************获取用户自定义提示音**************
	int getIdByAccount();						//******************通过账号名获取用户ID**************
	int setOnlineState();						//******************设置在线状态**************

	///**************IOS专用接口 begin***************/
	//
	//
	int setToken();							//******************IOS设置Token**************
	int setOnlineStatus();					//******************设置后台在线状态**************
	int setSessionPeerId();					//******************设置当前人的会话对象ID（中电科）**************
	int setTokens();						//******************批量设置token **************
	int setPushSwitch();					//******************ios设置是否推送 **************
	int setUnReadCount();					//******************ios设置客户端消息未读数量 **************
	int getInstallDays();					//******************获取用户应用安装天数 **************
	int getEntAppInfo();					//******************根据用户id分页获取企业号或应用号 **************
	int circleOfFriend();					//******************朋友圈接口 **************
	int queryUserIDByAccount();				//******************根据用户账号批量获取userID **************
	int operOnlineExt();					//******************新增更新或者删除在线扩展信息**************
	int queryOnlineExt();					//******************查询在线扩展信息，不需要入参，返回所有设备设置的在线拓展信息**************
	int queryJson();						//******************透传JSON格式请求**************
	int feedBack();							//******************意见反馈**************	
	int getWorkBenchBanners();				//******************获取工作台轮播图**************
	int getHelpSystemInfo();				//******************获取帮助系统信息**************
	int updateExtendInfo();					//******************设置用户扩展信息**************
	int queryUserIsExistList();				//******************判断目标用户是否在用户设置名单中(黑名单, 或者白名单)**************
	int getOauthCode();						//******************授权登录接口**************
	int createAppRoom();					//******************创建工作台应用房间**************
	int updateAppRoomInfo();				//******************工作台房间信息更新**************
	int updateAppRoomMem();					//******************工作台应用房间成员更新**************
	int setAppOrder();						//******************设置工作台排序信息**************
	int getInstalledApplicationSorted();	//******************获取工作台已安装应用排好序(没有设置过排序信息, 则时未排序的bool标识)**************
	bool addLocalApp();						//******************添加本地应用**************
	int deleteLocalApp();					//******************删除本地应用**************
	int getLocalAppList();					//******************获取本地应用列表**************
	int getDeviceLoginRecord();				//******************获取登录设备记录**************
	int deleteDeviceLoginRecord();			//******************删除登录设备记录**************
	int getMarketAppSort();					//******************获取应用市场应用分类集合（注释）**************
	//
	///**************IOS专用接口 end***************/
	//
	//
	///**************安卓专用接口 begin***************/
	//
	//
	int wakeUp();							//******************安卓事件通知**************	
	
	/**************安卓专用接口 end***************/
	int getAgencyList();					//******************拉取待办事项列表**************
	int getLoginClientRecord();				//******************根据用户ID集合查询用户的设备信息,豆豆版本**************
	int getSmallAppHelpFlagValue();			//******************获取客户端应用浏览器的应用服务开关总值**************
	int getSmallAppHelpList();				//******************获取客户端应用浏览器的帮助获取帮助列表**************
	bool backupDB();							//******************备份数据库**************
	protected:
		virtual void TestBody() {}
	private:
		std::shared_ptr<IUserService> m_userService = nullptr;
		std::shared_ptr<IAuthService> m_AuthService = nullptr;
	};
}

