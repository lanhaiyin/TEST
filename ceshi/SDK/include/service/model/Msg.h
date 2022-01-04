#pragma once
#include "SDKTypes.h"

#include <vector>
#include <string>
#include <string.h>
const int64  MSGMEMSIZE = 256;
namespace model 
{
///消息类型
enum MSG_TYPE
{
	MSG_TYPE_TEXT = 2,			///<文本消息
	MSG_TYPE_AUDIO,				///<语言消息
	MSG_TYPE_POSITION,			///<位置消息
	MSG_TYPE_IMG,				///<图片消息
	MSG_TYPE_FILE,				///<文件消息
	MSG_TYPE_CARD,				///<名片消息
	MSG_TYPE_TIP,				///<弱提示消息
	MSG_TYPE_WEB,				///<网页链接消息
	MSG_TYPE_COMBINEORDER = 11, ///<组合指令消息
	MSG_TYPE_PICTEXT = 12,		///<图文消息
	MSG_TYPE_COMBINE,           ///<组合消息
	MSG_TYPE_REVOKE = 18,		///<回执消息
	MSG_TYPE_DYNEXPRESSION,		///<动态表情消息
	MSG_TYPE_VOICE = 16,///<音頻消息
	MSG_TYPE_VIDEIO = 14,///<視頻消息
	MSG_TYPE_CONFER = 15,///<視頻会议消息
	MSG_TYPE_TASK = 17,///<任务消息
	MSG_TYPE_E2EE = 20,///<端到端消息
	MSG_TYPE_TEMPL = 26,    ///<模版消息
	MSG_TYPE_DYNEXPRESSION2 = 27, ///<新动态表情
	MSG_TYPE_NINEBLOCK = 28,///<9图消息
	MSG_TYPE_MAIL = 31, ///<邮件消息
	MSG_TYPE_UNREADSTATE = 34, ///<未读状态消息
	MSG_TYPE_NOTEBOOK = 35 ,	///<记事本消息
	MSG_TYPE_APPSHARE = 36,	///<应用分享消息
	MSG_TYPE_DIVERS =37,///<潜水者消息
	MSG_TYPE_TRACK = 38,///<运动轨迹消息
	MSG_TYPE_UNIVERSAL = 64,   ///<万能消息，具体看subMsgType
	MSG_TYPE_CUSTOM= 66,   ///<客服客户直接的消息，实际消息类型在msgProperties, realMsgType
	MSG_TYPE_ACTIONCARD = 71, ///<新待办模版消息
	MSG_TYPE_REDPACKET = 88,///<废弃
	MSG_TYPE_MINIVEDIO = 89,///<微视频消息	
	MSG_TYPE_SYS = 100,	///<系统消息
	MSG_TYPE_REDPACKETNEW = 118,///<红包消息
};

///消息子类型
enum SubMessageType
{
	sub_groupAnnouncement = 1,     //群公告推送msgType64号消息，subMsgtype=1
	sub_buddyApply = 201,				//好友申请通知
	sub_agreeBuddyApply = 202,			//同意好友申请通知
	sub_rejectBuddyApply = 203,			//拒绝好友申请通知
	sub_groupApply = 301,				//申请入群
	sub_adminAgreeGroupAplly = 302,     //管理员同意入群
	sub_adminRejectGroupAplly = 303,    //管理员拒绝入群
	sub_inviteEnterGroup = 401,			//邀请入群
	sub_agreeEnterGroup = 402,			//用户同意入群
	sub_rejectEnterGroup = 403,        //用户拒绝入群
	sub_adminKickMember = 501,			//管理员踢出群成员
	sub_dissolveGroup = 503,			//解散群
	sub_groupMemberExit = 504,         //群成员退出
};

///消息状态
enum MSG_STATE
{
	MSG_TYPEX_UPLOAD_FAILED = 0x100,	///< 附加资源失败
	MSG_TYPEX_SEND_ERROR = 0x200,		///< 发送消息失败
	MSG_TYPEX_DOWNLOAD_FAILED = 0x400,  ///< 下载失败
	MSG_TYPEX_SENDING = 0x1000,			///< 正在发送消息
	MSG_TYPEX_UPLOADING = 0x2000,		///< 正在上传附件
};

struct FailAttchment{
	FailAttchment() :filesize(0){}
	int64 filesize;   ///<发送失败且非一步发送时 存储的是文件大小
	std::string filePath;///<发送失败且非一步发送时 存储的是文件本地路径
	std::string fileName;///<发送失败且非一步发送时 存储的是文件名
};

///快照信息
struct SnapshotInfo
{
	SnapshotInfo() :msgId(0), snapshotId(0) {}
	int64 msgId;			//消息ID
	int64 snapshotId;		//群快照ID
};


struct MsgUnreadCounter
{
	MsgUnreadCounter() :messageId(0), unreadCount(0), maxUnreadCount(0), snapshotId(0) {}
	int64 messageId;
	int32 unreadCount;
	///最大消息未读数
	int32 maxUnreadCount;
	///群快照ID
	int64 snapshotId;
};


///PC登录基本信息
class MsgApp
{
public:
	MsgApp()
	{
		loginIp.resize(MSGMEMSIZE);
		appVersion.resize(MSGMEMSIZE);
		deviceInfo.resize(MSGMEMSIZE);
		mac.resize(MSGMEMSIZE);
		flag = 1;
		pcType = 0;
	}

	~MsgApp(){}

	int8 pcType;
	int16 flag;
	int64 loginport;
	std::string loginIp;
	std::string appVersion;		//应用版本号，如"1.5.0"  *必须设置
	std::string deviceInfo;		//设备信息 如"pc-windows"  *必须设置
	std::string mac;			//mac地址  windows,mac,linux平台会自动获取，其它平台需手动设置
};


///消息基类
class Msg 
{
public:
	Msg() :msgType(0), subType(0), deviceType(0), lastMsgId(0), msgId(0), targetId(0), fromId(0), toId(0),
		relatedUsers(0), relatedMsgId(0), noStore(0), time(0), localId(0), pursuitUsers(0),
		isPrivateMsg(0), timeZone(-1),/* isBurn(0),*/ activeType(0), deal(false), 
		msgRemindMode(1), isOri(false), isFeather(0), issueCreater(0), purmsgId(0),
		unReadCount(0), maxUnReadCount(0), snapshotId(0), issueId(0), issueOperType(0), isCustom(0), realTargetId(0), securityLevel(0), isContainSensitiveKeyword(0)
	{}
	virtual ~Msg() {}

