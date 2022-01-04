﻿#ifndef CMD_TYPE_DEF_H_
#define CMD_TYPE_DEF_H_
////////////////////////////////////////////////////////////////////////////////
/// Copyright (C), 2015-2016
/// \file   	cmdTypeDef.h
/// \brief  	SDK消息号定义头文件
/// \author 	sharp.young
/// \version    0.2.1
/// \data       2016/1/10
/// \warning    只有[out]没有[in]是纯推送消息
/// \Function List
/// \History:
///  	<author> 		<time>    	   <version >    	<desc>
///     sharp		    2016/1/14        0.2.1         增加 logic_cmd_localSetting 消息定义
////////////////////////////////////////////////////////////////////////////////

namespace imsdk
{

//////////////////////////////////////////////////
/// \enum  路径定义
/// 使用中的路径定义
//////////////////////////////////////////////////
enum  enUserPath 
{
	user_dbPath,		///< enum 数据库路径 user_dbPath
    user_dbPluginPath,  ///< 插件数据库路径
	user_pluginPath,    ///< 插件路径
	user_audioPath,		///< enum 音频路径 user_dbPath
	user_cachePath,		///< 缓存路径
	user_imgPath,		///< 图片路径
	user_filePath,		///< 文件路径
	user_videoPath,		///< 视频路径
	user_emotionPath,	///< 表情路径
	user_Path,			///< 应用程序根路径
	user_rcPath			///< 应用程序资源路径
};

///设备类型
enum eDeviceType
{
	client_dev_unknown = 0,		///< 未知
	client_dev_pc,				///< PC端
	client_dev_phone,			///< 移动端
	client_dev_html				///< 网页端
};

/**
* \brief 业务类消息号，各个平台的ＡＰＩ层要统一
* [in]  此消息的请求结构体
* [out] 此消息的响应结构体
* \warning (1)只有[out]没有[in]的消息是纯推送消息！！！(2) 实际API中使用的参数都是下面描述的结构体指针。
*/

enum  
{
	/**
	* \brief 一些耗时操作，由SDK下面推送的进度
	* [out] resp_Progress
	*/
	logic_cmd_progress = 0x00, 
	/**
	* \brief 升级提示
	* [out] resp_upgrade
	*/
	logic_cmd_upgrade = 0x01, 
	/**
	*  \brief 登录消息
	* [in]  req_loginParamBean
	* [out] resp_loginResultBean
	*/
	logic_cmd_login = 0x02,
	/**
	* \brief 注销消息
	* [in]  NULL
	* [out] resp_commonResult
	*/
	logic_cmd_logout = 0x03,
	/**
	* \brief 连续错误几次后
	* [in]  req_verfiyimg
	* [out] resp_verifyImg
	*/
	logic_cmd_verifyImg = 0x04,   
	/**
	 * \brief 自动登录
	 * [in]  req_loginParamBean(不需要密码)
	 * [out] resp_loginResultBean
	 */
	logic_cmd_loginAuto = 0x05,
	/**
	 * \brief 获取好友列表
	 * [in]  NULL
	 * [out] resp_buddyList
	 */
	logic_cmd_buddylist = 0x06,
	/**
	 * \brief 离线登录,
	 * [in]  req_offlineLogin
	 * [out] resp_commonResult
	 */
	logic_cmd_offlineLogin = 0x07,
	/**
	 * \brief 获取服务器时间
	 * [in] NULL
	 * [out] resp_commonResult i64 返回毫秒时间
	 */
	logic_cmd_getServerTime = 0x08, 
	/**
	 * \brief 注册第一步
	 * [in]  req_regParam1
	 * [out] resp_regResult1
	 */
	logic_cmd_reg1 = 0x09,
	/**
	 * \brief 注册第二步
	 * [in]  req_regParam２
	 * [out] resp_regResult２
	 */
	logic_cmd_reg2 = 0x0A,
	/**
	 * \brief 重置密码第一步
	 * [in]  req_regParam1
	 * [out] resp_regResult1
	 */
	logic_cmd_resetPw1 = 0x0B,     
	/**
	 * \brief 重置密码第二步
	 * [in]  req_regParam２
	 * [out] resp_regResult２
	 */
	logic_cmd_resetPw2 = 0x0C, 
	/**
	 * \brief 设置自己个人信息
	 * [in]  req_setMySelf
	 * [out] resp_commonResult
	 */
	logic_cmd_setMyself = 0x0D, 
	/**
	 * \brief 获取自己个人信息
	 * [in]  NULL
	 * [out] resp_getMyself
	 */
	logic_cmd_getMyself = 0x0E ,   
	/**
	 * \brief 操作好友, 主动请求操作好友
	 * [in]  req_opUser
	 * [out] resp_commonResult
	 */	
	logic_cmd_opuser = 0x0F, 
	/**
	 * \brief 修改密码
	 * [in]  req_changePw
	 * [out] resp_commonResult
	 */	
	logic_cmd_changePw = 0x10, 
	/**
	 * \brief 获取好友在线状态
	 * [in]  req_getBuddyOnline
	 * [out] resp_getBuddyOnlineResult
	 */	
	logic_cmd_getBuddyOnline = 0x11,
	/**
	 * \brief 更新自己在线状态
	 * [in]  req_updateOnlineState
	 * [out] NULL
	 */	
	logic_cmd_onlineState = 0x12, 
	/**
	 * \brief 发送消息
	 * [in]  req_sendMessage
	 * [out] resp_sendMessage
	 */
	logic_cmd_sendMessage = 0x13,   
	/**
	 * \brief 转发消息，服务器不保留，暂时未用
	 * [in]  req_sendMessage
	 * [out] resp_transferMsg
	 */
	logic_cmd_transferMessage = 0x14, 
	/**
	 * \brief 设置消息已读
	 * [in]  req_setMsgReaded
	 * [out] resp_commonResult
	 */
	logic_cmd_setMsgReaded = 0x15,  
	/**
	 * \brief 得到保存文件路径
	 * [in]  req_getFileInfos
	 * [out] resp_getFileInfos
	 */
	//logic_cmd_getBuddyReqVerifyBox = 0x16, 
	logic_cmd_getFileInfos = 0x16,
	/**
	 * \brief 得到隐藏好友
	 * [in]  req_getHiddenAccountNew
	 * [out] resp_getHiddenAccountNew
	 */
	logic_cmd_getHiddenAccountNew = 0x17,
	//logic_cmd_getBuddyRespVerifyBox = 0x17, 
	/**
	 * \brief 添加好友请求
	 * [in]  req_addBuddyRequest
	 * [out] resp_commonResult
	 */
	logic_cmd_addBuddyRequest = 0x18, 
	/**
	 * \brief 添加好友请求响应
	 * [in]  req_addBuddyResponse
	 * [out] resp_commonResult
	 */
	logic_cmd_addBuddyResponse = 0x19,  
	/**
	 * \brief 好友请求验证框已读
	 * [in]  req_reqVerifyBoxforRead
	 * [out] resp_commonResult
	 */
	logic_cmd_buddyReqVerForead = 0x1A, 
	/**
	 * \brief 根据消息类型获得聊天消息
	 * [in]  req_getMsgByType
	 * [out] resp_getMsgByType
	 */
	logic_cmd_getMsgByType = 0x1B,
	//logic_cmd_buddyRespVerForead = 0x1B, 
	/**
	 * \brief 获取指定用户信息
	 * [in]  req_getUserFromID
	 * [out] resp_getUserFromID
	 */
	logic_cmd_getUser = 0x1C,
	/**
	 * \brief 简单搜索好友
	 * [in]  req_simpleSearch
	 * [out] resp_searchResult
	 */
	logic_cmd_simpleSearch = 0x1D, 
	/**
	 * \brief 最近联系人列表
	 * [in]  NULL
	 * [out] resp_reContactList
	 */
	logic_cmd_reContactList = 0x1E,
	/**
	 * \brief 聊天界面获取聊天历史消息
	 * [in]  req_getHistoryMsg
	 * [out] resp_getHistoryMsg
	 */
	logic_cmd_getHistoryMsg = 0x1F, 
	/**
	 * \brief 获取群列表
	 * [in]  NULL
	 * [out] resp_getGroupList
	 */
	logic_cmd_getGroups = 0x20,  
	/**
	 * \brief 创建群
	 * [in]  req_createGroup
	 * [out] resp_createGroup
	 */
	logic_cmd_createGroup = 0x21,
	/**
	 * \brief 申请加入群
	 * [in]  req_groupVerifyRequest
	 * [out] resp_commonResult
	 */
	logic_cmd_groupVerifyReq = 0x22, 
	/**
	 * \brief 邀请加入群
	 * [in]  req_groupInviteRequest
	 * [out] resp_commonResult
	 */
	logic_cmd_groupInviteReq = 0x23, 
	/**
	 * \brief 推送外部群组信息
	 * [in]  NULL
	 * [out] NULL
	 */
	logic_cmd_PullOutSideGroupInfo = 0x24,
	/**
	 * \brief 发送文件
	 * [in]  req_sendFiles
	 * [out] resp_sendFiles
	 */
	logic_cmd_sendFiles = 0x25,
	/**
	 * \brief 接收文件，
	 * [in]  req_recvFiles
	 * [out] resp_recvFiles
	 */
	logic_cmd_recvFiles = 0x26, 

