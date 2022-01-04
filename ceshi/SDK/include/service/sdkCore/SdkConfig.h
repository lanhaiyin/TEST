#pragma once

#include <string>
#include <vector>
#include <config.h>
#include <cfgExport.h>
#include <interfaceExport.h>
#include "jsonToolInterface.h"
#include "interface.h"
#include "../model/LoginInfo.h"
#include "../model/Packet.h"

using namespace model;
namespace service
{
namespace sdk
{

//struct LoginInfo
//{
//	LoginInfo() = default;
//	LoginInfo(const st_LoginInfoBean&);
//	LoginInfo& operator=(const st_LoginInfoBean& bean);
//	operator st_LoginInfoBean() const;
//
//    int status = 0;            //在线状态-1：离线，1:在线；2:隐身,3:忙碌,4:离开,5:请勿打扰,6:想聊天 移动端用前两个
//    int keep_password = 0;     //是否记录密码1：是，0：否 PC使用
//    int auto_login = 0;        //是否自动登录1：是，0：否 PC使用
//    int64 user_id = 0;         //用户ID
//    int64 last_login_time = 0; //上次登录时间
//    std::string account;        //帐号
//    std::string pwd;            //密码 未加密
//    std::string head_img;       //头像 PC使用
//    std::string ent_area;       //企业域
//};


//用户配置，需要初始化客户端
class SdkConfig
{
public:
	SdkConfig();
    SdkConfig(int cliid);

	//登录信息
    std::vector<LoginInfo> getLoginInfos();
	bool setLoginInfo(const LoginInfo& info);
	//删除某个用户的登录信息
	bool delLoginInfo(int64 userId);
	//设置日志级别
	bool setLogLevel(LogLevel lvl);

	//互联功能配置  0.不使用互联  1.使用互联  默认使用互联
	bool setInterConnect(int flag);

	//设置ＮＯＴＩＦＹ状态 0.打开  1.关闭
	bool setNotifyStatus(int flag);

	//获取SDK缓存对象
	//ICacheMgr *getCacheMgr();
    bool getCacheData(dataType type, void* pOut, void* extra = NULL);

	//获取服务器信息
	bool getLoginExData(st_loginExData &info);

	//设置屏幕状态
	bool setScreenStatus(bool isLight);

	bool getSubServerInfo(std::vector<st_subSrv> &infos);

	LoginStatusInfo getLoginStatus();

	bool setSubServerInfo(std::vector<st_subSrv> &infos);

	bool setRoming(int32 isRoming);

	bool getRoming();

	bool setStatistics(statisticsToolInterface*);

	statisticsToolInterface* getStatistics();

	bool reNotifyData();
    
    bool setRootPath(const std::string &rootPath);

	bool setUserRcPath(const std::string& userPath);

	bool getUserRcPath(std::string& userPath);

	bool setUserPluginPath(const std::string& userPath);

	bool getUserPluginPath(std::string& userPath);
	
	
	bool setTicket(int64 userId, const std::string &ticket);

    //设置是否https方式登录
    bool setHttpsLogin(int8 isHttps);
	
	bool setMultichannel(int8 isMultichannel);

    bool getPreloginInfoEx(std::string& info);
	//获取预登录IP地址
	bool getPreloginIp(std::string& PreloginIp); 
	//获取预登录PORT端口
	bool getPreloginPort(int64 &PreloginPort);
	
	bool getCertOrgName(std::string &certOrgName);
	//设置是否开启端到端加密
	bool setIsOpenSecPlugin(bool isOpenSecPlugin);

	//获取是否开启端到端加密
	bool getIsOpenSecPlugin();

	bool setLogOutLevel(int level);
	
	bool setHideBuddySwitch(int flag);

	bool setCloudServerAddr(std::string &cloudAddr);

	bool getCloudServerAddr(std::string &cloudAddr);

	bool setCloudTransferSpeed(int64 speed);

	bool setCloudDownloadSpeed(int64 speed);

	bool setEmoReddot( int8& reddot);

	bool getEmoReddot();

	bool setServerHead(std::string &path);

	bool RefreshCache();

	bool setServerBlackList(std::string &serverblacklist);

	std::string getServerHead();

	//获取LIC证书的marksign值
	std::string getCertLIC();

	//判断是否是新的消息类型  从内存
	bool judgeNewMsgMEM(int32 MsgType, int32 SubMsgType);
private:
    int m_cliid;
};



//全局配置，不要初始化客户端
class SdkGConfig
{
public:
	SdkGConfig();

