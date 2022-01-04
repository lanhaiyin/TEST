#include "Environment.h"
namespace serviceTest {
	class ChatServiceUnitest /*:public testing::Test*/ {
	public:
		ChatServiceUnitest();
		bool getChatList();						//获取会话列表
		int removeChat();						//删除会话列表
		int sendMessage();						//发送消息
		int sendAppendixMessage();				//直接发送附件
		int insertMessage();					//插入消息
		int transferMessage();					//透传发送消息
		int forwardMessage(); 					//转发消息
		int deleteAllMessage();					//删除所有消息
		int deleteMessageById();				//通过msgId删除消息
		int deleteMessageByTime();				//删除时间段消息
		bool setMessageRead();					//设置消息已读
		int setMessageUnRead();					//设置消息未读
		bool getMessages();						//获取消息
		int chatTop();							//置顶会话
		int getImgMsg();						//获取图片消息
		int getUrlInfo();						//获取URL的详细信息
		int setPrivateKey();					//设置私信秘钥
		int decryptMsg();						//通过消息ID解密消息
		int updateMsg();						//更新对应targetId的消息)
		int addRecontact();						//增加最近联系人
		int getMsgDays();						//获取对象聊天时间数组
		int getMsgFromDay();					//根据日期获取消息
		int getAllMsgCount();					//获取所有消息数目
		bool sendShortMessage();					//发送短信
		bool getGroupMsgReadState();				//获取群内消息的读取状态
		bool getGroupMsgUnreadCounter();			//获取一批消息的未读数计数器
		int getGroupMsgUnreadInfo();			//统计消息已读、未读数量详细信息
		int getGroupDivers();					//获取群中潜水者ID集合
		int getContractMaxReadId();				//获取联系人最大已读ID
		bool getUnReadMsgCountByType();			//获取不同类型的未读消息数量
		int sendMsgInputState();				//发送消息输入状态
		int getAtMessage();						//获取@我的消息 或者 我@别人的消息
		int setMsgReads();						//批量设置已读
		bool getBadWordList();					//获取敏感词
		int getIssueById();						//获取群议题
		int getIssueMessages();					//拉取议题内历史消息
		int searchIssueLocal();					//本地查找群议题
		int deleteIssueLocal();					//标记删除本地议题
		int setGroupAnnouncementMsgReaded();	//设置群公告消息已读
		int getMsgByType();						//根据消息类型获取消息
		int getTaskMsg();						//根据任务timeTask获取任务消息
		bool MakeCombineMsg();					//组合消息
		bool toCombineMsg();						//
		bool toNotebookMsg();					//
		bool setGroupTopMsg();					//设置群置顶消息
		int getGroupTopMsgById();				//根据群会话Id获取群置顶消息集合
		bool ParseCombineMsg();					//
		bool isGroupTopMsgSync();				//根据群Id和消息Id判断该消息是否已被置顶
		int createReminderMsg();				//创建消息提醒
		int getReminderMsgByPage();				//分页查询消息提醒信息
		int deleteReminderMsg();				//删除消息提醒
		int upMsgCount();						//上传消息计数 注释

		int getBWLibList();						//获取敏感词库信息
		int getFileBWList();					//获取文件传输敏感词
		int handleDelayMsgByType();				//延时消息取消/立即发送接口
		int cleanClientData();					//删除客户端数据
	protected:
		virtual void TestBody() {}
	private:
		std::shared_ptr<IChatService> m_chatService = nullptr;
	};
}