	/**
	 * \brief 聊天消息 主动推送
	 *
	 * [out] resp_msgBean
	 */
	logic_cmd_msgStore = 0x27, 
	/**
	 * \brief 上下线 主动推送
	 *
	 * [out] resp_Present
	 */
	logic_cmd_present = 0x28,  
	/**
	 * \brief 对方请求添加好友消息 主动推送
	 *
	 * [out] resp_respBuddy
	 */
	logic_cmd_buddyreqVerBox = 0x29, 
	/**
	 * \brief 对方响应添加好友消息 主动推送
	 *
	 * [out] resp_respBuddy
	 */
	logic_cmd_buddyRespVerifybox = 0x2A,	
	/**
	 * \brief 推送消息（复杂应用） 主动推送
	 *
	 * [out] NULL
	 */	
	logic_cmd_pushMessage = 0x2B, 
	/**
	 * \brief 操作好友 主动推送
	 *
	 * [out] resp_operBuddy
	 */	
	logic_cmd_operateBuddy = 0x2C,     
	/**
	 * \brief 修改自己的信息 主动推送
	 *
	 * [out] resp_operUser
	 */	
	logic_cmd_operateUser = 0x2D, 
	/**
	 * \brief 群管理员收到请求，邀请添加群成员等请求 主动推送
	 *
	 * [out] resp_sysMsg
	 */	
	logic_cmd_reqGroup = 0x2E,
	/**
	 * \brief 群请求响应 主动推送
	 *
	 * [out] resp_sysMsg
	 */	
	logic_cmd_respGroup=0x2F,  
	/**
	 * \brief 群管理员收到其他管理员对群的操作通知 主动推送
	 *
	 * [out] resp_sysMsg
	 */	
	logic_cmd_adminRespGroupDone = 0x30,
	/**
	 * \brief 刷新群列表 主动推送
	 *
	 * [out] resp_groupNotify
	 */
	logic_cmd_groupRefresh = 0x31,  
	/**
	 * \brief 转让群 主动推送
	 *
	 * [out] resp_notifyTransGroup
	 */
	logic_cmd_transferGroup = 0x32,   
	/**
	 * \brief 刷新群成员资料 主动推送
	 *
	 * [out] resp_groupMemberInfoRefresh
	 */
	logic_cmd_groupMemberInfoRefresh = 0x33,
	/**
	 * \brief 刷新群成员列表 主动推送
	 *
	 * [out] resp_groupMembersRefresh
	 */
	logic_cmd_groupMembersRefresh = 0x34, 
	/**
	 * \brief 企业注册消息 主动推送
	 *
	 * [out] resp_enterpriseRegisterMessage
	 */
	logic_cmd_enterpriseRegisterMessage = 0x35,
	/**
	 * \brief 暂时未用 主动推送
	 *
	 * [out] NULL
	 */
	logic_cmd_reqResource = 0x36,
	/**
	 * \brief 错误信息，服务器检测 主动推送
	 *
	 * [out] NULL
	 */
	logic_cmd_error = 0x37, 
	/**
	 * \brief 未读消息列表，登录后ＳＤＫ会主动推送到界面 主动推送
	 *
	 * [out] resp_msgList
	 */
	logic_cmd_unReadmsgList = 0x38,
	/**
	 * \brief 设备消息，登录后ＳＤＫ会主动推送到界面 主动推送
	 *
	 * [out] resp_msgList
	 */
	logic_cmd_devicemsgList = 0x39, 
	/**
	 * \brief 获取好友详细信息
	 * [in]  req_getBuddyInfo
	 * [out] resp_getBuddyInfo
	 */
	logic_cmd_getBuddyInfo = 0x3A,
	/**
	 * \brief 更新头像, SDK下载完毕 ,推送到上层.
	 *
	 * [out] resp_updateHeadImg
	 */
	logic_cmd_updateHeadImg = 0x3B,
	/**
	* \brief 设置自己的头像
	* [in]  req_setHeadImg
	* [out] resp_setHeadImg
	*/
	logic_cmd_setHeadImg = 0x3C, 
	/**
	* \brief 获取好友验证方式
	* [in]  req_getBuddyVerifyType
	* [out] resp_getBuddyVerifyType
	*/
	logic_cmd_getBuddyVerifyType = 0x3D,
	/**
	* \brief 解散/退群
	* [in]  req_groupDelete
	* [out] resp_commonResult
	*/
	logic_cmd_groupDelete = 0x3E,
	/**
	* \brief 转让群
	* [in]  req_groupTrans
	* [out] resp_commonResult
	*/
	logic_cmd_groupTrans = 0x3F,
	/**
	* \brief 设置群资料
	* [in]  req_groupInfoUpdate
	* [out] resp_commonResult
	*/
	logic_cmd_groupUpdateInfo = 0x40,
	/**
	* \brief 获取群成员列表
	* [in]  req_groupCommonData
	* [out] resp_getGroupMemList
	*/
	logic_cmd_getGroupMemList = 0x41,
	/**
	* \brief 删除群成员
	* [in]  req_removeGroupMember
	* [out] resp_commonResult
	*/
	logic_cmd_removeGroupMember = 0x42,
	/**
	* \brief 获取群详细信息
	* [in]  req_groupCommonData
	* [out] resp_getGroupInfo
	*/
	logic_cmd_getGroupInfo = 0x43,
	/**
	* \brief 获取群验证方式
	* [in]  req_groupCommonData
	* [out] resp_getGroupSet
	*/
	logic_cmd_getGroupSet = 0x44, 
	/**
	* \brief 获取群成员详细信息
	* [in]  req_getMemberInfo
	* [out] resp_getGroupMemberInfo
	*/
	logic_cmd_getGroupMemberInfo = 0x45,
	/**
	* \brief 设置群成员详细信息
	* [in]  req_setGroupMemberInfo
	* [out] resp_commonResult
	*/
	logic_cmd_setGroupMemberInfo = 0x46,
	/**
	* \brief 设置群消息提示方式
	* [in]  req_setGroupShieldInfo
	* [out] resp_commonResult
	*/
	logic_cmd_setShieldGroupMessage = 0x47,
	/**
	* \brief 获取网址缩略图。
	* [in]  req_getUrlInfo
	* [out] resp_getUrlInfo
	*/
	logic_cmd_getUrlInfo = 0x48,
	/**
	* \brief 近距离加好友、群
	* [in]  req_faceToFaceJoin
	* [out] resp_faceToFaceJoin
	*/
	logic_cmd_faceToFaceJoin = 0x49, 
	/**
	* \brief 发送图片
	* [in]  req_sendImg
	* [out] resp_sendImg
	*/
	logic_cmd_sendImg = 0x4A,
	/**
	* \brief 接收图片
	* [in]  req_recvImg
	* [out] resp_recvImg
	*/
	logic_cmd_recvImg = 0x4B, 
	/**
	* \brief 设置群验证方式
	* [in]  req_setGroupSet
	* [out] resp_commonResult
	*/
	logic_cmd_setGroupSet = 0x4C,
	/**
	* \brief 最后未读一条系统消息(好友验证，响应，群申请等消息)
	* [in]  NULL
	* [out] resp_SysMsg
	*/
	logic_cmd_lastSysMsg = 0x4D, 
	/**
	* \brief 获取系统消息列表
	* [in]  req_getSysMsgList
	* [out] resp_getSysMsgList
	*/
	logic_cmd_getSysMsgList = 0x4E, 
	/**
	* \brief 设置系统消息已读
	* [in]  req_setSysMsgReaded
	* [out] resp_commonResult
	*/
	logic_cmd_setSysMsgReaded = 0x4F, 

