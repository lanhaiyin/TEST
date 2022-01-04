#pragma once

#include "../model/Group.h"
#include"../model/Packet.h"
#include "../model/Contact.h"
#include "../model/Member.h"
#include "IService.h"

#include <string>
#include <vector>

#define VER_GROUP INTERFACE_VERSION(1,0)
static const VRVIID IID_IGroupService = { 0x6df7882f, 0x5ab3, 0x4326, 0x4d, 0xd2, 0xaf, 0x3f, 0xb2, 0xd1, 0xa2, 0x16 };

namespace service
{

class IGroupService : public IService
{
public:

	virtual ~IGroupService(){}

	/*****************************************注册通知回调*******************************************/

	/**
	* \brief 监听群头像更新
	* @param[in] _1  群ID
	* @param[in] _2	  传入头像
	*/
	virtual void regGroupHeadImgUpdateCb(SFunction < void(int64, const std::string&) > cb) = 0;

	/**
	* \brief 监听群成员头像更新
	* @param[in] _1  群成员ID
	* @param[in] _2	  传入头像
	*/
	virtual void regMemberHeadImgUpdateCb(SFunction < void(int64, const std::string&) > cb) = 0;

	/**
	* \brief 监听群背景更新
	* @param[in] _1    群ID
	* @param[in] _2	  传入头像
	*/
	virtual void regGroupBackImgUpdateCb(SFunction < void(int64, const std::string&) > cb) = 0;

	/**
	* \brief 设置监听群信息更新的回调
	* @param[in] _1 操作类型 1.添加 2.更新，31.解散 32.移除 33.退出 35.群禁言或取消禁言
	* @param[in] _2 群信息
	*/
	virtual void regGroupRefreshCb(SFunction< void(int8, const Group&) > cb) = 0;




	/**
	* \brief 设置监听群主更新的回调
	* @param[in] _1 群主ID
	* @param[in] _2 群主名
	* @param[in] _3 群ID
	* @param[in] _4 群名
	*/
	virtual void regTransferGroupCb(SFunction< void(int64, const std::string&, int64, const std::string&) > cb) = 0;
	
	/**
	* \brief 设置监听群成员信息更新的回调
	* @param[in] _1 群ID
	* @param[in] _2 群成员信息
	*/
	virtual void regGrpMemInfoRefreshCb(SFunction< void(int64, const Member&) > cb) = 0;

	/**
	* \brief  设置群成员列表更新的回调
	* @param[in] _1 操作类型  1 添加， 32 移除， 33 退出
	* @param[in] _2 群ID
	* @param[in] _3 变更的群成员集合
	*/
	virtual void regGrpMemRefreshCb(SFunction< void(int, int64, std::vector<SSharedPtr<Member> >&) > cb) = 0;

	/**
	* \brief  设置获取群成员列表的回调
	* @param[in] _1 错误信息，不使用，只是为了和getMemberList回调函数一致
	* @param[in] _2 新增群成员
	* @param[in] _3 更新群成员信息
	* @param[in] _4 删除群成员
	*/
	virtual void regGetGrpMemListCb(SFunction<void(ErrorInfo, std::vector<SSharedPtr<Member> >&, std::vector<SSharedPtr<Member> >&, std::map<int64,std::vector<int64> >&)> cb) = 0;
	
	/**
	* \brief  监听群列表刷新
	* @param[in] _1 群列表
	*/
	virtual void regGroupListCb(SFunction< void(std::vector<SSharedPtr<TinyGroup> >&) > cb) = 0;


	/**
	* \brief  监听群信息或群设置更新
	* @param[in] _1 群更新或群设置信息
	* type=25 群v标用户信息更新 
	*/
	virtual void regGroupInfoOrSettingCb(SFunction< void(GroupInfoOrSettingInfo&) > cb) = 0;


	/**
	* \brief 设置监听群文档更新的回调
	* @param[in]群groupid  //1:正在上传 2:等待上传 3:上传完成 4:上传失败 5:重新上传 6:等待下载 7.正在下载 8:下载失败 9.下载完成
	* @param[in] _2 群文档更新信息
	*/
	virtual void regGDocRefreshCb(SFunction< void(GDocUpDownNotice&) > cb) = 0;


	/*****************************************请求接口*******************************************/

	/**
	* \brief 创建群
	* @param[in] level 传入群等级 1.临时群，2.普通群
	* @param[in] name 传入群名称
	* @param[in] members   传入群成员
	* @param[in] securityLevel 传入群密级
	* @param[in] powerSwitch   传入群提权开关
	* @param[in] cb  传入接收结果回调  _1错误信息  _2群ID
	* @param[in] securityLevel  powerSwitch  群密级，提权开关,没有默认给0
	*/

