#include "Environment.h"
namespace serviceTest{
	class SearchServiceUnitest /*:public testing::Test*/ {
	public:
		SearchServiceUnitest();
		int searchFromNet();				//******************��������в���**************
		int searchFromLocal();			//******************�����ݿ���в���**************
		int searchFromLocalWithType();	//******************�������ʹӱ������ݿ���в���**************
		int searchFromLocalWithMTypes();		//******************�������ʹӱ������ݿ���в���**************
		int groupSearchMember();			//******************�ӱ������ݿ�������ĳ��Ⱥ�ڵ�Ⱥ��Ա**************
		int getUserInfo();			//******************ͨ���û�ID��ȡİ������Ϣ**************
		int getUserInfoEx();				//******************ͨ���û�ID�����ȡ������Ϣ**************
		int getUserInfoWithoutDlHeadImg();	//******************ͨ���û�ID�����ȡ������Ϣ��������ͷ��**************
		int getUserInfoSync();			//******************ͨ���û�ID��ȡ��ϸ��Ϣ(ͬ���ӿ�)**************
		int getUserInfoByScene();				//******************���ݿͻ���ʹ�ó�����ȡ��Ӧ�û�����**************
		int getGroupInfo();				//******************ͨ��ȺID��ȡ��ϸ��Ϣ**************
		int searchMessage();				//******************ȫ�ֲ�����Ϣ**************
		int searchDetailMessage();		//******************������ӦtargetID����ϸ��Ϣ**************
		int getOutEntNodeInfo();			//******************��ȡ�ⲿ�ڵ���Ϣ**************
	protected:
		virtual void TestBody() {}
	private:
		std::shared_ptr<ISearchService> m_searchService = nullptr;
	};
}

