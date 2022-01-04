#include "Environment.h"
namespace serviceTest {
	class GroupServiceUnitest /*:public testing::Test*/ {
	public:
		GroupServiceUnitest();
		int createGroup();					//******************创建群**************
		int createGroupEx();				//******************创建群**************
		int	addGroup();						//******************加群**************
		int	removeGroup();					//******************解散群/群成员退群**************
		int removeGroupEx();				//******************解散群/群成员退群**************
		int	transferGroup();				//******************转让群**************
		int	getGroupSet();					//******************获取群设置**************
		int setGroupSet();					//******************设置群设置**************
		bool getGroupInfo();					//******************获取群信息(同步接口)**************
		int setGroupInfo();					//******************设置群信息**************
		int	getGroupList();					//******************获取群列表 （同步接口）**************
		int	inviteMember();					//******************邀请群成员**************
		int	inviteMemberEx();				//******************邀请群成员**************
		int	removeMember();					//******************移除群成员**************
		int	removeMembers();				//******************批量移除群成员**************
		int	setMemberInfo();				//******************设置群成员信息**************
		bool isInGroup();					//******************判断用户是否在群里 (同步接口)**************
		bool getMemberInfo();				//******************获取群成员信息 (同步接口)**************
		int	getMemberDetailInfo();			//******************获取群成员详细信息 (网络接口)**************
		int	getMemberList();				//******************获取群成员列表**************
		int	getMemberListNoDlHeadImg();		//******************获取群成员列表,不检查下载头像**************
		int	getGroupFileList_1();			//******************获取群文件列表**************
		int	getGroupFileList_2();			//******************获取群文件列表**************
		int	deleteGroupFile();				//******************删除群文件**************
		int	getPersonalGroupImg();			//******************获取个人群聊背景图片**************
		int	setPersonalGroupImg();			//******************设置个人群聊背景图片**************
		int	setGroupMsgRemindType();		//******************设置群消息接受消息模式**************1：提示并接收消息；2：不提示，接收仅显示数目；3：屏蔽消息
		int	getGroupMsgRemindType();		//******************获取群消息免打扰模式**************1：提示并接收消息；2：不提示，接收仅显示数目；3：屏蔽消息
		int setGroupExtraInfo();			//******************设置群消息内容模式和V标**************
		bool getGroupOnlineStatus();		//******************查询群在线人数状态**************                      
		int	setGroupFileTerm();				//******************设置群文件永久**************                       
		int	addGroupAnnouncement();			//******************添加群公告**************
		int	delGroupAnnouncement();			//******************删除单个群公告**************
		int	checkGroupAnnouncementExist();	//******************校验群公告是否存在**************
		int	getGroupAnnouncementList();		//******************分页获取群公告列表**************
		int setGroupBeepTone();				//******************设置个人群聊提示音信息**************
		int	getGroupBeepTone();				//******************获取个人群聊提示音信息**************
		int	setGroupChatForbid();			//******************设置群禁言或群成员禁言**************
		int isGroupMember();				//******************判断是否为群成员 同步接口(注释)**************
	protected:
		virtual void TestBody() {}
	private:
		std::shared_ptr<IGroupService> m_groupService = nullptr;
		int64 groupidEx = 0;
	};
}
