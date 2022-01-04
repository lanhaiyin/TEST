/*
 * cfgExport.h
 *  各端通过获取的数据结构定义,此头文件中所有结构体定义以st_开头
 *  Created on: 2015年8月5日
 *      Author: sharp
 */

#ifndef PROTOCOL_CFGEXPORT_H_
#define PROTOCOL_CFGEXPORT_H_

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

#include "config.h"

///获取配置的类型 ,标识<G>的是全局配置，不用登录就可以用．，<U>是用户/客户端实例相关配置.
///接口实际参数为[param] 的指针
enum  {
	// <U>获取终端最近一次登录信息 U　[param] 写：st_LoginInfoBean　，读：st_loginfoArray
	cfg_lastLogininfo =1,
	// <G>代理配置，ＰＣ专用 G [param] st_netProxy
	cfg_netproxy=2,
	///<G>网络设置, PC 专用 [param] st_net
	cfg_net=3,
	///<G>根路径　　[param]　std::string
	cfg_rootpath=4,
	///<G>头像路径 [param]　std::string
	cfg_headImgpath=5,
	///<G>是否插电 [param] bool   true插电，bool不插电 上面设置，在ＳＤＫ里面使用
	cfg_plugPower=6,
	/**
	 * \brief <G>网络状态 [param] int32 　0：断网，１：在线WIFI或者有线,2:在线２Ｇ，３：在线３Ｇ，４在线４Ｇ
	 * 当网络发生变化的时候上面设置，ＳＤＫ使用
	 * 如果是处在IPV6网络环境下
	 */
	cfg_netStatus=7,
	///<U>获取该用户聊天中图片信息的保存路径 [param]　std::string
	cfg_userImgPath=8,
	///<U>获取该用户聊天中音频信息的保存路径 [param]　std::string
	cfg_userAudioPath=9,
	///<U>获取该用户聊天中视频信息的保存路径 [param]　std::string
	cfg_userVideoPath=10,
	///<U>获取该用户聊天中cache           [param]　std::string
	cfg_usercachePath=11,
	///<U>获取该用户聊天中文件信息的保存路径 [param]　std::string
	cfg_userFilePath=12,
	///<G>设置登录地址, 内部调试使用.   [param]　st_loginAddress
	cfg_loginAddress=13,
	/**
	 * \brief <U>日志标识
	 * [param] int32 , 默认开发所有日志
	 * 0   : 关闭所有日志
	 * 0xFF: 打开所有日志
	 * 0x01: 调试日志 详细情况,标识：sdklog_debug
	 * 0x02: 运行状态信息，标识： sdklog_trace
	 * 0x04: 注意 有可能出错 ,比如内存占用高等 标识: sdklog_notice
	 * 0x08: 出错,但可以自行修复	sdklog_warn,
	 * 0x10: 除错，可能无法恢复    sdklog_err,
	 */
	cfg_setLogFlag=14,
	///<U>获取plugin管理接口  [param] IPluginSlot **/
	cfg_getPluginSlot,
	/**
	 * \brief <G>设置安卓消息响应模式,所有客户端实例都受控制,需要在第一次实例前调用
	 * 设置１，ＳＤＫ线程主动调用ＪＡＶＡ层ＡＰＩ
	 * 设置０，虚拟机线程主动调用ＳＤＫ，ＳＤＫ进行回调.
	 * [param] int
	 */
	cfg_setAndroidRespMode=16,
	/**
	 * \brief <U>当cfg_setAndroidRespMode为１时有效,每个实例设置不同的对象
	 * 这个类要和安卓的ＳＤＫAPI层商议好
	 */
	cfg_setJvmInterfaceObjForResp=17,
	/**
	 * \brief 获取ＳＤＫ版本号 [param] std::string
	 */
	cfg_sdkVersion=18,

	/**
	 * \brief 屏幕状态 安卓,IOS专用 [param] int , 0是暗，1是亮
	 */
	cfg_screenStatus=19,

