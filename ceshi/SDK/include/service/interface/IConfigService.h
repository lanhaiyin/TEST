#pragma once

#include <string>
#include <vector>
#include "../model/Packet.h"
#include "../model/LoginInfo.h"
#include "IService.h"

#define VER_CONFIG INTERFACE_VERSION(1,0)
static const VRVIID IID_IConfigService = { 0x6f57b9fc, 0x7c48, 0x42e8, 0xb8, 0xab, 0xc6, 0x9b, 0x1f, 0x80, 0x50, 0x13 };

namespace service
{

class IConfigService : public IService
{
public:

	virtual ~IConfigService(){}

	/**
	* \brief <U>获取登陆信息
	* @return 登录信息
	*/
	virtual std::vector<LoginInfo> getLoginInfos() = 0;

	/**
	* \brief <U>设置登陆信息
	* @param[in] 设置的登录信息
	* @return   设置结果
	*/
	virtual bool setLoginInfo(const LoginInfo& info) = 0;
	/**
	* \brief <U>删除某个用户的登陆信息
	* @param[in] 要删除用户的userId。
	* @return   设置结果
	*/
	virtual bool delLoginInfo(int64 userId) = 0;
	/**
	* \brief <U>设置日志级别
	* @param[in]  lvl 日志级别
	* @return   设置结果
	*/
	virtual bool setLogLevel(LogLevel lvl) = 0;

	/**
	* \brief <U>获取登录状态
	* @return   登录状态结果
	*			LoginStatusInfo.status  // 0：没有网络连接 1：没有登录, 但是网络联通 2：正在登录 3：断线重连状态 4：正常状态
	*			LoginStatusInfo.lastLoginCode:
	*										0 登录正常返回
	*										-1 网络错误
	*										113 帐号已经登录 
	*										117 账号被锁
	*										1102 重试次数太多,需要输入验证码
	*										1303  需要修改密码才能登陆
	*										11100 无法回避的内部错误,服务无法找到
	*										100001575 手机已更换设备
	*										100001576 第三方登录认证失败
	*										100002503 客户端为维护状态，不允许登录
	*										100008001 服务器返回该code值，客户端清除该账号的所有数据
	*										-16777171 客户端和sdk的登录状态不一致，sdk为未登录
	*										-16777214 预登录错误，服务器维护中，正在更新
	*										-16777179 预登录错误，需要强制升级
	*										-16777124 证书过期
	*										-16777207 证书验证失败
	*										-16777140 调试白名单校验失败
	*										-16777213 被取消执行
	*										-16777208 数据库升级失败
	*										-16777142 更新用户目录失败
	*										-16777215 打开本地数据库失败
	*										-16777165 域名解析失败				
	*/
	virtual LoginStatusInfo getLoginStatus() = 0;

	/**
	* \brief <U>互联功能配置 
	* @param[in]  flag  0.不使用互联  1.使用互联  默认使用互联
	* @return   设置结果
	*/
	virtual bool setInterConnect(int flag) = 0;

	
	/**
	* \brief <U>设置ＮＯＴＩＦＹ状态
	* @param[in]  flag  0.关闭  1.打开
	* @return   设置结果
	*/
	virtual bool setNotifyStatus(int flag) = 0;

	/**
	* \brief <G>设置证书,初始化客户端之前设置
	* @param[in]  path  证书路径
	* @return   设置结果
	*/
	virtual bool setCertificatePath(std::string &path) = 0;

	/**
	* \brief <G>获取网络代理
	* @return   返回网络代理信息
	*/
	virtual NetProxy getNetProxy() = 0;
	/**
	* \brief <G>设置网络代理
	* @param[in] param 需设置的网络代理信息
	* @return   设置结果
	*/
	virtual bool setNetProxy(NetProxy &param) = 0;




	/**
	* \brief <G> 判断是否新消息类型 从内存查找
	* @param[in] MsgType 消息类型
	* @param[in] subMsgType 子消息类型
	* @return   设置结果 true-已有消息    false-新消息类型 
	*/
	virtual bool JudgeNewMsgMEM(int32 MsgType, int32 subMsgType) = 0;

	/**
	* \brief <G>设置是否插电。客户端设置，在ＳＤＫ里面使用
	* @param[in] isPlug 是否插电
	* @return   设置结果
	*/
	virtual bool setPlugPower(bool isPlug) = 0;

	/**
	* \brief <G>设置网络状态。客户端设置，在ＳＤＫ里面使用
	* @param[in] state  0.断网，１.在线WIFI或者有线,2.在线２Ｇ，３.在线３Ｇ，４.在线４Ｇ
	* @return   设置结果
	*/
	virtual bool setNetStatus(int state) = 0;

