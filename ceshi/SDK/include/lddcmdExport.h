/*
 * lddcmdExport.h
 *
 *  Created on: 2016年4月25日
 *      Author: corning
 */

#ifndef LDDCMDEXPORT_H_
#define LDDCMDEXPORT_H_

#include <cmdReqDef.h>
#include <cmdComDef.h>
#include <string>
#include <vector>
#include <config.h>

using namespace imsdk;

namespace imsdkldd{

/**
 * 导出业务类消息号，各个平台的ＡＰＩ层要统一
 * ** [in] 标识输入参数
 * ** [out] 标识返回参数
 * ** 只有[out]没有[in] 标识该消息ＳＤＫ纯推送，只有reponse没有request
 */
enum {

    /// [in] req_topTaskMsg              [out] resp_commonResult
    ldd_logic_cmd_topTaskMsg = 11001,         /// 任务置顶

    /// [in] _sdkcmd_base                [out] resp_taskMsgCom
    ldd_logic_cmd_getSendTaskMsgs = 11002,    /// 获取指派的任务

    /// [in] _sdkcmd_base                [out] resp_taskMsgCom
    ldd_logic_cmd_getReceiveTaskMsgs = 11003, /// 获取接收的任务

    /// [in] _sdkcmd_base                [out] resp_taskMsgCom
    ldd_logic_cmd_getHistoryTaskMsgs = 11004, /// 获取历史任务

    /// [in] req_taskMsgCom              [out] resp_commonResult(value_str字段标记任务内容)
    ldd_logic_cmd_getBodyTaskMsg = 11005,     /// 获取任务上下文

    /// [in] req_taskMsgCom              [out] resp_commonResult
    ldd_logic_cmd_reCoveryTaskMsg = 11006,    /// 恢复任务

    /// [in] req_taskMsgCom              [out] resp_commonResult
    ldd_logic_cmd_finishTaskMsg = 11007,      /// 完成任务


    /// [in] req_createRoom              [out] resp_commonResult(value_i32字段标记rommID)
    ldd_logic_cmd_createRoom = 11008,         /// 创建房间

    /// [in] req_opRoom                  [out] resp_commonResult
    ldd_logic_cmd_opRoom = 11009,             /// 修改房间

    /// [in] req_roomCom                 [out] resp_commonResult
    ldd_logic_cmd_delRoom = 11010,            /// 删除房间

    /// [in] req_roomCom                 [out] resp_getAllRooms
    ldd_logic_cmd_getRoom = 11011,            /// 获取一个房间

    /// [in] NULL                        [out] resp_getAllRooms
    ldd_logic_cmd_getAllRooms = 11012,        /// 获取所有房间

    /// [in] req_topRoom                 [out] resp_commonResult
    ldd_logic_cmd_topRoom = 11013,            /// 房间置顶


	/// [in] NULL						[out] resp_getEnterpriseListByUser
    ldd_logic_cmd_getEnterpriseListByUser = 11014,      /// 废弃接口

	/// [in] req_getVisibleOrgUsers		[out] resp_getOrgUserAndChildNodes
    ldd_logic_cmd_getVisibleOrgUsers = 11015,           /// 获取某个用户所在组织下可见的子组织和用户

    /// [in] req_queryEnterpriseUserlist	[out] resp_queryEnterpriseUserlist
    // ldd_logic_cmd_queryEnterpriseUserlist = 11016,   /// 根据条件查询企业用户列表


	/// [in] req_getMsgCount 			[out] resp_commonResult
	ldd_cmd_getMsgCount = 11017,			  /// 根据targetId获取消息数量
	
	/// [in] req_getMsgCountTopN 		[out] resp_getMsgCountTopN
	ldd_cmd_getMsgCountTopN = 11018,		  /// 获取聊天数目最多的topN或@自己最多的topN


	/// [in] req_AddNote 				[out] resp_commonResult
	ldd_logic_cmd_AddNote = 11019, 			  /// 添加记事本
	
	/// [in] req_getNotes 				[out] resp_getNotes 
	ldd_logic_cmd_getNotes = 11020 ,		  /// 记事本查询
	
	/// [in] req_delNotes 				[out] resp_commonResult
	ldd_logic_cmd_delNotes = 11021, 		  /// 删除记事本
	
	/// [in] req_editNotes 				[out] resp_commonResult
	ldd_logic_cmd_editNotes = 11022,		  /// 修改记事本

	/// [in] req_archiveNotes			[out] resp_commonResult
	ldd_logic_cmd_archiveNotes = 11023,       /// 归档


    /// [in] req_qEnUS	                [out] resp_qEnUS
    ldd_logic_cmd_qEnUS = 11024,              /// 查询组织机构的用户

    /// [in] req_getOrgInfo	            [out] resp_getOrgInfo
    ldd_logic_cmd_getOrgInfo = 11025,         /// 获取组织的信息


    /// [in] req_archiveNotes            [out] resp_commonResult
    ldd_logic_cmd_topNote = 11026,            /// 记事本置顶

    /// [in] req_searchNotes             [out] resp_getNotes
    ldd_logic_cmd_searchNote = 11027,         /// 记事本搜索


    /// [in] req_taskMsgCom              [out] resp_commonResult
    ldd_logic_cmd_readTaskMsg = 11028,        /// 设置任务已读

    /// [in] req_getReceiveMsg           [out] resp_getReceiveMsg
    ldd_logic_cmd_getReceiveMsg = 11029,      /// 获取任务回复消息

    /// [in] req_updataTask              [out] resp_commonResult
    ldd_logic_cmd_updataTask = 11030,         /// 修改任务属性，包括 1：是否完成 2：是否标记 3：是否已读 4：是否置顶

    /// [in] req_taskMsgCom              [out] resp_commonResult
    ldd_logic_cmd_delTaskMsg = 11031,         /// 删除任务

    /// [in] req_opRoomMembers           [out] resp_commonResult
    ldd_logic_cmd_addRoomMembers = 11032,     /// 房间增加人员

    /// [in] req_opRoomMembers           [out] resp_commonResult
    ldd_logic_cmd_delRoomMembers = 11033,     /// 房间删除人员

    ldd_logic_cmd_getOrgInfos = 11034,        /// 批量获取组织信息


    /// [in] _sdkcmd_base                [out] resp_mailMsgCom
    ldd_logic_cmd_getSendMailMsgs = 11035,    /// 获取指派的邮件