	/**
	 * \brief ＳＤＫ证书路径,全路径,返回失败，标识证书校验失败.需要在initClient之前设置
	 */
	cfg_certificatePath=20,
	/**
	 * \brief 传入的文字编码格式  [param] int , 0是utf-8，1是gb 默认为uft-8,
	 * 需要在initClient之前设置.
	 */
	cfg_textCoding = 21,

	/**
	 * \brief <U>互联功能配置
	 * [param]  int , 0是否没有互联，１是有互联。默认使用互联
	 */
	cfg_InterConnect,

	/**
	 * \brief <G>APP名称， 安卓是包名，IOS是应用ID。
	 * [param] string
	 */
	cfg_appName,

	/**
	 *　\brief <U>获取预登录附加数据
	 *　[param] st_loginExData ,
	 *　[return] true 代表服务器可用
	 */
	cfg_loginExData,

	/**
	 * \brief <U>设置ＮＯＴＩＦＹ状态
	 * [param] int   0代表打开，１代表关闭
	 */
	cfg_notifyStatus,

	/**
	 * \brief <U> 多服务器信息保留,for linkdood json string.
	 * [param] vector<st_subSrv> ,包含当前登录的服务器 U
	 */
	cfg_subserverInfo ,

	/**
	 * \brief <U> 登录后批量消息推送（for nanjing 移动端多服务器）,通过异步推送到界面
	 */
	cfg_getLoginDatagain,

	/**
	 * \brief <G>当前语言环境 G
	 * [param] int 1.中文 2.英文 
	 */
	cfg_language,


	/**
	* \brief <u>  获取缓存接口
	*/
	cfg_getCache,

	/**
	 * \brief 获取数据库加密密钥
	*/
	cfg_getPrivateKey,
	
	/**
	* \brief <G>  应用版本号
	*/
	cfg_appVersion,

	/**
	* \brief <G>  获取上一次预登录数据
	* [param] std::string , 输入用户账号，返回成功得话，里面是预登录信息
	*/
	cfg_getLastPreLoginData,

	/*
	 * \brief <G> 设置文件加密算法 
	 *    [param] int  可选见aes.h 头文件 
	*/
	cfg_setAlgorithm,
	
	/**
	* \brief <U> 设置是否开启消息漫游，开启后可能会影响获取历史的响应速度,
	* 0为关闭，非零为打开，默认关闭
	*/
	cfg_msgRoaming = 34,

	///<U>获取该用户表情文件信息的保存路径 [param]　std::string
	cfg_userEmotionPath = 35,

	///<G>设置解析消息的接口  [param]　jsonToolInterface 的指针
	cfg_jsonToolInterface=36,

	 /**
	* \brief <U> 设置资源根路径，包括图片，文件，视频，音频路径都受影响
	* 比如设置为/home/sharp/。 图片路径就会成为/home/sharp/{usrid}/image 
	* userid为当时登录的用户ID
	*/
	 cfg_rcRootPath = 37 ,
	 
	 /**
	  *  \brief 登录票， 从外部设置进来绑定该客户端实例上，再进行自动登录的时候使用 。
	  *  参数为st_outterTicket指针 G
	  */
	cfg_ticket = 38,

	/*
		\brief G  设置密码是否加密
		参数为int32 1为加密， 0 为不加密， 默认加密

	*/
	cfg_isPwCrypt = 39 ,

