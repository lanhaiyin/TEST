#include "unitest_sysmsg.h"
namespace serviceTest {
	SysmsgServiceUnitest::SysmsgServiceUnitest() {
		m_sysmsgService = g_test[0].SYSMSGSERVICE();
	}
	int SysmsgServiceUnitest::respToAddBuddy() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_sysmsgService->respToAddBuddy(m_config->m_iMyUserId, 23119277, eSysRefuse, "", "", [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int SysmsgServiceUnitest::adminRespToEnterGroup() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_sysmsgService->adminRespToEnterGroup(m_config->m_testGroupId, 23119277, eSysRefuse, "", [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int SysmsgServiceUnitest::adminRespToEnterGroupEx() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_sysmsgService->adminRespToEnterGroupEx(m_config->m_testGroupId, 23119277, eSysRefuse, "", [&](int code, std::vector<Contact> apllication, std::vector<Contact> unapllication, std::vector<Contact>user1, std::vector<Contact>user2) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();

		return code;
	}
	int SysmsgServiceUnitest::userRespToEnterGroup() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_sysmsgService->userRespToEnterGroup(m_config->m_testGroupId, 23119277, eSysRefuse, "", [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int SysmsgServiceUnitest::userRespToEnterGroupEx() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_sysmsgService->userRespToEnterGroupEx(m_config->m_testGroupId, 23119277, eSysRefuse, "", [&](int code, std::vector<Contact> apllication, std::vector<Contact> unapllication, std::vector<Contact>user1, std::vector<Contact>user2) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();

		return code;
	}
	int SysmsgServiceUnitest::userRespToEnterGroupforHL() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_sysmsgService->userRespToEnterGroupforHL(m_config->m_testGroupId, 23119277, m_config->m_iMyUserId, eSysRefuse, "", [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();

		return code;
	}
	int SysmsgServiceUnitest::userRespToEnterGroupforHLEx() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_sysmsgService->userRespToEnterGroupforHLEx(m_config->m_testGroupId, 23119277, m_config->m_iMyUserId, eSysRefuse, "", [&](int code, std::vector<Contact> apllication, std::vector<Contact> unapllication, std::vector<Contact>user1, std::vector<Contact>user2) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();

		return code;
	}
	int SysmsgServiceUnitest::deleteMessageByType() {
		//std::promise<int> reqProm;
		//std::future<int> reqFut = reqProm.get_future();
		//std::vector<int64> msgIds;
		//m_sysmsgService->deleteMessageByType(1, msgIds,[&](int code) {
		//	reqProm.set_value(code);

		//});
		//int code = reqFut.get();

		return 0;
	}
	int SysmsgServiceUnitest::setMessagRead() {
		//std::promise<int> reqProm;
		//std::future<int> reqFut = reqProm.get_future();
		//std::vector<int64> msgIds;
		//m_sysmsgService->setMessagRead(1, msgIds,[&](int code) {
		//	reqProm.set_value(code);

		//});
		//int code = reqFut.get();


		return 0;
	}

}