	virtual void createGroup(int32 securityLevel, int8 powerSwitch ,int level, const std::string &name, std::vector<int64> &members, SFunction<void(ErrorInfo, int64)> cb) = 0;

	/**
	* \brief 创建群
	* @param[in] level 传入群等级 1.临时群，2.普通群
	* @param[in] name 传入群名称
	* @param[in] members   传入群成员
	* @param[in] securityLevel 传入群密级
	* @param[in] powerSwitch   传入群提权开关
	* @param[in] cb  传入接收结果回调  _1错误信息  _2群ID _3入群邀请需要验证用户集合,_4不接受入群邀请用户集合, _5直接可以进群用户集合 _6需要管理员验证的用户列表
	* @param[in] securityLevel  powerSwitch  群密级，提权开关,没有默认给0
	*/
	virtual void createGroupEx(int32 securityLevel, int8 powerSwitch,int level, const std::string &name, std::vector<int64> &members, SFunction<void(ErrorInfo, int64, std::vector<Contact>&, std::vector<Contact>&, std::vector<Contact>&, std::vector<Contact>&)> cb) = 0;
	//virtual void createGroup(int level, const std::string &name, std::vector<int64> &members, SFunction<void(ErrorInfo, int64)> cb) = 0;

	/**
	* \brief 加群
	* @param[in] groupid 传入群id
	* @param[in] verify_info 传入验证信息
	* @param[in] cb  传入接收结果回调  _1错误信息
	*/
	virtual void addGroup(int64 groupid, const std::string &verify_info, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 解散群
	* @param[in] type 传入操作类型 1 群主解散群，2 群成员退群
	* @param[in] groupid 传入群id
	* @param[in] cb  传入接收结果回调  _1错误信息
	*/
	virtual void removeGroup(int type, int64 groupid, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 转让群
	* @param[in] groupid 传入群id
	* @param[in] userid 传入新群主的id
	* @param[in] cb  传入接收结果回调  _1错误信息
	*/
	virtual void transferGroup(int64 groupid, int64 userid, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 获取群设置
	* @param[in] groupid 传入群id
	* @param[in] cb  传入接收结果回调  _1错误信息 \n
	*    _2  验证类型: 1.不允许任何人添加, 2.需要验证信息, 3.允许任何人添加.\n
	*	 _3	 是否允许群成员邀请好友加入群: 1.允许 2.不允许.
	*    _4  企业群群主是否可以转让群 0否(默认), 1是
	*    _5  企业群管理员是否可以邀请入群  0否, 1是(默认)
	*    _6  是否开启追一下；2-关闭；1-开启(默认)
	*    _7  是否开启抖一抖:2-关闭(默认)；1-开启
	*    后续扩展使用 getGroupSetExNew接口，返回extendGroupSetting包含以上字段
	*/
	virtual void getGroupSetExNew(int64 groupid, SFunction<void(ErrorInfo, extendGroupSetting&)> cb) = 0;

	virtual void getGroupSetEx(int64 groupid, SFunction<void(ErrorInfo, int8, int8, int8, int8)> cb) = 0;
	//老接口
	virtual void getGroupSet(int64 groupid, SFunction<void(ErrorInfo, int8, int8)> cb) = 0;

	/**
	* \brief 设置群设置
	* @param[in] groupid 传入群id
	* @param[in] verify_type 传入验证类型 1:不允许任何人添加,2：需要验证信息,3：允许任何人添加
	* @param[in] is_allow 传入是否允许成员邀请用户 1,允许 2,不允许 isAllow
	*（说明,可选参数）：isAllowTransferOwner，isAllowAdminInvite这两个字段暂不允许客户端修改，只能后台修改。传值也无效。
	* @param[in] isAllowTransferOwner 企业群群主是否可以转让群 0否(默认), 1是
    * @param[in] isAllowAdminInvite   企业群管理员是否可以邀请入群  0否, 1是(默认)
	* @param[in] isChase 是否开启追一下；2-关闭；1-开启(默认)
	* @param[in] isShake   是否开启抖一抖:2-关闭(默认)；1-开启
	* @param[in] cb  传入接收结果回调  _1错误信息 
	*/
	virtual void setGroupSet(extendGroupSetting& extendSet, SFunction<void(ErrorInfo)> cb) = 0;

	virtual void setGroupSet(int64 groupid, int8 verify_type, int8 is_allow, int8 isAllowTransferOwner, int8 isAllowAdminInvite, SFunction<void(ErrorInfo)> cb) = 0;
	//老接口
	virtual void setGroupSet(int64 groupid, int8 verify_type, int8 is_allow, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 获取群信息 （同步接口）
	* @param[in] groupid 传入群id
	* @param[out] groupInfo 群信息
	*/
	virtual void getGroupInfo(int64 groupid, Group& groupInfo) = 0;

	/**
	* \brief 设置群信息
	* @param[in] groupId 设置的群ID
	* @param[in] group  可设置的群信息
	* @param[in] cb  传入接收结果回调  _1错误信息 
	*/
	virtual void setGroupInfo(int64 groupId, GroupUpdate &group, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 获取群列表 （同步接口）
	* @param[in] cb  传入接收结果回调  _1群信息集合;
	*/
	virtual void getGroupList(std::vector<SSharedPtr<TinyGroup> > &groups) = 0;


	/**
	* \brief 邀请群成员
	* @param[in] groupid 传入群id
	* @param[in] members 传入成员名单
	* @param[in] cb  传入接收结果回调   _1错误信息
	*/
	virtual void inviteMember(int64 groupid, std::vector<int64> &members, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 邀请群成员
	* @param[in] groupid 传入群id
	* @param[in] members 传入成员名单
	* @param[in] cb  传入接收结果回调   _1错误信息,_2入群邀请需要验证用户集合, _3不接受入群邀请用户集合, _4直接可以进群用户集合 _5需要管理员验证的用户列表
	*/
	virtual void inviteMemberEx(int64 groupid, std::vector<int64> &members, SFunction<void(ErrorInfo, std::vector<Contact>&, std::vector<Contact>&, std::vector<Contact>&, std::vector<Contact>&)> cb) = 0;
	//virtual void inviteMember(int64 groupid, std::vector<int64> &members, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 移除群成员
	* @param[in] groupid 传入群id
	* @param[in] userid 传入需要移除的成员id
	* @param[in] cb  传入接收结果回调   _1错误信息
	*/
	virtual void removeMember(int64 groupid, int64 userid, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 批量移除群成员
	* @param[in] groupid 传入群id
	* @param[in] userids 传入需要移除的成员id集合
	* @param[in] cb  传入接收结果回调   _1错误信息
	*/
	virtual void removeMembers(int64 groupid, std::vector<int64> userids, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 设置群成员信息
	* @param[in] member 传入成员信息
	* @param[in] cb  传入接收结果回调
	*/
	virtual void setMemberInfo(Member &member, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 判断用户是否在群里 (同步接口)
	* @param[in] groupid 传入群id
	* @param[in] userid 传入成员id
	* @return false代表不是群成员
	*/
	virtual bool isInGroup(int64 groupId, int64 userId) = 0;

	/**
	* \brief 获取群成员信息 (同步接口)
	* @param[in] groupid 传入群id
	* @param[in] userid 传入成员id
	* @param[out] member返回成员信息
	* @return false代表没有此信息
	*/
	virtual bool getMemberInfo(int64 groupid, int64 userid, Member &member) = 0;
	/**
	* \brief 获取群成员详细信息 (网络接口)
	* @param[in] groupid 传入群id
	* @param[in] userid 传入成员id
	* @param[out] MemberDetailInfo 返回成员信息
	* @return false代表没有此信息
	*/
	virtual void getMemberDetailInfo(int64 groupid, int64 userid, SFunction<void(ErrorInfo, MemberDetailInfo)>) = 0;

	/**
	* \brief  获取群成员列表
	* @param[in] groupid 传入群id
	* @param[in] cb  传入接收结果回调   _1错误信息  _2群成员信息集合
	*/
	virtual void getMemberList(int64 groupid, SFunction<void(ErrorInfo, std::vector<SSharedPtr<Member> >&)> cb) = 0;

	/**
	* \brief  获取群成员列表,不检查下载头像
	* @param[in] groupid 传入群id
	* @param[in] cb  传入接收结果回调   _1错误信息  _2群成员信息集合
	*/
	virtual void getMemberListNoDlHeadImg(int64 groupid, SFunction<void(ErrorInfo, std::vector<SSharedPtr<Member> >&)> cb) = 0;
	
	/**
	* \brief 获取群文件列表
	* @param[in] groupid 传入群id
	* @param[in] beginid 传入起始id
	* @param[in] count 传入数量
	* @param[in] flag 传入偏移标志0为向上1为向下
	* @param[in] cb  传入接收结果回调   _1错误信息 _2文件信息集合
	*/
	virtual void getGroupFileList(int64 groupid, int64 beginid, int count, int8 flag, SFunction<void(ErrorInfo, std::vector<Fileinfo>&)> cb) = 0;
	virtual void getGroupFileList(GetGroupFile par, SFunction<void(ErrorInfo, std::vector<Fileinfo>&)> cb) =0;

	/**
	* \brief 删除群文件
	* @param[in] files 传入群文件id
	* @param[in] groupId 传入群id
	* @param[in] cb  传入接收结果回调   _1错误信息
	*/
	virtual void deleteGroupFile(std::vector<int64> &files, int64 groupId, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 获取个人群聊背景图片
	* @param[in] groupId 群ID
	* @param[in] cb  传入接收结果回调   _1错误信息   _2图片URL
	*/
	virtual void getPersonalGroupImg(int64 groupId, SFunction<void(ErrorInfo, const std::string&)> cb) = 0;

	/**
	* \brief 设置个人群聊背景图片
	* @param[in] groupId 群ID
	* @param[in] imgUrl 图片URL
	* @param[in] cb  传入接收结果回调   _1错误信息
	*/
	virtual void setPersonalGroupImg(int64 groupId, const std::string &imgUrl, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 设置群消息免打扰模式
	* @param[in] groupId 群ID
	* @param[in] mode 提醒模式 1：提示并接收消息；2：不提示，接收仅显示数目；3：屏蔽消息
	* @param[in] cb  传入接收结果回调   _1错误信息
	*/
	virtual void setGroupMsgRemindType(int64 groupId, int8 mode , SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 获取群消息免打扰模式
	* @param[in] groupId 群ID
	* @param[in] cb  传入接收结果回调   _1错误信息 _2提醒模式 1：提示并接收消息；2：不提示，接收仅显示数目；3：屏蔽消息 6:免打扰（云推送）
	*/
	virtual void getGroupMsgRemindType(int64 groupId, SFunction<void(ErrorInfo, int8)> cb) = 0;

	/**
	* \brief 设置群消息内容模式和V标
	* @param[in] groupId 群ID
	* @param[in] vSign 群V标 0为非v标群，1为v标群 -1为不设置
	* @param[in] msgContentMode 群通知消息内容模式: 1、通知详情  2、通知源，隐藏内容  3、完全隐藏   -1为不设置
	* @param[in] cb  传入接收结果回调   _1错误信息 _2提醒模式
	*/
	virtual void setGroupExtraInfo(int64 groupId, int8 vSign, int8 msgContentMode, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 判断是否为群成员 同步接口
	* @param[in] groupId 群ID
	* @param[in] memberId 群成员id
	* @return true代表为此群成员，返回false不为群成员
	*/
	//virtual bool isGroupMember(int64 groupId, int64 memberId) = 0;

    /**
    *\brief 查询群在线人数状态
    * @param[in] groupId 群Id
    * @param[out] cb 传入接收结果回调  _1错误信息  _2在线人数  _3离线人数
    */
    virtual void getGroupOnlineStatus(int64 groupId, SFunction<void(ErrorInfo, int64, int64)> cb) = 0;

	/**
	*\brief 设置群文件永久
	* @param[in] SetGroupFileTermParam 群文件信息
	* @param[out] cb 传入接收结果回调  _1错误信息 
	*/
	virtual void setGroupFileTerm(SetGroupFileTermParam groupFileInfo, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	*\brief 添加群公告
	* @param[in] GroupAnnouncementInfo 群公告信息
	* @param[out] cb 传入接收结果回调  _1错误信息
	*/
	virtual void addGroupAnnouncement(GroupAnnouncementInfo& info, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	*\brief 删除单个群公告
	* @param[in] groupId 群Id, announcementId 公告id
	* @param[out] cb 传入接收结果回调  _1错误信息 
	*/
	virtual void delGroupAnnouncement(int64 groupId, int64 announcementId, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	*\brief 校验群公告是否存在
	* @param[in] groupId 群Id, announcementId 公告id
	* @param[out] cb 传入接收结果回调  _1错误信息 _2 校验结果(0 公告不存在, 1 存在)
	*/
	virtual void checkGroupAnnouncementExist(int64 groupId, int64 announcementId, SFunction<void(ErrorInfo, int8)> cb) = 0;
	/**
	*\brief 分页获取群公告列表
	* @param[in] pageInfo 获取信息列表入参
	* @param[out] cb 传入接收结果回调  _1错误信息 _2 群公告列表
	*/
	virtual void getGroupAnnouncementList(GetGroupAnnouncementListParam& pageInfo, SFunction<void(ErrorInfo, GroupAnnouncementList&)> cb) = 0;

	/**
	* \brief 设置个人群聊提示音信息
	* @param[in] groupId 群ID
	* @param[in] toneInfo 提示音相关信息
	* @param[in] cb  传入接收结果回调   _1错误信息
	*/
	virtual void setGroupBeepTone(int64 groupId, const std::string &toneInfo, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 获取个人群聊提示音信息
	* @param[in] groupId 群ID
	* @param[in] cb  传入接收结果回调   _1错误信息   _2 提示音信息
	*/
	virtual void getGroupBeepTone(int64 groupId, SFunction<void(ErrorInfo, const std::string&)> cb) = 0;


	/**
	* \brief 设置群禁言或群成员禁言
	* @param[in] groupId 群ID
	* @param[in] targetId 被设置禁言的群成员，type为1和2时该值无效
	* @param[in] operateType 操作类型:1.解除群禁言 2.设置群禁言 3.解除用户禁言 4.设置用户禁言
	* @param[in] timeUtil 暂时无用，后期扩展定时功能使用，先传0
	* @param[in] cb  传入接收结果回调   _1错误信息 0:成功，100011022:没有权限禁言群/群成员，100011023:禁言对象不是群成员, 307:该群不存在
	*/
	virtual void setGroupChatForbid(int64 groupId, int64 targetId, int8 operateType, int64 timeUtil, SFunction<void(ErrorInfo)> cb) = 0;



	/*
	* \brief 修改群文档请求
	* @param[in] GroupDocAttribute &attribute 修改群文档属性结构体 
	groupID 必须
	docID 必须
	fileName 修改后的名称
	status 填2
	lastModifiedBy 操作者userID, 即调用者userID
	* @param[in] cb  传入接收结果回调   _1错误信息   _2 失败描述信息 _3  本次操作返回的版本号 _4 群文档占用空间总字节数 _5 群文档数量 
	11100:服务器异常 100:参数错误
	100027000: 成功
	100027001: 失败
	100011024: 群文件上传功能关闭
	100011025: 没有权限

	*/
	virtual void ModGroupShareFile(GroupDocAttribute &attribute, SFunction<void(ErrorInfo, const std::string&, int64, int64, int32)> cb) = 0;

	/*
	* \brief 修改群文档有效期
	* @param[in] GroupDocAttribute &attribute 修改群文档属性结构体
	groupID 必须
	docID 必须
	fileName 修改后的名称
	status 填2
	lastModifiedBy 操作者userID, 即调用者userID
	@param[in]  validityDays有效期
	* @param[in] cb  传入接收结果回调   _1错误信息   _2 失败描述信息 _3  本次操作返回的版本号 _4 群文档占用空间总字节数 _5 群文档数量
	11100:服务器异常 100:参数错误
	100027000: 成功
	100027001: 失败
	100011024: 群文件上传功能关闭
	100011025: 没有权限

	*/
	virtual void ModGroupShareFileValidity(GroupDocAttribute &attribute, int64 validityDays,SFunction<void(ErrorInfo, const std::string&, int64, int64, int32)> cb) = 0;


	/*
	* \brief 修改群文档权限
	* @param[in] GroupDocAttribute &attribute 修改群文档属性结构体
	groupID 必须
	docID 必须
	fileName 修改后的名称
	status 填2
	lastModifiedBy 操作者userID, 即调用者userID
	@param[in]  permission: 0 只读 1 可读可写
	* @param[in] cb  传入接收结果回调   _1错误信息   _2 失败描述信息 _3  本次操作返回的版本号 _4 群文档占用空间总字节数 _5 群文档数量
	11100:服务器异常 100:参数错误
	100027000: 成功
	100027001: 失败
	100011024: 群文件上传功能关闭
	100011025: 没有权限

	*/
	virtual void ModGShareFilePermission(GroupDocAttribute &attribute, int8 permission, SFunction<void(ErrorInfo, const std::string&, int64, int64, int32)> cb) = 0;


	/*
	* \brief 删除群文档请求
	* @param[in] GroupDocAttribute &attribute 删除群文档属性结构体
	groupID 必须
	docID 必须
	status 填3
	* @param[in] cb  传入接收结果回调   _1错误信息   _2 失败描述信息 _3  本次操作返回的版本号 _4 群文档占用空间总字节数 _5 群文档数量
	11100:服务器异常 100:参数错误
	100027000: 成功
	100027001: 失败
	100011024: 群文件上传功能关闭
	100011025: 没有权限
	*/
	virtual void DelGroupShareFile(GroupDocAttribute &attribute, SFunction<void(ErrorInfo, const std::string&, int64, int64, int32)> cb) = 0;

	/*查询最大version
	* @param[in] groupID  群id
	* @param[in] cb  传入接收结果回调   _1错误信息   _2 失败描述信息 _3  最大版本号
	*/
	virtual void GetGroupDocMVer(int64 groupID, SFunction<void(ErrorInfo, const std::string&, int64)> cb) = 0;

	/*群文件增量查询
	struct GroupDocServQuery {
		/*群ID
		1: i64 groupID;
		/*最大返回条数
		2: i16 pageSize;
		3: i64 version;本地版本号
	}
	/*查询最大version
	* @param[in] groupID  群id
	* @param[in] pageSize  一页数量
	* @param[in] version  本地最大版本号  
	* @param[in] cb  传入接收结果回调（返回服务器群最大版本和本地最大版本的差值）   _1错误信息   _2 失败描述信息 _3  最大版本号 _4 群文档占用空间总字节数 _5 群文档数量 _6 操作群文档的 记录属性GroupDocAttribute 

	 先 增量查询 然后 for循环 操作一次 im_GroupDocInfo 成功则 插入一条缓存 */
	virtual void QueryGroupDocOpt(int64 groupID, int32 pageSize, int64 version, SFunction<void(ErrorInfo, const std::string&, int64, int64, int32, std::vector<GroupDocAttribute>&)> cb) = 0;


	/**
	* \brief  获取群文档全量数据   获取缓存数据
	* @param[in] groupid 群id
	* @param[in] sversion 起始version
	* @param[in]  fversion 终止version
	* @param[in] cb  传入接收结果回调   _1错误信息  _2群文档属性集合
	缓存操作记录获取接口,
	fversion, 起始version 终止version fversion 返回的 GroupDocAttribute操作记录的vector
	*/
	virtual void GetGroupDocFileOpt(int64 groupid, int64 sversion, int64 fversion, std::vector<std::string>& opts) = 0;

	/**
	* \brief  获取群文档本地最大version
	* @param[in] 群id groupid
	* @param[in]  cb 本地最大版本号 maxversion
	*/
	virtual int64 GetMaxGDocVersion(int64 groupid) = 0;


	/**
	* \brief  获取群中群文档状态是否更新
	* @param[in] 群id groupid
	* @param[out] cb 所有群文档是否有更新
	*/
	virtual int8 GetGDocWhUpdate(int64 groupid) = 0;

	/**
	* \brief  获取群文档全量数据
	* @param[in] groupid 传入群id
	* @param[in]  docid 传入群文档id docid传0 代表全部 其他代表单个数据
	* @param[in] cb  传入接收结果回调   _1错误信息  _2群文档属性集合
	*/
	virtual void getGroupDocList(int64 groupid, int64 docid, SFunction<void(ErrorInfo, std::vector<GroupDocAttribute>&)> cb) = 0;

	/**
	* \brief  获取群上传下载 文档全量数据
	* @param[in] groupid 传入群id
	* @param[in]  docid 传入群文档id localpath传空 代表全部 其他代表单个数据
	* @param[in] cb  传入接收结果回调   _1错误信息  _2群文档属性集合
	*/
	virtual void getGDocUpDownList(int64 groupid, std::string &localpath, int8 whupordown, SFunction<void(ErrorInfo, std::vector<GroupDocUpdownInfo>&)> cb) = 0;



	/**
	* \brief  设置群上传下载 文档全量数据
	* @param[in] groupid 传入群id
	* @param[in]  修改的状态status 1:去掉 群文档更新状态 设置为群文档未更新 其他：暂不使用
	* @param[in] cb  传入接收结果回调
	*/
	virtual void setGDocUpDownList(int64 groupid, int8 status, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief  删除群上传下载 文档全量数据
	* @param[in] groupid 传入群id
	* @param[in]  docid 传入群文档id  localpath本地地址 docid 文档id
	* @param[in] cb  传入接收结果回调
	*/
	virtual void delGDocUpDownList(int64 groupid, std::string &localpath, int64 docid, SFunction<void(ErrorInfo)> cb) = 0;
};

} /*namespace service*/