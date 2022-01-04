#pragma once

#include "../model/SDKTypes.h"
#include <string>
#include <vector>
#include "../model/Optional.h"
#include <map>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN ///防止重复包含 
#include <Windows.h>
#else
//
#endif

namespace model
{

    // 任务属性
    struct MsgProperties {
        MsgProperties() {}

        std::string timeZone;       ///< 时区
        std::string timeTask;       ///< 任务时间
        std::string isFinish;       ///< 是否完成     0：未完成 1：完成
        std::string isTask;         ///< 任务标记     0：非任务 1：任务
        std::string isRead;         ///< 是否已读     0：未读   1：已读  2：已回复
    };

    // task
    struct Task
    {
        Task() :fromeUserID(0), sendTime(0), msgID(0), top(0), targetID(0)
        {
        }

        int64 fromeUserID;                  ///< 自己发送的这个字段填0
        int64 sendTime;                     ///< 发送时间
        std::string body;                   ///< 消息体
        int64 msgID;                        ///< 任务ID
        MsgProperties msgProperties;
        std::string relatedUsers;           ///< 如果是针对群全体成员，就是群ID，如果针对部分人，就是人的ID数组
        std::vector<int64> vt_relatedUsers; ///< 返回的时候用
        int32 badwordType;                  ///< 过滤词类型
        std::vector<std::string> vt_badword;///< 过滤词
        int8 top;                           ///< 是否置顶   0：不置顶 1：置顶
        int64 targetID; 		            ///< 接受者，可以为群或者人
    };

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///房间
    struct room
    {
        room() :roomID(0), top(0)
        {}

        int roomID;                         ///< 房间ID
        std::string roomName;               ///< 房间名
        std::string roomMember;             ///< 房间成员
        std::vector<int64> vt_roomMember;   ///< 返回的时候用
        int8 top;                           ///< 是否置顶   0：不置顶 1：置顶
        std::string portraitURL;            ///< 头像
    };
    /////////////////////////////////////////////////////////////////////////

    /// 企业信息
    struct entpriseInfo
    {
        entpriseInfo() :
        enterpriseID(0),
        sector(0),
        sectorDetail(0),
        type(0),
        provinceID(0),
        cityID(0),
        areaID(0),
        status(0),
        creationDate(0),
        updatedDate(0){}

        int64 enterpriseID;         ///< 企业ID enterpriseID.
        std::string fullName;       ///< 企业全称 fullName.
        std::string shortName;      ///< 企业简称 shortName.
        std::string keyWords;       ///< 企业关键字 keyWords.
        int64 sector;               ///< 企业所属行业 sector.
        int64 sectorDetail;         ///< 企业所属行业的具体哪一类 sectorDetail.
        int8 type;                  ///< 企业类型 type.
        int64 provinceID;           ///< 企业所属省份 provinceID.
        int64 cityID;               ///< 企业所属市 cityID.
        int64 areaID;               ///< 企业所属地区 areaID.
        std::string address;        ///< 企业地址 address.
        std::string postcode;       ///< 企业邮编 postcode.
        std::string phone;          ///< 企业电话 phone.
        std::string fax;            ///< 企业传真 fax.
        std::string email;          ///< 企业邮箱 email.
        std::string homepage;       ///< 企业主业 homepage.
        std::string introduction;   ///< 企业简介 introduction.
        std::string logUrl;         ///< 企业logURL地址 logUrl.
        int8 status;                ///< 企业状态：1:审核通过；2：未审核；3：审核未通过 status.
        int64 creationDate;         ///< 注册时间 creationDate.
        int64 updatedDate;          ///< 修改时间 updatedDate.
    };


    /// 企业成员信息
    struct EntpriseUserInfo
    {
        EntpriseUserInfo() :
        userID(0),
        enterpriseID(0),
        orgID(0),
        roleID(0),
        status(0),
        orderNum(0),
		securityLevel(0),
        newOrgID(0){}