	 /**
	 * \brief 推送接收
	 * [in]  req_setIosNoticeInfo
	 * [out] resp_commonResult
	 */
	logic_cmd_setUpiosRecvNotice = 0x50,
	/**
	* \brief 设置TOKEN
	* [in]  req_setTokenAndOlState
	* [out] resp_commonResult
	*/
	logic_cmd_setTokenAndOlState = 0x51,
	/**
	* \brief 1:ios 端切换到后台调用，2:ios 端切换到前台调用
	* [in]  req_setOLtype
	* [out] resp_commonResult
	*/
	logic_cmd_setOLtype = 0x52,
	/**
	* \brief 获取IOS推送设置
	* [in]  NULL
	* [out] resp_getIosNoticeInfo
	*/
	logic_cmd_getIosRecvNoticeSettings = 0x53, 
	/**
	* \brief 获取文件列表
	* [in]  req_getFileList
	* [out] resp_getFileList
	*/
	logic_cmd_getFileList = 0x54,
	/**
	* \brief 删除文件
	* [in]  req_delGroupFiles
	* [out] resp_commonResult
	*/
	logic_cmd_delGroupFiles = 0x55,
	/**
	* \brief 申请加入群响应
	* [in]  req_groupVerifyRespons
	* [out] resp_commonResult
	*/
	logic_cmd_groupVerifyResp = 0x56,
	/**
	* \brief 获取服务器密码规则
	* [in]  _sdkcmd_base
	* [out] resp_pwRuleResult
	*/
	logic_cmd_getPwRule = 0x57,
	/**
	* \brief 获取群消息提示方式
	* [in]  req_getGroupShieldInfo
	* [out] resp_getGroupShieldInfo
	*/
	logic_cmd_getShieldGroupMessage = 0x58,
	/**
	* \brief 获取clientKey , key在value_str里
	* [in]  NULL
	* [out] resp_commonResult
	*/
	logic_cmd_getClientKey = 0x59,
	/**
	* \brief 性能报告消息
	* [in]  NULL
	* [out] resp_perf
	*/
	logic_cmd_perf = 0x5A,

	///安卓专用 安卓事件通知
	logic_cmd_wakeUp = 0x5B,

	/**
	* \brief 发送九宫格图片
	* [in]  req_sendNineBoxImg
	* [out] resp_sendNineBoxImg
	*/
	logic_cmd_sendNineBoxImg = 0x5C,
	/**
	* \brief 接收九宫格图片
	* [in]  req_recvNineBoxImg
	* [out] resp_recvNineBoxImg
	*/
	logic_cmd_recvNineBoxImg = 0x5D,
	/**
	* \brief 设置全局勿扰模式开关信息
	* [in]  req_setNoDisturbMode
	* [out] resp_commonResult
	*/
	logic_cmd_setNoDisturbMode = 0x5E,
	/**
	* \brief 获取全局勿扰模式开关信息
	* [in]  _sdkcmd_base
	* [out] resp_getNoDisturbMode
	*/
	logic_cmd_getNoDisturbMode = 0x5F,
	/**
	* \brief 设置个人对目标用户的勿扰模式
	* [in]   req_setUserToTargetSwitch
	* [out]  resp_commonResult
	*/
	logic_cmd_setUserToTargetSwitch = 0x60,
	/**
	* \brief 获取个人对目标用户的勿扰模式
	* [in]  req_getUserToTargetSwitch
	* [out] resp_getUserToTargetSwitch
	*/
	logic_cmd_getUserToTargetSwitch = 0x61,
	/**
	* \brief 根据账号名获取ID
	* [in]  req_getIdByAccount
	* [out] resp_getIdByAccount
	*/
	logic_cmd_getIdByAccount = 0x62,
	/**
	* \brief
	* [in]  req_queryMarketApplication
	* [out] resp_queryMarketApplication
	*/
	 logic_cmd_queryMarketApplication = 0x63,
	/**
	* \brief 添加或删除应用
	* [in]  req_addOrDeleteApplication
	* [out] resp_commonResult
	*/
	 logic_cmd_addOrDeleteApplication = 0x64,
	/**
	* \brief 获取用户已安装列表信息
	* [in]  req_getInstalledApplication
	* [out] resp_getInstalledApplication
	*/
	 logic_cmd_getInstalledApplication = 0x65,
	/**
	* \brief 设置私信密码
	* [in]  req_setPrivateMsgPwd
	* [out] resp_commonResult
	*/
	logic_cmd_setPrivateMsgPwd = 0x66,
	/**
	* \brief 根据条件查询企业用户列表
	* [in]  req_queryEnterpriseUserlist
	* [out] resp_queryEnterpriseUserlist
	*/
	// logic_cmd_queryEnterpriseUserlist = 0x67,

	/**
	* \brief 删除最近联系人
	* [in]  req_delReContact
	* [out] resp_commonResult
	*/
	logic_cmd_delReContact = 0x68,
	/**
	* \brief 取消已经提交的请求，耗时的操作比较有用，不耗时的操作取消基本都会失败。
	* [in]  req_cancleExec
	* [out] resp_commonResult
	*/
	logic_cmd_cancleExec = 0x69,

	/**
	 *　\brief 发送错误日志
	 *　[in]   req_sendErrLog
	 *　[out]  resp_commonResult
	 */
	logic_cmd_sendErrLog = 0x6A,

	/**
	 *　\brief 获取应用信息
	 *　[in]   req_getAppinfo
	 *　[out]  resp_getAppInfo
	 */
	logic_cmd_getAppInfo = 0x6B,

	/**
	 * \brief　本地与用户相关的配置存储，只有登录后才能使用。
	 * [in] req_localSetting
	 * [out] resp_localSetting
	 */
	logic_cmd_localSetting = 0x6C,

	/**
	 * \brief 网络通知,纯推送
	 * [out] resp_netNotifyer
	 */
	logic_cmd_netNotifyer = 0x6D,

	/**
	 * \brief 获取安全中心页面
	 * [in] req_LoginParamBean ,
	 *      １：　如果没有登录，需要填写该结构体。
	 *      ２：　如果登录后，不用填写该结构体。
	 * [out] resp_commonResult 返回值存在 value_str
	 */
	logic_cmd_getSecUrl = 0x6E,
	
	/**
	 * \brief 　SDK数据库更新推送，升级期间，所有消息不提供服务. 发送请求会收到err_sdk_dbUpdate错误码
	 * [out] resp_commonResult  value_byte = 0 开始，value_byte = １ 成功结束 value_byte = 2 升级失败，
	 * 其它的值失败结束，错误值查看errorExport.h
	 */
	logic_cmd_dbUpdateNotifyer = 0x6F,
	
	/**
	 * \brief 查询组织机构的用户
	 * [in] req_qEnUS
	 * [out] resp_qEnUS
	 */
	// logic_cmd_qEnUS = 0x70,

	/**
	 * \brief 设置隐藏
	 * [in] req_setHiddenAccountNew
	 * [out] resp_HiddenPWDResult
	 */
	logic_cmd_setHiddenAccountNew = 0x71,

	/**
	 * \brief 删除隐藏
	 * [in]  req_setHiddenAccountNew
	 * [out] resp_HiddenPWDResult
	 */
	logic_cmd_deleteHiddenAccountNew = 0x72,

	/**
	 * \brief 找回隐藏密码
	 * [in] req_verifyHiddenInfo
	 * [out] resp_HiddenPWDResult
	 */
	logic_cmd_verifyHiddenInfo = 0x73,

	/**
	 * \brief 重置隐藏密码
	 * [in] req_resetHiddenPWD
	 * [out] resp_commonResult
	 */
	logic_cmd_resetHiddenPWD = 0x74,

	/**
	 * \brief 迁移外部聊天数据库 PC专用
	 * [in] req_transferOuterMsgDb
	 * [out] resp_commonResult
	 */
	logic_cmd_transferOuterMsgDb = 0x75,

	 /**
	 * \brief 外部文件下载命令
	 * [in] req_downloadFile
	 * [out] resp_commonResult
	 */
	logic_cmd_downloadFile = 0x76,

	 /**
	  * \brief 设置用户自身配置
	  * 生日，电话，邮件，好友，Ｖ标，提醒模式，全局消息通知模式
	  * [in]  req_PersonalData
	  * [out] resp_commonResult , value_i16 放置设置成功的条数
	  */
	logic_cmd_setPersonalData = 0x77,

	 /**
	  * \brief 获取用户自身配置
	  * 生日，电话，邮件，好友，Ｖ标，提醒模式，全局消息通知模式
	  * [in]  req_PersonalData
	  *       需要获取那些类型的数据，把类型添加进列表,要获取全部的话，列表可置为空。
	  * [out] resp_PersonalData
	  */
	logic_cmd_getPersonalData = 0x78,

	/**
	* \brief 本地消息全局搜索，只返回每个匹配到的群或个人的消息的数目。
	* [in] req_msgGlobalSearch
	* [out] resp_msgGlobalSearch
	*/
	logic_cmd_msgGlobalSearch = 0x79,

	/**
	* \brief 在某个群或个人的聊天记录中搜索关键字。
	* [in] req_msgDetailSearch
	* [out] resp_msgDetailSearch
	*/
	logic_cmd_msgDetailSearch = 0x7A,
	   
	 /**
      * \brief 通知界面更新完成
      * [out] resp_commonResult
      */
     logic_cmd_updatafinish = 0x7B,