	/**
	 * \brief G 获取邀请码
	 * 参数为char * , 长度最少为128.
	 * 传入为服务器地址, 输出为邀请码
	 */ 
	cfg_getInvitCode = 40,
	/**
	* \brief G 通过邀请码获取IP
	* 参数为std::string
	* 传入邀请码, 输出为服务器地址
	*/
	cfg_getIpByInvitCode = 41,
	/**
	* \brief 是否为https预登录
	* 参数为int8 0 http  1 https
	*/
	cfg_httpsPreLogin = 42,
	/**
	* \brief 是否启用多通道 
	* 参数为int8 0 不启用  1 启用(默认不启用)
	*/
	cfg_multichannel = 43,
    /**
    * \brief 获取预登陆信息
    */
    cfg_getPreloginInfo = 44,
	/*
	*\brief 设置验证签名信息
	*/
	cfg_verifySign = 45,
	/**
	* \brief 是否允许离线登录
	* 参数为int8 0 不允许  1 允许(默认不允许)
	*/
	cfg_allowOfflogin = 46,
	/**
	*\brief 设置调试模式 1.调试 0.默认
	*/
	cfg_setDevelopment = 47,
	/**
	*\brief 删除某个用户的登录信息
	*/
	cfg_delLoginInfo = 48,
	/**
	*\brief <G>证书使用者信息
	*/
	cfg_certOrgName = 49,
	/**
	* \brief G 是否使用http插件
	*/
	cfg_isUseHttpServer = 50,
	/**
	* \brief  是否开启端到端加密
	*/
	cfg_isOpenSecPlugin = 51,
	/**
	* \brief  数据库自动登录秘钥
	*/
	cfg_dbAutoLoginKey = 52,
	/**
	* \brief  dns缓存
	*/
	cfg_dnsCache = 53,
	/**
	* \brief  预登陆结果 之前的太烂了 不要用了
	*/
	cfg_getLastPreLoginData2 = 54,
		/**
	* \brief  设置log输出级别
	*/
	cfg_setLogLevel = 55,
	/**
	* \brief  隐藏好友开关
	*/
	cfg_hideBuddySwitch = 56,
	/**
	* \brief  设置日志解析类
	*/
	cfg_statistics = 57,
	/**
	* \brief  设置用户资源目录 U
	*/
	cfg_userRcPath = 58,
  	/*
	* \brief  设置云盘服务器地址
	*/
	cfg_setCloudServer = 59,
	/*
	* \brief  设置云盘服务器文件上传最大速度
	*/
	cfg_setCloudTransferSpeed = 60,
	/*
	* \brief 设置云盘服务器下载最大速度
	*/
	cfg_setCloudDownloadSpeed = 61,
	/**
	* \brief  获取预登录的IP地址
	*/
	cfg_getPreLoginIp = 62,
	/**
	* \brief  获取预登录的Port端口
	*/
	cfg_getPreLoginPort = 63,

	/**
	* \brief  获取LIC证书的marksign
	*/
	cfg_getCertLIC= 64,

	/**
	*　\brief <U>获取表情集合
	*/
	cfg_getEmoticon = 65,

	/**
	*　\brief <U>获取表情包集合
	*/
	cfg_getEmoticonPackage = 66,

	/**
	*　\brief <U>获取登录状态
	*/
	cfg_getLoginStatus = 67,

	/**
	*　\brief <U>服务器头像
	*/
	cfg_serverheadimg = 68,
	/*
	* \brief  设置服务器表情包小红点
	*/
	cfg_EmTServReddot = 69,                                        //value  elogo + ":1";

	/**
	*　\brief 刷新sysdb缓存
	*/
	cfg_RefreshCache = 70,

	/**
	*　\brief （防诈骗）服务器黑名单
	*/
	cfg_ServerBlackList = 71,

	/**
	* \brief  设置插件目录 U
	*/
	cfg_userPluginPath = 72,

	cfg_Export_max,      	//配置导出最大值,无特殊意义

 };

 struct NewMsgType //新消息类型
 {
	 NewMsgType() {
	 }
	 int32 MsgType;
	 int32 subMsgType;
 };

/*
 * \brief 最近一次登录信息基本结构
 */
struct    st_LoginInfoBean{
	st_LoginInfoBean(){
        flag = 0;
        status = 0;
        keepPwd = 0;
        autoLogin = 0;
        userid = 0;
        time = 0;
		userType = 0 ;
		nDeviceType = 0;
	}

