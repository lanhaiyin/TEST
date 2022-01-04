#ifndef CMD_RESP_DEF_H
#define CMD_RESP_DEF_H

#include "cmdComDef.h"

//=================================<所有响应消息结构体>============================================//

namespace imsdk
{

/**
 * \struct  resp_setHeadImg  消息号：logic_cmd_setHeadImg
 * \brief   设置头像
 */
struct resp_setHeadImg : public _sdkrespcmd_base  
{
	std::string  thumb_json;    ///< 缩略图本地地址 thumb_json.
	std::string  orgi_json;     ///< 大图本地地址 orgi_json.
	CMD_SIZE();
	COPY_OTHER(resp_setHeadImg);
};

/**
 * \struct  resp_getBuddyVerifyType  消息号：logic_cmd_getBuddyVerifyType
 * \brief   获得好友验证信息
 */
struct resp_getBuddyVerifyType : public _sdkrespcmd_base  
{
	resp_getBuddyVerifyType() :userid(0), type(0) {}
	int64 userid;             ///< 好友ＩＤ userid.
	int8 type;                ///< value: 1：需要验证信息,2:不允许任何人添加,3:允许任何人添加，默认1 
	CMD_SIZE();
	COPY_OTHER(resp_getBuddyVerifyType);
};

/**
 * \struct  resp_UpdateHeadImg  消息号：logic_cmd_updateHeadImg
 * \brief   更新头像
 */
struct resp_UpdateHeadImg : public _sdkrespcmd_base  
{
	resp_UpdateHeadImg() :userid(0) {}
	int64 userid; 	          ///< 用户ＩＤ,群ＩＤ，组织ＩＤ,APPID userid.
	std::string fileName;     ///< 文件名 不包含路径 fileName.
	CMD_SIZE();
	COPY_OTHER(resp_UpdateHeadImg);
};

/**
 * \struct  resp_getBuddyInfo  消息号：logic_cmd_getBuddyInfo
 * \brief   获取好友详细信息
 */
struct resp_getBuddyInfo : public _sdkrespcmd_base 
{
	st_buddyBean info;  ///< 好友信息 info.
	void  init() 
	{
		info.info.phones.clear();
		info.info.emails.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_getBuddyInfo);
};

/**
 * \struct  resp_recvFiles  消息号：logic_cmd_recvFiles
 * \brief   文件接收
 */
struct resp_recvFiles : public _sdkrespcmd_base
{
	resp_recvFiles() :targetID(0) {}
	int64       targetID;    ///< 对方ID,有可能是群或者人 targetID.
	std::string localPath;   ///< 接收成功后文件路径 localPath.
	CMD_SIZE();
	COPY_OTHER(resp_recvFiles);
};

/**
 * \struct  resp_sendFiles  消息号：logic_cmd_sendFiles
 * \brief   文件发送
 */
struct resp_sendFiles : public _sdkrespcmd_base
{
	resp_sendFiles() :targetID(0) {}
	int64       targetID;            ///< 目标ID targetID.
	std::vector<std::string> jsonVt; ///< JSON字符串数组 jsonVt.
	CMD_SIZE();
	COPY_OTHER(resp_sendFiles);
	void  init() 
	{
		jsonVt.clear();
	}
};

/**
 * \struct  resp_getHistoryMsg  消息号：logic_cmd_getHistoryMsg
 * \brief   历史聊天消息
 */
struct resp_getHistoryMsg : public _sdkrespcmd_base 
{
	resp_getHistoryMsg() :targetID(0) {}
	int64   targetID;			///< 目标ID,群号或者用户号 targetID.
	std::vector<st_msgBean>  _vt;
	void  init() 
	{
		_vt.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_getHistoryMsg);
};

/**
* \struct  resp_getAppointMsg  消息号：logic_cmd_getAppointMsg
* \brief   指定聊天消息
*/
struct resp_getAppointMsg : public _sdkrespcmd_base
{
	resp_getAppointMsg() :targetID(0) {}
    int64 targetID;			///< 目标ID,群号或者用户号 targetID.
    std::vector<st_msgBean>  _vt;
    void  init()
    {
        _vt.clear();
    }
    CMD_SIZE();
	COPY_OTHER(resp_getAppointMsg);
};

/**
 * \struct  resp_reContactList   消息号: logic_cmd_reContactList
 * \brief   联系人列表
 */
struct   resp_reContactList : public _sdkrespcmd_base 
{
	/**
	 * \brief 数据包flag
	 * 全部更新:
	*	0x01　第一个包,　　 需要清理原来的数据
	*	0x02  中间的包，　　在原来的数据后面追加
	*	0x04  最后的包，　　最近会话发送完毕
	* 部分更新:
	*   0x08  更新
	*	0x10  新增
	*	0x20  删除
	* 全部删除
	*   0x40 删除所有最近联系人
	 */
	int8 flag;               //包含0x01(第一个包), 0x02(后面还有数据包),0x04(最后一个数据包) flag.
	std::vector<st_reContact>  _vt;
	void init() 
	{
		_vt.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_reContactList);
};

/**
 * \struct  resp_transferMsg   消息号: logic_cmd_transMessage
 * \brief   转发信息
 */
struct  resp_transferMsg : public _sdkrespcmd_base
{
	resp_transferMsg() :sendTime(0) {}
	std::string what;
	int64  sendTime;
	CMD_SIZE();
	COPY_OTHER(resp_transferMsg);
};

/**
 * \struct  resp_sendMessage   消息号: logic_cmd_sendMessage
 * \brief   发送信息
 */
struct  resp_sendMessage : public _sdkrespcmd_base
{
	resp_sendMessage()
	{
		init();
	}
	std::string what;
	int64 messageID;       ///< 服务端发送消息ID
	int64 sendTime;        ///< 服务端发送消息时间
	int64 lastMessageID;   ///< 服务端上次发送消息ID
	std::vector<std::string> badwordList; ///< 如果发送的消息包含敏感词，返回敏感词的集合。用于一步发送文件消息时，为文件的远程url,按原图-缩略图-原图。。排列
	int8 badwordType;      ///< 0不过滤 1使用*号 2禁止发送
	int64 docid;
	void init()
	{
		messageID = 0;
		sendTime = 0;
		lastMessageID = 0;
		badwordType = 0;
		badwordList.clear();
		docid = 0;
	}
	CMD_SIZE();
	COPY_OTHER(resp_sendMessage);
};

/**
* \struct  resp_GroupDocFile   消息号: logic_cmd_GroupDocFile  ErrorInfo, std::string what,int64, int64 ,int64 ,int32
value64_1:
本次操作返回的版本号
value64_2:
群文档占用空间总字节数
value32_1:
群文档数量
* \brief   发送信息
*/
struct  resp_GroupDocFile : public _sdkrespcmd_base
{
	resp_GroupDocFile()
	{
		init();
	}
	std::string what;
	int64 version;       ///< 本次操作返回的版本号
	int64 totalsize;        ///< 群文档占用空间总字节数
	int32 GroupDocTotal;   ///< 群文档数量
	int8 status;
	std::vector<st_GroupDocAttribute> docs;
	void init()
	{
		version = 0;
		totalsize = 0;
		GroupDocTotal = 0;
		status = 0;
	}
	CMD_SIZE();
	COPY_OTHER(resp_GroupDocFile);
};
struct  resp_AddGroupDocFile : public _sdkrespcmd_base
{
	resp_GroupDocFile groupdocfile;
	resp_sendMessage respsmessage;
	CMD_SIZE();
	COPY_OTHER(resp_AddGroupDocFile);
};

/**
 * \struct  resp_sendMessageExt   消息号: logic_cmd_sendMessageExt
 * \brief   发送信息
 */
struct  resp_sendMessageExt : public resp_sendMessage
{
    /* nothing */
};

/**
 * \struct  resp_SearchResult   消息号: logic_cmd_simpleSearch
 * \brief   搜索
 */
struct resp_SearchResult : public _sdkrespcmd_base
{
	resp_SearchResult()
	{
		init();
	}

	int8 type;										///< 1 搜索联系人 2搜索群 3搜索团队 type.
	std::string what;
    std::string key;                                ///< 搜索关键字
	std::vector<st_smallUserBean> vtub;       		///< 用户列表 vtub.
	std::vector<st_groupBean> vtgroup;  		    ///< 群列表 vtgroup.
	std::vector<st_localSearchMemberInfo> vtMem;    ///< 群成员
    std::vector<st_entInfo> vtent;     	            ///< 企业列表 vtent.
	std::vector<st_orGroupinfo> vtOrgroup;     	    ///< 企业组织列表 vtOrgroup.
	std::vector<st_orgUserinfo> vtorgUser;      	///< 组织用户列表 vtorgUser
	std::vector<st_entAppinfo> vtEntApp;       	    ///< 企业应用列表 vtEntApp
	void push_orgUserinfo(const st_orgUserinfo & st) 
	{
		st_orgUserinfo tmp = st ;
		vtorgUser.push_back(tmp);
	}
	void init() 
	{
		_sdkrespcmd_base::init();
		vtub.clear();
		vtgroup.clear();
		vtMem.clear();
		vtent.clear();
		vtEntApp.clear();
		vtOrgroup.clear();
		vtorgUser.clear();

	}
	CMD_SIZE();
	COPY_OTHER(resp_SearchResult);
};

/**
* \struct  resp_mKSearchResult   消息号: logic_cmd_mKeysSearch
* \brief   多关键字搜索
*/
struct resp_mKSearchResult : public _sdkrespcmd_base
{
	int8 type;										///< 1 搜索联系人 2搜索群 3搜索团队 type.
	std::string what;
	std::vector<std::string> key;                   ///< 搜索关键字
	std::vector<st_smallUserBean> vtub;       		///< 用户列表 vtub.
	std::vector<st_groupBean> vtgroup;  		    ///< 群列表 vtgroup.
	std::vector<st_localSearchMemberInfo> vtMem;    ///< 群成员
	std::vector<st_entInfo> vtent;     	            ///< 企业列表 vtent.
	std::vector<st_orGroupinfo> vtOrgroup;     	    ///< 企业组织列表 vtOrgroup.
	std::vector<st_orgUserinfo> vtorgUser;      	///< 组织用户列表 vtorgUser
	std::vector<st_entAppinfo> vtEntApp;       	    ///< 企业应用列表 vtEntApp
	void push_orgUserinfo(const st_orgUserinfo & st)
	{
		st_orgUserinfo tmp = st;
		vtorgUser.push_back(tmp);
	}
	void init()
	{
		type = 0;
		vtub.clear();
		vtgroup.clear();
		vtMem.clear();
		vtent.clear();
		vtEntApp.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_mKSearchResult);
};
/**
 * \struct  resp_getBuddyOnlineResult   消息号: logic_cmd_getBuddyOnline
 * \brief  
 */
struct resp_getBuddyOnlineResult : public _sdkrespcmd_base 
{
	std::string   what;
	std::vector<st_onlineState> obs;
	void init() 
	{
		obs.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_getBuddyOnlineResult);
};

/**
* \struct  resp_getBuddyOnlineExResult   消息号: logic_cmd_getBuddyOnlineEx
* \brief
*/
struct resp_getBuddyOnlineExResult : public _sdkrespcmd_base
{
	std::string   what;
	std::map<int64, std::vector<st_onlineState>> obs;
	void init()
	{
		what = "";
		obs.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_getBuddyOnlineExResult);
};

/**
* \struct  resp_regBuddyOnlineResult   消息号: logic_cmd_regBuddyOnline
* \brief
*/
struct resp_regBuddyOnlineResult : public _sdkrespcmd_base
{
    std::string   what;
    st_onlineState os;

