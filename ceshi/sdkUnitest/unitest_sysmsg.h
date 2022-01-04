#include "Environment.h"
namespace serviceTest {
	class SysmsgServiceUnitest /*:public testing::Test*/ {
	public:
		SysmsgServiceUnitest();
		int respToAddBuddy();						//响应加好友的请求           
		int adminRespToEnterGroup();				//管理员响应进群的请求
		int adminRespToEnterGroupEx();				//管理员响应进群的请求
		int userRespToEnterGroup();					//用户被邀请进群的响应
		int userRespToEnterGroupEx();				//用户被邀请进群的响应
		int userRespToEnterGroupforHL();			//用户被邀请进群的响应
		int userRespToEnterGroupforHLEx();			//用户被邀请进群的响应
		int deleteMessageByType();					//通过类型删除系统消息 （废弃）
		int setMessagRead();						//设置消息已读 （废弃）
	protected:
		void TestBody() {}
	private:
		std::shared_ptr<ISysMsgService> m_sysmsgService = nullptr;
	};
}