	int32 flag;						///< 多账号登录顺序
	int32 status;				    ///< 在线状态-1：离线，1:在线；2:隐身,3:忙碌,4:离开,5:请勿打扰,6:想聊天 移动端用前两个
	int32 keepPwd;					///< 是否记录密码1：是，0：否 PC使用
	int32 autoLogin;			    ///< 是否自动登录1：是，0：否 PC使用
	int64 userid ;				    ///< 用户ID
	int64 time;						///< 上次登录时间
	int  nDeviceType;               ///<设备类型
	std::string account;			///< 帐号
	std::string name ;              ///< 用户名称
	std::string pwd;				///< 密码 未加密
	std::string avatar;				///< 头像 PC使用
	std::string entArea;			///< 企业域
	int32 userType;                 ///< 登录账户类型，1：手机，2：QQ，3：邮箱，4：UserID
	std::string nationalCode;       ///< 国家代码
	std::string phone;				///< 绑定的手机
	std::string email;				///< 绑定的邮箱
	std::string verImgPath;         ///< 客服信息

	const std::string output_parameter()
	{
		std::stringstream ss;
		ss << "st_LoginInfoBean::flag ＝ " << flag << "\n";
		ss << "st_LoginInfoBean::status ＝ " << status << "\n";
		ss << "st_LoginInfoBean::keepPwd ＝ " << keepPwd << "\n";
		ss << "st_LoginInfoBean::userid ＝ " << userid << "\n";
		ss << "st_LoginInfoBean::time ＝ " << time << "\n";
		ss << "st_LoginInfoBean::account ＝ " << account << "\n";
		ss << "st_LoginInfoBean::name ＝ " << name << "\n";
		ss << "st_LoginInfoBean::pwd ＝ " << pwd << "\n";
		ss << "st_LoginInfoBean::avatar ＝ " << avatar << "\n";
		ss << "st_LoginInfoBean::entArea ＝ " << entArea << "\n";
		ss << "st_LoginInfoBean::nationalCode ＝ " << nationalCode << "\n";

#ifdef LOCAL_DEBUG
		std::cout << ss.str();
#endif
		return ss.str();
	}
};

/**
 *  \brief cfg_lastLogininfo  类型返回
 */
struct    st_loginfoArray  {
	/**
	* \brief 移动端只有一条信息,
	*  PC端多条信息
	*/
	std::vector<st_LoginInfoBean>  _vt;

	const std::string output_parameter()
	{
		std::stringstream ss;
		ss << "st_loginfoArray::_vt.size() ＝ " << _vt.size() << "\n";
		for (unsigned int i = 0; i < _vt.size(); i++)
		{
			ss << "st_loginfoArray::_vt[ " << i << " ] ＝ " << _vt[i].output_parameter() << "\n";
		}

#ifdef LOCAL_DEBUG
		std::cout << ss.str();
#endif
		return ss.str();
	}
};

/**
 * \brief 代理配置
 * PC专用
 */
struct st_netProxy {
	st_netProxy() :type(0), port(0) {}
	int8     type;         ///< 0-不使用，１-http1.1  2-http1.0  3-socket4  4-socket5
	uint16   port;         ///< 端口
	std::string addr;      ///< 地址
	std::string user;      ///< 用户名
	std::string pw;        ///< 密码
	
	const std::string output_parameter()
	{
		std::stringstream ss;
		ss << "st_netProxy::type ＝ " << type << "\n";
		ss << "st_netProxy::port ＝ " << port << "\n";
		ss << "st_netProxy::addr ＝ " << addr << "\n";
		ss << "st_netProxy::user ＝ " << user << "\n";
		ss << "st_netProxy::pw ＝ " << pw << "\n";

#ifdef LOCAL_DEBUG
		std::cout << ss.str();
#endif
		return ss.str();
	}
};
typedef enum {
	NETPROXYTYPE_HTTP = 0, /* CONNECT HTTP/1.1 */
	NETPROXYTYPE_HTTP_1_0 = 1, /* CONNECT HTTP/1.0 */
	NETPROXYTYPE_SOCKS4 = 4,
	NETPROXYTYPE_SOCKS5 = 5,
	NETPROXYTYPE_SOCKS4A = 6,
	NETPROXYTYPE_SOCKS5_HOSTNAME = 7,
} netProxyType;

struct st_netProxyConfig {
	st_netProxyConfig() : port(0) {}
	netProxyType   type;
	std::string    addr;
	uint16       port;
	std::string    user;
	std::string    passcode;
};

