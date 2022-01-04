#include "unitest_chat.h"
namespace serviceTest {
	ChatServiceUnitest::ChatServiceUnitest() {
		m_chatService = g_test[0].CHATSERVICE();
	}
	bool ChatServiceUnitest::getChatList() {
		std::vector<SSharedPtr<Chat> > recontacts;
		m_chatService->getChatList(recontacts);
		bool isOk = !recontacts.empty();
		return isOk;
	}
	int ChatServiceUnitest::removeChat() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_chatService->removeChat(m_config->m_testFriendUserId2, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ChatServiceUnitest::sendMessage() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		Msg msg;
		BadWord badword;
		std::string pro;
		m_chatService->sendMessage(msg, [&](int code, int64 time, int64 msgid, BadWord& badword) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int ChatServiceUnitest::sendAppendixMessage() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		MsgFile msg;
		msg.filePath = m_config->m_upLoadFilePath;
		msg.targetId = m_config->m_testGroupTarget;
		msg.fromId = m_config->m_iMyUserId;
		msg.msgProperties = "";
		msg.msgId = 23134396;
		msg.msgType = 6;
		msg.fileName = "uploadFilePath.txt";
		msg.encryptKey = "1234567898765432";
		msg.time = 1596624561208;
		msg.isPrivateMsg = 0;
		msg.localId = time(NULL);
		msg.activeType = 0;
		msg.deviceType = 1;
		msg.timeZone = 32;
		msg.noStore = 0;
		msg.deal = false;
		m_chatService->sendAppendixMessage(msg, [&](int code, int64 time, int64 msgid, BadWord badword) {
			reqProm.set_value(code);
		}, [&](int32, int32, const std::string&) {; });
		int code = reqFut.get();
		if (code == 11100)
			code = 0;
		return code;
	}
	int ChatServiceUnitest::insertMessage() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		Msg msg;
		msg.fromId = m_config->m_testFriendUserId;
		msg.targetId = m_config->m_testGroupId;
		msg.userName = " ";
		msg.msgId = 23443585;
		msg.msgType = 2;
		msg.time = 1598841371942;
		msg.userName = m_config->m_account;
		msg.isPrivateMsg = 0;
		msg.activeType = 0;
		msg.deviceType = 0;
		msg.body = "123";
		msg.msgRemindMode = 3;
		m_chatService->insertMessage(msg, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ChatServiceUnitest::transferMessage() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		Msg msg;
		msg.msgType = 1;
		msg.lastMsgId = 0;
		msg.fromId = m_config->m_iMyUserId;
		msg.toId = m_config->m_testFriendUserId;
		msg.realTargetId = m_config->m_testFriendUserId;
		m_chatService->transferMessage(msg, [&](int code, int64 time, BadWord& badword) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ChatServiceUnitest::forwardMessage() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
#ifdef SDK_UNITEST_DEV
		m_chatService->forwardMessage(m_config->m_testGroupTarget, m_config->m_testFriendUserId, 23210951, [&](int code, int64 time, int64 messageid, BadWord& badword) {
			reqProm.set_value(code);
		});
#else
		m_chatService->forwardMessage(m_config->m_testGroupTarget, m_config->m_testFriendUserId, 23210951,1,[&](int code, int64 time, int64 messageid, BadWord& badword) {
			reqProm.set_value(code);
		});
#endif
		int code = reqFut.get();
		return code;
	}
	int ChatServiceUnitest::deleteAllMessage() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_chatService->deleteAllMessage(false, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ChatServiceUnitest::deleteMessageById() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::vector<int64> msgIds;
		int64 messageid = m_config->m_testMsgId;
		m_chatService->deleteMessageById(m_config->m_testFriendUserId2, msgIds, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ChatServiceUnitest::deleteMessageByTime() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_chatService->deleteMessageByTime(m_config->m_testFriendUserId2, 20, 22, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	bool ChatServiceUnitest::setMessageRead() {
		int64 messageid = m_config->m_testMsgId;
		m_chatService->setMessageRead(m_config->m_testFriendUserId2, messageid);
		/*	int code = reqFut.get();*/
		bool isOk = messageid;
		return isOk;
	}
	int ChatServiceUnitest::setMessageUnRead() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_chatService->setMessageUnRead(0, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	bool ChatServiceUnitest::getMessages() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		int64 messageid = m_config->m_testMsgId;
		std::vector<int64> fromUserId;
		std::vector<int32> msgType;
		std::vector<MsgPtr> msg;
		m_chatService->getMessages(m_config->m_testFriendUserId2, messageid, 1, 0, fromUserId, msgType, [&](int code, int64 a, std::vector<MsgPtr> msg) {
			reqProm.set_value(code);
			msg = msg;
		});
		int code = reqFut.get();
		bool isOk = !code&&msg.empty();
		return isOk;
	}
	int ChatServiceUnitest::chatTop() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_chatService->chatTop(m_config->m_testFriendUserId2, true, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ChatServiceUnitest::getImgMsg() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_chatService->getImgMsg(m_config->m_testFriendUserId2, [&](int code, std::vector<MsgPtr> img) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ChatServiceUnitest::getUrlInfo() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::string  path;
		m_chatService->getUrlInfo(" ", path, [&](int code, std::string url, std::string head, std::string path, std::string abs) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ChatServiceUnitest::setPrivateKey() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_chatService->setPrivateKey(m_config->m_testFriendUserId2, "", [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ChatServiceUnitest::decryptMsg() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::vector<int64> msgIds;
		m_chatService->decryptMsg(m_config->m_testFriendUserId2, msgIds, [&](int code, int64 msgid, std::vector<MsgPtr> msg) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ChatServiceUnitest::updateMsg() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		Msg msg;
		msg.targetId = m_config->m_iMyUserId;
		m_chatService->updateMsg(msg, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ChatServiceUnitest::addRecontact() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		Chat chat;

		m_chatService->addRecontact(chat, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ChatServiceUnitest::getMsgDays() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_chatService->getMsgDays(m_config->m_testFriendUserId2, 0, [&](int code, std::vector<model::YMD> ymd, std::vector<int32> co) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ChatServiceUnitest::getMsgFromDay() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		model::YMD ymd;
		m_chatService->getMsgFromDay(m_config->m_testFriendUserId2, 0, 0, 0, ymd, [&](int code, std::vector<MsgPtr> Msgptr) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ChatServiceUnitest::getAllMsgCount() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_chatService->getAllMsgCount(m_config->m_testFriendUserId2, [&](int code, int32 count) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	bool ChatServiceUnitest::sendShortMessage() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::vector<int64> userIds;
		userIds.push_back(4330043922);
		std::map<int64, std::string>  shrmsg;
		m_chatService->sendShortMessage(userIds, [&](int code, std::map<int64, std::string>  shrmsg) {
			reqProm.set_value(code);
			shrmsg = shrmsg;
		});
		int code = reqFut.get();
		bool isOk = !code &&shrmsg.empty();
		return isOk;
	}
	bool ChatServiceUnitest::getGroupMsgReadState() {
		//std::promise<int> reqProm;
		//std::future<int> reqFut = reqProm.get_future();
		//std::map < std::string, std::vector<int64>>states;
		//m_chatService->getGroupMsgReadState(m_config->m_testGroupTarget, 0, [&](int code, std::map < std::string, std::vector<int64>>states) {
		//	reqProm.set_value(code);
		//	states = states;
		//});
		//bool isOk = states.empty();
		return true;

	}
	bool ChatServiceUnitest::getGroupMsgUnreadCounter() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::vector<SnapshotInfo> infos;
		std::vector<MsgUnreadCounter> states;
		m_chatService->getGroupMsgUnreadCounter(m_config->m_testGroupId, infos, [&](int code, std::vector<MsgUnreadCounter> states) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		bool isOk = !code;
		return isOk;
	}
	int ChatServiceUnitest::getGroupMsgUnreadInfo() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		SnapshotInfo infos;
		m_chatService->getGroupMsgUnreadInfo(m_config->m_testGroupId, infos, [&](int code, std::vector<int64> read, std::vector<int64> unread) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int ChatServiceUnitest::getGroupDivers() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_chatService->getGroupDivers(m_config->m_testGroupId, [&](int code, std::vector<int64> userID) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int ChatServiceUnitest::getContractMaxReadId() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_chatService->getContractMaxReadId(m_config->m_testFriendUserId, [&](int code, int64 userID) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	bool ChatServiceUnitest::getUnReadMsgCountByType() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		int64 count = m_chatService->getUnReadMsgCountByType(1);
		bool isOk = !count;
		return isOk;
	}
	int ChatServiceUnitest::sendMsgInputState() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_chatService->sendMsgInputState(m_config->m_testFriendUserId2, 0, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ChatServiceUnitest::getAtMessage() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		getReqAtMsg req;
		m_chatService->getAtMessage(req, [&](int code, int64 id, std::vector<MsgPtr>  msg) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ChatServiceUnitest::setMsgReads() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_chatService->setMsgReads([&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	bool ChatServiceUnitest::getBadWordList() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		bool isOk = false;
#ifdef SDK_UNITEST_DEV
		std::vector<std::string> badword = m_chatService->getBadWordList();
		isOk = !badword.empty();
#else
		std::vector<model::st_dbBadWord> badword = m_chatService->getBadWordList();
		isOk = !badword.empty();
#endif
		return isOk;
	}
	int ChatServiceUnitest::getIssueById() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_chatService->getIssueById(m_config->m_testGroupTarget, [&](int code, GroupIssue issue) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ChatServiceUnitest::searchIssueLocal() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_chatService->searchIssueLocal(m_config->m_testGroupId, "", [&](int code, std::vector<GroupIssue> issue) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ChatServiceUnitest::getIssueMessages() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_chatService->getIssueMessages(m_config->m_testGroupId, 0, 1, 0, m_config->m_testGroupTarget, [&](int code, int64 n, std::vector<MsgPtr> msg) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ChatServiceUnitest::deleteIssueLocal() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::vector<int64> issues = { m_config->m_testGroupTarget };
		m_chatService->deleteIssueLocal(issues, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ChatServiceUnitest::setGroupAnnouncementMsgReaded() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_chatService->setGroupAnnouncementMsgReaded(m_config->m_testGroupId, 0, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ChatServiceUnitest::getMsgByType() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_chatService->getMsgByType(m_config->m_testGroupId, 1, [&](int code, std::vector<MsgPtr> msgs) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ChatServiceUnitest::getTaskMsg() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::string timeTask = "20:00:00";
		m_chatService->getTaskMsg(m_config->m_testGroupId, timeTask, [&](int code, int64 targetId, std::vector<MsgPtr> msgs) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	bool ChatServiceUnitest::MakeCombineMsg() {
		MsgCombine msg;
		std::string json;
		m_chatService->MakeCombineMsg(msg, json);
		//int code = reqFut.get();
		bool isOk = !json.empty();
		return isOk;
	}
	bool ChatServiceUnitest::ParseCombineMsg() {
		MsgCombine msg;
		std::string cmbjson;
		bool isOk = m_chatService->ParseCombineMsg(cmbjson, msg);
		//int code = reqFut.get();
		return isOk;
	}
	bool ChatServiceUnitest::toCombineMsg() {
		Msg *baseMsg;
		SSharedPtr<MsgCombine> msg = m_chatService->toCombineMsg(baseMsg);
		//int code = reqFut.get();
		bool isOk = msg.use_count();
		return isOk;
	}
	bool ChatServiceUnitest::toNotebookMsg() {
		Msg *baseMsg;
		SSharedPtr<MsgCombine> msg = m_chatService->toNotebookMsg(baseMsg);
		//int code = reqFut.get();
		bool isOk = msg.use_count();
		return isOk;
	}
	bool ChatServiceUnitest::setGroupTopMsg() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		Msg Msg;
		Msg.fromId = m_config->m_iMyUserId;
		Msg.relatedMsgId = 23119277;
		Msg.msgType = 64;
		Msg.msgId = 23119281;
		Msg.targetId = m_config->m_testGroupTarget;
		Msg.subType = 2;
		Msg.localId = time(NULL);
		int64 res = m_chatService->setGroupTopMsg(Msg, [&](int code, int64 Time, int64 msgid, BadWord badword) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		//bool isOk = !code&& res;
		return res;
	}
	int ChatServiceUnitest::getGroupTopMsgById() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_chatService->getGroupTopMsgById(m_config->m_testGroupTarget, 0, 1, 0, [&](int code, int64 id, std::vector<MsgPtr> msg) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	bool ChatServiceUnitest::isGroupTopMsgSync() {
		bool isFalse = m_chatService->isGroupTopMsgSync(m_config->m_testGroupTarget, 23107795);
		return isFalse;
	}
	int ChatServiceUnitest::createReminderMsg() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		Msg msg;
		m_chatService->createReminderMsg(0, 20, msg, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ChatServiceUnitest::getReminderMsgByPage() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_chatService->getReminderMsgByPage(1, 10, [&](int code, int64 scount, int64 sumpage, std::vector<reminderMsg> reminderMsg) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ChatServiceUnitest::deleteReminderMsg() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_chatService->deleteReminderMsg(1, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int ChatServiceUnitest::upMsgCount() {
		//std::promise<int> reqProm;
		//std::future<int> reqFut = reqProm.get_future();
		//upMsgCt msg;
		//msg.PackName = "test";
		//msg.UserName = m_config->m_account;
		//msg.MsgNum = 1;
		//msg.devtype = "Phone";
		//m_chatService->upMsgCount(msg, [&](int code) {
		//	reqProm.set_value(code);
		//});
		//int code = reqFut.get();
		return 0;
	}
	int ChatServiceUnitest::getBWLibList() {
		
		std::vector <st_dbBWLib> result;
		
		result = m_chatService->getBWLibList();
		if (!result.empty())
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}

	int ChatServiceUnitest::getFileBWList()
	{
		
		std::vector <std::string> result;

		result = m_chatService->getFileBWList();
		if (!result.empty())
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}

	int ChatServiceUnitest::handleDelayMsgByType()
	{
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_chatService->handleDelayMsgByType(82011051, 1, [&](int code)
		{
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}

	int ChatServiceUnitest::cleanClientData()
	{
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_chatService->cleanClientData(82011051,0, [&](int code)
		{
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
}








