#include "Environment.h"
namespace serviceTest {
	class CloudServiceUnitest /*:public testing::Test*/ {
	public:
		CloudServiceUnitest();
		int uploadFile();						//�ϴ��ļ� 
		int queryFloder();						//��ȡ�Ự�б�
		int addFile();							//����ļ�
		int delFile();							//ɾ���ļ�
		int renameFile();						//�������ļ�
		int getFileById();						//������Ϣ
		int getFilesByHash();					//ͨ���ļ�hash���ȡ�ļ�
		bool getFilesByHashSync(); 				//ͨ���ļ�hash���ȡ�ļ�
		int searchFiles();						//�����ļ�
		int createTeam();						//�����Ŷ��ļ���
		int teamAddMember();					//����Ŷӳ�Ա
		int teamRemoveMember();					//�Ƴ��Ŷӳ�Ա
		int teamResetMember();					//�����Ŷӳ�Ա
		int getTeams();							//��ȡ�Ŷ��ļ���
		int teamMembers();						//��ȡ�Ŷ��ļ������г�Ա
		int getRoles();							//��ȡ�Ŷӳ�Ա��ɫ
		int getRoleById();						//ͨ����ɫID��ȡ�Ŷӳ�Ա��ɫ
		int addRole();							//�����Ŷӳ�Ա��ɫ
		int editRole();							//�༭�Ŷӳ�Ա��ɫ
		int removerRole();						//�Ƴ��Ŷӳ�Ա��ɫ
		int getPermission();					//��ȡ�����Ϣ
		int getCloudFileInfo();					//userId �û�ID
		int createPubDir();						//���������ļ���
		int uploadFile_new();					//�ϴ��ļ�new 
		int moveFile();							//�ƶ��ļ���
		int copyFile();							//�����ļ���
		int querySubFolders();					//��ѯ�ļ�����������ļ���
		int queryFolderByParam();				//��ѯ�ļ���
		int checkFileExit();					//��ѯ�ļ���
		int downloadFile();						//�����ļ�
		int delFile_new();						//ɾ���ļ�
		int renameFile_new();					//�������ļ�
		int moveFile_new();						//�ƶ��ļ�
		int copyFile_new();						//�����ļ�
		int restoreCloudFile();					//���̻���վ��ԭ
		int clearCloudFile();					//���̻���վ���
		int syncCloudFile();					//ͬ���ļ�/�ļ���
		int getCloudTrashInfo();				//��ȡ����վ��Ϣ
		int getNewCloudFileInfo();				//��ȡ�ļ��������е���Ŀ¼���ļ�����ϸ��Ϣ
		int getNextLevelInfo();					//��ȡ��һ���ļ��е���Ϣ
		int getCloudUserInfo();					//��ѯ�ļ�����������ļ���
		int createShare();						//��������Ŀ¼
		int cloudShareToOther();				//��������˵�Ŀ¼
		int cloudShareToMe();					//���˹�����ҵ�
		int cloudChangeSharefolder();			//�޸Ĺ���Ŀ¼Ȩ��
		int cloudChangeShareuser();				//�޸Ĺ�����Ȩ��
		int getCloudShareInfo();				//��ȡ�ļ�����Ĺ�����Ϣ
		int setUserSetting();					//����������Ϣ
		int getUserSetting();					//��ѯ�ļ�����������ļ���
		int getCloudContactInfo();				//��ȡ�û���
		int getCloudTransferHistory();			//��ȡ�����ϴ�/������ʷ����
		int delCloudTransferHistory();			//ɾ�������ϴ�/������ʷ����
		int clearCloudTransferHistory();		//��������ϴ�/������ʷ����
	protected:
		virtual void TestBody() {}
	private:
		std::shared_ptr<ICloudService> m_cloudService = nullptr;
	};
}