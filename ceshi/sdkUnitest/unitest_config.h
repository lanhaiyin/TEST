#include "Environment.h"
namespace serviceTest {
	class ConfigServiceUnitest/*:public testing::Test*/ {
	public:
		ConfigServiceUnitest();
		int init();								//��ʼ��
		bool uninit();							//����ʼ��
		bool getLoginInfos();					//��ȡ��½��Ϣ
		bool delLoginInfo();					//ɾ��ĳ���û��ĵ�½��Ϣ
		bool getNetProxy();						//��ȡ�������
		bool setNetProxy();						//�����������
		bool setPlugPower();					//�����Ƿ��硣�ͻ������ã��ڣӣģ�����ʹ��
		bool setNetStatus();					//��������״̬
		bool getSdkVersion();					//��ȡsdk�汾��
		bool setAppVersion();					//����Ӧ����Ϣ
		bool setTextCoding();					//���ÿͻ������ֱ���
		bool setAppName();						//����Ӧ������
		bool headImgPath();						//��ȡͷ��·��
		bool getUserRcPath();					//��ȡ�û���ԴĿ¼
		bool userImgPath();						//��ȡ���û�������ͼƬ��Ϣ�ı���·�� 
		bool userAudioPath();					//��ȡ���û���������Ƶ��Ϣ�ı���·��
		bool userVideoPath();					//��ȡ���û���������Ƶ��Ϣ�ı���·��
		bool userCachePath();					//��ȡ���û�������cache
		bool userFilePath();					//��ȡ���û��������ļ���Ϣ�ı���·��
		bool userEmotionPath();					//��ȡ���û��������ļ��ı���·��
		bool getMsgParserMode();				//��ȡ��Ϣ������ʽ
		bool getLoginExData();					//��ȡԤ��¼��������
		bool setScreenStatus();					//��Ļ״̬ ��׿,IOSר��
		bool getSubServerInfo();				//��ȡ���������Ϣ
		bool setSubServerInfo();				//���ö��������Ϣ
		bool reNotifyData();					//������������
		bool getIsRoming();						//��ȡ��������
		bool setTicket();						//���õ�¼Ʊ��
		bool setMultichannel();					//�����Ƿ�����ͨ��
		bool getPreloginInfoEx();				//��ȡԤ��½��Ϣ
		bool setOffloginSwitch();				//�����Ƿ������ߵ�¼
		bool getOffloginStatus();				//��ѯ�Ƿ�������ߵ�¼
		bool getIsOpenSecPlugin();				//��ȡ�Ƿ����˵��˼���
		bool setHideBuddySwitch();				//�������غ��ѿ���״̬(Ĭ��Ϊ1�����������������Ҫ����Ϊ0)
		bool setCloudAddr();					//�������̷�������ַ
		bool setCloudUploadSpeed();				//���������ϴ�����ٶ�  10 ~ 10000000  ��λ��k/s  Ĭ��ֵ 100000000  k/s
		bool setCloudDownloadSpeed();			//����������������ٶ� 10 ~ 100000000    Ĭ��ֵ 100000000  k/s
		bool setDevelopmentMode();				//����Ϊ����ģʽ ����ģʽ��Ҫӵ�а������ʺŲ��ܵ�¼
		bool setUserRcPath();					//�����û���ԴĿ¼
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
		bool setLogLevel();						//������־����
		bool setInterConnect();					//������������ 
		bool setNotifyStatus();					//���ãΣϣԣɣƣ�״̬
		bool setCertificatePath();				//����֤��,��ʼ���ͻ���֮ǰ����
		bool getLastPreLoginData();				//��ȡ��һ��Ԥ��¼����
		bool setLanguage();						//����Ϊ����ģʽ ����ģʽ��Ҫӵ�а������ʺŲ��ܵ�¼
		bool setLanguageType();					//�������Ի���
		bool setMsgParserMode();				//������Ϣ������ʽ
		bool setIsRoming();						//��������
		bool getLastPreLogin();					//��ȡ��һ��Ԥ��¼����
		bool setPwIsCrypt();					//������Կ�Ƿ����
		bool setHttpsLogin();					//�����Ƿ�https��ʽ��¼
		bool setMac();							//����mac��ַ
		bool setIsOpenSecPlugin();				//�����Ƿ����˵��˼���
		bool setLogOutLevel();					//����log�������
		bool rootPath();						//��·��
		bool setRootPath();						//��ȡ��·��
	protected:
		virtual void TestBody() {}
	private:
		std::shared_ptr<IConfigService> m_beforeconfigService = nullptr;
	};
}