	bool operator == (const Msg & rhs) const
	{
		//if (isBurn != rhs.isBurn)
		//	return false;
		if (isContainSensitiveKeyword != rhs.isContainSensitiveKeyword)
			return false;
		if (securityLevel != rhs.securityLevel)
			return false;
		if (msgType != rhs.msgType)
			return false;
		if (msgId != rhs.msgId)
			return false;
		if (targetId != rhs.targetId)
			return false;
		if (fromId != rhs.fromId)
			return false;
		if (toId != rhs.toId)
			return false;
		if (relatedUsers != rhs.relatedUsers)
			return false;
		if (limitRange != rhs.limitRange)
			return false;
		if (pursuitUsers != rhs.pursuitUsers)
			return false;
		if (body != rhs.body)
			return false;
		if (relatedMsgId != rhs.relatedMsgId)
			return false;
		if (sourceId != rhs.sourceId)
			return false;
		if (noStore != rhs.noStore)
			return false;
		if (msgProperties != rhs.msgProperties)
			return false;
		if (time != rhs.time)
			return false;
		if (localId != rhs.localId)
			return false;
		if (format != rhs.format)
			return false;
		if (isPrivateMsg != rhs.isPrivateMsg)
			return false;
		if (unReadCount != rhs.unReadCount)
			return false;
		if (maxUnReadCount != rhs.maxUnReadCount)
			return false;
		if (snapshotId != rhs.snapshotId)
			return false;
		if (subType != rhs.subType)
			return false;
		if (issueId != rhs.issueId)
			return false;
		if (issueCreater != rhs.issueCreater)
			return false;
		if (issueName != rhs.issueName)
			return false;
		if (issueOperType != rhs.issueOperType)
			return false;
		if (isCustom != rhs.isCustom)
			return false;
		if (realTargetId != rhs.realTargetId)
			return false;
		if (purmsgId != rhs.purmsgId)
			return false;
		return true;
	}
	int8 activeType;           ///<0x01为阅后即焚 
	//int8  isBurn;            ///<0x01为阅后即焚 
	int8 deviceType;         ///<设备类型
	int8 noStore;			///<本地不存储消息  0为存储，1为不存储	
	int8 isPrivateMsg;		///<是否是私信   0不是 1是
	int8 msgRemindMode;		//与0x0F 0.免打扰 1.提醒始终有声音  2.提醒始终无声音  3.提醒  4.不提醒，仅显示条目 5.根据免打扰时间段判断是否免打扰
							//与 0xF0, 1、通知详情  2、通知源，隐藏内容  3、完全隐藏
	bool deal;  ///<标记已处理
	bool isOri; ///是否自定义
	int16 unReadCount;		///<未读数量
	int16 maxUnReadCount;     ///<最大未读数量
	int32 msgType;			///<消息类型
	int32 subType;	///< 消息子类型
	int32  timeZone;         ///<时区
	int32  isFeather;
	int64 snapshotId;		///<群快照ID
	int64 msgId;			///<消息ID
	int64 targetId;			///<会话者ID（群或用户等）
	int64 localId;			///<本地ID
	int64 fromId;			///<发送者ID
	int64 toId;				///<接收者ID
	int64 relatedMsgId;		///<关联消息ID
	int64 lastMsgId;		///<上一条消息ID
	int64 time;				///<消息发送的时间
	int64 issueId;			///<议题ID，只在群聊时使用
	int64 issueCreater;		///<议题创建者
	int8  issueOperType;		///<议题操作 1.回复 2.创建 3.删除
	int64 purmsgId;
	std::string sourceId;	///<会话来源ID 1_groupID表示传的群ID，2_orgID表示传的组织ID
	std::string body;		///<消息内容 
	std::string msgProperties;		///<消息属性
	std::string format;		///<格式
	std::vector<int64> relatedUsers;///<秘聊时相关的用户ID
	std::vector<int64> limitRange; ///<@人员列表
	std::vector<int64> pursuitUsers;///<追一下消息的相关的用户ID
	std::string loginfoPath; ///发送消息，登录信息路径。仅发送时使用
	std::string userName;///<用户名 组合消息和系统消息使用
	std::string userPic;///<用户头像 组合消息 

	std::string preDefined; ///自定义信息
	std::string  languageType;///<鸡毛信语言
	std::string issueName;	///< 议题名称
	//std::string oriBody;		///<消息内容 
	//std::string oriMsgProperties;		///<消息属性必须是json形式
	int8 isCustom;  ///<是否是客服客户之间的66号消息 0.否 1.是
	int64 realTargetId;  ///<发送消息用，客服给客户发消息时用，传公众号的appId
	int64 notifyFlag;	///<推送标识位，仅在收消息推送时生效
	int securityLevel;
	int8 isContainSensitiveKeyword; //是否包含敏感词  0不包含，1包含
};

///文本消息
class MsgText : public Msg 
{
public:
	MsgText() :isReceipt(false),isDelay(false), isRbtMsg(false), delayTime(0), fontSize(0), bwdType(-1), gifPlayed(0)
	{ 
		msgType = MSG_TYPE_TEXT; 
	}
	MsgText(Msg& msg) :Msg(msg), isReceipt(false), isDelay(false), isRbtMsg(false), delayTime(0), fontSize(0), bwdType(-1), gifPlayed(0)
	{
		msgType = MSG_TYPE_TEXT;
	}

	~MsgText(){}