    void init()
    {
        os.userID     = 0;
        os.deviceType = 0;
        os.flag       = 0;
        os.operTime   = 0;
        os.userID     = 0;
		os.nStatus    = 0;
		os.szExplain  = "";
    }
    CMD_SIZE();
    COPY_OTHER(resp_regBuddyOnlineResult);
};

/**
 * \struct  resp_getMyself   消息号: logic_cmd_getMyself
 * \brief  获取自身信息
 */
struct resp_getMyself : public _sdkrespcmd_base
{
	std::string what;
	st_userBean user;
	void init() 
	{
		user.init();
	}
	CMD_SIZE();
	COPY_OTHER(resp_getMyself);
};

/**
 * \struct  resp_getUserFromID   消息号: logic_cmd_getUser
 * \brief  通过ID获得用户
 */
struct   resp_getUserFromID : public _sdkrespcmd_base
{
	std::string       entExtend;
	st_smallUserBean  user;
	void init()
	{
		user.emails.clear();
		user.phoneNums.clear();
		user.accounts.clear();
		user.init();
		user.srvName = "";
		user.userID = 0;
	}
	CMD_SIZE();
	COPY_OTHER(resp_getUserFromID);
};

/**
 * \struct  resp_buddyList   消息号: logic_cmd_buddylist
 * \brief  好友列表
 */
struct resp_buddyList : public _sdkrespcmd_base
{
	/**
	  * \brief
	  * 0x01 包含此标识，清空ＵＩ列表插入下面列表项
	  * 0x02　包含此标识，ＵＩ列表尾部添加下面列表项
	  * 0x04 包含此标识，所有好友添加完毕
	  * 0x08 包含此标识，从当前ＵＩ列表中更新下面列表项　不和其他标识组合
	  * 0x10 包含此标识，从当前ＵＩ列表中删除下面列表项　不和其他标识组合
	  */
	int32  flag;
	std::vector<st_tinyBuddyBean>  tub;		 ///< 用户列表 tub.
	void  init() 
	{
		flag = 0;
		tub.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_buddyList);
};

/**
 * \struct  resp_getHiddenAccountNew   消息号: logic_cmd_getHiddenAccountNew
 * \brief  通过密码得到隐藏的好友或群Id
 */
struct resp_getHiddenAccountNew : public _sdkrespcmd_base
{
	resp_getHiddenAccountNew() :flag(0){}
	std::vector<int64> hiddenIds;			    ///< 隐藏好友或群ID集合.
	int8 flag;								///< 1代表存在此隐藏好友密码，0代表不存在.

	void init()
	{
		hiddenIds.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_getHiddenAccountNew);
};

/**
 * \struct  resp_buddyList   消息号: 
 * \brief  隐藏好友或群组
 */
struct resp_HiddenPWDResult : public _sdkrespcmd_base
{
	std::string what;			///< 出错信息 tub.
	int64 timestamp;			///< 时间戳 timestamp.
	std::map<std::string, std::vector<int64> >  haccounts;  ///< 隐藏的ID,key为密码，value为隐藏的id集合 hacounts.

	void init()
	{
		timestamp = 0;
		haccounts.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_HiddenPWDResult);
};

/**
 * \struct  resp_Progress   消息号: logic_cmd_progress
 * \brief  进度消息结构,主要用于sdk库执行期间返回一些描述信息
 *         该消息的localID为执行命令的消息localID
 */
struct resp_Progress : public _sdkrespcmd_base
{
	resp_Progress(): extra_req(0), progess(0) {}
	int32 extra_req;       ///< 额外的请求信息 extra_req.
	int32 progess;         ///< 进度百分比 progess.
	std::string info;      ///< 描述信息 info.
	CMD_SIZE();
	COPY_OTHER(resp_Progress);
};

/**
 * \struct  resp_upgrade   消息号: logic_cmd_upgrade
 * \brief  系统升级
 */
struct resp_upgrade : public _sdkrespcmd_base 
{
	std::string hasCode;	///< 升级包的HAXI值.
	int8 gradeType;			///< 升级类型 0建议升级,1强制升级 gradeType.
	std::string version;    ///< 服务器版本号 version.
	std::string updateAddr; ///< 旧升级的地址.
	std::vector <st_updateInfo> newUpdateAddr;///<新的预登录升级信息
	std::string desc;		///< 升级描述信息.
	std::string clientInfo ; ///< 客户端信息

    void init()
    {
		gradeType = 0;
        newUpdateAddr.clear();
    }
	CMD_SIZE();
	COPY_OTHER(resp_upgrade);
};


/**
 * \struct  resp_regResult1   消息号: logic_cmd_reg1，logic_cmd_resetPw1
 * \brief  注册1，找回密码1
 */
struct resp_regResult1 : public _sdkrespcmd_base 
{
	resp_regResult1() :registryID(0), reregistryTimeout(0), inviteCodeID(0) {}
	std::string  	what;
	int64         	registryID;
	std::string  	sendNumber;
	int32           reregistryTimeout;
	std::string  	nation;
    int64           inviteCodeID;
	CMD_SIZE();
	COPY_OTHER(resp_regResult1);
};

/**
 * \struct  resp_regResult2   消息号: logic_cmd_reg2，logic_cmd_resetPw2
 * \brief  注册2，找回密码2
 */
struct resp_regResult2 : public _sdkrespcmd_base
{
	resp_regResult2() :registryID(0), userID(0), inviteUserID(0) {}
	int64         	registryID; ///< 第二步传入的注册编号 registryID.
	int64           userID;     ///< 用户ID   userID.
	int64			inviteUserID;	///邀请码创建者ID
	std::string  	what;       ///< 错误描述，当前无用 what.
	std::string  	usr;        ///< 注册的用户名 usr.
	CMD_SIZE();
	COPY_OTHER(resp_regResult2);
};

/**
 * \struct  resp_verifyImg   消息号: logic_cmd_Verfiyimg
 * \brief  验证码返回
 */
struct  resp_verifyImg : public _sdkrespcmd_base 
{
	resp_verifyImg() :type(0) {}
	int8 type;		  ///< 类型 type.
	std::string what; ///< 错误描述 what.
	std::string img;  ///< 图片地址 img.
	CMD_SIZE();
	COPY_OTHER(resp_verifyImg);
};

/**
 * \struct  resp_LoginResultBean   消息号: logic_cmd_login
 * \brief  登录
 * 如果在登录状态下收到该结构体的CODE不为零，要跳回到登录界面
 */
struct resp_LoginResultBean : public _sdkrespcmd_base
{
	resp_LoginResultBean()
	{
		init();
	}
	int64 userid;					  ///< 用户ID userid.
	std::string what;                 ///< code非零的情况下有效 what.
	std::string verImgPath;           ///< 验证码 verImgPath.
	std::string area;                 ///< 地区 area.
	int32 sessionTimeout;             ///< 超时时间 sessionTimeout.
	int64 serverTime;                 ///< 服务器时间 serverTime.
	int64 remainLockTime;             ///< 账号锁定剩余时长,只有在账号被锁定时才有效
    int64 inviteUserID;
	int64 registerTime;				  ///< 用户注册时间
	int8 value_byte;					///< 二维码加好友开关
	std::string extinfo;              ///登录扩展信息。（防诈骗使用）
	void init() 
	{
		userid = 0;
		sessionTimeout = 0;
		serverTime = 0;
		remainLockTime = 0;
		inviteUserID = 0;
		registerTime = 0;
		what="";
		verImgPath="";
		area="";
		value_byte = 0;
		extinfo = "";
	}
	CMD_SIZE();
	COPY_OTHER(resp_LoginResultBean);
};

/**
 * \struct  resp_msgBean   消息号: logic_cmd_msgStore
 * \brief  聊天消息
 */
struct resp_msgBean : public _sdkrespcmd_base
{
	st_msgBean msg;
	int64 notifyFlag;
	void init() 
	{
		notifyFlag = 0;
		msg.limitRange.clear();
		msg.relatedUsers.clear();
		msg.unReadState.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_msgBean);
};

/**
* \struct  resp_notifyJsonMessageBean   消息号: logic_cmd_jsonMessageBean
* \brief   朋友圈消息推送
*/
struct resp_notifyJsonMessageBean : public _sdkrespcmd_base
{
	void init()
	{
		msgType = 0;
		respJson = "";
	}
	int16 msgType;	      ///< 类型  1、朋友圈未读数量
	std::string respJson; ///< 接受内容json串
	CMD_SIZE();
	COPY_OTHER(resp_notifyJsonMessageBean);
};

/**
 * \struct  resp_present   消息号: 
 * \brief  上下线消息
 */
struct resp_present : public _sdkrespcmd_base
{
	resp_present() :userID(0), deviceType(0), flag(0), operateDate(0),nStatus(0) 
	{
		szExplain = "";
	}
	int64 userID; ///< 上下线的用户ID userID.
	/**
	 * \brief 设备类型
	 * 1：PC；2：手机；3：pad；4：网页
	 */
	int8  deviceType;
	/**
	 * brief 设备标识
	 * -1：离线，1:在线；2:隐身,3:忙碌,4:离开,5:请勿打扰,6:想聊天
	 */
	int8  flag;
	std::string deviceInfo;
	///最后在线时间
	int64 operateDate;
	int8 nStatus;
	std::string szExplain;
	CMD_SIZE();
	COPY_OTHER(resp_present);
};

struct resp_qVerifyCodes : public _sdkrespcmd_base
{
	resp_qVerifyCodes()
	{
		failRet.clear();
		shareInfo.clear();
	}
	void init()
	{
		userId = 0;
		registerInfo = "";
		versionFlag = "";
		failRet.clear();
		value_byte = 0;
		shareInfo.clear();
	}

	std::map<int64, std::string> failRet;  ///< 失败的用户ID及失败原因
	std::string what;
	int64 userId;                          ///< 用户ID
	std::string registerInfo;              ///< 注册人数相关信息
	int8 value_byte;					//二维码分享添加好友开关  [10/28/2020 admin]
	std::string retExtData;			//好社工获取二维码
	std::string versionFlag;        //服务器版本标志（V5.19.0）
	std::vector<st_shareList> shareInfo;    //用户邀请码分享列表
};

struct resp_qMsgStores : public _sdkrespcmd_base
{
	void init()
	{
		msgStatusCount.clear();
		mucs.clear();
		maxReadID = 0;
	}
	/*表示返回对应类型的消息的userID列表
		key = "readCount"  表示已读消息用户ID集合
		key = "unReadCount" 表示未读消息用户ID集合
		key = "unPushCount" 表示未推送消息用户ID集合
	*/
	std::map<std::string, std::vector<int64> > msgStatusCount;  
	std::vector<st_msgUnreadCounter> mucs;
	int64 maxReadID;			///< 最大已读消息ID
};

/**
* \struct  resp_delayFiles   消息号: logic_cmd_delayFiles
* \brief  文件延期
*/
struct resp_delayFiles : public _sdkrespcmd_base
{
	resp_delayFiles()
	{
		fileUrls.clear();
		delayCode = 0;
	}
	void init()
	{
		fileUrls.clear();
		delayCode = 0;
	}
	///< 当入参delayType=1时，0.全部未过期   1.部分过期   -1.链接地址错误 -2.传的delayType错误
	///< 当入参delayType=2时，0.全部延期成功 1.部分延期成功 -1.链接地址错误 -2.传的delayType错误
	int32 delayCode; 
	std::vector<std::string> fileUrls; ///过期的文件链接路径
	CMD_SIZE();
	COPY_OTHER(resp_delayFiles);
};

/**
* \struct  resp_serverFileValidDays   消息号: logic_cmd_serverFileValidDays
* \brief  文件有效期
*/
struct resp_serverFileValidDays : public _sdkrespcmd_base
{
	resp_serverFileValidDays()
	{
		nIndiviValidDays = 0;
		nGroupValidDays = 0;
	}
	void init()
	{
		nIndiviValidDays = 0;
		nGroupValidDays = 0;
	}
	int64 nIndiviValidDays;
	int64 nGroupValidDays;
	CMD_SIZE();
	COPY_OTHER(resp_serverFileValidDays);
};

/**
* \struct  resp_fileExpirySoon   消息号: logic_cmd_fileExpirySoon
* \brief  未下载即将过期文件列表
*/
struct resp_fileExpirySoon : public _sdkrespcmd_base
{
	//int64 targetID;
	std::map<int64, std::vector<st_FileExpirySoon>> fileResult;
	void init()
	{
		//targetID = 0;
		fileResult.clear();
	}


	//std::vector<std::string> fileUrls; ///即将过期的文件链接路径
	CMD_SIZE();
	COPY_OTHER(resp_fileExpirySoon);
};

/**
* \struct  resp_fileExpirySoonResult   消息号: logic_cmd_fileExpirySoonResult
* \brief  未下载即将过期文件列表
*/
struct resp_fileExpirySoonResult : public _sdkrespcmd_base
{
	std::vector<st_FileExpirySoonResult> fileResult;
	void init()
	{
		fileResult.clear();
	}

