#pragma once
#include "User.h"
//#include "../extModel/packet.h"
//#include "../extModel/extpacket.h"
#include <vector>

namespace model
{

struct _Contact__isset 
{
	_Contact__isset() :isStar(false), isVip(false), pinyin(false), remark(false), server(false), team(false)
	{}
	bool isStar;
	bool isVip;
	bool pinyin;
	bool remark;
	bool server;
	bool team;
};
///联系人
class Contact : public User 
{
public:
	Contact() :isStar(0), isApp(0), birthday(0), isHidden(0), disturbSet(0)
	{}

	void init(){
		User::init();
	}

	bool operator == (const Contact & rhs) const
	{
		return (isStar == rhs.isStar) && (isApp == rhs.isApp) && (pinyin == rhs.pinyin) && 
			(acountName == rhs.acountName) && (remark == rhs.remark) && (server == rhs.server) && 
			(birthday == rhs.birthday) && (emails == rhs.emails) && (phones == rhs.phones) &&
			(chatImg == rhs.chatImg) && (privateMsgPwd == rhs.privateMsgPwd) &&
			(sign == rhs.sign) && (area == rhs.area) && (isHidden == rhs.isHidden) && (userStatus == rhs.userStatus);
	}

public:
	Optional<int8> isStar;					 ///<星标好友：1.星标好友，2.不是星标
	Optional<int8> isApp;					 ///<是否是应用 1.是,  2.否
	Optional<int8> isHidden;				 ///<是否是隐藏好友 1.是,  2.否
	Optional<int8> disturbSet;				 ///<免打扰 1为接收提醒, 2表示不提醒仅显示数字, 3为免打扰
	Optional<bool> isTop;					 ///<是否置顶
	Optional<std::string> pinyin;			 ///<名称拼音
	Optional<std::string> acountName;		 ///<豆豆账号
	Optional<std::string> remark;			 ///<备注
	Optional<std::string> server;			 ///<服务器
	Optional<int64> birthday;				 ///<生日
	Optional<std::string> chatImg;			 ///<聊天背景
	Optional<std::string> sign;				///<签名
	Optional<std::string> area;				///<地区
	Optional<std::string> privateMsgPwd;	 ///<私信秘钥
	Optional<std::vector<std::string> > emails;	 ///<邮件
	Optional<std::vector<std::string> > phones;	 ///<电话
	Optional<std::vector<model::AccountType> > accounts;        ///<账号
	//Optional<std::vector<model::OrganizationInfo> > orgList;    ///组织信息，只有getUserInfoByScene接口返回才会带此数据
};

} /*namespace model */