    /// [in] _sdkcmd_base                [out] resp_mailMsgCom
    ldd_logic_cmd_getReceiveMailMsgs = 11036, /// 获取接收的邮件

    /// [in] req_mailMsgCom              [out] resp_commonResult
    ldd_logic_cmd_readMailMsg = 11037,        /// 设置邮件已读

    /// [in] req_mailMsgCom              [out] resp_commonResult
    ldd_logic_cmd_delMailMsg = 11038,         /// 删除邮件

    /// [in] req_orgAndUserSearch        [out] resp_orgAndUserSearch
    ldd_logic_cmd_orgAndUserSearch = 11039,   /// 组织机构的模糊搜索

	/// [in] req_qCustomerS	                [out] resp_qCustomerS
	ldd_logic_cmd_qCustomerS = 11040,              /// 智能客服接口

	/// 记事本功能
	/// [in] req_notebook 				[out] resp_commonResult
	ldd_logic_cmd_addNotebook = 11041,

	/// [in] req_delNotebook 			[out] resp_commonResult
	ldd_logic_cmd_delNotebook = 11042,

	/// [in] req_getNotebooks 			[out] resp_getNotebooks
	ldd_logic_cmd_getNotebook = 11043,

	/// [in] req_notebook 				[out] resp_commonResult
	ldd_logic_cmd_updateNotebook = 11044,

	/// [in] req_encryptNotebook		[out] resp_commonResult
	ldd_logic_cmd_encryptNotebook = 11045,

	/// [in] req_decryptNotebook 		[out] resp_commonResult
	ldd_logic_cmd_decryptNotebook = 11046,

	/// [in] req_noteEntry 				[out] resp_commonResult
	ldd_logic_cmd_addNoteEntry = 11047,

	/// [in] req_getNoteContents 		[out] resp_getNoteEntrys
	ldd_logic_cmd_getNoteEntry = 11048,

	/// [in] req_delNoteEntry 			[out] resp_commonResult
	ldd_logic_cmd_delNoteEntry = 11049,

	/// [in] req_noteEntry 				[out] resp_commonResult
	ldd_logic_cmd_updateNoteEntry = 11050,

	/// [in] req_searchNoteEntry 		[out] resp_getNoteEntrys
	ldd_logic_cmd_searchNoteEntry = 11051,

	/// [in] req_getCustomHistoryMsg 		[out] resp_getCustomHistoryMsg
	ldd_logic_cmd_getCustomHistoryMsg = 11052,

	/// [in] req_delNotebook 			[out] resp_commonResult
	ldd_logic_cmd_delNotebookById = 11053,
	
	/// [in] req_encryptNotebook 			[out] resp_commonResult
	ldd_logic_cmd_checkNotebookey = 11054,

	/// [in] req_getUserShield        [out] resp_getUserShield
	ldd_logic_cmd_getUserShield = 11055,   /// 根据账号查询手机盾数据信息

	/// [in] req_getCustomChatList        [out] resp_customChatList
	ldd_logic_cmd_customContactList = 11056,  ///客服会话列表会话

	/// [in] req_getCustomChatList        [out] resp_commonResult
	ldd_logic_cmd_setCustomMsgReaded = 11057,  ///设置客服消息已读

	/// [in] req_encryptNotebook			[out] resp_commonResult
	ldd_logic_cmd_hideNotebook = 11058,		///隐藏记事本
	/// [in] req_encryptNotebook			[out] resp_commonResult
	ldd_logic_cmd_checkHiddenKey = 11059,		///查看隐藏记事本
	/// [in] NULL						[out] resp_stateColor
	ldd_logic_cmd_taskRemindColor = 11060,		///提醒颜色推送
	/// [in] req_editNotebookLabel 		[out] resp_commonResult
	ldd_logic_cmd_editNotebookLabel = 11061,   ///修改标签
	 /// [in] req_searchNotebook		[out] resp_searchNotebook
	ldd_logic_cmd_searchNotebook = 11062,     ///搜索记事本

	ldd_logic_cmd_max	                      /// 最大的命令标识，标识命令个数，无特殊业务意义
};

/// =========================================================================================

/// 任务属性
struct st_msgProperties {
    st_msgProperties() {
        timeZone = 0;
    }

    int32 timeZone;             ///< 时区
    std::string timeTask;       ///< 任务时间
    std::string isFinish;       ///< 是否完成     0：未完成 1：完成 2:与自己无关
    std::string isTask;         ///< 任务标记     0：非任务 1：任务
    std::string isRead;         ///< 是否已读     0：未读   1：已读	2: 已回复
};

/// task
struct st_task {
    st_task() {
        fromeUserID = 0;
        msgID = 0;
        top = 0;
        targetID = 0;
        badwordType = 0;
        vt_relatedUsers.clear();
        vt_badword.clear();
    }

    int64 fromeUserID;                  ///< 自己发送的这个字段填0
    int64 sendTime;                     ///< 发送时间
    std::string body;                   ///< 消息体
    int64 msgID;                        ///< 任务ID
    st_msgProperties msgProperties;
    std::string relatedUsers;           ///< 如果是针对群全体成员，就是群ID，如果针对部分人，就是人的ID数组
    std::vector<int64> vt_relatedUsers; ///< 返回的时候用
    int32 badwordType;                  ///< 过滤词type
    std::string badword;                ///< 过滤词
    std::vector<std::string> vt_badword;
    int8 top;                           ///< 是否置顶   0：不置顶 1：置顶
    int64 targetID; 		            ///< 接受者，可以为群或者人
};

/// mail
struct st_mail {
    st_mail() {
        fromeUserID = 0;
        sendTime = 0;
        msgID = 0;
        isRead = 0;
        targetID = 0;
    }

    int64 fromeUserID;                  ///< 发送人
    int64 sendTime;                     ///< 发送时间
    std::string body;                   ///< 消息体
    int64 msgID;                        ///< 邮件ID
    int8 isRead;                        ///< 0:未读  1:已读
    int64 targetID; 		            ///< 接受者，可以为群或者人
};

/// room
struct st_room {
    st_room() {
        roomID = 0;
        top = 0;
        vt_roomMember.clear();
    }