	/**
	* \brief 添加用户到黑名单或白名单
	* [in] req_addToBWlist
	* [out] resp_commonResult
	*/
	logic_cmd_addToBWlist = 0x7C,
	 
	/**
	* \brief 把用户从黑名单或白名单中移除
	* [in] req_removeFromBWlist
	* [out] resp_commonResult
	*/
	logic_cmd_removeFromBWlist = 0x7D,

	/**
	* \brief 获取黑名单或白名单列表
	* [in] req_getBWlist
	* [out] resp_getBWlist
	*/
	logic_cmd_getBWlist = 0x7E,
	  
	/**
     * \brief 获取指定消息
     * [in] req_getAppointMsg
     * [out] resp_getAppointMsg
     */
    logic_cmd_getAppointMsg = 0x7F,

	/**
	* \brief 删除消息
	* [in]  req_delMsg
	* [out] resp_commonResult
	*/
	logic_cmd_delMessage = 0x80,

	/**
	* \brief 聊天置顶
	* [in]  req_chatTop
	* [out] resp_commonResult
	*/
	logic_cmd_chatTop = 0x81,

   /**
	* \brief 特定用户信息设置(是否显示在线，设置用户被查找方式(豆豆号，手机号等),新消息提醒方式等)
	* [in]  req_setUserSetting
	* [out] resp_commonResult
	*/
	logic_cmd_setUserSetting = 0x82,

	/**
	 * \brief 得到特定用户信息设置(是否显示在线，设置用户被查找方式(豆豆号，手机号等),新消息提醒方式等)
	 * 返回值为 resp_commonResult的value_i64字段。
	 * [in]  req_getUserSetting
	 * [out] resp_commonResult
	 */
	logic_cmd_getUserSetting = 0x83,

	/**
	 * \brief 外部聊天消息导入 
	 * [in]  req_msgImport
	 * [out] resp_commonResult
	 */
	logic_cmd_msgImport = 0x84,

	/**
	 * \brief 进入群房间推送 
	 * [out] resp_faceJoinGroup
	 */
	logic_cmd_faceJoinGroup = 0x85,
	/**
	 * \brief 退出群房间推送
	 * [out] resp_exitFaceJoinGroup
	 */
	logic_cmd_exitFaceJoinGroup = 0x86,
	/**
	 * \brief 创建群成功后的推送
	 * [out] resp_createFaceGroupSuccess
	 */
	logic_cmd_createFaceGroupSuccess = 0x87,
	/**
	 * \brief 进入好友房间推送
	 * [out] resp_faceJoinGroup
	 */
	logic_cmd_faceAddBuddy = 0x88,
	/**
	 * \brief 退出好友房间推送
	 * [out] resp_exitFaceJoinGroup
	 */
	logic_cmd_exitFaceAddBuddy = 0x89,
	
	/**
	 * \brief 批量加好友成功后的推送
	 * [out] resp_createFaceGroupSuccess
	 */
	logic_cmd_faceAddBuddyConfirm = 0x8A,

	/**
	 * \brief 删除延迟消息
	 * [in] req_delDelayMsg
	 * [out] resp_commonResult
	 */
	logic_cmd_delDelayMsg = 0x8B,

	/**
	 * \brief 修改延迟消息
	 * [in] req_updateDelayMsg
	 * [out] resp_commonResult
	 */
	logic_cmd_updateDelayMsg = 0x8C,

	/**
	* \brief 绑定手机号第一步
	* [in]  req_authenticationParam
	* [out] resp_authenticationResult
	*/
	logic_cmd_bindEmailOrPhoneNumber1 = 0x8D,
	/**
	* \brief 绑定手机号第2步
	* [in]  req_authenticationServerCode
	* [out] resp_commonResult
	*/
	logic_cmd_bindEmailOrPhoneNumber2 = 0x8E,
	/**
	* \brief 绑定手机号第3步 或者为绑定邮箱（共1步）
	* [in]  req_MultiOpSTParam
	* [out] resp_commonResult
	*/
	logic_cmd_bindEmailOrPhoneNumber3 = 0x8F,

	/**
	* \brief 上传通讯录
	* [in]  req_postContact
	* [out] resp_postContactResult
	*/
	logic_cmd_postContact = 0x90,
	/**
	* \brief 前端用户设置分享列表
	* [in]  req_shareOption
	* [out] resp_commonResult
	*/
	logic_cmd_updateShareOption = 0x91,
	/**
	* \brief 前端用户得到分享列表
	* [in]  req_sharedType
	* [out] resp_commonListResult
	*/
	logic_cmd_getShareOption = 0x92,
	/**
	* \brief 用户自定义一些信息， 目前只表示声音
	* [in]  req_personDefinitionParam
	* [out] req_personDefinitionParam
	*/
	logic_cmd_setPersonDefinition = 0x93,
	/**
	* \brief 得到用户自定义一些信息
	* [in]  req_getPersonDef
	* [out] resp_getPersonDefinitionResult
	*/
	logic_cmd_getPersonDefinition = 0x94,
	/**
	* \brief 根据条件查询拓展字段信息
	* [in]  req_queryExtendedField
	* [out] resp_queryExtendedField
	*/
	logic_cmd_queryExtendedField = 0x95,
	/**
	* \brief 设置群成员背景图片
	* [in]  req_setUserGroupImage
	* [out] resp_commonResult  内容在value_str里面
	*/
	logic_cmd_setUserGroupImage = 0x96,
	/**
	* \brief 获取群成员背景图片
	* [in]  req_getUserGroupImage
	* [out] resp_commonResult  
	*/
	logic_cmd_getUserGroupImage = 0x97,

	/**
	* \brief 背景修改推送
	* [out] resp_bkImgUpdate
	*/
	logic_cmd_bkImgUpdate = 0x98,
	
	/**
	* \brief 单个表情查询、根据表情包标识查询表情，查询所有用户自定义表情
	* [in]  req_queryEmoticon
	* [out] resp_queryEmoticon
	*/
	logic_cmd_queryEmoticon = 0x99,
	/**
	* \brief 单个查询表情包
	* [in]  req_singleQueryEmoticonPackage
	* [out] resp_singleQueryEmoticonPackage
	*/
	logic_cmd_singleQueryEmoticonPackage = 0x9A,
	/**
	* \brief 分页查询表情包
	* [in]  req_pageQueryEmoticon
	* [out] resp_pageQueryEmoticon
	*/
	logic_cmd_pageQueryEmoticon = 0x9B,
	/**
	* \brief 增加或删除用户自定义表情
	* [in]  req_addOrDeleteCustomEmoticon
	* [out] resp_addOrDeleteCustomEmoticon
	*/
	logic_cmd_addOrDeleteCustomEmoticon = 0x9C,
	/**
	* \brief 删除系统消息
	* [in]  req_deleteSysMsgList
	* [out] resp_commonResult
	*/
	logic_cmd_deleteSysMsgList = 0x9D,
	
	/**
	 * \brief 获取局域网可以P2P通讯的用户
	 * [in] NULL
	 * [out] resp_getP2pUser
	 */
	logic_cmd_getP2pUsers=0x9E,

	/**
	 * \brief 局域网用户状态修改推送
	 * [out] resp_P2pUserStatusChg
	 */
	logic_cmd_P2pUserStatusChg=0x9F,

	/**
	 * \brief 局域网用户传输文件请求。
	 * [out] resp_P2pSendFileReq
	 */
	logic_cmd_p2pSendFilereq=0xA0,

	/**
	 * \brief 局域网用户传输文件操作
	 * [out] resp_P2pFileTransOp
	 */
	logic_cmd_p2pFileTransOps=0xA1,

	/**
	* \brief 更新解密后的消息到数据库
	* [in]  req_updateDecryptedMsg
	* [out] resp_commonResult
	*/
	logic_cmd_updateDecryptedMsg=0xA2,

	/**
	 * \brief 快速注册
	 * [in] req_quickRegister
	 * [out] resp_commonResult
	 */
	logic_cmd_quickRegister=0xA3,
	/**
	* \brief 得到最后一条未读系统消息河数量
	* [in] NULL
	* [out] resp_unReadSysMsg
	*/
	logic_cmd_lastUnReadSysMsg=0xA4,

	/**
	 * \brief 发送消息(消息类型可以是附件类型)
	 * [in]  req_sendMessage
	 * [out] resp_transferMsg
	 */
	logic_cmd_sendMessageExt=0xA5,

	/**
	* \brief 解密消息并更新到数据库
	* [in]  req_decryptMsg
	* [out] resp_getHistoryMsg
	*/
	logic_cmd_decryptMsg=0xA6,
	/**
	* \brief 单个查询表情包
	* [in]  req_labelQueryEmoticonPackage
	* [out] resp_labelQueryEmoticonPackage
	*/
	logic_cmd_labelQueryEmoticonPackage = 0xA7,
	/**
	* \brief 取消正在进行的传输或拒绝尚未开始的p2p传输
	* [in]  req_p2pTransferCancle
	*/
    logic_cmd_p2pFileTransCancle = 0xA8,
	/**
	*\brief 导入导出本地数据
	*[in] req_transferLocalData
	*[out] resp_commonresult
	*/
	logic_cmd_transferLocalData = 0xA9,

