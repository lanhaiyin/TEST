#ifndef CMD_COM_DEF_H_
#define CMD_COM_DEF_H_

////////////////////////////////////////////////////////////////////////////////
/// Copyright (C), 2015-2016
/// \file   	cmdComDef.h
/// \brief  	SDK通用结构体头文件
/// \author 	sharp.young
/// \version    0.2.1
/// \data       2016/1/10
/// \warning    消息号携带的数据结构，必须继承此结构体，如果结构体中有容器类的成员变量，“必须”重载init方法，完成清理工作
///             比如： 
///             struct test : public _sdkcmd_base {
///					std::vector<x> prop1 ;
///					void init() {
///						prop1.clear();
///					}
///				}
/// \warning    成员变量结构体(比如"st_"开头的结构体)里面含有容器类数据的话，该成员变量结构体须提供清理方法 需要将容器清理
/// \Function List
/// \History:
///  	<author> 		<time>    	   <version >    	<desc>
///
////////////////////////////////////////////////////////////////////////////////

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include "config.h"

namespace imsdk
{
	/**
	*  \def 结构体长度宏定义
	*/
#define CMD_SIZE() \
	virtual int32 getSize() { return sizeof(*this); }
#define COPY_OTHER(T) \
	virtual bool copyfrom(_sdkrespcmd_base * pOther) { *this = *((T*)pOther); return true; }
	/**
	 * 定义结构体:
	 *  struct Example {
	 *  	Example(){
	 *  		INIT_ISSET(test)
	 *  	}
	 *  	IS_SET(std::sting,test);
	 *  }
	 *
	 *  //使用
	 *  Example  myTest;
	 *  myTest._set_test("this is test");
	 *  printf("myTest.test = %s,",myTest.test.c_str());
	 *
	 *  //输出
	 *  myTest.test = this is test",
	 */
#define  IS_SET(type,x) \
		type  x;		 \
		bool isSet_##x ; \
		void _set_##x(const type & val) {   \
			x = val ;                  \
			isSet_##x = true ;        \
		}
#define INIT_ISSET(x) \
		isSet_##x = false;
#define INIT_ISSETEX(x,y) \
		isSet_##x = y;

/**
* \struct _sdkcmd_base
* \biref  所有消息的基类
* 
*/
//#if (defined __aarch64__) && (defined SDK_FOR_ANDROID)
//#pragma pack(push) //保存对齐状态
//#pragma pack(8)//设定为8字节对齐
//#endif
struct _sdkcmd_base 
{
	_sdkcmd_base():localID(0),retryCnt(0){
		
	}
	virtual ~_sdkcmd_base(){}
	virtual void init() {
		localID  = 0; 
		retryCnt = 0;
	}
	///本地唯一编号
	int64  localID;
    ///接口重试次数
    int32  retryCnt;
	CMD_SIZE();
	};

/**
 * \struct _sdkrespcmd_base
 * \biref 所有返回消息基类
*/
struct _sdkrespcmd_base : public _sdkcmd_base 
{
	_sdkrespcmd_base() :code(0) {}
	virtual ~_sdkrespcmd_base(){}
	virtual void init() 
	{
		code = 0;
		_sdkcmd_base::init();
	}
	virtual bool copyfrom(_sdkrespcmd_base * pOther) {
		*this = *pOther;
		return true ;
	}
	///响应返回值
	int32  code;
	CMD_SIZE();	
};
/**
*  \struct resp_verifyResult
*  \biref  通用返回结构体, 具体含义各个消息或有不同
*/
struct resp_verifyResult : public _sdkrespcmd_base
{
	resp_verifyResult() :bResult(false){}

	bool bResult;

	CMD_SIZE();
	COPY_OTHER(resp_verifyResult);
};
/**
*  \struct resp_commonResult
*  \biref  通用返回结构体, 具体含义各个消息或有不同
*/
struct resp_commonResult : public _sdkrespcmd_base 
{
	resp_commonResult() :value_byte(0),
						 value_i16(0),
	                     value_i32(0),
	                     value_i64(0)
	{}
	std::string 	what;
	int8 			value_byte;
	int16 			value_i16;
	int32 			value_i32;
	int64		    value_i64;
 	std::string 	value_str;
	void init()
	{
		value_str.clear();
	}
	CMD_SIZE();
	COPY_OTHER(resp_commonResult);
	};

