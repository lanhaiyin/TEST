#include "unitest_search.h"
namespace serviceTest {
	SearchServiceUnitest::SearchServiceUnitest() {
		m_searchService = g_test[0].SEARCHSERVICE();
	}

	int SearchServiceUnitest::searchFromNet() {
		//******************从网络进行查找**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_searchService->searchFromNet(m_config->m_account, [&](int code, SearchResult& json) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}

	int SearchServiceUnitest::searchFromLocal() {
		//******************从数据库进行查找**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_searchService->searchFromLocal(m_config->m_account, [&](int code, SearchResult& json) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	
	int SearchServiceUnitest::searchFromLocalWithType() {
		//******************根据类型从本地数据库进行查找**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_searchService->searchFromLocalWithType(m_config->m_account, 2, [&](int code, SearchResult& json) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}

	int SearchServiceUnitest::searchFromLocalWithMTypes() {
		//******************根据类型从本地数据库进行查找**************
		//std::promise<int> reqProm;
		//std::future<int> reqFut = reqProm.get_future();
		//
		//const std::vector<std::string> key = { m_config->m_account };
		//
		//
		//
		//m_searchService->searchFromLocalWithMTypes(key, 1, [&](int code, SearchResult& json) {
		//	reqProm.set_value(code);
		//});
		//int code = reqFut.get();
		//Assert::AreEqual(0, code);
		return 0;
	}

	int SearchServiceUnitest::groupSearchMember() {
		//******************从本地数据库里搜索某个群内的群成员**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		/*	m_searchService->searchFromLocalWithType("15055034326", 6, [&](int code, SearchResult& json) {
		reqProm.set_value(code);
		});*/

		//std::string key = "";

		m_searchService->groupSearchMember(m_config->m_testGroupId, m_config->m_account, [&](int code, std::vector<Member>& json) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}

	int SearchServiceUnitest::getUserInfo() {
		//******************通过用户ID获取陌生人信息**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_searchService->getUserInfo(m_config->m_testGroupId, [&](int code, Contact& json) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	
	int SearchServiceUnitest::getUserInfoEx() {
		//******************通过用户ID网络获取好友信息**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_searchService->getUserInfoEx(m_config->m_testFriendUserId2, [&](int code, Contact& json) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}

	int SearchServiceUnitest::getUserInfoWithoutDlHeadImg() {
		//******************通过用户ID网络获取好友信息，不下载头像**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_searchService->getUserInfoWithoutDlHeadImg(m_config->m_testFriendUserId2, [&](int code, Contact& json) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}

	int SearchServiceUnitest::getUserInfoSync() {
		//******************通过用户ID获取详细信息(同步接口)**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		model::Contact info;
		m_searchService->getUserInfoSync(m_config->m_testFriendUserId, info);
		return info.id.value()== m_config->m_testFriendUserId?0:1;
	}

	int SearchServiceUnitest::getUserInfoByScene() {
		//******************根据客户端使用场景获取相应用户资料**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_searchService->getUserInfoByScene(m_config->m_testFriendUserId, 1, [&](int code, Contact& json) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}

	int SearchServiceUnitest::getGroupInfo() {
		//******************通过群ID获取详细信息**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_searchService->getGroupInfo(m_config->m_testGroupId, [&](int code, Group& json) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return 0;
	}

	int SearchServiceUnitest::searchMessage() {
		//******************全局查找消息**************
		std::promise<int> reqPromSet;
		std::future<int> reqFutSet = reqPromSet.get_future();
		std::promise<int> reqPromGet;
		std::future<int> reqFutGet = reqPromGet.get_future();
		MsgSearchProperty msgProperty;
		msgProperty.targetid = m_config->m_testGroupTarget;
		msgProperty.count = 0;

		m_searchService->getGroupInfo(m_config->m_testGroupId, [&](int code, Group& json) {
			reqPromSet.set_value(code);
		});
		reqFutSet.get();
		m_searchService->searchMessage("123", msgProperty, [&](int code, MsgSearchResult& json) {
			reqPromGet.set_value(code);
		});
		int code = reqFutGet.get();
		return 0;
	}


	int SearchServiceUnitest::searchDetailMessage() {
		//******************查找相应targetID的详细消息**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		MsgDetailSearchProperty msgDetailProperty;
		msgDetailProperty.targetid = m_config->m_testGroupTarget;

		m_searchService->searchDetailMessage(m_config->m_account, msgDetailProperty, [&](int code, MsgDetailSearchResult& json) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return 0;
	}


	int SearchServiceUnitest::getOutEntNodeInfo() {
		//******************获取外部节点信息**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		MsgDetailSearchProperty msgDetailProperty;
		msgDetailProperty.targetid = m_config->m_testGroupTarget;

		m_searchService->getOutEntNodeInfo([&](int code, std::vector<OutEntNodeInfo>& json) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return 0;
	}


}