	/**
	* \brief 设置未读数量（IOS 专用接口）
	* [in]  req_setUnReadCount
	* [out] resp_setUnReadCount
	*/
	logic_cmd_setUnReadCount = 0xAA,

	/**
	* \brief 设置最后一条已读为未读（android)
	* [in]  req_setMsgUnRead
	* [out] resp_setMsgUnRead
	*/
	logic_cmd_setMsgUnRead = 0xAB,

	/**
	 * \brief  服务器推送错误 主动推送,下面会自动重联
	 *
	 * [out] NULL
	 */
	logic_cmd_NotifyError = 0xAC, 

	/**
	* \brief 上传消息计数
	*[in] req_cmd_upMsgCount
	*[out] resp_commonresult
	*/
	logic_cmd_upMsgCount = 0xAD,

	/**
	* \brief 消息游标推送
	*[in] NULL
	*[out] resp_MessageCursor
	*/
	logic_cmd_MessageCursor = 0xAE,

	/**
	* \brief 一步发送文件接口
	*[in] req_fileMessage
	*[out] resp_commonResult
	*/
	logic_cmd_fileMessage = 0xAF,

	/**
	* \brief 一步发送图片接口
	*[in] req_imgMessage
	*[out] resp_commonResult
	*/
	logic_cmd_imgMessage = 0xB0,
	/**
	* \brief 查询单个表情
	*[in] req_querySingleEmoticon
	*[out] resp_querySingleEmoticon
	*/
	logic_cmd_querySingleEmoticon = 0xB1,
	/**
	* \brief  查询机器人（公众号）时间戳，查询数据字典时间戳
	*[in] req_queryAppOrDictTimestamp
	*[out] resp_queryAppOrDictTimestamp
	*/
	logic_cmd_queryAppOrDictTimestamp = 0xB2,
	
	/**
	* \brief 检查URL的是否有效
	*[in] req_checkUrlValid
	*[out] resp_commonResult
	*/
	logic_cmd_checkUrlValid = 0xB3,

	/**
	* \brief 转发消息
	*[in] req_forwardMessage
	*[out] resp_sendMessage
	*/
	logic_cmd_forwardMessage = 0xB4,
	/**
	* \brief 增加最近联系人
	*[in] req_addRecontact
	*[out] resp_commonResult
	*/
	logic_cmd_addRecontact = 0xB5,
	/**
	* \brief 获取OAUTH登陆授权码
	*[in] req_getLoginAuthCode
	*[out] resp_commonResult
	*/
	logic_cmd_getLoginAuthCode = 0xB6,

	/**
	* \brief 获取对象聊天时间数组
	*[in] req_getMsgDays
	*[out] resp_getMsgDays
	*/
	logic_cmd_getMsgDays = 0xB7,

	/**
	* \brief 根据日期获取消息
	*[in] req_getMsgsFromDay
	*[out] resp_getMsgsFromDay
	*/
	logic_cmd_getMsgFromDay = 0xB8,

	logic_cmd_getInstallDays = 0xB9,

	logic_cmd_getAllMsgCount = 0xba,
	
	/**
	* \brief 获取打洞服务地址
	*[in] NULL
	*[out] resp_stunServerInfo
	*/
    logic_cmd_getStunServer = 0xBB,

	/**
	* \brief 获取声网服务功能
	*[int] req_agoraFunc
	*[out] resp_agoraFunc
	*/
	logic_cmd_getAgoraFunc = 0xBC,
	logic_cmd_transferMsg = 0xBD,
	/**
	* \brief 根据用户id分页获取企业号
	* [in]  req_getEntAppInfo
	* [out] resp_getEntAppInfo
	*/
	logic_cmd_getEntAppInfo = 0xBE,
	/**
	*  \brief 离线转在线登录消息
	* [in]  req_loginParamBean
	* [out] resp_loginResultBean
	*/
	logic_cmd_offLineToLogin = 0xBF,
	/**
	* \brief 根据用户ID向用户发送短信
	* [in] req_qVerifyCodes
	* [out] resp_qVerifyCodes
	*/
	logic_cmd_qVerifyCodes = 0xC0,
	/**
	* \brief 统计消息（未读，已读，未推送的userID列表)
	* [in] req_qMsgStores
	* [out] resp_qMsgStores
	*/
	logic_cmd_qMsgStores = 0xC1,
	/**
	* [in]  req_getAuthAccessToken
	* [out] resp_commonResult
	*/
	logic_cmd_getAuthAccessToken = 0xC2,
	/**
	* [in]  req_getAuthAccessToken
	* [out] resp_commonResult
	*/
	logic_cmd_checkOrRefreshAccessToken = 0xC3,
	/**
	* [in]  req_getAuthUserBean
	* [out] resp_getAuthUserBean
	*/
	logic_cmd_getAuthUserBean = 0xC4,
	/**
	* [in] req_cloudDiskFunc
	* [out] resp_commonResult
	*/
	logic_cmd_cloudDiskFunc = 0xC5,

	/**
	* [in] req_circleOfFriend
	* [out] resp_commonResult
	*/
	logic_cmd_circleOfFriend = 0xC6,
	/**
	* [in] req_webSiteAuth
	* [out] resp_commonResult
	*/
	logic_cmd_webSiteAuth = 0xC7,
	/**
	* [in] req_upload2Cloud
	* [out] resp_commonResult
	*/
	logic_cmd_upload2Cloud = 0xC8,
	/**
	* [in] req_accountQueryUserID
	* [out] resp_accountQueryUserID
	*/
	logic_cmd_accountQueryUserID = 0xC9,
	/**
	* [out] resp_notifyJsonMessageBean
	*/
	logic_cmd_jsonMessageBean = 0xCA,
	/**
	* [in] req_getMarketAppSort
	* [out] resp_getMarketAppSort
	*/
	logic_cmd_getMarketAppSort = 0xCB,
	/**
	* [in] req_getGroupAtMsg
	* [out] resp_getHistoryMsg
	*/
	logic_cmd_getGroupAtMsg = 0xCC,
	/**
	* [in] _sdkcmd_base
	* [out] resp_commonResult
	*/
	logic_cmd_setMsgReadeds = 0xCD,
	/**
	* [in] req_operOnlineExt
	* [out] resp_commonResult
	*/
	logic_cmd_setOrDelOnlineExt = 0xCE,
	/**
	* [in]  _sdkcmd_base
	* [out] resp_queryOnlineExt
	*/
	logic_cmd_queryOnlineExt = 0xCF,
	
	/**
	* [in]  req_insertMessage
	* [out] resp_commonResult
	*/
	logic_cmd_insertMessage = 0xD0,
	
	/**
	* \brief 根据客户端使用场景获取相应用户资料
	* [in]  req_getUserByScene
	* [out] resp_getUserFromID
	*/
	logic_cmd_getUserByScene = 0xD1,
    /**
    * [in] req_queryJson
    * [out] resp_commonResult
    */
    logic_cmd_queryJson = 0xD2,

