#include "unitest_gainter.h"
namespace serviceTest {
	GainterServiceUnitest::GainterServiceUnitest() {
		m_gainterService = g_test[0].GAISERVICE();
	}

	int GainterServiceUnitest::getAppNodeServers() {
		//******************获取外部节点信息**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_gainterService->getAppNodeServers([&](int code, std::vector<AppNodeInfo>& json) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();

		return code;
	}

	int GainterServiceUnitest::addThreeCardOper() {
		//******************添加三卡审计操作************** 
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		ThreeCardOper oper;


		m_gainterService->addThreeCardOper(oper, [&](int code) {
			reqProm.set_value(code);
		});

		int code = reqFut.get();
		return code;
	}


	int GainterServiceUnitest::getAuthCode() {
		//******************获取授权码************** 
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		int64 appid;
		std::string clientKey = "";

		m_gainterService->getAuthCode(appid, clientKey, [&](int code, const std::string& json) {
			reqProm.set_value(code);
		});

		int code = reqFut.get();
		return code;
	}

}