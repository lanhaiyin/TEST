#pragma once

#include "../model/LoginInfo.h"
#include "../model/Packet.h"
#include "../model/Account.h"
#include "IService.h"

#include <string>

#define VER_ICLOUD INTERFACE_VERSION(1,0)
static const VRVIID IID_ICloudService = { 0x526f54ac, 0x48b2, 0x41ec, 0x87, 0xd8, 0x86, 0x98, 0xfb, 0xb1, 0xf7, 0x3c };

namespace service
{

class ICloudService :public IService
{
public:
    virtual ~ICloudService(){}


	/**
	* \brief 上传文件到云盘
	* @param[in] pid 文件唯一标示
	* @param[in] userId 用户ID
	* @param[in] cb _1 错误信息  _2文件夹下所有子文件和子文件夹信息
	* @param[in] pro  进度回调 _1 extra_req  _2 process  _3 文件当前传入大小/文件总大小
	*/
	virtual void uploadFile(CloudUploadFileInfo &info, SFunction<void(ErrorInfo, const std::string&)> cb, SFunction<void(int32, int32, const std::string&)> pro = SNull) = 0;

	/**
	* \brief 查询文件夹
	* @param[in] pid 文件唯一标示
	* @param[in] userId 用户ID
	* @param[in] cb _1 错误信息  _2文件夹下所有子文件和子文件夹信息
	*/
    virtual void queryFloder(int64 pid, int64 userId, SFunction<void(ErrorInfo, std::vector<CloudFileInfo>&)> cb) = 0;

	/**
	* \brief 添加文件
	* @param[in] info 添加文件需要的信息
	* @param[in] cb _1 错误信息  _2添加的文件的详细信息
	*/
	virtual void addFile(CloudAddFileInfo &info, SFunction<void(ErrorInfo, CloudFileInfo&)> cb) = 0;