        int64 userID;               ///< 用户ID userID.
        int64 enterpriseID;         ///< 企业ID enterpriseID.
        int64 orgID;                ///< 组织机构ID orgID.
        int64 roleID;               ///< 角色ID roleID.
        std::string enName;         ///< 企业内用户名称 enName.
        std::string duty;           ///< 企业内用户职位 duty.
        std::string enMail;         ///< 企业内用户email enMail.
        std::string enMobile;       ///< 企业内用户手机号 enMobile.
        int8 status;                ///< 企业账号是否被停用 1：正常 2：停用 status.
        int64 orderNum;             ///< 人员排序 orderNum.
        int64 newOrgID;             ///< 用户修改组织机构使用，表示用户新组织机构，在修改时给用户增加组织机构时，使用newOgrID而不是orgID newOrgID.
        std::string orgName;        ///< 组织名 orgName.
        std::string extend;         ///< 扩展信息 extend.
        std::string accountName;    ///< 账号名称 accountName.
        std::string enNamePy;       ///< 拼音 enNamePy.
        int8  bizStatus;            ///< 业务状态 业务状态：1：初始状态，2：在高管群
        std::string userHead;       ///< 头像
        std::string userHeadUrl;    ///<头像全路径
        std::string power;         ///< 权限
		int securityLevel;       ///< 工作密级
		std::string tagIds;     ///< 用户标签id,多个用逗号分隔
    };

    /// 团队用户查询参数
    struct EnterpriseUserQueryInfo
    {
        EnterpriseUserQueryInfo() :
        entID(0),
        entOrgID(0),
        pageNo(0),
        pageSize(100),
        entUserID(0),
        bizStatus(0),
        status(0){}

        std::string username; 	    ///< 用户名称 username.
        int64 entID; 			    ///< 企业ID entID.
        int64 entOrgID; 		    ///< 组织架构ID entOrgID.
        int32 pageNo; 			    ///< 分页页码 pageNo.
        int32 pageSize; 		    ///< 分页每页大小 pageSize.
        int64 entUserID; 		    ///< 企业用户ID.
        int8 bizStatus;             ///< 业务状态，1：默认，2：在高管层.
        int8 status;                ///< 企业用户状态.
    };

    /// note
    struct _BaseNoteinfo__isset
    {
        _BaseNoteinfo__isset() :id(false), lastChgTime(false), sendUserId(false), targetId(false), type(false),
        content(false), title(false), key(false), isReminder(false), rmdTime(false), isArchive(false)
        {}
        bool id;						    ///记事本唯一标识
        bool lastChgTime;					///最后修改时间,毫秒
        bool sendUserId;					///发送的人
        bool targetId;						///来源 人或者群		
        bool type;
        bool content;						///内容     最长4096个字符	
        bool title;							///标题     最长128字符
        bool key;							///关键字(标签),  检索用 最长128字符 ,可以为空
        bool isReminder;					///是否是提醒
        bool rmdTime;						///提醒时间
        bool isArchive;						///是否归档
    };
    ///记事本
    struct BaseNoteInfo
    {
        BaseNoteInfo() :isNet(false), id(0), lastChgTime(0), sendUserId(0), targetId(0), type(0), isReminder(0), rmdTime(0), isArchive(0){}

        bool isNet;                             ///是否使用网络接口
        Optional<int64> id;						///<记事本唯一标识     收藏ID
        Optional<int64> lastChgTime;		    ///<最后修改时间,毫秒  创建时间
        Optional<int64> sendUserId;				///<发送的人           消息来源Id  
        Optional<int64> targetId;				///<来源 人或者群      群Id
        /**
        *  低8位 类型 1. 文本，2，图片，3，音频，4，视频，5，URL
        *  高8位 1. 本地， 0. 网络
        */
        Optional<int8> type;
        Optional<int16> netType;
        /**
        根据文件类型
        1. 文本、URL 直接存储内容。
        2. 非文本类型，存储附件地址，网络地址和本地地址均可。
        */
        Optional<std::string> content;		///<内容 最长4096个字符	    收藏消息