/**
 * \brief 网络配置
 * PC专用
 */
struct st_net {
	/**
	 * \brief 每条记录格式为　　起始ＩＰ-终止ｉＰ
	 * X.X.X.X-X.X.X.X
	 */
	std::vector<std::string>  addrlist;
	
	const std::string output_parameter()
	{
		std::stringstream ss;
		ss << "st_net::addrlist.size() ＝ " << addrlist.size() << "\n";
		for (unsigned int i = 0; i < addrlist.size(); i++)
		{
			ss << "st_net::addrlist[ " << i << " ] ＝ " << addrlist[i] << "\n";
		}

#ifdef LOCAL_DEBUG
		std::cout << ss.str();
#endif
		return ss.str();
	}
};

/**
 * \brief 登录地址结构
 */
struct st_loginAddress {
	std::string strIp ; ///< IP地址或者域名
	uint16      port  ; ///< 端口
	st_loginAddress() {
		port = 80 ;
	}
	
	const std::string output_parameter()
	{
		std::stringstream ss;
		ss << "st_loginAddress::strIp ＝ " << strIp << "\n";
		ss << "st_loginAddress::port ＝ " << port << "\n";

#ifdef LOCAL_DEBUG
		std::cout << ss.str();
#endif
		return ss.str();
	}
};

/**
 * \brief 预登录附加结构
 */
struct st_loginExData {
	st_loginExData() :allowLogin(0), sysConfig(0) {}
	///输入信息
	std::string   srvName ;  ///< 服务器名称,获取时候必须填写 !!!
	/**
	 * \brief 设备信息 , 获取时候必须填写 !!!
	 * 例如 pc-window7,an-xiaomei2,ios-iphone4s
	 */
	std::string   device ;
	std::string   local  ;
	std::string   version ;
	std::string   mark ;
	std::string   mac ;
	std::string   acoount ;
	std::string   cookiet;
	std::string   netType ;
	std::string   loginType;

	///下面为输出信息
	std::string   eLogo ;   ///<　英文ＬＯＧＯ
	std::string   imName ;  ///<　名称
	std::string   bgImg  ;  ///<　背景图片
	std::string   eName  ;  ///<　企业名称
	std::string   logoImg ; ///<　标识图片
    int64         allowLogin; ///< 允许登录项 1-iOS 2-Android 4-PC 8-Mac
    int64         sysConfig;  ///< 系统设置 各种开关合集
	std::string Orijson ; ///< 原始的ＪＳＯＮ
};

struct st_subSrv {
	st_subSrv() :userid(0), type(0), topTime(0){}
	std::string  addr;  ///< 服务器地址
	int64        userid;///< 用户ＩＤ
	std::string  name ; ///< 登录账号名称
	std::string  avatar ; ///< 头像
	std::string  account ;///< 账号
	std::string  remark ;
	int8         type ;  ///< 账号类型
	int64		topTime;  ///<置顶时间，0标识没有置顶
	std::string verImgPath; ///客服信息
	std::string serverHead; ///服务器头像
};

///预登录结构体
struct st_preLogincfg {
	st_preLogincfg() :userid(0) {}
	std::string  area;     ///< 输入 服务器
	std::string  account ; ///< 输入 账号
	int64 userid ;         ///< 输出 用户ID 
	std::string  json ;    ///< 输出 输出预登录结果
};

///登录票
struct st_outterTicket {
	st_outterTicket() :userid(0) {}
	int64       userid ;     ///用户ID
	std::string ticket ;     ///ID对应的票
};
//应用校验信息
struct st_appVerifyInfo{
	std::string issuer;//pc和Android需要填写
	std::string signature;//Android需要填写
};
struct st_loginStatusInfo{

	int32 status; // 0：没有网络连接 1：没有登录, 但是网络联通 2：正在登录 3：断线重连状态 4：正常状态
	int32 lastLoginCode;
};

struct st_cfgDomain
{
	std::string domain;
	std::vector<std::string> ipArr;
};

#endif /* PROTOCOL_CFGEXPORT_H_ */
