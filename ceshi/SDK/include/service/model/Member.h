#pragma once
#include "User.h"
#include <string>
#include <vector>
namespace model
{
///群成员
class Member : public User 
{
public:
	Member() :groupId(0), team(0), memberType(0), isApp(false), timeForbidUtil(0)
	{}
	virtual void init(){}
	
	bool operator == (const Member& rhs) const
	{
		return (groupId == rhs.groupId) && (team == rhs.team) && (isApp == rhs.isApp) &&
			(memberType == rhs.memberType) && (remark == rhs.remark) && (timeForbidUtil == rhs.timeForbidUtil) && (userStatus == rhs.userStatus);
	}
public:
	Optional<int64> groupId;		///<群id
	Optional<int>  team;			///<分组
	Optional<int8> memberType;		///<成员类型：1.普通 2.管理员 3.超级管理员
	Optional<bool> isApp;			///<是否为机器人
	Optional<std::string> remark;   ///<群备注
	Optional<std::string> pingyin;			///<拼音
	Optional<int64> timeForbidUtil;        ///<群成员禁言的截止时间，-1或0表示不禁言，毫秒为单位

};
/**
* \struct st_shieldGroupMessage
* \brief  群信息提示方式
*/
struct ShieldGroupMessage {
	ShieldGroupMessage() :pcMsgSet(0), phoneMsgSet(0), htmlMsgSet(0), groupMessageContentMode(0){}
	int8 pcMsgSet;			 ///< PC群消息设置 1：提示接收 2：不提示，显示数目 3：屏蔽消息 4：时间段接收 5：插电接收 pcMsgSet.
	int8 phoneMsgSet;			 ///< phone/pad群消息设置 1：提示接收 2：不提示，显示数目 3：屏蔽消息 4：时间段接收 5：插电接收 phoneMsgSet.
	int8 htmlMsgSet;			 ///< HTML群消息设置 1：提示接收 2：不提示，显示数目 3：屏蔽消息 4：时间段接收 5：插电接收 htmlMsgSet.
	int8 groupMessageContentMode; ///< 群通知消息内容模式: 1、通知详情  2、通知源，隐藏内容  3、完全隐藏 , 默认开启模式1
	std::string msgRecvTime;	 ///< 接收消息时间段 msgRecvTime.
};
class MemberDetailInfo 
{
public:
	int64 birthday;
	std::string name;   //用户名称
	std::string nickID;
	std::string vSign;  //< 是否为v标群，0不是 1是 只有当群成员为用户自己时使用	
	std::vector<std::string> phones;
	std::vector<std::string> emails;
	Member info;
	/**
	* \brief 如果获取的群成员是自己的话，这个字段的值有效。
	*/
	ShieldGroupMessage  shield;
};
}/*namespace model */
