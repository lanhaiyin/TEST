#pragma once

#include "../model/SDKTypes.h"
#include "../model/Packet.h"
#include "../model/Contact.h"
#include "IService.h"

#include <string>
#include <vector>

#define VER_CONTACT INTERFACE_VERSION(1,0)
static const VRVIID IID_IContactService = { 0x3de6bc58, 0x3d6f, 0x4b25, 0x8f, 0x36, 0xc5, 0xb, 0x65, 0x76, 0x44, 0xdd };

namespace service
{

class IContactService :public IService
{
public:

	virtual ~IContactService(){}

	/*****************************************注册通知回调*******************************************/

	/**
	* \brief 监听联系人头像更新
	* @param[out]  cb _1 传入目标ID，人或者群;  _2	  传入头像;
	*/
	virtual void regContactHeadImgUpdateCb(SFunction < void(int64, const std::string&) > cb) = 0;

	/**
	* \brief 监听联系人聊天背景更新
	* @param[out]  cb _1 传入目标ID，人或者群;  _2	  传入头像;
	*/
	virtual void regContactBackImgUpdateCb(SFunction < void(int64, const std::string&) > cb) = 0;
	
	/**
	* \brief 设置监听在线状态更新的回调
	* @param[out] cb _1 在线状态 见packet.h
	*/
	virtual void regPresentCb(SFunction< void(const OnlineState&) > cb) = 0;

	/**
	*  \brief 设置好友信息更新的回调
	* @param[out] cb _1 传入操作类型  1: 增加 2: 更新，3: 删除; _2  传入变更的联系人; 
	*/
	virtual void regOperateBuddyCb(SFunction< void(int, const Contact&) > cb) = 0;

	/**
	* \brief 监听好友刷新
	* @param[out] cb _1 传入操作类型 \n
	* 0x01 包含此标识，清空ＵＩ列表插入下面列表项 \n
	* 0x02　包含此标识，ＵＩ列表尾部添加下面列表项 \n
	* 0x04 包含此标识，所有好友添加完毕 \n
	* 0x08 包含此标识，从当前ＵＩ列表中更新下面列表项　不和其他标识组合 \n
	* 0x10 包含此标识，从当前ＵＩ列表中删除下面列表项　不和其他标识组合 \n
	* [in] _2	  传入变更的联系人
	*/
	virtual void regBuddyListCb(SFunction< void(int, std::vector<Contact>&) > cb) = 0;


	/**
	* \brief 监听服务器端推送的超级用户操作
	* @param[out] cb 服务器做了哪些操作 OperType为1-9
	超级用户功能简介：
	三种用户类型：超级用户，提权用户，普通用户
	数据字典获取高级权限开关，个人好友组织中获取tagIds中是否含有1来判断是不是超级用户，getTagStrategyFromNet接口type=2获取高级权限列表
	tagIds为用户标签ID的集合，用逗号分隔，其中有1则为超级用户，否则为提权用户或普通用户
	提权用户或普通用户需要判断高级权限开关是否开启，没开启就都是普通用户，如果开启，则获取高级权限列表，如果没有则为普通用户，如果有则为提权用户
	如果是超级用户，而且打开了高级权限开关，则可以调用接口对自己的好友或组织成员进行提权，权限回收等操作，自己的好友或组织成员通过tagIds判断他是不是超级用户避免操作超级用户

	（1）operType=1表示自己变为超级用户，收到该推送后客户端需要再次获取myself信息，重新拉取数据字典中的高级权限开关，重新拉取高级权限列表，客户端根据开关判断是否展示高级权限设置菜单，并重新计算该用户的权限
	（2）OperType=2表示自己变成普通用户，收到该推送后客户端需要再次获取myself信息，重新拉取数据字典中的高级权限开关，重新拉取高级权限列表，客户端根据开关和高级权限列表是否存在来判断自己是否为提权用户并重新计算该用户的权限
	（3）operType=3表示提权人被回收了权限（提权该用户的超级用户变成普通用户），客户端需要重新拉取高级权限列表，并重新计算权限
	（4）OperType=4表示服务器修改了超级用户的权限范围且该用户为超级用户，客户端需要重新拉取高级权限列表，并更新高级权限设置菜单的可显示授权项
	（5）OperType=5表示服务器修改了超级用户的权限范围且该用户为提权用户，客户端需要重新拉取高级权限列表，并重新计算权限
	（6）OperType=6表示该用户被某个超级用户新增为提权用户或增加了提权权限，客户端需要重新拉取高级权限列表，并重新计算权限
	（7）OperType=7表示该用户被某个超级用户修改了提权的权限，客户端需要重新拉取高级权限列表，并重新计算权限
	（8）OperType=8表示该用户被某个超级用户回收了提权的所有的权限，客户端需要重新拉取高级权限列表，并重新计算权限
	（9）OperType=9如果自己是超级用户，服务器更新了数据字典，sdk会推送type=9到客户端，客户端要重新拉取高级权限开关判断是否有变更并根据结果决定是否显示高级权限设置菜单
	*/
	virtual void regOperateSuperUserCb(SFunction< void(int64) > cb) = 0;



