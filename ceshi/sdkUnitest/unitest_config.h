#include "Environment.h"
namespace serviceTest {
	class ConfigServiceUnitest/*:public testing::Test*/ {
	public:
		ConfigServiceUnitest();
		int init();								//初始化
		bool uninit();							//反初始化
		bool getLoginInfos();					//获取登陆信息
		bool delLoginInfo();					//删除某个用户的登陆信息
		bool getNetProxy();						//获取网络代理
		bool setNetProxy();						//设置网络代理
		bool setPlugPower();					//设置是否插电。客户端设置，在ＳＤＫ里面使用
		bool setNetStatus();					//设置网络状态
		bool getSdkVersion();					//获取sdk版本号
		bool setAppVersion();					//设置应用信息
		bool setTextCoding();					//设置客户端文字编码
		bool setAppName();						//设置应用名称
		bool headImgPath();						//获取头像路径
		bool getUserRcPath();					//获取用户资源目录
		bool userImgPath();						//获取该用户聊天中图片信息的保存路径 
		bool userAudioPath();					//获取该用户聊天中音频信息的保存路径
		bool userVideoPath();					//获取该用户聊天中视频信息的保存路径
		bool userCachePath();					//获取该用户聊天中cache
		bool userFilePath();					//获取该用户聊天中文件信息的保存路径
		bool userEmotionPath();					//获取该用户表情中文件的保存路径
		bool getMsgParserMode();				//获取消息解析方式
		bool getLoginExData();					//获取预登录附加数据
		bool setScreenStatus();					//屏幕状态 安卓,IOS专用
		bool getSubServerInfo();				//获取多服务器信息
		bool setSubServerInfo();				//设置多服务器信息
		bool reNotifyData();					//重新推送数据
		bool getIsRoming();						//获取漫游设置
		bool setTicket();						//设置登录票据
		bool setMultichannel();					//设置是否开启多通道
		bool getPreloginInfoEx();				//获取预登陆信息
		bool setOffloginSwitch();				//设置是否开启离线登录
		bool getOffloginStatus();				//查询是否可以离线登录
		bool getIsOpenSecPlugin();				//获取是否开启端到端加密
		bool setHideBuddySwitch();				//设置隐藏好友开关状态(默认为1，手势密码解锁后需要设置为0)
		bool setCloudAddr();					//设置云盘服务器地址
		bool setCloudUploadSpeed();				//设置云盘上传最大速度  10 ~ 10000000  单位：k/s  默认值 100000000  k/s
		bool setCloudDownloadSpeed();			//设置云盘下载最大速度 10 ~ 100000000    默认值 100000000  k/s
		bool setDevelopmentMode();				//设置为调试模式 调试模式需要拥有白名单帐号才能登录
		bool setUserRcPath();					//设置用户资源目录
		bool setLoginInfo();
	protected:
		void TestBody() {
		}
	private:
		std::shared_ptr<IMClient> m_client;
		std::shared_ptr<IConfigService> m_configService = nullptr;
	};
	class beforeConfigServiceUnitest/*:public testing::Test*/{
	public:
		beforeConfigServiceUnitest();
		bool setLogLevel();						//设置日志级别
		bool setInterConnect();					//互联功能配置 
		bool setNotifyStatus();					//设置ＮＯＴＩＦＹ状态
		bool setCertificatePath();				//设置证书,初始化客户端之前设置
		bool getLastPreLoginData();				//获取上一次预登录数据
		bool setLanguage();						//设置为调试模式 调试模式需要拥有白名单帐号才能登录
		bool setLanguageType();					//设置语言环境
		bool setMsgParserMode();				//设置消息解析方式
		bool setIsRoming();						//设置漫游
		bool getLastPreLogin();					//获取上一次预登录数据
		bool setPwIsCrypt();					//设置密钥是否加密
		bool setHttpsLogin();					//设置是否https方式登录
		bool setMac();							//设置mac地址
		bool setIsOpenSecPlugin();				//设置是否开启端到端加密
		bool setLogOutLevel();					//设置log输出级别
		bool rootPath();						//根路径
		bool setRootPath();						//获取根路径
	protected:
		virtual void TestBody() {}
	private:
		std::shared_ptr<IConfigService> m_beforeconfigService = nullptr;
	};
}