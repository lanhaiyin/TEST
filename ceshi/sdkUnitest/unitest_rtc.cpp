#include "unitest_rtc.h"
namespace serviceTest {
	RtcServiceUnitest::RtcServiceUnitest() {
		m_rtcService = g_test[0].RTCSERVICE();
	}
	
	int RtcServiceUnitest::createChannel() {
		//******************�����Ա��������Ƶ����**************
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
		//******************���ܻ�ܾ�����Ƶ��������**************    
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
		//******************�ر�����Ƶ����**************  
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_rtcService->leaveChannel([&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();

		return code;
	}

	int RtcServiceUnitest::joinChannel() {
		//******************�����������Ƶ����**************
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
		//******************���û�����Ϣ**************  
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
		//******************��ȡ������Ϣ**************   
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_rtcService->getConferenceInfo([&](int code, getConfer& confer) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();

		return code;
	}

	int RtcServiceUnitest::switchChannel() {
		//******************����Ƶ�л�**************     
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_rtcService->switchChannel(1, [&](int code) {
			reqProm.set_value(code);						//*********type Ҫ�л������� 1:��Ƶ 2:��Ƶ************

		});
		int code = reqFut.get();

		return code;
	}

	int RtcServiceUnitest::getStunServer() {
		//******************��ȡ�򶴷����ַ**************  
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_rtcService->getStunServer([&](int code, p2pServerInfo& info) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();

		return code;
	}

	int RtcServiceUnitest::getAgoraFunc() {
		//******************AGORA������ط���ӿ�************** 
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_rtcService->getAgoraFunc(1, 23412345, 0, 0, [&](int code, int n, std::string& subkey, std::string& vendorKey) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();

		return code;
	}

	int RtcServiceUnitest::getStunServerSync() {
		//******************��ȡ�򶴷����ַ ͬ���ӿ�************** 
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		p2pServerInfo info;

		m_rtcService->getStunServerSync(info);

		return 0;
	}

	int RtcServiceUnitest::getStunServerList() {
		//******************��ȡ�򶴷����ַ�б� ��ͬ���ӿڣ�**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::vector<p2pServerInfo> stunList;

		m_rtcService->getStunServerList(stunList);

		return 0;
	}

	int RtcServiceUnitest::makePresenter() {
		//******************�������˻���**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_rtcService->makePresenter(23412346, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();

		return code;
	}

	int RtcServiceUnitest::extraEventCall() {
		//******************ͨ���¼�call************** 
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_rtcService->extraEventCall(1, "", "", [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();

		return code;
	}

	int RtcServiceUnitest::getCommonInfo() {
		//******************��ȡͨ����Ϣ**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_rtcService->getCommonInfo("", [&](int code, std::string& json) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int RtcServiceUnitest::regMultiEventCb() {
		//******************ע�����¼��ص�**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_rtcService->regMultiEventCb([&](model::multiRtcEvent& json) {


		});
		return 0;
	}

	int RtcServiceUnitest::getMultiServerSync() {
		//******************��ȡ��������Ϣ    ͬ���ӿ�**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		p2pServerInfo multiServer;

		m_rtcService->getMultiServerSync(multiServer);
		return 0;
	}

	int RtcServiceUnitest::multiTalkRequest() {
		//******************�������**************
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
		//******************��չ����**************  
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_rtcService->multiExtraRequest(1, "", "", [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
}