	/*****************************************请求接口*******************************************/

	/**
	* \brief 添加联系人
	* @param[in] userid 传入联系人ID
	* @param[in] remark 传入联系人备注，可以为空
	* @param[in] info   传入验证信息
	* @param[out] cb  传入接收结果回调 _1错误信息
	*/
	virtual void addContact(int64 userid, const std::string &remark, const std::string &info, 
							SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 直接添加联系人，不需要验证可扩展新增邀请码
	* @param[in] userid 传入联系人ID
	* @param[in] remark 传入联系人备注，可以为空
	* @param[in] info   传入验证信息
	* @param[in] inviteCode   传入邀请码
	* @param[out] cb  传入接收结果回调 _1错误信息
	*/
	virtual void addContactNoVerify(addBuddyResponseExt &addBuddy, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 直接添加联系人，不需要验证
	* @param[in] userid 传入联系人ID
	* @param[in] remark 传入联系人备注，可以为空
	* @param[in] info   传入验证信息
	* @param[out] cb  传入接收结果回调 _1错误信息
	*/
	virtual void addContactNoVerify(int64 userid, const std::string &remark, const std::string &info,
				SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 获取联系人验证方式
	* @param[in] userid 传入联系人ID
	* @param[out] cb  传入接收结果回调 _1 错误信息 _2验证方式
	*/
	virtual void getVerifyType(int64 userid, SFunction<void(ErrorInfo, ContactVerifyType&)> cb) = 0;

	/**
	* \brief 删除联系人
	* @param[in] userid 传入联系人ID
	* @param[out] cb  传入接收结果回调 _1 错误信息
	*/
	virtual void removeContact(int64 userid, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 更新联系人信息（星标&V标&备注）
	* @param[in] info 传入联系人信息 见contact.h
	* @param[out] cb  传入接收结果回调 _1错误信息
	*/
	virtual void updateContactInfo(Contact &info, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 获取联系人列表 （同步接口）
	* @param[out]  contacts 所有的联系人信息;
	*/
	virtual void getContactList(std::vector< SSharedPtr<Contact> > &contacts) = 0;

	/**
	* \brief 获取联系人在线状态
	* @param[in] users 传入联系人集合 如果为空则查所有联系人状态
	* @param[out] cb  传入接收结果回调 _1 错误信息; _2 在线状态
	错误信息:0:SUCCESS -1:其他错误  100008008:功能未上线
	*/
	virtual void getContactOnline(std::vector<int64> &users, SFunction<void(ErrorInfo, std::vector<OnlineState>&)> cb) = 0;

    /**
    * \brief 获取单聊在线状态 调用此接口后方可收到在线状态推送
    * @param[in] user 传入单聊对象
    * @param[out] cb  传入接收结果回调 _1 错误信息; _2 在线状态
	错误信息:0:SUCCESS -1:其他错误  100008008:功能未上线
    */
    virtual void regContactOnline(int64 user, SFunction<void(ErrorInfo, OnlineState&)> cb) = 0;

	/**
	* \brief 获取联系人信息 ( 同步接口 )
	* @param[in] userid 用户ID
	* @param[out] contact  联系人信息
	* @return 操作结果
	*/
	virtual bool getContactInfo(int64 userid, Contact& contact) = 0;

	/**
	* \brief 判断联系人与自己是否是好友关系 ( 同步接口 )
	* @param[in] userid 用户ID
	* @return true为好友  false非好友
	*/
	virtual bool contactIsBuddy(int64 userId) = 0;

	/**
	* \brief 获取黑名单
	* @param[out] cb 传入接收结果回调  _1错误信息 _2黑名单ID集合
	*/
	virtual void getBlackList(SFunction<void(ErrorInfo, std::vector<int64>&)> cb) = 0;

	/**
	* \brief 添加黑名单
	* @param[in] ids 要加入的黑名单对象ID集合
	* @param[out] cb 传入接收结果回调  _1错误信息
	*/
	virtual void addBlackList(std::vector<int64> &ids, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 删除黑名单
	* @param[in] ids 要删除的黑名单对象ID集合，为空则删除所有黑名单用户
	* @param[out] cb 传入接收结果回调  _1错误信息
	*/
	virtual void removeBlackList(std::vector<int64> &ids, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 根据条件查询拓展字段信息 根据dicKey和parentId共同查询拓展字段.
	* @param[in] dicKey 要查询的字段
	* @param[in] parentID 父组织ID 当parentId为-1时表示查询所有的拓展字段;当parentId为-2 时按dicKey查询;-3时dicKey为id,根据id查询
	* @param[out] cb 传入接收结果回调  _1错误信息 _2返回的查询信息
	*/
	virtual void queryExtendedField(const std::string &dicKey,int64 parentID, SFunction<void(ErrorInfo, std::vector<EnterpriseDictionary>&)> cb) = 0;
    
    /**
    * \brief 根据条件查询拓展字段信息（同步接口）
    * @param[in] dicKey 要查询的字段
    * @param[in] parentID 父组织ID 当parentId为-1时表示查询所有的拓展字段;当parentId为-2 时按dicKey查询
    * @param[out] result 查询结果  不会更新本地数据
    */
    virtual bool queryExtendedFieldSync(const std::string &dicKey, int64 parentID, std::vector<EnterpriseDictionary>& result) = 0;

	/**
	* \brief 上传通讯录
	* @param[in] ids 要删除的黑名单对象ID集合，为空则删除所有黑名单用户
	* @param[out] cb 传入接收结果回调  _1错误信息 2,推荐联系人
	*/
	virtual void postContact(std::vector<PhoneBookContact> &pbContacts, SFunction<void(ErrorInfo, std::vector<RecommendContact>&)> cb) = 0;

	/**
	* \brief 获取全部本地通讯录条目(同步方法)
	* @param[out] phoneBooks 返回的通讯录条目集合
	*/
	virtual bool getLocalPhoneBook(std::vector<localPhoneBook> &phoneBooks) = 0;
	/**
	* \brief 增加本地通讯录条目(同步方法)
	* @param[in] phoneBooks 通讯录条目集合
	*/
	virtual bool addLocalPhoneBook(std::vector<localPhoneBook> &phoneBooks) = 0;

	/**
	* \brief 删除本地通讯录条目(同步方法)
	* @param[in] phones 电话号码集合
	*/
	virtual bool deleteLocalPhoneBook(std::vector<std::string> &phones) = 0;

	/**
	* \brief 清空本地通讯录(同步方法)
	*/
	virtual bool deleteAllLocPhoneBook() = 0;

	/**
	* \brief 更新本地通讯录(同步方法)
	* @param[in] phoneBooks 通讯录条目集合
	*/
	virtual bool updateLocalPhoneBook(std::vector<localPhoneBook> &phoneBooks) = 0;
	/**
	*\brief从网络获取好友信息
	*/
	virtual void getBuddyInfoFromNet(int64 userId,SFunction<void(ErrorInfo,Contact&)> cb) = 0;

	/**
	*\brief 是否为单向增减删除好友 (同步方法)
	* @return  true 单向 false 双向
	*/
	virtual bool  oneWayBuddy() = 0;

	/**
	*\brief生成邀请码
	* @param[in] param 生成邀请码的参数
	* @param[out] cb 传入接收结果回调  _1错误信息 _2邀请码
	*/
	virtual void makeVerifyCode(InviteCodeParam &param, SFunction<void(ErrorInfo, const std::string&)> cb) = 0;

	/**
	*\brief是否是合法的邀请码(同步接口)
	* @param[in] inviteCode 邀请码
	* @param[in] serverIP 合法返回服务器IP
	* @param[out] return 合法返回服务器IP 不合法返回空
	*/
	virtual std::string isInviteCode(const std::string &inviteCode) = 0;
	
	/**
	*\brief校验本人是否有权限生成邀请码
	* @param[out] cb 传入接收结果回调  _1错误信息  0有权限 100001717没有权限
	*/
	virtual void canMakeVerifyCode(SFunction<void(ErrorInfo)> cb) = 0;

	/***********************邀请码优化新增接口BEGIN*********************************************/
	/**
	*\brief校验本人是否有权限生成邀请码(邀请码优化)
	* @param[out] cb 传入接收结果回调  _1错误信息  0有权限 100001717没有权限 _2返回服务器标识
	*/
	virtual void canMakeVerifyCode_New(SFunction<void(ErrorInfo, const std::string&)> cb) = 0;

	/**
	*\brief查询服务器允许注册人数
	* @param[out] cb 传入接收结果回调 
	_1返回码:
		0:成功
		100:参数错误
		11100:服务器内部错误
		100015004:没有该操作类型
		100015005:没有设置邀请码权限
		100015006:修改邀请码失败
		100015007:查询分享列表失败
		100015008:查询服务器限制人数失败

	_2: 允许注册人数相关信息
	*/
	virtual void getLimitRegisterCount(SFunction<void(ErrorInfo, const std::string&)> cb) = 0;

	/**
	*\brief设置邀请码
	* @param[in] 传入参数 
		setParam ==> setInviteCodeParam
	* @param[out] cb 传入接收结果回调
	_1返回码:
		0:成功
		100:参数错误
		11100:服务器内部错误
		100015004:没有该操作类型
		100015005:没有设置邀请码权限
		100015006:修改邀请码失败
		100015007:查询分享列表失败
		100015008:查询服务器限制人数失败
	*/
	virtual void setInviteCode(setInviteCodeParam &setParam, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	*\brief用户邀请码分享列表查询接口
	* @param[in] 传入参数
		shareParam  用户邀请码参数 ==> inviteCodeShareParam
	* @param[out] cb 传入接收结果回调
	_1返回码:
		0:成功
		100:参数错误
		11100:服务器内部错误
		100015004:没有该操作类型
		100015005:没有设置邀请码权限
		100015006:修改邀请码失败
		100015007:查询分享列表失败
		100015008:查询服务器限制人数失败
	_2返回列表:
		shareInfo 邀请码列表 ==> inviteCodeShareList
	*/
	virtual void getShareInviteCodeInfo(inviteCodeShareParam shareParam, SFunction<void(ErrorInfo, std::vector<inviteCodeShareList>&)> cb) = 0;

	/**
	*\brief保存邀请码图片
	* @param[in] 传入参数
		inviteCode   邀请码
		inviteCodePic  邀请码图片
	* @param[out] cb 传入接收结果回调
	_1返回码:
	0:成功
	100:参数错误
	11100:服务器内部错误
	*/
	virtual void saveInviteCodePic(std::string &inviteCode, std::string &inviteCodePic, SFunction<void(ErrorInfo)> cb) = 0;

	/***********************邀请码优化新增接口END*********************************************/
	/*brief检查邀请码是否有效
	* @param[in] inviteCode 邀请码
	* @param[in] uc 被邀请用户
	* @param[out] cb 传入接收结果回调  _1错误信息  0有效
	*/
	virtual void verifyCodeValid(const std::string &inviteCode, UserContact &uc, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	*\brief检查群邀请码是否有效
	* @param[in] inviteCode 邀请码
	* @param[out] cb 传入接收结果回调  _1错误信息  0成功 _2what值
	*/
	virtual void GroupVerifyCodeValid(const std::string &inviteCode, SFunction<void(ErrorInfo, const std::string&)> cb) = 0;
	
	/**
	*\brief 通过邀请码获取用户ID
	* @param[in] inviteCode 邀请码
	* @param[out] cb 传入接收结果回调  _1错误信息  _2用户ID _3buddy开关
	*/
	virtual void getUserIdByInviteCode(const std::string &inviteCode, SFunction<void(ErrorInfo, int64, int8)> cb) = 0;

	/**
	*\brief 通过邀请码获取用户ID
	* @param[in] inviteCode 邀请码
	* @param[out] cb 传入接收结果回调  _1错误信息  _2用户ID _3buddy开关 _4增加的json字符串(好社工邀请码)
	* [7/19/2021 zhuohc]
	*/
	virtual void getUserIdByInviteCodeExt(const std::string &inviteCode, SFunction<void(ErrorInfo, int64, int8, const std::string&)> cb) = 0;

	/**
	*\brief  手机控制pc退出
	* @param[in]  type  类型  1:下线
	* @param[in]  devValue 设备类型  1：pc,2：phone，3：pad，4：web
	* @param[out] cb 传入接收结果回调  _1错误信息 0表示成功 100表示参数错误 100008003表示失败
 	*/
	virtual void devKickOff(int8 type,int8 devValue,SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 获取用户设备在线状态
	* @param[in] users 传入用户列表集合 如果为空则查所有联系人状态
	* @param[out] cb  传入接收结果回调 _1 错误信息; _2 在线状态
	*/
	virtual void getDeviceOnline(std::vector<int64> &users, SFunction<void(ErrorInfo, std::vector<OnlineState>&)> cb) = 0;

	/**
	* \brief 获取用户设备在线状态,增加覆盖面(type=10),返回结果按照userid分组
	* @param[in] users 传入用户列表集合 如果为空则查所有联系人状态
	* @param[out] cb  传入接收结果回调 _1 错误信息; _2 在线状态(按照id分组)
	*/
	virtual void getDeviceOnlineEx(std::vector<int64> &users, SFunction<void(ErrorInfo, std::map<int64,std::vector<OnlineState>>&)> cb) = 0;

	/**
	* \brief 客户端首次登录账号需要激活，若开启了用户信息字段验证激活方式需要调用此接口验证信息是否正确,须在已登录后调用
	* @param[in] accountType	账号类型
	* @param[in] account		账号
	* @param[in] userField		用户验证信息JSON 格式,示例{"base_name": "value1","account_10": "value2","extend_49114af6d8d64aa7b9ff7d79ab7be137": "value3"}
	* @param[out] cb 传入接收结果回调  _1错误信息 （100008004用户不存在 100008005验证用户信息失败 0验证用户信息成功）
	*/
	virtual void verifyUserInfoField(int8 accountType, const std::string& account, const std::string& userField, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 获取用户设置信息
	* @param[in] userIdList	用户id列表
	* @param[out] cb 传入接收结果回调  _1错误信息 ,_2 用户的设置信息集合
	*/

	virtual void getBuddySetting(const std::vector<int64> userIdList, SFunction<void(ErrorInfo, std::map<int64,std::vector<PersonalDataSwitch>>&)> cb) = 0;

	/**
	* \brief 设置服务器别名
	* @param[in] userId	用户id
	* @param[in] serAlias	 要设置的别名
	* @param[out] cb 传入接收结果回调  _1错误信息          	
	                                                   0 成功//100005000
					                                  100005001 参数不全
	                                                  100 参数错误，未知type
	                                                  11100 服务器内部错误
	                                                  what 结果信息
	 [3/15/2021]
	*/
	virtual void setServerAlias(int64 userId, std::string serAlias, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* \brief 获取用户设置服务器别名
	* @param[in] userId	用户id
	* @param[out] cb 传入接收结果回调  _1错误信息 ,_2 用户的设置服务器别名
														0 成功//100005000
	                                                  100005001 参数不全
	                                                  100 参数错误，未知type
	                                                   11100 服务器内部错误
	                                                   what 结果信息
	[3/15/2021]
	*/
	virtual void getServerAlias(int64 userId, SFunction<void(ErrorInfo, const std::string&)> cb) = 0;



	/**
	* \brief 超级用户操作，保存提权人员所有权限
	* @param[in] elevatorList  提权人员列表
	* @param[out] cb 传入接收结果回调  _1错误信息(0:成功  -1:系统异常 -2:参数异常 100:未定义的type类型 11100调用底层接口失败)  _2 保存失败的userID集合
	*/
	virtual void saveElevatorAuthority(std::vector<ElevatorAuthority> &elevatorList, SFunction<void(ErrorInfo, const std::string&)> cb) = 0;


	/**
	* \brief 超级用户操作，删除提权人员所有权限
	* @param[in] sid  超级用户id
	* @param[in] uid  提权用户id
	* @param[out] cb 传入接收结果回调  _1错误信息(0:成功  -1:系统异常 -2:参数异常 100:未定义的type类型 11100调用底层接口失败) 
	*/
	virtual void deleteElevator(int64 sid, int64 uid, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 超级用户操作，查询当前超级用户的所有提权人员以及权限
	* @param[in] num  查询页数量
	* @param[in] index  查询页序号
	* @param[in] sid  超级用户id
	* @param[out] cb 传入接收结果回调  _1错误信息(0:成功 100:未定义的type类型 11100调用底层接口失败）
                                       _2 当前页数量    _3 当前页序号    _4 总页数    _5 总条数    _6 提权人员列表
	*/
	virtual void selectElevatorAuthorityAll(int64 num, int64 index, int64 sid, SFunction<void(ErrorInfo, int64, int64, int64, int64, std::vector<ElevatorAuthority>&)> cb) = 0;

	/**
	* \brief 超级用户操作，查询提权人员真实所有权限
	* @param[in] uid  提权人员id
	* @param[out] cb 传入接收结果回调  _1错误信息(0:成功  -1:系统异常 -2:参数异常 100:未定义的type类型 11100调用底层接口失败)  _2 权限json
	*/
	virtual void queryElevatorAuthorityReal(int64 uid, SFunction<void(ErrorInfo, const std::string&)> cb) = 0;

	/**
	* \brief 超级用户操作，分页查询操作记录信息
	* @param[in] num  查询页数量
	* @param[in] index  查询页序号
	* @param[in] sid  超级用户id
	* @param[in] uid  提权用户id
	* @param[out] cb 传入接收结果回调  _1错误信息(0:成功 100:未定义的type类型 11100调用底层接口失败）
	_2 当前页数量    _3 当前页序号    _4 总页数    _5 总条数    _6 提权人员列表
	*/
	virtual void listElevatorRecord(int64 num, int64 index, int64 sid, int64 uid, SFunction<void(ErrorInfo, int64, int64, int64, int64, std::vector<ElevatorAuthority>&)> cb) = 0;

	/**
	* \brief 获取用户标签
	* @param[in] userID  用户ID
	* @param[in] tagType  标签类型
	* @param[out] cb 传入接收结果回调  _1错误信息(0:成功 -1:网络失败 100004609:获取用户策略参数不正确 100004610:用户不存在 100004611:用户策略为空 100004613:获取用户策略失败 100004614:用户标签查询不存在）
	    _2 标签类型    _3 标签json
	*/
	virtual void getTagStrategyFromNet(int64 userID, int8 tagType, SFunction<void(ErrorInfo, int64, const std::string&)> cb) = 0;

	/**
	* \brief 超级用户操作，查询当前超级用户的某个提权人员以及权限
	* @param[in] sid  超级用户id
	* @param[in] uid  提权用户id
	* @param[out] cb 传入接收结果回调  _1错误信息(0:成功 100:未定义的type类型 11100调用底层接口失败） _2 提权人员列表
	*/
	virtual void selectElevatorAuthority(int64 sid, int64 uid, SFunction<void(ErrorInfo, std::vector<ElevatorAuthority>&)> cb) = 0;

};

} /*namespace service*/