//#if (defined __aarch64__) && (defined SDK_FOR_ANDROID)
//#pragma pack(pop)
//#endif
	/**
	 * \struct st_tinyUserBean
	 * \biref  用户基础信息，陌生人信息可以使用
	 */
	struct st_tinyUserBean
	{
		st_tinyUserBean() :
            sex(0),
		    timezone(0),
		    userid(0),
		    birthday(0),
			buddySet(0),
			registerTime(0),
			securityLevel(0),
			status(0)
		{
			init();
		}
		///性别
		IS_SET(int, sex)
		///时区
		IS_SET(int, timezone)
		///用户ID
		IS_SET(int64, userid)
		///生日
		IS_SET(int64, birthday)
		///名称
		IS_SET(std::string, name)
		///拼音
		IS_SET(std::string, pinyin)
		///头像
		IS_SET(std::string, avatar)
		IS_SET(std::string, avatarUrl)
		///大图头像
		IS_SET(std::string, srcAvatar)
		IS_SET(std::string, srcAvatarUrl)
		///签名
		IS_SET(std::string, sign)
		///区域
		IS_SET(std::string, area)
		///豆豆号
		IS_SET(std::string, nickID)
		///电话号码清单
		IS_SET(std::vector<std::string>, phones)
		///邮件清单
		IS_SET(std::vector<std::string>, emails)
		///好友设置 用前4位表示免打扰，0x1为接收提醒,0x2表示不提醒仅显示数字,0x3为免打扰
		IS_SET(int64, buddySet)
		///注册时间
		IS_SET(int64, registerTime)
		///工作密级
		IS_SET(int32, securityLevel)
		///用户标签id,多个用逗号分隔
		IS_SET(std::string, tagIds)
		///企业扩展信息
		IS_SET(std::string, entExtend)
		IS_SET(int8, status)
		void init()
		{
			INIT_ISSET(sex)
			INIT_ISSET(timezone)
			INIT_ISSET(userid)
			INIT_ISSET(birthday)
			INIT_ISSET(name)
			INIT_ISSET(pinyin)
			INIT_ISSET(avatar)
			INIT_ISSET(avatarUrl)
			INIT_ISSET(srcAvatar)
			INIT_ISSET(srcAvatarUrl)
			INIT_ISSET(sign)
			INIT_ISSET(area)
			INIT_ISSET(nickID)
			INIT_ISSET(phones)
			INIT_ISSET(emails)
			INIT_ISSET(buddySet)
			INIT_ISSET(registerTime)
			INIT_ISSET(securityLevel)
			INIT_ISSET(tagIds)
			INIT_ISSET(entExtend)
			INIT_ISSET(status)
			userid = 0;
			registerTime = 0;
			phones.clear();
			emails.clear();
		}
		bool operator == (const st_tinyUserBean& rhs) const
		{
			return (sex == rhs.sex &&
				timezone == rhs.timezone &&
				userid == rhs.userid &&
				birthday == rhs.birthday &&
				name == rhs.name &&
				pinyin == rhs.pinyin &&
				avatar == rhs.avatar &&
				avatarUrl == rhs.avatarUrl &&
				srcAvatar == rhs.srcAvatar &&
				srcAvatarUrl == rhs.srcAvatarUrl &&
				sign == rhs.sign &&
				area == rhs.area &&
				nickID == rhs.nickID &&
				phones == rhs.phones &&
				emails == rhs.emails &&
				buddySet == rhs.buddySet &&
				securityLevel == rhs.securityLevel &&
				tagIds == rhs.tagIds &&
				entExtend == rhs.entExtend&&
				status == rhs.status
				);
		}
	};

	/**
	 * \struct st_userBean
	 * \brief 用户的扩展信息
	 * IS_SET 标识需要使用函数来设置该类型，不设置的话，不会发送到服务器
	 * 比如 IS_SET(std::string,extend)
	 *
	 *    st_userBean param;
	 *    std::string newExtent="this is test";
	 *    param._set_extend(newExtent);
	 */
	struct st_userBean
	{
		st_userBean() {
			init();
		}
		void init() {
			INIT_ISSET(extend)
			INIT_ISSET(entExtend)
			INIT_ISSET(orgIds)
			INIT_ISSET(info)
			INIT_ISSET(accounts)
			INIT_ISSET(pwd)
			INIT_ISSET(roleID)
			info.init();
			accounts.clear();
		}
		
		struct AccountType
		{
			bool operator == (const AccountType& rhs) const
			{
				return (type == rhs.type && accounts == rhs.accounts  && mark == rhs.mark);
			}
			int8 type;                  // 账号类型 1：电话, 3：邮箱, 4：userID, 5:身份证, 6：豆豆号, 7:自定义帐号(不做限制)
			std::string accounts;       // 账号
			std::string mark;           // 标识
		};

		///< 账号信息
		IS_SET(std::vector<AccountType>, accounts)
		///扩展信息
		IS_SET(std::string, extend)
		///企业扩展
		IS_SET(std::string, entExtend)
		///组织结构id,多个用逗号分隔
		IS_SET(std::string, orgIds)
		///密码
		IS_SET(std::string, pwd)
		///基础信息
		IS_SET(st_tinyUserBean, info)

		IS_SET(int64, roleID)
		bool operator == (const st_userBean& rhs) const	{
			return (extend == rhs.extend && info == rhs.info  && entExtend == rhs.entExtend && orgIds == rhs.orgIds &&
				accounts == rhs.accounts && pwd == rhs.pwd && isSet_pwd == rhs.isSet_pwd&& roleID == rhs.roleID);
		}
	};

	/**
	 * \struct st_buddyBean
	 * \brief 好友数据结构
	 */
	struct st_buddyBean	
	{
		st_buddyBean() :page(0), isstar(0), securityLevel(0){
        }

		int32 securityLevel;		///密级
		int32 page;				    ///< 好友页 page.
		///是否特别/星标好友 1是，该字段含有0x1000标识为应用，含有0x2000标示为隐藏好友，含有0x4000表示置顶
		int32 isstar;
		std::string remark;			///< 备注 remark.
		std::string remarkPy;		///< 备注拼音 remarkPy.
		std::string chatImage;		///< 聊天背景 chatImage.
		std::string srvName;		///< 服务器名称 srvName,如果是空，则是当前服务器
		std::string privateMsgPwd;	///< 私信密码 privateMsgPwd.
		st_tinyUserBean info;		///< 基础信息 info.
		bool operator == (const st_buddyBean& rhs) const
		{
			return (page == rhs.page &&
				info == rhs.info &&
				isstar == rhs.isstar &&
				remark == rhs.remark &&
				remarkPy == rhs.remarkPy &&
				chatImage == rhs.chatImage &&
				privateMsgPwd == rhs.privateMsgPwd &&securityLevel == rhs.securityLevel
				);
		}		
	};



	/// 组织信息
	struct st_organizationInfo
	{
		st_organizationInfo() :
		orgID(0),
		enterpriseID(0),
		leaf(0),
		parentOrgID(0),
		orderNum(0),
		branchID(0),
		departLevel(0),
		subOrgNum(0),
		subUserNum(0),
		isHidden(0),
		provinceID(0),
		cityID(0),
		areaID(0) {
		}

		int64 orgID;                ///< 组织机构ID orgID.
		int64 enterpriseID;         ///< 企业ID enterpriseID.
		std::string orgName;        ///< 组织机构名称 orgName.
		std::string orgCode;        ///< 组织机构内码 orgCode.
		int8 leaf;                  ///< 是否叶节点 leaf.
		int64 parentOrgID;          ///< 父节点 parentOrgID.
		std::string remark;         ///< 备注 remark.
		int64 orderNum;             ///< 排序 orderNum.
		int64 branchID;             ///< 办公地ID branchID.
		std::string departID;       ///< 删除 departID.
		int8 departLevel;           ///< 组织级别 departLevel.
		int64 subOrgNum;            ///< 递归计算所有下级组织数 subOrgNum.
		int64 subUserNum;           ///< 递归计算所有下级成员数 subUserNum.
		int8 isHidden;              ///< 是否隐藏, 1对本部门公开 2对所有部门公开，3对部分部门公开 isHidden.
		int64 provinceID;           ///< 省份ID provinceID.
		std::string provinceName;   ///< 省份名称 provinceName.
		int64 cityID;               ///< 市ID cityID.
		std::string cityName;       ///< 市名称 cityName.
		int64 areaID;               ///< 县ID areaID.
		std::string areaName;       ///< 县名称 areaName.
		std::string orgNamePinyin;   ///< 拼音 orgNamePinyin.
	};

	/**
	 *	\struct st_smallUserBean
	 *	\brief  用户信息，好友使用。
	 */
	struct st_smallUserBean
	{
		st_smallUserBean()
		{
			sex = 0;
			status = 0;
			userID = 0;
			qqNum = 0;
			match = 0;
			birthday = 0;
			year = 0;
			month = 0;
			day = 0;
			serverStatus = 0;
			INIT_ISSET(orgList)
		}

		void init()
		{
			INIT_ISSET(orgList)
		}

		std::string phoneNum; 	///< 电话号码,可以删除 phoneNum.
		std::string email;	  	///< 电子邮件， 可以删除 email.
		std::string name;	  	///< 用户名   name.
		int8 sex;			  	///< 性别 sex.
		/**
		 * \brief 账号状态
		 * 用户状态 1：正常 2：停用 3: 注册邀请4: 影子用户，5:锁定，6:冻结
		 */
		int8 status;			///< 状态 status.
		/**
		 * \brief 好友头像
		 * 推送上去只是文件名部分
		 */
		std::string portraitURL;
		std::string portraitURLUrl;
		std::string sign;		///< 个性签名 sign.
		int64 userID;			///< 用户ID userID.
		int64 qqNum;			///< QQ号码 qqNum.
		/**
		 * \brief 匹配查询类型
		 * 1:qqNum 2:phoneNum 4:email 8:userID 16:name
		 */
		int8 match;
		std::vector<std::string>  phoneNums; ///< 电话号码清单 phoneNums.
		std::vector<std::string>  emails;	 ///< 电子邮件清单 emails.
		std::vector<st_userBean::AccountType> accounts;	///< 账号列表
		/**
		 * \brief 原始好友头像
		 * 推送上去只是文件名部分
		 */
		std::string oriPortraitURL;	///< 原始好友头像 oriPortraitURL.
		std::string oriPortraitURLUrl;
		int64 birthday;
		int16 year;					///< 生日年 year.
		int8 month;					///< 生日月 month.
		int8 day;					///< 生日天 day.
		std::string accountName;	///< 账号名称 accountName.
		std::string srvName;       ///< 服务器名称 srvName;
		std::string extend;		   ///< 扩展字段
		std::string area;
		int32 securityLevel;
		int8   serverStatus;		///是否是本服务人员，外服为4 本服务器为1
		IS_SET(std::vector<st_organizationInfo>, orgList)
	};

	/**
	 * \struct st_reContact
	 * \brief  最近联系人信息
	 */
	struct  st_reContact
	{
		st_reContact() :
		targetID(0),
		lastMsgid(0),
		time(0),
		type(0),
		isHiden(0),
		status(0),
		msgType(0),
		activeType(0),
		unreadCnt(0),
		realUnReadCnt(0),
		lastAtMsgID(0),
		msgRemindMode(0),
		disturbSet(0),
		securityLevel(0),
		sendUserID(0),
		userStatus(0),
		submsgtype(0){}

		int64 targetID;   		///< 目标用户ID targetID.
		int64 lastMsgid;        ///< 最后一次消息ID lastMsgid.
		int64 time;				///< 消息时间 time
		int8  type;				///< 会话类型  //1人，2群，3公众号，4企业号, 5 应用号
		int8  isHiden;			///< 是否是隐藏好友 0否 1是
		/**
		 * \brief 是否置顶
		 * 0x01男，0x02女,0x04置顶,0x08为群，前两位都为0 非男非女为保密
		 */
		int8  status;
		
		/*消息提醒模式 与0x0F 0.免打扰 1.提醒始终有声音  2.提醒始终无声音  3.提醒  4.不提醒，仅显示条目 5.根据免打扰时间段判断是否免打扰
		*与 0xF0, 1、通知详情  2、通知源，隐藏内容  3、完全隐藏*/
		int8 msgRemindMode;
		
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
		int16  realUnReadCnt; ///< 真正的未读消息数量 = unReadCnt+弱提示消息数量+其它端同步的设备消息数量，客户端每次拉取未读用这个字段，当realUnReadCnt为0时，表示所有消息在当前设备客户端都已经看过了
		/**
		 * \brief 头像
		 * 推送上去只有文件名部分
		 */
		std::string avatar;
		std::string avatarUrl;  ///< 服务器全路径
		std::string nickName;	///< 显示名称 nickName.
		std::string lastMsg;    ///< 最后一条消息描述 lastMsg.
		std::string whereFrom;  ///< 发送者名称,在群的时候有用 whereFrom.
		std::string msgProp;    ///< 消息属性
		std::string sourceID ;  ///< 消息附加源
		int64       lastAtMsgID; ///< 最后一条@你的消息,如果为零，则标识@的消息已读
		int64       sendUserID;  ///< 发送者ID
		int8        disturbSet;  ///< 免打扰，1为接收提醒,2表示不提醒仅显示数字,3为免打扰
		int32		securityLevel;///密级
		int submsgtype;           ///消息子类型
		int8 userStatus;
	}; 

	/**
	 * \struct st_onlineState
	 * \brief 好友状态
	 */
	struct  st_onlineState
	{
		st_onlineState() :userID(0), connectID(0), deviceType(0), flag(0), operTime(0), nStatus(0)
		{
			szExplain = "";
		}
		int64 userID;     ///< 用户ID userID.
		int64 connectID;  ///< 连接ID connectID.
		/**
		 * \brief 设备类型
		 * 1：PC；2：手机；3：pad；4：网页
		 */
		int8 deviceType;
		/**
		 * \brief 设备状态标识
		 * -1：离线，1:在线；2:隐身,3:忙碌,4:离开,5:请勿打扰, 6:想聊天
		 */
		int8 flag;
        int64 operTime; ///< 操作时间
		int8 nStatus;
		std::string szExplain;
	};

	/**
	 * \struct  st_PersonalData
	 * \brief   个人信息结构体
	 */
	struct st_personalData
	{
		st_personalData() :type(0), val(0) {}
		/**
		 * \brief type:   1 (生日)，２（电话），３（邮件）
		 * 　　　　　　　　value:  1：所有人可见 2：仅好友可见 3：仅自己可见，默认1
		 * type:   4 (好友验证方式)
		 * 　　　　　　　 value:   1：需要验证信息,2:不允许任何人添加,3:允许任何人添加，默认1
		 * type:   5 V标
		 *         value: 1:表示始终有声音提醒，2：表示始终无声音提醒 3:不始终提醒，默认1
		 * type:   6 @相关人提醒模式
		 *         value: 1:表示始终有声音提醒，2：表示始终无声音提醒 3:不始终提醒，默认1
		 * type:   7 全局通知消息内容展现模式
		 *         value: 1:通知详情，2：通知源，隐藏内容 3:完全隐藏，默认2
		 */
		int16 type; ///< 类型 type.
		int16 val; ///< 值 val.
	};

	/**
	 * \struct st_hiddenAccountInfo
	 * \brief 隐藏账户的信息
	 */
	struct st_hiddenAccountInfo
	{
		st_hiddenAccountInfo() :targetID(0), sendMsgUserID(0) {}
		int64 targetID;			///< 隐藏ID，可以是群,也可以是单个人  targetID.
		int64 sendMsgUserID;		///< 消息发送者ID sendMsgUserID.
		std::string message;		///< 发送的消息 message.
	};

	/**
	 *  \struct st_tinyBuddyBean
	 *  \brief  用户的缩略信息
	 */
	struct st_tinyBuddyBean
	{
		st_tinyBuddyBean() :flag(0), sex(0), userid(0), securityLevel(0)
		{
			INIT_ISSET(sex)
			INIT_ISSET(flag)
			INIT_ISSET(name)
			INIT_ISSET(avatar)
			INIT_ISSET(avatarUrl)
			INIT_ISSET(remark)
			INIT_ISSET(sign)
			INIT_ISSET(pinyin)
			INIT_ISSET(status)
			INIT_ISSET(srvName)
			INIT_ISSET(area)
			INIT_ISSET(birthday)
			INIT_ISSET(phoneNums)
			INIT_ISSET(emails)
			INIT_ISSET(nickID)
			INIT_ISSET(buddySet)
			INIT_ISSET(tagIds)
			INIT_ISSET(entExtend)
		}

		void init()
		{
			INIT_ISSET(sex)
			INIT_ISSET(flag)
			INIT_ISSET(name)
			INIT_ISSET(avatar)
			INIT_ISSET(avatarUrl)
			INIT_ISSET(remark)
			INIT_ISSET(sign)
			INIT_ISSET(pinyin)
			INIT_ISSET(status)
			INIT_ISSET(srvName)
			INIT_ISSET(area)
			INIT_ISSET(birthday)
			INIT_ISSET(phoneNums)
			INIT_ISSET(emails)
			INIT_ISSET(nickID)
			INIT_ISSET(buddySet)
			INIT_ISSET(securityLevel)
			INIT_ISSET(tagIds)
			INIT_ISSET(entExtend)
			
		}

		int64 userid;			///< 用户ID 	    userid.
		/**
		 * \brief 性别
		 * 1男，2女 其他保密
		 */
		IS_SET(int8, sex)
		/**
		 * \brief 星标好友
		 * 与上0x0001 = 1是星标好友， 该字段含有0x1000为应用, 0x2000标示是否为隐藏好友, 0x4000表示是否置顶
		 */
		IS_SET(int32, flag)
		IS_SET(std::string, name)		///< 用户名称 	name.
		/**
		 * \brief 用户头像
		 * 上传上去只是文件名，需要获取头像路径，拼接出路径
		 */
		IS_SET(std::string, avatar)
		IS_SET(std::string, avatarUrl)  ///< 好友头像服务器全路径
		IS_SET(std::string, remark)		///< 备注      remark.
		IS_SET(std::string, sign)		///< 个性签名   sign. 
		/**
		 * \brief 拼音，remark有值是remark的拼音，remark没值是name的拼音
		 * 格式 简拼$$全拼
		 * 比如 “连豆豆” 这个中文
		 * 简拼：ldd
		 * 全拼: liandoudou
		 * 该字段的值为 ldd$$liandoudou, 使用的时候注意分割
		 */
		IS_SET(std::string, pinyin)
		/**
		 * \brief 用户状态
		 * 1:正常,2:停用,3:注销,8:删除,16:隐藏
		 */
		IS_SET(std::string, status)
		///服务器名称
		IS_SET(std::string, srvName)	
		///地区
		IS_SET(std::string, area)
		///生日
		IS_SET(int64, birthday)
		//手机
		IS_SET(std::vector<std::string>, phoneNums)
		//邮箱
		IS_SET(std::vector<std::string>, emails)
		//账号
		IS_SET(std::string, nickID)
		///好友设置 用前4位表示免打扰，0x1为接收提醒,0x2表示不提醒仅显示数字,0x3为免打扰
		IS_SET(int64, buddySet)
		//工作密级
		IS_SET(int32, securityLevel)
		///用户标签id,多个用逗号分隔
		IS_SET(std::string, tagIds)
		///企业扩展信息
		IS_SET(std::string, entExtend)
	};

	/**
	 * \struct st_msgBean
	 * \brief 消息结构
	 */
	struct  st_msgBean
	{
        st_msgBean() {
            sendUserID = 0;
			receTargetID = 0;
			sendTime = 0;
			targetID = 0;
			isBurn = 0;
			messageType = 0;
			subMsgType = 0;
			lastMessageID = 0;
			senderSessionID = 0;
			activeType = 0;
			relatedMsgID = 0;
			localID = 0;
			msgRemindMode = 2;
			securityLevel = 0;
        }

		void init()
		{
			limitRange.clear();
			relatedUsers.clear();
		}

		int64 sendUserID;     ///< 消息发送人员ID sendUserID.
		int64 receTargetID;   ///< 消息接收者，有可能是自己，有可能是群 receTargetID.
		int64 sendTime;       ///< 发送时间 　　sendTime.
		int64 targetID;       ///< 肯定不是自己，有可能是别人或者群　targetID.
		std::string message;  ///< 消息内容 message.
		int8   isBurn;		  ///< 0x01为阅后即焚 isBurn.
		/**
		 * \brief 消息类型
		 * 分为两部分
		 * 1. 基本部分 messageType & 0x00FF
		 *    1: html , 2:文本 , 3: 音频 , 4: 位置 , 5:图片 , 6: 文件 , 7: 名片, 8: 弱提示
		 * 2. 附加部分 messageType & 0FF00
		 *    0x100: 为发送带附件的消息，附件上传失败会带有此标识 如图片，文件，音频等。
		 *    0x200: 为消息体本身发送失败，消息会含有此记录.
		 *    0x400: 为接收到带附件的消息，接收附件失败。
		 *    0x1000:  消息正在发送中
		 *    0x2000： 附件正在上传中
		 * Note: 上传附件和对应发送消息的localID必须保持一致
		 */
		int16   messageType;
		int32   subMsgType;		///< 消息子类型
		int64   messageID;      ///< 消息的整个系统里的唯一ID messageID.
		std::string format;     ///< 消息的格式 format.
		int64 lastMessageID;    ///< 上一条消息ID lastMessageID.
		int64 senderSessionID;  ///< 发送消息人员的会话ID senderSessionID.
		std::vector<int64>  limitRange; ///< limitRange limitRange.
		std::string msgProperties;		///< 消息属性　msgProperties.
		int8 activeType;                ///< 活动使用 ID activeType.
		std::vector<int64>  relatedUsers;///< @的人
		int64 relatedMsgID;             ///< 活动的响应 relatedMsgID.
		int64 localID;
		///陌生人单聊时的来源ID，1_groupID表示传的群ID，2_orgID表示传的组织ID
		std::string sourceID ;
		std::string memberName ;  ///< 群聊的时候值有效, 发送成员的名称. 单聊时也有效表示消息发送人员名称
		int8 msgRemindMode;		///< 0.免打扰 1.提醒始终有声音  2.提醒始终无声音  3.提醒  4.不提醒，仅显示条目 5.根据免打扰时间段判断是否免打扰
		//未读状态信息
		std::string unReadState;
		int64 realTargetId;   //真实接收者ID,用于客服之间客户消息
		int8 isCustom;  ///<是否是客服客户之间的66号消息 0.否 1.是
		int32 securityLevel;//密级
	};


	struct  st_tipmsgBean
	{
		int64 sendUserID;
		int64   messageID;      ///< 弱提示消息messageID.
		int64   relatedMsgID;      ///< 弱提示消息关联messageID.
	};

	/**
	 * \struct st_reqVerifyParam
	 * \brief  验证消息已读结构体
	 */
	struct st_reqVerifyParam
	{
		st_reqVerifyParam() :reqVerifyboxID(0), reqUserID(0) {}
		int64 reqVerifyboxID; ///< 验证ID reqVerifyboxID.
		int64 reqUserID;      ///< 发送验证请求的用户ID reqUserID.
	};

	/**
	 * \struct st_ureadMsgList
	 * \brief  未读消息推送结构体
	 */
	struct st_ureadMsgList
	{
		st_ureadMsgList() :unReadCnt(0), weakTipCnt(0) {}
		int32 unReadCnt;   ///< 未读消息数量  unReadCnt.
		int32 weakTipCnt;  ///< 未读中的弱提示数量 weakTipCnt.
		st_msgBean msg;    ///< 最后一条未读  msg.
	};

	/**
	 * \struct st_iosNoticeInfo
	 * \brief  IOS进入后台设置token结构体
	 */
	struct st_iosNoticeInfo
	{
		st_iosNoticeInfo() :recvType(0) {}
		/**
		 * \brief 接收类型 1. 免打扰，2. 取消免打扰
		 */
		int8 recvType;
		std::string token; ///< IOS token.
	};

	struct st_authenticationInfo
	{
		st_authenticationInfo() :type(0) {}
		int8 type;                               ///类型
		std::string password;
	};

	// TODO:
	struct  st_groupValAddedAttr
	{
		st_groupValAddedAttr() :groupValueAddedAttr(0), groupMemberNum(0) {}
		int64 groupValueAddedAttr;
		int32 groupMemberNum;
	};

	/**
	 * \struct st_orgUserinfo
	 * \brief  组织用户信息（搜索中使用）
	 */
	struct st_orgUserinfo
	{
		st_orgUserinfo() :
		userid(0) {
        }

		int64   userid; 	                        ///< 用户ID      userid.
		std::string name;                           ///< 用户名称 	 name.
		std::string orgname;                        ///< orgname 组织名称.
        std::string userHead;                       ///< 头像.
	};

    /**
    * \struct st_entpriseInfo
    * \brief 企业信息(搜索中使用)
    */
    struct  st_entInfo
    {
        st_entInfo() :
        enterpriseID(0){}

        int64 enterpriseID;         ///< 企业ID enterpriseID.
        std::string fullName;       ///< 企业全称 fullName.
        std::string shortName;      ///< 企业简称 shortName.
        std::string keyWords;       ///< 企业关键字 keyWords.
        std::string phone;          ///< 企业电话 phone.
    };

	/**
	 * \struct st_orGroupinfo
	 * \brief brief 组织信息（搜索中使用）
	 */
	struct st_orGroupinfo
	{
		st_orGroupinfo() :
		groupid(0),
		orderid(0) {
        }

		int64    groupid;
		int32    orderid;
		std::string groupname;
		std::string orgname;
	};

	/**
	 * \struct st_noDisturbModeInfo
	 * \brief
	 */
	struct st_noDisturbModeInfo
	{
		st_noDisturbModeInfo() :startTimer(0), endTimer(0), value(0) {}
		int32 startTimer;
		int32 endTimer;
		int8  value;
	};

	/**
	 * \struct st_userToTargetSwitchInfo
	 * \brief
	 */
	struct st_userToTargetSwitchInfo
	{
		st_userToTargetSwitchInfo() :targetUserId(0), typeValue(0), modeType(0) {}
		int64 targetUserId;
		int8  typeValue;
		int8  modeType;
	};

	/**
	 * \struct st_personalDataSwitchInfo
	 * \brief
	 */
	struct st_personalDataSwitchInfo {
		st_personalDataSwitchInfo() :switchType(0), value(0) {}
		int8 switchType;
		int8 value;
	};

	/**
	 * \struct st_orgOpenConfig
	 * \brief
	 */
	struct st_orgOpenConfig
	{
		st_orgOpenConfig() :teamID(0), openOrgID(0) {}
		int64 teamID;
		int64 openOrgID;
		std::vector<int64>  vtTargetOrgIDs;
	};

	/**
	 * \struct st_entAppinfo
	 * \brief 应用信息
	 */
	struct  st_entAppinfo
	{
		st_entAppinfo() :appID(0), entID(0), openIDEncoded(0), appSubType(0), recommend(0), defaultInstall(0),
			appType(0), status(0), subOrAppType(0), ownerId(0), forceGrant(0) {}
		std::string appSign;///< 应用标识
		std::string appName;///< 应用名称
		std::string appIcon;///< 应用图标
		std::string appIconUrl; ///服务器应用图标全路径
		int64 appID;        ///< 应用ID
		std::string appHomeUrl;///< 应用主页
		int64 entID;           ///< entID
		std::string entName;   ///< 应用名称
		std::map<std::string, std::string>  configItems; ///< 客户端配置
		std::string appSecret; ///< 应用密钥
		std::string appToken;  ///< 应用TOKEN
		std::string appMenus;  ///< 应用菜单
		int8	openIDEncoded; ///< openID是否编码，0:不编码，1:编码
		std::string subAccount;///< 应用子账号
		///子类型  1 H5应用，2 移动应用
		int8 appSubType;
		///推荐 1 是 ，2 否
		int8 recommend;
		/// 默认安装 1 是 ，2 否
		int8 defaultInstall;
		///扩展字段 json 格式，mainUrl H5首页，adminUrl 后台管理地址，myUrl 个人中心地址
		std::string extend;
		///设备类型 1(iPhone_E), 2(iPad_E), 3(iPhone), 4(iPad), 5(androidPhone), 6(androidPad)
		std::string deviceTypes;
		///消息历史地址
		std::string messageHistoryUrl;
		///是否启用自定义菜单   1 启用  0停用
		std::string menuOpen;
		///是否启用自定义菜单响应事件  1启用 0停用
		std::string replyMenuOpen;
		///智能开关 2
		int8 appType;
		///公众号状态
		int8 status;
		///1:订阅号2：企业号
		int8 subOrAppType;
		///应用功能介绍
		std::string appFunctintroduce;
		///公众号介绍
		std::string appDescription;
		///公众号创建者id  可能是appid也可能是userid
		int64 ownerId;
		///应用是否需要强制授权1需要，0不需要
		int8 forceGrant;
		///授权介绍
		std::string grantIntroduce;
	};

	/**
	 * \struct  st_tinyGroupBean
	 * \brief   群数据结构
	 */
	struct st_tinyGroupBean
	{
		st_tinyGroupBean() :memberNums(0), level(0), powerSwitch(0), securityLevel(0)
		{
			INIT_ISSET(memberNums)
			INIT_ISSET(level)
			INIT_ISSET(groupID)
			INIT_ISSET(createrID)
			INIT_ISSET(createTime)
			INIT_ISSET(relatedGroupID)
			INIT_ISSET(relatedEnt)
			INIT_ISSET(name)
			INIT_ISSET(pinyin)
			INIT_ISSET(icon)
			INIT_ISSET(srvName)
			INIT_ISSET(groupType)
			INIT_ISSET(securityLevel)
			INIT_ISSET(powerSwitch)
		}

		void init()
		{
			INIT_ISSET(memberNums)
			INIT_ISSET(level)
			INIT_ISSET(groupID)
			INIT_ISSET(createrID)
			INIT_ISSET(createTime)
			INIT_ISSET(relatedGroupID)
			INIT_ISSET(relatedEnt)
			INIT_ISSET(name)
			INIT_ISSET(pinyin)
			INIT_ISSET(icon)
			INIT_ISSET(srvName)
			INIT_ISSET(groupType)
			INIT_ISSET(securityLevel)
			INIT_ISSET(powerSwitch)
		}
		
		IS_SET(int32, memberNums)		///< 群成员数  memberNums.	
		/**
		* \brief 群等级 从低到高,1到4位代表群等级，5到6位不为0代表为互联群，7到8位位代表是否为v标群, 9到10位代表是否置顶(0表示未置顶，1表示置顶)，
		*  11位到12位代表群通知消息内容模式: 1、通知详情  2、通知源，隐藏内容  3、完全隐藏
		*  15位到16位代表是否为隐藏群：0，非隐藏 1，隐藏
		*  17位到18位代表是否允许主动退出, 0:可以主动退出,1:不能主动退出
		*/
		IS_SET(int32, level)					
		IS_SET(int64, groupID)			///< 群ID   groupID.		
		IS_SET(int64, createrID)		///< 创建者ID  createrID.		
		IS_SET(int64, createTime)		///< 创建时间	  createTime.	
		IS_SET(int64, relatedGroupID)	///< 关联群ID，存在关联群ID则属于群内房间 relatedGroupID.	
		IS_SET(int64, relatedEnt)		///< 关联企业ID,	relatedEnt.	
		IS_SET(std::string, name)		///< 群名称 name.
		IS_SET(std::string, pinyin)		///< 拼音名称 pinyin.
		IS_SET(std::string, icon)		///< 群头像	icon.
		IS_SET(std::string, iconUrl)    ///< 群头像服务器全路径
		IS_SET(std::string, srvName)	///< 服务器名称  
		IS_SET(std::string, groupType)	///< 群分类 groupType.

		IS_SET(int32, securityLevel)    ///< 群密级 securityLevel 
		IS_SET(int8, powerSwitch)       ///< 提权开关 powerSwitch 默认0关闭
	};

	/**
	 * \struct st_groupBean
	 * \brief  群数据结构
	 */
	struct st_groupBean
	{
		st_groupBean() :isActive(1), isSearch(1)
		{
			INIT_ISSET(isActive)
			INIT_ISSET(isSearch)
			INIT_ISSET(serverInfo)
			INIT_ISSET(brief)
			INIT_ISSET(groupType)
			INIT_ISSET(bulletin)
			INIT_ISSET(chatImage)
			INIT_ISSET(extend)
			INIT_ISSET(groupMessageContentMode)
			INIT_ISSET(disturbSet)
			INIT_ISSET(timeForbidUtil)
			INIT_ISSET(info)
		}
		void init()
		{
			INIT_ISSET(isActive)
			INIT_ISSET(isSearch)
			INIT_ISSET(serverInfo)
			INIT_ISSET(brief)
			INIT_ISSET(groupType)
			INIT_ISSET(bulletin)
			INIT_ISSET(chatImage)
			INIT_ISSET(extend)
			INIT_ISSET(groupMessageContentMode)
			INIT_ISSET(disturbSet)
			INIT_ISSET(privateMsgPwd)
			INIT_ISSET(timeForbidUtil)
			INIT_ISSET(info)
			info.init();
		}
		/**
		 * \brief 激活群
		 * 1. 激活， 2：未激活
		 */
		IS_SET(int32, isActive)
		IS_SET(int32, isSearch)			///< 是否可以被检索 1可以，2不可以 isSearch.
		IS_SET(std::string, serverInfo) ///< 本地服务器地址 serverInfo.
		IS_SET(std::string, brief)		///< 群简介 brief.
		IS_SET(std::string, groupType)	///< 群分类 groupType.
		IS_SET(std::string, bulletin)	///< 群公告 bulletin.
		IS_SET(std::string, chatImage)	///< 群聊背景 chatImage.
		/** 
		 *	\brief 群扩展字段,以json形式,目前： 
		 *  警种ID： policeTypeID
		 *  地域---省份ID：provinceID
		 *  地域---市ID： cityID
		 *  私信模式：privateMsg：1为开启私信   0表示不允许私信 extend.
		 */
		IS_SET(std::string, extend)
		/** 
		 *	\brief 群消息通知详情: 1、开启(显示详情)  2、关闭(显示通知源，隐藏内容)  默认开启 groupMessageContentMode.
		 */
		IS_SET(int8, groupMessageContentMode)
		/**
		*	\brief 免打扰 1为接收提醒, 2表示不提醒仅显示数字, 3为免打扰
		*/
		IS_SET(int8, disturbSet)
		
		IS_SET(std::string, privateMsgPwd);	///< 私信密码 privateMsgPwd.

		IS_SET(int64, timeForbidUtil);	///< 群禁言，-1或0表示不禁言，禁言截止的毫秒数.

		IS_SET(st_tinyGroupBean, info)	///< 群信息 info.		
	};

	/**
	 * \struct st_groupSet
	 * \brief  群验证方式信息
	 */
	struct st_groupSet
	{
		st_groupSet() :verifyType(0), isAllow(0), isAllowTransferOwner(0), isAllowAdminInvite(1), isChase(0), isShake(0) {}
		int8 verifyType;		///< 验证类型:1:不允许任何人添加,2：需要验证信息,3：允许任何人添加 verifyType.
		int8 isAllow;			///< 是否允许群成员邀请好友加入群:1,允许 2,不允许 isAllow.
		int8 isAllowTransferOwner;///<企业群群主是否可以转让群 0否(默认), 1是
		int8 isAllowAdminInvite;  ///企业群管理员是否可以邀请入群  0否, 1是(默认)
		int8 isChase;	///< 是否开启追一下;2-关闭；1-开启(默认)
		int8 isShake;	///< 是否开启抖一抖;2-关闭(默认)；1-开启
	};

	/**
	 * \struct st_shieldGroupMessage
	 * \brief  群信息提示方式
	 */
	struct st_shieldGroupMessage {
		st_shieldGroupMessage()
		{
			INIT_ISSET(pcMsgSet)
			INIT_ISSET(phoneMsgSet)
			INIT_ISSET(htmlMsgSet)
			INIT_ISSET(groupMessageContentMode)
			INIT_ISSET(msgRecvTime)
		}
		void init()
		{
			INIT_ISSET(pcMsgSet)
			INIT_ISSET(phoneMsgSet)
			INIT_ISSET(htmlMsgSet)
			INIT_ISSET(groupMessageContentMode)
			INIT_ISSET(msgRecvTime)
		}

		IS_SET(int8, pcMsgSet)				 ///< PC群消息设置 1：提示接收 2：不提示，显示数目 3：屏蔽消息 4：时间段接收 5：插电接收 pcMsgSet.
		IS_SET(int8, phoneMsgSet)			 ///< phone/pad群消息设置 1：提示接收 2：不提示，显示数目 3：屏蔽消息 4：时间段接收 5：插电接收 phoneMsgSet.
		IS_SET(int8, htmlMsgSet)			 ///< HTML群消息设置 1：提示接收 2：不提示，显示数目 3：屏蔽消息 4：时间段接收 5：插电接收 htmlMsgSet.
		int64 groupid;
		IS_SET(int8, groupMessageContentMode) ///< 群通知消息内容模式: 1、通知详情  2、通知源，隐藏内容  3、完全隐藏 , 默认开启模式1
		IS_SET(std::string, msgRecvTime)	 ///< 接收消息时间段 msgRecvTime.
	};

	/**
	 * \struct st_tinyGroupMemberBean
	 * \brief  群成员结构
	 */
	struct st_tinyGroupMemberBean {
		st_tinyGroupMemberBean()
		{
			INIT_ISSET(sex)
			INIT_ISSET(userType)
			INIT_ISSET(userid)
			INIT_ISSET(memberName)
			INIT_ISSET(avatar)
			INIT_ISSET(avatarUrl)
			INIT_ISSET(vSign)
			INIT_ISSET(pinyin)
			INIT_ISSET(name)
			INIT_ISSET(timeForbidUtil)
			INIT_ISSET(securityLevel)
			INIT_ISSET(status)
		}
		void init()
		{
			INIT_ISSET(sex)
			INIT_ISSET(userType)
			INIT_ISSET(userid)
			INIT_ISSET(memberName)
			INIT_ISSET(avatar)
			INIT_ISSET(avatarUrl)
			INIT_ISSET(vSign)
			INIT_ISSET(pinyin)
			INIT_ISSET(name)
			INIT_ISSET(timeForbidUtil)
			INIT_ISSET(securityLevel)
			INIT_ISSET(status)
			avatar = "";
			avatarUrl = "";
		}
		IS_SET(int8, sex)			///< 性别 1男 2女 0保密 sex.	 		
		IS_SET(int8, userType)		///< 用户类型复用，与上0x0F  1：普通用户 2：管理员 3：超级管理员; 与上0xF0＝0xF0: 该群成员为应用 userType.			
		IS_SET(int64, userid)		///< 用户ＩＤ，当userType为１００的时候是应用 userid.	
		IS_SET(std::string, name)	///< 成员名称
		IS_SET(std::string, memberName)	///< 群名称 memberName.	
		IS_SET(std::string, avatar)		///< 用户头像 avatar.
		IS_SET(std::string, avatarUrl)  ///< 头像服务器全路径
		IS_SET(int8, vSign)				///< 是否为v标群，0不是 1是 只有当群成员为用户自己时使用				
		/**
		 * \brief 拼音，memberName
		 * 格式 简拼$$全拼
		 * 比如 “连豆豆” 这个中文
		 * 简拼：ldd
		 * 全拼: liandoudou
		 * 该字段的值为 ldd$$liandoudou, 使用的时候注意分割
		 */
		IS_SET(std::string, pinyin)
		IS_SET(int64, timeForbidUtil)
		IS_SET(int32, securityLevel)
		IS_SET(int8, status)     /// 离职状态标记功能添加，群成员也展示状态
	};

	/**
	 * \struct st_groupMemberBean
	 * \brief
	 */
	struct st_groupMemberBean{
		st_groupMemberBean() :birthday(0) {}
		int64 birthday;
		std::string name;
		std::string nickID;
		std::string sign;
		std::vector<std::string> phones;
		std::vector<std::string> emails;
		st_tinyGroupMemberBean info;
		/**
		 * \brief 如果获取的群成员是自己的话，这个字段的值有效。
		 * 标识这个群
		 */
		st_shieldGroupMessage  shield;
	};

	/**
	 * \struct st_buddyReqBean
	 * \brief 添加好友结构
	 */
	struct  st_buddyReqBean
	{
		st_buddyReqBean() :reqVerifyboxID(0), requestType(0), requestTime(0), isResponse(0) {}
		int64 reqVerifyboxID;
		st_smallUserBean reqUserBean;
		std::vector<std::string>  verifyInfo;
		int8 requestType;
		int64 requestTime;
		int8 isResponse;
	};

	/**
	 * \struct st_buddyRespBean
	 * \brief 添加好友响应结构体
	 */
	struct st_buddyRespBean
	{
		st_buddyRespBean() :respVerifyboxID(0), isAgree(0), responseTime(0) {}
		int64 respVerifyboxID;
		st_smallUserBean respUserBean;
		std::string refuseReason;
		int8   isAgree;
		int64 responseTime;
	};

	//=================================<其它协议>============================================//
	///发送文件结构.
	struct   st_sendFile
	{
		st_sendFile() :fileSign(0),isResume(false), mediaTime(0), securityLevel(0){};
		int32           fileSign;	///< 文件唯一标识
		std::string     localPath;  ///< 本地地址
		std::string     dirPath;    ///< 文件夹地址，上传文件夹时使用
		bool            isResume;   ///< 是否断点上传
		//以下iOS专用字段
		std::string		relaPath;	///< 相对路径
		int32			mediaTime;  ///< 音频时长
		int32           securityLevel; ///<密级
	};

	///文件结构
	struct st_Fileinfo
	{
		st_Fileinfo() :isEncrypt(0),fileID(0),userID(0),targetID(0),fileSize(0),uploadTime(0),fileTerm(1){};

		int8    isEncrypt;		///< 是否加密
		int64   fileID;			///< 文件ID
		int64   userID;			///< 发送者
		int64   targetID;		///< 目标对象, 可能是用户,也可能是群
		int64   fileSize;		///< 文件大小
		int64   uploadTime;		///< 上传时间
		int8	fileTerm;		///< 群文件有效期< 1.临时 2.永久
		int8	fileType;		///< 文件类型  6.文档 5.图片(九宫格存储是5) 89.视频 3.音频
		std::string filePath;   ///< 本地路径
		std::string fileName;	///< 文件名
		std::string fileUrl;	///< 文件URL
		std::string secretKey;	///< 加密KEY
		std::string fromName;   ///< 发送者名字，如果在本地没找到返回空
		std::string thumbPath;
		std::string thumbUrl;
		std::string thumbRelaPath;
		std::string relaPath;
		std::string ext;
		int32    securityLevel; ///<密级
	};

	struct st_FileExpirySoon :public st_Fileinfo
	{
		st_FileExpirySoon()
		{
			fileID = 0;
			fileUrl = "";
			targetID = 0;
			targetName = "";
			isSwitchOn = 0;
			fromUserID = 0;
			fileName = "";
			uploadAt = 0;
			validDays = 0;
			flag = 0;
		}
		void init()
		{
			fileID = 0;
			fileUrl = "";
			targetID = 0;
			targetName = "";
			isSwitchOn = 0;
			fromUserID = 0;
			fileName = "";
			uploadAt = 0;
			validDays = 0;
			flag = 0;
		}

		int64 fileID;						///<文件ID，唯一性，同msgID
		std::string fileUrl;				///<文件链接地址，唯一性
		int64 targetID;					///<群或人ID
		std::string targetName;		///<群或人名称
		int isSwitchOn;					///<开关状态
		int64 fromUserID;				///<文件发送者
		std::string fileName;			///<文件名称
		int64 uploadAt;					///<上传时间
		int validDays;						///<有效天数
		int flag;								///<0未下载，1已下载
	};

	struct st_FileExpirySoonResult :public st_Fileinfo
	{
		st_FileExpirySoonResult()
		{
			targetID = 0;
			fileID = 0;
			//fileUrl = "";
			//targetName = "";
			isSwitchOn = 0;
			//fromUserID = 0;
			//fileName = "";
			//uploadAt = 0;
			//validDays = 0;
			visitDate = "";
			//flag = 0;
			isRemind = 0;
		}
		void init()
		{
			targetID = 0;
			fileID = 0;
			//fileUrl = "";
			//targetName = "";
			isSwitchOn = 0;
			//fromUserID = 0;
			//fileName = "";
			//uploadAt = 0;
			//validDays = 0;
			visitDate = "";
			//flag = 0;
			isRemind = 0;
		}

		int64 targetID;					///<群/人 ID
		int64 fileID;						///<文件ID，唯一性，同msgID
		//std::string fileUrl;				///<文件链接地址，唯一性
		//std::string targetName;		///<群或人名称
		int isSwitchOn;					///<开关状态
		//int64 fromUserID;				///<文件发送者
		//std::string fileName;			///<文件名称
		//int64 uploadAt;					///<上传时间
		//int validDays;						///<有效天数
		std::string visitDate;
		//int flag;								///<0未下载，1已下载
		int isRemind;					///当天多次访问
	};

	struct st_FileExpiryInfoStore :public st_Fileinfo
	{
		st_FileExpiryInfoStore()
		{
			targetID = 0;
			fileID = 0;
			//fileUrl = "";
			//targetName = "";
			isSwitchOn = 0;
			//fromUserID = 0;
			//fileName = "";
			//uploadAt = 0;
			//validDays = 0;
			//flag = 0;
			visitDate = "";
		}
		void init()
		{
			targetID = 0;
			fileID = 0;
			//fileUrl = "";
			//targetName = "";
			isSwitchOn = 0;
			//fromUserID = 0;
			//fileName = "";
			//uploadAt = 0;
			//validDays = 0;
			//flag = 0;
			visitDate = "";
		}

		int64 targetID;					///<群或人ID
		int64 fileID;						///<文件ID，唯一性，最大msgID
		//std::string fileUrl;				///<文件链接地址，唯一性
		//std::string targetName;		///<群或人名称
		int isSwitchOn;					///<开关状态
		//int64 fromUserID;				///<文件发送者
		//std::string fileName;			///<文件名称
		//int64 uploadAt;					///<上传时间
		//int validDays;						///<有效天数
		//int flag;								///<0未下载，1已下载
		std::string visitDate;			///<访问日期
	};

	struct st_FileExpiryInfoAsk :public st_Fileinfo
	{
		st_FileExpiryInfoAsk()
		{
			fileID = 0;
			//fileUrl = "";
			targetID = 0;
			//targetName = "";
			isSwitchOn = 0;
			//fromUserID = 0;
			///fileName = "";
			//uploadAt = 0;
			//validDays = 0;
			//flag = 0;
		}
		void init()
		{
			fileID = 0;
			//fileUrl = "";
			targetID = 0;
			//targetName = "";
			isSwitchOn = 0;
			//fromUserID = 0;
			//fileName = "";
			//uploadAt = 0;
			//validDays = 0;
			//flag = 0;
		}

		int64 fileID;						///<文件ID，唯一性，同msgID
		//std::string fileUrl;				///<文件链接地址，唯一性
		int64 targetID;					///<群或人ID
		//std::string targetName;		///<群或人名称
		int isSwitchOn;					///<开关状态
		//int64 fromUserID;				///<文件发送者
		//std::string fileName;			///<文件名称
		//int64 uploadAt;					///<上传时间
		//int validDays;						///<有效天数
		//int flag;								///<0未下载，1已下载
	};

	struct st_GroupDocAttribute :public st_Fileinfo{
		st_GroupDocAttribute() : status(0)
		{
			createAt = 0;
			updateAt = 0;
			deleteAt = 0;
			version = 0;
			lastModifiedBy = 0;
			url = "";
			encryptAlgorithm = "";
			hashcode = "";
			validityDays = -1;
			permission = 0;
			modContentVersion = 0;
		}

		std::string url; // upload返回的路径
		std::string encryptAlgorithm; // 加密算法optional
		std::string hashcode; // 文件hash值 optional
		int8 status; // 1: 新增 2: 改名 3: 删除
		int8 type;
		int64 createAt;
		int64 updateAt;
		int64 deleteAt;
		int64 version;
		int64 lastModifiedBy;//optional 
		int64 validityDays;
		int8 permission;//0 只读 1可读可写 默认是0
		int64 modContentVersion; //最后一次在线编辑 version
	};


	//群文档上传下载结构体  edit by :jss
	struct st_GroupDocUpdownInfo :public st_Fileinfo{
		st_GroupDocUpdownInfo() :status(0), version(0)
		{
			createAt = 0;
			docLocalID = 0;
			uploader = 0;
			downloader = 0;
			validityDays = -1;
			permission = 0;
			modContentVersion = 0;
		}
		int64 createAt;									    ///< 创建时间，主键
		int64 docLocalID;									///< 文档localid
		int64 uploader;								        ///< 上传者
		int64 downloader;                                   ///< 下载者
		int	status;                          				///< 状态  1:正在上传 2:等待上传 3:上传完成 4:上传失败 5:重新上传 6:下载完成
		int64 version;							            ///< 文档版本
		int64 validityDays;
		int8 permission;//0 只读 1可读可写 默认是0
		int64 modContentVersion; //最后一次在线编辑 version

	};



	struct  YMD
	{
		YMD() :year(0), month(0), day(0) {}
		int16  year;
		int8   month;
		int8   day;
	};

	///应用信息
	struct st_tinyAppInfo {
		st_tinyAppInfo() : appID(0),entID(0),openIDEncoded(0),appSubType(0),recommend(0),defaultInstall(0),
		appType(0),status(0),subOrAppType(0),ownerId(0),forceGrant(0),CSID(0){
			configKey.clear();
			configVal.clear();
		}

		void init() {
			configKey.clear();
			configVal.clear();
		}

		std::string appSign; ///< 应用标识
		std::string appName; ///< 应用名称
		std::string appIcon; ///< 应用图标
		int64       appID;   ///< 应用ＩＤ
		std::string homeUrl; ///< 主页地址
		int64       entID;   ///< 企业ＩＤ
		std::string entName; ///< 企业名称
		///客户端配置ＫＥＹ
		std::vector<std::string> configKey;
		///客户端配置ＶＡＬＵＥ
		std::vector<std::string> configVal;
		///应用密钥
		std::string appSecret;
		///应用令牌
		std::string appToken;
		std::string appMenus;  ///应用菜单
		int8	openIDEncoded; ///openID是否编码，0:不编码，1:编码
		std::string subAccount;///机器人子账户列表 json格式数据

		///子类型  1 H5应用，2 移动应用
		int8 appSubType;
		///推荐 1 是 ，2 否
		int8 recommend;
		/// 默认安装 1 是 ，2 否
		int8 defaultInstall;
		///扩展字段 json 格式，mainUrl H5首页，adminUrl 后台管理地址，myUrl 个人中心地址
		std::string extend;
		///设备类型 1(iPhone_E), 2(iPad_E), 3(iPhone), 4(iPad), 5(androidPhone), 6(androidPad)
		std::string deviceTypes;
		///消息历史地址
		std::string messageHistoryUrl;
		///是否启用自定义菜单   1 启用  0停用
		std::string menuOpen;
		///是否启用自定义菜单响应事件  1启用 0停用
		std::string replyMenuOpen;
		///智能开关 2
		int8 appType;
		///公众号状态
		int8 status;
		///1:订阅号2：企业号 3:应用号
		int8 subOrAppType;
		///应用功能介绍
		std::string appFunctintroduce;
		///公众号介绍
		std::string appDescription;
		///公众号创建者id  可能是appid也可能是userid
		int64 ownerId;
		///应用是否需要强制授权1需要，0不需要
		int8 forceGrant;
		///授权介绍
		std::string grantIntroduce;
		///客服ID
		int64 CSID;
	};

	///应用市场应用分类
	struct st_smallMarketAppType
	{
		st_smallMarketAppType() :appTypeID(0) {}
		int64 appTypeID;         ///< 应用分类id
		std::string appTypeName; ///< 应用分类名称
	};
	///本地配置条目
	struct st_localSetting {
		std::string key; ///标识
		std::string val; ///值
	};

	//搜索返回群或个人的简要信息
	struct st_simpleSearchInfo
	{
		st_simpleSearchInfo() :targetFlag(0) {}
		/**
		* \brief 0x01男，0x02女,0x08为群，0x10为app, 0 非男非女为保密
		*/
		int8 targetFlag;
		///对象名称
		std::string name;
		///头像
		std::string avatr;
		std::string avatrUrl; ///头像服务器全路径
	};

	///保存搜索的targetId对象的简要信息和搜索出的消息数量
	struct st_msgGlobalSearch
	{
		st_msgGlobalSearch() :targetID(0), amount(0), lastTime(0){}
		///会话对象
		int64 targetID;
		///搜索到的target最新消息时间
		int64 lastTime;
		///消息数目
		int amount;
		///群或个人的简要信息
		st_simpleSearchInfo info;
		st_msgBean msg; //匹配到的第一条消息
	};

	///近距离加好友、群请求结构
	struct st_faceToFaceBean
	{
		st_faceToFaceBean() :uid(0), longitude(0), latitude(0)
		{
			INIT_ISSET(passwd)
		}
		void init()
		{
			INIT_ISSET(passwd)
		}

		int64  uid;					///< 用户Id
		double longitude;			///< 经度
		double latitude;			///< 纬度
		IS_SET(std::string, passwd) ///< 房间密码
		int8 operation;				///< 操作类型 1.建群 2.加好友
	};

	/// 第三步 做真正的操作
	struct st_userAccountOperate
	{
		st_userAccountOperate()
		{
			INIT_ISSET(operation)
			INIT_ISSET(registryID)
			INIT_ISSET(code)
		}

		IS_SET(int8, operation)    ///< 1: 绑定 2: 解绑
		IS_SET(int64, registryID)  ///< 需要验证的那些都需要填写
		IS_SET(std::string, code)  ///< 验证码
	};

	/// 通信录信息
	struct st_contactBean
	{
		st_contactBean() :source(0), area(0) {}
		std::string contactNum;   ///< 联系人号码
		std::string name;         ///< 联系人姓名
		int8 source;              ///< 数据来源 1：手机通讯录； 2：qq好友；
        int8 area;                ///< 号码归属地 1：国内； 2：国际；
	};

	struct st_autoAttentionBean
	{
		st_contactBean contact;
		st_tinyUserBean userBean;
	};
	/// 推荐信息
	struct st_recommendContact
	{
		st_recommendContact() :isBuddy(0) {}
		st_contactBean contact;     ///< 通信录信息
		st_smallUserBean sub;       ///< 联系人信息
		st_smallUserBean recommend; ///< 推荐者信息
		int8 isBuddy;               ///< 是否是好友标识，1表示是好友关系，2表示不是好友关系, 3表示等待验证
	};

	///分享设置选项
	struct st_shareOptionBean
	{
		st_shareOptionBean() :shareType(0), targetUserID(0) {}
		int8 shareType;          ///< 1:不允许他看我的分享，2：不看他的分享 
		int64 targetUserID;      ///< 目标用户ID
	};

	//用户自定义信息
	struct st_personDefinition
	{
		st_personDefinition() :defType(0) {}
		int8 defType;         ///< 1表示推送通知提示音
		std::string value;    ///< defType=1的时候表示提示音的名字
	};
	
	///数据字典
	struct st_enterpriseDictionary
	{
		st_enterpriseDictionary() :id(0), parentId(0) {}
		int32 id;                ///< 组织ID
		int32 parentId;          ///< 父组织ID
		std::string dicValue;    ///< 字段的名字
		std::string dickey;      ///< 字段的键值
		std::string extend;      ///< 扩展字段，格式为{"isEdit":0,"isFriend":0,"isInput":0,"isLogin":0,"isShow":0,"isStrange":0},isEdit:是否客户端可编辑;isFriend:客户端是否好友可见;isInput:是否必填字段;isLogin:是否登录项字段;isShow:客户端组织架构是否可见;isStrange:客户端是否陌生人可见
	};

	///查询标签
	struct st_queryTag
	{
		st_queryTag() :key(0) {}
		int32 key;
		std::string value;
	};

	///应用市场信息
	struct st_smallMarketAppInfo
	{
		st_smallMarketAppInfo() :appID(0), entID(0), ownerId(0), status(0), appType(0), defaultInstall(0),
		showInMy(0), sourceType(0), vestAppID(0), appTypeID(0), mustUpdate(2) {}
		int64 appID;                   ///< 应用ID
		int64 entID;                   ///< 企业ID
		int64 ownerId;                 ///< 所有者id
		int8 status;                   ///< 状态 1启用，2停用，3删除
		int8 appType;                  ///< 类型：1(H5应用), 2(IOS应用), 3(Android应用), 4(内部应用), 5(快捷应用)
		int8 defaultInstall;           ///< 默认安装 1 是 ，2 否
		int8 showInMy;                 //< 个人安全中心是否展示 1 是 ，2 否
		std::string appSign;           ///< 应用标识
		std::string appName;           ///< 应用名称
		std::string appIcon;           ///< 应用图标		
		std::string appIconUrl;           ///< 应用图标url		
		std::string appFunctintroduce; ///< 应用功能介绍
		std::string version;           ///< 版本号	
		std::string mainUrl;           ///< H5首页
		std::string adminUrl;          ///< 后台管理地址
		std::string myUrl;             ///< 个人中心地址
		std::string packageName;       ///< 包名
		std::string downloadUrl;       ///< 下载地址
		std::string urlScheme;         ///< urlScheme
		std::string quickUrl;          ///< 快捷应用地址
		std::string extend;            ///< 扩展字段
		std::string activityName;      ///< activity
		std::vector<st_queryTag> tags; ///< 查询标签
		int8 sourceType;               ///< 应用来源 1：后台管理应用 2：开放平台应用
		int64 vestAppID;               ///< 应用对应的应用号id 
		int64 appTypeID;               ///< 应用分类id
		std::string appTypeName;       ///< 应用分类名称
		std::string processName;       ///< 进程名
		std::string updateExplain;     ///< 更新说明
		std::string introduce;         ///< 应用简介（edit by jss 2021/04/27）
		int8 mustUpdate;               ///< 1,必须升级，2不必须 默认为2
	};
	///应用市场分页查询结果新增群应用
	struct st_smallMarketAppPage
	{
		st_smallMarketAppPage() : pageNum(0), pageSize(0), count(0), totalPage(0)
		{
			appInfoList.clear();
		}
		int32 pageNum;                              ///< 页码
		int32 pageSize;                             ///< 页长
		int32 count;                                ///< 总数
		int32 totalPage;                            ///< 总页数
		std::vector<st_smallMarketAppInfo> appInfoList; ///< 应用列表
		std::map<int8, std::map<int64, st_smallMarketAppInfo> > extMap; ///<为以后考虑，标识暂时1为工作台隐藏应用2为群隐藏应用
	};
	
	struct st_emoticon
	{
		st_emoticon():userID(0),createTime(0),property(0),emoStatus(0),type(0),category(0),bRead(0){}
		std::string mdCode;         ///< 整个文件的MD5hashcode码
		std::string depict;         ///< 表情描述
		int64 userID;               ///< 表情创建人
		int64 createTime;           ///< 创建时间
		std::string mainUrl;        ///< 表情Url
		int8 property;              ///< 表情属性 1：表情包2：自定义表情
		int8 emoStatus;             ///< 表情状态 1：服务器记录该文件被下载或收藏 2：服务器记录该文件被卸载或取消收藏
		std::string packageCode;    ///< 关联表情包Code
		int8 type;                  ///< 表情类型 1：静态表情2：动态表情
		///表情类目 1人物 2情侣 3动物 4食物 5节日 6网络热点 7征稿活动 8其他
		int8 category;
		///表情标签  多个标签用分隔符分开，web端自己定义自己解析，服务只做存储
		std::string label;
		std::string thumbnailUrl;     ///< 缩略图url
		std::string meaning;          ///< 表情含义
		std::string orderNum;         ///< 排序字段
		std::string extendFiled;      ///< 拓展字段1
		std::string extendColumn;     ///< 拓展字段2
		std::string sha256Hash;       ///< 表情sha256
		int8 bRead;                   ///< 是否已读，0表示未读，1表示已读
		std::string domainPort;        ///< 来源域名加端口
		std::string elogo;            ///< 来源elogo
		std::string gifPath;           ///< 动态图片本地路径
		std::string pngPath;           ///< 静态图片本地路径
		std::string emotionSdkPath;    ///< 表情存储在sdk的跟路径
	};

	struct st_singleEmoticon
	{
		st_singleEmoticon()
		{

		}
		std::string mdCode;               ///< 单个表情MdCode
		std::string thumbnailUrl;
		std::string mainUrl;              ///< 大图地址
		std::string meaning;              ///< 含义	
	};
	struct st_emoticonPackage
	{
		st_emoticonPackage() :userID(0), createTime(0), property(0), packStatus(0), type(0), category(0), bRead(0) {}
		std::string mdCode;          ///< 整个文件的MD5hashcode码
		std::string depict;          ///< 表情描述
		int64 userID;                ///< 表情创建人
		int64 createTime;            ///< 创建时间
		std::string mainUrl;         ///< 表情Url
		int8 property;               ///< 表情属性 1：表情包2：自定义表情
		int8 packStatus;             ///< 表情状态 1：服务器记录该文件被下载或收藏 2：服务器记录该文件被卸载或取消收藏
		std::string name;            ///< 表情包名称
		std::string bannerUrl;       ///< 详细页横幅URL
		int8 type;                   ///< 表情类型 1：静态表情2：动态表情
		///表情类目 1人物 2情侣 3动物 4食物 5节日 6网络热点 7征稿活动 8其他
		int8 category;
		///表情标签  多个标签用分隔符分开，web端自己定义自己解析，服务只做存储
		std::string label;
		std::string iconUrl;             ///< 图标url
		std::string coverUrl;            ///< 封面URL
		std::string instruction;         ///< 表情包说明
		std::string orderNum;            ///< 排序字段
		std::string extendFiled;         ///< 拓展字段1
		std::string extendColumn;        ///< 拓展字段2
		std::vector<st_emoticon> emoticonList; //单个表情列表
		//std::string emoticonListJson;    ///< 关联表情 格式json-list<map>
		int8 bRead;                   ///< 是否已读，0表示未读，1表示已读
		int64 updatetime;
	    std::string domainPort;        ///< 来源域名加端口
	    std::string elogo;            ///< 来源elogo
	    std::string emotionSdkPath;    ///< 表情包存储在sdk的跟路径

	};

	struct st_emoticonResult
	{
		st_emoticonResult() :resultCode(0), orderNum(0) ,status(0), type(0){}
		int resultCode;                  ///< 结果编码 801:md5Code不存在，802：md5Code文件已存在
		std::string resultMessage;       ///< 结果信息
		std::string mdCode;              ///< 表情code
		int64 orderNum;                    ///< 排序

		std::string mainUrl;
		std::string thumbnailUrl;
		std::string name;
		std::string shaHash;
		int status;  //1表示新增 2表示删除
		int type;   //1表示表情包 2表示自定义表情
	};
	
	///局域网用户
	struct st_p2pUser {
		st_p2pUser() :userid(0), flag(0) {}
		int64 userid ; ///< 用户ID
		int8  flag   ; ///< PC 0x01，移动 0x02
	};

	///更新的解密消息
	/*struct st_updateMsg
	{
		int64 targetId;
		///msgId,messsage和msgProperty一一对应
		std::vector<int64> msgId;
		std::vector<std::string> message;		
		std::vector<std::string> msgProperty;
	};*/

	struct st_sysMsg
	{
		st_sysMsg() :msgID(0), userID(0), groupID(0), msgType(0), time(0), isResponse(0), isRead(0), opType(0), subType(0), securityLevel(0) {}
		int64 msgID;									///< 消息ID msgID.
		int64 userID;									///< 用户ID userID.
		int64 groupID;									///< 群ID groupID.
		/**
		* \brief 1:加好友请求
		* 2:加好友响应
		* 3:加群请求
		* 4:加群响应
		*/
		int32 msgType;
		int32 securityLevel;							///密级
		int64 time;										///< 时间秒 time.
		int32 isResponse;								///< 是否需要回复:	1:需要应答，	2：不需要应答 isResponse.
		int32 isRead;									///< ０未读，１已读 isRead.
		/**
		* \brief #msgType=1  1: 通过，２：拒绝，３：永久拒绝 4:忽略 0:没有操作
		*  #msgType=2  1: 通过，２：拒绝，３：永久拒绝
		*  #msgType=3  1: 忽略，２：同意，３：拒绝，４：永久拒绝，５：解散，６：移出，７主动退出  0:没有操作
		*  #msgType=4  1: 忽略，２：同意，３：拒绝，４：永久拒绝，５：解散，６：移出，７主动退出
		*/
		int32 opType;
		/**
		* \brief #msgType=1	 * 1:　添加好友，２：关注
		* #msgType=3	 * 1: 邀请, 2: 申请加入
		*/
		int32 subType;									///< 请求子类型 subType.
		std::string name;								///< 用户名 name.
		std::string groupName;							///< 群名称 groupName.
		std::string portraitUrl;						///< 头像   portraitUrl
		std::string addInfo;							///< 附加消息 addInfo
	};
    /**
     * \struct st_sendFilesExt 消息号: logic_cmd_sendFilesExt
     * \brief  发送文件。单个文件接收进度消息使用logic_cmd_progress消息返回
     */
    typedef bool (parseJsonCallback_t)(int32 type, std::vector<std::string> jsons,
            std::string &body, std::string &prop);

    struct st_sendFilesExt
    {
        int64 targetID;					///< 目标ID,有可能是群或者人 targetID.
        /**
         * \brief 加密KEY，为空不进行加密
         */
        std::string encryptKey;			///< 加密KEY encryptKey.
        std::string message;            ///< 附加信息由上层定义和使用
        std::vector<st_sendFile> _vt;	///< 发送文件数组 _vt.
        int8      isP2p ;               ///< 是否点对点 0 否， 1 是

        /*
         * \brief 解析上传附件返回的json
         * type:  附件类型
         * jsons: 上传附件返回的json vector
         * body:  解析完成后对应的消息body
         * prop:  解析完成后对应的消息属性
         * return: true for success, false for fail
         */
        parseJsonCallback_t *parseJsonCB;

        st_sendFilesExt() {
            init();
        }

        void  init() {
			targetID = 0;
			isP2p = 0;
            _vt.clear();
            isP2p = 0 ;
            parseJsonCB = NULL;
        }
    };

	///p2p对象
	struct p2pUser{
		p2pUser() :userid(0), flag(0){}
		int64 userid; ///<用户ID
		int8  flag; ///<PC 0x01，移动 0x02
	};
	///局域网设备用户列表
	struct p2pUsers {
		p2pUsers() :code(0) {}
		int32 code;
		std::vector<p2pUser> _vt; ///< 用户列表
	};

	struct tfFileInfo {
		tfFileInfo() {
			fileType = 1;
			size = 0;
			finished = 0;
		}

		char   fileType; /* 1:文件, 2:文件夹 */
		int64  size;    /* 当前文件大小, http上传时是总分片数 */
		int64  finished; /* 完成量, http上传时是已上传的分片数 */
		std::string   remotePath; /* 远端路径 */
		std::string   localPath;  /* 本地路径 */
	};
		///保存的上传通讯录字段
	struct st_localPostContact
	{
		st_localPostContact() :userId(0), flag(0)
		{
		}
		std::string phone;			//手机号
		int64 userId;				//用户ID
		int8 flag;					//标示
		std::string phoneName ;     ///手机通讯录里面的名称
		std::string userName ;      ///用户名称
		std::string userHead ;      ///用户头像
	};

	struct st_updateInfo
	{
		/*该字段决定预登陆是否该缓存升级服务器的安装包;
		 0，代表不缓存，返回给客户端运维服务器的安装包下载地址;
		 1，代表预登陆缓存到本地，返回给客户端本地服务器的安装包下载地址
		*/
		std::string nocache; 
		std::string url;///<升级服务器安装包下载地址
		std::string descr;///<安装包描述信息
		std::string fileSize;    ///<安装包大小
		std::string signCode;///<安装包签名
		std::string htmlDowmload;///<是否 当前下载包给web端
		std::string ext;///<透传信息
	};
	/*
	* 打洞服务器信息
	*/
	struct st_stunServerInfo
	{
		st_stunServerInfo() :isSet(false){}
		bool isSet;
		std::string stunAddr;
		std::string stunPort;
		std::string turnAddr;
		std::string turnPort;
		std::string account;
		std::string password;
	};

	///全文检索的消息结构
	struct st_FTSBean
	{
		st_FTSBean() :senderID(0), msgID(0), time(0)
		{}
		int64 senderID;		///< 发送者ID
		int64 msgID;		///< 消息ID
		int64 time;			///< 发送时间
		std::string body;	///< 纯消息内容(非json)
	};

	///用户账户
	struct st_userContact
	{
		st_userContact() :type(0), status(0)
		{}
		int8 type;			///< 账号类型 1.电话号码 3.email 4.userID 6.accountName
		std::string name;	///< 帐号名称
		int8 status;		///< 状态 1.启用， 2.禁用, 5.锁定, 6.冻结 
	};
	
	///邀请码参数
	struct st_inviteCodeParam
	{
		st_inviteCodeParam() :createUserID(0), digit(0), effectiveSeconds(0), effectiveCount(0),value_byte(0){}
		
		int64 createUserID;			///< 生成邀请码的用户的userid
		int32 digit;				///< 生成邀请的位数
		int64 effectiveSeconds;		///< 有效秒数（默认一个月） 
		int32 effectiveCount;		///< 有效次数（默认无数次）
		std::vector<st_userContact> consumeAccount; ///< 不传时默认任何账号都能使用
		int8 value_byte;				///<二维码分享加好友开关//  [10/27/2020 admin]
		std::string extData;			///<好社工邀请码参数
		std::string groupName;         ///< 群名称
	};
	///设置邀请码
	struct st_inviteSetParam
	{
		st_inviteSetParam() :inviteCode(), setupUserID(0), operationType(0), effertiveTime(0), inviteCount(0), buddySwitch(0), deviceType(0) {}

		std::string inviteCode;           /** 邀请码 */
		int64 setupUserID;                /** 用户id（生成该邀请码的人） */
		int8 operationType;               /** 操作类型（1-修改邀请码；2-设置邀请码失效）*/
		int64 effertiveTime;              /** 邀请码有效期（秒，永久传-1）*/
		int32 inviteCount;                /** 邀请人数*/
		int8 buddySwitch;                 /** 是否自动添加好友*/
		int8 deviceType;                  //设备类型 1：PC；2：手机；3：pad；4：网页
	};

	///获取邀请码分享列表入参
	struct st_inviteCodeShareParam
	{
		st_inviteCodeShareParam() :setupUserID(0), groupID(0) {}
		int64 setupUserID;        // 用户id（生成该邀请码的人）
		int64 groupID;            // 用户所查询的群id
	};
	//用户邀请码分享列表
	struct st_shareList
	{
		st_shareList() : inviteCode(), setupUserID(0), shareTime(0), effectiveTime(0), invalidTime(0), inviteCount(0), buddySwitch(0), registerCount(0), buddyCount(0), addGroupCount(0), inviteCodeStatus(0), groupName(), inviteCodePic(){}
		std::string inviteCode;
		int64 setupUserID;
		int64 shareTime;
		int64 effectiveTime;
		int64 invalidTime;
		int32 inviteCount;
		int8 buddySwitch;
		int32 registerCount;
		int32 buddyCount;
		int32 addGroupCount;
		int8 inviteCodeStatus;
		std::string groupName;
		std::string inviteCodePic;
	};

    struct st_appNodeInfo
    {
        std::string nodeID;       ///< 节点ID（唯一）
        std::string nodeName;     ///< 节点名
        std::string productType;  ///< 企业类型
    };

    //工作台轮播图实体
    struct st_workBenchBanner{
		st_workBenchBanner() :type(0), displayStatus(0), sortNum(0), createTime(0), updateTime(0) {}
        std::string id;            ///< 轮播图Id，主键 
        std::string title;         ///< 标题 
        std::string cover;         ///< 封面  只支持jpg、png
        int32 type;                ///< 类型  1：外链，2:非外链 
        std::string displayType;   ///< 展示设备类型  1：安卓，2：ios
        int32 displayStatus;       ///< 显示状态  1：显示，2：隐藏 
		std::string linkUrl;	   ///< 外链地址 
        std::string detailUrl;     ///< 地址（外链-完整路径；非外-存轮播图详情页的相对地址） 
        std::string content;       ///< 富文本内容 
        int32 sortNum;             ///< 排序 
        int64 createTime;          ///< 创建时间 
        int64 updateTime;          ///< 更新时间 
    };

    //帮助系统信息
    struct st_helpSystemInfo{
		st_helpSystemInfo() :id(0), parentId(0), helpType(0), linkType(0), displayStatus(0), sortNum(0),
			createTime(0), updateTime(0), status(0) {}
        int64 id;               ///< 帮助ID 
        std::string title;      ///< 标题 
        int64 parentId;         ///< 父ID 
        int32 helpType;         ///< 帮助类型 
        int32 linkType;         ///< 外链类型 
        int32 displayStatus;    ///< 显示状态 
        std::string linkUrl;    ///< 外链地址 
        std::string detailUrl;  ///< 细节地址 
        std::string content;    ///< 富文本内容  
        int32 sortNum;          ///< 排序 
        int64 createTime;       ///< 创建时间 
        int64 updateTime;       ///< 更新时间 
        int32 status;           ///< 状态 
    };
	
	//动态菜单实体
	struct st_ClientMenu {

		st_ClientMenu() :id(0), type(0), isShow(0), isDefaultPage(0), isOriginIcon(0), sortId(0){}
		/**id**/
		int32 id;
		/**客户端菜单类型 1.内置不可关闭菜单;2.内置可关闭菜单;3.用户自定义菜单**/
		int8 type;
		/**客户端菜单code 唯一**/
		std::string code;
		/**客户端菜单name JSON格式字符串 {"zh":"zhname","en":"enname"}**/
		std::string name;
		/**客户端菜单是否开启 1.是;2.否**/
		int8 isShow;
		/**客户端默认展示页 1.是;2.否**/
		int8 isDefaultPage;
		/**是否是原生内置图标**/
		int8 isOriginIcon;
		/**客户端默认展示图标**/
		std::string defaultIcon;
		/**客户端选中展示图标**/
		std::string clickIcon;
		/**客户端菜单拓展字段**/
		std::string extend;
		/**客户端菜单排序字段**/
		int32 sortId;
	};

	//公众号免打扰配置实体
	struct st_UserToAppConfig{
		st_UserToAppConfig() :appId(0), timestamp(0), type(1), value(1){}
		int64 appId;  //公共号id
		int64 timestamp;  //时间戳
		int8 type;  //配置类型1消息提醒（勿扰模式）
		int32 value;  //type=1时 1:为接收提醒 2:表示不提醒仅显示数字 3:为免打扰 
	};

	//隐私中搜索信息
	struct st_PersionSearchSetting
	{
		st_PersionSearchSetting()
		{
			nSwitchValue = 0;
			szDicKey = "";
			szDicVal = "";
			szSearchKey = "";
		}

		int nSwitchValue;
		std::string szDicKey;
		std::string szDicVal;
		std::string szSearchKey;
	};

	// 用户绑定的后台管理员角色信息 [2/25/2021 zhuohc]
	struct st_AdminRoleInfo{
		st_AdminRoleInfo() {}
		std::string adminUserId;			//	管理后台绑定人员ID
		std::string adminUserName;		//	管理后台绑定人员名称
		std::string adminAccount;		//	管理后台绑定人员帐号
		std::string adminRoleName;		//	管理后台绑定人员角色名称
		std::string adminRoleId;			//	管理后台绑定人员角色ID
	};

	//消息未读数实体
	struct st_msgUnreadCounter
	{
		st_msgUnreadCounter() :messageID(0), unreadCount(0), maxUnreadCount(0), snapshotID(0) {}
		int64 messageID;		//消息id
		int32 unreadCount;		//消息未读数
		int32 maxUnreadCount;	//最大未读数
		int64 snapshotID;		//群快照
	};

	struct st_groupTopMsgParam
	{
		st_groupTopMsgParam(): targetId(0), relateMsgId(0){}
		int64 targetId;
		int64 relateMsgId;
	};
	struct st_getGroupTopMsgByPage
	{
	st_getGroupTopMsgByPage():targetId(0), msgId(0), count(0), flag(0) {}
		int64 targetId;
		int64 msgId;
		int count;
		int flag;
	};


	struct st_AccountType{
		st_AccountType() :type(0) {}
		bool operator == (const st_AccountType & rhs) const
		{
			return (type == rhs.type) && (accounts == rhs.accounts) && (mark == rhs.mark);

		}
		int8 type;                  // 账号类型 1：电话, 3：邮箱, 4：userID, 5:身份证, 6：豆豆号, 7:自定义帐号(不做限制)
		std::string accounts;       // 账号
		std::string mark;           // 标识
	};
	typedef std::map<int32, int32> map_int32_int32;
	struct st_TinyUserBean {
		st_TinyUserBean()
		{
			INIT_ISSET(name)
			INIT_ISSET(sex)
			INIT_ISSET(status)
			INIT_ISSET(portraitURL)
			INIT_ISSET( remark)
			INIT_ISSET(groupID)
			INIT_ISSET( sign)
			INIT_ISSET(page)
			INIT_ISSET( tinyUserType)
			INIT_ISSET( starBuddy)
			INIT_ISSET(tagIds)
			INIT_ISSET(timeZone)
			INIT_ISSET( phoneNums)
			INIT_ISSET( emails)
			INIT_ISSET( oriPortraitURL)
			INIT_ISSET( backgroundURL)
			INIT_ISSET( accountName)
			INIT_ISSET( area)
			INIT_ISSET(birthday)
			INIT_ISSET( lockDeadline)
			INIT_ISSET( remainLockDuration)
			INIT_ISSET( SDKID)
			INIT_ISSET(accounts)
			INIT_ISSET(userTypeNum)
			INIT_ISSET( buddySetting);
		}
		void init()
		{
			INIT_ISSET(tagIds)
			phoneNums.clear();
			emails.clear();
			accounts.clear();
			buddySetting.clear();
		}
		/*好友的用户ID*/
		int64 userID;
		/*好友的用户名*/
		IS_SET(std::string, name)
		/*好友的性别：2：女，1：男, 0: 未知*/
		IS_SET(int32, sex)
		/*账号状态：用户状态 1：正常 2：停用 3: 注册邀请4: 影子用户，5:锁定，6:冻结*/
		IS_SET(int8, status)
		/*好友头像url*/
		IS_SET(std::string, portraitURL)
		/*好友的备注名*/
		IS_SET(std::string, remark)
		/*所在的组ID*/
		IS_SET(int64, groupID)
		/*个性签名*/
		IS_SET(std::string, sign)
		/*服务器分页, 从1开始*/
		IS_SET(int16, page)
		/*好友类型：1：好友，2：关注 3: 被关注(粉丝) 4: 陌生人*/
		IS_SET(int8, tinyUserType)
		/*特别好友/星标好友 1: 星标*/
		IS_SET(int8, starBuddy)
		/*时区**/
		IS_SET(int8, timeZone)
		IS_SET(std::vector<std::string>, phoneNums)  /*电话号码清单*/
		IS_SET(std::vector<std::string>, emails) /*邮箱清单 */
		IS_SET(std::string, oriPortraitURL) /*原始好友头像url*/
		IS_SET(std::string, backgroundURL) /*聊天背景地址*/
		IS_SET(std::string, accountName)/*账号名称*/
		IS_SET(std::string, area)/*区域 */
		IS_SET(YMD, birthday) /*生日*/
		IS_SET(int64, lockDeadline)/*锁定截止时间，毫秒*/
		IS_SET(int64, remainLockDuration)/*剩余锁定时长，毫秒*/
		IS_SET(int64, SDKID)
		IS_SET(std::vector<st_AccountType>, accounts); /*联系方式集合 */
		/*好友类型标识:1:人 2:公众号*/
		IS_SET(int16, userTypeNum);
		IS_SET(map_int32_int32, buddySetting);
		/* 用户标签id,多个用逗号分隔 */
		IS_SET(std::string, tagIds)
	};

	struct st_DetailContent{
		st_DetailContent()
		{
			INIT_ISSET(content)
			INIT_ISSET(imgurls)
			INIT_ISSET(transferUserID)
			INIT_ISSET(transferUser)
			INIT_ISSET(resource)
		}
		void init()
		{
			imgurls.clear();

		}
		IS_SET(std::string, content); // 内容
		IS_SET(std::vector<std::string>, imgurls); //图片地址
		IS_SET(int64, transferUserID);
		IS_SET(st_TinyUserBean, transferUser);
		IS_SET(std::string, resource);//资源对象
	};

	struct st_ShareMessage{
		st_ShareMessage()
		{
			INIT_ISSET(messageID)
				INIT_ISSET(userID)
				INIT_ISSET(fromUserID)
				INIT_ISSET(shareID)
				INIT_ISSET(content)
				INIT_ISSET(type)
				INIT_ISSET(time)
				INIT_ISSET(isRead)
		}
		IS_SET(std::string, messageID);
		IS_SET(int64, userID);  // 评论人ID
		IS_SET(int64, fromUserID); // 回复用户ID
		IS_SET(std::string, shareID); //分享的ID
		IS_SET(std::string, content);  //评论内容
		IS_SET(std::string, type);  //1 评论 2点赞
		IS_SET(int64, time);
		IS_SET(int32, isRead); //是否已读
	};

	struct st_Share{
		st_Share()
		{
			INIT_ISSET(userID)
			INIT_ISSET(shareID)
			INIT_ISSET(referencedShareID)
			INIT_ISSET(originalShareID)
			INIT_ISSET(content)
			INIT_ISSET(longitude)
			INIT_ISSET(latitude)
			INIT_ISSET(time)
			INIT_ISSET(address)
			INIT_ISSET(scope)
			INIT_ISSET(type)
			INIT_ISSET(showType)
			INIT_ISSET(detailContent)
			INIT_ISSET(shareUser)
			INIT_ISSET(relatedUserIds)
			INIT_ISSET(relatedUsers)
		}
		void init()
		{
			relatedUserIds.clear();
			relatedUsers.clear();
		}
		IS_SET(int64,  userID); //用户ID
		IS_SET(std::string, shareID); //分享的ID
		IS_SET(std::string, referencedShareID); // 转发shareID
		IS_SET(std::string, originalShareID); //转发时源shareID
		IS_SET(std::string, content);  //书写的内容
		IS_SET(double, longitude); //经度
		IS_SET(double, latitude); //纬度
		IS_SET(int64, time);  //时间
		IS_SET(std::string, address);  //地址
		IS_SET(std::string, scope);  // public enable private
		IS_SET(std::string, type);  //1，原创；2，转发
		IS_SET(int32, showType); //1，公司可见；2，好友可见；3，全部可见
		/*如果是原创 存放原创的图片  如果是转发 存放转发的内容。 添加时原创要将图片地址放进去  转发不需要*/
		IS_SET(st_DetailContent, detailContent);
		IS_SET(st_TinyUserBean, shareUser);//分享用户
		IS_SET(std::vector<int64>, relatedUserIds);
		IS_SET(std::vector<st_TinyUserBean>, relatedUsers);
	};

	struct st_SharePage{
		void init()
		{
			totalCount = 0;
			totalPage = 0;
			lastShareID = 0;
			shares.clear();
		}
		/* 分享列表 */
		std::vector<st_Share> shares;
		/* 总个数*/
		int64 totalCount;
		/* 总页数 */
		int64 totalPage;
		int64 lastShareID;
	};

	struct st_CommentCenterBean{
		st_CommentCenterBean()
		{
			INIT_ISSET(commentUserID);
			INIT_ISSET(replyCommentID);
			INIT_ISSET(content);
			INIT_ISSET(createTime);
			INIT_ISSET(subjectID);
			INIT_ISSET(commentID);
			INIT_ISSET(subjectType);
			INIT_ISSET(relatedUserIDs);
			INIT_ISSET(replyUserID);
			INIT_ISSET(relatedUsers);
			INIT_ISSET(replyUser);
			INIT_ISSET(commentUser);
		}
		void init()
		{
			relatedUserIDs.clear();
			relatedUsers.clear();
		}
		/*评论用户*/
		IS_SET(int64, commentUserID);
		/*回复评论ID*/
		IS_SET(int64, replyCommentID);
		/* 评论内容 */
		IS_SET(std::string, content);
		/* 创建时间 */
		IS_SET(int64, createTime);
		/* 主题ID */
		IS_SET(int64, subjectID);
		/* 评论ID */
		IS_SET(int64, commentID);
		/* 主题类型 */
		IS_SET(int32, subjectType);
		/*@用户列表*/
		IS_SET(std::vector<int64>, relatedUserIDs);
		/*回复用户ID*/
		IS_SET(int64, replyUserID);
		/*@用户名称列表*/
		IS_SET(std::vector<st_TinyUserBean>, relatedUsers);
		/*回复用户*/
		IS_SET(st_TinyUserBean, replyUser);
		/*评论用户*/
		IS_SET(st_TinyUserBean, commentUser);
	};

	struct st_CommentPage{
		st_CommentPage()
		{
			INIT_ISSET(commentLst);
			INIT_ISSET(pageSize);
			INIT_ISSET(totalCount);
			INIT_ISSET(lastCommentID);
		}
		void init()
		{
			commentLst.clear();
		}
		/*评论集合*/
		IS_SET(std::vector<st_CommentCenterBean>, commentLst);
		/*页长*/
		IS_SET(int32,  pageSize);
		/*总数*/
		IS_SET(int32,  totalCount);

		IS_SET(int64,  lastCommentID);
	};

	struct st_PraiseStatisticBean{
		st_PraiseStatisticBean()
		{
			INIT_ISSET(praiseCount);
			INIT_ISSET(treadCount);
			INIT_ISSET(subjectID);
			INIT_ISSET(subjectType);
		}
		/*点赞数量*/
		IS_SET(int32,  praiseCount);
		/*踩数量*/
		IS_SET(int32,  treadCount);
		/*主题ID*/
		IS_SET(int64,  subjectID);
		/*主题类型*/
		IS_SET(int32,  subjectType);
	};

	struct st_PraiseBean{
		st_PraiseBean()
		{
			INIT_ISSET(userID);
			INIT_ISSET(type);
			INIT_ISSET(createTime);
			INIT_ISSET(subjectID);
			INIT_ISSET(praiseID);
			INIT_ISSET(subjectType);
			INIT_ISSET(replyUserID);
			INIT_ISSET(user);
		}
		/* 用户编码 */
		IS_SET(int64,  userID);
		/*类型 1.点赞 2.踩*/
		IS_SET(int32,  type);
		/* 创建时间 */
		IS_SET(int64,  createTime);
		/* 主题ID */
		IS_SET(int64,  subjectID);
		/*点赞ID*/
		IS_SET(int64,  praiseID);
		/* 主题类型 */
		IS_SET(int32,  subjectType);
		/*点赞用户*/
		IS_SET(int64,  replyUserID);
		/*用户*/
		IS_SET(st_TinyUserBean, user);
	};


	struct st_ShareParam{
		st_ShareParam() : userID(0), showType(0), pageSize(0), lastShareID(0), shareUserID(0), pageNum(0)
		{
			INIT_ISSET(userID);
			INIT_ISSET(showType)
			INIT_ISSET(pageSize)
			INIT_ISSET(lastShareID)
			INIT_ISSET(shareUserID)
			INIT_ISSET(pageNum)
		}
		IS_SET(int64, userID);
		IS_SET(int32, showType);  //1，公司可见；2，好友可见；3，全部可见,
		IS_SET(int32, pageSize); //页大小
		IS_SET(int64, lastShareID);
		IS_SET(int64, shareUserID);//分享好友ID 不传默认查找用户所有好友的分享
		IS_SET(int32, pageNum);
	};

	struct st_CommentParam{
		st_CommentParam() : pageSize(0), pageNum(0), subjectType(0), lastCommentID(0)
		{
			INIT_ISSET(pageSize);
			INIT_ISSET(pageNum);
			INIT_ISSET(subjectType);
			INIT_ISSET(lastCommentID);
		}
		IS_SET(int32, pageSize);
		IS_SET(int32, pageNum);
		IS_SET(int32, subjectType);
		IS_SET(int64, lastCommentID);
	};



	struct st_SCContentInner {
		void init()
		{
			praiseList.clear();
		}
		st_Share share;
		st_CommentPage commentPage;
		st_PraiseStatisticBean praiseCountBean;
		std::vector<st_PraiseBean> praiseList;
	};

	struct st_SCContentJson {
		st_SCContentInner content;
	};

	struct st_SCShareListJson {
		void init()
		{
			count = 0;
			content.clear();
		}
		int64 count;
		std::vector<st_SCContentInner> content;

	};


	struct st_CommentCenterResultBean{
		st_CommentCenterResultBean()
		{
			resultCode = 0;
			INIT_ISSET(resultMessage);
			INIT_ISSET(commentID);
		}
		/* 结果编码 */
		int32 resultCode;
		/* 结果信息 */
		IS_SET(std::string, resultMessage)
		/*评论id*/
		IS_SET(int64, commentID)

	};

	struct st_CommentStatisticBean{
		st_CommentStatisticBean()
		{
			INIT_ISSET(subjectID)
				INIT_ISSET(subjectType)
				INIT_ISSET(type)
				INIT_ISSET(collectNum)
		}
		/*主题ID*/
		IS_SET(int64, subjectID);
		/*主题类型*/
		IS_SET(int32, subjectType);
		/*类型*/
		IS_SET(int32, type);
		/*数量*/
		IS_SET(int32, collectNum);
	};
	struct st_HaveShareRsultBean{
		st_HaveShareRsultBean()
		{
			INIT_ISSET(ishave);
			INIT_ISSET(lastShareID);
			INIT_ISSET(userID);
			INIT_ISSET(portraitURL);
		}
		IS_SET(bool, ishave)
		IS_SET(int64,  lastShareID)
		IS_SET(int64,  userID)
		IS_SET(std::string, portraitURL)
	};

	struct st_ShareImg{
		st_ShareImg()
		{
			INIT_ISSET(userID)
			INIT_ISSET(shareID)
			INIT_ISSET(createTime)
			INIT_ISSET(imgUrl)
			INIT_ISSET(scope)
			INIT_ISSET(fileType)
	    }
		/*用户ID*/
		IS_SET(int64, userID)
		/*分享ID*/
		IS_SET(int64, shareID)
		/*创建时间*/
		IS_SET(int64, createTime)
		/*图片路径*/
		IS_SET(std::string, imgUrl)
		/*类型*/
		IS_SET(std::string, scope)
		/*文件类型*/
		IS_SET(int32, fileType)
	};

	struct st_ShareUserParam{
		st_ShareUserParam()
		{
			INIT_ISSET(pageNum)
			INIT_ISSET(pageSize)
			INIT_ISSET(userID)
			INIT_ISSET(isRead)
		}
		IS_SET(int32, pageNum)//页数
			IS_SET(int32, pageSize)//页码
			IS_SET(int64, userID)//用户ID
			IS_SET(int32, isRead)//1已读 2未读
	};

	struct st_ShareUser{
		st_ShareUser()
		{
			INIT_ISSET(userID)
			INIT_ISSET(shareUserID)
			INIT_ISSET(shareID)
			INIT_ISSET(createTime)
		}
		IS_SET(int64, userID);//用户ID
		IS_SET(int64, shareUserID);//分享用户ID
		IS_SET(int64, shareID);//分享ID
		IS_SET(int64, createTime);//@用户时间
	};

	struct st_ShareUserPage{
		st_ShareUserPage()
		{
			INIT_ISSET(count)
			INIT_ISSET(shareUsers)
		}
		void init()
		{
			shareUsers.clear();
		}
		IS_SET(int32, count)//数量
		IS_SET(std::vector<st_ShareUser>, shareUsers)
	};

	struct st_ShareResultBean{
		st_ShareResultBean()
		{
			resultCode = 0;
			INIT_ISSET(resultMessage)
		}
		/* 结果编码 */
		int32 resultCode;
		/* 结果信息 */
		IS_SET(std::string, resultMessage);
	};

	struct st_UserGroup{
		st_UserGroup()
		{
			INIT_ISSET(groupID)
				INIT_ISSET(groupName)
				INIT_ISSET(userID)
				INIT_ISSET(time)
				INIT_ISSET(type)
				INIT_ISSET(groupMembers)
				INIT_ISSET(userCount)
				INIT_ISSET(userName)
				INIT_ISSET(groupUsers)

		}
		void init()
		{
			groupMembers.clear();
			groupUsers.clear();
		}
		IS_SET(int64, groupID) //组ID
		IS_SET(std::string, groupName); //组名
		IS_SET(int64, userID);  //创建组的用户ID
		IS_SET(int64, time);
		IS_SET(std::string, type); // 1可见 2不可见
		IS_SET(std::vector<int64>, groupMembers);  //成员id
		IS_SET(int32, userCount);  // 用户个数
		IS_SET(std::string, userName);
		IS_SET(std::vector<st_TinyUserBean>, groupUsers);
	};

	struct st_SCGetComments {
		void init()
		{
			comments.clear();
			pariseCounts.clear();
		}
		std::map<std::string, st_CommentPage> comments;
		std::map<std::string, st_PraiseStatisticBean> pariseCounts;
	};


	struct st_CommentRecord{
		st_CommentRecord()
		{
			INIT_ISSET(subjectID)
				INIT_ISSET(subjectType)
				INIT_ISSET(commentID)
				INIT_ISSET(operateUserID)
				INIT_ISSET(relatedUserID)
				INIT_ISSET(createTime)
				INIT_ISSET(type)
				INIT_ISSET(isRead)
				INIT_ISSET(id)
				INIT_ISSET(operateUser)
				INIT_ISSET(relatedUser)
		}
		/* 主题ID */
		IS_SET(int64, subjectID);
		/* 主题类型 */
		IS_SET(int32, subjectType);
		/* 评论ID */
		IS_SET(int64, commentID);
		/* 操作人id */
		IS_SET(int64, operateUserID);
		/* @的用户id */
		IS_SET(int64, relatedUserID);
		/*创建时间*/
		IS_SET(int64, createTime);
		/*类型 1.普通评论 2.点赞 3.踩 4.@用户*/
		IS_SET(int32, type);
		/*是否已读*/
		IS_SET(int32, isRead);
		/*id*/
		IS_SET(int64, id);
		/* 操作人*/
		IS_SET(st_TinyUserBean, operateUser);
		/* @的用户*/
		IS_SET(st_TinyUserBean, relatedUser);
	};

	struct st_UserPraiseParam{
		st_UserPraiseParam()
		{
			INIT_ISSET(userID)
				INIT_ISSET(subjectID)
				INIT_ISSET(subjectType)
		}
		IS_SET(int64, userID);
		/* 主题ID */
		IS_SET(int64, subjectID);
		/* 主题类型 */
		IS_SET(int32, subjectType);
	};

	struct st_CommentStatisticParam{
		st_CommentStatisticParam()
		{
			INIT_ISSET(subjectID)
				INIT_ISSET(subjectType)
				INIT_ISSET(type)
		}
		/*主题ID*/
		IS_SET(int64, subjectID);
		/*主题类型*/
		IS_SET(int32, subjectType);
		/*类型*/
		IS_SET(int32, type);
	};
	struct st_CommentRecordParam{
		st_CommentRecordParam()
		{
			INIT_ISSET(userID)
				INIT_ISSET(subjectType)
				INIT_ISSET(pageNum)
				INIT_ISSET(pageSize)
				INIT_ISSET(isRead)
		}
		/*我的帐号ID*/
		IS_SET(int64, userID);
		/*主题类型*/
		IS_SET(int32, subjectType);
		/* 页码 */
		IS_SET(int32, pageNum);
		/* 页长 */
		IS_SET(int32, pageSize);
		/*是否已读*/
		IS_SET(int32, isRead);
	};

	struct st_CommentRecordPage{
		st_CommentRecordPage()
		{
			INIT_ISSET(recordLst)
				INIT_ISSET(pageSize)
				INIT_ISSET(totalCount)
		}
		void init()
		{
			recordLst.clear();
		}
		/*@我的帐号ID*/
		IS_SET(std::vector<st_CommentRecord>, recordLst);
		/*页长*/
		IS_SET(int16, pageSize);
		/*总数*/
		IS_SET(int32, totalCount);
	};

	struct st_PraiseParam{
		st_PraiseParam()
		{
			INIT_ISSET(pageNum)
				INIT_ISSET(pageSize)
				INIT_ISSET(type)
				INIT_ISSET(subjectID)
				INIT_ISSET(subjectType)
		}
		/* 页码 */
		IS_SET(int32, pageNum);
		/* 页长 */
		IS_SET(int32, pageSize)
		/*类型 1:赞 2:踩 */
		IS_SET(int32, type)
		/*主题ID*/
		IS_SET(int64, subjectID);
		/*主题类型*/
		IS_SET(int32, subjectType);
	};

	struct st_CommentCenterParam{
		st_CommentCenterParam()
		{
			INIT_ISSET(pageNum)
				INIT_ISSET(pageSize)
				INIT_ISSET(subjectID)
				INIT_ISSET(subjectType)
				INIT_ISSET(orderType)
				INIT_ISSET(lastCommentID)
				INIT_ISSET(type)
		}
		/* 页码 */
		IS_SET(int32, pageNum);
		/* 页长 */
		IS_SET(int32, pageSize);
		/*主题ID*/
		IS_SET(int64, subjectID);
		/*主题类型*/
		IS_SET(int32, subjectType);
		/*排序 1:DESC 2:ASC*/
		IS_SET(int32, orderType);

		IS_SET(int64, lastCommentID);

		IS_SET(int32, type);
	};

	struct st_SCRespJson {
		std::string function;
		std::string shareID;
		std::string operType;
		std::string count;
	};

	struct st_ShareBackgroundImg {
		st_ShareBackgroundImg() :userID(0) {}
		int64 userID;
		std::string backgroundUrl;
	};
	struct st_AlbumCoverResultBean {
		st_AlbumCoverResultBean() :setBackgroundUrl(false), setUserID(false), userID(0) {}
		std::string backgroundUrl;
		bool setBackgroundUrl;
		bool setUserID;
		int64 userID;
	};
	struct st_AppRoomInfo
	{
		st_AppRoomInfo():id(0),type(0),order(0),extend(0){
			INIT_ISSET(id)
				INIT_ISSET(type)
				INIT_ISSET(order)
				INIT_ISSET(extend)
				INIT_ISSET(name)
				INIT_ISSET(apps)
				INIT_ISSET(icon);
		}
		/* 房间id或应用id */
		IS_SET(int64, id);
		/* 1、房间 2、应用 3、本地应用*/
		IS_SET(int8, type);
		/* 排序位置 */
		IS_SET(int32, order);
		/* 扩展字段，暂时没用 */
		IS_SET(int32, extend);
		/* 房间或应用名称 */
		IS_SET(std::string, name);
		/* 图标 */
		IS_SET(std::string, icon);

		IS_SET(std::vector<int64>, apps);
	};
	struct st_MarketAppGroup
	{
		st_MarketAppGroup() :id(0), type(0){}

		int64 id;  //房间id或应用id
		int8 type; // 1、房间 2、应用 3、本地应用
		std::string name;  //房间名称或应用名称
		std::string icon;
		std::vector<st_smallMarketAppInfo> apps;
	};
	struct st_GroupIssue
	{
		st_GroupIssue() :id(0), groupId(0), createrId(0), createTime(0) {}

		int64 id;		//议题id
		int64 groupId;	//群Id
		int64 createrId;//创建者Id
		int64 createTime;//创建时间
		std::string name;//议题名称 
		int8 operType;	//操作类型 1.回复 2.创建 3.删除 
	};
	struct st_GroupJssdkAuth
	{
		st_GroupJssdkAuth() :appID(0), timeStamp(0) {}

		int64 appID;				//
		int64 timeStamp;		//时间戳
		std::string noncestr;	//随机字符串
		std::string url;			//
		std::string signature;	//签名
		std::vector<std::string> jsApiList;//
		int64 valiTime;
	};
	struct st_GroupAgencyListFinishCnt
	{
		st_GroupAgencyListFinishCnt() :userID(0), nCntDone(0), nCntUndone(0) {}

		int64 userID;				//
		int64 nCntDone;			//已完成
		int64 nCntUndone;		//未完成
	};
	/**
	* \brief 自定义菜单栏目信息
	*/
	struct st_GroupAppListMenuResult
	{
		st_GroupAppListMenuResult() :appID(0), appType(0){}
		int64 appID;
		int8 appType;						//1 H5, 2 苹果, 3 安卓, 4 内部, 5 快捷, 5 本地
		std::string appTypeName;	//应用类型中文名
		std::string appSign;			//应用标识
		std::string appName;			//应用名称
		std::string appIcon;			//应用图标
		std::string mainUrl;			//	应用地址
		std::string adminUrl;			//	应用后台地址
		std::string packageName;	//	应用包名
		std::string downloadUrl;	//	应用下载地址
		std::string urlScheme;		//	应用urlScheme
	};
	///自定义菜单栏目信息
	struct st_AppListMenuInfo{
		st_AppListMenuInfo() :resultCode(0){
			menuInfos.clear();
		}
		int8 resultCode;		//0成功 - 1失败

		std::vector<st_GroupAppListMenuResult> menuInfos;	 //resultData:Array

	};
	struct st_GroupAnnouncement
	{
		st_GroupAnnouncement() :announcementID(0), groupID(0), createUserID(0), createDt(0) {}

		int64 announcementID;  //公告id
		int64 groupID;        //群id
		int64 createUserID;  //创建者id
		int64 createDt;   //创建时间
		std::string content;  //公告内容
	};
	struct st_LocalAppInfo
	{
		st_LocalAppInfo() :appId(0), order(0), extend(0){
		}
		int64 appId;
		std::string name;
		std::string icon;
		std::string url;
		int32 order;   //位置字段，暂时没有用
		int32 extend;  //扩展字段，暂时没有用
	};

	struct delFileinfo
	{
		delFileinfo() :fileid(0) {}
		int64 fileid;                 ///<文件ID
		std::string thumbPath;		  ///<缩略图本地路径
		std::string thumbUrl;		  ///<缩略图地址
	};

	struct st_NoDisturbModeInfo
	{
		st_NoDisturbModeInfo() :startTime(0), endTime(0), isOpen(false){
		}
		int32 startTime;   //开始时间
		int32 endTime;  //结束时间
		bool isOpen;
		std::string name;
	};
	struct st_LoginRecord
	{
		st_LoginRecord() :userID(0), loginTime(0), deviceType(0),SDKID(0){
		}
		int64 userID;  // 用户ID
		int64 loginTime;  //登录时间 
		int8 deviceType;  //设备类型 
		std::string deviceInfo; //设备信息 
		std::string macCode;  //mac地址 
		std::string loginIP;  // 登录IP 
		std::string loginCity;  //登录地址 
		int64 SDKID;
	};
	struct st_getSecurity
	{
		st_getSecurity() :userID(0), level(0), operateTime(0), operateUserId(0){}
		int64 userID;  // 用户ID
		int32 level;  //等级
		int64 operateTime;  //操作时间
		int64 operateUserId; //操作人用户ID
		std::string name;  //密级名称
		std::string color;  //密级颜色
	};
	//本地搜索群成员信息
	struct st_localSearchMemberInfo
	{
		st_localSearchMemberInfo() :groupID(0), groupMemberNum(0), matchFlag(0), userID(0), lastTime(0){}
		int64 groupID;				//所在群ID
		int groupMemberNum;			//所在群人数
		int matchFlag;				//匹配类型 1.通过用户名匹配到 2.通过备注匹配到
		int64 userID;               //匹配到的用户ID
		std::string name;			//匹配到的用户名
		std::string remark;         //匹配到的用户备注
		int32 securityLevel;        //工作密级
		int64 lastTime;			    //所在群最新消息时间
	};

	//创建消息提醒
	struct st_reminderMsg
	{
		st_reminderMsg()
		{
			init();
		}
		void init()
		{
			reminderId = 0;
			receiverUserId = 0;
			reminderSendTime = 0;
			reminderMsgId = 0;
			sourceId = 0;
			msg.init();
		}
		int64 reminderId;                                ///消息提醒id，发送时不赋值
		int64 receiverUserId;                            ///接收者用户ID,设置消息提醒的人，a用户设置了消息提醒，时间戳到达时服务器会发送给a用户
		int64 reminderSendTime;                          ///消息提醒发送时间（时间戳）
		int64 reminderMsgId;                             ///需要提醒的消息ID，关联消息id
		int64 sourceId;                                  ///原消息发送者ID（用户或群），原消息所在的会话id，跳转或显示头像使用
		st_msgBean msg;                                  ///原始消息数据
	};
	//消息提醒分页查询
	struct st_reminderMsgPage
	{
		st_reminderMsgPage() 
		{
			init();
		}
		void init()
		{
			totalCount = 0;
			totalPageNo = 0;
			reminderMsgList.clear();
		}
		std::vector<st_reminderMsg> reminderMsgList;   ///查询获取的消息提醒实体列表
		int64 totalCount;                              ///总记录数
		int64 totalPageNo;                             ///总页数
	};

	struct st_cloudTransferInfo
	{
		st_cloudTransferInfo(){
			pid = 0;
			user = 0;
			sdkid = 0;
			sowner = 0;
			ssdkid = 0;
			fileId = 0;
			fileSize = 0;
			splitSize = 0;
			splitFinished = 0;
			transferType = 0;
			transferState = 0;
			fileName = "";
			encryptKey = "";
			uploadPath = "";
			md = "";
			sha = "";
			downLoadPath = "";
		}
		int64 pid;						// 云盘父目录id 如果没有父目录，传0。
		int64 user;					// 用户id
		int64 sdkid;					// sdkid
		int64 sowner;					// 共享目录拥有者 id
		int64 ssdkid;					// 共享目录拥有者 sdkid

		int64 fileId;					// 文件id
		int64 fileSize;				// 文件大小	 
		std::string fileName;			///<文件名，为空时，取localPath的文件名
		std::string encryptKey;		// 加密key 
		std::string uploadPath;		///<本地文件地址
		std::string md;					/// 文件 md5码
		std::string sha;				/// 文件 sha256码
		std::string downLoadPath;		///< 文件本地保存路径 localPath

		int64 splitSize;    			/// http上传时是总分片数
		int64 splitFinished; 			/// 完成量, http上传时是已上传的分片数

		//bool  isResumeUpload;			///<是否支持断点续传
		//bool  isEncrypt;				/// 是否加密
		//bool  bisResumeDownload;		///<是否断点下载

		int32	transferType;			/// transferType = 1, 上传， transferType = 2, 下载
		int32	transferState;			///	transferState = 1, 成功， transferState = 2, 失败，

	};

	// 云盘文件基本信息
	struct st_cloudFileInfo{

		st_cloudFileInfo()
		{
			virtualid = 0;
			pid = 0;
			type = 0;
			dtime = 0;
			mtime = 0;
			atime = 0;
			fsize = 0;
			isdel = 0;
			createtime = 0;
			updatetime = 0;
			deletetime = 0;
			shareCreateAt = 0;
			shareDeleteAt = 0;
			shareUpdateAt = 0;
			groupid = 0;
			ownerid = 0;
			createid = 0;
			isShare = 0;
			permission = 0;
			uploadid = 0;
		}
		int64 virtualid;
		int64 pid;
		std::string fname;		//名字  (可能为空)
		int32 type;				// 1 文件， 2 文件夹
		int64 dtime;			// 被删除时间， -1 彻底删除
		std::string ftype;		// 文件类型
		std::string md5;		// 
		std::string sha2;		//
		std::string skey;
		int64 mtime;
		int64 atime;
		int64 fsize;			// 文件字节大小
		int32 isdel;			// 是否 回收站删除
		int64 createtime;		// 创建时间
		int64 updatetime;		// 修改时间
		int64 deletetime;		// 删除时间
		int64 shareCreateAt;	// 共享组创建时间
		int64 shareUpdateAt;	// 共享组修改时间
		int64 shareDeleteAt;	// 共享组删除时间
		int64 groupid;			// 共享组id
		int64 ownerid;			// 共享提供者id
		int64 createid;			// 共享创建者id
		int32 permission;		// 读写
		int32 isShare;			// 0 未被共享， 1 被共享
		int64 uploadid;			// 上传者 id
	};

	struct st_AgencyBean{

		st_AgencyBean() 
		{
			init();
		}

		void init()
		{
			appId = userId = agencyCount = agencyStatus = updateAtTime = 0;
			appName = "";
			agencyContentZh = "";
			agencyContentEn = "";
			agencyUrl = "";
			agencyExtendInfo = "";
		}
		/**公共号Id**/
		int64 appId;
		/**用户Id**/
		int64 userId;
		/**公共号名称**/
		std::string appName;
		/**待办事项计数**/
		int32 agencyCount;
		/**中文消息模板**/
		std::string agencyContentZh;
		/**英文消息模板**/
		std::string agencyContentEn;
		/**待办事项地址**/
		std::string agencyUrl;
		/**待办事项拓展字段**/
		std::string agencyExtendInfo;
		/**用户对应用的状态**/
		int8 agencyStatus;
		/**更新时间**/
		int64 updateAtTime;
	};
	/* 新待办任务结构体 */
	struct st_agencyMessageBean{
		st_agencyMessageBean() : userID(0), targetID(0), message(), messageType(0), localID(0), maccode(), format(), msgProperties(), activeType(0), relatedMsgID(0), SDKID(0), setRead(0), sourceID(), subMsgType(0), securityLevel(0) {
		}
		int64 userID;
		int64 targetID;
		std::string message;
		int8 messageType;
		int64 localID;
		std::string maccode;
		std::string format;
		std::vector<int64>  limitRange;
		std::string msgProperties;
		int8 activeType;
		std::vector<int64>  relatedUsers;
		int64 relatedMsgID;
		int64 SDKID;
		int8 setRead;
		std::string sourceID;
		int32 subMsgType;
		int32 securityLevel;
	};
	struct st_ToDoTaskMsg {
		st_ToDoTaskMsg() : targetID(0), appID(0), taskID(0), messageID(0), urgent(0), finished(0), createTime(0), updateTime(0) {
		}
		int64 targetID;
		int64 appID;
		int64 taskID;
		int64 messageID;
		st_agencyMessageBean messageBean;
		int8 urgent;
		int8 finished;
		int64 createTime;
		int64 updateTime;
	};

	/**
	*  \struct st_LoginClientRecord
	*  \biref  用户登录的设备信息,豆豆版本
	*/
	struct st_LoginClientRecord {
		st_LoginClientRecord(){
			init();
		}

		void init(){
			userID = loginTime = deviceType = clientType  = 0;
			deviceInfo.clear();
			clientVersion.clear();
			SDKID.clear();
		}
		int64 userID;				//用户ID
		int64 loginTime;			//登录时间
		int8  deviceType;			//登录设备类型
		int8  clientType;			//client类型
		std::string deviceInfo;		//登录设备信息
		std::string clientVersion;	//client版本
		std::string SDKID;			//SDKID
	};

	struct st_smallAppHelp{
		IS_SET(int64, id)
		IS_SET(int64, appId)
		IS_SET(int64, parentId)
		IS_SET(std::string, title)
		IS_SET(int8, helpType)
		IS_SET(int8, articleType)
		IS_SET(std::string, linkUrl)
		IS_SET(std::string, fileUrl)
		IS_SET(std::string, detailUrl)
		IS_SET(int32, sortNum)

		st_smallAppHelp(){
			init();
		}
		void init(){
			INIT_ISSET(id)
			INIT_ISSET(appId)
			INIT_ISSET(parentId)
			INIT_ISSET(title)
			INIT_ISSET(helpType)
			INIT_ISSET(articleType)
			INIT_ISSET(linkUrl)
			INIT_ISSET(fileUrl)
			INIT_ISSET(detailUrl)
			INIT_ISSET(sortNum)
		}


	};

	struct st_personalDataSwitch
	{

		IS_SET(int64, currentUserId)
		IS_SET(int32, switchType)
		IS_SET(std::string, value)
		IS_SET(int64, SDKID)
		IS_SET(std::string, extendValue)

		st_personalDataSwitch(){
			init();
		}

		void init(){
			INIT_ISSET(currentUserId)
			INIT_ISSET(switchType)
			INIT_ISSET(value)
			INIT_ISSET(SDKID)
			INIT_ISSET(extendValue)

		}
	};

	/* 新待办事项结构体BEGIN */
	struct agencyMessageBean{
		agencyMessageBean() : userID(0), targetID(0), message(), messageType(0), localID(0), maccode(), format(), msgProperties(), activeType(0), relatedMsgID(0), SDKID(0), setRead(0), sourceID(), subMsgType(0), securityLevel(0) {
		}
		int64 userID;
		int64 targetID;
		std::string message;
		int8 messageType;
		int64 localID;
		std::string maccode;
		std::string format;
		std::vector<int64>  limitRange;
		std::string msgProperties;
		int8 activeType;
		std::vector<int64>  relatedUsers;
		int64 relatedMsgID;
		int64 SDKID;
		int8 setRead;
		std::string sourceID;
		int32 subMsgType;
		int32 securityLevel;
	};

	struct st_getLocalAgencyListFromDb{

		st_getLocalAgencyListFromDb()
		{
			init();
		}

		void init()
		{
			targetID = 0;
			appID = 0;
			taskID = 0;
			messageID = 0;
			urgent = 0;
			finished = 0;
			createTime = 0;
			updateTime = 0;
		}
		int64 targetID;
		int64 appID;
		int64 taskID;
		int64 messageID;
		agencyMessageBean messageBean;
		int8 urgent;
		int8 finished;
		int64 createTime;
		int64 updateTime;

	};

	struct st_commonTokenInfo {
		st_commonTokenInfo()
		{
			init();
		}
		std::string commonToken;
		int64 userId;
		int64 expireTime;
		void init() {
			userId = 0;
			expireTime = 0;
		}
	};

	struct resp_commonTokenRsp : public _sdkrespcmd_base {
		resp_commonTokenRsp()
		{
			code = 0;
		}
		std::string message;//返回码描述
		st_commonTokenInfo commonTokenInfo;
		int32 code;
		CMD_SIZE();
		COPY_OTHER(resp_commonTokenRsp);
	};
	struct st_operateCacheMsgStatusData
	{
		st_operateCacheMsgStatusData() : localId(0), targetId(0), messageType(0), operateType(0){}
		int64 localId;
		int64 targetId;
		int16 messageType;
		int operateType;
	};

	struct st_messageIdListInfo   //根据消息id列表查询消息
	{
		st_messageIdListInfo() :targetID(0)
		{
			messageIdList.clear();
		}
		void init()
		{
			targetID = 0;
			messageIdList.clear();
		}
		int64    targetID;				///< 目标ID,群号或者用户号 targetID.

		std::vector<int64>    messageIdList; ///消息id列表
	};

	struct st_CombinationOrderRemind
	{
		st_CombinationOrderRemind()
		{
			nRemindType = 0;
			szDelayTime = "";
		}

		int8 nRemindType;
		std::string szDelayTime;
	};

	struct st_CombinationOrder
	{
		st_CombinationOrder()
		{
			nBitSwitch     = 0;
			nUserId        = 0;
			nDelayTime     = 0;
			szTemplateid   = "";
			szTemplateName = "";
			remindVt.clear();	
		}

		int32 nBitSwitch;
		int64 nDelayTime;
		int64 nUserId;
		std::string szTemplateid;
		std::string szTemplateName;
		std::vector<st_CombinationOrderRemind> remindVt;
	};
}

#endif   //CMD_COM_DEF_H_
