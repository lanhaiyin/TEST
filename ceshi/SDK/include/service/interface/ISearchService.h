#pragma once

#include "../model/Packet.h"
#include "../model/Group.h"
#include "../model/Contact.h"
#include "../model/Member.h"
#include "IService.h"
#include <string>

#define VER_SEARCH INTERFACE_VERSION(1,0)
static const VRVIID IID_ISearchService = { 0xe14e0da, 0xff4b, 0x4644, 0xbc, 0x3b, 0xd4, 0x50, 0x45, 0x6a, 0xff, 0x7b };

namespace service 
{

class ISearchService : public IService
{
public:

	virtual ~ISearchService(){}

	/**
	* \brief 从网络进行查找
	* @param[in] key 传入关键字
	* @param[in] cb 传入接收结果回调  _1错误信息  _2搜索结果
	*/
	virtual void searchFromNet(const std::string &key, SFunction<void(ErrorInfo,SearchResult&)> cb) = 0;

	/**
	* \brief 从本地数据库进行查找
	* @param[in] key 传入关键字
	* @param[in] cb 传入接收结果回调  _1错误信息  _2搜索结果
	*/
	virtual void searchFromLocal(const std::string &key, SFunction<void(ErrorInfo, SearchResult&)> cb) = 0;


	/**
	* \brief 根据类型从本地数据库进行查找
	* @param[in] key 传入关键字
	* @param[in] type 传入查询类型  _1联系人  _2群 _3组织机构 _4群内成员 _5联系人和群一起查 _6群和群成员一起查
	* @param[in] cb 传入接收结果回调  _1错误信息  _2搜索结果
	*/
	virtual void searchFromLocalWithType(const std::string &key,int8 type, SFunction<void(ErrorInfo, SearchResult&)> cb) = 0;

	/**
	* \brief 根据类型从本地数据库进行查找
	* @param[in] keys 传入关键字
	* @param[in] type 传入查询类型  _1联系人  _2群 _3组织机构 _4群内成员 _5联系人和群一起查 _6群和群成员一起查
	* @param[in] cb 传入接收结果回调  _1错误信息  _2搜索结果
	*/
	virtual void searchFromLocalWithMTypes(const std::vector<std::string> &keys, int8 type, SFunction<void(ErrorInfo, SearchResult&)> cb) = 0;

	/**
	* \brief 从本地数据库里搜索某个群内的群成员
	* @param[in] groupId 群id
	* @param[in] key 传入关键字
	* @param[in] cb 传入接收结果回调  _1错误信息  _2搜索结果
	*/
	virtual void groupSearchMember(int64 groupId, const std::string &key, SFunction<void(ErrorInfo, std::vector<Member>&)> cb) = 0;

	/**
	* \brief 通过用户ID获取陌生人信息
	* @param[in] userid 传入用户ID
	* @param[in] cb 传入接收结果回调  _1错误信息  _2用户信息
	*/
	virtual void getUserInfo(int64 userid, SFunction<void(ErrorInfo, Contact&)> cb) = 0;

	/**
	* \brief 通过用户ID网络获取好友信息
	* @param[in] userid 传入用户ID
	* @param[in] cb 传入接收结果回调  _1错误信息  _2用户信息
	*/
	virtual void getUserInfoEx(int64 userid, SFunction<void(ErrorInfo, Contact&)> cb) = 0;

	/**
	* \brief 通过用户ID网络获取好友信息可以指定下载的头像类型
	* @param[in] userid 传入用户ID
	* @param[in] dwnPortaitType 需要下载的头像类型  0 原图及缩略图全部下载 1 原图  2缩略图
	* @param[in] cb 传入接收结果回调  _1错误信息  _2用户信息
	*/
	virtual void getUserInfoEx(int64 userid, int32 dwnPortaitType, SFunction<void(ErrorInfo, Contact&)> cb) = 0;

	/**
	* \brief 通过用户ID网络获取好友信息，不下载头像
	* @param[in] userid 传入用户ID
	* @param[in] cb 传入接收结果回调  _1错误信息  _2用户信息
	*/
	virtual void getUserInfoWithoutDlHeadImg(int64 userid, SFunction<void(ErrorInfo, Contact&)> cb) = 0;
	
	/**
	* \brief 通过用户ID获取详细信息(同步接口)
	* @param[in] userid 传入用户ID
	* @param[in] info 具体信息
	*/
	virtual void getUserInfoSync(int64 userid, Contact& info) = 0;

	/**
	* \brief 根据客户端使用场景获取相应用户资料
	* @param[in] targetId 传入需要获取的ID
	* @param[in] userSence 用户场景 1：好友中点击 2：陌生人中点击 3：组织架构中点击
	* @param[in] info 具体信息
	*/
	virtual void getUserInfoByScene(int64 targetId, int8 userSence, SFunction<void(ErrorInfo, Contact&)> cb) = 0;

	/**
	* \brief 通过用户ID获取用户企业扩展信息（先查本地包括好友和陌生人）
	* @param[in] userid 传入用户ID
	* @param[in] cb 传入接收结果回调  _1错误信息  _2用户信息
	*/
	virtual void getUserEntExtendByID(int64 userid, SFunction<void(ErrorInfo, Contact&)> cb) = 0;
	/**
	* \brief 通过群ID获取详细信息
	* @param[in] groupId 传入群ID
	* @param[in] cb 传入接收结果回调  _1错误信息  _2群信息
	*/
	virtual void getGroupInfo(int64 groupId, SFunction<void(ErrorInfo, Group&)> cb) = 0;

	/**
	* \brief 全局查找消息
	* @param[in] key	   传入查找关键字
	* @param[in] msgProperty  传入查找的附加属性
	* @param[in] cb     传入接收结果回调  _1错误信息  _2消息搜索结果集合
	*/
	virtual void searchMessage(const std::string &key, MsgSearchProperty &msgProperty,
		SFunction<void(ErrorInfo, MsgSearchResult&)> cb) = 0;

	/**
	* \brief 查找相应targetID的详细消息
	* @param[in] key	   传入查找关键字
	* @param[in] msgDetailProperty  传入查找的附加属性
	* @param[in] cb     传入接收结果回调  _1错误信息  _2消息搜索结果集合
	*/
	virtual void searchDetailMessage(const std::string &key, MsgDetailSearchProperty &msgDetailProperty,
		SFunction<void(ErrorInfo, MsgDetailSearchResult&)> cb) = 0;

	/**
	* \brief 获取外部节点信息
	* @param[out] cb     传入接收结果回调  _1错误信息  _2消息搜索结果集合
	*/
	virtual void getOutEntNodeInfo(SFunction<void(ErrorInfo, std::vector<OutEntNodeInfo>&)> cb) = 0;
};

} /*namespace service*/