	/**
	* \brief <G>获取sdk版本号
	* @return   sdk版本号
	*/
	virtual std::string getSdkVersion() = 0;

	/**
	* \brief <G>设置应用信息
	* @param[in] version 版本号
	* @param[in] deviceType 设备类型
	* @param[in] deviceInfo 设备信息
	* @return   设置结果
	*/
	virtual bool setAppVersion(const std::string &version, int deviceType, const std::string &deviceInfo, const std::string &netType = "", const std::string &mac = "", const std::string &mark = "") = 0;


	/**
	* \brief <G>设置客户端文字编码
	* @param[in] code  编码 0.uft-8   1.gbk  默认utf-8
	* @return   设置结果
	*/
	virtual bool setTextCoding(int code) = 0;

	/**
	* \brief <G>设置应用名称
	* @param[in] name 应用名 安卓为包名 IOS为应用ID
	* @return   设置结果
	*/
	virtual bool setAppName(const std::string &name) = 0;
	/**
	* \brief <G>设置为调试模式 调试模式需要拥有白名单帐号才能登录
	* @param[in] option 1 调试模式 0 非调试模式
	*/
	virtual bool setDevelopmentMode(int option) = 0;
	/**
	* \brief <G>设置语言环境
	* @param[in] language 语言
	* @return   设置结果
	*/
	virtual bool setLanguage(const std::string &language) = 0;
	/**
	* \brief <G>设置鸡毛信语言环境
	* @param[in] language 语言
	*/
	virtual void setLanguageType(const std::string &language) = 0;

	/**
	* \brief <G>获取根路径
	* @return   根路径
	*/
	virtual std::string rootPath() = 0;
    
    /**
     * \brief <U>设置资源根路径，包括图片，文件，音频，视频路径都受影响
     * 比如设置为/home/sharp/ , 图片路径就会成为/home/sharp/{userid}/image
     * userid为当前登录的用户ID
     */
    virtual bool setRootPath(const std::string &rootPath) = 0;

	/**
	* \brief <G>获取头像路径
	* @return   头像路径
	*/
	virtual std::string headImgPath() = 0;
	/**
	* \brief <U>设置用户资源目录
	* @return   图片信息的保存路径
	*/
	virtual bool setUserRcPath(const std::string& userPath) = 0;
	virtual std::string getUserRcPath() = 0;
	/**
	* \brief <U>设置用户secmsg插件库目录
	* @return   库信息的保存路径
	*/
	virtual bool setUserPluginPath(const std::string& userPath) = 0;
	virtual std::string getUserPluginPath() = 0;
	/**
	* \brief <U>获取该用户聊天中图片信息的保存路径 
	* @return   图片信息的保存路径 
	*/
	virtual std::string userImgPath() = 0;

	/**
	* \brief <U>获取该用户聊天中音频信息的保存路径
	* @return   音频信息的保存路径
	*/
	virtual std::string userAudioPath() = 0;

	/**
	* \brief <U>获取该用户聊天中视频信息的保存路径
	* @return   视频信息的保存路径
	*/
	virtual std::string userVideoPath() = 0;

	/**
	* \brief <U>获取该用户聊天中cache
	* @return   用户聊天中cache
	*/
	virtual std::string userCachePath() = 0;

	/**
	* \brief <U>获取该用户聊天中文件信息的保存路径
	* @return   文件信息的保存路径
	*/
	virtual std::string userFilePath() = 0;

	/**
	* \brief <U>获取该用户表情中文件的保存路径
	* @return   文件信息的保存路径
	*/
	virtual std::string userEmotionPath() = 0;

	/**
	* \brief <G>设置消息解析方式
	* @param[in]  isParser  true 解析生成json, false由用户自己处理json
	*/
	virtual bool setMsgParserMode(bool isParser) = 0;
	/**
	* \brief <G>获取消息解析方式
	* @return 是否由sdk解析
	*/
	virtual bool getMsgParserMode() = 0;

	/**
	* \brief <U>获取预登录附加数据
	* @return   附加数据json串
	*/
	virtual std::string getLoginExData(const std::string &serverName) = 0;

	/**
	* \brief <U>屏幕状态 安卓,IOS专用
	*/
	virtual bool setScreenStatus(bool isLight) = 0;

	/**
	* \brief <U>获取多服务器信息
	*/
	virtual bool getSubServerInfo(std::vector<SubServerInfo> &infos) = 0;

	/**
	* \brief <U>设置多服务器信息
	*/
	virtual bool setSubServerInfo(std::vector<SubServerInfo> &infos) = 0;