    int roomID;                         ///< 房间ID
    std::string roomName;               ///< 房间名
    std::string roomMember;             ///< 房间成员
    std::vector<int64> vt_roomMember;   ///< 返回的时候用
    int8 top;                           ///< 是否置顶   0：不置顶 1：置顶
    std::string portraitURL;            ///< 头像
};

/// note
struct st_baseNoteinfo
{
    st_baseNoteinfo() : isNet(false), id(0), lastChgTime(0), sendUserId(0), targetId(0), type(0), isReminder(0), rmdTime(0), isArchive(0) {
        INIT_ISSET(lastChgTime)
            INIT_ISSET(sendUserId)
            INIT_ISSET(targetId)
            INIT_ISSET(type)
            INIT_ISSET(content)
            INIT_ISSET(title)
            INIT_ISSET(key)
            INIT_ISSET(isReminder)
            INIT_ISSET(rmdTime)
            INIT_ISSET(isArchive)
    }

    bool isNet;                     ///< 是否使用网络接口
    int64 id;						///< 记事本唯一标识,不用赋值
    IS_SET(int64, lastChgTime) 		///< 最后修改时间,毫秒
    IS_SET(int64, sendUserId)		///< 发送的人
    IS_SET(int64, targetId)		    ///< 来源 人或者群
    /**
     * 低8位 类型 1. 文本，2，图片，3，音频，4，视频，5，URL 6, 文件 7,名片
     * 高8位 1. 本地， 0. 网络
     */
    IS_SET(int8, type)
    IS_SET(int16, netType)
    /**
     * 根据文件类型
     * 1. 文本、URL 直接存储内容。
     * 2. 非文本类型，存储附件地址，网络地址和本地地址均可。
     */
    IS_SET(std::string, content)	///< 内容,最长4096个字符	
    IS_SET(std::string, title)		///< 标题,最长128字符
    IS_SET(std::string, key)		///< 关键字(标签),检索用 最长128字符 ,可以为空
    IS_SET(int8, isReminder)		///< 是否是提醒
    IS_SET(int64, rmdTime)			///< 提醒时间
    IS_SET(int8, isArchive)			///< 是否归档
    //下面是网络接口参数
    IS_SET(std::string, msgProperties)  ///< 消息属性
    IS_SET(std::string, fileName)       ///< 文件名
    IS_SET(std::string, exts)           ///< 扩展字段
};

/// 企业信息
struct st_entpriseInfo
{
	st_entpriseInfo() :
	    enterpriseID(0),
	    sector(0),
	    sectorDetail(0),
	    type(0),
	    provinceID(0),
	    cityID(0),
	    areaID(0),
	    status(0),
	    creationDate(0),
	    updatedDate(0) {
    }

	int64 enterpriseID;         ///< 企业ID enterpriseID.
	std::string fullName;       ///< 企业全称 fullName.
	std::string shortName;      ///< 企业简称 shortName.
	std::string keyWords;       ///< 企业关键字 keyWords.
	int64 sector;               ///< 企业所属行业 sector.
	int64 sectorDetail;         ///< 企业所属行业的具体哪一类 sectorDetail.
	int8 type;                  ///< 企业类型 type.
	int64 provinceID;           ///< 企业所属省份 provinceID.
	int64 cityID;               ///< 企业所属市 cityID.
	int64 areaID;               ///< 企业所属地区 areaID.
	std::string address;        ///< 企业地址 address.
	std::string postcode;       ///< 企业邮编 postcode.
	std::string phone;          ///< 企业电话 phone.
	std::string fax;            ///< 企业传真 fax.
	std::string email;          ///< 企业邮箱 email.
	std::string homepage;       ///< 企业主业 homepage.
	std::string introduction;   ///< 企业简介 introduction.
	std::string logUrl;         ///< 企业logURL地址 logUrl.
	int8 status;                ///< 企业状态：1:审核通过；2：未审核；3：审核未通过 status.
	int64 creationDate;         ///< 注册时间 creationDate.
	int64 updatedDate;          ///< 修改时间 updatedDate.
};


/// 企业成员信息
struct st_entpriseUserInfo
{
	st_entpriseUserInfo() :
	    userID(0),
	    enterpriseID(0),
	    orgID(0),
	    roleID(0),
	    status(0),
	    orderNum(0),
	    newOrgID(0) {
    }

	int64 userID;               ///< 用户ID userID.
	int64 enterpriseID;         ///< 企业ID enterpriseID.
	int64 orgID;                ///< 组织机构ID orgID.
	int64 roleID;               ///< 角色ID roleID.
	std::string enName;         ///< 企业内用户名称 enName.
	std::string duty;           ///< 企业内用户职位 duty.
	std::string enMail;         ///< 企业内用户email enMail.
	std::string enMobile;       ///< 企业内用户手机号 enMobile.
	int8 status;                ///< 企业账号是否被停用 1：正常 2：停用 status.
	int64 orderNum;             ///< 人员排序 orderNum.
	int64 newOrgID;             ///< 用户修改组织机构使用，表示用户新组织机构，在修改时给用户增加组织机构时，使用newOgrID而不是orgID newOrgID.
	std::string orgName;        ///< 组织名 orgName.
	std::string extend;         ///< 扩展信息 extend.
	std::string accountName;    ///< 账号名称 accountName.
	std::string enNamePy;       ///< 拼音 enNamePy.
    int8  bizStatus;            ///< 业务状态 业务状态：1：初始状态，2：在高管群
    std::string userHead;       ///< 头像
	std::string userHeadUrl;    ///< 头像全路径
    std::string power;          ///< 组织策略权限
	int32 securityLevel;        ///< 工作密级
	std::string tagIds;          ///< 用户标签id,多个用逗号分隔
};

//记事本
struct st_Notebook
{
	st_Notebook() :id(0), lastChgTime(0), createTime(0), noteCount(0),
		isEncrypted(0), isRemind(0), rmdTime(0), isHidden(0)
	{
		INIT_ISSET(lastChgTime)
			INIT_ISSET(noteCount)
			INIT_ISSET(isEncrypted)
			INIT_ISSET(isRemind)
			INIT_ISSET(rmdTime)
			INIT_ISSET(title)
			INIT_ISSET(encryptKey)
			INIT_ISSET(ext)
			INIT_ISSET(isHidden)
			INIT_ISSET(hiddenKey)
			INIT_ISSET(label)
	}

