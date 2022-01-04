#include "unitest_contact.h"
namespace serviceTest {
	ContactServiceUnitest::ContactServiceUnitest() {
		m_contactService = g_test[0].CONTACTSERVICE();
	}
	int ContactServiceUnitest::addContact() {
		//添加联系人
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_contactService->addContact(m_config->m_testFriendUserId, " ", " ", [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ContactServiceUnitest::addContactNoVerify() {
		//直接添加联系人
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_contactService->addContactNoVerify(m_config->m_testFriendUserId, " ", " ", [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ContactServiceUnitest::getVerifyType() {
		//获取联系人验证方式
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_contactService->getVerifyType(m_config->m_testFriendUserId, [&](int code, ContactVerifyType result) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int ContactServiceUnitest::updateContactInfo() {
		//更新联系人信息
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		Contact data;

		m_contactService->updateContactInfo(data, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	bool ContactServiceUnitest::getContactList() {
		//获取联系人列表
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::vector< SSharedPtr<Contact> > contacts;
		m_contactService->getContactList(contacts);
		bool isOk = !contacts.empty();
		return isOk;
	}
	int ContactServiceUnitest::getContactOnline() {
		//获取联系人在线状态
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::vector <int64> users;
		users.push_back(m_config->m_testFriendUserId);
		m_contactService->getContactOnline(users, [&](int code, std::vector<OnlineState> states) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int ContactServiceUnitest::removeContact() {
		//删除联系人
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_contactService->removeContact(1, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	bool ContactServiceUnitest::getContactInfo() {
		//获取联系人信息
		Contact data;
		bool isOk = m_contactService->getContactInfo(0, data);
		return isOk;
	}
	bool ContactServiceUnitest::contactIsBuddy() {
		//判断联系人与自己是否是好友关系 ( 同步接口 )
		bool isFalse = m_contactService->contactIsBuddy(1);
		return isFalse;
	}
	int ContactServiceUnitest::getBlackList() {
		//获取黑名单
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_contactService->getBlackList([&](int code, std::vector<int64> blackids) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int ContactServiceUnitest::addBlackList() {
		//添加黑名单
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::vector<int64> ids = { 1 };
		m_contactService->addBlackList(ids, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int ContactServiceUnitest::removeBlackList() {
		//删除黑名单
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::vector<int64> ids;

		m_contactService->removeBlackList(ids, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	bool ContactServiceUnitest::regContactOnline() {
		//删除黑名单
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		OnlineState state;
		m_contactService->regContactOnline(m_config->m_testFriendUserId, [&](int code, OnlineState state) {
			reqProm.set_value(code);
			state = state;
		});
		bool a = state.userID;
		int code = reqFut.get();
		return a;
	}
	int ContactServiceUnitest::queryExtendedField() {
		//根据条件查询拓展字段信息 根据dicKey和parentId共同查询拓展字段.
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_contactService->queryExtendedField("", -1, [&](int code, std::vector<EnterpriseDictionary> infos) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	bool ContactServiceUnitest::queryExtendedFieldSync() {
		//根据条件查询拓展字段信息（同步接口）
		std::vector<EnterpriseDictionary> infos;
		bool isOk = m_contactService->queryExtendedFieldSync("", -1, infos);
		return isOk;
	}
	int ContactServiceUnitest::postContact() {
		//根据条件查询拓展字段信息 根据dicKey和parentId共同查询拓展字段.
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::vector<PhoneBookContact> pbContacts;
		m_contactService->postContact(pbContacts, [&](int code, std::vector<RecommendContact> contacts) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	bool ContactServiceUnitest::getLocalPhoneBook() {
		//获取全部本地通讯录条目(同步方法)
		std::vector<localPhoneBook> phoneBooks;

		bool isOk = m_contactService->getLocalPhoneBook(phoneBooks);
		return isOk;
	}
	bool ContactServiceUnitest::addLocalPhoneBook() {
		//增加本地通讯录条目(同步方法)
		std::vector<localPhoneBook> phoneBooks;

		bool isOk = m_contactService->addLocalPhoneBook(phoneBooks);
		return isOk;
	}
	bool ContactServiceUnitest::deleteLocalPhoneBook() {
		//删除本地通讯录条目(同步方法)
		std::vector<std::string> phones;

		bool isOk = m_contactService->deleteLocalPhoneBook(phones);
		return isOk;
	}
	bool ContactServiceUnitest::updateLocalPhoneBook() {
		//更新本地通讯录(同步方法)
		std::vector<localPhoneBook> phoneBooks;

		bool isOk = m_contactService->updateLocalPhoneBook(phoneBooks);
		return isOk;
	}
	int ContactServiceUnitest::getBuddyInfoFromNet() {
		//从网络获取好友信息
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_contactService->getBuddyInfoFromNet(1, [&](int code, Contact& contact) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ContactServiceUnitest::oneWayBuddy() {
		//是否为单向增减删除好友 (同步方法)
		//std::promise<int> reqProm;
		//	//std::future<int> reqFut = reqProm.get_future();
		//	std::vector<localPhoneBook> phoneBooks;

		//	bool isOk = m_contactService->oneWayBuddy();
		return 0;
	}
	int ContactServiceUnitest::makeVerifyCode() {
		//生成邀请码
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::string res = "";
		InviteCodeParam param;
		param.createUserID = m_config->m_iMyUserId;
		param.digit = 20;

		m_contactService->makeVerifyCode(param, [&](int code, const std::string& verifycode) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	bool ContactServiceUnitest::isInviteCode() {
		//是否是合法的邀请码(同步接口)
		const std::string invitecode = "1234";
		std::string res = m_contactService->isInviteCode(invitecode);
		bool isOk = res.empty();
		return isOk;
	}
	int ContactServiceUnitest::canMakeVerifyCode() {
		//校验本人是否有权限生成邀请码
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_contactService->canMakeVerifyCode([&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ContactServiceUnitest::verifyCodeValid() {
		//检查邀请码是否有效
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		UserContact uc;
		m_contactService->verifyCodeValid("1234", uc, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ContactServiceUnitest::getUserIdByInviteCode() {
		//通过邀请码获取用户ID
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
#ifdef SDK_UNITEST_DEV
		m_contactService->getUserIdByInviteCode("1234", [&](int code, int64 ID) {
			reqProm.set_value(code);
		});
#else
		m_contactService->getUserIdByInviteCode("1234", [&](int code, int64 ID,int8 canAddbuddy) {
			reqProm.set_value(code);
		});
#endif
		int code = reqFut.get();
		return code;
	}
	int ContactServiceUnitest::devKickOff() {
		//手机控制pc退出
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_contactService->devKickOff(1, 2, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int ContactServiceUnitest::getDeviceOnline() {
		//获取用户设备在线状态
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::vector<int64> users;
		m_contactService->getDeviceOnline(users, [&](int code, std::vector<OnlineState> state) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int ContactServiceUnitest::verifyUserInfoField() {
		//客户端首次登录账号需要激活
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::string account = ((1 == m_config->m_userType) ? "0086" + m_config->m_account : m_config->m_account);
		m_contactService->verifyUserInfoField(1, account, "un", [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int ContactServiceUnitest::getBuddySetting() {
		//客户端首次登录账号需要激活
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::vector<int64> userIdList;

		m_contactService->getBuddySetting(userIdList, [&](int code, std::map<int64, std::vector<PersonalDataSwitch>> res) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
/*
	int ContactServiceUnitest::setServerAlias() {
		//设置服务器别名
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_contactService->setServerAlias(m_config->m_iMyUserId,"123",[&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}

	int ContactServiceUnitest::getServerAlias()
	{
		//获取服务器别名
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_contactService->getServerAlias(m_config->m_iMyUserId, [&](int code,std::string name) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}


	int ContactServiceUnitest::saveElevatorAuthority()
	{
		//超级用户操作，保存提权人员所有权限
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::vector<ElevatorAuthority> elevatorlist;

		ElevatorAuthority A;
		A.superUserId = m_config->m_iMyUserId;
		A.authorityCode = "0";
		A.createTime = 0;
		A.updateTime = 0;
		elevatorlist.push_back(A);

		m_contactService->saveElevatorAuthority(elevatorlist, [&](int code, std::string name) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}


	int ContactServiceUnitest::deleteElevator()
	{
		//超级用户操作，删除提权人员所有权限
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_contactService->deleteElevator(1,1, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}

	int ContactServiceUnitest::selectElevatorAuthorityAll()
	{
		//超级用户操作，查询当前超级用户的所有提权人员以及权限
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_contactService->selectElevatorAuthorityAll(1, 1,1, [&](int code,int64 currpage,int64 currNum, int64 totalpage,int64 totaltie,std::vector<ElevatorAuthority> elevatorlist) {
			reqProm.set_value(code);
		});

		int code = reqFut.get();
		return code;
	}


	int ContactServiceUnitest::queryElevatorAuthorityReal()
	{
		//超级用户操作，查询提权人员真实所有权限
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_contactService->queryElevatorAuthorityReal(1, [&](int code, const std::string json) {
			reqProm.set_value(code);
		});

		int code = reqFut.get();
		return code;
	}

	int ContactServiceUnitest::listElevatorRecord()
	{
		//超级用户操作，分页查询操作记录信息
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_contactService->listElevatorRecord(1,1,1,1, [&](int code, int64 currpage, int64 currNum, int64 totalpage, int64 totaltie, std::vector<ElevatorAuthority> elevatorlist) {
			reqProm.set_value(code);
		});

		int code = reqFut.get();
		return code;
	}


	int ContactServiceUnitest::getTagStrategyFromNet()
	{
		//获取用户标签
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_contactService->getTagStrategyFromNet(m_config->m_iMyUserId,1, [&](int code, int64 tagtype,std::string json) {
			reqProm.set_value(code);
		});

		int code = reqFut.get();
		return code;
	}

	int ContactServiceUnitest::selectElevatorAuthority()
	{
		//超级用户操作，查询当前超级用户的某个提权人员以及权限
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_contactService->selectElevatorAuthority(m_config->m_iMyUserId, 1, [&](int code,std::vector<ElevatorAuthority> elevatorlist) {
			reqProm.set_value(code);
		});

		int code = reqFut.get();
		return code;
	}
	*/
}