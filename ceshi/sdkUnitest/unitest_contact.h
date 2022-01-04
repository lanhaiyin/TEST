#include "Environment.h"
namespace serviceTest {
	class ContactServiceUnitest /*:public testing::Test*/ {
	public:
		ContactServiceUnitest();
		int addContact();				//添加联系人
		int addContactNoVerify();		//直接添加联系人
		int getVerifyType();			//获取联系人验证方式
		int removeContact();			//删除联系人
		int updateContactInfo();		//更新联系人信息
		bool getContactList();			//获取联系人列表
		int getContactOnline();			//获取联系人在线状态
		bool regContactOnline();			//获取单聊在线状态 
		bool getContactInfo();			//获取联系人信息
		bool contactIsBuddy();			//判断联系人与自己是否是好友关系 ( 同步接口 )
		int getBlackList();				//获取黑名单
		int addBlackList();				//添加黑名单
		int removeBlackList();			//删除黑名单
		int queryExtendedField();		//根据条件查询拓展字段信息
		bool queryExtendedFieldSync();	//根据条件查询拓展字段信息
		int postContact();				//上传通讯录
		bool getLocalPhoneBook();		//获取全部本地通讯录条目(同步方法)
		bool addLocalPhoneBook();		//增加本地通讯录条目(同步方法)
		bool deleteLocalPhoneBook();	//删除本地通讯录条目(同步方法)
		bool updateLocalPhoneBook();	//更新本地通讯录(同步方法)
		int getBuddyInfoFromNet();		//从网络获取好友信息
		int oneWayBuddy();				//是否为单向增减删除好友 (同步方法)
		int makeVerifyCode();			//生成邀请码
		bool isInviteCode();			//是否是合法的邀请码(同步接口)
		int canMakeVerifyCode();		//校验本人是否有权限生成邀请码
		int verifyCodeValid();			//检查邀请码是否有效
		int getUserIdByInviteCode();	//通过邀请码获取用户ID
		int devKickOff();				//手机控制pc退出
		int getDeviceOnline();			//通过邀请码获取用户ID
		int verifyUserInfoField();		//客户端首次登录账号需要激活，
		int getBuddySetting();			//获取用户设置信息
		//int setServerAlias();			//设置服务器别名
		//int getServerAlias();			//获取用户设置服务器别名
		//int saveElevatorAuthority();	//超级用户操作，保存提权人员所有权限
		//int deleteElevator();			//超级用户操作，删除提权人员所有权限
		//int selectElevatorAuthorityAll(); //超级用户操作，查询当前超级用户的所有提权人员以及权限
		//int queryElevatorAuthorityReal(); //超级用户操作，查询提权人员真实所有权限
		//int listElevatorRecord();		  //超级用户操作，分页查询操作记录信息
		//int getTagStrategyFromNet();	  //获取用户标签
		//int selectElevatorAuthority();	  //超级用户操作，查询当前超级用户的某个提权人员以及权限
	protected:
		virtual void TestBody() {}
	private:
		std::shared_ptr<IContactService> m_contactService = nullptr;
	};
}