	int64 id;				///< 记事本唯一标识
	int64 createTime;		///< 创建时间
	IS_SET(int64, lastChgTime) 		///< 最后修改时间,毫秒
	IS_SET(int32, noteCount)		///< 记事本条目数
	IS_SET(int8, isEncrypted)		///< 加密方式 0.不加密 1.字符加密 2.手势加密
	IS_SET(int8, isRemind)			///< 是否提醒
	IS_SET(int64, rmdTime)			///< 提醒时间
	IS_SET(std::string, title)		///< 标题,最长128字符
	IS_SET(std::string, encryptKey) ///< 加密密钥
	IS_SET(std::string, bgImage)	///< 背景图片
	IS_SET(std::string, ext)		///< 扩展内容
	IS_SET(int8, isHidden)			///< 是否提醒
	IS_SET(std::string, hiddenKey)	///< 扩展内容
	IS_SET(std::string, label)		///< 标签
};
//记事内容
struct st_NoteEntry
{
	st_NoteEntry() :id(0), noteId(0), lastChgTime(0), createTime(0),
	sourceId(0), type(0), isRemind(0), rmdTime(0), securityLevel(0)
	{
		INIT_ISSET(noteId)
			INIT_ISSET(lastChgTime)
			INIT_ISSET(sourceId)
			INIT_ISSET(type)
			INIT_ISSET(isRemind)
			INIT_ISSET(rmdTime)
			INIT_ISSET(title)
			INIT_ISSET(content)
			INIT_ISSET(msgProperty)
			INIT_ISSET(sourceName)
			INIT_ISSET(securityLevel)
	}

	int64 id;				///< 记事条目唯一标识
	int64 createTime;		///< 创建时间
	IS_SET(int64, noteId)			///< 对应的记事本Id
		IS_SET(int64, lastChgTime) 		///< 最后修改时间,毫秒
		IS_SET(int64, sourceId)			///< 来源Id
		IS_SET(int32, type)				///< 记事类型 2.文本 3.语音 4.文件 5.图片
		IS_SET(int8, isRemind)			///< 是否提醒
		IS_SET(int64, rmdTime)			///< 提醒时间
		IS_SET(std::string, title)		///< 标题,最长128字符
		IS_SET(std::string, content)	///< 记事内容
		IS_SET(std::string, msgProperty)///< 消息属性
		IS_SET(std::string, sourceName)	///< 来源名称
		IS_SET(int32, securityLevel)	///< 来源名称
};

/// ===============================================================================================

/// task
struct req_taskMsgCom : public _sdkcmd_base
{
    int64 msgID;
    CMD_SIZE();
};

struct resp_taskMsgCom : public _sdkrespcmd_base {
    std::vector<st_task> vtTaskMsgs;
    CMD_SIZE();
    COPY_OTHER(resp_taskMsgCom);
};

/// ldd_logic_cmd_topTaskMsg
struct req_topTaskMsg : public _sdkcmd_base
{
    int64 msgID;
    int8 top;               ///< 是否置顶   0：不置顶 1：置顶
    CMD_SIZE();
};

/// ldd_logic_cmd_getReceiveMsg
struct req_getReceiveMsg : public _sdkcmd_base
{
    req_getReceiveMsg() {
        type = 0;
        msgID = 0;
        count = 10;
    }

    int8 type;              ///< 1:根据msgID获取; 2:根据timeTask获取
    int64 msgID;            ///< type = 1时赋值
    std::string timeTask;   ///< type = 2时赋值
    int begin;              ///< 从第几条开始获取，如果从第一条开始获取，传0
    int count;              ///< 获取几条
    CMD_SIZE();
};

struct resp_getReceiveMsg : public _sdkrespcmd_base {
    std::vector<st_task> vtMainTasks;               ///< 查询的任务
    std::vector<imsdk::st_msgBean> vtReceiveMsgs;   ///< 任务的回复
    CMD_SIZE();
    COPY_OTHER(resp_getReceiveMsg);
};


/// ldd_logic_cmd_updataTask
struct req_updataTask : public _sdkcmd_base
{
    req_updataTask() {
        isSetFinish = false;
        isSetTask = false;
        isSetRead = false;
        isSetTop = false;
        msgID = 0;
        isTop = 0;
    }

    int64 msgID;

    bool isSetFinish;       ///< 标记是否设置isFinish字段
    std::string isFinish;   ///< 是否完成     0：未完成 1：完成

    bool isSetTask;         ///< 标记是否设置isTask字段
    std::string isTask;     ///< 任务标记     0：非任务 1：任务

    bool isSetRead;         ///< 标记是否设置isRead字段
    std::string isRead;     ///< 是否已读     0：未读 1：已读

    bool isSetTop;          ///< 标记是否设置isTop字段
    int8 isTop;             ///< 是否置顶   0：不置顶 1：置顶

    CMD_SIZE();
};

/// room
struct req_roomCom : public _sdkcmd_base
{
    int roomID;             ///< 房间ID
    CMD_SIZE();
};

/// ldd_logic_cmd_createRoom
struct req_createRoom : public _sdkcmd_base
{
    req_createRoom() {
        top = 0;
        vt.clear();
    }

    std::string roomName;   ///< 房间名
    std::vector<int64> vt;  ///< 成员集合
    int8 top;               ///< 是否置顶   0：不置顶 1：置顶
    std::string portraitURL;///< 头像
    CMD_SIZE();
};

/// ldd_logic_cmd_opRoom
struct req_opRoom : public _sdkcmd_base
{
    req_opRoom() {
        isSetroomName = false;
        isSetportraitURL = false;
        isSetmember = false;
    }
    int roomID;             ///< 房间ID
    std::string roomName;   ///< 名字（修改了传值，没修改不传值）
    bool isSetroomName;     ///< 修改名字置为true，没有修改置为false
    std::string portraitURL;///< 头像（修改了传值，没修改不传值）
    bool isSetportraitURL;  ///< 修改头像置为true，没有修改置为false
    std::vector<int64> vt;  ///< 成员集合(有新增的或者删除的就传值，保留最终人员，没有就不传)
    bool isSetmember;       ///< vt有值时设置为true,没有值时为false
    CMD_SIZE();
};

/// ldd_logic_cmd_topRoom
struct req_topRoom : public _sdkcmd_base
{
    int roomID;		        ///< 房间ID
    int8 top;               ///< 是否置顶   0：不置顶 1：置顶
    CMD_SIZE();
};

/// ldd_logic_cmd_getAllRooms
struct resp_getAllRooms : public _sdkrespcmd_base {
    std::vector<st_room> vt;
    CMD_SIZE();
    COPY_OTHER(resp_getAllRooms);
};

/// ldd_logic_cmd_getEnterpriseListByUser
struct resp_getEnterpriseListByUser : public _sdkrespcmd_base {
	std::vector<st_entpriseInfo> vtEntpriseInfo;
	CMD_SIZE();
    COPY_OTHER(resp_getEnterpriseListByUser);
};

/// ldd_logic_cmd_getVisibleOrgUsers
struct req_getVisibleOrgUsers : public _sdkcmd_base
{
    req_getVisibleOrgUsers() {
        flag = 0;
        type = 0;
        orgID = 0;
    }

