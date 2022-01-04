#include "Environment.h"
namespace serviceTest {
	class RtcServiceUnitest /*:public testing::Test*/ {
	public:
		RtcServiceUnitest();
		int createChannel();				//******************邀请成员加入音视频会议**************      //createoffer  函数 返回  sdp码
		int acceptOrReject();				//******************接受或拒绝音视频会议邀请**************
		int leaveChannel();					//******************关闭音视频会议**************   
		int joinChannel();					//******************关闭音视频会议**************  
		int setConferenceInfo();			//******************设置会议信息**************
		int getConferenceInfo();			//******************获取会议信息**************  
		int switchChannel();				//******************音视频切换**************	
		int getStunServer();				//******************获取打洞服务地址**************    
		int getAgoraFunc();					//******************AGORA声网相关服务接口**************  
		int getStunServerSync();			//******************获取打洞服务地址 同步接口**************  
		int getStunServerList();			//******************获取打洞服务地址列表 （同步接口）**************
		int makePresenter();				//******************创建四人会议**************
		int extraEventCall();				//******************通用事件call**************
		int getCommonInfo();				//******************获取通用信息**************  
		int regMultiEventCb();				//******************注册多点事件回调**************
		int getMultiServerSync();			//******************获取多点服务信息    同步接口************** 
		int multiTalkRequest();				//******************多点请求**************  
		int multiExtraRequest();			//******************扩展请求************** 	
	protected:
		virtual void TestBody() {}
	private:
		std::shared_ptr<IRtcService> m_rtcService = nullptr;
	};
}

