#include "Environment.h"
namespace serviceTest {
	class ExtServiceUnitest /*:public testing::Test*/ {
	public:
		ExtServiceUnitest();
		int sendTaskMsg();							//����������Ϣ
		int topTask();								//�ö�����
		int getApTask();							//��ȡָ�ɵ�����
		int getRecvTask();							//��ȡ���յ�����
		int getHistoryTask();						//��ȡ��ʷ����
		int getBodyTask();							//��ȡ����������
		int recoveryTask();							//�ָ�����
		int finishTask();							//�������
		int setReadTask();							//���������Ѷ�
		int getRecvMsg();							//��ȡ����ظ���Ϣ
		int getTaskState();							//��ȡ������ɫ����
		int createRoom();							//��������
		int changRoomName();						//�޸ķ�������
		int changRoomIcon();						//�޸ķ���ͷ��
		int deleRoom();								//ɾ������
		int getRoom();								//��ȡ������Ϣ
		int getAllRoom();							//��ȡ���з�����Ϣ
		bool getAllRoomSync();						//��ȡ���з�����Ϣ
		int topRoom();								//�����ö�
		int addRoomMember();						//����������Ա
		int delRoomMember();						//����ɾ����Ա
		int getVisibleOrgUsers();					//��ȡ��֯����
		bool getVisibleOrgUsersSync();				//��ȡ��ҵ�б�
		int queryEnterpriseUserlist();				//����������ѯ��ҵ�û��б�
		int queryEntUserAll();						//��ȡ��ҵ�����û���Ϣ
		int queryEntUserOneById();					//��ѯ��ҵ�û���Ϣ
		int queryEntUserOneByName();				//��ѯ��ҵ�û���Ϣ
		int getOrgInfo();							//��ȡ��֯��Ϣ
		int getOrgInfos();							//��ȡ��֯��Ϣ
		bool getOrgInfoSync();						//��ȡ��֯��Ϣ
		int orgAndUserSearch();						//��֯����ģ������
		int getMsgCountByTargetID();				//��ȡ��ӦtargetId�е�������Ϣ��Ŀ
		int getMsgTopNGroup();						//��ȡ��������ǰtopN��Ⱥ��
		int getMsgTopNSession();					//��ȡ������ĿǰtopN�ĵ���
		int getMsgTopNAtGroup();					//��ȡ@�Լ�����topN��Ⱥ
		int addNote();								//��Ӽ��±�
		int getNote();								//��ȡ���±�
		int delNote();								//ɾ�����±�
		int editNote();								//�޸ļ��±�
		int archiveNote();							//�鵵���±�
		int topNote();								//�ö����±�
		int searchNote();							//�������±�
		int isCustomer();							//�жϵ�ǰ�û��Ƿ�Ϊ�ͷ�
		int getUserByAppIdAndCustomId();			//��ȡ�ͷ����ڷ�����û��б�
		int getCustomerPoolByAppID();				//��ȡ�ͻ����б�
		int closeConversation();					//�ͷ��رջỰ
		int accessCustom();							//�ͷ�����ͻ�
		int getLastMessage();						//��ȡ���һ����Ϣ
		int getCustomPoolCount();					//��ȡ�ͻ��ش�С
		int updateCustomerService();				//�޸Ŀͷ���Ϣ
		int getAppListByUserID();					//��ȡ�ͷ����ں���Ϣ�б�
		int getCustomMessages();					//��ȡ�ͻ�����Ϣ
		int getAppCustomerInfo();					//��ȡ�ͷ���Ϣ
		int getCustomerLastMessageByDB();			//��ȡ���ܿͷ����ݿ����һ����Ϣ
		int setCustomMsgReaded();					//���ÿͻ���Ϣ�Ѷ�
		int getCustomChatList();					//��ȡ�ͷ��Ự�б�
		int addNotebook();							//��Ӽ��±�
		int getNotebook();							//��ȡ���±�
		int delNotebook();							//ɾ�����±�
		int delNotebookById();						//ɾ�����±�
		int editNotebook();							//�޸ļ��±�
		int encryptNotebook();						//���ܼ��±�
		int decryptNotebook();						//���ܼ��±�
		int checkNoteEnkey();						//У����±�����
		int hideNotebook();							//���ؼ��±�
		int checkHiddenKey();						//У��������Կ
		int addNoteEntry();							//��Ӽ�������
		int getNoteEntry();							//��ȡ��������
		int delNoteEntry();							//ɾ����������
		int editNoteEntry();						//�༭��������
		int searchNoteEntry();						//������������
		int setSecSessionOnOff();					//���ûỰ������رն˵���
		int getSecSessionOnOff();					//��ȡ�Ự������رն˵���״̬
		int checkSecSession();						//ÿ���յ�����ʧ�ܵĴ�����ʱ���ô˽ӿ�
		int orgAndUserSearchEx();					//��Ա��֯��������
		int getUserShieldByAccount();				//�����˺���Ϣ��ȡ�ֻ�����Ϣ��ע�ͣ�

		int meessageSecurityCheck();				//��Ϣ���
		int fileSecurityCheck();					//�ļ����
		int setFileOrMsgRule();						//���ü�����
	protected:
		virtual void TestBody() {}
	private:
		std::shared_ptr<IExtService> m_extService = nullptr;
	};
}