    /**
     * 正常情况下这个值不用传，如果是离线登陆，传1
     */
    int8 flag;
    /**
     * 老版本的组织机构使用
     * 0:获取登陆时刻的组织机构
     * 1:获取当前时刻的组织机构
     * =1 比 =0 速度上慢了很多，建议使用 =0
     */
    int8 type;
	int64 orgID;            ///< 传 0 表示获取根组织
	CMD_SIZE();
};

/// ldd_logic_cmd_addRoomMembers
/// ldd_logic_cmd_delRoomMembers
struct req_opRoomMembers : public _sdkcmd_base
{
    req_opRoomMembers() {
        roomID = 0;
    }

    int roomID;             ///< 房间号
    std::vector<int64> vt;  ///< 成员集合
    CMD_SIZE();
};

struct resp_getOrgUserAndChildNodes : public _sdkrespcmd_base
{
    resp_getOrgUserAndChildNodes() {
        allowChat = 1;
        contactVisiable = 1;
        vtOrgInfo.clear();
        vtEntUser.clear();
    }

    int8 allowChat;         ///< 是否可聊天(0: 不可以， 1: 可以)
    int8 contactVisiable;   ///< 是否可查看联系方式(0: 不可以， 1: 可以)
	std::vector<st_organizationInfo> vtOrgInfo;
	std::vector<st_entpriseUserInfo> vtEntUser;
	CMD_SIZE();
    COPY_OTHER(resp_getOrgUserAndChildNodes);
};

/// ldd_logic_cmd_qEnUS
struct req_qEnUS : public _sdkcmd_base
{
    req_qEnUS() {
        type = 0;
        userID = 0;
        flag = 0;
        vt.clear();
    }

    /**
     * 正常情况下这个值不用传，如果是离线登陆，传1
     */
    int8 flag;
    int8  type;              ///< 1:输入userID，获取用户信息; 2:输入用户名称，获取用户信息; 3:输入用户ID集合，返回这些用户信息
    int64 userID;            ///< type=2 或 3 时不用赋值，type=1 时为用户ID
    std::string userName;    ///< type=1 或 3 时不用传值，type=2 时传用户名称
    std::vector<int64> vt;   ///< type=1 或 2 时不用传值，type=3 时传用户ID集合
    CMD_SIZE();
};

struct resp_qEnUS : public _sdkrespcmd_base
{
    resp_qEnUS() {
        vtEntUser.clear();
    }

    std::vector<st_entpriseUserInfo> vtEntUser;
    CMD_SIZE();
    COPY_OTHER(resp_qEnUS);
};

/// ldd_logic_cmd_getOrgInfo
struct req_getOrgInfo : public _sdkcmd_base
{
    req_getOrgInfo() {
        flag = 0;
        orgID = 0;
    }

    /**
     * 正常情况下这个值不用传，如果是离线登陆，传1
     */
    int8 flag;
    int64 orgID;      ///< 组织ID orgID.
    CMD_SIZE();
};

struct resp_getOrgInfo : public _sdkrespcmd_base
{
    st_organizationInfo orgInfo;
    CMD_SIZE();
    COPY_OTHER(resp_getOrgInfo);
};

/// ldd_logic_cmd_getOrgInfos
struct req_getOrgInfos : public _sdkcmd_base
{
    req_getOrgInfos() {
        vt.clear();
    }

    std::vector<int64> vt;
    CMD_SIZE();
};

struct resp_getOrgInfos : public _sdkrespcmd_base
{
    resp_getOrgInfos() {
        orgs.clear();
    }

    std::vector<st_organizationInfo> orgs;
    CMD_SIZE();
    COPY_OTHER(resp_getOrgInfos);
};

/// ldd_cmd_getMsgCount
struct req_getMsgCount : public _sdkcmd_base
{
	req_getMsgCount() :targetId(0){}
	int64 targetId;		///< 个人或群Id
	CMD_SIZE();
};

/// ldd_cmd_getMsgCountTopN
struct req_getMsgCountTopN : public _sdkcmd_base
{
	req_getMsgCountTopN() :type(1){}
	int8 type;			///< 1.获取topN群. 2.获取topN单聊 3.获取@自己最多的topN群
	int topN;			///< 获取的数量
	CMD_SIZE();
};

struct resp_getMsgCountTopN : public _sdkrespcmd_base
{
	std::vector<int64> targetIds;		///< 返回群或个人的ID集合
	std::vector<int> counts;			///< 对应每个targetId的数目
	CMD_SIZE();
    COPY_OTHER(resp_getMsgCountTopN);
};

/// ldd_logic_cmd_AddNote
struct req_AddNote :  public _sdkcmd_base
{
    /// 添加的时候，本地附件填写全路径
    std::string loginInfo;
	st_baseNoteinfo info ;
	CMD_SIZE();
};

/// ldd_logic_cmd_getNotes
struct req_getNotes :  public _sdkcmd_base {
	 int64   beginID ;      ///< 起始消息ID offsetFlag = 0 beginID = 0时，代表从最大的消息Id进行查找
	 int32   offset ;       ///< 查询的数量(赋值为0代表查询全部)
	 int8    offsetFlag ;   ///< 偏移标志；0.消息Id由大到小偏移 1.消息Id由小到大偏移 offsetFlag.
	 CMD_SIZE();
};

struct resp_getNotes : public _sdkrespcmd_base {
	std::vector<st_baseNoteinfo>  _vt ;
	CMD_SIZE();	
    COPY_OTHER(resp_getNotes);
};

/// ldd_logic_cmd_delNotes 
struct req_delNotes : public _sdkcmd_base {
	std::vector<int64> _vt;    ///< 删除ID列表
	CMD_SIZE();
};

/// ldd_logic_cmd_editNotes 
struct req_editNotes : public _sdkcmd_base {
	/**
	 *  附件记事本只能修改标题，关键字（标签）,
	 *  文本类可以修改内容
	 *  归档字段并不能修改，需要使用归档接口
	 */
	st_baseNoteinfo  info;
	CMD_SIZE();
};

/// ldd_logic_cmd_archiveNotes
/// ldd_logic_cmd_topNote
struct req_archiveNotes : public _sdkcmd_base {
	/**
	 * 只能修改归档字段
	 */
	int64   id;         ///< 进行 归档 或 置顶 的note id
    /**
     *  低4位：表示是否归档 0. 不归档，1. 归档
     *  高4位：表示是否置顶 0. 不置顶，1. 置顶
     */
	int8    isArchive;  ///< 是否归档 或 置顶
	CMD_SIZE();
};

/// ldd_logic_cmd_searchNote 
struct req_searchNotes : public _sdkcmd_base {
    req_searchNotes() :
        isNet(false),
        beginID(0),
        offset(0),
        offsetFlag(0),
        type(0),
        is_all(0), 
        is_archive(0) {}