	bool operator == (const MsgText & rhs) const
	{
		return (isReceipt == rhs.isReceipt) && (isDelay == rhs.isDelay) ;
	}
	bool isRbtMsg;           ///<是否是机器人消息
	bool isDelay;			///<是否延迟消息
	int64 delayTime;        ///<延迟时间
	bool isReceipt;			///<是否阅后回执
	bool isReceiptAll;			///<消息是抖一抖或阅后回执，且此消息体最后是英文小于号<结尾的
	int fontSize;
	int8 bwdType;           ///<敏感词类型(发送不用传)
	int8 gifPlayed;         ///<是否已播放过gif 0.播放过或不需播放 1.需要播放,播放后通过updateMsg函数更新(文本消息中含有生日快乐等词汇)
	std::string scope;      ///<橡皮擦消息区分清除消息的范围（scope取值沿用现有指令消息内容today，all）
	std::vector<std::string> bwds;///<敏感词集合(发送不用传)
};


///端到端消息
class MsgE2E : public Msg
{
public:
	MsgE2E() :isReceipt(false), isDelay(false), isRbtMsg(false), delayTime(0), fontSize(0), bwdType(-1), gifPlayed(0), msgCode(0)
	{
		msgType = MSG_TYPE_E2EE;
	}
	MsgE2E(Msg& msg) :Msg(msg), isReceipt(false), isDelay(false), isRbtMsg(false), delayTime(0), fontSize(0), bwdType(-1), gifPlayed(0), msgCode(0)
	{
		msgType = MSG_TYPE_E2EE;
	}

	~MsgE2E(){}

	bool operator == (const MsgE2E & rhs) const
	{
		return (isReceipt == rhs.isReceipt) && (isDelay == rhs.isDelay);
	}
	bool isRbtMsg;           ///<是否是机器人消息
	bool isDelay;			///<是否延迟消息
	int64 delayTime;        ///<延迟时间
	bool isReceipt;			///<是否阅后回执
	bool isReceiptAll;			///<消息是抖一抖或阅后回执，且此消息体最后是英文小于号<结尾的
	int fontSize;
	int8 bwdType;           ///<敏感词类型(发送不用传)
	int8 gifPlayed;         ///<是否已播放过gif 0.播放过或不需播放 1.需要播放,播放后通过updateMsg函数更新(文本消息中含有生日快乐等词汇)
	std::vector<std::string> bwds;///<敏感词集合(发送不用传)
	int64 msgCode;         ///错误码

};

class MsgDivers:public Msg
{
public :
	MsgDivers()
	{
		msgType = MSG_TYPE_DIVERS;
	}
	MsgDivers(Msg& msg) :Msg(msg)
	{
		msgType = MSG_TYPE_DIVERS;
	}

	~MsgDivers(){}

};

class MsgSys : public Msg
{
public:
	MsgSys() :applicationId(0), userId(0), receiveId(0), groupId(0), senderId(0)
	{
		msgType = MSG_TYPE_SYS;
	}
	MsgSys(Msg& msg) :Msg(msg),applicationId(0), userId(0), receiveId(0),groupId(0), senderId(0)
	{
		msgType = MSG_TYPE_SYS;
	}

	~MsgSys() {}

	int64 applicationId;           ///< 标识一个请求的id
	int64 receiveId;			   ///< 接收者ID 
	std::string receiveName;	   ///< 接收者名称
	std::string receiveIcon;	   ///< 接受者头像(加好友时有效)
	int64 senderId;				   ///< 发送者ID
	std::string senderName;		   ///< 发送者姓名
	std::string senderIcon;		   ///< 发送者头像(加好友时有效)
	int64 userId;				   ///< 一次完整的系统消息触发者ID 用户名在基类中 (加群时有效)
	int64 groupId;				   ///< 群ID(加群时有效)
	std::string groupName;         ///< 群名(加群时有效)
	std::string groupIcon;         ///< 群头像(加群时有效)
};

///音頻消息
class MsgVoice : public Msg
{
public:
	MsgVoice() :extendMsgType(0)
	{
		msgType = MSG_TYPE_VOICE;
		session.resize(MSGMEMSIZE);
	}
	MsgVoice(Msg& msg) :Msg(msg), extendMsgType(0)
	{
		msgType = MSG_TYPE_VOICE;
	}

	~MsgVoice(){}

	bool operator == (const MsgVoice & rhs) const
	{
		return (extendMsgType == rhs.extendMsgType) && (session == rhs.session);
	}
	int extendMsgType;
	std::string session;
};
///視頻消息
class MsgVedio : public Msg
{
public:
	MsgVedio()
	{
		msgType = MSG_TYPE_VIDEIO;
		channelID.resize(MSGMEMSIZE);
		isSipChat.resize(MSGMEMSIZE);
		videoType.resize(MSGMEMSIZE);
		videostatus.resize(MSGMEMSIZE);
		key.resize(MSGMEMSIZE);
		version.resize(MSGMEMSIZE);
        msgModel.resize(MSGMEMSIZE);
        msgInfo.resize(MSGMEMSIZE);
	}
	MsgVedio(Msg& msg) :Msg(msg)
	{
		msgType = MSG_TYPE_VIDEIO;
	}

	~MsgVedio(){}

	
	std::string channelID;
	std::string isSipChat;//1,音频 4，视频 5，p2p  (只适用单点和p2p)
	std::string videoType;
	std::string videostatus;
	std::string key;
	std::string version;//没值的是 单点音视频 或者 p2p; 有值  "rtc@1.0.0"  ///rtc协议版本  "agora@1.0.0" ///声网协议版本
    std::string msgModel;
    std::string msgInfo;
};
///位置消息
class MsgPosition : public Msg
{
public:
	MsgPosition() :isDelay(false), latitude(0), longitude(0), delayTime(0), isReceipt(false)
	{
		msgType = MSG_TYPE_POSITION;
		name.resize(MSGMEMSIZE);
	}
	MsgPosition(Msg& msg) :Msg(msg), isDelay(false), latitude(0), longitude(0), delayTime(0), isReceipt(false)
	{
		msgType = MSG_TYPE_POSITION;
	}
	~MsgPosition(){}

