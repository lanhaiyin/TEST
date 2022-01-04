#include "unitest_group.h"
namespace serviceTest {
	GroupServiceUnitest::GroupServiceUnitest() {
		m_groupService = g_test[0].GROUPSERVICE();
	}

	void _GBKToUTF8(std::string &strAscii)                            //����  ���� -> utf-8  ת�� ������Ⱥʹ��
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
		//******************����Ⱥ**************    //�Ժ�������
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
		//******************����Ⱥ**************    //�Ժ�������
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
		//******************��Ⱥ**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_groupService->addGroup(m_config->m_testGroupId, "Beijing VRV Software Corporation Limited.", [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::transferGroup() {
		//******************ת��Ⱥ**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_groupService->transferGroup(m_config->m_testGroupId, m_config->m_testFriendUserId, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::getGroupSet() {
		//******************��ȡȺ���� **************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_groupService->getGroupSet(m_config->m_testGroupId, [&](int code, int8 a, int8 b) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::setGroupSet() {
		//******************����Ⱥ����**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_groupService->setGroupSet(m_config->m_testGroupId, 2, 1, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	bool GroupServiceUnitest::getGroupInfo() {
		//******************��ȡȺ��Ϣ(ͬ���ӿ�)**************
		Group groupInfo;
		int64 groupID = 0;
		bool ret = false;
		m_groupService->getGroupInfo(m_config->m_testGroupId, groupInfo);
		groupID = groupInfo.info.value().groupId.value();
		ret = ((groupID == m_config->m_testGroupId) ? true : false);
		return ret;
	}

	int GroupServiceUnitest::setGroupInfo() {
		//******************����Ⱥ��Ϣ**************
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
		//******************��ȡȺ�б� ��ͬ���ӿڣ�**************
		std::vector<SSharedPtr<TinyGroup> > groups = {};

		m_groupService->getGroupList(groups);
		return 0;
	}

	int GroupServiceUnitest::inviteMember() {
		//******************����Ⱥ��Ա**************
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
		//******************����Ⱥ��Ա**************
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
		//******************�Ƴ�Ⱥ��Ա**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_groupService->removeMember(m_config->m_testGroupId, m_config->m_testFriendUserId2, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::removeMembers() {
		//******************�����Ƴ�Ⱥ��Ա**************
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
		//******************����Ⱥ��Ա��Ϣ**************
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
		//******************�ж��û��Ƿ���Ⱥ�� (ͬ���ӿ�)**************
		bool code = m_groupService->isInGroup(g_sta_groupid, m_config->m_testFriendUserId);
		return code;
	}

	bool GroupServiceUnitest::getMemberInfo() {
		//******************����Ⱥ��Ա��Ϣ**************
		Member member;
		member.groupId = g_sta_groupid;

		bool code = m_groupService->getMemberInfo(g_sta_groupid, m_config->m_testFriendUserId, member);
		return code;
	}

	int GroupServiceUnitest::getMemberDetailInfo() {
		//******************��ȡȺ��Ա��ϸ��Ϣ (����ӿ�)**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_groupService->getMemberDetailInfo(m_config->m_testGroupId, m_config->m_testFriendUserId2, [&](int code, MemberDetailInfo info) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::getMemberList() {
		//******************��ȡȺ��Ա�б�**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_groupService->getMemberList(m_config->m_testGroupId, [&](int code, std::vector<SSharedPtr<Member> > json) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::getMemberListNoDlHeadImg() {
		//******************��ȡȺ��Ա�б�,���������ͷ��**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_groupService->getMemberListNoDlHeadImg(m_config->m_testGroupId,[&](int code, std::vector<SSharedPtr<Member> > json) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::getGroupFileList_1() {
		//******************��ȡȺ�б�**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_groupService->getGroupFileList(m_config->m_testGroupId, 0, 2, 0, [&](int code, std::vector<Fileinfo> json) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::deleteGroupFile() {
		//******************ɾ��Ⱥ�ļ�**************
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
		//******************��ȡȺ�ļ��б�**************
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
		//******************��ȡ����Ⱥ�ı���ͼƬ**************
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
		//******************���ø���Ⱥ�ı���ͼƬ**************
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
		//******************����Ⱥ��Ϣ������Ϣģʽ**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_groupService->setGroupMsgRemindType(m_config->m_testGroupId,1, [&](int code){
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::getGroupMsgRemindType() {
		//******************��ȡȺ��Ϣ�����ģʽ**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_groupService->getGroupMsgRemindType(m_config->m_testGroupId, [&](int code, int json) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::setGroupExtraInfo() {
		//******************����Ⱥ��Ϣ����ģʽ��V��**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_groupService->setGroupExtraInfo(g_sta_groupid, 1, -1, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	bool GroupServiceUnitest::getGroupOnlineStatus() {
		//******************��ѯȺ��������״̬**************
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
		//******************����Ⱥ�ļ�����**************
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
		//******************���Ⱥ����**************
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
		//******************ɾ������Ⱥ����**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_groupService->delGroupAnnouncement(m_config->m_testGroupId, 12, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::checkGroupAnnouncementExist() {
		//******************У��Ⱥ�����Ƿ����**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		m_groupService->checkGroupAnnouncementExist(m_config->m_testGroupId, 12, [&](int code, int exist) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::getGroupAnnouncementList() {
		//******************��ҳ��ȡȺ�����б�**************
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
		//******************���ø���Ⱥ����ʾ����Ϣ**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_groupService->setGroupBeepTone(m_config->m_testGroupId, " ", [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::getGroupBeepTone() {
		//******************��ȡ����Ⱥ����ʾ����Ϣ**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_groupService->getGroupBeepTone(m_config->m_testGroupId, [&](int code, std::string json) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::setGroupChatForbid() {
		//******************����Ⱥ���Ի�Ⱥ��Ա����**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_groupService->setGroupChatForbid(m_config->m_testGroupId, m_config->m_testFriendUserId, 2, 0, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::removeGroup() {
		//******************��ɢȺ/Ⱥ��Ա��Ⱥ**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_groupService->removeGroup(1, g_sta_groupid, [&](int code) {
			reqProm.set_value(code);


		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::removeGroupEx() {
		//******************��ɢȺ/Ⱥ��Ա��Ⱥ**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();


		m_groupService->removeGroup(1, groupidEx, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}

	int GroupServiceUnitest::isGroupMember() {
		//******************�ж��Ƿ�ΪȺ��Ա ͬ���ӿ�(ע��)**************
		//std::promise<int> reqProm;
		//std::future<int> reqFut = reqProm.get_future();


		//m_groupService->isGroupMember(1, sta_groupid, [&](int code) {
		//	reqProm.set_value(code);


		//});
		//int code = reqFut.get();
		return 0;
	}


}