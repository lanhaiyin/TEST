#include "Environment.h"
namespace serviceTest {
	class SysmsgServiceUnitest /*:public testing::Test*/ {
	public:
		SysmsgServiceUnitest();
		int respToAddBuddy();						//��Ӧ�Ӻ��ѵ�����           
		int adminRespToEnterGroup();				//����Ա��Ӧ��Ⱥ������
		int adminRespToEnterGroupEx();				//����Ա��Ӧ��Ⱥ������
		int userRespToEnterGroup();					//�û��������Ⱥ����Ӧ
		int userRespToEnterGroupEx();				//�û��������Ⱥ����Ӧ
		int userRespToEnterGroupforHL();			//�û��������Ⱥ����Ӧ
		int userRespToEnterGroupforHLEx();			//�û��������Ⱥ����Ӧ
		int deleteMessageByType();					//ͨ������ɾ��ϵͳ��Ϣ ��������
		int setMessagRead();						//������Ϣ�Ѷ� ��������
	protected:
		void TestBody() {}
	private:
		std::shared_ptr<ISysMsgService> m_sysmsgService = nullptr;
	};
}