#include "Environment.h"
namespace serviceTest {
    class AuthServiceUnitest /*:public testing::Test*/ {
	public:
		AuthServiceUnitest();
		virtual ~AuthServiceUnitest();
		int prelogin();								//******************Ԥ��½**************
		int abortLogin();							//******************ȡ����¼**************	//����ûʵ��
		int quickRegister();						//******************����ע��**************  
		int beforeLogin();							//******************��¼ǰ����**************
		int getRegCode();							//******************��ȡ��֤��**************
		int signup();								//******************ע��**************
		int signupEx();								//******************ע��**************
		bool verifyImgCode();						//******************���ߵ�¼**************
		int loginSpecial();							//******************����ת���ߵ�½**************
		int offlineLogin();							//******************PCר�õ�¼**************
		int offLineToLogin();						//******************�Զ���¼**************
		int autoLogin();							//******************��¼**************
		int logoutLocal();							//******************��֤��¼��֤����߻�ȡ��һ����֤��**************
		int loginEx();								//******************��ȡ��ȫ����URL**************
		int getSecUrl();							//******************��ȡClient Key**************
		int getClientKey();							//******************�����ǳƺ�����**************
		int setNameAndPasswd();						//******************�޸�����**************
		int changePassword();						//******************��ȡ����������֤��**************
		int getResetPwCode();						//******************��������**************
		int resetPasswd();							//******************��ȡ���븴�Ӷ�**************
		int getPasswordRule();						//******************��ȡ���ֻ�����֤��**************
		int getBindPhoneCode();						//******************������֤����ֻ�**************
		int bindPhone();							//******************������**************
		bool bindMail();							//******************��ȡ�ֻ���������֤����֤��**************
		int getVerifyMailOrPhoneCode();				//******************��֤��������ֻ���֤��**************
		int verifyMailOrPhoneCode();				//******************��ȡ��¼��Ϣ(ͬ���ӿ�)**************
		int getLoginInfo();							//******************��ȡOauth ��Ȩ��**************
		int getLoginAuthCode();						//******************�����û�ID���û����Ͷ���**************
		int getqVerifyCodes();						//******************��ȡ��Ȩƾ֤**************
		int getAuthAccessToken();					//******************У��accessToken�Ƿ����**************
		int checkOrRefreshAccessToken();			//******************����Ӧ����Ȩƾ֤��ȡ�û���Ϣ**************
		int getAuthUserBean();						//******************������ַ���ӻ�ȡ��Ȩ��**************
		int getWebSiteAuth();						//******************������������ǩ����֤**************
		int verifyPKSign();							//******************��ȡ֤�����ʱ��**************
		bool getCertOutDate();						//******************��ȡ֤��ʹ��������**************
		int getCertOrgName();						//******************��ȡ֤��ʹ��������**************
		int signupOld();							//******************ɨ���¼��̨**************
		int scanCodeLogin();						//******************��ȡ���һ�������ɹ�ʱ��**************
		int getLastHBTime();						//******************PC�˶�ά��ɨ���ȡ��ά����Ϣ�ӿ� ��PC************
		int getPCLoginQrcode();						//******************PC�˶�ά��ɨ���ȡ��ά��״̬�ӿ� ��PC************
		int getQrLoginStatus();						//******************��ȡ��ά��״̬�Ƿ��ѱ�ɨ���¼��Ϣ ���ƶ���******
		int scanPCLoginQrCode();					//******************ȷ�ϵ�¼ȡ����¼��ά��ӿ� ���ƶ���**************
		int confirmPCLogin();						//******************У�����һ��PCɨ���¼�豸�ӿ�**************
		int checkQrLoginDevice();					//******************PC�˿��ٵ�¼�ӿ�**************
		int pcQuickLogin();							//******************��ȡ�û��˻�ע��У����**************  ����100
		int getLogoutCode();						//******************�û��˺�ע��**************				����C0000

		int setLogoutAccount();						//******************�û��˺�ע��******************
		int authPcBrowserLoginTokenCheck();			//******************PC���������Ȩ��֤��¼��֤******************
		int configJssdkAuthLocal();					//******************JssdkAuth�������������У�飬�Ϸ�ʱ�������ݿ�******************
		int checkJssdkAuthLocal();					//******************JssdkAuth���������洢�����ݿ��е���Ϣ����ƥ��******************
		int checkJssdkAuthLocalByAppId();			//******************JssdkAuth���������洢�����ݿ��е���Ϣ����ƥ��******************
		int thirdPartyAuthbyToken();				//******************�������û���ʶ��Ȩ����������idToken��ȡ�û�userId******************
		int SetBifactorLogin();						//******************˫���ӵ�¼����******************
		int MQrCodeQuery();							//******************�ͻ��˽ӿ� (��M�ж�ά��ɨ���¼)******************
		int getMCircleQrCode();						//******************�ͻ��˽ӿ� (��M�ж�ά��ɨ���¼)*****************
		int showVerifyUserPassword();				//******************������У����棬����ͨ�ӿ�******************
	protected:
		virtual void TestBody() {}
	private:
		std::shared_ptr<IAuthService> m_authService = nullptr;
		std::shared_ptr<IConfigService> m_configService = nullptr;
	};											
}												
												
												
												
								