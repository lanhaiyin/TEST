#pragma once

#include "../model/LoginInfo.h"
#include "../model/Packet.h"
#include "../model/Account.h"
#include "IService.h"
#include <string>

#define VER_IAUTH INTERFACE_VERSION(1,0)
static const VRVIID IID_IAuthSrvice = { 0x3271f2c2, 0xb855, 0x4234, 0x9f, 0x8b, 0x4d, 0x86, 0xd0, 0x6c, 0x2b, 0xb7 };

namespace service 
{

class IAuthService : public IService
{
public:
		
	virtual ~IAuthService(){};

	/*****************************************注册通知回调*******************************************/

	/**
	* \brief 监听网络连接状态
	* @param[out] cb 0代表网络ＯＫ，非零是网络异常
	* -1表示与服务器无法建立连接
	* -2表示推送连接两次尝试失败，客户端收到-2后根据系统api提供的4Gwifi网络状态和sdk提供的ap请求异常，判断服务器是否宕机
	* -3表示推送线程退出，客户端收到-3后如果再收到请求接口返回-16777171或者regReLoginCb接口返回115，可以报登录状态异常
	*/
	virtual void regNetChangedCb(SFunction< void(int) > cb) = 0;

	/**
	* \brief 监听补链结果
	* @param[out] cb 0代表补链完成，非零是异常
	*/
	virtual void regPullMsgCb(SFunction< void(int) > cb) = 0;

	/**
	* \brief 设置监听数据库升级完成的回调
	* @param[out] cb 0代表开始 1代表升级完成 2升级失败
	*/
	virtual void regDbUpdatedCb(SFunction< void(int) > cb) = 0;

	/**
	* \brief 设置监听数据库升级完成的回调，带进度条
	* @param[out] cb  _1：0代表开始 1代表升级完成 2升级失败 3升级进行中 _2升级进行中时使用，进度0代表0%，100代表100%
	*/
	virtual void regDbUpdatedProcessCb(SFunction< void(int,int64) > cb) = 0;

	/**
	* \brief 重新登录时推送
	* @param[out] cb  _1 错误标示,  _2用户ID
	*/
	virtual void regReLoginCb(SFunction< void(int, int64) > cb) = 0;

	/**
	* \brief 登陆跳转url,返回code推送
	* @param[out] cb _1 暂时不用, _2 返回信息
	*/
	virtual void regOAuthInfoCb(SFunction< void(int32, const std::string&) > cb) = 0;

	/**
	* \brief 版本升级推送
	* @param[out] cb 版本升级信息结构 见packet.h
	*/
	virtual void regUpgrageCb(SFunction< void(UpgradeInfo&) > cb) = 0;

	/**
	* \brief 监听服务器端推送的Qrcode字符串
	* @param[out] cb Qrcode string 字符串代表推送的二维码QrCode的string
	*/
	virtual void regScanQrCb(SFunction< void(const std::string&) > cb) = 0;

	/**
	* \brief 获取是否有后台请求
	* @param[out] cb 结果回调 _1 错误信息 0:成功，_2 返回结构体信息 如果SUBTYPE 是5 需要获取adminName 如果是6获取status
	*/
	virtual void regGetServerRequst(SFunction<void(int, BifactorSt&) >cb) = 0;
	/*****************************************请求接口*******************************************/