	/**
	* \brief <U>重新推送数据
	*/
	virtual bool reNotifyData() = 0;

	/**
	* \brief <U>设置漫游
	*/
	virtual bool setIsRoming(int32 isRoming) = 0;
	/**
	* \brief <U>获取漫游设置
	*/
	virtual bool getIsRoming() = 0;

	/**
	* \brief <G>  获取上一次预登录数据
	*/
	virtual PreLogincfg getLastPreLoginData(int64 userId) = 0;
	virtual std::string getLastPreLogin(const std::string& server) = 0;

	/**
	* \brief <U>设置登录票据
	*/
	virtual bool setTicket(int64 userId, const std::string &ticket) = 0;
	/**
	* \brief <G>设置密钥是否加密
	0为不加密， 1为加密
	*/
	virtual bool setPwIsCrypt(bool bCrypt) = 0;
	/**
	* \brief <U>设置是否https方式登录
		0 否， 1是
	*/
	virtual bool setHttpsLogin(int8 isHttps) = 0;
	/**
	* \brief <U>设置是否开启多通道
	0 否， 1是
	*/
	virtual bool setMultichannel(int8 isMultichannel) = 0;
    /**
    * \brief <U>获取预登陆信息
    * json格式字段:preloginIP,port,netId
    */
    virtual std::string getPreloginInfoEx() = 0;

	/**
	* \brief <U>设置是否开启离线登录
	* 0 不允许  1 允许
	*/
	virtual bool setOffloginSwitch(int8 isAllowOfflogin) = 0;
	/**
	* \brief <U>查询是否可以离线登录
	* false 不允许  true 允许
	*/
	virtual bool getOffloginStatus() = 0;
	/**
	* \brief <G>设置mac地址(用于初始化后更改mac地址)
	* false 不允许  true 允许
	*/
	virtual void setMac(const std::string &mac) = 0;
	/**
	* \brief 设置是否开启端到端加密
	* @param[in]  bool isOpenSecPlugin
	*/
	virtual bool setIsOpenSecPlugin(bool isOpenSecPlugin) = 0;
	/**
	* \brief 获取是否开启端到端加密
	* @return 是否开启端到端加密
	*/
	virtual bool getIsOpenSecPlugin() = 0;
	/**
	* \brief 设置log输出级别
	* level 0 不输出log，1、不输出debug 2 输出所有log
	*/
	virtual void setLogOutLevel(int level) = 0;
	/**
	* \brief 设置隐藏好友开关状态(默认为1，手势密码解锁后需要设置为0)
	* flag 0.显示隐藏好友  1.不显示隐藏好友
	*/
	virtual void setHideBuddySwitch(int8 flag) = 0;

	/*
	* \brief 设置云盘服务器地址
	* @param[in] string addr   eg: http://192.x.x.x:80   包含 http,  url  port
	*/
	virtual void setCloudAddr(const std::string &addr) = 0;

	/*
	* \brief 设置云盘上传最大速度  10 ~ 10000000  单位：k/s  默认值 100000000  k/s
	*/
	virtual void setCloudUploadSpeed(int64 speed) = 0;

	/*
	* \brief 设置云盘下载最大速度 10 ~ 100000000    默认值 100000000  k/s
	*/
	virtual void setCloudDownloadSpeed(int64 speed) = 0;

	//* \brief <G>设置服务器表情包小红点
	//* @param[in] reddot 小红点值，0 清除 1 置位
	//* @return   设置结果
	//*/
	virtual bool setEmoReddot(int8 reddot) = 0;

	virtual bool getEmoReddot() = 0;

	/*暂时屏蔽此接口，单独设置会出现子账号先默认头像再正常的现象。产品不接受*/
	///**
	//* \brief <G>设置服务器头像
	//* @param[in] serverlocalpath 本地图片全路径
	//* @return   设置结果
	//*/
	//virtual bool setServerHead(const std::string &serverlocalpath) = 0;

	///**
	//* \brief <G>获取服务器头像
	//* @return   设置结果
	//*/
	//virtual std::string getServerHead() = 0;

	/**
	* \brief <U>刷新sysdb缓存信息（数据迁移成功后使用）
	*/
	virtual bool RefreshSysCache() = 0;

	/**
	* \brief <G>（防诈骗）设置黑名单列表(服务器elogo列表)，格式要求：字符串以#号分隔“elogo1#elogo2#elogo3”
	*/
	virtual bool setServerBlackList(const std::string &serverblacklist) = 0;
private:
		
};

} /*namespace service*/