	bool operator == (const MsgPosition &rhs) const
	{
		return (name == rhs.name) && (isDelay == rhs.isDelay) &&
			(latitude == rhs.latitude) && (longitude == rhs.longitude);
	}
	bool isDelay;			///<是否延迟消息
	bool isReceipt;			///<是否阅后回执
	int64 delayTime;        ///<延迟时间
	std::string name;		///<地名
	double latitude;		///<纬度
	double longitude;		///<经度
};
///文件消息
class MsgFile : public Msg 
{
public:
	MsgFile() :isDelay(false), states(0), size(0), fileId(0), isOld(false), delayTime(0), isResume(false), 
		isFolder(0), isReceipt(false), validity(0), isOverdue(0), sendPasswdWithoutEncrypt(0), bwdType(-1), isGroupDoc(0)
	{ 
		msgType = MSG_TYPE_FILE; 
		fileName.resize(MSGMEMSIZE);
		filePath.resize(MSGMEMSIZE);
		encryptKey.resize(MSGMEMSIZE);
		url.resize(MSGMEMSIZE);
	}
	MsgFile(Msg& msg) :Msg(msg), isDelay(false), states(0), size(0), fileId(0), isOld(false), delayTime(0), isResume(false), 
		isFolder(0), isReceipt(false), validity(0), sendPasswdWithoutEncrypt(0), bwdType(-1), isGroupDoc(0)
	{
		msgType = MSG_TYPE_FILE;
	}
	~MsgFile(){}

	bool operator == (const MsgFile& rhs) const
	{
		return (isDelay == rhs.isDelay) && (states == rhs.states) &&
			(size == rhs.size) && (fileId == rhs.fileId) && (fileName == rhs.fileName) &&
			(filePath == rhs.filePath) && (url == rhs.url) && (encryptKey == rhs.encryptKey) && (isGroupDoc == rhs.isGroupDoc);
	}

	bool isDelay;			///<是否延迟消息
	int64 delayTime;        ///<延迟时间
	bool isReceipt;			///<是否阅后回执
	int states;             ///<文件
	int64 size;				///<文件大小  
	int64 fileId;			///<文件ID
	std::string fileName;	///<文件名  
	std::string filePath;	///<文件本地路径  
	std::string encryptKey;///<加密KEY
	int8 sendPasswdWithoutEncrypt;   ///<只发送秘钥，不进行加密 0.加密文件 1.不实际加密文件 
	std::string url;		///<文件URL	 一步发送消息时不赋值
	std::string fileTypeName;  ///< 标示文件类型 如gif
	int32       docID;       ///是否加密
	int8 isFolder;         ///<是否是文件夹 0,不是 1,是
	int64 validity;          ///附件有效期
	int8 isGroupDoc;

	bool isOld;      ///<是否是老的形式(非一步发送)
	bool isResume;   ///<是否断点上传(一步发消息时使用)
	int8 isOverdue;  ///< 服务器路径是否过期，1.过期，0.未过期
	std::string md5Code;	///< MD5校验码
	std::string szFileShowDevice;   ///<指定端可以下载标识（电脑端，手机端，pad端）

	//以下iOS专用字段
	std::string relaPath;	///< 相对路径
	int8 bwdType;           ///<敏感词类型
	std::vector<std::string> bwds;///<敏感词集合
};


///图片消息
class MsgImg : public Msg 
{
public:
	MsgImg() :isDelay(false), width(0), height(0), isCmd(false), isOld(false), buddyId(0), 
		delayTime(0), isReceipt(0), validity(0), bwdType(-1), isOverdue(0), isOriImg(0), sendPasswdWithoutEncrypt(0), size(0)
	{ 
		msgType = MSG_TYPE_IMG; 
		thumbUrl.resize(MSGMEMSIZE);
		mainUrl.resize(MSGMEMSIZE);
		thumbPath.resize(MSGMEMSIZE);
		mainPath.resize(MSGMEMSIZE);
		encryptKey.resize(MSGMEMSIZE);
		fileName.resize(MSGMEMSIZE);
		imageContents.resize(MSGMEMSIZE);
	}
	MsgImg(Msg& msg) :Msg(msg), isDelay(false), width(0), height(0), isCmd(false), isOld(false), 
		buddyId(0), delayTime(0), isReceipt(0), validity(0), bwdType(-1), isOverdue(0), isOriImg(0), size(0), sendPasswdWithoutEncrypt(0)
	{
		msgType = MSG_TYPE_IMG;
	}
	~MsgImg(){}

	bool operator == (const MsgImg& rhs) const
	{
		return (width == rhs.width) && (height == rhs.height) && (fileName == rhs.fileName) &&
			(thumbUrl == rhs.thumbUrl) && (mainUrl == rhs.mainUrl) && (encryptKey == rhs.encryptKey) &&
			(isDelay == rhs.isDelay);

	}
public:
	bool isDelay;			///<是否延迟消息
	int64 delayTime;        ///<延迟时间
	bool isReceipt;			///<是否阅后回执
	int width;				///<图像宽度
	int height;				///<图像高度
	std::string thumbUrl;	///<缩略图URL 一步发送消息时不赋值
	std::string mainUrl;	///<大图URL  一步发送消息时不赋值
	std::string thumbPath;	///<缩略图本地地址 一步发送消息时使用
	std::string mainPath;	///<大图本地地址 一步发送消息时使用
	std::string encryptKey;///<加密KEY
	int8 sendPasswdWithoutEncrypt;   ///<只发送秘钥，不进行加密 0.加密文件 1.不实际加密文件 
	std::string fileName;   ///<文件名  
	bool isCmd; ///<是否是指令消息
	std::string imageContents;///<图片描述
	int32        docID;       ///是否加密
	int64       validity;    ///附件有效期
	int64 size;				///<文件大小  
	std::string thumBbinary;  ///缩略图二进制

	int64 buddyId;    ///<九宫格消息使用
	bool isOld;      ///<是否是老的形式(非一步发送)

	int8 bwdType;           ///<敏感词类型
	std::vector<std::string> bwds;///<敏感词集合
	int8 isOverdue;         ///< 服务器路径是否过期，1.过期，0.未过期
	int8 isOriImg;    //是否是原图，0、不是 1、是

	std::string md5Code;	//原图MD5值，校验用，发图片时不用传
	std::string thumbMd5;	//缩略图Md5值

