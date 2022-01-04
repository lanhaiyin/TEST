#include "Environment.h"
namespace serviceTest {
	class GroupServiceUnitest /*:public testing::Test*/ {
	public:
		GroupServiceUnitest();
		int createGroup();					//******************����Ⱥ**************
		int createGroupEx();				//******************����Ⱥ**************
		int	addGroup();						//******************��Ⱥ**************
		int	removeGroup();					//******************��ɢȺ/Ⱥ��Ա��Ⱥ**************
		int removeGroupEx();				//******************��ɢȺ/Ⱥ��Ա��Ⱥ**************
		int	transferGroup();				//******************ת��Ⱥ**************
		int	getGroupSet();					//******************��ȡȺ����**************
		int setGroupSet();					//******************����Ⱥ����**************
		bool getGroupInfo();					//******************��ȡȺ��Ϣ(ͬ���ӿ�)**************
		int setGroupInfo();					//******************����Ⱥ��Ϣ**************
		int	getGroupList();					//******************��ȡȺ�б� ��ͬ���ӿڣ�**************
		int	inviteMember();					//******************����Ⱥ��Ա**************
		int	inviteMemberEx();				//******************����Ⱥ��Ա**************
		int	removeMember();					//******************�Ƴ�Ⱥ��Ա**************
		int	removeMembers();				//******************�����Ƴ�Ⱥ��Ա**************
		int	setMemberInfo();				//******************����Ⱥ��Ա��Ϣ**************
		bool isInGroup();					//******************�ж��û��Ƿ���Ⱥ�� (ͬ���ӿ�)**************
		bool getMemberInfo();				//******************��ȡȺ��Ա��Ϣ (ͬ���ӿ�)**************
		int	getMemberDetailInfo();			//******************��ȡȺ��Ա��ϸ��Ϣ (����ӿ�)**************
		int	getMemberList();				//******************��ȡȺ��Ա�б�**************
		int	getMemberListNoDlHeadImg();		//******************��ȡȺ��Ա�б�,���������ͷ��**************
		int	getGroupFileList_1();			//******************��ȡȺ�ļ��б�**************
		int	getGroupFileList_2();			//******************��ȡȺ�ļ��б�**************
		int	deleteGroupFile();				//******************ɾ��Ⱥ�ļ�**************
		int	getPersonalGroupImg();			//******************��ȡ����Ⱥ�ı���ͼƬ**************
		int	setPersonalGroupImg();			//******************���ø���Ⱥ�ı���ͼƬ**************
		int	setGroupMsgRemindType();		//******************����Ⱥ��Ϣ������Ϣģʽ**************1����ʾ��������Ϣ��2������ʾ�����ս���ʾ��Ŀ��3��������Ϣ
		int	getGroupMsgRemindType();		//******************��ȡȺ��Ϣ�����ģʽ**************1����ʾ��������Ϣ��2������ʾ�����ս���ʾ��Ŀ��3��������Ϣ
		int setGroupExtraInfo();			//******************����Ⱥ��Ϣ����ģʽ��V��**************
		bool getGroupOnlineStatus();		//******************��ѯȺ��������״̬**************                      
		int	setGroupFileTerm();				//******************����Ⱥ�ļ�����**************                       
		int	addGroupAnnouncement();			//******************���Ⱥ����**************
		int	delGroupAnnouncement();			//******************ɾ������Ⱥ����**************
		int	checkGroupAnnouncementExist();	//******************У��Ⱥ�����Ƿ����**************
		int	getGroupAnnouncementList();		//******************��ҳ��ȡȺ�����б�**************
		int setGroupBeepTone();				//******************���ø���Ⱥ����ʾ����Ϣ**************
		int	getGroupBeepTone();				//******************��ȡ����Ⱥ����ʾ����Ϣ**************
		int	setGroupChatForbid();			//******************����Ⱥ���Ի�Ⱥ��Ա����**************
		int isGroupMember();				//******************�ж��Ƿ�ΪȺ��Ա ͬ���ӿ�(ע��)**************
	protected:
		virtual void TestBody() {}
	private:
		std::shared_ptr<IGroupService> m_groupService = nullptr;
		int64 groupidEx = 0;
	};
}