	CMD_SIZE();
	COPY_OTHER(resp_fileExpirySoonResult);
};

/**
* \struct  resp_fileExpiryInfoStore   消息号: logic_cmd_fileExpiryInfoStore
* \brief  未下载即将过期文件信息存储
*/
struct resp_fileExpiryInfoStore : public _sdkrespcmd_base
{

	std::vector<st_FileExpiryInfoStore> fileStore;
	void init()
	{
		fileStore.clear();
	}

	CMD_SIZE();
	COPY_OTHER(resp_fileExpiryInfoStore);
};

/**
* \struct  resp_fileExpiryInfoAsk   消息号: logic_cmd_fileExpiryInfoAsk
* \brief  未下载即将过期文件信息获取
*/
struct resp_fileExpiryInfoAsk : public _sdkrespcmd_base
{
	std::vector<st_FileExpiryInfoAsk> fileResult;
	void init()
	{
		fileResult.clear();
	}

	CMD_SIZE();
	COPY_OTHER(resp_fileExpiryInfoAsk);
};

/**
* \struct  resp_queryUserIsExistList   消息号: logic_cmd_queryUserIsExistList
* \brief  查询目标ID是否在用户的黑/白名单中
*/
struct resp_queryUserIsExistList : public _sdkrespcmd_base
{
	resp_queryUserIsExistList()
	{
		queryResult = 0;
	}
	void init()
	{
		queryResult = 0;
	}
	int8 queryResult;  ///< 1.在名单中, 2.不在名单中
	CMD_SIZE();
	COPY_OTHER(resp_queryUserIsExistList);
};
/**
* \struct  resp_accountQueryUserID   消息号: logic_cmd_accountQueryUserID
* \brief  根据用户账号批量userID
*/
struct resp_accountQueryUserID : public _sdkrespcmd_base
{
	resp_accountQueryUserID()
	{
		userIDS.clear();
	}
	void init()
	{
		userIDS.clear();
	}
	std::map<std::string, int64> userIDS;   ///(key:type+"-"+contactInfo+"-"+SDKID, value:UserID)
};

//=================================<推送消息>============================================//

/**
 * \struct  resp_groupNotify   消息号: logic_cmd_groupRefresh
 * \brief  群刷新
 */
struct resp_groupNotify : public _sdkrespcmd_base
{

	void init()
	{
		group.init();
		operType = 0;
		userID = 0;
	}

	int8  operType;	            ///< 操作类型 1：添加 2：更新，31：解散 32：移除 33：退出 operType 35：禁言或取消禁言.
	int64 userID; 	 			///< 操作人信息 userID.
	std::string  userName;      ///< 操作人姓名 userName.
	st_groupBean group;         ///< 群信息 group.
	CMD_SIZE();
	COPY_OTHER(resp_groupNotify);
};


/**
* \struct  resp_groupNotify   消息号: logic_cmd_groupRefresh
* \brief  群文档刷新
*/
struct resp_gdocNotify : public _sdkrespcmd_base
{

	void init()
	{
		locapath.clear();
		docid = 0;
		status = 0;
		updateat = 0;
		groupid = 0;
	}

	int64 groupid;
	int64 docid;          //文件id
	std::string locapath;        //本地路径
	int8 status;//状态值
	int64 updateat;// 更新时间

	CMD_SIZE();
	COPY_OTHER(resp_gdocNotify);
};

/**
 * \struct  resp_reqBuddy   消息号: logic_cmd_buddyreqVerBox
 * \brief  服务器主动推送消息
 */
struct resp_reqBuddy : public _sdkrespcmd_base
{
	int64  			 ts  ;   ///< UI不用 ts.
	st_buddyReqBean  brq ;   ///< 添加好友结构 brq.
	void init() 
	{
		ts = 0;
		brq.reqUserBean.phoneNums.clear();
		brq.reqUserBean.emails.clear();
		brq.verifyInfo.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_reqBuddy);
};

/**
 * \struct  resp_respBuddy   消息号: logic_cmd_buddyRespVerifybox
 * \brief  
 */
struct  resp_respBuddy : public _sdkrespcmd_base
{
	int64            ts;    ///< UI不用 ts.
	st_buddyRespBean brq;   ///< 好友响应结构 brq.
	void init() {
		ts = 0;
		brq.respUserBean.phoneNums.clear();
		brq.respUserBean.emails.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_respBuddy);
};

/**
 * \struct  resp_pushMessage   消息号: logic_cmd_pushMessage
 * \brief  推送消息（复杂应用）
 */
struct  resp_pushMessage : public _sdkrespcmd_base 
{
    resp_pushMessage() :
        previousMsgID(0),
        msgType(0),
        msgID(0),
        createUserID(0),
        fromTeamID(0),
        originalMsgID(0),
        status(0),
        createTime(0),
        operType(0),
        havVaild(0) {}

	int64 previousMsgID;
	int8  msgType;
	int64 msgID;
	int64 createUserID;
	int64 fromTeamID;
	std::vector<int64>  targetUserIDs;
	std::string title;
	std::string body;
	std::string format;
	int64 originalMsgID;
	int8 status;
	int64 createTime;
	int8 operType;
	std::string maccode;
	int8 havVaild;
	void init() 
	{
		targetUserIDs.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_pushMessage);
};

/**
 * \struct  resp_operBuddy   消息号: logic_cmd_operateBuddy
 * \brief  操作好友
 */
struct resp_operBuddy : public _sdkrespcmd_base 
{
	int8 operType;			///< 1: add 2: update，3: delete operType.
	st_tinyBuddyBean  tub;
	void init() 
	{
		operType = 0;
		tub.init();
	}
	CMD_SIZE();
	COPY_OTHER(resp_operBuddy);
};

/**
 * \struct  resp_operUser   消息号: logic_cmd_operateUser
 * \brief  操作自己
 */
struct resp_operUser : public _sdkrespcmd_base  
{
	st_userBean  user;
	void init() 
	{
		user.init();
	}
	CMD_SIZE();
	COPY_OTHER(resp_operUser);
};

/**
 * \struct  resp_reqGroup   消息号: logic_cmd_reqGroup
 * \brief  群管理收到请求，添加等请求
 */     
struct resp_reqGroup : public _sdkrespcmd_base {
	int64 reqID;
	int64 reqUserID;
	int64 groupID;
	std::string verifyInfo;
	int8  reqType;
	int64 reqTime;
	int8  status;
	std::string groupName;
	std::string groupIcon;
	std::string groupType;
	std::vector<int64>  inviteUsers;
	void init() 
	{
		reqID = 0;
		reqUserID = 0;
		groupID = 0;
		reqType = 0;
		reqTime = 0;
		status = 0;
		inviteUsers.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_reqGroup);
};

/**
 * \struct  resp_createGroup   消息号: logic_cmd_createGroup
 * \brief  创建群
 */  
struct resp_createGroup : public _sdkrespcmd_base
{
	int64 groupid;   ///< 群ＩＤ groupid.
	std::vector<st_buddyBean> inviteVerifyUserList; //进群需要验证的用户集合
	std::vector<st_buddyBean> inviteNotAllowUserList;//不接受进群的用户集合
	std::vector<st_buddyBean> inviteAddUserList;//可以直接进群的用户集合
	std::vector<st_buddyBean> inviteAdminVerifyUserList;//需要管理员验证的用户集合
	void init(){
		groupid = 0;
		inviteVerifyUserList.clear();
		inviteNotAllowUserList.clear();
		inviteAddUserList.clear();
		inviteAdminVerifyUserList.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_createGroup);
};

/**
 * \struct  resp_getGroupList   消息号: logic_cmd_getGroups
 * \brief  获取群列表返回
 */
struct resp_getGroupList : public _sdkrespcmd_base
{
	std::vector<st_tinyGroupBean> groups;
	void init() 
	{
		groups.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_getGroupList);
};

/**
 * \struct  resp_groupResponseResult   消息号: 
 * \brief  
 */
struct resp_groupResponseResult : public _sdkrespcmd_base
{
	resp_groupResponseResult() :result(0) {}
	int32 result;				///< 多个管理员处理的时候，如果已经处理了，返回上一个处理结果 result.
	st_tinyUserBean user;		///< 响应人信息 user.
	resp_commonResult ret;
	CMD_SIZE();
	COPY_OTHER(resp_groupResponseResult);
};

/**
 * \struct  resp_msgList   消息号: logic_cmd_unReadmsgList
 * \brief   获取系统消息列表
 */
struct resp_msgList : public _sdkrespcmd_base
{
	std::vector<st_ureadMsgList> msglist;
	void init() 
	{
		msglist.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_msgList);
};

/**
 * \struct  resp_getGroupMemList   消息号: logic_cmd_getGroupMemList
 * \brief   群成员列表
 */
struct resp_getGroupMemList : public _sdkrespcmd_base
{
	int64   groupID;
	std::vector<st_tinyGroupMemberBean>  _vt;
	std::vector<st_tinyGroupMemberBean>newGrpMem;
	std::vector<st_tinyGroupMemberBean>updateGrpMem;
	std::map<int64,std::vector<int64> > delGrpMem;
	void init()
	{
		groupID = 0;
		_vt.clear();
		newGrpMem.clear();
		updateGrpMem.clear();
		delGrpMem.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_getGroupMemList);
};

/**
* \struct  resp_getGroupDocList   消息号: logic_cmd_getGroupDocList
* \brief   群成员列表
*/
struct resp_getGDocList : public _sdkrespcmd_base
{
	int64   groupID;
	std::vector<st_GroupDocAttribute>  _vt;

	void init()
	{
		groupID = 0;
		_vt.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_getGDocList);
};

/**
* \struct  resp_getGDocUpDownList   消息号: logic_cmd_getGDocUpDownList
* \brief   群成员列表
*/
struct resp_getGDocUpDownList : public _sdkrespcmd_base
{
	int64   groupID;
	std::vector<st_GroupDocUpdownInfo>  _vt;

	void init()
	{
		groupID = 0;
		_vt.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_getGDocUpDownList);
};


/**
 * \struct  resp_getGroupInfo   消息号: logic_cmd_getGroupInfo
 * \brief   获取群详细信息
 */
struct resp_getGroupInfo : public _sdkrespcmd_base
{
	st_groupBean group;
	void init()
	{
		_sdkrespcmd_base::init();
	}
	CMD_SIZE();
	COPY_OTHER(resp_getGroupInfo);
};

/**
 * \struct  resp_getGroupSet   消息号: logic_cmd_getGroupSet
 * \brief   获取群验证方式
 */
struct resp_getGroupSet : public _sdkrespcmd_base
{
	st_groupSet gs;
	void init()
	{
		_sdkrespcmd_base::init();
	}
	CMD_SIZE();
	COPY_OTHER(resp_getGroupSet);
};

/**
 * \struct  resp_getGroupMemberInfo   消息号: logci_cmd_getGroupMemberInfo
 * \brief   获取群成员信息
 */
struct resp_getGroupMemberInfo : public _sdkrespcmd_base
{
	st_groupMemberBean member;
	CMD_SIZE();
	COPY_OTHER(resp_getGroupMemberInfo);
	void init()
	{
		member.birthday = 0;
		member.name = "";
		member.nickID = "";
		member.sign = "";
		member.phones.clear();
		member.emails.clear();
		member.info.init();
	}
};

/**
 * \struct  resp_setGroupMemberInfo   消息号: logic_cmd_setGroupMemberInfo
 * \brief   设置群成员信息
 */
struct resp_setGroupMemberInfo : public _sdkrespcmd_base
{
	st_groupMemberBean member;
	CMD_SIZE();
	COPY_OTHER(resp_setGroupMemberInfo);
};

/**
 * \struct  resp_getGroupShieldInfo   消息号: logic_cmd_getShieldGroupMessage
 * \brief   获取群消息提示方式
 */
struct resp_getGroupShieldInfo : public _sdkrespcmd_base
{
	int8  receiveMsgType;     ///< 1：提示并接收消息；2：不提示，接收仅显示数目；3：屏蔽消息 receiveMsgType.
	int64 groupId;			  ///< 群ID.
	std::string receiveTimePeriod;
	void init()
	{
		receiveMsgType = 0;
		receiveTimePeriod = "";
		groupId = 0;
	}
	CMD_SIZE();
	COPY_OTHER(resp_getGroupShieldInfo);
};

/**
 * \struct  resp_notifyTransGroup   消息号: logic_cmd_transferGroup
 * \brief   转移群
 */
struct resp_notifyTransGroup : public _sdkrespcmd_base
{
	resp_notifyTransGroup() :groupID(0), userID(0) {}
	int64 groupID;
	std::string groupName;
	std::string userName;   // 暂时不用.
	int64 userID;           // 转让群后，新的群主ID.
	CMD_SIZE();
	COPY_OTHER(resp_notifyTransGroup);
};

/**
 * \struct  resp_groupMemberInfoRefresh   消息号: logic_cmd_groupMemberInfoRefresh
 * \brief   群成员信息刷新
 */
struct resp_groupMemberInfoRefresh : public _sdkrespcmd_base
{
	void init()
	{
		groupID = 0;
		info.init();
	}