	//以下iOS专用字段
	std::string relaThumbPath;	///< 相对路径
	std::string relaPath;
};

///动态表情
class MsgDynExpression : public Msg 
{
public:
	MsgDynExpression()
	{ 
		msgType = MSG_TYPE_DYNEXPRESSION; 
	}
	MsgDynExpression(Msg& msg) :Msg(msg)
	{
		msgType = MSG_TYPE_DYNEXPRESSION;
	}
	~MsgDynExpression(){}
};

class MsgCard : public Msg
{
public:
	MsgCard() :isDelay(false), delayTime(0), isReceipt(false)
	{
		msgType = MSG_TYPE_CARD;
		mediaUrl.resize(MSGMEMSIZE*2);
	}
	MsgCard(Msg& msg) :Msg(msg), isDelay(false), delayTime(0), isReceipt(false)
	{
		msgType = MSG_TYPE_CARD;
	}
	~MsgCard(){}

	bool isDelay;			///<是否延迟消息
	int64 delayTime;        ///<延迟时间
	bool isReceipt;			///<是否阅后回执
	std::string mediaUrl;	///<名片url
};
///tip消息
class MsgTip : public Msg 
{
public:
	MsgTip() :tipType(0), operType(0), forbidOperateType(0), forbidOperUserType(0)
	{ 
		msgType = MSG_TYPE_TIP; 
		tipTime.resize(MSGMEMSIZE);
		operUser.resize(MSGMEMSIZE);
		userInfo.resize(MSGMEMSIZE);
		fileInfo.resize(MSGMEMSIZE);
		status.resize(MSGMEMSIZE);
	}
	MsgTip(Msg& msg) :Msg(msg), tipType(0), operType(0), forbidOperateType(0), forbidOperUserType(0)
	{
		msgType = MSG_TYPE_TIP;
	}
	~MsgTip(){}
	bool operator == (const MsgTip& rhs) const 
	{
		return (tipType == rhs.tipType) && (operType == rhs.operType) && (tipTime == rhs.tipTime) &&
			(operUser == rhs.operUser) && (userInfo == rhs.userInfo) &&
			(forbidOperateType == rhs.forbidOperateType) && (forbidOperUserType == rhs.forbidOperUserType) && (status == rhs.status);
	}

	int tipType; ///<tip 类型
	int operType;///<操作类型
	std::string tipTime;///<时间
	std::string operUser;///<操作userId
	std::string userInfo;///<用户信息
	std::string fileInfo;///<文件信息
	std::string status;//消息状态
	int forbidOperateType;  ///<群禁言操作标示：1，解除群禁言 2，设置群禁言 3，解除群成员禁言 4，设置群成员禁言；目前因为msgProperty中该字段过于简单，容易被复用，先设置数据为0提示用户有这个值，msgProperty取值，json字段operate
	int forbidOperUserType; ///<群禁言操作人类型：1，普通用户 2，管理员 3，群主；目前因为msgProperty中该字段过于简单，容易被复用，先设置数据为0提示用户有这个值，msgProperty取值，json字段operUserType
};

///网页消息
class MsgWeb : public Msg
{
public:
	MsgWeb()
	{
		msgType = MSG_TYPE_WEB;
		title.resize(MSGMEMSIZE);
		url.resize(MSGMEMSIZE);
		img.resize(MSGMEMSIZE);
		desc.resize(MSGMEMSIZE*2);
	}
	MsgWeb(Msg& msg) :Msg(msg)
	{
		msgType = MSG_TYPE_WEB;
	}
	~MsgWeb(){}
	bool operator == (const MsgWeb& rhs) const
	{
		return (title == rhs.title) && (url == rhs.url) && (img == rhs.img) && (desc == rhs.desc);
	}

	std::string title;	 ///<网页内容标题
	std::string url;	 ///<网页链接地址
	std::string img;	 ///<网页内容第一张图片
	std::string desc;	 ///<网页内容摘要
};

///回执消息
class MsgRevoke : public Msg 
{
public:
    MsgRevoke() :revokeMsgId(0), adminRevoke(0)
	{ 
		msgType = MSG_TYPE_REVOKE; 
	}
    MsgRevoke(Msg& msg) :Msg(msg), revokeMsgId(0), adminRevoke(0)
	{
		msgType = MSG_TYPE_REVOKE;
	}
	~MsgRevoke(){}

	bool operator == (const MsgRevoke& rhs) const 
	{
		if (revokeMsgId != rhs.revokeMsgId)
			return false;
        if (adminRevoke != rhs.adminRevoke)
            return false;
		return true;
	}
public:
	int64 revokeMsgId;///<id
    int8 adminRevoke; ///<是否管理员撤回 1-是 0-否
	std::string revokedBody;  ///< 撤回的消息的body(只有撤回文本消息时使用，用于撤回消息重编辑)
};
///音频消息
class MsgAudio :public Msg{
public:
	MsgAudio() :mediaTime(0), status(0), isOld(false), validity(0), isOverdue(0), size(0), sendPasswdWithoutEncrypt(0){
		msgType = MSG_TYPE_AUDIO;
		fileName.resize(MSGMEMSIZE);
		meidaUrl.resize(MSGMEMSIZE);
		encryptKey.resize(MSGMEMSIZE);
		localPath.resize(MSGMEMSIZE);
	}
	MsgAudio(Msg& msg) :Msg(msg), mediaTime(0), status(0), isOld(false), validity(0), isOverdue(0), sendPasswdWithoutEncrypt(0){
		msgType = MSG_TYPE_AUDIO;
	}
	bool operator == (const MsgAudio& rhs) const
	{
		return (mediaTime == rhs.mediaTime) && (fileName == rhs.fileName) && (meidaUrl == rhs.meidaUrl) && (status == rhs.status);
	}
	~MsgAudio(){};

	int32 mediaTime;			///<时长
	std::string fileName;    ///<文件名
	std::string meidaUrl;      ///<路径
	int8 sendPasswdWithoutEncrypt;   ///<只发送秘钥，不进行加密 0.加密文件 1.不实际加密文件 
	std::string encryptKey;///<加密KEY
	int status;    ///<ui层用，标志是否需要显示小红点 0、不需要 1、需要 
	std::string localPath;		//音频本地路径 
	int64       validity;      ///附件有效期
	int64 size;				///<文件大小  

	bool isOld;      ///<是否是老的消息(非一步发送)
	int8 isOverdue;  ///< 服务器路径是否过期，1.过期，0.未过期
	std::string md5Code;	//加密后MD5值，校验用，发语音时不用传