	static SdkGConfig *instance();

	//设置证书,初始化客户端之前设置
	bool setCertificatePath(std::string &path);

	//网络代理
	NetProxy getNetProxy();
	bool setNetProxy(NetProxy &param);

	//设置是否插电。客户端设置，在ＳＤＫ里面使用
	bool setPlugPower(bool isPlug);

	//设置网络状态。客户端设置，在ＳＤＫ里面使用 0.断网，１.在线WIFI或者有线,2.在线２Ｇ，３.在线３Ｇ，４.在线４Ｇ
	bool setNetStatus(int state);

	//获取sdk版本号
	std::string getSdkVersion();

	//获取service版本好
	std::string getServiceVersion();

	//设置应用版本号
	bool setAppVersion(const std::string &version);

	//获取应用版本号
	std::string getAppVersion();

	//设置客户端文字编码 0.uft-8   1.gbk 默认utf-8
	bool setTextCoding(int code);

	//设置应用名称 安卓为包名 IOS为应用ID
	bool setAppName(const std::string &name);
	//设置签名信息
	bool setVerifySign(appVerifyInfo &name);
	//设置开发模式
	bool setDevelopmentMode(int option);
	//设置是否使用http插件
	bool setIsUseHttpServer(int8 option);
	//设置语言环境
	bool setLanguage(const std::string &language);
	void setconfigAsync(int flag);
	//获取语言环境 1.中文 2.英文
	std::string getLanguage();

	///设置鸡毛信语言
	void setLanguageType(const std::string& lang){
		m_languageType = lang;
	}
	//设置消息解析方式 true 解析生成json, false由用户自己处理json
	bool setMsgParserMode(bool isParser);

	//获取消息解析方式 true 解析生成json, false由用户自己处理json
	bool getMsgParserMode();
	//设置jsontool对象
	bool setJsonTool(jsonToolInterface*);
	///设置密钥是否加密
	void setPwIsCrypt(bool bCrypt);

	PreLogincfg getLastPreLogin(int64 userId);
	std::string getLastPreLogin(const std::string& server);

	//通过验证码获取ip
	std::string getIpByInvitCode(const std::string &code);

	//获取设备类型
	int8 getDeviceType()
	{
		return m_deviceType;
	}

	std::string getLanguageType(){
		return m_languageType;
	}
	//设置设备类型
	void setDeviceType(int8 deviceType)
	{
		m_deviceType = deviceType;
	}

	//获取登录账号类型
	int8 getUserType()
	{
		return m_userType;
	}

	//设置登录账号类型
	void setUserType(int8 userType)
	{
		m_userType = userType;
	}

	AppInfo getAppInfo()
	{
		return m_appInfo;
	}

	void setAppInfo(AppInfo &info)
	{
		m_appInfo = info;
	}

	bool setOffloginSwitch(int8 isAllowOfflogin);

	bool getOffloginStatus();
	
private:
	std::string m_language;
	std::string m_languageType;///<鸡毛信用
	bool m_isParser;
	int8 m_deviceType;
	int8 m_userType;
	AppInfo m_appInfo;
};


//应用路径信息
class  AppPath
{
public:
	AppPath();
	AppPath(int cliid);
	void reset();						//重置缓存数据
	std::string rootPath();				//根路径
	std::string headImgPath();			//获取头像路径
	void setRootPath(const std::string &rootPath) 
	{ 
		reset();
		m_rootPath = rootPath;
		m_headImgPath = rootPath  + "public/head/";;
	}
	std::string userImgPath();			//<U>获取该用户聊天中图片信息的保存路径 [param]　std::string
	std::string userAudioPath();		//<U>获取该用户聊天中音频信息的保存路径 [param]　std::string
	std::string userVideoPath();		//<U>获取该用户聊天中视频信息的保存路径 [param]　std::string
	std::string userCachePath();		//<U>获取该用户聊天中cache           [param]　std::string
	std::string userFilePath();			//<U>获取该用户聊天中文件信息的保存路径 [param]　std::string
	std::string userEmotionPath();			//<U>获取该用户聊天中文件信息的保存路径 [param]　std::string
private:
	int m_cliid;
	std::string m_rootPath;
	std::string m_headImgPath;
	std::string m_userImgPath;
	std::string m_userAudioPath;
	std::string m_userVideoPath;
	std::string m_userCachePath;
	std::string m_userFilePath;
	std::string m_userEmotionPath;
};

}	/*namespace sdk*/
}	/*namespace service*/