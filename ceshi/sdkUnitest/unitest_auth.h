#include "Environment.h"
namespace serviceTest {
    class AuthServiceUnitest /*:public testing::Test*/ {
	public:
		AuthServiceUnitest();
		virtual ~AuthServiceUnitest();
		int prelogin();								//******************预登陆**************
		int abortLogin();							//******************取消登录**************	//代码没实现
		int quickRegister();						//******************快速注册**************  
		int beforeLogin();							//******************登录前操作**************
		int getRegCode();							//******************获取验证码**************
		int signup();								//******************注册**************
		int signupEx();								//******************注册**************
		bool verifyImgCode();						//******************离线登录**************
		int loginSpecial();							//******************离线转在线登陆**************
		int offlineLogin();							//******************PC专用登录**************
		int offLineToLogin();						//******************自动登录**************
		int autoLogin();							//******************登录**************
		int logoutLocal();							//******************验证登录验证码或者获取下一张验证码**************
		int loginEx();								//******************获取安全中心URL**************
		int getSecUrl();							//******************获取Client Key**************
		int getClientKey();							//******************设置昵称和密码**************
		int setNameAndPasswd();						//******************修改密码**************
		int changePassword();						//******************获取重置密码验证码**************
		int getResetPwCode();						//******************重置密码**************
		int resetPasswd();							//******************获取密码复杂度**************
		int getPasswordRule();						//******************获取绑定手机的验证码**************
		int getBindPhoneCode();						//******************利用验证码绑定手机**************
		int bindPhone();							//******************绑定邮箱**************
		bool bindMail();							//******************获取手机或邮箱验证码验证码**************
		int getVerifyMailOrPhoneCode();				//******************验证码邮箱或手机验证码**************
		int verifyMailOrPhoneCode();				//******************获取登录信息(同步接口)**************
		int getLoginInfo();							//******************获取Oauth 授权码**************
		int getLoginAuthCode();						//******************根据用户ID向用户发送短信**************
		int getqVerifyCodes();						//******************获取授权凭证**************
		int getAuthAccessToken();					//******************校验accessToken是否过期**************
		int checkOrRefreshAccessToken();			//******************根据应用授权凭证获取用户信息**************
		int getAuthUserBean();						//******************根据网址链接获取授权码**************
		int getWebSiteAuth();						//******************对升级包进行签名认证**************
		int verifyPKSign();							//******************获取证书过期时间**************
		bool getCertOutDate();						//******************获取证书使用者名称**************
		int getCertOrgName();						//******************获取证书使用者名称**************
		int signupOld();							//******************扫码登录后台**************
		int scanCodeLogin();						//******************获取最后一次心跳成功时间**************
		int getLastHBTime();						//******************PC端二维码扫描获取二维码信息接口 仅PC************
		int getPCLoginQrcode();						//******************PC端二维码扫描获取二维码状态接口 仅PC************
		int getQrLoginStatus();						//******************获取二维码状态是否已被扫描登录信息 仅移动端******
		int scanPCLoginQrCode();					//******************确认登录取消登录二维码接口 仅移动端**************
		int confirmPCLogin();						//******************校验最后一次PC扫码登录设备接口**************
		int checkQrLoginDevice();					//******************PC端快速登录接口**************
		int pcQuickLogin();							//******************获取用户账户注销校验码**************  返回100
		int getLogoutCode();						//******************用户账号注销**************				错误C0000

		int setLogoutAccount();						//******************用户账号注销******************
		int authPcBrowserLoginTokenCheck();			//******************PC端浏览器授权认证登录认证******************
		int configJssdkAuthLocal();					//******************JssdkAuth传入参数与服务端校验，合法时存入数据库******************
		int checkJssdkAuthLocal();					//******************JssdkAuth传入参数与存储在数据库中的信息进行匹配******************
		int checkJssdkAuthLocalByAppId();			//******************JssdkAuth传入参数与存储在数据库中的信息进行匹配******************
		int thirdPartyAuthbyToken();				//******************第三方用户标识鉴权新增，根据idToken获取用户userId******************
		int SetBifactorLogin();						//******************双因子登录请求******************
		int MQrCodeQuery();							//******************客户端接口 (仅M盒二维码扫描登录)******************
		int getMCircleQrCode();						//******************客户端接口 (仅M盒二维码扫描登录)*****************
		int showVerifyUserPassword();				//******************打开密码校验界面，民情通接口******************
	protected:
		virtual void TestBody() {}
	private:
		std::shared_ptr<IAuthService> m_authService = nullptr;
		std::shared_ptr<IConfigService> m_configService = nullptr;
	};											
}												
												
												
												
								