        //这些都是本地记事本字段
        Optional<std::string> title;		///<标题 最长128字符
        Optional<std::string> key;			///<关键字(标签),  检索用 最长128字符 ,可以为空
        Optional<int8> isReminder;			///<是否是提醒
        Optional<int64> rmdTime;			///<提醒时间
        Optional<int8> isArchive;			///<是否归档

        //以下是网络收藏字段
        Optional<std::string> msgProperties;	///<消息属性
        Optional<std::string> fileName;		    ///<文件名
        Optional<std::string> exts;			    ///<扩展字段
        Optional<std::string> loginInfo;
    };
    struct searchNoteInfo{
        searchNoteInfo() :isNet(false), beginID(0), offset(0), offsetFlag(0), type(0){}

        bool isNet;         ///< 是否使用网络接口  
        int64 beginID;      ///< 起始消息ID / 网络接口：查询页数,从1开始
        int32 offset;       ///< 查询的数量(为0查询全部) / 网络接口：单页的查询数量(为0查询全部)
        int8  offsetFlag;   ///< 偏移标志；0.由大到小 1.由小到大 网络查询固定从大到小排列

        //以下几个字段是本地查询字段，网络查询不需要传值
        int16 type;         ///< 0:查询所有; 1:根据msgType; 2:根据消息内容 3:根据文件名;
        /**
        * 下面3个字段每次只能给一个字段赋值，剩余2个字段不用赋值
        */
        int8 is_all;        ///< 1:获取全部.
        int8 is_archive;    ///< 1:获取未归档 2:获取已经归档  
		std::string key;    ///< 根据关键词查找 
        //本地查询字段 End

        /**
          * 网络查询参数，根据key条件查询
          * collectUserId   收藏者Id，必传
          * messageType     根据消息类型查询
          * message         根据消息内容查询
          * fileName        根据文件名称查询
          * startTime       创建开始时间
          * endTime         创建结束时间
        **/
        std::map<std::string, std::string> params;  ///< 网络查询参数 
    };

    struct OrgAndUserSearchIn {
        OrgAndUserSearchIn() :
        type(0),
        userID(0),
        pageNum(0),
        pageSize(0) {
            orgIDs.clear();
        }

        int8  type;                                 /// 4：组织机构模糊查找 5：搜索人员接口
        int64 userID;                               /// 用户ID
        std::string name;                           /// 名称
        int32 pageNum;                              /// 页码
        int32 pageSize;                             /// 页长	
        std::vector<int64> orgIDs;                  /// 选择的部门ID集合(type=5时赋值)
    };

    struct OrgSearchUserInfo{
        EntpriseUserInfo uBean;
        std::string oPower;
    };
	///记事本功能
    struct Notebook{
		Notebook() : id(0), lastChgTime(0), createTime(0), count(0), isEncrypt(0), isReminder(0), rmdTime(0), isHidden(0)
		{
		}

        int64 id;                           /// 唯一标示id
        Optional<int64> lastChgTime;        /// 上次修改时间
        Optional<int64> createTime;         /// 创建时间
        Optional<int> count;              /// 记事本内容数量
        Optional<std::string> title;        /// 标题
        Optional<int8> isEncrypt;           /// 是否加密 0.不加密 1.字符加密 2.手势加密 
        Optional<std::string> encryptKey;   /// 加密锁
        Optional<int8> isReminder;          /// 是否设置提醒
        Optional<int64> rmdTime;            /// 提醒时间
		Optional<std::string> bgImage;      /// 背景图片 全路径
		Optional<std::string> ext;			/// 扩展信息 客户端妥善使用
		Optional<int8> isHidden;			/// 是否是隐藏记事本 0.公开 3.隐藏
		Optional<std::string> label;		/// 标签
    };
    struct NoteEntry{
		NoteEntry() : id(0), noteId(0), lastChgTime(0), createTime(0), sourceId(0), type(0), isReminder(0), rmdTime(0)
		{
		}