	//以下iOS专用字段
	std::string relaPath;	///< 相对路径
};


///图文消息
struct picTextBean{
	picTextBean() :index(0){}
	int32 index;
	std::string picUrl;///<图片url
	std::string title;///<标题
	std::string url;///<url
	std::string dsc;///<描述

	bool operator == (const picTextBean& rhs) const
	{
		return (index == rhs.index) && (picUrl == rhs.picUrl) && (title == rhs.title) && (url == rhs.url) && (dsc==rhs.dsc);
	}
};
///图文消息
class MsgPicWithText :public Msg{
public:
	MsgPicWithText(){
		msgType = MSG_TYPE_PICTEXT;
	}
	MsgPicWithText(Msg& msg) : Msg(msg){
		msgType = MSG_TYPE_PICTEXT;
	}

	bool operator == (const MsgPicWithText& rhs) const
	{
		return (vtPtBean == rhs.vtPtBean);
	}
	~MsgPicWithText(){}

	std::vector<picTextBean> vtPtBean;///<消息集合
};


class MsgDynExpression2 :public Msg{
public:
	MsgDynExpression2() :DyType(0), textSize(0){
		msgType = MSG_TYPE_DYNEXPRESSION2;
		code.resize(MSGMEMSIZE);
		emoji.resize(MSGMEMSIZE);
		mdCode.resize(MSGMEMSIZE);
		meaning.resize(MSGMEMSIZE);
		thumbnailUrl.resize(MSGMEMSIZE);
		elogo.resize(MSGMEMSIZE);
		domainPort.resize(MSGMEMSIZE);
		gifPath.resize(MSGMEMSIZE);
		pngPath.resize(MSGMEMSIZE);
	}
	std::string code;
	std::string emoji;
	std::string mdCode;
	std::string meaning;
	int8 DyType;
	int textSize;

	std::string thumbnailUrl;
	std::string elogo;
	std::string domainPort;
	std::string gifPath;
    std::string pngPath;



};
class MsgTask :public Msg{
public:
	MsgTask(){
		msgType = MSG_TYPE_TASK;
		timeTask.resize(MSGMEMSIZE);
		isFinish.resize(MSGMEMSIZE);
		isTask.resize(MSGMEMSIZE);
		isRead.resize(MSGMEMSIZE);
		fontSize = 0;
	}
	~MsgTask(){}
	std::string timeTask;
	std::string isFinish;
	std::string isTask;
	std::string isRead;
	int fontSize;
    int8 bwdType;                 ///<敏感词类型(发送不用传)
    std::vector<std::string> bwds;///<敏感词集合(发送不用传)
};

struct st_Masterplate {
	std::string content;
	std::string num;
	std::string proposer;
	std::string approver;
};
class MsgMasterplate :public Msg{
public:
	MsgMasterplate() :createTime(0), forwardConfig(0), taskID(0){
		msgType = MSG_TYPE_TEMPL;
		content.reserve(MSGMEMSIZE);
		detailUrl.reserve(MSGMEMSIZE);
		title.reserve(MSGMEMSIZE);
		toUsers.reserve(MSGMEMSIZE);
		status.reserve(MSGMEMSIZE);
		statColor.reserve(MSGMEMSIZE);
		titleColor.reserve(MSGMEMSIZE);
		type.reserve(MSGMEMSIZE);
		titleBGColor.reserve(MSGMEMSIZE);
		fields.reserve(MSGMEMSIZE * 2);
		creator.reserve(MSGMEMSIZE);
		bId.reserve(MSGMEMSIZE);
		mToken.reserve(MSGMEMSIZE);
		buttons.reserve(MSGMEMSIZE * 2);
		eventData.reserve(MSGMEMSIZE * 2);
		isShowSession.reserve(MSGMEMSIZE);
	}
	std::string  content;
	int64 createTime;
	std::string detailUrl;
	std::string title;
	std::string  toUsers;
	std::string status;
	std::string statColor;
	std::string titleColor;
	std::string type;
	std::string titleBGColor;
	std::string fields;
	std::string creator;
	std::string mToken;    //模板消息的消息ID，多条按钮消息可能是同一个bid，使用mToken区分
	std::string bId; //模板消息的审记ID，应用提供的，一个申请可能拒绝多次，此ID用来判断为同一个申请

	//按钮操作记录，json的string类型，内容格式List<Map<String,String>>，map key包含 _1enname按钮英文名，客户端需要国际化 _2cname按钮中文名，客户端需要国际化 _3eventType事件，同意，拒绝 _4isInput是否弹出输入框，例如拒绝需要理由
	//举例 "buttons":[{"cnName":"同意", "isInput" : "false", "enName" : "agree", "eventType" : "1"}, { "cnName":"取消", "isInput" : "true", "enName" : "cancel", "eventType" : "2" }]
	//发送消息给服务器时不需要buttons
	std::string buttons;  

	//审批的结果，json的string类型，内容格式Map<String,String>，map key包含 _1enname按钮英文名，客户端需要国际化 _2cname按钮中文名，客户端需要国际化 _3eventType事件，同意，拒绝 _4code服务器错误码
	//比如点击同意后，客户端发送内容为 {"eventType" : "1"}
	//比如ddio url出错，服务器返回为{"code" : "1001"}
	//比如应用审批后，通过服务器返回为{"cnName":"已结束",  "enName" : "over"}
	std::string eventData; 

	//客户端根据该字段判断展示位置，1，只展示会话不展示工作台，2只展示工作台不展示会话，3展示工作台和会话，4不展示工作台也不展示会话
	std::string isShowSession;


	int forwardConfig; ///是否可以转发 1 禁止，2 可以 默认2可以转发
	int64	taskID; ///消息任务ID
};


class MsgActionCard :public Msg{
public:
	MsgActionCard() : taskID(0),isShowSession(0){
		msgType = MSG_TYPE_ACTIONCARD;
		title.reserve(MSGMEMSIZE);
		content.reserve(MSGMEMSIZE*2);
		bID.reserve(MSGMEMSIZE);
		fileds.reserve(MSGMEMSIZE*2);
		button.reserve(MSGMEMSIZE*2);
		detailUrl.reserve(MSGMEMSIZE*2);
		picUrl.reserve(MSGMEMSIZE*2);
		userList.reserve(MSGMEMSIZE*2);
		tag.reserve(MSGMEMSIZE);
	}
	int64	taskID; ///消息任务ID