	int64 groupID;
	st_tinyGroupMemberBean info;
	CMD_SIZE();
	COPY_OTHER(resp_groupMemberInfoRefresh);
};

/**
 * \struct  resp_groupMembersRefresh   消息号: logic_cmd_groupMemberInfoRefresh
 * \brief   所有群成员信息刷新
 */
struct resp_groupMembersRefresh : public _sdkrespcmd_base
{
	int8  operType;                         ///< 1 添加， 32 移除， 33 退出 operType.
	int64 groupID;
	std::vector<st_tinyGroupMemberBean> infos;
	void init()
	{
		operType = 0;
		groupID = 0;
		infos.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_groupMembersRefresh);
};

/**
 * \struct  resp_sendImg   消息号: logic_cmd_sendImg
 * \brief   发送图片
 */
struct resp_sendImg : public _sdkrespcmd_base 
{
	resp_sendImg() :targetID(0) {}
	int64   targetID;			///< 发送方ID targetID.
	std::string  thumb_Json;    ///< 返回缩略图JSON串 thumb_Json.
	std::string  orgi_json;     ///< 返回大图JSON orgi_json.
	CMD_SIZE();
	COPY_OTHER(resp_sendImg);
};

/**
 * \struct  resp_recvImg   消息号: logic_cmd_recvImg
 * \brief   接收图片
 */
struct resp_recvImg : public _sdkrespcmd_base 
{
	resp_recvImg() :targetID(0) {}
	int64  targetID; 		    ///< 发送方对方ＩＤ targetID.
	std::string imgName;  	    ///< 本地文件路径 imgName.
	CMD_SIZE();
	COPY_OTHER(resp_recvImg);
};

/**
* \struct  resp_sendNineBoxImg   消息号: logic_cmd_sendNineBoxImg
* \brief   发送九宫格图片
*/
struct resp_sendNineBoxImg : public _sdkrespcmd_base
{
	resp_sendNineBoxImg() :targetID(0), imgIndex(0) {}
	int64   targetID;			///< 发送方ID targetID.
	std::string  thumb_Json;    ///< 返回缩略图JSON串 thumb_Json.
	std::string  orgi_json;     ///< 返回大图JSON orgi_json.
	int8 imgIndex;				///< 图片索引 0-8
	CMD_SIZE();
	COPY_OTHER(resp_sendNineBoxImg);
};

/**
* \struct  resp_recvNineBoxImg   消息号: logic_cmd_recvNineBoxImg
* \brief   接收九宫格图片，接收几张，会推送几次消息
*/
struct resp_recvNineBoxImg : public _sdkrespcmd_base
{
	resp_recvNineBoxImg() :targetID(0), imgIndex(0), imgCount(0) {}
	int64  targetID; 		    ///< 发送方对方ＩＤ targetID.
	std::string imgName;  	    ///< 本地文件路径 imgName.
	int8 imgIndex;				///< 图片索引 0-8
	int8 imgCount;				///< 总图片数
	CMD_SIZE();
	COPY_OTHER(resp_recvNineBoxImg);
};

/**
 * \struct  resp_SysMsg   消息号: logic_cmd_lastSysMsg
 * \brief   最后一条系统消息
 */
struct  resp_SysMsg : public _sdkrespcmd_base 
{
	st_sysMsg sysMsg;
	CMD_SIZE();
	COPY_OTHER(resp_SysMsg);		
};

/**
* \struct  resp_unReadSysMsg   消息号: logic_cmd_lastUnReadSysMsg
* \brief   最后一条系统消息，刚登陆上时推送
*/
struct  resp_unReadSysMsg : public _sdkrespcmd_base
{
	resp_unReadSysMsg() :unReadCount(0) {}
	st_sysMsg sysMsg;                               ///< 系统消息.
	int32 unReadCount;                              ///< 未读数量.
	CMD_SIZE();
	COPY_OTHER(resp_unReadSysMsg);
};

/**
 * \struct  resp_getSysMsgList   消息号: logic_cmd_getSysMsgList
 * \brief   获取系统消息列表
 */
struct resp_getSysMsgList : public _sdkrespcmd_base 
{
	resp_getSysMsgList() :type(0) {}
	int8      type;
	std::vector<resp_SysMsg>  sysMsgVt;
	void init()
	{
		sysMsgVt.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_getSysMsgList);
};

/**
 * \struct  resp_getIosNoticeInfo   消息号: logic_cmd_getIosRecvNoticeSettings
 * \brief   获取Ios通知信息
 */
struct resp_getIosNoticeInfo : public _sdkrespcmd_base
{
	st_iosNoticeInfo info;
	CMD_SIZE();
	COPY_OTHER(resp_getIosNoticeInfo);
};

/**
 * \struct  resp_getFileList   消息号: logic_cmd_getFileList
 * \brief   得到文件列表
 */
struct resp_getFileList : public _sdkrespcmd_base 
{
	std::vector<st_Fileinfo> _vt;
	void init() 
	{
		_vt.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_getFileList);
};

/**
 * \struct  resp_pwRuleResult   消息号: logic_cmd_getPwRule
 * \brief   得到密码规则
 *		高8位代表最小长度
 *		低8位，按照最低位开始，一次代表:(1代表必须，0 表示可选)
 *		1. 是否必须有数字
 *		2. 是否必须有小写字母
 *		3. 是否必须有大写字母
 *		4. 是否必须有英文字母
 *		5. 是否必须有字符(特殊字符)
 *		6. 是否允许注册(1允许，0不允许)
 */
struct resp_pwRuleResult : public _sdkrespcmd_base
{
	resp_pwRuleResult() :code(0), stipulate(0) {}
	int32 code;
	std::string what;
	int16 stipulate;
	CMD_SIZE();
	COPY_OTHER(resp_pwRuleResult);
};

/**
 * \struct  resp_perf   消息号:
 * \brief  
 */
struct resp_perf : public _sdkcmd_base 
{
	uint16  cmd;
	int8    type;	///< 0 请求通道处理时间,1:DB通道处理时间,2:网络通道处理时间,3,other处理时间 type.
	int32   Perf;
	void init() 
	{
		cmd = 0;
		type = 0;
		Perf = 0;
	}
	CMD_SIZE();
	COPY_OTHER(resp_perf);
};

/**
 * \struct  resp_getAppInfo   消息号: logic_cmd_getAppInfo
 * \brief   获取应用详细信息返回
 */
struct resp_getAppInfo : public _sdkrespcmd_base
{
	st_tinyAppInfo info ;
	CMD_SIZE();
	COPY_OTHER(resp_getAppInfo);
};

/**
 * \struct  resp_localSetting   消息号: logic_cmd_localSetting
 * \brief   本地配置请求返回
 */
struct resp_localSetting : public _sdkrespcmd_base
{
	int8    type ;  ///< 0 : 增加，１：查询 , 2: 修改，３：删除 type.
	/**
	 * \type 的值不同，items有不同的意义
	 * 0: items里面为空
	 * 1: items里面带查询的后的输出.
	 * 2: items里面为空
	 * 3: items里面为空
	 */
	std::vector<st_localSetting> items ;
	void init() {
		type = 0;
		items.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_localSetting);
};

/**
 * \struct  resp_netNotifyer   消息号: logic_cmd_netNotifyer
 * \brief   网络状态通知
 */
struct resp_netNotifyer : public _sdkrespcmd_base
{
	resp_netNotifyer() :type(0) {}
	int8 type ;  ///< 0是　网络ＯＫ，非零是网络异常  type.
	CMD_SIZE();
	COPY_OTHER(resp_netNotifyer);
};

/**
* \struct  resp_PullMsg   消息号: logic_cmd_PullMsg
* \brief   补链结果通知
*/
struct resp_PullMsg : public _sdkrespcmd_base
{
	int8 type;  ///< 0是　ＯＫ，非零是异常  type.
	CMD_SIZE();
	COPY_OTHER(resp_PullMsg);
};
/**
 * \struct  resp_PersonalData   消息号: logic_cmd_getPersonalData
 * \brief   获取用户个人设置
 */
struct resp_PersonalData : public _sdkrespcmd_base
{
	std::vector<st_personalData> vt; ///< 获取用户数据
    void init()
    {
    	vt.clear();
    }
    CMD_SIZE();
    COPY_OTHER(resp_PersonalData);
};

/**
 * \struct  resp_msgAmountSearch   消息号: logic_cmd_msgGlobalSearch 
 * \brief   本地消息全局搜索，只返回每个匹配到的群或个人的消息的数目。
 */
struct resp_msgGlobalSearch : public _sdkrespcmd_base
{
	std::string key;    ///< 查找的关键字.
	int64 nextTargetId; ///< 后续查找的targetId，0代表已搜索全部消息.
	std::vector<st_msgGlobalSearch> results; ///< 搜索到的targetId对象简要信息集合.
	COPY_OTHER(resp_msgGlobalSearch);
	void init()
	{
		nextTargetId = 0;
		results.clear();
	}
	CMD_SIZE();
};

/**
 * \struct  resp_msgDetailSearch  消息号: logic_cmd_msgDetailSearch 
 * \brief   在某个群或个人的聊天记录中搜索关键字。
 */
struct resp_msgDetailSearch : public _sdkrespcmd_base
{
	int64 targetId; ///< 搜索的目标Id.
	int64 nextMsgId; ///< 后续查找的消息ID，0代表已搜索全部消息.
	std::string key; ///< 查找的关键字.
	std::map<int64, st_simpleSearchInfo> senderInfos; ///< 存放此次搜索结果中的所有发送者信息,key为senderUserId.
	std::vector<st_msgBean> msgs; ///< 保存所有消息内容信息.

	void init()
	{
		targetId = 0;
		nextMsgId = 0;
		senderInfos.clear();
		msgs.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_msgDetailSearch);
};

/**
* \struct  resp_groupSearchMember  消息号: logic_cmd_groupSearchMember
* \brief   群内搜索群成员
*/
struct resp_groupSearchMember : public _sdkrespcmd_base
{
	resp_groupSearchMember()
	{
		init();
	}
	void init()
	{
		groupId = 0;
		members.clear();
	}
	int64 groupId;
	std::vector<st_tinyGroupMemberBean> members;
	CMD_SIZE();
	COPY_OTHER(resp_groupSearchMember);
};
/**
 * \struct  resp_getBWlist  消息号: logic_cmd_getBWlist 
 * \brief   获取黑名单或白名单列表。
 */
struct resp_getBWlist : public _sdkrespcmd_base
{
	std::vector<int64> memList;

	void init()
	{
		memList.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_getBWlist);
};

///**
//* \struct  resp_FileFragmentationInfo 消息号　logic_cmd_getFileFragmentationInfo
//* \brief 获取文件分片信息返回结构体
//*/
//struct resp_FileFragmentationInfo : public _sdkrespcmd_base
//{
//	resp_FileFragmentationInfo() :fileNumber(0),
//		fileID(0)
//	{}
//	int64		    fileNumber;
//	int64		    fileID;
//	std::string 	encryptKey;
//	void init()
//	{
//		encryptKey.clear();
//	}
//	CMD_SIZE();
//	COPY_OTHER(resp_FileFragmentationInfo);
//};
/**
* \struct  resp_getFileInfos 消息号　logic_cmd_getFileInfos
* \brief 得到保存文件信息
*/
struct resp_getFileInfos : public  _sdkrespcmd_base
{
	std::map<int64, st_Fileinfo> fileInfos;	 ///< 获取的文件详细信息,key为文件消息ID.

	void init()
	{
		fileInfos.clear();
	}