    /**
    * [in] _sdkcmd_base
    * [out] resp_appNodeServer
    */
    logic_cmd_getAppNodes = 0xD3,
	/**
	* [in] req_feedBack
	* [out] resp_commonResult
	*/
	logic_cmd_feedBack = 0xD4,
    /**
    * [in] req_getWBBanners
    * [out] resp_getWBBanners
    */
    logic_cmd_getWBBanners = 0xD5,
    /**
    * [in] req_helpSystem
    * [out] resp_helpSystem
    */
    logic_cmd_helpSystem = 0xD6,
    /**
    * [in] req_groupOnlineStatus
    * [out] resp_groupOnlineStatus
    */
    logic_cmd_groupOnlineStatus = 0xD7,
	/**
	* [in] req_delayFiles
	* [out] resp_delayFiles
	*/
	logic_cmd_delayFiles = 0xD8,
	/**
    * [in] req_userContact
    * [out] _sdkrespcmd_base
    */
    logic_cmd_updateExtendInfo = 0xD9,
    /**
    * \brief 获取好友在线状态
    * [in]  req_regBuddyOnline
    * [out] resp_regBuddyOnlineResult
    */
    logic_cmd_regBuddyOnline = 0xDA,
	/**
	* [in] req_queryUserIsExistList
	* [out] resp_queryUserIsExistList
	*/
	logic_cmd_queryUserIsExistList = 0xDB,
	/**
	* [in] req_OauthParam
	* [out] resp_OauthResult
	*/
	logic_cmd_oAuth = 0xDC,
	/**
	* \brief 敏感词推送
	*[in] NULL
	*[out] resp_commonResult
	*/
	logic_cmd_BadWordUpdate = 0xDD,
	/**
	* [in] req_groupSearchMember
	* [out] resp_groupSearchMember
	*/
	logic_cmd_groupSearchMember = 0xDE,
	/**
	* [in] req_setGroupFileTermParam
	* [out] resp_commonResult
	*/
	logic_cmd_setGroupFileTerm = 0xDF,
	/**
	*  \brief 预登陆
	* [in]  req_loginParamBean
	* [out] resp_loginResultBean
	*/
	logic_cmd_prelogin = 0xE0,
	/**
	*  \brief 断线重连
	* [in]  req_loginParamBean
	* [out] resp_loginResultBean
	*/
	logic_cmd_reconnect = 0xE1,
	/**
	*  \brief 扫码登录后台
	* [in]  req_scanCodeLogin
	* [out] resp_commonResult
	*/
	logic_cmd_scanCodeLogin = 0xE2,
	/**
	*  \brief 工作台创建应用房间
	* [in]  req_createAppRoom
	* [out] resp_commonResult
	*/
	logic_cmd_createAppRoom = 0xE3,
	/**
	*  \brief 工作台更新房间信息
	* [in]	req_updateAppRoomInfo
	* [out] resp_commonResult
	*/
	logic_cmd_updateAppRoomInfo = 0xE4,
	/**
	*  \brief 工作台更新房间成员
	* [in] req_updateAppRoomMem
	* [out] resp_commonResult
	*/
	logic_cmd_updateAppRoomMem = 0xE5,
	/**
	*  \brief 设置工作台应用顺序信息
	* [in] req_setAppOrder
	* [out] resp_commonResult
	*/
	logic_cmd_setAppOrder = 0xE6,
	/**
	* \brief 获取用户已安装列表信息排序的
	* [in]  req_getInstalledApplication
	* [out] resp_getInstalledApplicationSorted
	*/
	logic_cmd_getInstalledApplicationSorted = 0xE7,
	/**
	* \brief 获取群议题
	* [in]  req_getIssue
	* [out] resp_getInstalledApplicationSorted
	*/
	logic_cmd_getIssuebyId = 0xE8,
	/**
	* \brief 获取用户已安装列表信息排序的
	* [in]  req_searchIssue
	* [out] resp_getInstalledApplicationSorted
	*/
	logic_cmd_searchIssue = 0xE9,
	/**
	* \brief 获取用户已安装列表信息排序的
	* [in]  req_getIssueMsg
	* [out] resp_getInstalledApplicationSorted
	*/
	logic_cmd_getIssueMsg = 0xEA,
	/**
	* \brief 数据迁移功能
	* [in]  req_migrateUserData
	* [out] resp_commonResult
	*/
	logic_cmd_migrateUserData = 0xEB,
	/**
	* \brief 群公告功能
	* [in]  req_groupAnnouncementParam
	* [out] resp_groupAnnouncementResult
	*/
	logic_cmd_qGroupS = 0xEC,
	/**
	* \brief 设置群公告消息已读到数据库
	* [in]  req_updateDecryptedMsg
	* [out] resp_commonResult
	*/
	logic_cmd_setGroupAnnReaded= 0xED,
	/**
	*  \brief 工作台添加本地应用
	* [in]  req_addLocalApp
	* [out] resp_commonResult
	*/
	logic_cmd_addLocalApp = 0xEE,
	/**
	*  \brief 删除本地应用
	* [in]	req_delLocalApp
	* [out] resp_commonResult
	*/
	logic_cmd_delLocalApp = 0xEF,
	/**
	*  \brief 获取本地应用列表
	* [in] _sdkcmd_base
	* [out] resp_getLocalAppListResult
	*/
	logic_cmd_getLocalAppList = 0xF0,
	/**
	*  \brief 登录前操作
	* [in] req_beforeLogin
	* [out] resp_beforeLogin
	*/
	logic_cmd_beforeLogin = 0xF1,

	/**
	*  \brief 强制pc推出
	* [in] req_offline
	* [out] resp_commonResult
	*/
    logic_cmd_kickoff = 0xF2,

	/**
	* \brief 统计消息（未读，已读，未推送的userID列表)
	* [in] req_qMsgStores
	* [out] resp_qMsgStores
	*/
	logic_cmd_getContactRead = 0xF3,

	/**
	* \brief 获取好友在线状态
	* [in]  req_getBuddyOnline
	* [out] resp_getBuddyOnlineResult
	*/
	logic_cmd_getDeviceOnline = 0xF4,

	/**
	* \brief 透传消息 主动推送
	*
	* [out] resp_msgBean
	*/
	logic_cmd_notifyTransferMessage = 0xF5,

	/**
	* \brief 设置群聊天提示音信息
	* [in]  req_setUserGroupImage
	* [out] resp_commonResult  内容在value_str里面
	*/
	logic_cmd_setGroupBeepTone = 0xF6,

	/**
	* \brief 获取群聊天提示音信息
	* [in]  req_getUserGroupImage
	* [out] resp_commonResult
	*/
	logic_cmd_getGroupBeepTone = 0xF7,


	/**
	* \brief 验证登录后用户信息字段是否正确
	* [in]  req_verifyUserInfoField
	* [out] resp_commonResult
	*/
	logic_cmd_verifyUserInfoField = 0xF8,
	/**
	* \brief 根据timeTask获取任务消息
	* [in]  req_getTaskMsg
	* [out] resp_getHistoryMsg
	*/
	logic_cmd_getTaskMsg = 0xF9,

	/**
	* \brief 分页获取群置顶消息
	* [in]  req_getGroupTopMsgByPage
	* [out] resp_getHistoryMsg
	*/
	logic_cmd_getGroupTopMsgByPage = 0xFA,
		/**
	* \brief 登录设备管理
	* [in]  req_loginDeviceManage
	* [out] resp_loginDeviceManage
	*/
	logic_cmd_loginDeviceManage = 0xFB,
	/**
	* \brief 删除本地议题
	* [in]  req_deleteIssue
	* [out] resp_commonResult
	*/
	logic_cmd_deleteIssue = 0xFC,
	/**
	* \brief 创建消息提醒
	* [in]  req_reminderMsg
	* [out] resp_commonResult
	*/
	logic_cmd_createReminderMsg = 0xFD,
	/**
	* \brief 分页查询消息提醒
	* [in]  req_getReminderMsgPage
	* [out] resp_getReminderMsgPage
	*/
	logic_cmd_getReminderMsgPage = 0xFE,
	/**
	* \brief 删除消息提醒
	* [in]  req_deleteReminderMsg
	* [out] resp_commonResult
	*/
	logic_cmd_deleteReminderMsg = 0xFF,
	/**
	* \brief 获取群文件
	* [in]  req_getFileList
	* [out] resp_getFileList
	*/
	logic_cmd_getGroupFile = 0x0100,

	/**
	* \brief 群禁言
	* [in]  req_setGroupChatForbid
	* [out] resp_commonResult
	*/
	logic_cmd_setGroupChatForbid = 0x0101,

  /*
  * \brief 下载云盘文件
  * [in] req_downloadCloud
  * [out] resp_commonResult
  */
  logic_cmd_downCloud = 0x0102,
  
  /**
  * \brief xin云盘请求
  * [in] req_cloudDiskFunc
  * [out] resp_commonResult
  */
  logic_cmd_newCloudFunc = 0x0103,
	/*
	* \brief 上传云盘文件
	* [in] req_uploadCloud
	* [out] resp_commonResult
	*/
	logic_cmd_uploadNewCloud = 0x0104,

	/*
	* \brief 查询云盘传输历史任务
	*/
	logic_cmd_getNewCloudTransfer = 0x0105,
	/*
	* \brief 删除云盘传输历史任务
	*/
	logic_cmd_delNewCloudTransfer = 0x0106,
	/*
	* \brief 清空云盘传输历史任务
	*/
	logic_cmd_clearNewCloudTransfer = 0x0107,
	/*
	* \brief 循环请求云盘文件内容
	*/
	logic_cmd_cycleNewCloudReq = 0x0108,
	
	
		/**
	*\brief 追加preKey
	*/
	logic_cmd_appendPreKeyFromNet = 0x0109,

	/**
	* \brief
	* [in]  req_queryTrackInfo
	* [out] resp_commonResult
	*/
	logic_cmd_queryTrackInfo = 0x10A,

	logic_cmd_migrateUserDataNew = 0x10B,
	/**
	*  \brief PC获取二维码信息接口 (PC)
	* [in] req_getqrCode
	* [out] resp_beforeLogin
	*/
	logic_cmd_getQrCode = 0x10C,