	/**
	* \brief 快速注册
	* @param[in] server 传入服务器地址，域名或IP均可
	* @param[in] name 用户昵称
	* @param[in] account 传入注册账号 如果是手机账户格式为“0086158********”
	* @param[in] passwd 密码
	* @param[out] cb 传入接收结果回调 _1错误信息  _2超时
	*/
	virtual void quickRegister(const std::string &server, const std::string &name, const std::string &account, const std::string &passwd, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 获取注册验证码
	* @param[in] server 服务器或邀请码
	* @param[in] account 传入注册账号 目前只支持手机注册 手机账户格式为“0086********”
    * @param[in] type 1.获取手机号注册验证码 2.获取手机号登录验证码 3.更换手机获取验证码
	* @param[out] cb 传入接收结果回调 _1错误信息  _2超时
	*/
	virtual void getRegCode(const std::string& server, const std::string &account, int8 type, SFunction<void(ErrorInfo, int/*超时*/)> cb) = 0;

	/**
	* \brief 注册用户
	* @param[in] regCode 验证码
	* @param[in] account 注册账号 手机账户格式为“0086158********”
	* @param[out] cb 传入接收结果回调  _1错误信息 _2如果是通过邀请码注册，返回邀请码创建者ID
	*/
    virtual void signup(const std::string& regCode, const std::string &account, SFunction<void(ErrorInfo, int64, int64)> cb) = 0;

	/**
	* \brief 注册用户扩展，可返回我的客服信息
	* @param[in] regCode 验证码
	* @param[in] account 注册账号 手机账户格式为“0086158********”
	* @param[out] cb 传入接收结果回调  _1错误信息 _2如果是通过邀请码注册，返回邀请码创建者ID _3客服数据 _4邀请码好友添加开关
	*/
	virtual void signupEx(const std::string& regCode, const std::string &account, SFunction<void(ErrorInfo, int64, int64,const std::string&, int8)> cb) = 0;

	/**
	* \brief 同时设置昵称和密码(signup后调用)
	* @param[in] name 用户名
	* @param[in] passwd 密码
	* @param[out] cb 传入接收结果回调  _1错误信息
	*/
	virtual void setNameAndPasswd(const std::string& name, const std::string &passwd, SFunction<void(ErrorInfo)> cb) = 0;
	
	/**
	* \brief 获取重置密码验证码
	* @param[in] server 服务器
	* @param[in] account 传入注册账号 如果是手机账户格式为“0086********”
	* @param[out] cb 传入接收结果回调 _1错误信息  _2超时
	*/
	virtual void getResetPwCode(const std::string& server, const std::string &account, SFunction<void(ErrorInfo, int/*超时*/)> cb) = 0;

	/**
	* \brief 重置密码
	* @param[in] regCode 验证码
	* @param[in] user    传入用户名，为空代表不改名
	* @param[in] pwd	 传入新密码
	* @param[out] cb 传入接收结果回调  _1错误信息
	*/
	virtual void resetPasswd(const std::string& regCode, const std::string &user, const std::string &pwd, SFunction<void(ErrorInfo)> cb) = 0;
		
	/**
	* \brief 获取密码复杂度
	* @param[in] cb 传入接收结果回调 _1错误信息
	*  _2密码规则: 
	*	高8位代表最小长度
	*	低8位，按照最低位开始，依次代表:(1代表必须，0 表示可选)
	*	1. 是否必须有数字
	*	2. 是否必须有小写字母
	*	3. 是否必须有大写字母
	*	4. 是否必须有英文字母
	*	5. 是否必须有字符(特殊字符)
	*	6. 是否允许注册(1允许，0不允许)
	*/
	virtual void getPasswordRule(SFunction<void(ErrorInfo, int)> cb) = 0;

	//////////////////////////////////////////////////////////////////////////
	//	登录相关接口

	/**
	*  \brief 预登录
	* @param[in] server 传入服务器地址，域名或IP均可
	* @param[out] cb 传入接收结果回调 _1错误信息  _2预登陆返回json
	* @return	int64 返回当前localID，用于取消该次执行
	*/
	virtual int64 prelogin(const std::string& server, SFunction<void(ErrorInfo, std::string&)> cb) = 0;
	/**
	*  \brief 预登录带有升级检查
	* @param[in] server 传入服务器地址，域名或IP均可
	* @param[in] userType 1-7为账号密码登录 1.手机  2.qq 3.邮箱  4.豆豆号 5.身份证, 6.豆豆账号 7.自定义账号   96.手机号验证码登录 97.更换手机验证码登录 -1 二维码扫描登录专用 使用user传userid  pwd传票据进行登录
	* @param[out] cb 传入接收结果回调 _1错误信息  _2预登陆返回json
	* @return	int64 返回当前localID，用于取消该次执行
	*/
	virtual int64 prelogin(const std::string& server, const int8 userType,SFunction<void(ErrorInfo, std::string&)> cb) = 0;
	/**
	*  \brief 登录 loginSpecial为PC专用接口，其他客户端不要使用
	* @param[in] user 传入用户名 如果是手机账户格式为“0086158********”
	* @param[in] pwd 传入密码
	* @param[in] server 传入服务器地址，域名或IP均可
    * @param[in] userType  1-7为账号密码登录 1.手机  2.qq 3.邮箱  4.豆豆号 5.身份证, 6.豆豆账号 7.自定义账号   96.手机号验证码登录 97.更换手机验证码登录 -1 二维码扫描登录专用 使用user传userid  pwd传票据进行登录，login接口改造
	* @param[in] thirdParam 第三方参数json
	* @param[out] cb 传入接收结果回调 _1错误信息  _2 用户Id  _3 帐号被锁定剩余时长   _4 登录失败返回1102错误时的验证码路径 返回100001575错误(更换设备)为手机号，成功时返回我的客服数据
	* @return	int64 返回当前localID，用于取消该次执行
	*/
	virtual int64 login(const std::string& user, const std::string& pwd, const std::string& server, int8 userType,
						SFunction<void(ErrorInfo, int64,int64, const std::string&)> cb) = 0;

	virtual int64 loginEx(const std::string& user, const std::string& pwd, const std::string& server, int8 userType,
		const std::string& thirdParam, SFunction<void(ErrorInfo, int64, int64, const std::string&)> cb) = 0;

	virtual int64 loginSpecial(const std::string& user, const std::string& pwd, const std::string& server, int8 userType,
		SFunction<void(ErrorInfo, int64, int64, const std::string&)> cb) = 0;

	/*
	*  \brief 获取登录结果（防诈骗必须登录之后调用）
	* @return	LoginResult
	*/
	virtual LoginResult getloginresult()= 0;
	//离线转在线接口
	/**
	 * @param[in] server 传入服务器地址，域名或IP均可
	 * @param[out] cb 传入接收结果回调 _1错误信息  _2用户Id  _3 帐号被锁定剩余时长  _4 返回1102错误时的验证码路径
	 * @return	int64 返回当前localID，用于取消该次执行
	 */

	virtual int64 offLineToLogin(const std::string& server,SFunction<void(ErrorInfo, int64, int64, const std::string&)> cb) = 0;
	//登录

	/**
	* \brief 自动登录（不用填密码）
	* @param[in] userid 传入用户ID
	* @param[in] server 传入服务器地址，域名或IP均可
	* @param[out] cb 传入接收结果回调 _1错误信息  _2用户Id  _3 帐号被锁定剩余时长  _4 返回1102错误时的验证码路径
	* @return	int64 返回当前localID，用于取消该次执行
	*/
	virtual int64 autoLogin(int64 userid, const std::string &server, SFunction<void(ErrorInfo, int64, int64, const std::string&)> cb) = 0;

	/**
	* \brief 离线登录
	* @param[in] userId 用户id
	* @param[in] pwd 密码
    * @param[in] elogo 服务器标识
	* @param[out] cb 传入接收结果回调 _1错误信息 
	*/
    virtual void offlineLogin(int64 userId, const std::string& pwd, const std::string& elogo, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	 * \brief 无密码登录
	 * @param[in] userId 用户id
	 * @param[in] elogo 服务器标识
	 * @param[out] cb 传入接收结果回调 _1错误信息
	 */
	virtual void offlineLoginNoPwd(int64 userId, const std::string& elogo, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	 * \brief 验证密码是否正确
	 * @param[in] userId 用户id
	 * @param[in] pwd 密码
	 * @param[in] elogo 服务器标识
	 * @param[out] cb 传入接收结果回调 _1错误信息
	 */
	virtual void loginPwdVerify(int64 userId, const std::string& pwd, const std::string& elogo, SFunction<void(ErrorInfo)> cb) = 0;
	
	/**
	* \brief 输入密码，返回加密后的字符串
	* @param[out] cb 传入接收结果回调 _1错误信息  _2 返回加密字符串
	*/
	virtual void loginPwdEncrypt(const std::string& pwd, SFunction<void(ErrorInfo, const std::string&)> cb) = 0;

	/**
	* \brief 登出
	* @param[out] cb 传入接收结果回调  _1错误信息
	*/
	virtual void logout(SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 第三方认证登出 PC专用 用于第三方应用认证退出客户端程序时候调用
	*
	*/
	virtual void appAuthLogout(SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 本地登出
	* @param[out] cb 传入接收结果回调  _1错误信息
	*/
	virtual void logoutLocal(SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 取消登录
	* @param[in] operateid 传入对应登录操作的ID
	* @param[out] cb 传入接收结果回调  _1错误信息
	*/
	virtual void abortLogin(int64 operateid, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 验证登录验证码或者获取下一张验证码
	* @param[[in] account 传入登录账号
	* @param[[in] code	 传入验证码内容 code为空则获取下一张验证码
	* @param[[out] cb 传入接收结果回调 _1错误信息  _2 下一张验证图片
	*/
	virtual void verifyImgCode(const std::string& account, const std::string& code, 
							SFunction<void(ErrorInfo, const std::string&)> cb) = 0;

	/**
	* \brief 获取安全中心URL
	* @param[in] server 传入企业服务器
	* @param[out] cb 传入接收结果回调 _1错误信息  _2 url
	*/
	virtual void getSecUrl(const std::string &server, SFunction<void(ErrorInfo, const std::string&)> cb) = 0;

	/**
	* \brief 修改密码
	* @param[in] oldPw 传入旧密码
	* @param[in] newPw 传入新密码
	* @param[out] cb 传入接收结果回调  _1错误信息
	*/
	virtual void changePassword(const std::string &oldPw, const std::string &newPw, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 获取CLIENTKEY
	* @param[out] cb 传入接收结果回调  _1错误信息  _2 clientkey
	*/
	virtual void getClientKey(SFunction<void(ErrorInfo, const std::string&)> cb) = 0;

	/**
	* \brief 获取绑定手机验证码
	* @param[in] phone 手机号
	* @param[in] language 语言
	* @param[out] cb 传入接收结果回调  _1错误信息  _2超时重发时间  _3注册ID
	*/
	virtual void getBindPhoneCode(const std::string &phone, const std::string &language, SFunction<void(ErrorInfo, int32, int64)> cb) = 0;

	/**
	* \brief 通过获取的验证码绑定手机
	* @param[in] phone 手机号
	* @param[in] code 验证码
	* @param[in] registryID 获取验证码时返回的ID
	* @param[out] cb 传入接收结果回调  _1错误信息 0成功 100参数不正确 120账号不存在 381未指定接受者  382未指定接收者类型 
	*				383验证码已过期 384验证码不正确  385发送间隔时间太短 386发送失败  387：未发送过验证码 
	*/
	virtual void bindPhone(const std::string &phone, const std::string &code, int64 registryID,  SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 绑定邮箱
	* @param[in] mail  邮箱号
    * @param[in] lang  语言 zh_cn:中文 en_us:英文
	* @param[out] cb 传入接收结果回调  _1错误信息 0:成功，100:参数错误，120: 帐号不存在，510:帐号已被使用
	*/
    virtual void bindMail(const std::string &mail, const std::string& lang, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 获取手机或邮箱验证码验证码
	* @param[in] type  1.手机  2.邮箱
	* @param[in] mailOrPhone 邮箱或手机
	* @param[in] lang 语言
	* @param[out] cb 传入接收结果回调  _1错误信息  _2超时重发时间 _3唯一注册ID
	*/
	virtual void getVerifyMailOrPhoneCode(int8 type, const std::string &mailOrPhone, const std::string &lang, SFunction<void(ErrorInfo, int32, int64)> cb) = 0;

	/**
	* \brief 验证码邮箱或手机验证码
	* @param[in] type  1.手机  2.邮箱
	* @param[in] code 验证码
	* @param[in] registryId 唯一注册ID
	* @param[out] cb 传入接收结果回调  _1错误信息 0成功 120: 帐号不存在		381: 未指定接收者
										382: 未指定接收者类型            	383: 验证码已过期
										384: 验证码不正确 					385: 发送间隔时间太短
										386: 发送失败 						387：未发送过验证码
	*/
	virtual void verifyMailOrPhoneCode(int8 type, const std::string &code, int64 registryId,SFunction<void(ErrorInfo)> cb) = 0;
	
	/**
	* \brief 获取登录信息。(同步接口)
	* @param[out] data  用户传入的内存地址，获取成功后，把信息拷贝到此内存中
	* @param[in] len 用户传入内存地址的长度
	* @param[return] 返回0代表获取失败，否则，返回获取数据的实际长度
	*/
	virtual int getLoginInfo(uint8 *data, int len) = 0;

	/**
	* \brief 获取Oauth 授权码
	* @param[in] oauth oauth请求结构，见packet.h
	* @param[out]  cb 传入接收结果回调  _1错误信息 _2授权码
	*/
	virtual void getLoginAuthCode(oauthReq& oauth, SFunction<void(ErrorInfo, const std::string&)> cb) = 0;
	/**
	*根据用户ID向用户发送短信
	*/
	virtual void getqVerifyCodes(qVerifyCodes&, SFunction<void(ErrorInfo,std::map<int64,std::string>&)> cb) = 0;

	/**
	*根据新朋友的用户ID向朋友发送添加好友的短信，好友提醒
	*/
	virtual void sendbuddyReminder(std::vector<int64> userIds, SFunction<void(ErrorInfo, std::map<int64, std::string>&)> cb) = 0;

	/**
	*\brief    获取授权凭证
	*@param[in] appID         应用ID
	*@param[in] accountType   登陆账号类型
	*@param[in] appSecret     企业应用密钥一个凭证,如果appSecret为空，表示获取授权码，如果不为空表示获取授权凭证
	*@param[out] code  cb 传入接收结果回调  _1错误信息 _2授权凭证
	*/
	virtual void getAuthAccessToken(int64 appID, std::string& accountType, std::string& appSecret, SFunction<void(ErrorInfo, const std::string&)> cb) = 0;
	/**
	*\brief 校验accessToken是否过期
	*@param[in] appID         应用ID
	*@param[in] type		  10,校验accessToken是否过期 11刷新accessToken,获得新的accessToken
	*@param[in] accessToken   授权凭证（accessToken，上一步骤获取的）
	*@param[out] code  cb 传入接收结果回调  _1错误信息 _2新的授权凭证 type = 11时使用
	*/
	virtual void checkOrRefreshAccessToken(int64 appID, int type, std::string& accessToken, SFunction<void(ErrorInfo, const std::string&)> cb) = 0;
	/**
	*\brief 根据应用授权凭证获取用户信息
	*@param[in] appID         应用ID（appID）
	*@param[in] accessToken   app授权凭证
	*@param[out] code  cb 传入接收结果回调  _1错误信息 _2见packet.h
	*/
	virtual void getAuthUserBean(int64 appID, std::string& accessToken, SFunction<void(ErrorInfo, AuthUserBean&)> cb) = 0;
	/**
	* \brief   根据网址链接获取授权码，返回的授权码会拼接到网址后面返回,格式为&auth_code=授权码
	* 如:入参:http(s) ://vrv.linkdood/platform/api2/oauth/authorize?id=APPID&st=STATE&sc=SCOPE&uri=xxxxxx
	*    出参:http(s) ://vrv.linkdood/platform/api2/oauth/authorize?id=APPID&st=STATE&sc=SCOPE&uri=xxxxxx&auth_code=yyyyyy
	*@param[in] webSite       网址链接
        webSite中必须有"/platform/api2/oauth/authorize?id=","&st=","&sc=","&uri="这些字段,否则认为不是合法的网址，返回错误，code值对应err_sdk_paramInvalidat宏表示的值；
	*@param[out] code  cb 传入接收结果回调  _1错误信息 _2授权码
	*/
	virtual void getWebSiteAuth(std::string& webSite, SFunction<void(ErrorInfo,std::string&)> cb) = 0;
	/**
	*\brief 对升级包进行签名认证
	*@Param[in] filePath 下载的升级包文件本地路径
	*@Param[in] certPath 证书路径
	*@Param[in] dsg      签名
	*@return  true 验证通过 false 验证失败
	*/
	virtual bool verifyPKSign(const char* filePath, const char* certPath, std::string& dsg) = 0;
	/**
	*\brief 获取证书过期时间
	*/
	virtual int64 getCertOutDate() = 0;
	
	/**
	*\brief 获取证书使用者名称
	*/
	virtual std::string getCertOrgName(const std::string &elogo = "") = 0;

    /**
    * \brief 旧版本注册用户
    * @param[in] regCode 验证码
	* @param[in] user    传入用户名，建议使用真实姓名
	* @param[in] pwd	 传入注册密码
	* @param[out] cb 传入接收结果回调  _1错误信息 _2如果是通过邀请码注册，返回邀请码创建者ID
	*/
    virtual void signupOld(const std::string& regCode, const std::string &user, const std::string &pwd, SFunction<void(ErrorInfo, int64)> cb) = 0;

	/**
	* \brief 扫码登录后台
	* @param[in] qId		二维码标识
	* @param[in] serverUrl	后台服务Url
	* @param[in] type		操作类型 1.扫描检测 2.二维码登录
	* @param[out] cb 传入接收结果回调  _1错误信息 _2错误描述
	*/
	virtual void scanCodeLogin(int64 qId, const std::string& serverUrl, int8 type, SFunction<void(ErrorInfo, std::string&)> cb) = 0;
	/**
	*\brief 获取最后一次心跳成功时间
	*@param[out] lastHBTime最后一次心跳成功时间 13位Unix时间戳，精确到毫秒
	*/
	virtual int64 getLastHBTime() = 0;

	/**
	*\brief 获取设备类型
	*/
	virtual int  GetDevType() = 0;
	 
	/**
	*\brief 设置设备类型
	*@param[in] nType 设备类型 1：PC；2：手机；3：pad；4：网页
	*/
	virtual bool SetDevType(int nType) = 0;

	/**
	* \brief 登录前操作
	* @param[in] type		操作类型
	* @param[in] func		方法名
	* @param[in] value		json参数 透传
	* @param[out] cb 传入接收结果回调  _1错误信息 _2错误描述 _3返回的json结果
	*/
	virtual void beforeLogin(int8 type, const std::string& func, const std::string& value, SFunction<void(ErrorInfo, std::string&, std::string&)> cb) = 0;


	/**
	* \brief PC端二维码扫描获取二维码信息接口 仅PC
	* @param[in] elogo 		服务器elogo
	* @param[out] cb 传入接收结果回调  _1错误信息 _2错误描述 _3返回的json结果 二维码数据信息
	*/
	virtual void getPCLoginQrcode(const std::string& elogo, SFunction<void(ErrorInfo, std::string&, std::string&)> cb) = 0;

	/**
	* \brief PC端二维码扫描获取二维码状态接口 仅PC
	* @param[in] QrCodeId 		二维码唯一id
	* @param[in] qrCodeIdEv 	二维码唯一id加密值（二维码唯一id +盐后再MD5加密）
	* @param[out] cb 传入接收结果回调  _1错误信息 _2错误描述 _3返回的json结果 票据信息-登录成功才有
	*/
	virtual void getQrLoginStatus(const std::string& QrCodeId,const std::string& QrCodeIdEv, SFunction<void(ErrorInfo, std::string&, std::string&)> cb) = 0;


	/**
	* \brief 获取二维码状态是否已被扫描登录信息 仅移动端
	* @param[in] elogo 服务器elogo
	* @param[in] QrCodeId	 二维码唯一id，扫描二维码获取到
	* @param[out] cb 传入接收结果回调  _1状态信息 
	*/
	virtual void scanPCLoginQrCode(const std::string& elogo, const std::string& QrCodeId, SFunction<void(ErrorInfo, std::string&)> cb) = 0;

	/**
	* \brief 确认登录取消登录二维码接口 仅移动端
	* @param[in] QrCodeId	 二维码唯一id，扫描二维码获取到
	* @param[in] confirm 确认取消
	* @param[out] cb 传入接收结果回调  _1错误信息 _2错误描述  
	*/
	virtual void confirmPCLogin(const std::string& QrCodeId, int8 confirm, SFunction<void(ErrorInfo, std::string&)> cb) = 0;
	

	/**
	* \brief 校验最后一次PC扫码登录设备接口
	* @param[in] userid	 用户userid
	* @param[in] MacCode	 MAC地址 
	* @param[out] cb 传入接收结果回调  _1错误信息 _2错误描述  
	*/
	virtual void checkQrLoginDevice(int64 userid,const std::string& MacCode, SFunction<void(ErrorInfo, std::string&)> cb) = 0;

	/**
	* \brief PC端快速登录接口
	* @param[in] userid	 用户userid
	* @param[in] pcType  pcType  PC设备类型 1-windows，2-MAC
	* @param[out] cb 传入接收结果回调  _1错误信息_2错误描述 _3返回的json结果  用户信息数据
	*/
	virtual void pcQuickLogin(int64 userid, int8 pcType,SFunction<void(ErrorInfo, std::string&, std::string&)> cb) = 0;
	/**
	* \brief 通用接口
	* @param[in] 用户认证信息
	*            info说明：int8 logout_mode;                        //注销模式   1:注销用户密码认证，自动注销模式 2:申请注销密码认证，手动注销模式
	*					   int8 type;                               ///类型 4.用户账号注销校验（校验能不能注销）
																			5.用户注销（mode=1不需要审核，mode=2为发送申请注销请求到服务器）
	                                                                        6.查询注销状态（管理员审核客户端通过这个知道服务器的进度）
	                                                                        7.取消注销申请（所谓的取消注销就是取消管理员审核，注销是不可逆的）
	*					   std::string password;                    ///密码
	*                      std::string authenticationCode           ///type为5必须传入
	* @param[out] cb 传入接收结果回调  _1错误码:
												|#type = 4:                                                  #|   |#type = 6                         #|   |#type = 7                        #|
												|#100004500 成功，通过                                       #|   |#100004525  不存在待审核注销申请  #|   |#100004500  成功，通过           #|                                        
												|#100004520 接口异常、失败                                   #|   |#100004526  存在待审核注销申请    #|   |#100004525  不存在待审核注销申请 #|
												|#100004521 用户不存在                                       #|   
												|#100004522 密码错误                                         #|   |#type =5
												|#100004523 类型不合法                                       #|   |#100004524 注销验证码验证失败
												|#100004527 禁止注销/禁止申请注销                            #|
												|#100004528 注销(mode=1)/申请注销(mode=2)对应注销配置项不匹配#|
												|#100004530 账户被锁定                                       #|
												|#message 结果码说明                                         #|
												|#验证成功返回验证码,为authenticationCode                    #|

	*									_2结果码说明 _3验证成功返回验证码
	*/
	virtual void getLogoutCode(UserAuthenticationInfo &info, SFunction<void(ErrorInfo, std::string&, std::string&)> cb) = 0;
	/**
	* \brief 用户账号注销
	* @param[in] _1.是否是当前设备主动发起的注销请求 
	*							type = 1 当前设备主动发起
	*							type = 2 服务器推送,仅在服务器推送  OnlineState.flags = 15 号消息时使用 (回调注册接口为regPresentCb)
	*                           type现在不用了，只要调这个接口就删除本地数据
	*			_2.注销用户的验证码，type=1时 该参数不能为空，由getLogoutCode 函数获得,type=2 时 将该参数值设置为空。
	* @param[out] cb 传入接收结果回调  _1错误码
	*									0:成功
	*									100004520:接口异常
	*									100004521:用户不存在
	*									100004524:注销验证码验证失败
	*/
	virtual void setLogoutAccount(int type,const std::string &authenticationCode, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	*\brief PC端浏览器授权认证登录认证,需要认证通过豆豆PC客户端才能将clientKey以及用户信息返回给浏览器端,auth统一认证功能,只有pc端浏览器使用
	* @param[in] appId 公共号ID客户端提供
	* @param[in] loginToken  auth统一认证token
	*@param[out] cb 进度回调 _1错误信息 0:成功，100:参数错误，11100:内部错误; 100013076: loginToken认证失败
	*/
	virtual void authPcBrowserLoginTokenCheck(int64 appId, std::string &loginToken, SFunction<void(ErrorInfo)> cb) = 0;

	/*
	*\brief 	JssdkAuth传入参数与服务端校验，合法时存入数据库，appID唯一键重复时会更新已有数据 [12/1/2020 admin]
	* @param[in] jssdkAuth  jssdk结构体
	*			int64 appID;
	*			int64 timeStamp;
	*			std::string noncestr;
	*			std::string url;
	*			std::string signature;
	*			std::vector<std::string> jsApiList;
	*@param[out] cb 进度回调 _1错误信息 0:成功
	*/
	virtual void configJssdkAuthLocal(JssdkAuthInfo &jssdkAuth, SFunction<void(ErrorInfo)> cb) = 0;

	/*
	*\brief 	JssdkAuth传入参数与存储在数据库中的信息进行匹配，两个小时之内的鉴权信息才能成功 [12/1/2020 admin]
	* @param[in] jssdkAuth  jssdk结构体，校验时传入下面两个参数，其余参数默认
	*	In:		jssdkAuth.url
	*				jssdkAuth.jsApiList
	*@param[out] cb 进度回调 _1错误信息 
	*										100013102:成功
	*										100:参数错误
	*										11100:内部错误
	*										100013103:令牌无效令牌过期
	*										100013104:url域名无效域名验证错误code
	*										100013105:签名验证失败验证签名，验证不通过验证签名失败
	*										100013106:jsApiList接口验证错误
	*/
	virtual void checkJssdkAuthLocal(JssdkAuthInfo &jssdkAuth, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 第三方用户标识鉴权新增，根据idToken获取用户userId
	* @param[in] idToken 用户token，例{"id_token":"abcd"}
	* @param[out] cb 传入接收结果回调  _1错误码
	*										   0:成功
	*                                          100:未定义的type类型
	*                                          11100:调用底层接口失败
	*										   100008031:失败
	*										   100008032:系统出现异常
	*                                  _2返回user结果
	*/
	virtual void thirdPartyAuthbyToken(const std::string& idToken, SFunction<void(ErrorInfo, std::string&)> cb) = 0;
	
	
		/**
	*\brief 双因子登录请求
	* @param[in] nLoginType 登录认证类型 1后台 目前只有1
	* @param[in] nStatus  用户点击按钮状态 1同意 2拒绝
	* @param[in] nMessageID  消息ID
	* @param[in] nDeviceType  处理该请求的设备
	* @param[in] szUserName  管理员名称
	*@param[out] cb 结果回调 _1错误信息 0:成功，100:未知type，11100:内部失败 100008032:授权已失效 100008000:服务异常
	*/
	virtual void SetBifactorLogin(int8 nLoginType, int8 nStatus, int64 nMessageID, int8 nDeviceType, const std::string szUserName, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 客户端接口 (仅M盒二维码扫描登录)
	* @param[in] deviceflag	 1:PC 包括 windows MAC  2:移动客户端，包括安卓，IOS
	* @param[in] optflag	 操作 针对 (1--PC)：1.PC客户端向elogo查找服务请求elogo查询二维码  ，2：PC客户端从豆豆服务器获取了登陆二维码之后,向elogo查询服务器上报
	*                                                        (2--移动客户端)：1.手机客户端将本服务器的elogo上报给查询服务器
	* @param[in] param1	 根据上面入参 deviceflag-optflag，1-1 MAC地址      1-2 elogoQrId-Elogo查询二维码id    2-1 elogoQrId-Elogo查询二维码id
	* @param[in] param2	 根据上面入参 deviceflag-optflag，1-1 Ip地址            1-2 loginQrCode-登陆二维码             2-1 elogo 服务器elogo
	* @param[in] param3	 根据上面入参 deviceflag-optflag，只针对 2-1 MAC地址，checkCode,其他传空""即可
	* @param[out] cb 传入接收结果回调  _1错误信息码 (11020001参数错误  11020002生成失败) _2错误描述 _3 具体操作获取到的结果
	*/
	virtual void  MQrCodeQuery(int8 deviceflag, int8 optflag, const std::string& param1, const std::string&  param2, const std::string&  param3,SFunction<void(ErrorInfo, std::string&, std::string&)> cb) = 0;

	/**
	* \brief 客户端接口 (仅M盒二维码扫描登录)
	* @param[in] deviceflag	 1:PC 包括 windows MAC  2:移动客户端，包括安卓，IOS
	* @param[in] optflag	 操作 针对 (1--PC)：1.PC客户端周期向中转服务器请求查询结果
	*                                                        (2--移动客户端)：1.手机客户端周期向中转服务器中期查询PC是否上报了登陆二维码
	* @param[in] elogoQrId	  elogoQrId-Elogo查询二维码id
	* @param[out] cb 传入接收结果回调  _1错误信息码 (11020001参数错误  11020002生成失败) _2错误描述 _3 具体操作获取到的结果，如果错误返回为空
	*/
	virtual void  getMCircleQrCode(int8 deviceflag, int8 optflag, const std::string& elogoQrId, SFunction<void(ErrorInfo, std::string&, std::string&)> cb) = 0;
	/**
	* \brief 打开密码校验界面，民情通接口
	* @param[in] 用户密码
	* @param[out] cb  传入接收结果回调  _1错误码(0验证成功 100004522 密码错误 100004530 账号被锁定)
	 [3/9/2021 zhuohc]
	*/
	virtual void showVerifyUserPassword(const std::string &passwd, SFunction<void(ErrorInfo)> cb) = 0;

	/********************************获取用户通用token******************************************
	*返回：@param cb [out]传入接收结果回调  _1错误信息，_2 CommonTokenRsp(通用token信息)
	*/
	virtual void getCommonToken(SFunction<void(ErrorInfo, CommonTokenRsp&)> cb) = 0;

	/********************************校验通用token(通过用户通用token获取用户ID)******************************************
	*参数：@param strCommonToken	[in]用户通用token
	*返回：@param cb	[out]传入接收结果回调  _1错误信息，_2 CommonTokenRsp(通用token信息)
	*/
	virtual void checkCommonToken(std::string& strCommonToken, SFunction<void(ErrorInfo, CommonTokenRsp&)> cb) = 0;
};
} /*namespace service*/