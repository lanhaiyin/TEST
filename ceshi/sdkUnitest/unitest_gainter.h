#include "Environment.h"
namespace serviceTest {
	class GainterServiceUnitest /*:public testing::Test*/ {
	public:
		GainterServiceUnitest();
		int getAppNodeServers();			//******************获取外部节点信息**************  
		int addThreeCardOper();				//******************添加三卡审计操作**************
		int getAuthCode();					//******************获取授权码**************  
	protected:
		virtual void TestBody() {}
	private:
		std::shared_ptr<IGaInterService> m_gainterService = nullptr;
	};
}