	/**
	*  \brief 获取二维码登录状态接口(PC)
	* [in] req_getqrStatus
	* [out] resp_beforeLogin
	*/
	logic_cmd_getQrStatus = 0x10D,

	/**
	*  \brief 二维码扫描登录接口 (移动端)
	* [in] req_scanqrCode
	* [out] resp_commonResult
	*/
	logic_cmd_scanQrCode = 0x10E,

	/**
	*  \brief 确认二维码扫描登录接口 (移动端)
	* [in] req_getQrStatus
	* [out] resp_commonResult
	*/
	logic_cmd_ConfirmPCLogin = 0x10F,
	
	
	logic_cmd_operateAgency = 0x110,
	/**
	*  \brief 根据用户ID集合查询用户的设备信息,豆豆版本
	* [in] req_getLoginClientRecord
	* [out] resp_getLoginClientRecord
	*/
	logic_cmd_getLoginClientRecord = 0x111,

	/**
	* \brief 更新已下载的文件的保存路径到数据库
	*/
	logic_cmd_updateFileLocalPath = 0x112,

	/**
	* \brief 群信息或设置推送
	*/
	logic_cmd_groupInfoOrSetting = 0x113,

	/**
	* \brief 工作台代办设置推送
	*/
	logic_cmd_appShow = 0x114,

	/**
	*  \brief 二维码扫描登录接口 (PC端)
	* [in] req_getAuthUserBean
	* [out] resp_commonResult
	*/
	logic_cmd_checkQrDevice = 0x115,

	/**
	* \brief pc快速登录 (PC端)
	* [in]  req_quickLogin
	* [out] resp_beforeLogin
	*/
	logic_cmd_pcQuickLogin = 0x116,
	
	/**
	* \brief 扫描二维码获取推送的Qrcode
	*/
	logic_cmd_PushQrcode = 0x117,


	/**
	* \brief 客户端应用浏览器的应用服务开关总值
	* [in]  req_getSmalAppHelpFlagValue
	* [out] resp_commonResult
	*/

	logic_cmd_getSmalAppHelpFlagValue = 0x118,

	/**
	* \brief 获取客户端应用浏览器的帮助获取帮助列表
	* [in]  req_getSmallAppHelpList
	* [out] resp_getSmallAppHelpList
	*/

	logic_cmd_getSmallAppHelpList = 0x119,


	/**
	* \brief 获取用户设置项
	* [in]  req_getBuddySetting
	* [out] resp_buddySetting
	*/

	logic_cmd_getBuddySetting = 0x11A,

        /**
	* \brief 多关键字搜索
	* [in]  req_mKeysSearch
	* [out] resp_mKsearchResult
	*/
	logic_cmd_mKeysSearch = 0x11B,

	/**
	* \brief 推送用户标签和动态菜单
	* [in]  NULL
	* [out] resp_getUtagCmenuList  
	*/
	logic_cmd_uTagcMenu = 0x11C,

	/**
	* \brief 备份数据库
	* [in]  _sdkcmd_base
	* [out] resp_commonResult
	*/
	logic_cmd_backupDB = 0x11D,

	/**
	* \brief 获取外部节点信息
	* [in]  _sdkcmd_base
	* [out] resp_commonResult
	*/
	logic_cmd_getOutEntNodeInfo = 0x11E,
	
	/**
	* \brief 获取用户账号注销验证码
	* [in]  req_getLogoutCode
	* [out] resp_getLogoutCode
	*/
	logic_cmd_getLogoutCode = 0x11F,

	/**
	* \brief 注销删除账号
	* [in]  req_setLogoutAccount
	* [out] resp_commonResult
	*/
    logic_cmd_setLogoutAccount = 0x120,

	/**
	* \brief 本地退出登录
	* [in]  _sdkcmd_base
	* [out] resp_commonResult
	*/
	logic_cmd_logout_local = 0x121,


	/**
	* \brief 获取用户工作密集
	* [in]  NULL
	* [out] resp_getUtagCmenuList
	*/
	logic_cmd_getSecurityList = 0x122,
	
	/**
	* \brief 补链结果,纯推送
	* [out] resp_PullMsg
	*/
	logic_cmd_PullMsg = 0x123,
	/**
	* \brief 离线登录无密码,
	* [in]  req_offlineLogin
	* [out] resp_commonResult
	//  [10/16/2020 admin]
	*/
	logic_cmd_offlineLogin_NoPwd = 0x124,
	/**
	*  \brief PC端浏览器授权认证登录认证(仅PC端浏览器)
	* [in] req_getAuthUserBean
	* [out] resp_commonResult
	*/
	logic_cmd_authPcBrowserLoginTokenCheck = 0x125,
	/**
	* \brief 删除客户端数据
	* [in]  req_delMsg
	* [out] resp_commonResult
	*/
	logic_cmd_cleanClientData = 0x126,

	/**
	* \brief 超级用户操作
	* [in]  req_elevatorAuthInfo
	* [out] resp_elevatorAuthInfo
	*/

	logic_cmd_elevatorAuthInfo = 0x127,
	
	/**
	* \brief 输入密码验证,
	* [in]  req_offlineLogin
	* [out] resp_commonResult
	//  [11/9/2020 admin]
	*/
	logic_cmd_loginPwdVerify = 0x128,

	/**
	* \brief 获取用户标签
	* [in]  req_getTagStrategyFromNet
	* [out] resp_commonResult
	*/
	logic_cmd_getTagStrategyFromNet = 0x129,

	/**
	* \brief 超级用户操作推送
	*/
	logic_cmd_OperateSuperUser = 0x12A,
	
		/**
	*  \brief 工作台应用更新推送接口
	* [out] resp_commonResult
	*/
	logic_cmd_applicationUpdate = 0x12B,
	/**
	* \brief 删除指定会话橡皮檫之前的所有消息
	* [in]  req_delMsg
	* [out] resp_commonResult
	*/
	logic_cmd_delEraserMessage = 0x12C,
	//设置本地已读
	logic_cmd_setMsgReaded_local = 0x12D,
	/**
	* \brief 第三方应用认证登出接口PC专用
	* [in]  NULL
	* [out] resp_commonResult
	*/
	logic_cmd_appAuthLogout = 0x12E,
	/**
	* \brief 插入jssdk认证信息
	* [in]  req_insertJssdkAuth
	* [out] resp_
	*/
	logic_cmd_insertJssdkAuth=0x12F,
	/**
	* \brief 请求jssdk认证信息 [删除不用了,2021-04-16]
	* [in]  req_getJssdkAuth
	* [out] resp_
	*/
	logic_cmd_getJssdkAuth = 0x130,
	/**
	* \brief 校验jssdk认证信息
	* [in]  req_checkJssdkAuth
	* [out] resp_
	*/
	logic_cmd_checkJssdkAuthUrl = 0x131,
	/**
	* \brief 校验jssdk认证信息 [删除不用了,2021-04-16]
	* [in]  req_checkJssdkAuth
	* [out] resp_
	*/
	logic_cmd_checkJssdkAuthAppId = 0x132,
	logic_cmd_operateAgencyEx = 0x133,

	/**
	* \brief 任务代办本地分页展示结果
	* [in]  req_getLocalAgencyListFromDb
	* [out] resp_getLocalAgencyListFromDb
	*/
	logic_cmd_getLocalAgencyListFromDb = 0x134,
	/**
	* \brief 获取已完成和未完成列表数
	* [in]  req_getAgencyListFinishCnt
	* [out] resp_getAgencyListFinishCnt
	*/
	logic_cmd_getAgencyListFinishCnt= 0x135,
	/**
	* \brief 工作台任务设置已读和未读
	* [in]  req_setAgencyListRead
	* [out] resp_setAgencyListRead
	*/
	logic_cmd_setAgencyListRead = 0x136,
	/**
	* \brief 获取本地筛选条件（来源和标签展示）
	* [in]  req_getAgencyListScreenItem
	* [out] resp_getAgencyListScreenItem
	*/
	logic_cmd_getAgencyListScreenItem = 0x137,
	/**
	* \brief 展示历史搜索记录
	* [in]  req_disHistoryAgencyListRecords
	* [out] resp_disHistoryAgencyListRecords
	*/
	logic_cmd_disHistoryAgencyListRecords = 0x138,
	/**
	* \brief 清空历史搜索记录
	* [in]  req_delHistoryAgencyListRecords
	* [out] resp_delHistoryAgencyListRecords
	*/
	logic_cmd_delHistoryAgencyListRecords = 0x139,
	/**
	* \brief 获取栏目的应用列表
	* [in]  req_getAppListByMenuCode
	* [out] resp_getAppListByMenuCode
	*/
	logic_cmd_getAppListByMenuCode = 0x13A,
	/**
	* \brief 获取栏目的应用列表
	* [in]  req_getAppListByMenuSeq
	* [out] resp_getAppListByMenuSeq
	*/
	logic_cmd_getAppListByMenuSeq = 0x13B,
	/**
	* \brief 新待办用户点击按钮回馈信息给应用
	* [in]  req_pushMsgToApp
	* [out] resp_commonResult
	*/
	logic_cmd_pushMsgToApp = 0x13C,
	/**
	*  \brief 第三方用户标识鉴权新增，根据idToken获取用户userId
	* [in] req_getAuthUserBean
	* [out] resp_commonResult
	*/
	logic_cmd_thirdPartyAuth = 0x13D,
	
	
	