	std::string title; // 标题
	std::string	content; // 内容说明
	std::string	bID; //  业务方自己的唯一主键
	std::string	fileds; // 补充的内容, markdown形式展示
	std::string	button; // 业务动作，确定；其他业务可以扩展多个动作
	std::string	detailUrl; //  消息正文的链接URL
	std::string	picUrl; // 消息中的图片
	std::string	userList; //  参与人员, 多个人员逗号分隔
	int	isShowSession; // 客户端根据该字段判断展示位置(1展示会话不展示工作台; 2不展示会话, 展示工作台; 3展示会话和工作台; 4不展示会话和工作台)
	std::string tag; // 消息标签，最多支持4个中文字符，12个英文字符, 最多支持6个
};


class MsgMiniVedio :public Msg{
public:
	MsgMiniVedio() :buddyId(0), brustFlag(0), vedioHight(0), vedioLenth(0), vedioWideth(0), vedioSize(0), validity(0), isOverdue(0), sendPasswdWithoutEncrypt(0){
		msgType = MSG_TYPE_MINIVEDIO;
		preImgPath.resize(MSGMEMSIZE);
		vedioFileName.resize(MSGMEMSIZE);
		localPreImgPath.resize(MSGMEMSIZE);
		localVedioPath.resize(MSGMEMSIZE);
		encryptKey.resize(MSGMEMSIZE);
	}
	int64 buddyId;					///< 接收人ID
	int8 brustFlag;					///< 是否阅后即焚
	std::string preImgPath;			///< 预览图片服务器地址  一步发送消息时不赋值
	std::string vedioFileName;		///< 视频服务器地址	 一步发送消息时不赋值
	std::string localPreImgPath;	///< 本地预览图片路径 一步发送消息时使用
	std::string localVedioPath;		///< 本地视频路径	一步发送消息时使用
	int64 vedioHight;				///< 视频分辨率高
	int64 vedioLenth;				///< 视频长, （毫秒）
	int64 vedioWideth;				///< 视频分比率宽
	int64 vedioSize;				///< 视频大小（Byte）
	int8 sendPasswdWithoutEncrypt;   ///<只发送秘钥，不进行加密 0.加密文件 1.不实际加密文件 
	std::string encryptKey;         ///<加密KEY
	int32       docID;              ///< 是否加密
	int64       validity;           ///<附件有效期
	int8 isOverdue;                 ///< 服务器路径是否过期，1.过期，0.未过期

	std::string md5Code;	//原视频MD5值，校验用，发消息时不用传
	std::string thumbMd5;	//缩略图Md5值

	//以下iOS专用字段
	std::string relaThumbPath;	///< 相对路径
	std::string relaPath;
};

struct ImgMsgInner{

	ImgMsgInner() :docID(1), toId(0), fromId(0), msgType(MSG_TYPE_IMG), msgId(0), time(0), 
	height(0), width(0), buddyId(0), isDelay(0), delayTime(0), isCmd(false), isOverdue(0),isOriImg(0),size(0),sendPasswdWithoutEncrypt(0) {}
	int64 toId;
	int64 fromId;
	std::string userName;
	std::string userPic;
	int64   msgType;
	int64   msgId;
	int64   time;

	std::string encryptKey;
	int8 sendPasswdWithoutEncrypt;   ///<只发送秘钥，不进行加密 0.加密文件 1.不实际加密文件 
	std::string fileName;
	int height;
	int width;
	int64 size;
	std::string mainUrl;
	std::string thumbUrl;
	std::string body;
	int64 buddyId;
	std::string mainPath;
	std::string thumbPath;
	int32       docID;

	bool isDelay;			///<是否延迟消息
	int64 delayTime;        ///<延迟时间
	bool isCmd; ///<是否是指令消息
	std::string imageContents;///<图片描述
	int8 isOverdue;         ///< 服务器路径是否过期，1.过期，0.未过期
	int8 isOriImg;    //是否是原图，0、不是 1、是
	std::string md5Code;	//原图MD5值，校验用，发图片时不用传
	std::string thumbMd5;	//缩略图Md5值
};

 
struct TextMsgInner{
	TextMsgInner() :toId(0), fromId(0), msgType(MSG_TYPE_TEXT), msgId(0), time(0), isRbtMsg(false), isDelay(false), delayTime(0), isReceipt(false){}
	int64 toId;
	int64 fromId;
	std::string userName;
	std::string userPic;
	int64   msgType;
	int64   msgId;
	int64   time;

	bool isRbtMsg;           ///<是否是机器人消息
	bool isDelay;			///<是否延迟消息
	int64 delayTime;        ///<延迟时间
	bool isReceipt;			///<是否阅后回执
	std::string  body;      ///<消息体
};

struct AudioMsgInner{
	AudioMsgInner() :toId(0), fromId(0), msgType(MSG_TYPE_AUDIO), msgId(0), time(0), 
	mediaTime(0), status(0), isOverdue(0),size(0){}
	int64 toId;
	int64 fromId;
	std::string userName;
	std::string userPic;
	int64   msgType;
	int64   msgId;
	int64   time;
	int64 size;

	int32 mediaTime;			///<时长
	std::string fileName;    ///<文件名
	std::string meidaUrl;      ///<路径
	std::string encryptKey;///<加密KEY
	int status;    ///<ui层用，标志是否需要显示小红点 0、不需要 1、需要 
	std::string localPath;		//音频本地路径 
	int8 isOverdue;  ///< 服务器路径是否过期，1.过期，0.未过期
};

struct PositionMsgInner{
	PositionMsgInner() :toId(0), fromId(0), msgType(MSG_TYPE_POSITION), msgId(0), time(0), isDelay(false), delayTime(0), latitude(0), longitude(0){}
	int64 toId;
	int64 fromId;
	std::string userName;
	std::string userPic;
	int64   msgType;
	int64   msgId;
	int64   time;