    bool isNet;         ///< 是否使用网络接口
    /**
     * 下面3个字代表查找范围
     */
    int64 beginID;      ///< 起始消息ID, offsetFlag = 0 beginID = 0时，代表从最大的消息Id进行查找
    int32 offset;       ///< 查询的数量(赋值为0代表查询全部)
    int8  offsetFlag;   ///< 偏移标志；0.消息Id由大到小偏移 1.消息Id由小到大偏移 offsetFlag.

    int8 type;          ///< 1:只需给is_all赋值; 2:只需给is_archive赋值; 3:只需给key赋值;
    /**
     * 下面3个字段每次只能给一个字段赋值，剩余2个字段不用赋值
     */
    int8 is_all;        ///< 1:获取全部
    int8 is_archive;    ///< 1:获取未归档 2:获取已经归档
    std::string key;    ///< 根据关键词查找

    std::map<std::string, std::string> params;  ///< 网络查询参数
    CMD_SIZE();
};

/// mail
struct req_mailMsgCom : public _sdkcmd_base {
    int64 msgID;
    CMD_SIZE();
};

struct resp_mailMsgCom : public _sdkrespcmd_base {
    std::vector<st_mail> vtMailMsgs;
    CMD_SIZE();
    COPY_OTHER(resp_mailMsgCom);
};

/// ldd_logic_cmd_orgAndUserSearch
struct st_orgSearchUserInfo{
    st_entpriseUserInfo uBean;
    std::string oPower;
};

struct req_orgAndUserSearch : public _sdkcmd_base {
    req_orgAndUserSearch() :
        type(0),
        userID(0),
        pageNum(0),
        pageSize(0) {
            orgIDs.clear();
        }

