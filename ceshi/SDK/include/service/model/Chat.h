#pragma once

#include "User.h"

///聊天类型
enum ChatType
{
	BUDDY_CHAT = 1,        ///<好友聊天
	GROUP_CHAT = 2,        ///<群组聊天
	APP_CHAT = 3,		   ///<公众号
	SYSTEM_MSG = 4,        ///<系统消息
	STRANGER_CHAT = 5,     ///<陌生人聊天
	ENT_USER_CHAT = 6,     ///<企业成员聊天
	PHONE_CHAT = 7,          ///<我的设备
	ENT_CHAT,				///<企业号
	APPLICATION_CHAT,		///<应用号
	MAIL_TYPE_CHAT,        ///<邮件号
	SMART_DEVICE_CHAT,     ///<智能设备号
};

namespace model
{
///聊天信息	
class Chat : public User 
{
public:
	Chat() :msgType(0), chatType(0), operType(0), subType(0), unreadCount(0), lastMsgId(0), msgTime(0), msgRemindMode(1), lastAtMsgID(0), 
		realUnReadCnt(0), sendUserId(0), disturbSet(0), memberIsVSign(0), triggerType(0), isTop(0), isHidden(0), bpursuit(0)
	{
	}
	void init(){}
	bool operator == (const Chat &rhs) const 
	{
		return (msgType == rhs.msgType) && (chatType == rhs.chatType) &&
			(operType == rhs.operType) && (subType == rhs.subType) && (unreadCount == rhs.unreadCount) &&
			(lastMsgId == rhs.lastMsgId) && (msgTime == rhs.msgTime) && (lastMsg == rhs.lastMsg) && (triggerType == rhs.triggerType) &&
			(whereFrom == rhs.whereFrom) && (lastAtMsgID == rhs.lastAtMsgID) && (msgProp == rhs.msgProp) && (realUnReadCnt == rhs.realUnReadCnt) && (bpursuit == rhs.bpursuit);
	}
public:
	int msgType;		  ///<消息类型;1：HTML, 2:TEXT, 3：AUDIO, 4：POSITION, 5：IMG, 6：FILE, 7：CARD,  8：TIP
	int chatType;	      ///<聊天类型  1人，2群，3公众号，8企业号,9应用号
	int operType;         ///<1为阅后即焚
	int8 isTop;			  ///是否置顶 0.非置顶 1.置顶
	int8_t isHidden;	  ///是否隐藏 0.否 1.是
	int subType;          ///<系统消息子类型
	int triggerType;	  ///<最近联系人触发类型 0.手动添加 1.消息触发 2.置顶触发 3.设置已读触发
	int unreadCount;      ///<未读消息数量
	int32  realUnReadCnt; ///< 真正的未读消息数量 = unReadCnt+弱提示消息数量+其它端同步的设备消息数量，客户端每次拉取未读用这个字段，当realUnReadCnt为0时，表示所有消息在当前设备客户端都已经看过了
	///< 消息提醒模式 与0x0F 0.免打扰 1.提醒始终有声音  2.提醒始终无声音  3.提醒  4.不提醒，仅显示条目 5.根据免打扰时间段判断是否免打扰  6.强制提醒(仅群有效)
	//< 与 0xF0, 1、通知详情  2、通知源，隐藏内容  3、完全隐藏  4、云推推过了，不显示通知
	int8 msgRemindMode;
	int8 disturbSet;		///<免打扰 1为接收提醒, 2表示不提醒仅显示数字, 3为免打扰
	int64 lastMsgId;      ///<最后一条消息ID
	int64 lastAtMsgID;	  ///<最后一条@消息ID
	bool memberIsVSign;	  ///<发消息的群成员是否为v标好友
	int64 msgTime;        ///<消息时间
	std::string whereFrom;///< 消息来源 在群的时候有用 
	std::string lastMsg;  ///<最后一条消息
	std::string msgProp;  ///<消息属性
	int64  sendUserId;    ///< 发送者Id
	int8 bpursuit;  //追一下字段
};
///本地敏感词表
struct st_dbBadWord{
	st_dbBadWord() {
	}

	std::string badword;								///<关键字
	int64 bwlibid;									///< 关键字词库id
};

///本地敏感词库表
struct st_dbBWLib{
	st_dbBWLib() {
	}

	int64 bwlibid;								///<关键字词库id
	int8 bused;									///< 关键字词库是否开启 0：关闭 1：开启
};
} /*namespace model */