	CMD_SIZE();
	COPY_OTHER(resp_getFileInfos);
};

/**
* \struct  resp_getMsgByType 消息号　logic_cmd_getMsgByType
* \brief 根据消息类型获得聊天消息
*/
struct resp_getMsgByType : public  _sdkrespcmd_base
{
	std::vector<st_msgBean> msgs;		///< 返回的消息集合.

	void init()
	{
		msgs.clear();
	}

	CMD_SIZE();
	COPY_OTHER(resp_getMsgByType);
};

/**
* \struct  resp_getUrlInfo 消息号　logic_cmd_getUrlInfo
* \brief 获取网址缩略图信息
*/
struct resp_getUrlInfo : public _sdkrespcmd_base
{
	std::string url;		///< 网址.
	std::string title;		///< 解析的标题.
	std::string img;		///< 解析的图片地址.
	std::string desc;		///< 解析的摘要.

	CMD_SIZE();
	COPY_OTHER(resp_getUrlInfo);
};

/**
* \struct  resp_faceToFaceJoin 消息号　logic_cmd_faceToFaceJoin
* \brief 近距离加好友，群
*/
struct resp_faceToFaceJoin : public _sdkrespcmd_base
{	
	int8 result; ///< 1：加入或者创建成功，2：创建失败，精度、纬度、房间密码不符合要求 3：已与房主是好友关系, 4:房间不存在.
	std::string roomId; ///< 房间ID.
	std::vector<st_smallUserBean> userList; ///< 返回此房间的用户列表，主要信息用户ID,用户名，图像，如果是近距离加好友只返回房主用户信息.
	std::string randomCode; ///< 随机码,创建房间时返回.

	void init()
	{
		userList.clear();
	}
	
	CMD_SIZE();
	COPY_OTHER(resp_faceToFaceJoin);
};

/**
* \struct  resp_faceJoinGroup 消息号　logic_cmd_faceJoinGroup, logic_cmd_faceAddBuddy
* \brief 进入房间推送
*/
struct resp_faceJoinGroup : public _sdkrespcmd_base
{
	std::string roomId;			///< 房间ID.
	st_smallUserBean userInfo;	    ///< 进入房间的用户的信息.

	void init()
	{
		userInfo.emails.clear();
		userInfo.phoneNums.clear();
	}
	
	CMD_SIZE();
	COPY_OTHER(resp_faceJoinGroup);
};

/**
* \struct  resp_exitFaceJoinGroup 消息号　logic_cmd_exitFaceJoinGroup, logic_cmd_exitFaceAddBuddy
* \brief 退出房间推送
*/
struct resp_exitFaceJoinGroup : public _sdkrespcmd_base
{
	resp_exitFaceJoinGroup() :userId(0), deleteRoom(0) {}
	std::string roomId;			///< 房间ID.
	int64 userId;				    ///< 退出人员ID.
	int8 deleteRoom;			    ///< 1：退出并解散房间，其他值退出房间.

	CMD_SIZE();
	COPY_OTHER(resp_exitFaceJoinGroup);
};

/**
 *\struct resp_MessageCursor 消息号 logic_cmd_MessageCursor
 *\消息游标推送
 */
struct resp_MessageCursor :public _sdkrespcmd_base
{
	resp_MessageCursor() :userID(0), targetID(0), maxReadID(0) {}
	int64 userID;  ///<本人用户ID
	int64 targetID;///<目标ID(单聊人ID,群聊群组ID)
	int64 maxReadID;///<所有设备中最大的消息已读ID

	CMD_SIZE();
	COPY_OTHER(resp_MessageCursor);
};
/**
* \struct  resp_createFaceGroupSuccess 消息号　logic_cmd_createFaceGroupSuccess, logic_cmd_faceAddBuddyConfirm
* \brief 创建群或加好友成功后的推送
*/
struct resp_createFaceGroupSuccess : public _sdkrespcmd_base
{
	resp_createFaceGroupSuccess() :groupID(0), joinFlag(0) {}
	std::string roomId;			///< 房间ID.
	int64 groupID;				///< 群ID.
	int8 joinFlag;				///< 加入标识, 1:加入成功, 2:取消加入.

	CMD_SIZE();
	COPY_OTHER(resp_createFaceGroupSuccess);
};

/**
* \struct  resp_authenticationResult 消息号　logic_cmd_bindEmailOrPhoneNumber1
* \brief 绑定手机号第1步返回值
*/
struct resp_authenticationResult : public _sdkrespcmd_base
{
	resp_authenticationResult():reregistryTimeout(0),registryID(0){}

	int32  reregistryTimeout;			    ///< 重新发短信或邮件的间隔, 默认 60秒.
	int64  registryID;					///< 豆豆ID.
	std::string sendNumber;				///< 发送短信或者邮件的号码或者邮箱.
	std::string nation;				    ///< 国家编码, 默认是0086.

	CMD_SIZE();
	COPY_OTHER(resp_authenticationResult);
};

/**
* \struct  resp_getNoDisturbMode 消息号　logic_cmd_setNoDisturbMode
* \brief 设置全局勿扰模式开关信息
*/
struct  resp_getNoDisturbMode : public _sdkrespcmd_base
{
	resp_getNoDisturbMode() {}
	void init()
	{
		disturbList.clear();
	}

	std::vector<st_NoDisturbModeInfo> disturbList;

	CMD_SIZE();
	COPY_OTHER(resp_getNoDisturbMode);
};

/**
* \struct  resp_getUserToTargetSwitch 消息号　logic_cmd_getUserToTargetSwitch
* \brief 获取个人对目标用户的勿扰模式
*/
struct  resp_getUserToTargetSwitch : public _sdkrespcmd_base
{
	resp_getUserToTargetSwitch() :targetId(0), type(0), value1(0),value2(0)
	{
	}

	int64 targetId;	///< 用户ID.
	int8  type;		///< 设置类型 0.全部获取 1:个人设置项 2:个人通知消息详情模式.
	int8  value1;		///< 个人设置项, type为0和1时赋值， value1: 1为接收提醒 2表示不提醒仅显示数字 3:为免打扰, 默认1.
	int8  value2;		///< 个人通知消息详情模式, type为0和2时赋值, value2:1、通知详情 2、通知源，隐藏内容 3、完全隐藏 默认开启模式1.

	CMD_SIZE();
	COPY_OTHER(resp_getUserToTargetSwitch);
};

/**
* \struct  resp_postContactResult 消息号　logic_cmd_postContact
* \brief 上传通讯录返回信息
*/

struct resp_postContactResult : public _sdkrespcmd_base
{
	void init()
	{
		recommends.clear();
	}

	std::vector<st_autoAttentionBean>  autoAttents;
	std::vector<st_recommendContact>   recommends;   ///< 推荐者,那些无法自动加好友的人.                    

	CMD_SIZE();
	COPY_OTHER(resp_postContactResult);
};

/**
* \struct  resp_commonListResult 消息号　logic_cmd_getShareOptions
* \brief 前端用户得到分享列表
*/
struct resp_commonListResult : public _sdkrespcmd_base
{
	resp_commonListResult()
	{
		memList.clear();
	}
	void init()
	{
		memList.clear();
	}
	
	std::vector<int64> memList;   ///< ID列表.
	CMD_SIZE();
	COPY_OTHER(resp_commonListResult);
};

/**
* \struct  resp_getPersonDefinitionResult 消息号　logic_cmd_getPersonDefinition
* \brief 得到用户自定义一些信息
*/
struct resp_getPersonDefinitionResult : public _sdkrespcmd_base
{
	resp_getPersonDefinitionResult()
	{
		personDef.clear();
	}
	void init()
	{
		personDef.clear();
	}
	std::vector<st_personDefinition> personDef;

	CMD_SIZE();
	COPY_OTHER(resp_getPersonDefinitionResult);
};

/**
* \struct  resp_queryExtendedField 消息号　logic_cmd_queryExtendedField
* \brief  根据条件查询拓展字段信息
*/
struct resp_queryExtendedField : public _sdkrespcmd_base
{
	void init()
	{
		listEnDic.clear();
	}
	std::vector<st_enterpriseDictionary>  listEnDic;

	CMD_SIZE();
	COPY_OTHER(resp_queryExtendedField);
};

/**
* \struct resp_bkImgUpdate 消息号 logic_cmd_bkImgUpdate
* \brief 背景图片修改推送
*/
struct resp_bkImgUpdate : public _sdkrespcmd_base {
	void init() {
		;
	}
	int64   targetID ;
	std::string img ;
};

/**
* \struct resp_queryMarketApplication 消息号 logic_cmd_queryMarketApplication
* \brief 分页查询应用市场应用信息新增群应用
*/
struct resp_queryMarketApplication : public _sdkrespcmd_base
{
	st_smallMarketAppPage  marketApp;
	void init() {
		marketApp.appInfoList.clear();
		marketApp.extMap.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_queryMarketApplication);
};


/**
* \struct resp_emoticonUnionOne 消息号 logic_cmd_emoticonUnionOne
* \brief 表情包一期集合
*/
struct resp_emoticonUnionOne : public _sdkrespcmd_base
{
	resp_emoticonUnionOne()
	{
		init();
	}
	void init()
	{
		type = 0;
		vecSuccMdCode.clear();
		vecFailMdCode.clear();

		resultCode = 0;
		emoticonList.clear();
		emoticonPackageList.clear();
		timestamp = 0;
	}

	int type;   ///< 1,删除表情包 2,设置表情包已读 3,从网络获取信息增加表情包 4,从客户端获取信息增加表情包
	std::vector<std::string> vecSuccMdCode;
	std::vector<std::string> vecFailMdCode;
	st_emoticon stEmot;


	/**
	*0:操作成功
	*100026500:表情包参数错误
	*100026501:表情包添加数据库错误
	*100026502:表情包删除数据库错误
	*100026503:表情包时间戳错误
	*100026504:批量表情超过最大数量
	*100026505:表情包需要拉取
	*100026506:表情已存在
	*/
	int32 resultCode;        
	std::string resultMessage; ///< 结果信息.
	std::vector<st_emoticonResult> emoticonList;           ///< 自定义表情列表.
	std::vector<st_emoticonResult> emoticonPackageList;    ///< 表情包列表.
	int64 timestamp;              ///< 服务器返回的时间戳

	CMD_SIZE();
	COPY_OTHER(resp_emoticonUnionOne);
};

/**
* \struct resp_bkImgUpdate 消息号 logic_cmd_getInstalledApplication
* \brief 获取用户已安装列表信息
*/
struct resp_getInstalledApplication : public _sdkrespcmd_base
{
	void init() {
		appInfoList.clear();
	}
	std::vector<st_smallMarketAppInfo> appInfoList;  ///< 应用列表.
	CMD_SIZE();
	COPY_OTHER(resp_getInstalledApplication);
};
/**
* \struct resp_getEntAppInfo 消息号 logic_cmd_getEntAppInfo
* \brief 根据用户id分页获取企业号
*/
struct resp_getEntAppInfo : public _sdkrespcmd_base
{
	void init() {
		totalCount = 0;
		totalPage = 0;
		appList.clear();
	}
	int64 totalCount;                         ///< 总数量
	int64 totalPage;                          ///< 总页数
	std::vector<st_tinyAppInfo> appList;      ///< 企业号集合

	CMD_SIZE();
	COPY_OTHER(resp_getEntAppInfo);
};

/**
* \struct resp_getMarketAppSort 消息号 logic_cmd_getMarketAppSort
* \brief  获取应用市场应用分类集合
*/
struct resp_getMarketAppSort : public _sdkrespcmd_base
{
	void init()
	{
		marketSort.clear();
	}
	std::vector<st_smallMarketAppType> marketSort;
	CMD_SIZE();
	COPY_OTHER(resp_getMarketAppSort);
};
/**
* \struct resp_getAuthUserBean 消息号 logic_cmd_getAuthUserBean
* \brief 通过accessToken获取用户信息
*/
struct resp_getAuthUserBean : public _sdkrespcmd_base
{
	resp_getAuthUserBean() :userID(0), sex(0), year(0), month(0), day(0)
	{
		name = "";
		area = "";
		school = "";
		portraitURL = "";
		phoneNums.clear();
		emails.clear();
	}
	void init()
	{
		phoneNums.clear();
		emails.clear();
	}