        int64 id;                           /// 记事内容id
        Optional<int64> noteId;             /// 上次修改时间
        Optional<int64> lastChgTime;        /// 上次修改时间
        Optional<int64> createTime;         /// 创建时间
        Optional<int64> sourceId;           /// 来源id
        Optional<std::string> sourceName;   /// 来源名称
        Optional<int> type;               /// 记事类型 同消息类型
        Optional<std::string> content;      /// 内容 格式由客户端自行组织
        Optional<std::string> title;        /// 标题
        Optional<int8> isReminder;          /// 是否设置提醒
        Optional<int64> rmdTime;            /// 提醒时间
        Optional<std::string> msgProperties;/// 消息属性，辅助contetn存储
	    Optional<int32> securityLevel;      /// 密级字段
    };
    struct GetNoteEntryParam{
        GetNoteEntryParam() : noteId(0), startId(0), offset(0), offsetFlag(0), type(0)
        {}
        int64 noteId;		/// 记事本Id
        int64 startId;		/// 起始查找ID offsetFlag = 0 beginID = 0时，代表从最大的消息Id进行查找
        int32 offset;       /// 查询的数量(赋值为0代表查询全部)
        int8 offsetFlag;	/// 偏移标志；0.由大到小偏移 1.由小到大偏移
        int8 type;			/// 查询方式 0.按id 1.按创建时间 2.按修改时间
        std::string encryptKey;	/// 加密秘钥
    };
	struct CustomerPoolBean
	{
		CustomerPoolBean() :
		userID(0) {
		}
		
		int64 userID;  ///客户id
		std::string name;  ///客户昵称
		std::string portraitURL;  ///客户头像
		MsgPtr message; ///最后一条消息
	};
	//客服信息
	struct AppCustomerInfo
	{
		AppCustomerInfo() :
		CSID(0),appID(0),customerID(0),maxReception(0),totalReception(0),createDt(0),updateDt(0) {
		}
		int64 CSID;			//客服id
		int64 appID;			 //公众号id
		int64 customerID; //客服的用户id
		int8 onlineStatus;  //在线状态1:在线，2:离线
		int32 maxReception;  //当前最大可接待数
		int32 totalReception;  //总接待数
		std::string portraitUrl;  //客服头像
		std::string nickname;  //客服昵称
		std::string extJson;	//扩展信息
		int64 createDt;			//创建时间
		int64 updateDt;	 //修改时间
	};
	struct UserShield{

		std::string keyId;          //手机盾用户KEYID
		std::string eventData;      //手机盾登录事件数据
		std::string expireTime;     // 手机盾过期时间
		int8 shieldStatus;        //手机盾激活状态(1正常，2重置，3未激活)
	};
	/**
	* \struct CustomChat
	* \brief  客服会话联系人信息
	*/
	struct  CustomChat
	{
		CustomChat() : appId(0),targetID(0),lastMsgid(0),time(0),msgType(0),activeType(0),unreadCnt(0){
		}

		int64 appId;				///<公众号Id
		int64 targetID;   		///< 目标用户ID targetID.
		int64 lastMsgid;        ///< 最后一次消息ID lastMsgid.
		int64 time;				///< 消息时间 time
		int8  sex;			 ///<  0保密 1男，2女
		/**
		* \brief 消息类型
		*/
		int16  msgType;
		int32  activeType;		 ///< 激活类型， 当前未用 activeType.
		int16  unreadCnt;        ///< 未读数量   unreadCnt.

		std::string avatar;
		std::string avatarUrl;  ///< 服务器全路径
		std::string nickName;	///< 显示名称 nickName.
		std::string lastMsg;    ///< 最后一条消息描述 lastMsg.
		std::string msgProp;    ///< 消息属性
	};

	/**
	* \struct CustomAppInfo
	* \brief  客服公众号信息
	*/
	struct  CustomAppInfo
	{
		CustomAppInfo() {}

		EntAppinfo appInfo;
		MsgPtr message; ///最后一条消息
	};
}
