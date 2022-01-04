#include "Environment.h"
namespace serviceTest {
	class GainterServiceUnitest /*:public testing::Test*/ {
	public:
		GainterServiceUnitest();
		int getAppNodeServers();			//******************��ȡ�ⲿ�ڵ���Ϣ**************  
		int addThreeCardOper();				//******************���������Ʋ���**************
		int getAuthCode();					//******************��ȡ��Ȩ��**************  
	protected:
		virtual void TestBody() {}
	private:
		std::shared_ptr<IGaInterService> m_gainterService = nullptr;
	};
}