    int8  type;                                 /// 4：组织机构模糊查找 5：搜索人员接口
    int64 userID;                               /// 用户ID
    std::string name;                           /// 名称
    int32 pageNum;                              /// 页码
    int32 pageSize;                             /// 页长	
    std::vector<int64> orgIDs;                  /// 选择的部门ID集合(type=5时赋值)
    CMD_SIZE();
};

struct resp_orgAndUserSearch : public _sdkrespcmd_base {
    resp_orgAndUserSearch() :
        count(0) {
            users.clear();
            orgs.clear();
        }
    int64 count;
    std::vector<st_organizationInfo> orgs;      /// 组织机构列表
    std::vector<st_orgSearchUserInfo> users;    /// 查询用户列表
    CMD_SIZE();
    COPY_OTHER(resp_orgAndUserSearch);
};

//ldd_logic_cmd_qCustomerS
struct req_qCustomerS : public _sdkcmd_base {
	req_qCustomerS() :
	type(0),
	appId(0),
	userId(0),
	CSID(0),
	status(0),
	curMaxCount(0){
	}
	/*
	* 1:判断当前用户是否为客服(入参:无; 返回 isCustomer );   2:获取客服正在服务的用户列表(入参: appId; 返回 smallUserBeans)
	* 3:获取客户池列表(入参: appId; 返回 customerPoolBeans) 4.关闭会话(入参:客服Id(CSID),userId,返回 无) 
	* 5.接入客户(入参:客服Id、userId,返回 无) 6.获取最后一条消息(入参:客服Id、userId,返回 msgBean) 
	* 7. 获取客户池大小(入参:userId,返回 customPoolCount)  8.修改客服信息(入参: 公众号appID、status、curMaxCount, 返回: 无)
	* 9.获取客服公众号信息集合(入参:无，返回smallApps)
	* 10.查询单个客服信息(入参 客服Id， 返回 customerInfo)
	*/
	int8  type;   
	int64 appId;    //公众号appID
	int64 userId;   //客户的userID
	int64 CSID;  //客服id(SmallEntAppInfo中的CSID字段)
	int8  status;  //客服接待状态 1:客服在线（可接待用户），2:客服离线（不可接待用户）
	int32 curMaxCount; //当前最大可接待数
	CMD_SIZE();
};
struct st_customerPoolBean
{
	//客户id
	int64 userID;
	//客户昵称
	std::string name;
	//客户头像
	std::string portraitURL;
	//最后一条消息
	st_msgBean message;
};
//客服信息
struct st_appCustomerServiceInfo
{	
	int64 CSID;			//客服id
	int64 appID;			 //公众号id
	int64 customerID; //客服的用户id
	int8 onlineStatus;  //在线状态1:在线，2:离线
	int32 maxReception;  //当前最大可接待数
	int32 totalReception;  //总接待数
	std::string portraitUrl;  //客服头像
	std::string nickname;  //客服昵称
	std::string extJson;	//扩展信息
	int64 createDt;			//创建时间
	int64 updateDt;	 //修改时间
};
//获取客服的公众号列表
struct st_customAppList
{
	st_tinyAppInfo appInfo;  //公众号信息
	st_msgBean msgInfo;     //最后一条消息
};
struct resp_qCustomerS : public _sdkrespcmd_base {
	resp_qCustomerS() :
	isCustomer(false),
	customPoolCount(0){
		userList.clear();
		appList.clear();
		poolList.clear();
	}
	//详细返回描述信息看 req_qCustomerS的备注
	bool isCustomer;
	int64 customPoolCount;
	std::vector<st_smallUserBean> userList;
	std::vector<st_customerPoolBean> poolList;
	st_msgBean msgBean;
	//std::vector<st_tinyAppInfo> appList;
	std::vector<st_customAppList> appList;
	st_appCustomerServiceInfo customerInfo;
	CMD_SIZE();
	COPY_OTHER(resp_qCustomerS);
};

struct req_notebook : public _sdkcmd_base {
	req_notebook()
	{
	}
	st_Notebook note;
	CMD_SIZE();
};

struct req_getNotebooks : public _sdkcmd_base {
	req_getNotebooks() :offsetFlag(0), type(0)
	{
	}
	int8 offsetFlag;	///< 偏移标志；0.由大到小偏移 1.由小到大偏移
	int8 type;			///< 查询方式 0.按id 1.按创建时间 2.按修改时间
	std::string hiddenKey;///< 隐藏密码 访问隐藏记事本用
	CMD_SIZE();
};
struct resp_getNotebooks : public _sdkrespcmd_base {
	resp_getNotebooks()
	{
		notes.clear();
	}
	std::vector<st_Notebook> notes;
	CMD_SIZE();
	COPY_OTHER(resp_getNotebooks);
};
struct req_delNotebooks : public _sdkcmd_base {
	req_delNotebooks() 
	{
		vecNoteId.clear();
	}
	std::vector<int64> vecNoteId;	/// 要删除的记事本集合
	CMD_SIZE();
};
struct req_delNotebook : public _sdkcmd_base {
	req_delNotebook(): noteId(0) {}
	int64 noteId;	/// 要删除的记事本
	std::string encryptKey;	///密钥
	CMD_SIZE();
};
struct req_editNotebookLabel : public _sdkcmd_base {
	req_editNotebookLabel() : noteId(0) {}
	int64 noteId;		/// 要修改的记事本
	std::string label;	///标签
	CMD_SIZE();
};
struct req_encryptNotebook : public _sdkcmd_base {
	req_encryptNotebook() : noteId(0), encryptType(0) {}
	int64 noteId;			/// 加密记事本
	int8 encryptType;		/// 加密方式 0.不加密 1.字符加密 2.手势加密
	std::string encryptKey;	/// 秘钥
	CMD_SIZE();
};
struct req_searchNotebook : public _sdkcmd_base {
	req_searchNotebook(){}
	std::string label;	/// 标签
	CMD_SIZE();
};
struct resp_searchNotebook : public _sdkrespcmd_base {
	resp_searchNotebook()
	{
		notes.clear();
	}
	std::vector<st_Notebook> notes;
	CMD_SIZE();
	COPY_OTHER(resp_searchNotebook);
};
struct req_noteEntry : public _sdkcmd_base {
	req_noteEntry()
	{
	}
	st_NoteEntry note;
	CMD_SIZE();
};
struct req_getNoteContents : public _sdkcmd_base {
	req_getNoteContents() : noteId(0), startId(0), offset(0), offsetFlag(0), type(0)
	{
	}
	int64 noteId;		/// 记事本Id
	int64 startId;		/// 起始消息ID offsetFlag = 0 beginID = 0时，代表从最大的消息Id进行查找
	int32 offset;       /// 查询的数量(赋值为0代表查询全部)
	int8 offsetFlag;	/// 偏移标志；0.由大到小偏移 1.由小到大偏移
	int8 type;			/// 查询方式 0.按id 1.按创建时间 2.按修改时间
	std::string encryptKey;	/// 加密秘钥
	CMD_SIZE();
};
struct req_searchNoteEntrys : public _sdkcmd_base {
	req_searchNoteEntrys() : noteId(0)
	{
	}
	int64 noteId;			/// 记事本Id
	std::string searchKey;	/// 查询内容
	CMD_SIZE();
};
struct resp_getNoteEntrys : public _sdkrespcmd_base {
	resp_getNoteEntrys()
	{
	}
	std::vector<st_NoteEntry> notes;
	CMD_SIZE();
	COPY_OTHER(resp_getNoteEntrys);
};
struct req_delNoteEntrys : public _sdkcmd_base {
	req_delNoteEntrys() {}
	std::vector<int64> vecNoteId;	/// 要删除的记事条目
	CMD_SIZE();
};
///客服消息记录信息只有保存数据库用
struct st_dbCustomMsgBean{
	st_dbCustomMsgBean() {
		toUserID = 0;
		fromeUserID = 0;
		msgType = 0;
		msgID = 0;
		lateMsgID = 0;
		time = 0;
		burnAfterReading = 0;
		status = 0x04;
		targetID = 0;
		y = 0;
		m = 0;
		d = 0;
		activeType = 0;
		relatedMsgID = 0;
		localID = 0;
		realTargetId = 0;
	}

