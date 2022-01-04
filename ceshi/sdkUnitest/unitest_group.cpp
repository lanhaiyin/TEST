#include "unitest_group.h"
namespace serviceTest {
	GroupServiceUnitest::GroupServiceUnitest() {
		m_groupService = g_test[0].GROUPSERVICE();
	}

	void _GBKToUTF8(std::string &strAscii)                            //用于  中文 -> utf-8  转化 ，创建群使用
	{
#ifdef _WIN32
		std::string strGBK;
		strGBK = strAscii.c_str();
		std::string strOutUTF8 = "";
		WCHAR * str1;
		int n = MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, NULL, 0);
		str1 = new WCHAR[n];
		MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, str1, n);
		n = WideCharToMultiByte(CP_UTF8, 0, str1, -1, NULL, 0, NULL, NULL);
		char * str2 = new char[n];
		WideCharToMultiByte(CP_UTF8, 0, str1, -1, str2, n, NULL, NULL);
		strOutUTF8 = str2;
		delete[]str1;
		str1 = NULL;
		delete[]str2;
		str2 = NULL;
		strAscii = strOutUTF8.c_str();
#else
#endif
		//return strOutUTF8;
	}

	int GroupServiceUnitest::createGroup() {
		//******************创建群**************    //稍后再请求
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::vector<int64> members = { m_config->m_testFriendUserId };

		std::string groupname = "test111";
		_GBKToUTF8(groupname);
#ifdef SDK_UNITEST_DEV
		m_groupService->createGroup(2, groupname, members, [&](int code, int64 groupid) {
			g_sta_groupid = groupid;
			reqProm.set_value(code);
		});
#else
		m_groupService->createGroup(1,1,2,groupname, members, [&](int code, int64 groupid) {
			g_sta_groupid = groupid;
			reqProm.set_value(code);
		});
#endif
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::createGroupEx() {
		//******************创建群**************    //稍后再请求
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::vector<int64> members = {};

		std::string groupname = "test111";
		_GBKToUTF8(groupname);
#ifdef SDK_UNITEST_DEV
		m_groupService->createGroupEx(1, groupname, members, [&](int code, int64 groupid, std::vector<Contact>& json1, std::vector<Contact>& json2, std::vector<Contact>& json3, std::vector<Contact>& json4) {
			reqProm.set_value(code);
			groupidEx = groupid;
		});
#else
		m_groupService->createGroupEx(1,1,1,groupname, members,[&](int code, int64 groupid, std::vector<Contact>& json1, std::vector<Contact>& json2, std::vector<Contact>& json3, std::vector<Contact>& json4) {
			reqProm.set_value(code);
			groupidEx = groupid;
		});
#endif
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::addGroup() {
		//******************加群**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_groupService->addGroup(m_config->m_testGroupId, "Beijing VRV Software Corporation Limited.", [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::transferGroup() {
		//******************转让群**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_groupService->transferGroup(m_config->m_testGroupId, m_config->m_testFriendUserId, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::getGroupSet() {
		//******************获取群设置 **************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_groupService->getGroupSet(m_config->m_testGroupId, [&](int code, int8 a, int8 b) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::setGroupSet() {
		//******************设置群设置**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_groupService->setGroupSet(m_config->m_testGroupId, 2, 1, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	bool GroupServiceUnitest::getGroupInfo() {
		//******************获取群信息(同步接口)**************
		Group groupInfo;
		int64 groupID = 0;
		bool ret = false;
		m_groupService->getGroupInfo(m_config->m_testGroupId, groupInfo);
		groupID = groupInfo.info.value().groupId.value();
		ret = ((groupID == m_config->m_testGroupId) ? true : false);
		return ret;
	}

	int GroupServiceUnitest::setGroupInfo() {
		//******************设置群信息**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		GroupUpdate group;
		group.groupName = std::string("test Group");
		m_groupService->setGroupInfo(m_config->m_testGroupId, group, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::getGroupList() {
		//******************获取群列表 （同步接口）**************
		std::vector<SSharedPtr<TinyGroup> > groups = {};

		m_groupService->getGroupList(groups);
		return 0;
	}

	int GroupServiceUnitest::inviteMember() {
		//******************邀请群成员**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::vector<int64> members = { m_config->m_testFriendUserId2 };

		m_groupService->inviteMember(m_config->m_testGroupId, members, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::inviteMemberEx() {
		//******************邀请群成员**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::vector<int64> members = { m_config->m_testFriendUserId2 };

		m_groupService->inviteMemberEx(m_config->m_testGroupId, members, [&](int code, std::vector<Contact>& json1, std::vector<Contact>& json2, std::vector<Contact>& json3, std::vector<Contact>& json4) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::removeMember() {
		//******************移除群成员**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_groupService->removeMember(m_config->m_testGroupId, m_config->m_testFriendUserId2, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::removeMembers() {
		//******************批量移除群成员**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::vector<int64> userids = { m_config->m_testFriendUserId2 };

		m_groupService->removeMembers(m_config->m_testGroupId, userids, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::setMemberInfo() {
		//******************设置群成员信息**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		Member member;
		member.groupId = m_config->m_testGroupId;
		member.id = m_config->m_testFriendUserId;

		m_groupService->setMemberInfo(member, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	bool GroupServiceUnitest::isInGroup() {
		//******************判断用户是否在群里 (同步接口)**************
		bool code = m_groupService->isInGroup(g_sta_groupid, m_config->m_testFriendUserId);
		return code;
	}

	bool GroupServiceUnitest::getMemberInfo() {
		//******************设置群成员信息**************
		Member member;
		member.groupId = g_sta_groupid;

		bool code = m_groupService->getMemberInfo(g_sta_groupid, m_config->m_testFriendUserId, member);
		return code;
	}

	int GroupServiceUnitest::getMemberDetailInfo() {
		//******************获取群成员详细信息 (网络接口)**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_groupService->getMemberDetailInfo(m_config->m_testGroupId, m_config->m_testFriendUserId2, [&](int code, MemberDetailInfo info) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::getMemberList() {
		//******************获取群成员列表**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_groupService->getMemberList(m_config->m_testGroupId, [&](int code, std::vector<SSharedPtr<Member> > json) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::getMemberListNoDlHeadImg() {
		//******************获取群成员列表,不检查下载头像**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_groupService->getMemberListNoDlHeadImg(m_config->m_testGroupId,[&](int code, std::vector<SSharedPtr<Member> > json) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::getGroupFileList_1() {
		//******************获取群列表**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_groupService->getGroupFileList(m_config->m_testGroupId, 0, 2, 0, [&](int code, std::vector<Fileinfo> json) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::deleteGroupFile() {
		//******************删除群文件**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::vector<int64> files = { 000000001 };

		m_groupService->deleteGroupFile(files, m_config->m_testGroupId, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::getGroupFileList_2() {
		//******************获取群文件列表**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		GetGroupFile par;
		par.targetID = 20211130580;
		par.msgBeginID = 0;
		par.fileType = 0;
		par.fileTerm = 0;
		par.offsetFlag = 0;
		par.msgOffset = 0;

		m_groupService->getGroupFileList(par, [&](int code, std::vector<Fileinfo> json) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::getPersonalGroupImg() {
		//******************获取个人群聊背景图片**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		int ret = 0;

		m_groupService->getPersonalGroupImg(m_config->m_testGroupId, [&](int code, std::string json) {
			reqProm.set_value(code);
		});
		ret = reqFut.get();
		return ret;
	}
	int GroupServiceUnitest::setPersonalGroupImg() {
		//******************设置个人群聊背景图片**************
		std::promise<int> reqPromSetPsGI;
		std::future<int> reqFutSetPsGI = reqPromSetPsGI.get_future();
		int ret = 0;
		printf("\n m_groupService=0x%x m_config=0x%x m_testGroupId=%lld m_backGroundImg=%s\n", m_groupService.get(), m_config, m_config->m_testGroupId, m_config->m_backGroundImg.c_str());
		m_groupService->setPersonalGroupImg(m_config->m_testGroupId, m_config->m_backGroundImg, [&](int code) {
			reqPromSetPsGI.set_value(code);
		});
		ret = reqFutSetPsGI.get();
		return ret;
	}

	int GroupServiceUnitest::setGroupMsgRemindType() {
		//******************设置群消息接受消息模式**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_groupService->setGroupMsgRemindType(m_config->m_testGroupId,1, [&](int code){
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::getGroupMsgRemindType() {
		//******************获取群消息免打扰模式**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_groupService->getGroupMsgRemindType(m_config->m_testGroupId, [&](int code, int json) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::setGroupExtraInfo() {
		//******************设置群消息内容模式和V标**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_groupService->setGroupExtraInfo(g_sta_groupid, 1, -1, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	bool GroupServiceUnitest::getGroupOnlineStatus() {
		//******************查询群在线人数状态**************
		std::promise<int> reqPromGet;
		std::future<int> reqFutGet = reqPromGet.get_future();

		m_groupService->getGroupOnlineStatus(m_config->m_testGroupId, [&](int code, int online, int downline) {
			reqPromGet.set_value(code);
		});
		int code = reqFutGet.get();
		bool isOk = (code == 0 || code == 100);
		return isOk;
	}

	int GroupServiceUnitest::setGroupFileTerm() {
		//******************设置群文件永久**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		SetGroupFileTermParam groupFileInfo;
		groupFileInfo.groupId = m_config->m_testGroupId;
		groupFileInfo.userID = m_config->m_iMyUserId;
		groupFileInfo.fileId = 23132627;
		groupFileInfo.fileTerm = 2;
		groupFileInfo.fileUrl = m_config->m_upLoadFilePath;

		m_groupService->setGroupFileTerm(groupFileInfo, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::addGroupAnnouncement() {
		//******************添加群公告**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		GroupAnnouncementInfo info;
		info.groupID = m_config->m_testGroupId;

		m_groupService->addGroupAnnouncement(info, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::delGroupAnnouncement() {
		//******************删除单个群公告**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_groupService->delGroupAnnouncement(m_config->m_testGroupId, 12, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::checkGroupAnnouncementExist() {
		//******************校验群公告是否存在**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_groupService->checkGroupAnnouncementExist(m_config->m_testGroupId, 12, [&](int code, int exist) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::getGroupAnnouncementList() {
		//******************分页获取群公告列表**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		GetGroupAnnouncementListParam pageInfo;
		pageInfo.groupID = m_config->m_testGroupId;
		pageInfo.userID = m_config->m_iMyUserId;

		m_groupService->getGroupAnnouncementList(pageInfo, [&](int code, GroupAnnouncementList b) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::setGroupBeepTone() {
		//******************设置个人群聊提示音信息**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_groupService->setGroupBeepTone(m_config->m_testGroupId, " ", [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::getGroupBeepTone() {
		//******************获取个人群聊提示音信息**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_groupService->getGroupBeepTone(m_config->m_testGroupId, [&](int code, std::string json) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::setGroupChatForbid() {
		//******************设置群禁言或群成员禁言**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_groupService->setGroupChatForbid(m_config->m_testGroupId, m_config->m_testFriendUserId, 2, 0, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::removeGroup() {
		//******************解散群/群成员退群**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_groupService->removeGroup(1, g_sta_groupid, [&](int code) {
			reqProm.set_value(code);


		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::removeGroupEx() {
		//******************解散群/群成员退群**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_groupService->removeGroup(1, groupidEx, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::isGroupMember() {
		//******************判断是否为群成员 同步接口(注释)**************
		//std::promise<int> reqProm;
		//std::future<int> reqFut = reqProm.get_future();


		//m_groupService->isGroupMember(1, sta_groupid, [&](int code) {
		//	reqProm.set_value(code);


		//});
		//int code = reqFut.get();
		return 0;
	}


}