	bool isDelay;			///<是否延迟消息
	int64 delayTime;        ///<延迟时间
	std::string name;		///<地名
	double latitude;		///<纬度
	double longitude;		///<经度
};
class MsgConference:public Msg{

public:
	MsgConference() :conferType(0){
		msgType = MSG_TYPE_CONFER;
	}
	std::string comment;	//VideoStatus
	int8 conferType;			//VideoType
	//std::string conferType;		//int8类型错误修改  [3/18/2021 zhuohc]

	//密话增加字段  [3/18/2021 zhuohc]
	//std::string secretBody;		///<密话字段
	//std::string bodyType;	///<
	//std::string annotation;	///<
	//std::string senderId;		///<
	//std::string onwerId;		///<
	//std::string roomId;			///<
	////std::string bodyDeviceType;		///<Msg结构体有
	//std::string version;			///<
	//std::string rtcType;			///<
};
///应用分享消息
class MsgAppShare : public Msg
{
public:
	MsgAppShare()
	{
		msgType = MSG_TYPE_APPSHARE;
	}
	MsgAppShare(Msg& msg) :Msg(msg)
	{
		msgType = MSG_TYPE_APPSHARE;
	}
	~MsgAppShare(){}
};

#if (defined SDK_FOR_ANDROID) || (defined OEM_OS_YUANXIN)
class MsgNineBlock :public Msg{
public:
	MsgNineBlock():validity(0), isOverdue(0){
		msgType = MSG_TYPE_NINEBLOCK;
	}
	std::vector<ImgMsgInner> nine;
	int64   validity; ///附件有效期
	int8 isOverdue;  ///< 服务器路径是否过期，1.过期，0.未过期
};
class MsgCombine :public Msg{
public:
	MsgCombine():totoalMsgPiece(1),currentMsgPiece(1),combineMsgGroupId(0){
		msgType = MSG_TYPE_COMBINE;
		bwdType = -1;
	}
	~MsgCombine(){}
	std::vector<MsgText> mVt_TextMsg;
	std::vector<MsgImg> mVt_ImgMsg;
	std::vector<MsgWeb> mVt_WebMsg;
	std::vector<MsgAudio> mVt_AudMsg;
	std::vector<MsgPosition> mVt_PosMsg;
	std::vector<MsgFile> mVt_FileMsg;
	std::vector<MsgCard> mVt_CardMsg;
	std::vector<MsgTip> mVt_TipMsg;
	std::vector<MsgPicWithText> mVt_PicTextMsg;
	std::vector<MsgDynExpression> mVt_Dy1Msg;
	std::vector<MsgVoice> mVt_VoiceMsg;
	std::vector<MsgTask> mVt_TaskMsg;
	std::vector<MsgMasterplate> mVt_TemlMsg;
	std::vector<MsgMiniVedio> mVt_MiniVedioMsg;
	std::vector<MsgNineBlock> mVt_NineMsg;
	std::vector<MsgDynExpression2> mVt_Dy2Msg;
	std::vector<MsgAppShare> mVt_AppShareMsg;

	int8 bwdType;                
	std::vector<std::string> bwds;
	int totoalMsgPiece; //多个组合消息总分片数
	int currentMsgPiece;//当前发送的组合消息的分片
	int64 combineMsgGroupId;//组合消息的组Id
};
#else
class MsgCombine :public Msg{
public:
	MsgCombine() :totoalMsgPiece(1), currentMsgPiece(1), combineMsgGroupId(0){
		msgType = MSG_TYPE_COMBINE;
		bwdType = -1;
	}
	~MsgCombine(){}
	std::vector<SSharedPtr<Msg> > mVt_msg;	
	int8 bwdType;                 ///<敏感词类型(发送不用传)
	std::vector<std::string> bwds;///<敏感词集合(发送不用传)
	int totoalMsgPiece; //多条组合消息总分片数
	int currentMsgPiece;//当前发送的组合消息的分片
	int64 combineMsgGroupId;// 多条组合消息的组id
};
class MsgNineBlock :public Msg{
public:
	MsgNineBlock() :validity(0), isOverdue(0){
		msgType = MSG_TYPE_NINEBLOCK;
	}
	std::vector<MsgImg> nine;
	int64   validity; ///附件有效期
	int8 isOverdue;  ///< 服务器路径是否过期，1.过期，0.未过期
};

#endif

class MsgNotebook :public MsgCombine{
public:
	MsgNotebook(){
		msgType = MSG_TYPE_NOTEBOOK;
	}
	int64 notebookId;
	std::string noteTitle;
	~MsgNotebook(){}
};
///接收方可以单发，可以群发。发送方地址需要注意，必须是豆豆号@本服务器域名
class MsgMail :public Msg{
public:
	MsgMail(){
		msgType = MSG_TYPE_MAIL;
	}
	~MsgMail(){}
	std::string senderName;///<发送者
	std::string senderAddress;//<发送者邮箱
	std::string subject;///<邮件主题
	std::string content;///<邮件内容
	std::vector<std::string> receivers;///<接收者
};

class MsgRedPacket :public Msg{
public:
	MsgRedPacket(){
	msgType	= MSG_TYPE_REDPACKET;
	}	 
	~MsgRedPacket(){}
	std::string typeSendHongBao;///<1、拼手气红包 2、普通红包3、口令红包
	std::string myHongBaoId; 
};

///万能消息
class MsgUniversal : public Msg
{
public:
	MsgUniversal()
	{
		msgType = MSG_TYPE_UNIVERSAL;
	}
	MsgUniversal(Msg& msg) :Msg(msg)
	{
		msgType = MSG_TYPE_UNIVERSAL;
	}
	~MsgUniversal(){}
};
///json数据异常消息类型 PC专用
class MsgJsonErr: public Msg
{
public:
	MsgJsonErr()
	{
	}
	MsgJsonErr(Msg& msg) :Msg(msg)
	{
	}
	void clearBody() {
		body = "{}";
		msgType = -msgType;
	}
	void clearMsgProperties() {
		msgProperties= "{}";
		msgType = -msgType;
	}
	~MsgJsonErr() {}
};

typedef SSharedPtr<Msg> MsgPtr;

template<typename T>
T& msgCast(Msg& val){ return dynamic_cast<T&>(val); }

template <typename T>
SSharedPtr<T> msgPointCast(MsgPtr val){ return std::dynamic_pointer_cast<T>(val); }
	
} /*namespace model*/