	int64 toUserID;									///< 目标ID
	int64 fromeUserID;								///< 源ID
	std::string body;								///< 消息内容
	int32 msgType;									///< 消息类型1:html 2:文本，3:音频 4: 位置 5:图片6:文件 7:名片 8:弱提示
	int64 msgID;									///< 消息ID
	int64 lateMsgID;								///< 上一条消息ID
	int64 time;										///< 时间
	int32 burnAfterReading;							///< 阅后即焚 1为阅后即焚
	int32 status;									///< 0x01,确认可设已读.0x02\不可设已读，不计算未读,　0x04 初始值
	int64 targetID;									///< 聊天对象ID
	std::string msgProperties;						///< 消息属性
	int32 y;										///< 年
	int32 m;										///< 月
	int32 d;										///< 日
	std::string limitRange;							///< 私聊成员
	std::string format;								///< 格式化字符串（暂时是字体）
	std::string uuid;								///< 消息唯一标识
	int32 activeType;								///< 消息事件属性
	int64 relatedMsgID;								///< 关联消息ID
	int64 localID;                                  ///< 消息本地ID
	std::string relatedUsers;                       ///< @的对象
	///陌生人单聊时的来源ID，1_groupID表示传的群ID，2_orgID表示传的组织ID sourceID.
	std::string sourceID;
	///未读状态信息
	std::string unReadState;
	int64 realTargetId;  //真实的targetId及客户的id
};

/**
* \struct req_getCustomHistoryMsg 消息号: ldd_logic_cmd_getCustomHistoryMsg
* \brief 获取客户的历史消息,
*
*/
struct req_getCustomHistoryMsg : public _sdkcmd_base
{
	req_getCustomHistoryMsg() :appId(0), msgBeginID(0), msgOffset(0), userId(0)
	{
		msgType.clear();
		fromUserID.clear();
	}
	void init()
	{
		appId = 0;
		userId = 0;
		msgBeginID = 0;
		msgOffset = 0;
		msgType.clear();
		fromUserID.clear();
	}
	int64    appId;				///< 公众号Id
	int64	userId;              //客户的userID
	/**
	* \brief 起始消息ID
	*        返回的结果会包含这条消息
	如果是按消息Id查询传入查询消息的起始消息ID，如果是按消息时间查询传入查询消息的起始时间。
	*        offsetFlag = 0 msgBeginID = 0时，代表从最大的消息Id进行查找
	*   如果msgBeginID = -1,标志获取所有客服消息的最后一条消息
	*  如果msgBeginID = -2,标志获取appId对应的公众号的最后一条消息
	*/
	int64    msgBeginID;
	int32    msgOffset;			     ///< 消息偏移量 msgOffset.
	/**
	偏移标志 0.消息Id由大到小偏移 1.消息Id由小到大偏移 offsetFlag.
	如果msgBeginID代表的是消息时间的话，或上0xF0,如果是消息ID的话就不用或上0xF0
	*/
	int8     offsetFlag;
	std::vector<int16>    msgType;   ///< 消息类型,表示查询某一些类型的消息，默认为空,表示查询所有类型的消息,最多查询5种类型的消息。
	std::vector<int64>    fromUserID; ///< 发送者ID,表示只查询某一些人发的消息，默认为空，表示查询所有人的消息，最多查询10个人的消息。
	CMD_SIZE();
};
struct resp_getCustomHistoryMsg : public _sdkrespcmd_base
{
	int64   appId;			///公众号appId.
	int64   userId;           //客户用户Id 
	std::vector<st_msgBean>  _vt;
	void  init()
	{
		_vt.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_getCustomHistoryMsg);
};

struct req_getUserShield : public _sdkcmd_base {
	req_getUserShield() :
	type(0),
	value_byte(0),
	accountType(0) {
	}

	int8 type;             //thrift接口预留type，目前默认为1
	int8 value_byte;       //询为1 登录为2
	int8 accountType;      //账号类型，目前只能手机，默认为1
	std::string accounts;  //账号(手机号码)
	std::string mark;      //标识(默认不需要传值)
	CMD_SIZE();
};

struct resp_getUserShield : public _sdkrespcmd_base {
	resp_getUserShield() :
	code(0),
	shieldStatus(0) {
	}
	int32 code;            //返回码
	std::string what;      //返回实体
	std::string keyId;     //手机盾用户KEYID
	std::string eventData; //手机盾登录事件数据
	std::string expireTime;//手机盾过期时间
	int8 shieldStatus;     //手机盾激活状态(1正常，2重置，3未激活)
	CMD_SIZE();
	COPY_OTHER(resp_getUserShield);
};

/**
* \struct st_customChat
* \brief  最近联系人信息
*/
struct  st_customChat
{
	st_customChat() :
	targetID(0),
	lastMsgid(0),
	time(0),
	msgType(0),
	activeType(0),
	unreadCnt(0)
	{}

	int64 appId;				///<公众号Id
	int64 targetID;   		///< 目标用户ID targetID.
	int64 lastMsgid;        ///< 最后一次消息ID lastMsgid.
	int64 time;				///< 消息时间 time
	int8  sex;			 ///<  0保密 1男，2女
	/**
	* \brief 消息类型
	* 分为两部分
	* 1. 基本部分 messageType & 0x00FF
	*    1: html , 2:文本 , 3: 音频 , 4: 位置 , 5:图片 , 6: 文件 , 7: 名片, 8: 弱提示
	* 2. 附加部分 messageType & 0FF00
	*    0x100: 为发送带附件的消息，附件上传失败会带有此标识 如图片，文件，音频等。
	*    0x200: 为消息体本身发送失败，消息会含有此记录.
	*    0x400: 为接收到带附件的消息，接收附件失败。
	*/
	int16  msgType;
	int32  activeType;		 ///< 激活类型， 当前未用 activeType.
	int16  unreadCnt;        ///< 未读数量   unreadCnt.
	//int16  realUnReadCnt; ///< 真正的未读消息数量 = unReadCnt+弱提示消息数量+其它端同步的设备消息数量，客户端每次拉取未读用这个字段，当realUnReadCnt为0时，表示所有消息在当前设备客户端都已经看过了
	/**
	* \brief 头像
	* 推送上去只有文件名部分
	*/
	std::string avatar;
	std::string avatarUrl;  ///< 服务器全路径
	std::string nickName;	///< 显示名称 nickName.
	std::string lastMsg;    ///< 最后一条消息描述 lastMsg.
	std::string msgProp;    ///< 消息属性
	//std::string sourceID;  ///< 消息附加源
};
/**
* \struct  req_getCustomChatList   消息号: ldd_logic_cmd_customContactList
* \brief   客服联系人列表
*/
struct req_getCustomChatList : public _sdkcmd_base {
	req_getCustomChatList() :
	appId(0)
	{}
	int64 appId;
	CMD_SIZE();
};

/**
* \struct  resp_customChatList   消息号: ldd_logic_cmd_customContactList
* \brief   客服联系人列表
*/
struct   resp_customChatList : public _sdkrespcmd_base
{
	/**
	* \brief 数据包flag
	*	0x01　获取对应公众号会话列表
	* 部分更新:
	*   0x08  更新
	*	0x10  新增
	*	0x20  删除
	*/
	int8 flag; 
	std::vector<st_customChat>  _vt;
	void init()
	{
		_vt.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_customChatList);
};
/**
* \struct  req_setCustomMsgReaded   消息号: ldd_logic_cmd_setCustomMsgReaded
* \brief   设置客服消息已读
*/
struct req_setCustomMsgReaded : public _sdkcmd_base {
	req_setCustomMsgReaded() :
	appID(0),
	targetID(0),
	msgID(0)
	{}

	int64 appID;
	int64 targetID;
	int64 msgID;
	CMD_SIZE();
};

struct resp_stateColor : public _sdkrespcmd_base {
	resp_stateColor(){
		color = 0;
	}

	int  color; /// 1,没图标 2,红 3,黄 4,蓝  5,白 
	void init(){
		color = 0;
	}
	CMD_SIZE();
	COPY_OTHER(resp_stateColor);
};

}

#endif