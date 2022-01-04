#include "unitest_rtc.h"
namespace serviceTest {
	RtcServiceUnitest::RtcServiceUnitest() {
		m_rtcService = g_test[0].RTCSERVICE();
	}
	
	int RtcServiceUnitest::createChannel() {
		//******************邀请成员加入音视频会议**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		channelRequest request;
		request.targetId = m_config->m_testGroupTarget;
		request.operType = 0;
		request.reject = false;
		request.videoType = 4;
		request.firstSdp = "";
		request.isGroup = true;
		std::vector<int64> members = { m_config->m_testFriendUserId };
		request.members = members;



		m_rtcService->createChannel(request, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();

		return code;
	}

	int RtcServiceUnitest::acceptOrReject() {
		//******************接受或拒绝音视频会议邀请**************    
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		rejectOrAccept judge;


		m_rtcService->acceptOrReject(judge, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();

		return code;
	}

	int RtcServiceUnitest::leaveChannel() {
		//******************关闭音视频会议**************  
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_rtcService->leaveChannel([&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();

		return code;
	}

	int RtcServiceUnitest::joinChannel() {
		//******************请求加入音视频会议**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		joinChl join;

		join.channelId = 123423231;



		m_rtcService->joinChannel(join, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();

		return code;
	}

	int RtcServiceUnitest::setConferenceInfo() {
		//******************设置会议信息**************  
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		setConfer set;
		set.m_vtMembers = m_config->m_testFriendUserId;


		m_rtcService->setConferenceInfo(set, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();

		return code;
	}

	int RtcServiceUnitest::getConferenceInfo() {
		//******************获取会议信息**************   
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_rtcService->getConferenceInfo([&](int code, getConfer& confer) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();

		return code;
	}

	int RtcServiceUnitest::switchChannel() {
		//******************音视频切换**************     
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_rtcService->switchChannel(1, [&](int code) {
			reqProm.set_value(code);						//*********type 要切换的类型 1:音频 2:视频************

		});
		int code = reqFut.get();

		return code;
	}

	int RtcServiceUnitest::getStunServer() {
		//******************获取打洞服务地址**************  
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_rtcService->getStunServer([&](int code, p2pServerInfo& info) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();

		return code;
	}

	int RtcServiceUnitest::getAgoraFunc() {
		//******************AGORA声网相关服务接口************** 
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_rtcService->getAgoraFunc(1, 23412345, 0, 0, [&](int code, int n, std::string& subkey, std::string& vendorKey) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();

		return code;
	}

	int RtcServiceUnitest::getStunServerSync() {
		//******************获取打洞服务地址 同步接口************** 
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		p2pServerInfo info;

		m_rtcService->getStunServerSync(info);

		return 0;
	}

	int RtcServiceUnitest::getStunServerList() {
		//******************获取打洞服务地址列表 （同步接口）**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::vector<p2pServerInfo> stunList;

		m_rtcService->getStunServerList(stunList);

		return 0;
	}

	int RtcServiceUnitest::makePresenter() {
		//******************创建四人会议**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_rtcService->makePresenter(23412346, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();

		return code;
	}

	int RtcServiceUnitest::extraEventCall() {
		//******************通用事件call************** 
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_rtcService->extraEventCall(1, "", "", [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();

		return code;
	}

	int RtcServiceUnitest::getCommonInfo() {
		//******************获取通用信息**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_rtcService->getCommonInfo("", [&](int code, std::string& json) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int RtcServiceUnitest::regMultiEventCb() {
		//******************注册多点事件回调**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_rtcService->regMultiEventCb([&](model::multiRtcEvent& json) {


		});
		return 0;
	}

	int RtcServiceUnitest::getMultiServerSync() {
		//******************获取多点服务信息    同步接口**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		p2pServerInfo multiServer;

		m_rtcService->getMultiServerSync(multiServer);
		return 0;
	}

	int RtcServiceUnitest::multiTalkRequest() {
		//******************多点请求**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		multiRequest request;
		/*request.reqType = 1;
		request.annotation = "";
		request.groupId = 4338348117;
		std::vector<int64> members = { 4330043921 };
		request.members = members;*/




		m_rtcService->multiTalkRequest(request, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int RtcServiceUnitest::multiExtraRequest() {
		//******************扩展请求**************  
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_rtcService->multiExtraRequest(1, "", "", [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
}