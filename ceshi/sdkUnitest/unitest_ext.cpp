#include "unitest_ext.h"
namespace serviceTest {
	ExtServiceUnitest::ExtServiceUnitest() {
		m_extService = g_test[0].EXTSERVICE();
	}
	int ExtServiceUnitest::sendTaskMsg() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		Msg msg;
		m_extService->sendTaskMsg(msg, [&](int code, int64 msgID, int64 sendTime) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::topTask() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_extService->topTask(0, 0, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();

		return code;
	}
	int ExtServiceUnitest::getApTask() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_extService->getApTask([&](int code, std::vector<Task> tasks) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();

		return code;
	}
	int ExtServiceUnitest::getRecvTask() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_extService->getRecvTask([&](int code, std::vector<Task> tasks) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();

		return code;
	}
	int ExtServiceUnitest::getHistoryTask() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_extService->getHistoryTask([&](int code, std::vector<Task> tasks) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();


		return code;
	}
	int ExtServiceUnitest::getBodyTask() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_extService->getBodyTask(1, [&](int code, std::string txt) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::recoveryTask() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_extService->recoveryTask(1, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::finishTask() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_extService->finishTask(1, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();

		return code;
	}
	int ExtServiceUnitest::setReadTask() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_extService->setReadTask(1, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::getRecvMsg() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_extService->getRecvMsg(2, 0, "20", 1, 0, [&](int code, std::vector<MsgPtr> msgptr, std::vector<model::Task>) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();

		return code;
	}
	int ExtServiceUnitest::getTaskState() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_extService->getTaskState([&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::createRoom() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::vector<int64> ids;
		std::string roomName = "测试房间";
		std::string url = "";
		m_extService->createRoom(roomName, ids, 0, url, [&](int code, int32 err) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::changRoomName() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::vector<int64> ids;
		std::string roomName = "测试房间";
		std::string url = "";
		m_extService->changRoomName(1, roomName, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::changRoomIcon() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::string url = "";
		m_extService->changRoomIcon(1, url, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::deleRoom() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_extService->deleRoom(1, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::getRoom() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_extService->getRoom(1, [&](int code, std::vector<room> room) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	bool ExtServiceUnitest::getAllRoomSync() {

		std::vector<room> rooms = m_extService->getAllRoomSync();
		/*	int code = reqFut.get();*/
		bool isOk = true;
		return isOk;
	}
	int ExtServiceUnitest::topRoom() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_extService->topRoom(1, 0, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::addRoomMember() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::vector<int64> vt;
		m_extService->addRoomMember(1, vt, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::delRoomMember() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::vector<int64> vt;
		m_extService->delRoomMember(1, vt, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::getVisibleOrgUsers() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_extService->getVisibleOrgUsers(0, 0, 0, [&](int code, int8 er, int8 err, std::vector<OrganizationInfo> Orinfos, std::vector<EntpriseUserInfo> userinfos) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	bool ExtServiceUnitest::getVisibleOrgUsersSync() {
		std::vector<OrganizationInfo> orginfo;
		std::vector<EntpriseUserInfo> userinfo;
		m_extService->getVisibleOrgUsersSync(m_config->m_testGroupId, orginfo, userinfo);
		/*		int code = reqFut.get();*/
		bool isOk = orginfo.empty();
		return isOk;
	}
	int ExtServiceUnitest::queryEnterpriseUserlist() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		EnterpriseUserQueryInfo enterpriseUserQueryInfo;
		m_extService->queryEnterpriseUserlist(enterpriseUserQueryInfo, [&](int code, int64 total, int64 totalPage, std::map<std::string, std::vector<EntpriseUserInfo> > users) {
			reqProm.set_value(code);
		});

		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::queryEntUserAll() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::vector<int64> vt = { m_config->m_testFriendUserId };
		m_extService->queryEntUserAll(vt, [&](int code, std::vector<EntpriseUserInfo> userinfos) {
			reqProm.set_value(code);
		});

		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::queryEntUserOneById() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_extService->queryEntUserOneById(0, m_config->m_testFriendUserId, [&](int code, std::vector<EntpriseUserInfo> userinfos) {
			reqProm.set_value(code);
		});

		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::queryEntUserOneByName() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::string userName = m_config->m_account;
		m_extService->queryEntUserOneByName(0, userName, [&](int code, std::vector<EntpriseUserInfo> userinfos) {
			reqProm.set_value(code);
		});

		int code = reqFut.get();
		return code;
	}

	int ExtServiceUnitest::getOrgInfo() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_extService->getOrgInfo(0, m_config->m_iMyUserId, [&](int code, OrganizationInfo info) {
			reqProm.set_value(code);
		});

		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::getCustomChatList() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_extService->getCustomChatList(1, [&](int code, std::vector<CustomChat> chat) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	bool ExtServiceUnitest::getOrgInfoSync() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		OrganizationInfo org;
		org.orgID = 1;
		org.parentOrgID = 0;
		m_extService->getOrgInfoSync(0, org);
		bool isOk = true;
		return isOk;
	}
	int ExtServiceUnitest::delNotebookById() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		int64 notebookId = 0;
		std::string enKey;
		m_extService->delNotebookById(notebookId, enKey, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::getAllRoom() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_extService->getAllRoom([&](int code, std::vector<room> room) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	
	int ExtServiceUnitest::orgAndUserSearch() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		OrgAndUserSearchIn orgAndUser;
		orgAndUser.type = 4;
		orgAndUser.userID = m_config->m_testFriendUserId;
		m_extService->orgAndUserSearch(orgAndUser, [&](int code, int64 n, std::vector<OrganizationInfo> orginfos, std::vector<OrgSearchUserInfo> userinfos) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::getMsgCountByTargetID() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_extService->getMsgCountByTargetID(m_config->m_testFriendUserId, [&](int code, int32 count) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::getMsgTopNGroup() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_extService->getMsgTopNGroup(1, [&](int code, std::vector<int64> targetids, std::vector<int> count) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();

		return code;
	}
	int ExtServiceUnitest::getMsgTopNSession() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_extService->getMsgTopNSession(1, [&](int code, std::vector<int64> targetids, std::vector<int> count) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::getMsgTopNAtGroup() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_extService->getMsgTopNAtGroup(1, [&](int code, std::vector<int64> targetids, std::vector<int> count) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::addNote() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		BaseNoteInfo noteInfo;
		m_extService->addNote(noteInfo, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::getNote() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_extService->getNote(0, 1, 0, [&](int code, std::vector<BaseNoteInfo> noteinfos) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::delNote() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::vector<int64> noteId = { 0 };
		m_extService->delNote(noteId, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::editNote() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		BaseNoteInfo baseInfo;
		baseInfo.isNet = true;
		baseInfo.id = 1;
		baseInfo.sendUserId = m_config->m_iMyUserId;
		baseInfo.lastChgTime = 20;
		baseInfo.targetId = m_config->m_iMyUserId;
		baseInfo.type = 00000001;
		baseInfo.netType = 0000000100000001;
		baseInfo.content = "ceshi";
		baseInfo.title = "ceshi";
		baseInfo.isReminder = 0;
		baseInfo.isArchive = 0;
		m_extService->editNote(baseInfo, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::archiveNote() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_extService->archiveNote(00000000, 1, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::topNote() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_extService->topNote(1, 0, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::searchNote() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		searchNoteInfo info;
		m_extService->searchNote(info, [&](int code, std::vector<BaseNoteInfo> noteinfo) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::isCustomer() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		searchNoteInfo info;
		m_extService->isCustomer([&](int code, bool is) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::getUserByAppIdAndCustomId() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_extService->getUserByAppIdAndCustomId(1, [&](int code, std::vector<User> users) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::getCustomerPoolByAppID() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_extService->getCustomerPoolByAppID(1, [&](int code, std::vector<CustomerPoolBean> poolbean) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();

		return code;
	}
	int ExtServiceUnitest::closeConversation() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_extService->closeConversation(1, 1, m_config->m_iMyUserId, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();

		return code;
	}
	int ExtServiceUnitest::accessCustom() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_extService->accessCustom(1, 1, m_config->m_iMyUserId, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();

		return code;
	}
	int ExtServiceUnitest::getLastMessage() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_extService->getLastMessage(1, 1, m_config->m_iMyUserId, [&](int code, SSharedPtr<Msg> msg) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();

		return code;
	}
	int ExtServiceUnitest::getCustomPoolCount() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_extService->getCustomPoolCount(1, [&](int code, int64 size) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();

		return code;
	}
	int ExtServiceUnitest::updateCustomerService() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_extService->updateCustomerService(1, 1, 1, 1, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();

		return code;
	}
	int ExtServiceUnitest::getAppListByUserID() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_extService->getAppListByUserID([&](int code, std::vector<CustomAppInfo> appinfos) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();

		return code;
	}
	int ExtServiceUnitest::getCustomMessages() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_extService->getCustomMessages(1, m_config->m_iMyUserId, 0, 1, 0, [&](int code, int64 appid, int64 userid, std::vector<MsgPtr> msgptr) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::getAppCustomerInfo() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_extService->getAppCustomerInfo(1, [&](int code, AppCustomerInfo appinfo) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::getCustomerLastMessageByDB() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_extService->getCustomerLastMessageByDB(0, [&](int code, SSharedPtr<Msg> msg) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();

		return code;
	}
	int ExtServiceUnitest::setCustomMsgReaded() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_extService->setCustomMsgReaded(1, m_config->m_iMyUserId, 23107811, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();

		return code;
	}
	int ExtServiceUnitest::getOrgInfos() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		/*	std::vector<int64> orgId = { m_config->m_iMyUserId };
		m_extService->getOrgInfos(orgId, [&](int code, std::vector<OrganizationInfo>& infos) {
		reqProm.set_value(code);
		});

		int code = reqFut.get();*/
		int code = 0;

		return code;
	}
	int ExtServiceUnitest::addNotebook() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		Notebook note;
		m_extService->addNotebook(note, [&](int code, int64 noteid) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();


		return code;
	}
	int ExtServiceUnitest::getNotebook() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::string hiddenKey;
		m_extService->getNotebook(0, 0, hiddenKey, [&](int code, std::vector<Notebook> notebook) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();


		return code;
	}
	int ExtServiceUnitest::delNotebook() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::vector<int64> notebookId = { 0 };
		m_extService->delNotebook(notebookId, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();


		return code;
	}
	int ExtServiceUnitest::editNotebook() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		Notebook note;
		m_extService->editNotebook(note, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();


		return code;
	}
	int ExtServiceUnitest::encryptNotebook() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		int64 noteid = 0;
		std::string enKey;
		m_extService->encryptNotebook(noteid, 1, enKey, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::decryptNotebook() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		int64 noteid = 0;
		std::string enKey;
		m_extService->decryptNotebook(noteid, enKey, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::checkNoteEnkey() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		int64 noteid = 0;
		std::string enKey;
		m_extService->checkNoteEnkey(noteid, enKey, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::hideNotebook() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		int64 noteid = 0;
		std::string enKey;
		m_extService->hideNotebook(noteid, enKey, 0, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::checkHiddenKey() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::string enKey;
		m_extService->checkHiddenKey(enKey, [&](int code, int64 count) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::addNoteEntry() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		NoteEntry entry;
		m_extService->addNoteEntry(entry, [&](int code, int64 id) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::getNoteEntry() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		GetNoteEntryParam param;
		m_extService->getNoteEntry(param, [&](int code, std::vector<NoteEntry> noteentry) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::delNoteEntry() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::vector<int64> noteEntryId;
		m_extService->delNoteEntry(noteEntryId, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::editNoteEntry() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		NoteEntry entry;
		m_extService->editNoteEntry(entry, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::searchNoteEntry() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		int64 notebookId = 0;
		std::string searchText;
		m_extService->searchNoteEntry(notebookId, searchText, [&](int code, std::vector<NoteEntry> note) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::setSecSessionOnOff() {
		int8 openFlag = 1;
		int res = m_extService->setSecSessionOnOff(m_config->m_testFriendUserId, 0, openFlag);
		return res;
	}
	int ExtServiceUnitest::getSecSessionOnOff() {
		int8 openFlag = 0;
		int res = m_extService->getSecSessionOnOff(m_config->m_testFriendUserId, 0, openFlag);
		return res;
	}
	int ExtServiceUnitest::checkSecSession() {
		//int res = m_extService->checkSecSession(m_config->m_testFriendUserId, 2);
		return 0;
	}
	int ExtServiceUnitest::orgAndUserSearchEx() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::string keyword;
		std::vector<int64> orgIDs;
		m_extService->orgAndUserSearchEx(keyword, orgIDs, [&](int code, int64 no, std::vector<OrganizationInfo> orginfos, std::vector<OrgSearchUserInfo> userinfos) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ExtServiceUnitest::getUserShieldByAccount() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::string keyword;
		std::vector<int64> orgIDs;
		//m_extService->getUserShieldByAccount(keyword, orgIDs, [&](int code, int64 no, std::vector<OrganizationInfo> orginfos, std::vector<OrgSearchUserInfo> userinfos) {
		//	reqProm.set_value(code);
		//});
		//int code = reqFut.get();
		//if (m_config->m_server == "vrv") {
		//	bool isOk = (code == -16777214 || code == 16004);
		//	Assert::IsTrue(isOk);
		//}
		//else if (m_config->m_server == "bxy") {
		int code = 0;
		return code;
	}
	int ExtServiceUnitest::meessageSecurityCheck() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		
		std::string message = "白粉";
		m_extService->meessageSecurityCheck(message,[&](int code,  std::map<std::string,int64> orginfos) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}

	
	int ExtServiceUnitest::fileSecurityCheck() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::string path = m_config->m_upLoadFilePath;

		m_extService->fileSecurityCheck(path, [&](int code, int type,std::map<std::string, int64> orginfos) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}


	int ExtServiceUnitest::setFileOrMsgRule() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::string rule = "<root>\
		<rules>\
		< group id = \"ea3c83d77e2c40fc9ddb50a125ac3587\" name=\"XP\" description=\"\" secretLevelID=\"a4fc7fd6d3e645bdb5764e6a41ddf74d\">\
		< contain relation = \"2\">\
		< rule name = \"nh12\" id=\"07b4bc0d7abd4231a9baa3e52e058ac6\" ruledescription=\"11\" mode=\"1\" ext=\"256511\" extex=\".bmp\" part=\"4097\" bytecount=\"\" keyword=\"秘密;机密;绝密\" relation=\"2\" checkEmbedPhoto=\"1\" ignoreCase=\"1\" hitMode=\"0\" hitGreaterCond=\"\" hitGreaterValue=\"\" hitRelation=\"\" hitLessValue=\"\" DataIdentifyStrictlevel=\"\" DataIdentifier=\"\" BuildinRegularName=\"\" RegularType=\"0\" ExactMatch=\"\" MatchDegree=\"\" IndexFileUrl=\"\" IndexFileCrc=\"\" ColumnMask=\"\" fileHeaders=\"\" fileName=\"\" sizeGreaterCond=\"\" sizeGreaterValue=\"\" sizeGreaterUnit=\"\" sizeLessCond=\"\" sizeLessValue=\"\" sizeLessUnit=\"\" sizeRelation=\"\" fileEncrypt=\"\" Reference=\"\" fileOwner=\"\" timeCreateCond=\"\" timeCreateTime=\"\" timeRelation=\"\" timeModifyCond=\"\" timeModifyTime=\"\" ColumnSum=\"\" RowSum=\"\" />\
		< / contain>\
		< exception relation = \"2\" />\
		< / group>\
		< group id = \"f82014f05ab64ccc9b8d7f04d870b97e\" name=\"敏感nihao\" description=\"你好1   等级 1\" secretLevelID=\"9583ca541a1749ccbdb4ae37595532f0\">\
		< contain relation = \"1\">\
		< rule name = \"nihao\" id=\"10e501a2cc254d79a4e7629c5eea9a9c\" ruledescription=\"22\" mode=\"1\" ext=\"256511\" extex=\"\" part=\"1\" bytecount=\"\" keyword=\"扩散;转发;外发\" relation=\"2\" checkEmbedPhoto=\"1\" ignoreCase=\"1\" hitMode=\"0\" hitGreaterCond=\"\" hitGreaterValue=\"\" hitRelation=\"\" hitLessValue=\"\" DataIdentifyStrictlevel=\"\" DataIdentifier=\"\" BuildinRegularName=\"\" RegularType=\"0\" ExactMatch=\"\" MatchDegree=\"\" IndexFileUrl=\"\" IndexFileCrc=\"\" ColumnMask=\"\" fileHeaders=\"\" fileName=\"\" sizeGreaterCond=\"\" sizeGreaterValue=\"\" sizeGreaterUnit=\"\" sizeLessCond=\"\" sizeLessValue=\"\" sizeLessUnit=\"\" sizeRelation=\"\" fileEncrypt=\"\" Reference=\"\" fileOwner=\"\" timeCreateCond=\"\" timeCreateTime=\"\" timeRelation=\"\" timeModifyCond=\"\" timeModifyTime=\"\" ColumnSum=\"\" RowSum=\"\" />\
		< rule name = \"jimi\" id=\"f01e291d77064cffb446f81741d161a1\" ruledescription=\"33\" mode=\"1\" ext=\"256511\" extex=\"\" part=\"1\" bytecount=\"\" keyword=\"不;禁\" relation=\"2\" checkEmbedPhoto=\"0\" ignoreCase=\"1\" hitMode=\"0\" hitGreaterCond=\"\" hitGreaterValue=\"\" hitRelation=\"\" hitLessValue=\"\" DataIdentifyStrictlevel=\"\" DataIdentifier=\"\" BuildinRegularName=\"\" RegularType=\"0\" ExactMatch=\"\" MatchDegree=\"\" IndexFileUrl=\"\" IndexFileCrc=\"\" ColumnMask=\"\" fileHeaders=\"\" fileName=\"\" sizeGreaterCond=\"\" sizeGreaterValue=\"\" sizeGreaterUnit=\"\" sizeLessCond=\"\" sizeLessValue=\"\" sizeLessUnit=\"\" sizeRelation=\"\" fileEncrypt=\"\" Reference=\"\" fileOwner=\"\" timeCreateCond=\"\" timeCreateTime=\"\" timeRelation=\"\" timeModifyCond=\"\" timeModifyTime=\"\" ColumnSum=\"\" RowSum=\"\" />\
		< / contain>\
		< exception relation = \"1\" />\
		< / group>\
		< / rules>\
		< / root>\
		";
		m_extService->setFileOrMsgRule(rule,1,[&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
}