	int64 userID;                              ///用户ID
	std::string name;                          ///用户名
	int8 sex;                                  ///性别
	std::string area;                          ///区域
	int16  year;                               ///生日
	int8   month;
	int8   day;
	std::string school;                        ///毕业学校
	std::string portraitURL;                   ///头像地址
	std::vector<std::string> phoneNums;        ///电话号码清单
	std::vector<std::string> emails;           ///邮箱清单
	CMD_SIZE();
	COPY_OTHER(resp_getAuthUserBean);
};
/**
*  \struct resp_getFileFragmentationInfo
*  \biref  获取文件分片信息返回结构体
*/
struct resp_FileFragmentationInfo : public _sdkrespcmd_base
{
	resp_FileFragmentationInfo() :fileNumber(0), burstSize(0)
	{}
	std::string   fileID;    /* 文件id*/
	int64  fileNumber;       /* 上传时总分片数 */
	std::string   fileName;  /* 文件名*/
	std::string   fileHash;  /* 文件hash */
	std::string   fileSize;  /* 文件大小 */
	std::string   filePath;  /* 文件路径 */
	int32 burstSize;         /* 分片大小 */
	std::string   encryptKey;/* 加密秘钥 */
	bool isEncrypt;
	void init()
	{
		encryptKey.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_FileFragmentationInfo);
};
/**
*  \struct resp_FileContentByFragmentIndex
*  \biref  获取文件分片内容返回结构体
*/
struct resp_FileContentByFragmentIndex : public _sdkrespcmd_base
{
	std::vector<std::string> content;			//内容

	void init()
	{
		content.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_FileContentByFragmentIndex);
};
/**
* \struct resp_queryEmoticon 消息号 logic_cmd_queryEmoticon
* \brief  单个表情查询、根据表情包标识查询表情，查询所有用户自定义表情
* \	返回：code:　0:成功，100:参数错误，11100:内部错误
*/
struct resp_queryEmoticon : public _sdkrespcmd_base
{
	void init() {
		emotlist.clear();
	}
	std::vector<st_emoticon> emotlist;

	CMD_SIZE();
	COPY_OTHER(resp_queryEmoticon);
};

/**
* \struct resp_querySingleEmoticon 消息号 logic_cmd_querySingleEmoticon
* \brief  查询某个表情包里单个表情信息
*/
struct resp_querySingleEmoticon : public _sdkrespcmd_base
{
	resp_querySingleEmoticon():type(0){}
	std::string packMdCode;           ///< 表情包MdCode
	std::string mainUrl;              ///< 大图地址
	std::string meaning;              ///< 含义
	std::string mdCode;               ///< 单个表情MdCode
	int8 type;                        ///< 表情类型 1：静态表情2：动态表情
};
/**
* \struct resp_singleQueryEmoticonPackage 消息号 logic_cmd_singleQueryEmoticonPackage
* \brief  单个查询表情包
*/
struct resp_singleQueryEmoticonPackage : public _sdkrespcmd_base
{
	st_emoticonPackage emotPackage;
	CMD_SIZE();
	COPY_OTHER(resp_singleQueryEmoticonPackage);
};

/**
* \struct req_pageQueryEmoticon 消息号 logic_cmd_pageQueryEmoticon
* \brief  分页查询表情包
*/
struct resp_pageQueryEmoticon : public _sdkrespcmd_base
{
	void init()
	{
		pageNum = 0;
		pageSize = 0;
		totalPage = 0;
		totalItems = 0;
		emotItem.clear();
	}
	int32 pageNum;     ///< 请求页码.
	int16 pageSize;    ///< 每页大小.
	int64 totalPage;   ///< 总页数.
	int64 totalItems;  ///< 总条数.
	std::vector<st_emoticonPackage> emotItem; //当前页数据

	CMD_SIZE();
	COPY_OTHER(resp_pageQueryEmoticon);
};

/**
* \struct req_addOrDeleteCustomEmoticon 消息号 logic_cmd_addOrDeleteCustomEmoticon
* \brief  增加或删除用户自定义表情
* \返回值：	添加：code　0:成功，100:参数错误，801:md5Code不正确，802:md5Code文件已存在，11100:内部错误
* \	         删除：code　0:成功，100:参数错误，801:md5Code不正确，11100:内部错误
*/
struct resp_addOrDeleteCustomEmoticon : public _sdkrespcmd_base
{
	void init()
	{
		resultCode = 0;      
		timestamp = 0;
		successList.clear();
		failList.clear();
		emoticonList.clear();
		emoticonPackageList.clear();
	}

	/**
	*0:操作成功
	*100026500:表情包参数错误
	*100026501:表情包添加数据库错误
	*100026502:表情包删除数据库错误
	*100026503:表情包时间戳错误
	*100026504:批量表情超过最大数量
	*100026505:表情包需要拉取
	*100026506:表情已存在
	*/
	int32 resultCode;         
	std::string resultMessage; ///< 结果信息.
	std::vector<st_emoticonResult> successList; ///< 批量成功ID记录.
	std::vector<st_emoticonResult> failList;    ///< 批量失败ID记录.

	std::vector<st_emoticonResult> emoticonList;           ///< 自定义表情列表.
	std::vector<st_emoticonResult> emoticonPackageList;    ///< 表情包列表.
	int64 timestamp;              ///< 服务器返回的时间戳


	CMD_SIZE();
	COPY_OTHER(resp_addOrDeleteCustomEmoticon);
};

/**
* \struct resp_labelQueryEmoticonPackage 消息号 logic_cmd_labelQueryEmoticonPackage
* \brief  单个查询表情包
*/
struct resp_labelQueryEmoticonPackage : public _sdkrespcmd_base
{
	void init()
	{
		emotPackageList.clear();
	}
	std::vector<st_emoticonPackage> emotPackageList;
	CMD_SIZE();
	COPY_OTHER(resp_labelQueryEmoticonPackage);
};

/**
* \struct resp_queryAppOrDictTimestamp 消息号 logic_cmd_queryAppOrDictTimestamp
* \brief 查询机器人（公众号）时间戳，查询数据字典时间戳
*/
struct resp_queryAppOrDictTimestamp : public _sdkrespcmd_base
{
	resp_queryAppOrDictTimestamp() : timeStamp(0)
	{
	}
	int64 timeStamp;       //时间戳
	CMD_SIZE();
	COPY_OTHER(resp_queryAppOrDictTimestamp);
};

/**
* \struct resp_setUnReadCount 消息号 logic_cmd_setUnReadCount
* \brief 设置客户端消息未读数量 
*/
struct resp_setUnReadCount : public _sdkrespcmd_base
{
	resp_setUnReadCount()
	{

	}
	CMD_SIZE();
	COPY_OTHER(resp_setUnReadCount);
};

/**
* \struct resp_setMsgUnRead 消息号： logic_cmd_setMsgUnRead
* \brief 设置最后一条已读为未读
*/
struct resp_setMsgUnRead : public _sdkrespcmd_base
{
	resp_setMsgUnRead()
	{

	}
	CMD_SIZE();
	COPY_OTHER(resp_setMsgUnRead);
};

/**
* \struct  resp_getP2pUser 消息号　logic_cmd_getP2pUsers
* \brief 得到可以P2P通讯的用户
*/
struct resp_getP2pUser : public _sdkrespcmd_base
{
	resp_getP2pUser()
	{
		users.clear();
	}
	std::vector<st_p2pUser> users;

	CMD_SIZE();
	COPY_OTHER(resp_getP2pUser);
};

/**
* \struct  resp_P2pUserStatusChg 消息号　logic_cmd_P2pUserStatusChg
* \brief p2p用户的状态改变
*/
struct resp_P2pUserStatusChg : public _sdkrespcmd_base
{
	resp_P2pUserStatusChg()
	{
		userID = 0 ;
		device = 0 ;
		status = 0 ;
	}
	int64  userID ; ///< 用户ID.
	int8   device ; ///< 0x01 PC , 0x02 移动终端.
	int8   status ; ///< 上线 0 ， 下线， 1.

	CMD_SIZE();
	COPY_OTHER(resp_P2pUserStatusChg);
};

/**
 *	\struct resp_P2pSendFileReq 消息号 logic_cmd_p2pSendFilereq
 *	\brief P2P用户发送文件请求
 */
struct resp_P2pSendFileReq: public _sdkrespcmd_base
{
	resp_P2pSendFileReq():fileType(0),fileSize(0),fileSign(0),sendUserID(0){}
    int8        fileType; ///< 1:文件, 2:目录.
	std::string fileName ; ///< 文件名称.
	int64       fileSize ; ///< 文件大小.
	/**
	 * 发送文件的标识,响应的时候需要回传回去
	 */
	int64       fileSign ; ///< 发送标识.
	int64       sendUserID;///< 发送者ID.
	CMD_SIZE();
	COPY_OTHER(resp_P2pSendFileReq);
};

/**
 *	\struct resp_P2pFileTransOp 消息号 logic_cmd_p2pFileTransOps
 *	\brief P2P用户文件传输操作
 */
struct resp_P2pFileTransOp: public _sdkrespcmd_base
{
	resp_P2pFileTransOp() :opType(0), fileSign(0) {}
	int8    opType; /// <接收 0,  取消 1.
	int64   fileSign; ///< 发送标识taskID.

	CMD_SIZE();
	COPY_OTHER(resp_P2pFileTransOp);
};

/**
*	\struct resp_getIdByAccount 消息号 logic_cmd_getIdByAccount 
*	\brief 通过账号名获取用户ID
*/
struct resp_getIdByAccount : public _sdkrespcmd_base
{
	resp_getIdByAccount() {
	}
	
	void init()
	{
		userIds.clear();
	}
	std::map<std::string, int64> userIds;	//用户ID集合，key为account

	CMD_SIZE();
	COPY_OTHER(resp_getIdByAccount);
};

/**
   \struct resp_getMsgDays 
   \brief 获取聊天消息日期
*/
struct resp_getMsgDays : public _sdkrespcmd_base{
	///聊天日期数组
	std::vector<YMD> vt_days ;
	///每天的消息数 数组下标同 vt_days 一一对应
	std::vector<int32> vt_cnt  ;
    void init() {
		vt_days.clear();
		vt_cnt.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_getMsgDays);
};

/**
   \struct resp_getMsgsFromDay 
   \brief 根据日期获取聊天消息
*/
struct resp_getMsgsFromDay: public _sdkrespcmd_base {
	std::vector<st_msgBean>  _vt;
	void init() {
		_vt.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_getMsgsFromDay);
};

/**
\struct resp_stunServerInfo
\brief 获取打洞服务地址
*/
struct resp_getStunServer: public _sdkrespcmd_base {
	std::string stunAddr;
	std::string stunPort;
	std::string turnAddr;
	std::string turnPort;
	std::string account;
	std::string password;
	CMD_SIZE();
	COPY_OTHER(resp_getStunServer);
};
/**
\struct resp_agoraFunc
\brief 声网服务相关接口
*/
struct resp_agoraFunc :public _sdkrespcmd_base{
	resp_agoraFunc() :retCode(0) {}
	int retCode;
	std::string vendorKey;
	std::string subKey;
	CMD_SIZE();
	COPY_OTHER(resp_agoraFunc);
};

/**
* \struct resp_queryOnlineExt logic_cmd_queryOnlineExt
* \brief 查询所有的devicetype的jsonExt信息
*/
struct resp_queryOnlineExt :public _sdkrespcmd_base{

	void init()
	{
		params.clear();
	}
	std::map<std::string, std::string> params; //key是devicetype，value是jsonExt
	CMD_SIZE();
	COPY_OTHER(resp_queryOnlineExt);
};

/**
* \struct resp_queryEmoticon 消息号 logic_cmd_queryEmoticon
* \brief  单个表情查询、根据表情包标识查询表情，查询所有用户自定义表情
* \	返回：code:　0:成功，100:参数错误，11100:内部错误
*/
struct resp_appNodeServer : public _sdkrespcmd_base
{
    void init() {
        what = "";
        appNodes.clear();
    }

    std::string what;
    std::vector<st_appNodeInfo> appNodes;

    CMD_SIZE();
    COPY_OTHER(resp_appNodeServer);
};

/**
* \struct  resp_getWBBanners 消息号　logic_cmd_getBanners
* \brief  根据条件查询拓展字段信息
*/
struct resp_getWBBanners : public _sdkrespcmd_base
{
    void init()
    {
        vecBanners.clear();
    }
    std::vector<st_workBenchBanner>  vecBanners;

