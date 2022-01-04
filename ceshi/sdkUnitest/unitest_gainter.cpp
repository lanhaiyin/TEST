#include "unitest_gainter.h"
namespace serviceTest {
	GainterServiceUnitest::GainterServiceUnitest() {
		m_gainterService = g_test[0].GAISERVICE();
	}

	int GainterServiceUnitest::getAppNodeServers() {
		//******************��ȡ�ⲿ�ڵ���Ϣ**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_gainterService->getAppNodeServers([&](int code, std::vector<AppNodeInfo>& json) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();

		return code;
	}

	int GainterServiceUnitest::addThreeCardOper() {
		//******************���������Ʋ���************** 
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
		//******************��ȡ��Ȩ��************** 
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