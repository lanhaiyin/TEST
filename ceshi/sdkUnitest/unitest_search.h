#include "Environment.h"
namespace serviceTest{
	class SearchServiceUnitest /*:public testing::Test*/ {
	public:
		SearchServiceUnitest();
		int searchFromNet();				//******************从网络进行查找**************
		int searchFromLocal();			//******************从数据库进行查找**************
		int searchFromLocalWithType();	//******************根据类型从本地数据库进行查找**************
		int searchFromLocalWithMTypes();		//******************根据类型从本地数据库进行查找**************
		int groupSearchMember();			//******************从本地数据库里搜索某个群内的群成员**************
		int getUserInfo();			//******************通过用户ID获取陌生人信息**************
		int getUserInfoEx();				//******************通过用户ID网络获取好友信息**************
		int getUserInfoWithoutDlHeadImg();	//******************通过用户ID网络获取好友信息，不下载头像**************
		int getUserInfoSync();			//******************通过用户ID获取详细信息(同步接口)**************
		int getUserInfoByScene();				//******************根据客户端使用场景获取相应用户资料**************
		int getGroupInfo();				//******************通过群ID获取详细信息**************
		int searchMessage();				//******************全局查找消息**************
		int searchDetailMessage();		//******************查找相应targetID的详细消息**************
		int getOutEntNodeInfo();			//******************获取外部节点信息**************
	protected:
		virtual void TestBody() {}
	private:
		std::shared_ptr<ISearchService> m_searchService = nullptr;
	};
}