    CMD_SIZE();
    COPY_OTHER(resp_getWBBanners);
};

/**
* \struct  resp_helpSystem 消息号　logic_cmd_helpSystem
* \brief  根据条件查询拓展字段信息
*/
struct resp_helpSystem : public _sdkrespcmd_base
{
    void init()
    {
        vecHelps.clear();
    }
    std::vector<st_helpSystemInfo>  vecHelps;

    CMD_SIZE();
    COPY_OTHER(resp_helpSystem);
};
/**
* \struct  resp_clientMenu 消息号　
* \brief  根据时间戳动态菜单信息
*/
struct resp_clientMenu : public _sdkrespcmd_base
{
	void init()
	{
		vec_clientMenu.clear();
	}
	std::vector<st_ClientMenu>  vec_clientMenu;

	CMD_SIZE();
	COPY_OTHER(resp_clientMenu);
};
/**
* \struct  resp_groupOnlineStatus 消息号　logic_cmd_groupOnlineStatus
* \brief  根据条件查询拓展字段信息
*/
struct resp_groupOnlineStatus : public _sdkrespcmd_base
{
    int64 onlineCount;
    int64 offlineCount;
    CMD_SIZE();
    COPY_OTHER(resp_groupOnlineStatus);
};

/**
* \struct  resp_queryUserIsExistList   消息号: logic_cmd_queryUserIsExistList
* \brief  查询目标ID是否在用户的黑/白名单中
*/
struct resp_OauthResult : public _sdkrespcmd_base
{
	resp_OauthResult()
	{
		scope = 0;
		silentAuth = 0;
	}
	void init()
	{
		scope = 0;
		silentAuth = 0;
		appName.clear();
		appIcon.clear();
		authCode.clear();
	}
	std::string appName;
	std::string appIcon;
	int32 scope;
	std::string authCode;
	int8 silentAuth;

	CMD_SIZE();
	COPY_OTHER(resp_OauthResult);
};
/**
* \struct resp_getInstalledApplicationSorted 消息号 logic_cmd_getInstalledApplicationSorted
* \brief 获取用户已安装列表信息排序的
*/
struct resp_getInstalledApplicationSorted : public _sdkrespcmd_base
{
	void init() {
		code = 0;
		isSorted = false;
		apps.clear();
	}
	bool isSorted;  //标识没有设置过排序信息。列表里是未排序的。
	std::vector<st_MarketAppGroup> apps;  //列表.
	CMD_SIZE();
	COPY_OTHER(resp_getInstalledApplicationSorted);
};
/**
* \struct resp_getIssue 消息号 logic_cmd_getIssuebyId
* \brief 获取用户已安装列表信息排序的
*/
struct resp_getIssue : public _sdkrespcmd_base
{
	void init() {
		
	}
	st_GroupIssue issue;
	CMD_SIZE();
	COPY_OTHER(resp_getIssue);
};
/**
* \struct resp_searchIssue 消息号 logic_cmd_searchIssue
* \brief 获取用户已安装列表信息排序的
*/
struct resp_searchIssue : public _sdkrespcmd_base
{
	void init() {
		issues.clear();
	}
	std::vector<st_GroupIssue> issues;
	CMD_SIZE();
	COPY_OTHER(resp_searchIssue);
};
/**
* \struct resp_insertJssdkAuth 消息号 logic_cmd_insertJssdkAuth
* \brief jssdk验证信息
*/
struct resp_insertJssdkAuth : public _sdkrespcmd_base
{
	void init() {

	}
	//std::vector<st_GroupJssdkAuth> jssdkAuthes;
	st_GroupJssdkAuth jssdkAuthes;
	CMD_SIZE();
	COPY_OTHER(resp_insertJssdkAuth);
};

/**
* \struct resp_checkJssdkAuth 消息号 logic_cmd_checkJssdkAuth
* \brief jssdk验证信息
*/
struct resp_checkJssdkAuth : public _sdkrespcmd_base
{
	void init() {

	}
	//std::vector<st_GroupJssdkAuth> jssdkAuthes;
	st_GroupJssdkAuth jssdkAuth;
	CMD_SIZE();
	COPY_OTHER(resp_checkJssdkAuth);
};

/**
* \struct resp_groupAnnouncementResult 消息号 logic_cmd_qGroupS
* \brief 群公告功能操作结果
*/
struct resp_groupAnnouncementResult : public _sdkrespcmd_base
{
	void init() {
		announcementList.clear();
	}
	std::vector<st_GroupAnnouncement> announcementList;
	CMD_SIZE();
	COPY_OTHER(resp_groupAnnouncementResult);
};
/**
* \struct resp_getLocalAppListResult 消息号 logic_cmd_getLocalAppList
* \brief 获取本地应用列表
*/
struct resp_getLocalAppListResult : public _sdkrespcmd_base
{
	void init() {
		localAppList.clear();
	}
	std::vector<st_LocalAppInfo> localAppList;
	CMD_SIZE();
	COPY_OTHER(resp_getLocalAppListResult);
};
/**
* \struct resp_beforeLogin 消息号 logic_cmd_beforeLogin
* \brief 登陆前操作
*/
struct resp_beforeLogin : public _sdkrespcmd_base
{
	void init() {
		result.clear();
	}
	std::string what;
	std::string result;
	CMD_SIZE();
	COPY_OTHER(resp_beforeLogin);
};

/**
* \struct resp_getLogoutCode 消息号 logic_cmd_getLogoutCode
* \brief 获取注销账户验证码
*/
struct resp_getLogoutCode : public _sdkrespcmd_base
{
	void init() {
		code = 0;
		message.clear();
		authenticationCode.clear();
	}
	std::string message;
	std::string authenticationCode;
	CMD_SIZE();
	COPY_OTHER(resp_getLogoutCode);
};

/**
* \struct resp_QrCodeQuery 消息号 logic_cmd_MQrCodeQuery  logic_cmd_MCircleQrCodeQuery
* \brief 登陆前操作
*/
struct resp_QrCodeQuery : public _sdkrespcmd_base
{
	void init() {
		result.clear();
	}
	std::string what;
	std::string result;
	CMD_SIZE();
	COPY_OTHER(resp_QrCodeQuery);
};


///
struct resp_setLogoutAccount : public _sdkrespcmd_base
{
	void init() {
		code = 0;
		message.clear();
		result = 0;
	}
	std::string message;
	int64 result;
	CMD_SIZE();
	COPY_OTHER(resp_setLogoutAccount);
};
/**
* \struct resp_loginDeviceManage 消息号 logic_cmd_loginDeviceManage
* \brief 登录设备管理
*/
struct resp_loginDeviceManage : public _sdkrespcmd_base
{
	void init() {
		loginRecordList.clear();
	}
	std::vector<st_LoginRecord>  loginRecordList;
	CMD_SIZE();
	COPY_OTHER(resp_loginDeviceManage);
};
///工作密集
struct resp_getSecurityList : public _sdkrespcmd_base
{
	void init() {
		getSecurityList.clear();
	}
	std::vector<st_getSecurity>  getSecurityList;
	CMD_SIZE();
	COPY_OTHER(resp_getSecurityList);
};

	/// logic_cmd_getReminderMsgPage
	struct resp_getReminderMsgPage : public _sdkrespcmd_base {
		resp_getReminderMsgPage()
		{
			st.init();
		}
		void init() {
			st.init();
		}
		st_reminderMsgPage st;
		CMD_SIZE();
		COPY_OTHER(resp_getReminderMsgPage);
	};

/**
* \brief  返回云盘传输任务历史
*/
struct resp_CloudTransferHistory : public _sdkrespcmd_base
{
	void init()
	{
		vecTransferHistory.clear();
	}
	std::vector<st_cloudTransferInfo> vecTransferHistory;
	CMD_SIZE();
	COPY_OTHER(resp_CloudTransferHistory);
};

/*
* \brief 云盘循环调用返回文件信息
*/
struct resp_vecCloudFileResult : public _sdkrespcmd_base
{
	void init()
	{
		vecCloudFileInfo.clear();
	}
	std::vector<st_cloudFileInfo> vecCloudFileInfo;
	CMD_SIZE();
	COPY_OTHER(resp_vecCloudFileResult);
};
/**
* \struct  resp_getAgency   
* \brief   拉取待办事项列表返回信息
*/
struct resp_getAgency : public _sdkrespcmd_base
{
	std::vector<st_AgencyBean> AgencyList;

	void init()
	{
		AgencyList.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_getAgency);
};

struct resp_getAgencyEx : public _sdkrespcmd_base
{
	resp_getAgencyEx() :totalCount(0), totalPage(0){}
	void init()
	{
		ToDoTaskMsgs.clear();
	}
	std::vector<st_ToDoTaskMsg>  ToDoTaskMsgs;
	int64 totalCount;
	int64 totalPage;
	CMD_SIZE();
	COPY_OTHER(resp_getAgencyEx);
};
/**
*  \struct resp_getLoginClientRecord
*  \biref  根据用户ID集合查询用户的设备信息,豆豆版本的返回结果
*/
struct resp_getLoginClientRecord : public _sdkrespcmd_base
{
	resp_getLoginClientRecord(){
		init();
	}
	std::string what;
	std::map<int64, std::vector< st_LoginClientRecord> >  resultLoginRecord;
	void init()
	{
		what.clear();
		resultLoginRecord.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_getLoginClientRecord);
};
/**
* \struct  resp_groupInfoOrSetting
* \brief   群信息变更或设置推送
*/
struct resp_groupInfoOrSetting : public _sdkrespcmd_base
{
	resp_groupInfoOrSetting(){
		init();
	}
	/**
	 *   25 管理员或者用户更新群成员信息之后，如果这个人设置了v标群推送   
	 */
	int type;    

	int64 groupId; //type=25时使用 


	void init()
	{
		type = 0;
		groupId = 0;
	}
	CMD_SIZE();
	COPY_OTHER(resp_groupInfoOrSetting);
};

/**
* \struct  resp_QrScanCode
* \brief   扫描二维码信息 推送Qrcode
*/
struct resp_QrScanCode : public _sdkrespcmd_base
{
	std::string  strQrcode; //type=25时使用 
	CMD_SIZE();
	COPY_OTHER(resp_QrScanCode);
};

/**
* \struct  resp_getUtagCmenuList   消息号: logic_cmd_getGroupMemList
* \brief   用户标签和动态菜单
*/
struct resp_getUtagCmenuList : public _sdkrespcmd_base
{
	std::string  strUtag;
	std::vector<st_ClientMenu>  _vt;
	void init()
	{
		strUtag = "";
		_vt.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_getUtagCmenuList);
};

/**
* \struct  resp_getUtagCmenuList   消息号: logic_cmd_getGroupMemList
* \brief   用户标签和动态菜单
*/
struct resp_PushEmottoClient : public _sdkrespcmd_base
{
	int8  bPushEmtoClient;
	std::string mdcodes;
	void init()
	{
		bPushEmtoClient = 0;
		mdcodes.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_PushEmottoClient);
};



struct resp_inviteMember : public _sdkrespcmd_base
{
	std::vector<st_buddyBean> inviteVerifyUserList; //进群需要验证的用户集合
	std::vector<st_buddyBean> inviteNotAllowUserList;//不接受进群的用户集合
	std::vector<st_buddyBean> inviteAddUserList;//可以直接进群的用户集合
	std::vector<st_buddyBean> inviteAdminVerifyUserList;//需要管理员验证的用户集合
	void init(){
		inviteVerifyUserList.clear();
		inviteNotAllowUserList.clear();
		inviteAddUserList.clear();
		inviteAdminVerifyUserList.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_inviteMember);
};
typedef resp_inviteMember resp_groupVerifyRespons;

struct resp_smallAppHelpList : public _sdkrespcmd_base
{
	std::vector<st_smallAppHelp> smallAppHelpList;
	std::string what;
	resp_smallAppHelpList(){
		init();
	}
	void init(){
		what = "";
		smallAppHelpList.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_smallAppHelpList);
};

//公众号免打扰
struct resp_UserToAppConfig : public _sdkrespcmd_base
{
	std::vector<st_UserToAppConfig> usertoappconfig;
	std::string what;
	resp_UserToAppConfig(){
		init();
	}
	void init(){
		what = "";
		usertoappconfig.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_UserToAppConfig);
};

//隐私中搜索信息列表
struct resp_GetClientSearchingSetting : public _sdkrespcmd_base
{
	resp_GetClientSearchingSetting()
	{
		VcUserSetting.clear();
		what = "";
	}
	std::vector<st_PersionSearchSetting> VcUserSetting;
	std::string what;
	CMD_SIZE();
	COPY_OTHER(resp_GetClientSearchingSetting);
};

//用户绑定的后台管理员角色信息  [2/25/2021 zhuohc]
struct resp_AdminRoleInfo : public _sdkrespcmd_base
{
	resp_AdminRoleInfo()
	{
		superAdmin = false;
	}
	void init()
	{
		superAdmin = false;
		adminName.clear();
		adminAccount.clear();
	}
	bool superAdmin;				//是否是超级管理员，true是，false否
	std::string adminName;		//管理后台绑定人员名称
	std::string adminAccount;	//管理后台绑定人员帐号

