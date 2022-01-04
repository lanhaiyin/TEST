#pragma once
#include "TinyGroup.h"

namespace model 
{
///群组
class Group 
{
public:
	Group() :createTime(0), relatedGroupId(0), relatedEntId(0), memberNums(0), isSearch(false),
		groupMessageContentMode(0), disturbSet(0), timeForbidUtil(0)
	{}
	virtual void init(){}

	
	bool operator == (const Group &rhs) const
	{
		return (brief == rhs.brief) && (bulletin == rhs.bulletin) && (extend == rhs.extend) && 
			(createTime == rhs.createTime) && (relatedGroupId == rhs.relatedGroupId) &&
			(relatedEntId == rhs.relatedEntId) && (memberNums == rhs.memberNums) &&
			(isSearch == rhs.isSearch) && (groupMessageContentMode == rhs.groupMessageContentMode) &&
			(privateMsgPwd == rhs.privateMsgPwd) && (info == rhs.info) && (disturbSet == rhs.disturbSet) && (timeForbidUtil == rhs.timeForbidUtil);
	}

public:
	Optional<std::string> brief;			///<群简介
	Optional<std::string> bulletin;			///<群公告
	Optional<std::string> extend;			///<群扩展字段
	Optional<int64> createTime;				///<创建时间
	Optional<int64> relatedGroupId;			///<关联群ID
	Optional<int64> relatedEntId;			///<关联企业ID，存在此ID则属于企业群
	Optional<int> memberNums;				///<群成员数量
	Optional<bool> isSearch;				///<是否允许被搜索
	Optional<int8> groupMessageContentMode; ///<群消息通知详情: 1、开启(显示详情)  2、关闭(显示通知源，隐藏内容)  默认开启 groupMessageContentMode.
	Optional<int8> personalMessageContentMode; ///<个人群消息通知详情: 1、通知详情  2、通知源，隐藏内容  3、完全隐藏
	Optional<int8> disturbSet;				///<免打扰 1为接收提醒, 2表示不提醒仅显示数字, 3为免打扰
	Optional<std::string> privateMsgPwd;	///<私信密码 
	Optional<std::string> chatImage;		///<群聊背景 
	Optional<int64> timeForbidUtil;		///<群禁言截止时间，-1或0表示不禁言，单位为毫秒 
	Optional<TinyGroup> info;				///<群信息
};

///群更新
class GroupUpdate
{
public:
	GroupUpdate() :groupSearch(0), groupMessageContentMode(0)
	{}

	Optional<std::string> groupName;				///<群名称
	Optional<std::string> groupIcon;				///<群图标
	Optional<std::string> groupBrief;				///<群简介
	Optional<std::string> groupBulletin;			///<群公告
	Optional<std::string> groupBackgroundURL;		///<群背景图片
	Optional<int8> groupSearch;						///<群是否可以被外部检索 1可以 2不可以
	Optional<int8> groupMessageContentMode;			///<群消息通知详情: 1、开启(显示详情)  2、关闭(显示通知源，隐藏内容)  默认开启
	/**群扩展字段,以json形式,目前：
	* 警种ID： policeTypeID
	* 地域---省份ID：provinceID
	* 地域---市ID： cityID
	* 私信模式：privateMsg：1为开启私信   0表示不允许私信
	* 群文件上传开关 groupFileSwitch: 1开启，2关闭	
	* 群文件上传权限	uploadFileRole :1群管理员，2全员
	*/
	Optional<std::string> extendProperties;
	Optional<int32> securityLevel;                 ///<群密级
	Optional<int32> powerSwitch;                   ///<提权开关 0关 1开
};

} /*namespace model */
