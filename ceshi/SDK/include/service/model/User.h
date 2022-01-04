#pragma once

//#include "SDKTypes.h"
//#include "Optional.h"
//#include <string>
#include "../extModel/packet.h"

namespace model
{
///用户信息
class User 
{
public:
	User() : gender(0), timeZone(0), id(0), status(0), userStatus(0)
	{}
	virtual ~User(){}
	virtual void init(){}


	bool operator == (const User & rhs) const
	{
		return (gender == rhs.gender) && (timeZone == rhs.timeZone) && (id == rhs.id) &&
			(name == rhs.name) && (avatar == rhs.avatar) && (extends == rhs.extends) && (orgIds == rhs.orgIds) &&
			(entExtends == rhs.entExtends) && (thumbAvatar == rhs.thumbAvatar) && (avatarUrl == rhs.avatarUrl) &&
			(thumbAvatarUrl == rhs.thumbAvatarUrl) && (orgList == rhs.orgList) && (securityLevel == rhs.securityLevel) && (status == rhs.status) && (tagIds == rhs.tagIds) && (userStatus == rhs.userStatus);
	}

public:
	Optional<int> securityLevel;			///密信等级
	Optional<int> gender;					///<性别:1男2女0保密
	Optional<int> timeZone;					///<时区
	Optional<int64> id;						///<id
	Optional<std::string> name;				///<名称
	Optional<std::string> avatar;			///<原图图像
	Optional<std::string> extends;			///<扩展字段,搜索返回用该字段表示最新消息时间
	Optional<std::string> entExtends;        ///<企业扩展信息
	Optional<std::string> orgIds;		///<组织结构id,多个用逗号分隔
	Optional<std::string> thumbAvatar;		///<缩略图
	Optional<std::string> avatarUrl;		///<原图url
	Optional<std::string> thumbAvatarUrl;	///<缩略图url
	Optional<std::vector<model::OrganizationInfo> > orgList;    ///组织信息，只有searchFromNet接口和getUserInfoByScene接口返回才会带此数据
	Optional<int> status;                 /// 是否是本服务人员，外服为4

	Optional<std::string> tagIds;				///<用户标签id,多个用逗号分隔
	Optional<int8> userStatus;                 /// 禁用状态标记
};

typedef SSharedPtr<User> UserPtr;


} /*namespace model*/