	CMD_SIZE();
	COPY_OTHER(resp_AdminRoleInfo);
};
//用户绑定的后台管理员角色信息  [3/8/2021 zhuohc]
struct resp_AdminRoleInfoJson : public _sdkrespcmd_base
{
	resp_AdminRoleInfoJson()
	{
	}
	void init()
	{
		roleInfoResult.clear();
	}
	std::string roleInfoResult;		//管理后台绑定人员名称

	CMD_SIZE();
	COPY_OTHER(resp_AdminRoleInfoJson);
};

// 打开密码校验界面，民情通接口 [3/9/2021 zhuohc]
struct resp_showVerifyUserPassword : public _sdkrespcmd_base
{
	resp_showVerifyUserPassword(){}
	void init(){}

	CMD_SIZE();
	COPY_OTHER(resp_showVerifyUserPassword);
};
/**
*  \struct resp_buddySetting
*  \biref  根据用户ID集合查询用户的设置项信息
*/

struct resp_buddySetting:public _sdkrespcmd_base
{
	std::string what;
	std::map<int64, std::vector<st_personalDataSwitch> > userDataSwitchMap;
	resp_buddySetting(){
		init();
	}
	void init(){
		what = "";
		userDataSwitchMap.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_buddySetting);
};

/**
*  \struct resp_setServerAlias
*  \biref  设置服务器别名
*/
struct resp_setServerAlias :public _sdkrespcmd_base
{
	resp_setServerAlias(){
		init();
	}
	void init(){
	}
	CMD_SIZE();
	COPY_OTHER(resp_setServerAlias);
};

/**
*  \struct resp_getServerAlias
*  \biref  获取用户设置的服务器别名
*/
struct resp_getServerAlias :public _sdkrespcmd_base
{
	std::string what;
	std::string serverAlias;
	resp_getServerAlias(){
		init();
	}
	void init(){
		what = "";
		serverAlias.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_getServerAlias);
};

/**
*  \struct resp_elevatorAuthInfo  消息号 logic_cmd_elevatorAuthInfo
*  \biref  超级用户相关的操作

type=3, 保存提权人员所有权限 (saveElevatorAuthority)
参数：elevatorList  提权人员列表
返回: code ：0:成功  -1:系统异常 -2:参数异常 100:未定义的type类型 11100调用底层接口失败
what 结果消息
value_str 保存失败的userID集合

type=4, 删除提权人员所有权限 (deleteElevator)
参数：
value64 超级用户id
value64_2 提权用户id

返回: code ：0:成功  -1:系统异常 -2:参数异常 100:未定义的type类型 11100调用底层接口失败
what 结果消息

type=5, 查询当前超级用户的所有提权人员以及权限 (selectElevatorAuthorityAll)
参数:
value64 查询页数量
value64_2 查询页序号
value64_3 超级用户id

返回：
code ：0:成功 100:未定义的type类型 11100调用底层接口失败
value64 当前页数量
value64_2 当前页序号
value64_3 总页数
value64_4 总条数
elevatorList 提权人员列表

type=6, 查询提权人员真实所有权限 (queryElevatorAuthorityReal)
参数：
value64 提权人员id
返回: code ：0:成功  -1:系统异常 -2:参数异常 100:未定义的type类型 11100调用底层接口失败
what 结果消息
value_str 权限json

type=7, 分页查询操作记录信息 (listElevatorRecord)
参数：
value64 查询页数量
value64_2 查询页序号
value64_3 提权人员id
value64_4 超级用户id

返回：
code ：0 成功 100:未定义的type类型 11100调用底层接口失败
value64 当前页数量
value64_2 当前页序号
value64_3 总页数
value64_4 总条数
elevatorList 提权人员列表

*/

struct resp_elevatorAuthInfo :public _sdkrespcmd_base
{

	struct st_elevatorAuthority
	{

		int64 elevatorUserId; // 提权人员userId
		int64 superUserId;  // 超级用户userId
		std::string authorityCode; // 权限code/提权记录信息
		int64 createTime; //创建时间
		int64 updateTime; //更新时间
	};

	std::string what;
	int16 type;
	std::vector<st_elevatorAuthority> elevatorList;
	int64 value64;
	int64 value64_2;
	int64 value64_3;
	int64 value64_4;
	std::string value_str;
	resp_elevatorAuthInfo(){
		init();
	}
	void init(){
		elevatorList.clear();
		type = 0;
		value64 = 0;
		value64_2 = 0;
		value64_3 = 0;
		value64_4 = 0;
	}
	CMD_SIZE();
	COPY_OTHER(resp_elevatorAuthInfo);
};

/// logic_cmd_getReminderMsgPage
struct resp_getServerDoubleKeyInfo : public _sdkrespcmd_base {

	bool bTips;       //是否要弹框
	int8 nSubType;   //子消息类型
	int8 nOperater; //用户操作 1同意 2拒绝
	int64 nMessageId; //消息ID
	int64 nTargetId;  //目标ID
	int64 nLoginTime;
	std::string szAdminName; //管理员姓名
	resp_getServerDoubleKeyInfo()
	{
		init();
	}
	void init() {
		bTips = false;
		nSubType = 0;
		nTargetId  = 0;
		nMessageId = 0;
		nOperater = 0;
		nLoginTime = 0;
		szAdminName = "";
	}

	CMD_SIZE();
	COPY_OTHER(resp_getServerDoubleKeyInfo);
};

struct resp_outEntNodeInfo :public _sdkrespcmd_base
{
	void init() {
		what = "";
		appNodes.clear();
	}

	std::string what;
	std::vector<st_appNodeInfo> appNodes;

	CMD_SIZE();
	COPY_OTHER(resp_outEntNodeInfo);


};
/**
* \struct  resp_getLocalAgencyListFromDb
* \brief   本地拉取待办事项列表返回信息
*/
struct resp_getLocalAgencyListFromDb : public _sdkrespcmd_base
{
	resp_getLocalAgencyListFromDb(){
		init();
	}
	std::vector<st_getLocalAgencyListFromDb> st_agencyList;

	void init()
	{
	}
	CMD_SIZE();
	COPY_OTHER(resp_getLocalAgencyListFromDb);
};
/**
* \struct  resp_getAgencyListFinishCnt 消息号　logic_cmd_getAgencyListFinishCnt
* \brief 获取已完成和未完成列表数
*/
struct  resp_getAgencyListFinishCnt : public _sdkrespcmd_base
{
	resp_getAgencyListFinishCnt() :userId(0), nCntDone(0), nCntUndone(0)
	{
	}

	int64 userId;	///< 用户ID.
	int64  nCntDone;		///< 待办事项已完成数量
	int64  nCntUndone;		///< 待办事项未完成数量
	
	CMD_SIZE();
	COPY_OTHER(resp_getAgencyListFinishCnt);
};
/**
* \struct  resp_setAgencyListRead 消息号　logic_cmd_setAgencyListRead
* \brief 工作台任务设置已读和未读
*/
struct  resp_setAgencyListRead : public _sdkrespcmd_base
{
	resp_setAgencyListRead() :userId(0)
	{
	}

	int64 userId;	///< 用户ID.

	CMD_SIZE();
	COPY_OTHER(resp_setAgencyListRead);
};
/**
* \struct  resp_getAgencyListScreenItem 消息号　logic_cmd_getAgencyListScreenItem
* \brief 获取本地筛选条件（来源和标签展示）
*/
struct  resp_getAgencyListScreenItem : public _sdkrespcmd_base
{
	resp_getAgencyListScreenItem() :userId(0)
	{
	}
	void init()
	{
		fromBuss.clear();
		tags.clear();
	}
	int64 userId;	///< 用户ID.
	std::vector<int64>  fromBuss;		///< 待办事项已完成数量
	std::vector<std::string>  tags;		///< 待办事项未完成数量

	CMD_SIZE();
	COPY_OTHER(resp_getAgencyListScreenItem);
};
/**
* \struct  resp_disHistoryAgencyListRecords 消息号　logic_cmd_disHistoryAgencyListRecords
* \brief 展示历史搜索记录
*/
struct  resp_disHistoryAgencyListRecords : public _sdkrespcmd_base
{
	resp_disHistoryAgencyListRecords() :userId(0)
	{
	}
	void init()
	{
		records.clear();
	}
	int64 userId;	///< 用户ID.
	std::vector<std::string>  records;		///< 待办事项列表

	CMD_SIZE();
	COPY_OTHER(resp_disHistoryAgencyListRecords);
};
/**
* \struct  resp_delHistoryAgencyListRecords 消息号　logic_cmd_delHistoryAgencyListRecords
* \brief 清空历史搜索记录
*/
struct  resp_delHistoryAgencyListRecords : public _sdkrespcmd_base
{
	resp_delHistoryAgencyListRecords() :userId(0)
	{
	}

	int64 userId;	///< 用户ID

	CMD_SIZE();
	COPY_OTHER(resp_delHistoryAgencyListRecords);
};
/**
* \struct  resp_getAppListByMenuCode 消息号　logic_cmd_getAppListByMenuCode
* \brief 获取栏目的应用列表
*/
struct  resp_getAppListByMenuCode : public _sdkrespcmd_base
{
	resp_getAppListByMenuCode() :menuID(0)
	{
	}
	int16 menuID;	///< 菜单ID
	st_AppListMenuInfo appListMenuInfo;
	void init(){
		appListMenuInfo.menuInfos.clear();
	}

	//int8 resultCode;
	//std::vector<GroupAppListMenuResult> appListMenuInfos;
	CMD_SIZE();
	COPY_OTHER(resp_getAppListByMenuCode);
};
/**
* \struct  resp_getAppListByMenuSeq 消息号　logic_cmd_getAppListByMenuSeq
* \brief 获取栏目的应用列表
*/
struct  resp_getAppListByMenuSeq : public _sdkrespcmd_base
{
	resp_getAppListByMenuSeq() :menuID(0)
	{
	}
	int16 menuID;	///< 菜单ID
	st_AppListMenuInfo appListMenuInfo;
	void init(){
		appListMenuInfo.menuInfos.clear();
	}

	//int8 resultCode;
	//std::vector<GroupAppListMenuResult> appListMenuInfos;
	CMD_SIZE();
	COPY_OTHER(resp_getAppListByMenuSeq);
};
/**
\struct resp_UploadOverDueMessageFile
\brief 上传过期文件或者图片的返回值
*/
struct resp_uploadOverDueMessageFile : public _sdkrespcmd_base {
	st_msgBean  overDueMsg;
	void init() {
		overDueMsg.message = "";
		overDueMsg.msgProperties = "";
		overDueMsg.init();
		overDueMsg.sendUserID = 0;
		overDueMsg.receTargetID = 0;
		overDueMsg.sendTime = 0;
		overDueMsg.targetID = 0;
		overDueMsg.isBurn = 0;
		overDueMsg.messageType = 0;
		overDueMsg.subMsgType = 0;
		overDueMsg.lastMessageID = 0;
		overDueMsg.senderSessionID = 0;
		overDueMsg.activeType = 0;
		overDueMsg.relatedMsgID = 0;
		overDueMsg.localID = 0;
		overDueMsg.msgRemindMode = 2;
		overDueMsg.securityLevel = 0;
	}
	CMD_SIZE();
	COPY_OTHER(resp_uploadOverDueMessageFile);
};

struct resp_CombinationSettingResult : public _sdkrespcmd_base
{
	resp_CombinationSettingResult()
	{
		nCode = 0;
		szInfo = "";
		OrderVt.clear();
	}
	int32 nCode;
	std::string szInfo;
	std::vector<st_CombinationOrder>  OrderVt;		///< 待办事项列表
};
}

#endif   //CMD_RESP_DEF_H
