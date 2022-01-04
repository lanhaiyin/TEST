#include "Environment.h"
namespace serviceTest {
	class ContactServiceUnitest /*:public testing::Test*/ {
	public:
		ContactServiceUnitest();
		int addContact();				//�����ϵ��
		int addContactNoVerify();		//ֱ�������ϵ��
		int getVerifyType();			//��ȡ��ϵ����֤��ʽ
		int removeContact();			//ɾ����ϵ��
		int updateContactInfo();		//������ϵ����Ϣ
		bool getContactList();			//��ȡ��ϵ���б�
		int getContactOnline();			//��ȡ��ϵ������״̬
		bool regContactOnline();			//��ȡ��������״̬ 
		bool getContactInfo();			//��ȡ��ϵ����Ϣ
		bool contactIsBuddy();			//�ж���ϵ�����Լ��Ƿ��Ǻ��ѹ�ϵ ( ͬ���ӿ� )
		int getBlackList();				//��ȡ������
		int addBlackList();				//��Ӻ�����
		int removeBlackList();			//ɾ��������
		int queryExtendedField();		//����������ѯ��չ�ֶ���Ϣ
		bool queryExtendedFieldSync();	//����������ѯ��չ�ֶ���Ϣ
		int postContact();				//�ϴ�ͨѶ¼
		bool getLocalPhoneBook();		//��ȡȫ������ͨѶ¼��Ŀ(ͬ������)
		bool addLocalPhoneBook();		//���ӱ���ͨѶ¼��Ŀ(ͬ������)
		bool deleteLocalPhoneBook();	//ɾ������ͨѶ¼��Ŀ(ͬ������)
		bool updateLocalPhoneBook();	//���±���ͨѶ¼(ͬ������)
		int getBuddyInfoFromNet();		//�������ȡ������Ϣ
		int oneWayBuddy();				//�Ƿ�Ϊ��������ɾ������ (ͬ������)
		int makeVerifyCode();			//����������
		bool isInviteCode();			//�Ƿ��ǺϷ���������(ͬ���ӿ�)
		int canMakeVerifyCode();		//У�鱾���Ƿ���Ȩ������������
		int verifyCodeValid();			//����������Ƿ���Ч
		int getUserIdByInviteCode();	//ͨ���������ȡ�û�ID
		int devKickOff();				//�ֻ�����pc�˳�
		int getDeviceOnline();			//ͨ���������ȡ�û�ID
		int verifyUserInfoField();		//�ͻ����״ε�¼�˺���Ҫ���
		int getBuddySetting();			//��ȡ�û�������Ϣ
		//int setServerAlias();			//���÷���������
		//int getServerAlias();			//��ȡ�û����÷���������
		//int saveElevatorAuthority();	//�����û�������������Ȩ��Ա����Ȩ��
		//int deleteElevator();			//�����û�������ɾ����Ȩ��Ա����Ȩ��
		//int selectElevatorAuthorityAll(); //�����û���������ѯ��ǰ�����û���������Ȩ��Ա�Լ�Ȩ��
		//int queryElevatorAuthorityReal(); //�����û���������ѯ��Ȩ��Ա��ʵ����Ȩ��
		//int listElevatorRecord();		  //�����û���������ҳ��ѯ������¼��Ϣ
		//int getTagStrategyFromNet();	  //��ȡ�û���ǩ
		//int selectElevatorAuthority();	  //�����û���������ѯ��ǰ�����û���ĳ����Ȩ��Ա�Լ�Ȩ��
	protected:
		virtual void TestBody() {}
	private:
		std::shared_ptr<IContactService> m_contactService = nullptr;
	};
}
