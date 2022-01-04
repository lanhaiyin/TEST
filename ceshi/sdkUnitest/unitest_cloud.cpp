#include "unitest_cloud.h"
namespace serviceTest {
	CloudServiceUnitest::CloudServiceUnitest() {
		m_cloudService = g_test[0].CLOUDSERVICE();
	}
	int CloudServiceUnitest::uploadFile() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		CloudUploadFileInfo info;
		info.pid = 0;
		info.localPath = m_config->m_upLoadFilePath;
		info.fileCode = "100110011747te";
		m_cloudService->uploadFile(info, [&](int code, const std::string&) {
			reqProm.set_value(code);

		}, [&](int32 pros, int32 pross, const std::string pro) {});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::queryFloder() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_cloudService->queryFloder(1, m_config->m_iMyUserId, [&](int code, std::vector<CloudFileInfo> fileinfo) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	//int CloudServiceUnitest::queryFloder() {
	//	std::promise<int> reqProm;
	//	std::future<int> reqFut = reqProm.get_future();

	//	m_cloudService->queryFloder(1, m_config->m_iMyUserId, [&](int code, std::vector<CloudFileInfo> fileinfo) {
	//		reqProm.set_value(code);

	//	});
	//	int code = reqFut.get();
	//	return code;
	//}
	int CloudServiceUnitest::addFile() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		CloudAddFileInfo info;
		info.pid = 0;
		info.encryptKey = "1234567898765432";
		info.filePath = m_config->m_upLoadFilePath;
		info.fileName = "m_upLoadFilePath.txt";
		info.fileType = 1;
		info.fileCode = "123456";
		info.uploaderId = m_config->m_iMyUserId;
		m_cloudService->addFile(info, [&](int code, CloudFileInfo fileinfo) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::delFile() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::vector<std::string> fileCodes = { "123456" };

		m_cloudService->delFile(fileCodes, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::renameFile() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		CloudCommonParam info;
		m_cloudService->renameFile(info, [&](int code, cloudCommonRet ret) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::getFileById() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_cloudService->getFileById(23132627, [&](int code, CloudFileInfo fileinfo) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::getFilesByHash() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::string hash;
		m_cloudService->getFilesByHash(hash, [&](int code, std::vector<CloudFileInfo> fileinfo) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	bool CloudServiceUnitest::getFilesByHashSync() {
		std::string hash;
		std::vector<CloudFileInfo> fileinfo = m_cloudService->getFilesByHashSync(hash);
		bool isOk = !fileinfo.empty();
		return isOk;
	}
	int CloudServiceUnitest::searchFiles() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_cloudService->searchFiles(2, m_config->m_iMyUserId, m_config->m_account, m_config->m_account, [&](int code, std::vector<CloudFileInfo> fileinfo) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::createTeam() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		CloudAddFileInfo  info;
		info.uploaderId = m_config->m_testFriendUserId;
		m_cloudService->createTeam(info, [&](int code, CloudFileInfo fileinfo) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::teamAddMember() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		TeamMemberInfo user;
		user.userId = m_config->m_testFriendUserId;
		std::vector<TeamMemberInfo> members = { user };
		m_cloudService->teamAddMember(members, [&](int code) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::teamRemoveMember() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		TeamMemberInfo user;
		user.userId = m_config->m_testFriendUserId;
		std::vector<TeamMemberInfo> members = { user };
		m_cloudService->teamRemoveMember(members, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::teamResetMember() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::vector<TeamMemberInfo> members;
		TeamMemberInfo member;
		member.fileId = 0;
		member.headImg = "ceshi";
		member.userId = m_config->m_iMyUserId;
		member.userName = m_config->m_account;
		m_cloudService->teamResetMember(members, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::getTeams() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_cloudService->getTeams(m_config->m_iMyUserId, [&](int code, std::vector<CloudFileInfo> fileinfo) {
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::teamMembers() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_cloudService->teamMembers(1, [&](int code, std::vector<TeamMemberInfo> teaminfo) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::getRoles() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_cloudService->getRoles(1, [&](int code, std::vector<CloudRoleInfo> roleinfos) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::getRoleById() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_cloudService->getRoleById(1, [&](int code, CloudRoleInfo roleinfo) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::addRole() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		BaseRoleInfo role;
		role.isShow = 1;
		role.name = m_config->m_account;
		role.totalSize = 1;
		role.uploadSize = 1;
		m_cloudService->addRole(role, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::editRole() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		BaseRoleInfo role;
		role.isShow = 1;
		role.name = m_config->m_account;
		role.totalSize = 1;
		role.uploadSize = 1;
		m_cloudService->editRole(role, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::removerRole() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_cloudService->removerRole(m_config->m_testFriendUserId, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::getPermission() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_cloudService->getPermission(6, 2, m_config->m_iMyUserId, [&](int code, CloudPermission permission) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::getCloudFileInfo() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_cloudService->getCloudFileInfo(m_config->m_iMyUserId, [&](int code, CloudUserInfo userinfo) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::createPubDir() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		CloudAddFileInfo info;
		m_cloudService->createPubDir(info, [&](int code, CloudFileInfo fileinfo) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::moveFile() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::vector<int64> fileIds;
		m_cloudService->moveFile(m_config->m_iMyUserId, fileIds, 23132638, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::copyFile() {
		std::promise<int> reqProm;
			std::future<int> reqFut = reqProm.get_future();
			std::vector<int64> fileIds;
			m_cloudService->copyFile(m_config->m_iMyUserId, fileIds, 23132638, [&](int code) {
				reqProm.set_value(code);

			});
			int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::querySubFolders() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_cloudService->querySubFolders(m_config->m_iMyUserId, 1, [&](int code, std::vector<CloudFileInfo> fileinfo) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::queryFolderByParam() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		FolderOpenBean fob;
		fob.ownerId = m_config->m_iMyUserId;
		m_cloudService->queryFolderByParam(fob, [&](int code, std::vector<CloudFileInfo> fileinfo) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::checkFileExit() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		CloudPreUpload preUploadInfo;
		m_cloudService->checkFileExit(preUploadInfo, [&](int code, cloudCommonRet ret) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::uploadFile_new() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		NewCloudUploadFileInfo Info;
		Info.pid = 0;
		Info.user = m_config->m_iMyUserId;
		Info.localPath = m_config->m_upLoadFilePath;
		//Info.ftype = 1;
		//Info.type = 1;
		/*Info.encryptKey = "1234567898765432";
		Info.localId = time(NULL);
		Info.sowner = m_config->m_iMyUserId;
		Info.ssdkid = m_config->sdkId;
		Info.sdkid = m_config->sdkId;
		Info.virtualid = 2674003547217069184;*/
		m_cloudService->uploadFile(Info, [&](int code, const std::string& info) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::downloadFile() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		CloudDownloadFileInfo info;
		info.localPath = m_config->m_upLoadFilePath;
		info.fileName = "uploadFilePath";
		info.userId = m_config->m_iMyUserId;
		info.fileId = 2627846121963259008;
		info.localId = 1597891051;
		info.fileSize = 1234;
		info.sowner = m_config->m_iMyUserId;
		m_cloudService->downloadFile(info, [&](int code, const std::string& localpath) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();

		return code;
	}
	int CloudServiceUnitest::delFile_new() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		CloudCommonParam info;
		m_cloudService->delFile(info, [&](int code, cloudCommonRet commonret, std::vector<delFileRet> filereq) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();

		return code;
	}
	int CloudServiceUnitest::renameFile_new() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		CloudCommonParam info;
		m_cloudService->renameFile(info, [&](int code, cloudCommonRet commonret) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();

		return code;
	}
	int CloudServiceUnitest::moveFile_new() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		CloudCommonParam info;
		m_cloudService->moveFile(info, [&](int code, cloudCommonRet ret, std::vector<returnSuc> suc, std::vector<returnFail> fail) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();

		return code;
	}
	int CloudServiceUnitest::copyFile_new() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		CloudCommonParam info;
		m_cloudService->copyFile(info, [&](int code, cloudCommonRet ret, std::vector<returnSuc> suc, std::vector<returnFail> fail) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();

		return code;
	}
	int CloudServiceUnitest::restoreCloudFile() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::vector<int64> restoreids;
		m_cloudService->restoreCloudFile(m_config->m_iMyUserId, 0, restoreids, [&](int code, cloudCommonRet ret, std::vector<returnSuc> suc, std::vector<returnFail> fail) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::clearCloudFile() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::vector<int64> delids;
		m_cloudService->clearCloudFile(m_config->m_iMyUserId, 0, delids, [&](int code, cloudCommonRet ret, std::vector<returnSuc> suc, std::vector<returnFail> fail) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::syncCloudFile() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_cloudService->syncCloudFile(1, m_config->m_iMyUserId, m_config->sdkId, 0, [&](int code, std::vector<newCloudFileInfo>& fileinfo) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::getCloudTrashInfo() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_cloudService->getCloudTrashInfo(m_config->m_iMyUserId, 0, [&](int code, std::vector<newCloudFileInfo> fileinfo) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::getNewCloudFileInfo() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_cloudService->getNewCloudFileInfo(m_config->m_iMyUserId, 0, 0, [&](int code, std::vector<newCloudFileInfo> fileinfo) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::getNextLevelInfo() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_cloudService->getNextLevelInfo(m_config->m_testFriendUserId, 0, 0, [&](int code, std::vector<newCloudFileInfo> fileinfo) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::getCloudUserInfo() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_cloudService->getCloudUserInfo(m_config->m_iMyUserId, 0, [&](int code, CloudUserInfo userinfo) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::createShare() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		cloudShare shareInfo;
		m_cloudService->createShare(shareInfo, [&](int code, cloudCommonRet commonret, std::vector<cloudShareRet>shareret) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::cloudShareToOther() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		cloudShare shareInfo;
		m_cloudService->cloudShareToOther(shareInfo, [&](int code, std::vector<cloudShareOtherRet> shareret) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::cloudShareToMe() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		cloudShare shareInfo;
		m_cloudService->cloudShareToMe(shareInfo, [&](int code, std::vector<newCloudFileInfo> fileinfo) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::cloudChangeSharefolder() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		cloudShare shareInfo;
		m_cloudService->cloudChangeSharefolder(shareInfo, [&](int code, cloudCommonRet commonret) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::cloudChangeShareuser() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		cloudShare shareInfo;
		m_cloudService->cloudChangeShareuser(shareInfo, [&](int code, cloudCommonRet commonret) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::getCloudShareInfo() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		cloudShare shareInfo;
		m_cloudService->getCloudShareInfo(shareInfo, [&](int code, newCloudFileInfo fileinfo, std::vector<cloudShareOtherRet> otherret) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::setUserSetting() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		CloudUserInfo userSetting;
		m_cloudService->setUserSetting(userSetting, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::getUserSetting() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_cloudService->getUserSetting(m_config->m_iMyUserId, 1, [&](int code, CloudUserInfo userinfo) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::getCloudContactInfo() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		std::vector<int64> vecUser;
		m_cloudService->getCloudContactInfo(m_config->m_iMyUserId, 1, vecUser, [&](int code, std::vector<cloudContactInfo> contactinfo) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::getCloudTransferHistory() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_cloudService->getCloudTransferHistory(0, 0, [&](int code, std::vector<cloudTransferInfo> transferInfo) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	int CloudServiceUnitest::delCloudTransferHistory() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		cloudTransferInfo transferInfo;
		m_cloudService->delCloudTransferHistory(transferInfo, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
	
	int CloudServiceUnitest::clearCloudTransferHistory() {
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();
		m_cloudService->clearCloudTransferHistory(1, 1, [&](int code) {
			reqProm.set_value(code);

		});
		int code = reqFut.get();
		return code;
	}
}