	/**
	* \brief 删除文件
	* @param[in] fileCodes 要删除的文件编码集合
	* @param[in] cb _1 错误信息
	*/
	virtual void delFile(std::vector<std::string> &fileCodes, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 重命名文件
	* @param[in] fileId 文件ID
	* @param[in] fileName 文件名
	* @param[in] cb _1 错误信息
	*/
	virtual void renameFile(int64 fileId, const std::string &fileName,  SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 通过文件ID获取文件
	* @param[in] fileId 文件ID
	* @param[in] cb _1 错误信息 _2获取的文件信息
	*/
	virtual void getFileById(int64 fileId, SFunction<void(ErrorInfo, CloudFileInfo&)> cb) = 0;

	/**
	* \brief 通过文件hash码获取文件
	* @param[in] hash  hash码
	* @param[in] cb _1 错误信息 _2获取的文件信息
	*/
	virtual void getFilesByHash(const std::string &hash, SFunction<void(ErrorInfo, std::vector<CloudFileInfo>&)> cb) = 0;

	/**
	* \brief 通过文件hash码获取文件(同步接口)
	*/
	virtual std::vector<CloudFileInfo> getFilesByHashSync(const std::string &hash) = 0;
	
	/**
	* \brief 搜索文件
	* @param[in] type  搜索方式  1 搜索文本; 2用户名搜索； 3 both 是搜索指定用户的文件带有关键字的
	* @param[in] userId 用户id
	* @param[in] userName 用户名
	* @param[in] searchText 搜索的内容
	* @param[in] cb _1 错误信息 _2获取的文件信息
	*/
	virtual void searchFiles(int type, int64 userId, const std::string &userName, const std::string &searchText, SFunction<void(ErrorInfo, std::vector<CloudFileInfo>&)> cb) = 0;

	/**
	* \brief 创建团队文件夹
	* @param[in] info 添加文件需要的信息
	* @param[in] cb _1 错误信息  _2添加的文件的详细信息
	*/
	virtual void createTeam(CloudAddFileInfo  &info, SFunction<void(ErrorInfo, CloudFileInfo&)> cb) = 0;

	/**
	* \brief 添加团队成员
	* @param[in] members 成员信息
	* @param[in] cb _1 错误信息 
	*/
	virtual void teamAddMember(std::vector<TeamMemberInfo> &members, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 移除团队成员
	* @param[in] members 成员信息
	* @param[in] cb _1 错误信息
	*/
	virtual void teamRemoveMember(std::vector<TeamMemberInfo> &members, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 重置团队成员
	* @param[in] members 成员信息
	* @param[in] cb _1 错误信息
	*/
	virtual void teamResetMember(std::vector<TeamMemberInfo> &members, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 获取团队文件夹
	* @param[in] userId 用户id
	* @param[in] cb _1 错误信息 _2 team信息集合
	*/
	virtual void getTeams(int64 userId, SFunction<void(ErrorInfo, std::vector<CloudFileInfo>&)> cb) = 0;

	/**
	* \brief 获取团队文件夹所有成员
	* @param[in] fileId 文件ID
	* @param[in] cb _1 错误信息 _2 member信息集合
	*/
	virtual void teamMembers(int64 fileId, SFunction<void(ErrorInfo, std::vector<TeamMemberInfo>&)> cb) = 0;

	/**
	* \brief 获取团队成员角色
	* @param[in] isShow   角色是否在前端显示 目前始终为1
	* @param[in] cb _1 错误信息 _2 role信息集合
	*/
	virtual void getRoles(int8 isShow, SFunction<void(ErrorInfo, std::vector<CloudRoleInfo>&)> cb) = 0;

	/**
	* \brief 通过角色ID获取团队成员角色
	* @param[in] roleId
	* @param[in] cb _1 错误信息 _2 role信息
	*/
	virtual void getRoleById(int64 roleId, SFunction<void(ErrorInfo, CloudRoleInfo&)> cb) = 0;

	/**
	* \brief 增加团队成员角色
	* @param[in] role 角色信息
	* @param[in] cb _1 错误信息
	*/
	virtual void addRole(BaseRoleInfo &role, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 编辑团队成员角色
	* @param[in] role 角色信息
	* @param[in] cb _1 错误信息
	*/
	virtual void editRole(BaseRoleInfo &role, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 移除团队成员角色
	* @param[in] roleId 角色ID
	* @param[in] cb _1 错误信息
	*/
	virtual void removerRole(int64 roleId, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 获取许可信息
	* @param[in] roleId 角色ID
	* @param[in] fileId 文件ID
	* @param[in] userId 用户ID
	* @param[in] cb _1 错误信息
	*/
	virtual void getPermission(int64 roleId, int64 fileId, int64 userId, SFunction<void(ErrorInfo, CloudPermission&)> cb) = 0;

	/*
	* @param[in] userId 用户ID
	* @param[in] cb _1 错误信息
	* @param[in] cb _2 用户云盘信息
	*/
	virtual void getCloudFileInfo(int64 userId, SFunction<void(ErrorInfo, CloudUserInfo&)> cb) = 0;

	/**
	* \brief 创建公共文件夹
	* @param[in] info 添加文件夹需要的信息
	* @param[in] cb _1 错误信息 _2文件详细信息
	*/
	virtual void createPubDir(CloudAddFileInfo &info, SFunction<void(ErrorInfo, CloudFileInfo&)> cb) = 0;

	/*
	* \brief 移动文件夹
	* @param[in] userId 用户id
	* @param[in] fileIds 文件Id
	* @param[in] dstFolderId 目标文件Id
	*/
	virtual void moveFile(int64 userId, std::vector<int64> &fileIds, int64 dstFolderId,
		SFunction<void(ErrorInfo)> cb) = 0;

	/*
	* \brief 复制文件夹
	* @param[in] userId 用户id
	* @param[in] fileIds 文件Id
	* @param[in] dstFolderId 目标文件Id
	*/
	virtual void copyFile(int64 userId, std::vector<int64> &fileIds, int64 dstFolderId,
		SFunction<void(ErrorInfo)> cb) = 0;
	/*
	* \brief 查询文件夹下面的子文件夹
	* @param[in] userId 用户id
	* @param[in] folderId 文件夹Id
	*/
	virtual void querySubFolders(int64 userId, int64 folderId, SFunction<void(ErrorInfo, std::vector<CloudFileInfo>&)> cb) = 0;
	
	/*
	* \brief 查询文件夹
	*/
	virtual void queryFolderByParam(FolderOpenBean &fob, SFunction<void(ErrorInfo, std::vector<CloudFileInfo>&)> cb) = 0;



////////////////////////////////////// 新云盘接口////////////////////////

	/*
	* \brief 查询文件是否存在
	*/
	virtual void checkFileExit(CloudPreUpload &preUploadInfo, SFunction<void(ErrorInfo, cloudCommonRet &)> cb) = 0;
	/**
	* \brief 上传文件到云盘
	* @param[in] pid 文件唯一标示
	* @param[in] userId 用户ID
	* @param[in] cb _1 错误信息  _2文件夹下所有子文件和子文件夹信息
	* @param[in] pro  进度回调 _1 extra_req  _2 process  _3 文件当前传入大小/文件总大小
	*/
	virtual void uploadFile(NewCloudUploadFileInfo &info, SFunction<void(ErrorInfo, const std::string&)> cb, SFunction<void(int32, int32, const std::string&)> pro = SNull) = 0;
	/**
	* \brief 下载文件
	* @param[in] targetId 发送者的targetId
	* @param[in] fileId
	* @param[in] localId
	* @param[in] sdkId
	* @param[in] cb  传入接收结果回调 _1错误信息  _2接收成功后文件路径 localPath _3发送者ID
	* @param[in] pro  进度回调
	* @return 每个文件对应的唯一localID
	*/
	virtual void downloadFile(CloudDownloadFileInfo &info, SFunction<void(ErrorInfo, const std::string&)> cb,
		SFunction<void(int32, int32, const std::string&)> pro = SNull) = 0;
	
	/**
	* \brief 删除文件
	* @param[in] 
	* @param[in] cb _1 错误信息
	*/
	virtual void delFile(CloudCommonParam &info, SFunction<void(ErrorInfo, cloudCommonRet&, std::vector<delFileRet>&)> cb) = 0;

	/**
	* \brief 重命名文件
	* @param[in] 
	* @param[in] 
	* @param[in] cb _1 错误信息
	*/
	virtual void renameFile(CloudCommonParam &info, SFunction<void(ErrorInfo, cloudCommonRet&)> cb) = 0;

	/*
	* \brief 移动文件夹
	* @param[in] 
	* @param[in] 
	* @param[in] 
	*/
	virtual void moveFile(CloudCommonParam &info, SFunction<void(ErrorInfo, cloudCommonRet &, std::vector<returnSuc>&, std::vector<returnFail>&)> cb) = 0;

	/*
	* \brief 复制文件夹
	* @param[in] 
	* @param[in] 
	* @param[in] 
	*/
	virtual void copyFile(CloudCommonParam &info, SFunction<void(ErrorInfo, cloudCommonRet &, std::vector<returnSuc>&, std::vector<returnFail>&)> cb) = 0;

	/*
	* \brief 云盘回收站还原
	*/
	virtual void restoreCloudFile(int64 userid, int64 sdkid, std::vector<int64> restoreids, SFunction<void(ErrorInfo, cloudCommonRet &, std::vector<returnSuc>&, std::vector<returnFail>&)> cb) = 0;

	/*
	* \brief 云盘回收站清空
	*/
	virtual void clearCloudFile(int64 userid, int64 sdkid, std::vector<int64> delids, SFunction<void(ErrorInfo, cloudCommonRet &, std::vector<returnSuc>&, std::vector<returnFail>&)> cb) = 0;

	/*
	* \brief 同步文件/文件夹 接口
	*/
	virtual void syncCloudFile(int32 type, int64 user, int64 sdkid, int64 atime, SFunction<void(ErrorInfo, std::vector<newCloudFileInfo> &)> cb) = 0;
	
	/*
	* \brief 拉取回收站信息
	*/
	virtual void getCloudTrashInfo(int64 userid, int64 sdkid, SFunction<void(ErrorInfo, std::vector<newCloudFileInfo> &)> cb) = 0;

	/*
	* \brief 获取文件夹下所有的子目录和文件的详细信息

	*/
	virtual void getNewCloudFileInfo(int64 userid, int64 sdkid, int64 virtualid, SFunction<void(ErrorInfo, std::vector<newCloudFileInfo> &)> cb) = 0;

	/*
	* \brief 获取下一层文件夹的信息
	*/
	virtual void getNextLevelInfo(int64 userid, int64 sdkid, int64 virtualid, SFunction<void(ErrorInfo, std::vector<newCloudFileInfo> &)> cb) = 0;
	
	/*
	* \brief 个人信息获取, 容量 cap
	*/
	virtual void getCloudUserInfo(int64 userid, int64 sdkid, SFunction<void(ErrorInfo, CloudUserInfo&)> cb) = 0;
	/*
	* \brief 创建共享目录
	*/
	virtual void createShare(cloudShare &shareInfo, SFunction<void(ErrorInfo, cloudCommonRet&, std::vector<cloudShareRet>&)> cb) = 0;
	/*
	* \brief 共享给别人的目录
	*/
	virtual void cloudShareToOther(cloudShare &shareInfo, SFunction<void(ErrorInfo, std::vector<cloudShareOtherRet>&)> cb) = 0;
	/*
	* \brief 别人共享给我的
	*/
	virtual void cloudShareToMe(cloudShare &shareInfo, SFunction<void(ErrorInfo, std::vector<newCloudFileInfo>&)> cb) = 0;
	/*
	* \brief 修改共享目录权限
	*/
	virtual void cloudChangeSharefolder(cloudShare &shareInfo, SFunction<void(ErrorInfo, cloudCommonRet&)> cb) = 0;
	/*
	* \brief 修改共享人权限
	*/
	virtual void cloudChangeShareuser(cloudShare &shareInfo, SFunction<void(ErrorInfo, cloudCommonRet&)> cb) = 0;
	/*
	* \brief 获取文件自身的文件信息
	*/
	virtual void getCloudFileInfo(int64 userid, int64 sdkid, int64 virtualid, SFunction<void(ErrorInfo, std::vector<newCloudFileInfo> &)> cb) = 0;
	/*
	* \brief 获取文件自身的共享信息
	*/
	virtual void getCloudShareInfo(cloudShare &shareInfo, SFunction<void(ErrorInfo, newCloudFileInfo&, std::vector<cloudShareOtherRet>&)> cb) = 0;
	/*
	* \brief 个人设置信息  回收站文件保留天数，上传/下载数目
	*/
	virtual void setUserSetting(CloudUserInfo& userSetting, SFunction<void(ErrorInfo)> cb) = 0;
	/*
	* \brief 获取个人设置信息
	*/
	virtual void getUserSetting(int64 userid, int64 sdkid, SFunction<void(ErrorInfo, CloudUserInfo&)> cb) = 0;
	/*
	* \brief 获取用户名
	*/
	virtual void getCloudContactInfo(int64 userid, int64 sdkid, std::vector<int64> vecUser, SFunction<void(ErrorInfo, std::vector<cloudContactInfo>&)> cb) = 0;

	/*
	* \brief 获取云盘上传/下载历史任务
	*/
	virtual void getCloudTransferHistory(int32 transferType, int32 transferStatu, SFunction<void(ErrorInfo, std::vector<cloudTransferInfo>&)> cb) = 0;
	/*
	* \brief 删除云盘上传/下载历史任务
	*/
	virtual void delCloudTransferHistory(cloudTransferInfo& transferInfo, SFunction<void(ErrorInfo)> cb) = 0;
	/*
	* \brief 清空云盘上传/下载历史任务
	* param transferType 1 上传任务， 2 下载任务
	* param transferStatue  1 删除成功， 2 删除失败， 3 都删除
	*/
	virtual void clearCloudTransferHistory(int32 transferType, int32 transferStatu, SFunction<void(ErrorInfo)> cb) = 0;
};



}