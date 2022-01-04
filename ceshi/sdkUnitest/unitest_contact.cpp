#include "unitest_contact.h"
namespace serviceTest {
	ContactServiceUnitest::ContactServiceUnitest() {
		m_contactService = g_test[0].CONTACTSERVICE();
	}
	int ContactServiceUnitest::addContact() {
		//�����ϵ��
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_contactService->addContact(m_config->m_testFriendUserId, " ", " ", [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ContactServiceUnitest::addContactNoVerify() {
		//ֱ�������ϵ��
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_contactService->addContactNoVerify(m_config->m_testFriendUserId, " ", " ", [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ContactServiceUnitest::getVerifyType() {
		//��ȡ��ϵ����֤��ʽ
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_contactService->getVerifyType(m_config->m_testFriendUserId, [&](int code, ContactVerifyType result) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int ContactServiceUnitest::updateContactInfo() {
		//������ϵ����Ϣ
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
		//��ȡ��ϵ���б�
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::vector< SSharedPtr<Contact> > contacts;
		m_contactService->getContactList(contacts);
		bool isOk = !contacts.empty();
		return isOk;
	}
	int ContactServiceUnitest::getContactOnline() {
		//��ȡ��ϵ������״̬
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
		//ɾ����ϵ��
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_contactService->removeContact(1, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	bool ContactServiceUnitest::getContactInfo() {
		//��ȡ��ϵ����Ϣ
		Contact data;
		bool isOk = m_contactService->getContactInfo(0, data);
		return isOk;
	}
	bool ContactServiceUnitest::contactIsBuddy() {
		//�ж���ϵ�����Լ��Ƿ��Ǻ��ѹ�ϵ ( ͬ���ӿ� )
		bool isFalse = m_contactService->contactIsBuddy(1);
		return isFalse;
	}
	int ContactServiceUnitest::getBlackList() {
		//��ȡ������
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_contactService->getBlackList([&](int code, std::vector<int64> blackids) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int ContactServiceUnitest::addBlackList() {
		//��Ӻ�����
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
		//ɾ��������
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
		//ɾ��������
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
		//����������ѯ��չ�ֶ���Ϣ ����dicKey��parentId��ͬ��ѯ��չ�ֶ�.
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_contactService->queryExtendedField("", -1, [&](int code, std::vector<EnterpriseDictionary> infos) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	bool ContactServiceUnitest::queryExtendedFieldSync() {
		//����������ѯ��չ�ֶ���Ϣ��ͬ���ӿڣ�
		std::vector<EnterpriseDictionary> infos;
		bool isOk = m_contactService->queryExtendedFieldSync("", -1, infos);
		return isOk;
	}
	int ContactServiceUnitest::postContact() {
		//����������ѯ��չ�ֶ���Ϣ ����dicKey��parentId��ͬ��ѯ��չ�ֶ�.
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
		//��ȡȫ������ͨѶ¼��Ŀ(ͬ������)
		std::vector<localPhoneBook> phoneBooks;

		bool isOk = m_contactService->getLocalPhoneBook(phoneBooks);
		return isOk;
	}
	bool ContactServiceUnitest::addLocalPhoneBook() {
		//���ӱ���ͨѶ¼��Ŀ(ͬ������)
		std::vector<localPhoneBook> phoneBooks;

		bool isOk = m_contactService->addLocalPhoneBook(phoneBooks);
		return isOk;
	}
	bool ContactServiceUnitest::deleteLocalPhoneBook() {
		//ɾ������ͨѶ¼��Ŀ(ͬ������)
		std::vector<std::string> phones;

		bool isOk = m_contactService->deleteLocalPhoneBook(phones);
		return isOk;
	}
	bool ContactServiceUnitest::updateLocalPhoneBook() {
		//���±���ͨѶ¼(ͬ������)
		std::vector<localPhoneBook> phoneBooks;

		bool isOk = m_contactService->updateLocalPhoneBook(phoneBooks);
		return isOk;
	}
	int ContactServiceUnitest::getBuddyInfoFromNet() {
		//�������ȡ������Ϣ
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_contactService->getBuddyInfoFromNet(1, [&](int code, Contact& contact) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ContactServiceUnitest::oneWayBuddy() {
		//�Ƿ�Ϊ��������ɾ������ (ͬ������)
		//std::promise<int> reqProm;
		//	//std::future<int> reqFut = reqProm.get_future();
		//	std::vector<localPhoneBook> phoneBooks;

		//	bool isOk = m_contactService->oneWayBuddy();
		return 0;
	}
	int ContactServiceUnitest::makeVerifyCode() {
		//����������
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
		//�Ƿ��ǺϷ���������(ͬ���ӿ�)
		const std::string invitecode = "1234";
		std::string res = m_contactService->isInviteCode(invitecode);
		bool isOk = res.empty();
		return isOk;
	}
	int ContactServiceUnitest::canMakeVerifyCode() {
		//У�鱾���Ƿ���Ȩ������������
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_contactService->canMakeVerifyCode([&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ContactServiceUnitest::verifyCodeValid() {
		//����������Ƿ���Ч
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
		//ͨ���������ȡ�û�ID
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
		//�ֻ�����pc�˳�
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_contactService->devKickOff(1, 2, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int ContactServiceUnitest::getDeviceOnline() {
		//��ȡ�û��豸����״̬
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
		//�ͻ����״ε�¼�˺���Ҫ����
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
		//�ͻ����״ε�¼�˺���Ҫ����
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
		//���÷���������
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
		//��ȡ����������
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
		//�����û�������������Ȩ��Ա����Ȩ��
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
		//�����û�������ɾ����Ȩ��Ա����Ȩ��
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
		//�����û���������ѯ��ǰ�����û���������Ȩ��Ա�Լ�Ȩ��
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
		//�����û���������ѯ��Ȩ��Ա��ʵ����Ȩ��
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
		//�����û���������ҳ��ѯ������¼��Ϣ
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
		//��ȡ�û���ǩ
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
		//�����û���������ѯ��ǰ�����û���ĳ����Ȩ��Ա�Լ�Ȩ��
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