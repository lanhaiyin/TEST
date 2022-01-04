#include "Environment.h"
namespace serviceTest {
	class ExtServiceUnitest /*:public testing::Test*/ {
	public:
		ExtServiceUnitest();
		int sendTaskMsg();							//发送任务消息
		int topTask();								//置顶任务
		int getApTask();							//获取指派的任务
		int getRecvTask();							//获取接收的任务
		int getHistoryTask();						//获取历史任务
		int getBodyTask();							//获取任务上下文
		int recoveryTask();							//恢复任务
		int finishTask();							//完成任务
		int setReadTask();							//设置任务已读
		int getRecvMsg();							//获取任务回复消息
		int getTaskState();							//获取任务颜色提醒
		int createRoom();							//创建房间
		int changRoomName();						//修改房间名称
		int changRoomIcon();						//修改房间头像
		int deleRoom();								//删除房间
		int getRoom();								//获取房间信息
		int getAllRoom();							//获取所有房间信息
		bool getAllRoomSync();						//获取所有房间信息
		int topRoom();								//房间置顶
		int addRoomMember();						//房间增加人员
		int delRoomMember();						//房间删除人员
		int getVisibleOrgUsers();					//获取组织机构
		bool getVisibleOrgUsersSync();				//获取企业列表
		int queryEnterpriseUserlist();				//根据条件查询企业用户列表
		int queryEntUserAll();						//获取企业所有用户信息
		int queryEntUserOneById();					//查询企业用户信息
		int queryEntUserOneByName();				//查询企业用户信息
		int getOrgInfo();							//获取组织信息
		int getOrgInfos();							//获取组织信息
		bool getOrgInfoSync();						//获取组织信息
		int orgAndUserSearch();						//组织机构模糊查找
		int getMsgCountByTargetID();				//获取对应targetId中的所有消息数目
		int getMsgTopNGroup();						//获取聊天数量前topN的群组
		int getMsgTopNSession();					//获取聊天数目前topN的单聊
		int getMsgTopNAtGroup();					//获取@自己最多的topN个群
		int addNote();								//添加记事本
		int getNote();								//获取记事本
		int delNote();								//删除记事本
		int editNote();								//修改记事本
		int archiveNote();							//归档记事本
		int topNote();								//置顶记事本
		int searchNote();							//搜索记事本
		int isCustomer();							//判断当前用户是否为客服
		int getUserByAppIdAndCustomId();			//获取客服正在服务的用户列表
		int getCustomerPoolByAppID();				//获取客户池列表
		int closeConversation();					//客服关闭会话
		int accessCustom();							//客服接入客户
		int getLastMessage();						//获取最后一条消息
		int getCustomPoolCount();					//获取客户池大小
		int updateCustomerService();				//修改客服信息
		int getAppListByUserID();					//获取客服公众号信息列表
		int getCustomMessages();					//获取客户的消息
		int getAppCustomerInfo();					//获取客服信息
		int getCustomerLastMessageByDB();			//获取智能客服数据库最后一条消息
		int setCustomMsgReaded();					//设置客户消息已读
		int getCustomChatList();					//获取客服会话列表
		int addNotebook();							//添加记事本
		int getNotebook();							//获取记事本
		int delNotebook();							//删除记事本
		int delNotebookById();						//删除记事本
		int editNotebook();							//修改记事本
		int encryptNotebook();						//加密记事本
		int decryptNotebook();						//解密记事本
		int checkNoteEnkey();						//校验记事本密码
		int hideNotebook();							//隐藏记事本
		int checkHiddenKey();						//校验隐藏秘钥
		int addNoteEntry();							//添加记事内容
		int getNoteEntry();							//获取记事内容
		int delNoteEntry();							//删除记事内容
		int editNoteEntry();						//编辑记事内容
		int searchNoteEntry();						//搜索记事内容
		int setSecSessionOnOff();					//设置会话开启或关闭端到端
		int getSecSessionOnOff();					//获取会话开启或关闭端到端状态
		int checkSecSession();						//每次收到解密失败的错误码时调用此接口
		int orgAndUserSearchEx();					//人员组织机构搜索
		int getUserShieldByAccount();				//根据账号信息获取手机盾信息（注释）

		int meessageSecurityCheck();				//消息检查
		int fileSecurityCheck();					//文件检查
		int setFileOrMsgRule();						//设置检查规则
	protected:
		virtual void TestBody() {}
	private:
		std::shared_ptr<IExtService> m_extService = nullptr;
	};
}