		logic_cmd_DoubleKeyMessage = 0x13E,

	logic_cmd_BifactorLoginMessage = 0x13F,
	//公众号提醒
	logic_cmd_setUserToAppConfig = 0x140,
	logic_cmd_getUserToAppConfigList = 0x141,
	/**
	* \brief 获取用户已安装列表信息返回给客户端
	* [in]  req_getInstalledApplication
	* [out] resp_getInstalledApplication
	*/
	logic_cmd_getInstalledAppFromNet = 0x142,
	logic_cmd_updateDeReconMsg = 0x143,
	/**
	* \brief M盒二维码查询相关接口
	* [in]  req_mQrCodeQuery
	* [out] resp_QrCodeQuery
	*/
	logic_cmd_MQrCodeQuery = 0x144,

	/**
	* \brief M盒二维码周期查询相关接口
	* [in]  req_mQrCodeQuery
	* [out] resp_QrCodeQuery
	*/
	logic_cmd_MCircleQrCodeQuery = 0x145,
	/**
	* \brief 用户绑定的后台管理员角色信息
	*/
	logic_cmd_getAdminRoleInfo = 0x146,
	/**
	* \brief 用户绑定的后台管理员角色信息
	*/
	logic_cmd_getAdminRoleInfoJson = 0x147,
	/**
	* \brief 打开密码校验界面
	*/
	logic_cmd_showVerifyUserPassword = 0x148,

	logic_cmd_OpeateDelayMsg = 0x149,

	/**
	* \brief 表情包一期改造的集合
	* [in]  req_emoticonUnionOne
	* [out] resp_emoticonUnionOne
	*/
	logic_cmd_emoticonUnionOne = 0x14A,
	/**
	* \brief 用户设置服务器别名
	* [in]  req_setServerAlias
	* [out] resp_setServerAlias
	*/
	logic_cmd_setServerAlias = 0x14B,
	/**
	* \brief 用户设置服务器别名
	* [in]  req_getServerAlias
	* [out] resp_getServerAlias
	*/
	logic_cmd_getServerAlias = 0x14C,
	/**
	* \brief 获取用户通用token
	* [in]  NULL
	* [out] resp_getUtagCmenuList
	*/
	logic_cmd_getCommonToken = 0x14D,
	/**
	* \brief 通过用户通用token获取用户id
	* [in]  NULL
	* [out] resp_getUtagCmenuList
	*/
	logic_cmd_checkCommonToken = 0x14E,

	/**
	* \brief 忽略/添加群应用
	* [in]  req_IgnoreMarketApp
	* [out] resp_IgnoreMarketApp
	*/
	logic_cmd_IgnoreMarketApp = 0x14F,
	/**
	* \brief
	* [in]  req_delFileInfoList
	* [out] resp_commonResult
	*/
	logic_cmd_delFileInfoList = 0x150,

	/**
	* \brief 新增群文档接口
	*[in] req_AddGroupDocFile
	*[out] resp_AddGroupDocFile
	*/
	logic_cmd_GroupDocFile = 0x151,
	/**
	* \brief 修改群文档名接口
	*[in] req_GroupDocAttribute
	*[out] resp_GroupDocFile
	*/
	logic_cmd_UpdateGDocFile = 0x152,
	/**
	* \brief 增量查询群文档数据接口
	*[in]  req_GroupDocQuery, 
	*[out] resp_GroupDocFile
	*/
	logic_cmd_QueryGDocFile = 0x153,

	/**
	* \brief 获取群文档数据列表
	* [in]  req_groupDocComData
	* [out] resp_getGDocList
	*/
	logic_cmd_getGroupDocList = 0x154,


	/**
	* \brief 获取群上传下载文档数据列表
	* [in]  req_gDocupDownData
	* [out] resp_getGDocList
	*/
	logic_cmd_getGDocUpDownList = 0x155,

	/**
	* \brief 获取群上传下载文档数据列表
	* [in]  req_gDocupDownData
	* [out] resp_getGDocList
	*/
	logic_cmd_setGDocUpDownList = 0x156,
	/**
	* \brief 获取群上传下载文档数据列表
	* [in]  req_gDocupDownData
	* [out] resp_getGDocList
	*/
	logic_cmd_delGDocUpDownList = 0x157,

	/**
	* \brief 刷新群文档列表 主动推送
	*
	* [out] resp_groupNotify
	*/
	logic_cmd_gdocRefresh = 0x158,


	/**
	* \brief 获取指定用户信息
	* [in]  req_getUserFromID
	* [out] resp_getUserFromID
	*/
	logic_cmd_getUserByID = 0x159,
	/**
	* \brief 上传过期的文件消息
	* [in]  req_fileMessage
	* [out] resp_uploadOverDueMessageFile
	*/
	logic_cmd_uploadOverDueMessageFile = 0x15A,

	/**
	* \brief 上传过期的图片消息
	* [in]  req_imgMessage
	* [out] resp_uploadOverDueMessageFile
	*/
	logic_cmd_uploadOverDueMessageImg = 0x15B,

	/**
	* \brief 获取搜索信息
	* [in]  req_GetUserSetting
	* [out] resp_GetClientSearchingSetting
	*/  
	logic_cmd_GetClientSearchSetting = 0x15C,
	logic_cmd_SetClientSearchSetting = 0x15D,

	/**
	* \brief 获取组合消息模板
	* [in]  req_GetCombinationReq
	* [out] resp_CombinationSettingResult
	*/
	logic_cmd_GetCombinationSetting  = 0x15E,

	/**
	* \brief 设置组合消息模板
	* [in]  req_SetCombinationReq
	* [out] resp_CombinationSettingResult
	*/
	logic_cmd_SetCombinationSetting  = 0x15F,
	/* 推送给客户端的表情包状态信息 按位 1 新增 2修改  3删除
	* [out] resp_PushEmottoClient
	*/
	logic_cmd_PushEmoPacktoClient = 0x160,
	/**
	* \brief 获取好友在线状态,增强版
	* [in]  req_getBuddyOnline
	* [out] resp_getBuddyOnlineResult
	*/
	logic_cmd_getDeviceOnlineEx = 0x161,
	/**
	* \brief 输入密码加密后返回,
	* [in]  req_offlineLogin
	* [out] resp_commonResult
	*/
	logic_cmd_loginPwdEncrypt = 0x162,
	/**
	* \brief 获取文件分片信息
	* [in]  req_FileFragmentationInfo
	* [out] resp_getBuddyOnlineResult
	*/
	logic_cmd_getFileFragmentationInfo = 0x163,
	/**
	* \brief 获取文件分片内容
	* [in]  req_FileFragmentationInfo
	* [out] resp_getBuddyOnlineResult
	*/
	logic_cmd_getFileContentByFragmentIndex =0x164,
	/**
	* [in] req_fileExpirySoon
	* [out] resp_fileExpirySoon
	*/
	logic_cmd_fileExpirySoon = 0x165,
	/**
	* [in] req_fileExpirySoonResult
	* [out] resp_fileExpirySoonResult
	*/
	logic_cmd_fileExpirySoonResult = 0x166,
	/**
	* [in]  _sdkcmd_base
	* [out] resp_serverFileValidDays
	*/
	logic_cmd_serverFileValidDays = 0x167,
	/**
	* [in] req_fileExpiryInfoStore
	* [out] resp_fileExpiryInfoStore
	*/
	logic_cmd_fileExpiryInfoStore = 0x168,
	/**
	* [in] req_fileExpiryInfoAsk
	* [out] resp_fileExpiryInfoAsk
	*/
	logic_cmd_fileExpiryInfoAsk = 0x169,
	/**
	* \brief 设置密聊密码
	* [in]  req_verifyPrivateMsgPwd
	* [out] resp_verifyResult
	*/
	logic_cmd_verifyPrivateMsgPwd = 0x16A,
	/**
	* [in] req_OperaMassRecord
	* [out] resp_commonResult
	*/
	logic_cmd_OperaMassRecord = 0x16B,
	/**
	* [in] req_QueryMassRecord
	* [out] resp_QueryMassRecord
	*/
	logic_cmd_QueryMassRecord = 0x16C,
	logic_cmd_max
};

}

#endif  //CMD_TYPE_DEF_H_
