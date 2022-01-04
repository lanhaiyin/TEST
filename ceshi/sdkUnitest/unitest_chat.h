#include "Environment.h"
namespace serviceTest {
	class ChatServiceUnitest /*:public testing::Test*/ {
	public:
		ChatServiceUnitest();
		bool getChatList();						//��ȡ�Ự�б�
		int removeChat();						//ɾ���Ự�б�
		int sendMessage();						//������Ϣ
		int sendAppendixMessage();				//ֱ�ӷ��͸���
		int insertMessage();					//������Ϣ
		int transferMessage();					//͸��������Ϣ
		int forwardMessage(); 					//ת����Ϣ
		int deleteAllMessage();					//ɾ��������Ϣ
		int deleteMessageById();				//ͨ��msgIdɾ����Ϣ
		int deleteMessageByTime();				//ɾ��ʱ�����Ϣ
		bool setMessageRead();					//������Ϣ�Ѷ�
		int setMessageUnRead();					//������Ϣδ��
		bool getMessages();						//��ȡ��Ϣ
		int chatTop();							//�ö��Ự
		int getImgMsg();						//��ȡͼƬ��Ϣ
		int getUrlInfo();						//��ȡURL����ϸ��Ϣ
		int setPrivateKey();					//����˽����Կ
		int decryptMsg();						//ͨ����ϢID������Ϣ
		int updateMsg();						//���¶�ӦtargetId����Ϣ)
		int addRecontact();						//���������ϵ��
		int getMsgDays();						//��ȡ��������ʱ������
		int getMsgFromDay();					//�������ڻ�ȡ��Ϣ
		int getAllMsgCount();					//��ȡ������Ϣ��Ŀ
		bool sendShortMessage();					//���Ͷ���
		bool getGroupMsgReadState();				//��ȡȺ����Ϣ�Ķ�ȡ״̬
		bool getGroupMsgUnreadCounter();			//��ȡһ����Ϣ��δ����������
		int getGroupMsgUnreadInfo();			//ͳ����Ϣ�Ѷ���δ��������ϸ��Ϣ
		int getGroupDivers();					//��ȡȺ��Ǳˮ��ID����
		int getContractMaxReadId();				//��ȡ��ϵ������Ѷ�ID
		bool getUnReadMsgCountByType();			//��ȡ��ͬ���͵�δ����Ϣ����
		int sendMsgInputState();				//������Ϣ����״̬
		int getAtMessage();						//��ȡ@�ҵ���Ϣ ���� ��@���˵���Ϣ
		int setMsgReads();						//���������Ѷ�
		bool getBadWordList();					//��ȡ���д�
		int getIssueById();						//��ȡȺ����
		int getIssueMessages();					//��ȡ��������ʷ��Ϣ
		int searchIssueLocal();					//���ز���Ⱥ����
		int deleteIssueLocal();					//���ɾ����������
		int setGroupAnnouncementMsgReaded();	//����Ⱥ������Ϣ�Ѷ�
		int getMsgByType();						//������Ϣ���ͻ�ȡ��Ϣ
		int getTaskMsg();						//��������timeTask��ȡ������Ϣ
		bool MakeCombineMsg();					//�����Ϣ
		bool toCombineMsg();						//
		bool toNotebookMsg();					//
		bool setGroupTopMsg();					//����Ⱥ�ö���Ϣ
		int getGroupTopMsgById();				//����Ⱥ�ỰId��ȡȺ�ö���Ϣ����
		bool ParseCombineMsg();					//
		bool isGroupTopMsgSync();				//����ȺId����ϢId�жϸ���Ϣ�Ƿ��ѱ��ö�
		int createReminderMsg();				//������Ϣ����
		int getReminderMsgByPage();				//��ҳ��ѯ��Ϣ������Ϣ
		int deleteReminderMsg();				//ɾ����Ϣ����
		int upMsgCount();						//�ϴ���Ϣ���� ע��

		int getBWLibList();						//��ȡ���дʿ���Ϣ
		int getFileBWList();					//��ȡ�ļ��������д�
		int handleDelayMsgByType();				//��ʱ��Ϣȡ��/�������ͽӿ�
		int cleanClientData();					//ɾ���ͻ�������
	protected:
		virtual void TestBody() {}
	private:
		std::shared_ptr<IChatService> m_chatService = nullptr;
	};
}