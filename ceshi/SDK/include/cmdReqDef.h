#ifndef CMD_REQ_DEF_H
#define CMD_REQ_DEF_H

#include "cmdComDef.h"

//=================================<所有请求消息结构体>============================================//

typedef bool(*MatchFunc)(const char *msg, const char *key);

namespace imsdk
{
	/**
	  * \struct  req_setHeadImg
	  * \brief   设置头像 , logic_cmd_setHeadImg 消息携带
	  */
	struct req_setHeadImg : public _sdkcmd_base
	{
		req_setHeadImg() :imgType(0) {}
		std::string thumb_path;    ///< 缩略图本地地址 thumb_path.
		std::string orgi_path;	   ///< 大图本地地址 orgi_path.
		int8 imgType;			   ///< 0.头像 1.背景图
		CMD_SIZE();
	};

	/**
	  * \struct req_getBuddyVerifyType 消息号: logic_cmd_getBuddyVerifyType
	  * \ brief 获取好友验证类型
	  */
	struct req_getBuddyVerifyType : public _sdkcmd_base
	{
		req_getBuddyVerifyType() :userid(0) {}
		int64 userid; ///< 要加为好友的人ID userid.
		CMD_SIZE();
	};

	/**
	  * \struct req_getBuddyInfo
	  * \brief 获取好友详细信息  消息号：logic_cmd_getBuddyInfo
	  */
	struct req_getBuddyInfo : public _sdkcmd_base
	{
		req_getBuddyInfo() :flag(0), userID(0) {}
		int8 flag;			///< 0为读取本地，1为获取网络最新 flag.
		int64 userID;		///< 好友的ＩＤ号 userID.
		CMD_SIZE();
	};

	/**
	  * \struct  req_downloadFile
	  * \brief   文件接收请求 消息号: logic_cmd_downloadFile
	  * 		 接收进度消息使用logic_cmd_progress消息返回
	  */
	struct req_downloadFile : public _sdkcmd_base
	{
		req_downloadFile() :flag(0) {}
		std::string localPath;	 ///< 文件本地保存路径 localPath.
		std::string remotePath;	 
		///< 0:remotePath为全路径，1.远程路径,从消息JSON中解析出来的路径  或上0xF0，代表只判断文件有效性，不下载 remotePath
		int8 flag;              					 
		CMD_SIZE();
	};

	/**
	  * \struct  req_recvFiles
	  * \brief   文件接收请求 消息号: logic_cmd_recvFiles
	  * 		 接收进度消息使用logic_cmd_progress消息返回
	  */
	struct req_recvFiles : public _sdkcmd_base
	{
		req_recvFiles () {
			bisP2P = false;
            msgID = 0;
            targetID = 0;
            fromID = 0;
			bisResume = true;
			threadCount = 0;
			fileType = 0;
			securityLevel = 0;
			isGroupDoc = 0;
			docid = 0;
		}
		/**
		 * \brief 1. 当bisP2P=false, 传该文件所属的消息ID
		 *        2. 当bisP2P=true, 传下层请求中带的TASKID
		 */
		int64       msgID;        ///如果是p2p传输, msgid将被用作taskID
		int64       targetID;	 ///< 目标ID	有可能是群或者人 targetID.
		std::string encryptKey;  ///< 暂时不用.
		std::string localPath;	 ///< 文件本地保存路径 localPath.
		std::string remotePath;	 ///< 远程路径,从消息JSON中解析出来的路径 remotePath.
		int64       fromID;      ///< 发送者ID fromID.
		std::string fileName;    ///< 真实的文件名 fileName.
		bool        bisP2P ;	 ///< 是否接收局域网直传文件.
		bool        bisResume;   ///<是否断点下载
		int			threadCount;	///< 下载的线程数量 bIsResume为true且threadCount>1时生效
		int			fileType;		///< 文件类型 1文档 2图片 3视频 4音频 5其他 存fileInfo用
		int64		mediaTime;	 ///< 媒体文件时长 秒
		std::string relaPath;	 ///< 相对路径 iOS专用
		int32     securityLevel; ///<密级
		std::string md5Code;	 ///< 文件MD5值，校验用，传空则不校验
		int8 isGroupDoc;  //是否群文档 0：否  1：是
		int64 docid;  //群文档id
		CMD_SIZE(); 
		
		void  init()
		{
			bisP2P = false ;
			md5Code.clear();
		}
	};

	/**
	  * \struct req_sendFiles 消息号: logic_cmd_sendFiles
	  * \brief  发送文件。单个文件接收进度消息使用logic_cmd_progress消息返回
	  */
	struct req_sendFiles : public _sdkcmd_base
	{
		int64 targetID;					///< 目标ID,有可能是群或者人 targetID.
        uint16 type;                    ///< 消息类型, 同req_sendMessage的messageType.
                                        ///< 3:音频 5:图片 6:文件.
		/**
		 * \brief 加密KEY，为空不进行加密
		 */
		std::string encryptKey;			///< 加密KEY encryptKey.
        std::string message;            ///< 附加信息由上层定义和使用.
		std::vector<st_sendFile> _vt;	///< 发送文件数组 _vt.
		int8      isP2p ;               ///< 是否点对点 0 否， 1 是.
		int8      isJS;                 ///< 是否JS上传图片,0 否， 1 是
		int8	  noStore;				///< 是否不存消息和文件信息到数据库0 否， 1 是
        std::string loginInfo;          ///< 登录信息（iOS插件外部APP上传文件专用）

		req_sendFiles() {
			init();
		}

		void  init()
		{
			targetID = 0;
			type = 0;
			_vt.clear();
			isP2p = 0 ;
			isJS = 0;
			noStore = 0;
		}
		CMD_SIZE();
	};

	/**
	  * \struct req_getHistoryMsg 消息号: logic_cmd_getHistoryMsg
	  * \brief 获取历史消息,
	  *
	  */
	struct req_getHistoryMsg : public _sdkcmd_base
	{
		req_getHistoryMsg() :targetID(0), msgBeginID(0), msgOffset(0)
		{
			msgType.clear();
			fromUserID.clear();
		}
		void init()
		{
			targetID = 0;
			msgBeginID = 0;
			msgOffset = 0;
			msgType.clear();
			fromUserID.clear();
		}
		int64    targetID;				///< 目标ID,群号或者用户号 targetID.
        /**
         * \brief 起始消息ID
         *        返回的结果会包含这条消息
				  如果是按消息Id查询传入查询消息的起始消息ID，如果是按消息时间查询传入查询消息的起始时间。
         *        offsetFlag = 0 msgBeginID = 0时，代表从最大的消息Id进行查找
         */
		int64    msgBeginID;
		int32    msgOffset;			     ///< 消息偏移量 msgOffset.
		/**
			偏移标志 0.消息Id由大到小偏移 1.消息Id由小到大偏移 offsetFlag.
			如果msgBeginID代表的是消息时间的话，或上0xF0,如果是消息ID的话就不用或上0xF0
		*/
		int8     offsetFlag;  		     
		std::vector<int16>    msgType;   ///< 消息类型,表示查询某一些类型的消息，默认为空,表示查询所有类型的消息,最多查询5种类型的消息。
		std::vector<int64>    fromUserID; ///< 发送者ID,表示只查询某一些人发的消息，默认为空，表示查询所有人的消息，最多查询10个人的消息。
		CMD_SIZE();
	};

	/**
	* \struct req_getAppointMsg 消息号: logic_cmd_getAppointMsg
	* \brief 获取指定消息,
	*
	*/
	struct req_getAppointMsg : public _sdkcmd_base
	{
		req_getAppointMsg() :targetID(0) {}
		int64 targetID;				///< 目标ID,   群号或者用户号 targetID.
		std::vector<int64> _vt;     ///< msg ID
		void  init()
		{
			_vt.clear();
		}
		CMD_SIZE();
	};



	/**
	* \struct req_getGroupTopMsgByPage 消息号: logic_cmd_getGroupTopMsgByPage
	* \brief 获取置顶消息
	*
	*/
	struct req_getGroupTopMsgByPage : public _sdkcmd_base
	{

		req_getGroupTopMsgByPage()
		{
			init();
		}

		void  init()
		{
			targetId = 0;
		    msgId = 0;
			count = 0;
			flag = 0;
		}
		int64 targetId;
		int64 msgId;
		int count; 
		int flag;
		CMD_SIZE();
	};


	/**
	  * \struct req_setMsgReaded  消息号: logic_cmd_setMsgReaded
	  * \brief 设置消息已读
	  */
	struct  req_setMsgReaded : public _sdkcmd_base
	{
		req_setMsgReaded() :targetID(0), msgID(0) {}
		int64    targetID;  ///< 目标ID，群或者人ID， targetID.
		/**
		 * \brief 需要设置的消息ID
		 * 比如设置为100, 比100小的所有消息都为已读
		 */
		int64    msgID;
		CMD_SIZE();
	};

	/**
	  * \struct req_sendMessage 	消息号： logic_cmd_sendMessage
	  * \brief  发送消息结构体
	  */
	struct req_sendMessage : public _sdkcmd_base
	{
		req_sendMessage() :userID(0), targetID(0),
				isBurn(0), noStore(0), activeType(0),
				relatedMsgID(0), realTargetId(0), isCustom(0), subMsgType(0), securityLevel(0), messageType(0), issueId(0), issueCreater(0), issueOperType(0)
		{
		}
		int64 userID;   		///< TODO,要删除,不用设置自己的用户ID.
		int64 targetID; 		///< 接受者，可以为群或者人 targetID.
		std::string message; 	///< 消息体 message.
		int8 isBurn;         	///< 是否阅后即焚 isBurn.
		int8 noStore;			///< 本地不存储消息  0为存储，1为不存储.			
		/**
		 * \brief 消息类型
		 * 1:html 2:文本，3:音频 4: 位置 5:图片6:文件 7:名片 8:弱提示
		 */
		int16 messageType;
		std::string maccode; 	///< mac地址 maccode.
		std::string format;  	///< 文本格式，可以不用 format.
		std::vector<int64>  limitRange; ///< 限制消息用户范围 limitRange.
		std::string msgProperties; 	///< 消息属性, 可定义为json串  msgProperties.
		int8  activeType;    	///< 消息事件属性 activeType.
		std::vector<int64>  relatedUsers; ///< @功能使用，填入@人员的用户ID relatedUsers.
		int64 relatedMsgID;  	///< 关联消息ID relatedMsgID.
		std::string sourceID;   ///< 陌生人单聊时的来源ID，1_groupID表示传的群ID，2_orgID表示传的组织ID sourceID.
		std::string loginfoPath; ///发送消息，登录信息路径
		int64 issueId;			///< 议题id 1为创建
		int64 issueCreater;		///< 议题创建者Id
		std::string issueName;	///< 议题名称 "-delete"为删除
		int8 issueOperType;		///< 议题操作 1.回复 2.创建 3.删除
		int64 realTargetId;   //真实接收者ID,用于客服给客户发消息,
		int8 isCustom;  ///<是否是客服客户之间的66号消息 0.否 1.是
		int8 subMsgType; ///子类型
		int32 securityLevel;//密级
		int64 msgId;//目前仅为上传过期文件消息使用

		void init() {
			format.clear();
			sourceID.clear();
			message.clear();
			userID = 0;
			targetID = 0;
			isBurn = 0;
			noStore = 0;
			activeType = 0;
			relatedMsgID = 0;
			issueId = 0;
			issueCreater = 0;
			issueOperType = 0;
			limitRange.clear();
			relatedUsers.clear();
			msgProperties = "";
			loginfoPath = "";
			issueName = "";
			realTargetId = 0;
			subMsgType = 0;
			securityLevel = 0;
			messageType = 0;
			msgId = 0;
		}
		CMD_SIZE();
	};

	/**
	* \struct req_fileMessage 	消息号： logic_cmd_fileMessage
	* \brief  发送消息(包含附件消息)结构体
	*/
	struct req_fileMessage : public req_sendMessage
	{
		req_fileMessage() :isP2p(0), sendPasswdWithoutEncrypt(0){}
		void init()
		{
			req_sendMessage::init();
			isP2p = 0;
			sendPasswdWithoutEncrypt = 0;
			validityDays = 0;
		}
		int8        isP2p;                ///< 是否点对点 0 否， 1 是.
		int8 sendPasswdWithoutEncrypt;   ///<只发送秘钥，不进行加密 0.加密文件 1.不实际加密文件 
		std::string encryptKey;			  ///< 加密KEY encryptKey.
		st_sendFile file;			      ///< 发送的文件
		int8 isGroupDoc;  // 是否群文档  0：否   1：是
		int64 validityDays;
		CMD_SIZE();
	};

	struct req_AddGroupDocFile : public _sdkcmd_base
	{
		req_AddGroupDocFile()
		{
		}
		req_fileMessage sendfile;
		st_GroupDocAttribute groupdocAttr;

		CMD_SIZE();
	};

	struct req_GroupDocAttribute : public _sdkcmd_base
	{
		req_GroupDocAttribute() :modtype(0)
		{
		}
		st_GroupDocAttribute groupdocfile;
		int8 modtype;
		CMD_SIZE();
	};

	/*
		1: i64 groupID;
		/*最大返回条数
	2: i16 pageSize;
	3: i64 version;
	*/
	struct req_GroupDocQuery : public _sdkcmd_base
	{
		req_GroupDocQuery()
		{
		}
		int64 groupID;
		int16 pageSize;
		int64 version;
		CMD_SIZE();
	};
	/**
	* \struct req_imgMessage 	消息号： logic_cmd_imgMessage
	* \brief  发送消息(包含附件消息)结构体
	*/
	struct req_imgMessage : public req_sendMessage
	{
		void init()
		{
			req_sendMessage::init();
			thumbPaths.clear();
			orgPaths.clear();
			fileInfoExt.clear();
			sendPasswdWithoutEncrypt = 0;
		}
		int8 sendPasswdWithoutEncrypt;   ///<只发送秘钥，不进行加密 0.加密文件 1.不实际加密文件 
		std::string encryptKey;					///< 加密KEY encryptKey.
		///< 缩略图和原图一一对应，一对图推一次进度
		std::vector<std::string> thumbPaths;	///< 缩略图路径
		std::vector<std::string> orgPaths;		///< 原图路径
		//以下iOS专用字段
		std::vector<std::string> relaPaths;		///< 相对路径
		std::vector<std::string> fileInfoExt;	///< 存fileInfo库的ext 包括图片视频分辨率 视频音频时长
		CMD_SIZE();
	};

    /**
     * \struct req_sendMessageExt 	消息号： logic_cmd_sendMessageExt
     * \brief  发送消息(包含附件消息)结构体
     */
    struct req_sendMessageExt : public req_sendMessage
    {
        st_sendFilesExt attachment; ///附件消息
        CMD_SIZE();
    };

	/**
	  * \struct   req_simpleSearch
	  * \brief    搜索
	  */
	struct req_simpleSearch : public _sdkcmd_base
	{
		req_simpleSearch() :type(0),area(0) {}

		/**
		 * \brief 搜索类型
		 * type 与上 0x0F:
		 * 1: 搜索联系人
		 * 2: 搜索群
		 * 3: 搜索团队
		 * 0: 全部搜索
		 * type 与上 0xF0:
		 * 0x10: 标识本地搜索
		 */
		int8 type;
		/**
		 * \brief 搜索范围
		 * 1: 本公司搜索
		 * 2: 互联搜索
		 */
		int8 area;                 ///< 地区 1 本公司搜索 2 互联搜索 area.
		std::string keyword;       ///< 关键字 keyword.
		CMD_SIZE();
	};

	/**
	* \struct   req_mKeysSearch
	* \brief    多关键字搜索
	*/
	struct req_mKeysSearch : public _sdkcmd_base
	{
		req_mKeysSearch() :type(0), area(0) {}
		/**
		* \brief 搜索类型
		* type 与上 0x0F:
		* 1: 搜索联系人
		* 2: 搜索群
		* 3: 搜索团队
		* 0: 全部搜索
		* type 与上 0xF0:
		* 0x10: 标识本地搜索
		*/
		int8 type;
		/**
		* \brief 搜索范围
		* 1: 本公司搜索
		* 2: 互联搜索
		*/
		int8 area;                 ///< 地区 1 本公司搜索 2 互联搜索 area.
		std::vector<std::string> keywords;       ///< 关键字 keyword.
		CMD_SIZE();
	};

	/**
	* \struct   req_groupSearchMember 消息号： logic_cmd_groupSearchMember
	* \brief    群内搜索群成员
	*/
	struct req_groupSearchMember : public _sdkcmd_base
	{
		req_groupSearchMember() :groupId(0) {}
		int64 groupId;               ///< 群Id
		std::string keyword;         ///< 关键字
		CMD_SIZE();
	};
	/**
	 * \struct req_updateOnlineState
	 * \brief  更新在线状态
	 */
	struct req_updateOnlineState : public _sdkcmd_base
	{
		req_updateOnlineState() :flag(0) {}
		int8 flag; ///< 1:在线,2:隐身,3:忙碌,4:离开,5:请勿打扰 flag.
		int8 nStatus; //1:在线；2:会议中,3:忙碌,4:飞机上,5:请勿打扰,6:自定义
		std::string szExplain;
		CMD_SIZE();
	};

	/**
	  * \struct req_getBuddyOnline 消息号:  logic_cmd_getBuddyOnline
	  * \brief 获取好友在线状态
	  */
	struct req_getBuddyOnline : public _sdkcmd_base
	{
		/**
		 * \biref 用户列表 , 如果列表为空，
		 * 表示获取全部好友状态，否则获取指定成员状态。
		 */
		std::vector<int64> member;
		void init()
		{
			member.clear();
		}
		CMD_SIZE();
	};

	/**
	* \struct req_getBuddyOnlineEx 消息号:  logic_cmd_getBuddyOnlineEx
	* \brief 获取好友在线状态,增强版
	*/
	struct req_getBuddyOnlineEx : public _sdkcmd_base
	{
		/**
		* \biref 用户列表 , 如果列表为空，
		* 表示获取全部好友状态，否则获取指定成员状态。
		*/
		std::vector<int64> member;
		void init()
		{
			member.clear();
		}
		CMD_SIZE();
	};

	/**
	 * \struct req_Changepw  ， 消息号: logic_cmd_changePw
	 * \brief 修改密码
	 */
	struct req_Changepw : public _sdkcmd_base
	{
		std::string  oldPw;   ///< 旧密码 oldPw.
		std::string  newpw;   ///< 新密码 newpw.
		CMD_SIZE();
	};

	/**
	 * \struct req_opUser , 消息号: logic_cmd_opuser
	 * \brief 操作好友
	 */
	struct req_opUser : public _sdkcmd_base
	{
		req_opUser()
		{
			INIT_ISSET(isDeleteOtherSide)
			INIT_ISSET(tinyUserType)
			INIT_ISSET(starBuddy)
			INIT_ISSET(groupID)
			INIT_ISSET(remark)
			INIT_ISSET(backgroundURL)
			INIT_ISSET(disturbSet)
		}

		int8 operType;	///< 2:更新，3：删除 operType.
		/**
		* \brief 好友ＩＤ
		*/
		int64 userID;
		/**
		* \brief 对方列表中 1： 删除， 2： 不删除
		*/
		IS_SET(int8, isDeleteOtherSide)
		/**
		* \brief 好友类型 1: 好友， 2：关注
		*/
		IS_SET(int8, tinyUserType)
		/**
		* \brief 星标好友 1：星标好友，　２：非星标好友
		*/
		IS_SET(int8, starBuddy)

		/**
		* \brief 操作到组
		* 1.我的好友 2陌生人 3黑名单，其他用户自定义分组
		*/
		IS_SET(int64, groupID)
		IS_SET(std::string, remark)	///< 好友备注 remark.
		IS_SET(std::string, backgroundURL)	///< 聊天背景 backgroundURL.		
		IS_SET(int8, disturbSet)            ///好友设置 1为接收提醒,2表示不提醒仅显示数字,3为免打扰

		void init()
		{
			operType = 0;
			isDeleteOtherSide = 0;
			tinyUserType = 0;
			starBuddy = 0;
			userID = 0;
			groupID = 0;
			INIT_ISSET(isDeleteOtherSide)
			INIT_ISSET(tinyUserType)
			INIT_ISSET(starBuddy)
			INIT_ISSET(groupID)
			INIT_ISSET(remark)
			INIT_ISSET(backgroundURL)
			INIT_ISSET(disturbSet)
		}

		CMD_SIZE();
	};

	/**
	* \struct req_getHiddenAccountNew , 消息号: logic_cmd_getHiddenAccountNew
	* \brief 通过密码得到隐藏的好友或群Id
	*/
	struct req_getHiddenAccountNew : public _sdkcmd_base
	{
		std::string pwd;				///< 之前设置过的隐藏密码 pwd.
		CMD_SIZE();
	};

	/**
	 * \struct req_setHiddenAccountNew , 消息号: logic_cmd_setHiddenAccountNew
	 * \brief 设置隐藏
	 */
	struct req_setHiddenAccountNew : public _sdkcmd_base
	{
		std::string pwd;				///< 设置隐藏的密码 pwd.
		std::vector<int64> hiddenIDs;   ///< 需要隐藏的好友或群ID hiddenIDs
		CMD_SIZE();
	};

	/**
	 * \struct req_deleteHiddenAccountNew , 消息号: logic_cmd_deleteHiddenAccountNew
	 * \brief 删除隐藏
	 */
	struct req_deleteHiddenAccountNew : public _sdkcmd_base
	{
		std::string pwd;				///< 删除需要的密码 pwd.
		std::vector<int64> hiddenIDs;   ///< 需要删除的好友或群ID hiddenIDs
		CMD_SIZE();
	};

	/**
	 * \struct req_verifyHiddenInfo , 消息号: logic_cmd_verifyHiddenInfo
	 * \brief 找回隐藏密码，验证聊天信息
	 */
	struct req_verifyHiddenInfo : public _sdkcmd_base
	{
		std::vector<st_hiddenAccountInfo> hiddenAccountInfos;	///< 验证以前的聊天记录，三句大于5字节以上的聊天信息,可以是多个人的,也可以是一个人的,优先多个人
		CMD_SIZE();
	};

	/**
	* \struct req_resetHiddenPWD , 消息号: logic_cmd_resetHiddenPWD
	* \brief 重置隐藏密码
	*/
	struct req_resetHiddenPWD : public _sdkcmd_base
	{
		std::string oldpwd;				///< 旧密码  oldpwd
		std::string newpwd;				///< 新密码  newpwd
		CMD_SIZE();
	};

	/**
	* \struct  req_setMySelf 消息号: logic_cmd_setMyself
	* \brief 设置用户请求
	*/
	struct req_setMySelf : public _sdkcmd_base
	{
		st_userBean user; ///< 用户信息结构 user.
		void init() {
			user.info.emails.clear();
			user.info.phones.clear();
			user.init();
		}
		CMD_SIZE();
	};

	/**
	 * \struct  req_getUserFromID 消息号: logic_cmd_getUser
	 * \brief   根据ＩＤ获取用户信息
	 */
	struct  req_getUserFromID : public _sdkcmd_base
	{
		req_getUserFromID():userid(0),dwnPortaitType(0){}
		int32    dwnPortaitType;     ///< 指定要下载的头像类型 1 原图  2缩略图   0 全部下载
		int64    userid;			 ///< 用户ＩＤ userid.
		CMD_SIZE();
	};
	
	/**
	* \struct  req_getUserByScene 消息号: logic_cmd_getUserByScene
	* \brief   根据客户端使用场景获取相应用户资料
	*/
	struct  req_getUserByScene : public _sdkcmd_base
	{
		req_getUserByScene() :targetId(0), scene(0) {}
		int64    targetId;  ///< 用户ＩＤ userid.
		int8 scene;			///< 用户场景,1：好友中点击 2：陌生人中点击 3：组织架构中点击
		CMD_SIZE();
	};

	/**
	 * \struct req_LoginParamBean
	 * \brief 如果只进行预登录，只填写 :
	 * 1. area
	 * 2. usrid 填0
	 * 3. version
	 * 4. device_info
	 * 5  userType
	 */
	struct req_LoginParamBean : public _sdkcmd_base
	{
		req_LoginParamBean()
		{
			init();
		}
		void init() {
			device_type = 0;
			userType = 0;
			usrid = 0;
			tick = 0;
			user = "";
			pwd = "";
			mac = device_info = version = net_type = local = area = nationalCode = thirdParam = "";
			sdkid = 0;
            inviteCodeId = 0;
			serverip = "";
		}
		/**
		 * \brief  用户类型
		 * 手机 1，  qq 2 ， 邮箱 3 ，豆豆号 4， 身份证 5 , 6 豆豆账号  95 注册登录   96 验证码登录
		 */
		int32 userType;
		/**
		 * \brief 设备类型
		 * 设备类型 1：PC；2：手机；3：pad；4：网页
		 */
		int32 device_type;
		/**
		 * \brief 踢人策略
		 * 1: 强制踢(登录) 2: 不踢人(重连)
		 */
		int32 tick;
		int64 usrid;                	        ///< 用户id　usrid.
		int64 sdkid;                            ///< SDKid,标识唯一APP sdkid.
        int64 inviteCodeId;                     ///< 邀请者Id
		std::string mark;						///< 版本标识，mark.
		std::string user;                  	    ///< 用户名, user.
		std::string pwd;                   	    ///< 密码 pwd.
		std::string mac;                   	    ///< mac 地址 统一格式 XX:XX:XX:XX:XX:XX mac.
		/**
		 * \brief 设备信息
		 * pc-window7,an-xiaomei2,ios-iphone4s
		 */
		std::string device_info;
		std::string version;				    ///< 客户端版本,如1.23,1.2281(点后面超过2位为测试版) version.
		std::string net_type;				    ///< 网络类型,wifi或2g/3g或httpproxy net_type.
		std::string local;               	    ///< 语言及国家,zh_CN local.
		/**
		 * \brief
		 * 分两种
		 * 1. 使用ＶＲＶ服务器的二级域名
		 * 		比如传入 vrv 连接的服务器为 vrv.linkdood.cn
		 * 		传入 wechat 的连接服务器为 wechat.linkdood.cn;
		 * 2. IP地址　格式为　地址:端口 比如: 192.168.0.1:80 ，或者 163.com:80。
		 *
		 *
		 */
		std::string area;               	    ///< 多服务器的情况下,是服务器地址 area.
		std::string nationalCode;         		///< 国家代码 nationalCode.
		std::string captcha;                    ///< 验证码 captcha.
		std::string thirdParam;					///< 第三方参数json
		std::string serverip;                   ///< 登录成功的服务器IP
		CMD_SIZE();
	};

	/**
	*  开放登陆
	*/
	struct req_getLoginAuthCode : public _sdkcmd_base
	{
		req_getLoginAuthCode()
		{
			appID.clear();
			userID.clear();
			account.clear();
			INIT_ISSET(account);
			INIT_ISSET(password);
		}
		void init()
		{
			appID.clear();
			userID.clear();
			account.clear();
			INIT_ISSET(account);
			INIT_ISSET(password);
		}

		std::string appID;            ///< 应用ID
		std::string userID;           ///< 用户ID
		std::string accountType;      ///< 账户类型
		IS_SET(std::string, account)  ///< 账户
		IS_SET(std::string, password) ///< 密码
		CMD_SIZE();
	};

	/**
	* \struct req_qVerifyCodes  消息号 logic_cmd_qVerifyCodes
	* \brief 邀请码相关
	* \type 类型
	1.根据用户ID向用户发送短信(只根据语言发送，不处理内容)
	参数： userIDs==>用户ID集合
	返回：code:　0:成功，100:参数错误，11100:内部错误
	map<string, string> failRet==>失败的用户ID及失败原因
	2.生成邀请码
	参数：inviteCodeParam
	返回：code:0, what:7CUFV48，code为0时表示生成邀请码成功，what中返回的为生成的邀请码
	3.校验本人是否有生成邀请码的权限
	参数：无
	返回：code为0表示有权限，100001717表示此人没有权限生成邀请码
	4.校验邀请码是否有效
	参数：value_str:邀请码     uc:被邀请用户
	返回：code:0邀请码有效；code:100参数错误，100001715邀请码已失效
	8. 查询服务器允许注册人数 (getLimitRegisterCount)
	参数：无
	返回值
	code:
	0:成功
	100:参数错误
	11100:服务器内部错误
	100015004:没有该操作类型
	100015005:没有设置邀请码权限
	100015006:修改邀请码失败
	100015007:查询分享列表失败
	value64: 允许注册人数
	9. 设置邀请码接口 (setInviteCode)
	参数：
	setParam ==> InviteSetParam
	返回值
	code:
	0:成功
	100:参数错误
	11100:服务器内部错误
	100015004:没有该操作类型
	100015005:没有设置邀请码权限
	100015006:修改邀请码失败
	100015007:查询分享列表失败
	10. 用户邀请码分享列表查询接口 (getShareInviteCodeInfo)
	参数：
	value64  查询人用户id ==> setupUserID
	返回值
	code:
	0:成功
	100:参数错误
	11100:服务器内部错误
	100015004:没有该操作类型
	100015005:没有设置邀请码权限
	100015006:修改邀请码失败
	100015007:查询分享列表失败
	shareInfo 邀请码列表 ==> list<aphead.InviteCodeShare>
	11. 保存邀请码图片
	参数:
		inviteCode   邀请码
		inviteCodePic  邀请码图片
	返回值:
	0:成功
	100:参数错误
	11100:服务器内部错误
	*/
	struct req_qVerifyCodes : public _sdkcmd_base
	{
		req_qVerifyCodes()
		{
			INIT_ISSET(type);
			INIT_ISSET(value_str);
			INIT_ISSET(value_str2);
			INIT_ISSET(uc);
			INIT_ISSET(userIDs);
			INIT_ISSET(inviteCodeParam);
			INIT_ISSET(inviteSetParam);
			INIT_ISSET(shareListParam);
		}

		void init()
		{
			INIT_ISSET(type);
			INIT_ISSET(value_str);
			INIT_ISSET(value_str2);
			INIT_ISSET(uc);
			INIT_ISSET(userIDs);
			INIT_ISSET(inviteCodeParam);
			INIT_ISSET(inviteSetParam);
			INIT_ISSET(shareListParam);
		}
		IS_SET(int8, type)  
		IS_SET(std::string, value_str)
		IS_SET(std::string, value_str2)
		IS_SET(st_userContact, uc)
		IS_SET(std::vector<int64>, userIDs)
		IS_SET(st_inviteCodeParam, inviteCodeParam)
		IS_SET(st_inviteSetParam, inviteSetParam)
		IS_SET(st_inviteCodeShareParam, shareListParam)
		
		CMD_SIZE();
	};

	/**
	* \struct req_qMsgStores , 消息号: logic_cmd_qMsgStores
	* \brief /统计消息
	*/
	struct req_qMsgStores : public _sdkcmd_base
	{
		req_qMsgStores()
		{
			INIT_ISSET(type);
			INIT_ISSET(messageID);
			INIT_ISSET(targetID);
			INIT_ISSET(snapshotID);
			INIT_ISSET(mucs);
		}
		void init()
		{
			INIT_ISSET(type);
			INIT_ISSET(messageID);
			INIT_ISSET(targetID);
			INIT_ISSET(snapshotID);
			INIT_ISSET(mucs);
		}

		IS_SET(int8, type)        ///1.统计消息未读、已读、未推送的userID列表
		IS_SET(int64, messageID)  ///消息ID
		IS_SET(int64, targetID)   ///消息目标ID 人或者群
		IS_SET(int64, snapshotID); ///群快照ID
		IS_SET(std::vector<st_msgUnreadCounter>,mucs)  
		CMD_SIZE();
	};

	/**
	* \struct req_cloudDiskFunc , 消息号: logic_cmd_cloudDiskFunc
	* \brief /云盘接口 返回值为resp_commonResult，取value_str值。
	*/
	struct req_cloudDiskFunc : public _sdkcmd_base
	{
		req_cloudDiskFunc()
		{
			jsonStr = "";
		}
		void init()
		{
			jsonStr = "";
		}
		std::string jsonStr;    //json格式
		CMD_SIZE();
	};

	/**
	* \struct req_circleOfFriend , 消息号: logic_cmd_circleOfFriend
	* \brief /朋友圈接口 返回值为resp_commonResult，取value_str值。
	*/
	struct req_circleOfFriend : public _sdkcmd_base
	{
		void init()
		{
			jsonStr = "";
			loginfoPath = "";
		}
		std::string jsonStr;    //json格式
		std::string loginfoPath;	///< 登录信息保存路径
		CMD_SIZE();
	};

    /**
    * \struct req_queryJson , 消息号: logic_cmd_queryJson
    * \brief /json透传接口 返回值为resp_commonResult，取value_str值。
    */
    struct req_queryJson : public _sdkcmd_base
    {
        void init()
        {
            reqJson = "";
            type = 0;
        }
        std::string reqJson;    //json格式
        int8 type;	///< 服务类型 1:调用声网服务 2:原生朋友圈 3:原生云盘
        CMD_SIZE();
    };

	/**
	* \struct req_elayFiles , 消息号: logic_cmd_elayFiles
	* \brief 文件链接延期 返回值为resp_delayFiles，取value_str。
	*/
	struct req_delayFiles : public _sdkcmd_base
	{
		req_delayFiles()
		{
			init();
		}
		void init()
		{
			delayType = 0;
			fileUrls.clear();
		}
		int32 delayType;        ///< 1.查询文件链接是否过期 2.文件链接延期
		std::vector<std::string> fileUrls;
		CMD_SIZE();
	};

	/**
	* \struct req_fileExpirySoon , 消息号: logic_cmd_fileExpirySoon
	* \brief 获取未下载即将过期文件列表 返回值为resp_fileExpirySoon，取value_str。
	*/
	struct req_fileExpirySoon : public _sdkcmd_base
	{
		req_fileExpirySoon()
		{
			init();
		}
		void init()
		{
			targetIDs.clear();
			//fileUrls.clear();
		}
		std::vector<int64> targetIDs;        ///< 1.群或人ID集合
		int64 userID;
		int nValidDays1;							///<单聊文件有效期
		int nValidDays2;							///<群聊文件有效期
		//std::vector<std::string> fileUrls;
		CMD_SIZE();
	};

	/**
	* \struct req_fileExpirySoonResult , 消息号: logic_cmd_fileExpirySoonResult
	* \brief 获取未下载即将过期文件列表 返回值为resp_fileExpirySoonResult，取value_str。
	*/
	struct req_fileExpirySoonResult : public _sdkcmd_base
	{
		req_fileExpirySoonResult()
		{
			init();
		}
		void init()
		{
			targetID=0;
			//fileUrls.clear();
		}
		int64 targetID;        ///< 1.群或人ID集合
		//int64 userID;
		//std::vector<std::string> fileUrls;
		CMD_SIZE();
	};

	/**
	* \struct req_fileExpiryInfoStore , 消息号: logic_cmd_fileExpiryInfoStore
	* \brief 存储未下载即将过期文件信息 返回值为resp_fileExpiryInfoStore。
	*/
	struct req_fileExpiryInfoStore : public _sdkcmd_base
	{
		req_fileExpiryInfoStore()
		{
			init();
		}
		void init()
		{
			fileInfos.clear();
			targetID=0;
			fileID = 0;
			isSwitchOn = 0;
		}
		std::vector<st_FileExpiryInfoStore> fileInfos;
		int64 targetID;         ///< 1.群或人ID集合
		int64 fileID;					///<最大msgID
		int32 isSwitchOn;			///>开关
		CMD_SIZE();
	};

	/**
	* \struct req_fileExpiryInfoAsk , 消息号: logic_cmd_fileExpiryInfoAsk
	* \brief 获取未下载即将过期文件信息 返回值为resp_fileExpiryInfoAsk。
	*/
	struct req_fileExpiryInfoAsk : public _sdkcmd_base
	{
		req_fileExpiryInfoAsk()
		{
			init();
		}
		void init()
		{
			targetIDs.clear();
			//fileID = 0;
			//isSwitchOn = 0;
		}
		std::vector<int64> targetIDs;         ///< 1.群或人ID集合
		//int64 fileID;					///<最大msgID
		//int32 isSwitchOn;			///>开关
		CMD_SIZE();
	};

	/**
	* \struct req_accountQueryUserID, 消息号: 
	* \brief 根据用户账号批量userID 
	* 返回: map<string,int64>　(key:type+"-"+contactInfo+"-"+SDKID, value:UserID)
	*/
	struct req_accountQueryUserID : public _sdkcmd_base
	{
		req_accountQueryUserID()
		{
			accounts.clear();
			type = 0;
			status = 0;
			SDKID = 0;
		}
		void init()
		{
			accounts.clear();
			type = 0;
			status = 0;
			SDKID = 0;
		}
		std::vector<std::string> accounts; ///< 帐号名称集合 手机号前加0086
		int8 type;           ///< 1.电话号码 3.email 4.userID 6.accountName
		int8 status;         ///< 1.启用， 2.禁用, 5.锁定, 6.冻结
		int64 SDKID;         ///< vrv服务器传0    
		CMD_SIZE();      
	};
	/**
	* \struct req_queryUserIsExistList, 消息号: logic_cmd_queryUserIsExistList
	* \brief 判断某个目标用户是否在用户设置名单中(黑名单, 或者白名单)
	*/
	struct req_queryUserIsExistList : public _sdkcmd_base
	{
		req_queryUserIsExistList()
		{
			init();
		}
		void init()
		{
			queryType = 0;
			entId = 0;
			targetId = 0;
		}
		int8  queryType;    ///< 1.黑名单 2.白名单
		int64 entId;        ///< 当addType == 2的时候设置， 表示企业ID
		int64 targetId;     ///< 目标ID,如果查询自己是否在别人黑名单中,targetId传自己ID,queryType传2，entId传对方ID
		CMD_SIZE();

	};
	/**
	* \struct req_getGroupAtMsg, 消息号: logic_cmd_getGroupAtMsg
	* \brief 获取群内@过自己或者自己@过别人的消息
	* 返回:返回结构和获取历史消息共用一个结构体resp_getHistoryMsg
	*/
	struct req_getGroupAtMsg : public _sdkcmd_base
	{
		req_getGroupAtMsg()
		{
			groupID = 0;
			beginTime = 0;
			endTime = 0;
			maxCount = 0;
			atType = 0;
		}
		void init()
		{
			groupID = 0;
			beginTime = 0;
			endTime = 0;
			maxCount = 0;
			atType = 0;
		}

		int64    groupID;           ///< 群ID
		int64    beginTime;         ///< 起始时间
		int64    endTime;           ///< 结束时间
		int32    maxCount;          ///< 最大返回的消息数量,消息排序按时间倒叙排列。
		int8     atType;            ///< 0.别人@我，1.我@别人
	};

	/**
	 * \struct req_addBuddyResponse 消息号: logic_cmd_addBuddyResponse
	 * \brief 　加好友响应
	 */
	struct  req_addBuddyResponse : public _sdkcmd_base
	{
		req_addBuddyResponse()
		{
			refuseReason = "";
			remark = "";
			INIT_ISSET(inviteMark)
			INIT_ISSET(inviteCode)
		}
		void init()
		{
			refuseReason = "";
			remark = "";
			INIT_ISSET(inviteMark)
			INIT_ISSET(inviteCode)
		}
		int64 userID; 			  ///< 将要添加好友ＩＤ userID.
		std::string refuseReason; ///< 拒绝理由 refuseReason.
		std::string remark;       ///< 备注　remark.
		int16 isAgree;            ///< 参见subType
		int64 reqVerifyboxID;     ///< 验证请求唯一编号 reqVerifyboxID.
		IS_SET(int64, inviteMark) ///< 1.注册邀请
		IS_SET(std::string, inviteCode) ///< 注册邀请码
		CMD_SIZE();
	};

	/**
	 * \struct  req_addBuddyRequest 消息号: logic_cmd_addBuddyRequest
	 * \brief 发送好友请求
	 */
	struct req_addBuddyRequest : public _sdkcmd_base
	{
		req_addBuddyRequest() :requestType(0), userID(0) {}
		/**
		 * \brief １是加好友，　２是关注
		 */
		int8 requestType;
		int64 userID;                         ///< 被请求好友的ＩＤ userID.
		std::vector<std::string>  verifyInfo; ///< 验证信息 verifyInfo.
		std::string remark;                   ///< 好友备注 remark.

		void init()
		{
			verifyInfo.clear();
		}
		CMD_SIZE();
	};

	/**
	 * \struct req_regParam1  消息号: logic_cmd_reg1 logic_cmd_resetPw1
	 * \brief 注册账号第一步，找回密码第一步
	 */
	struct req_regParam1 : public _sdkcmd_base{
		req_regParam1() :usertype(0), operType(0) {}
		int8                usertype;       ///<  用户类型 usertype.
		std::string   	    number;			///<  手机号或者电子邮箱 number.
		std::string         domain;			///<  企业域 domain.
        int8                operType;       ///<  操作类型 1-注册 2-登录
		/**
		 * \brief 做预登录用,
		 * 请查看req_LoginParamBean　预登录填写规则
		 */
		req_LoginParamBean  login;
		CMD_SIZE();
	};

	/**
	* \struct req_regParam2   消息号: logic_cmd_reg2,logic_cmd_resetPw2
	* \brief  注册账号第二步，找回密码第二步
	*	     这条消息有2种使用模式
	*	     1: 一步走完，code、name和pwd都赋值
	*	     2: 两步走完，如下：
	*	     第一步：code赋值，name、pwd不赋值。
	*	     返回 resp_regResult2
	*	     第二步：name、pwd赋值，code不赋值。
	*		 返回 resp_regResult2
	*	     *registryID， sdkid都要赋值
	*/
	struct req_regParam2 : public _sdkcmd_base
	{
		req_regParam2() :registryID(0), sdkid(0) {}
		int64          	registryID;       ///<  注册第一步返回的注册编号ID registryID.
		int64           sdkid;            ///<  使用SDK标识唯一APP sdkid.
		std::string  	code;             ///<  验证码 code.
		std::string  	name;             ///<  用户名 name.
		std::string  	pwd;              ///<  密码 pwd.
		CMD_SIZE();
	};

	/**
	 * \struct req_verifyImg  消息号：  logic_cmd_verifyImg
	 * \brief  验证码操作
	 */
	struct  req_verifyImg : public _sdkcmd_base
	{
		req_verifyImg() :next(0), type(0) {}
		int8        next;		///< 1，更换下一张，2，不更换下一张 next.
		int8        type;		///< 验证码类型，默认填１ type.
		std::string usrName;	///< 用户名 usrName.
		std::string info;		///< 从验证码获得的检验信息 info.
		std::string macAddr;	///< MAC地址，必选参数 macAddr.
		CMD_SIZE();
	};

	/**
	 * \struct req_createGroup 消息号： logic_cmd_createGroup
	 * \brief 创建群
	 */
	struct req_createGroup : public _sdkcmd_base
	{
		req_createGroup()
		{
			init();
		}
		std::string serverInfo;		       ///< 本地服务器地址,当前没有使用 serverInfo.
		int8 level;			               ///< 群等级 1、2、3、4 level.
		std::string extend;	               ///< 群扩展字段 extend.
		std::vector<int64> inviteMembers;  ///< 邀请用户 inviteMembers.
		int8 groupSearch;			       ///< 群是否可以被检索，1.可以 2.不可以 默认1 groupSearch.
		int8 groupActive;			       ///< 群是否激活 1.激活 2.不激活 默认1 groupActive.
		int8  receiveMsgType;              ///< 1：提示并接收消息；2：不提示，接收仅显示数目；3：屏蔽消息 receiveMsgType.
		std::string receiveTimePeriod;    
		std::string name ;                 ///< 群名称.
		std::string brief ;                ///< 公告.
		int64       relatedGroupID ;       ///< 关联群，默认为零.
		int64       relatedEntID ;         ///< 关联企业 默认为零.
		int32 securityLevel;               ///< 群密级
		int8 powerSwitch;                  ///<提权开关
		void init() {
			serverInfo = "";
			level = 1;
			extend = "";
			inviteMembers.clear();
			groupSearch = 2;
			groupActive = 1;
			receiveMsgType = 1;
			receiveTimePeriod = "";
			name = "";
			brief = "";
			relatedGroupID =  0;
			relatedEntID = 0 ;
            securityLevel = 0;
            powerSwitch = 0;
		}
		CMD_SIZE();
	};

	/**
	 * \struct req_groupVerifyRequest 消息号: logic_cmd_groupVerifyReq
	 * \brief 申请加入群请求
	 */
	struct req_groupVerifyRequest : public _sdkcmd_base
	{
		req_groupVerifyRequest() :groupID(0) {}
		int64 groupID;				///< 群ID groupID.
		std::string verifyInfo;		///< 验证信息 verifyInfo.
		CMD_SIZE();
	};

	/**
	 * \struct req_groupInviteRequest　 消息号  logic_cmd_groupInviteReq
	 * \brief   邀请加入群请求命令
	 */
	struct req_groupInviteRequest : public _sdkcmd_base
	{
		req_groupInviteRequest() :groupID(0) {}
		int64 groupID;				///< 群ID groupID.
		std::string verifyInfo;		///< 验证信息 verifyInfo.
		std::vector<int64> users;	///< 邀请的用户ID集合　users.
		void init() {
			users.clear();
		}
		CMD_SIZE();
	};

	/**
	 *  \struct req_groupDelete 消息号 logic_cmd_groupDelete
	 *  \brief   删除群
	 */
	struct req_groupDelete : public _sdkcmd_base
	{
		int8  operType;				///< 1 群主解散群，2 群成员退群 operType.
		int64 groupid;				///< 群ID groupid.
		void init()
		{
			operType = 0;
			groupid = 0;
		}
		CMD_SIZE();
	};

	/**
	 *  \struct req_groupTrans 消息号 logic_cmd_groupTrans
	 *  \brief   群转移
	 */
	struct req_groupTrans : public _sdkcmd_base
	{
		int64 groupid;
		int64 targetUserid;
		void init()
		{
			groupid = 0;
			targetUserid = 0;
		}
		CMD_SIZE();
	};

	/**
	 *  \struct req_groupInfoUpdate 消息号 logic_cmd_groupUpdateInfo
	 *  \brief   群信息更新
	 */
	struct req_groupInfoUpdate : public _sdkcmd_base
	{
		req_groupInfoUpdate()
		{
			INIT_ISSET(groupName)
			INIT_ISSET(groupIcon)
			INIT_ISSET(groupBrief)
			INIT_ISSET(groupBulletin)
			INIT_ISSET(groupBackgroundURL)
			INIT_ISSET(groupSearch)
			INIT_ISSET(extendProperties)
			INIT_ISSET(groupMessageContentMode)
			INIT_ISSET(securityLevel)
			INIT_ISSET(powerSwitch)

		}
		int64 groupID;
		IS_SET(std::string, groupName)				///< 群名称.
		IS_SET(std::string, groupIcon)				///< 群图标.
		IS_SET(std::string, groupBrief)				///< 群简介.
		IS_SET(std::string, groupBulletin)			///< 群公告.
		IS_SET(std::string, groupBackgroundURL)		///< 群背景图片.
		IS_SET(int8, groupSearch);					///< 群是否可以被外部检索 1可以 2不可以.
		/**
		 * \brief群扩展字段,以json形式,目前：  ;
		 * 警种ID： policeTypeID
		 * 地域---省份ID：provinceID
		 * 地域---市ID： cityID
		 * 私信模式：privateMsg：1为开启私信   0表示不允许私信
		 */
		IS_SET(std::string, extendProperties)	
		IS_SET(int8, groupMessageContentMode)		 ///< 群消息通知详情: 1、开启(显示详情)  2、关闭(显示通知源，隐藏内容)  默认开启.

		IS_SET(int8, securityLevel)                  ///<群密级
		IS_SET(int8, powerSwitch)                    ///<提权开关
		void init()
		{
			groupID = 0;
			groupSearch = 0;
			groupName = "";
			groupIcon = "";
			groupBrief = "";
			groupBulletin = "";
			groupBackgroundURL = "";
			powerSwitch = 0;
			INIT_ISSET(groupName)
			INIT_ISSET(groupIcon)
			INIT_ISSET(groupBrief)
			INIT_ISSET(groupBulletin)
			INIT_ISSET(groupBackgroundURL)
			INIT_ISSET(groupSearch);
			INIT_ISSET(extendProperties)
			INIT_ISSET(groupMessageContentMode)
			INIT_ISSET(securityLevel)
			INIT_ISSET(powerSwitch)
		}
		CMD_SIZE();
	};

	/**
	 *  \struct req_groupCommonData 消息号
	 *  \brief   群请求通用接口体
	 */
	struct req_groupCommonData : public _sdkcmd_base
	{
		int64 groupid;
		void init()
		{
			groupid = 0;
		}
		CMD_SIZE();
	};

	/**
	*  \struct req_groupDocComData 消息号
	*  \brief   群文档请求通用接口体
	*/
	struct req_groupDocComData : public _sdkcmd_base
	{
		int64 groupid;
		int64 docid;
		void init()
		{
			groupid = 0;
			docid = 0;
		}
		CMD_SIZE();
	};

	/**
	*  \struct req_groupDocComData 消息号
	*  \brief   群上传下载文档请求通用接口体
	*/
	struct req_gDocUpDownData : public _sdkcmd_base
	{
		int64 groupid;
		std::string localpath;
		int64 docid;
		int8 status;
		int8 whupordown;
		void init()
		{
			groupid = 0;
			docid = 0;
			status = 0;
			whupordown = 0;
			localpath.clear();
		}
		CMD_SIZE();
	};


	/**
	 *  \struct req_removeGroupMember 消息号 logic_cmd_removeGroupMember
	 *  \brief   删除群成员
	 */
	struct  req_removeGroupMember : public _sdkcmd_base
	{
		req_removeGroupMember() :groupID(0), userID(0) {}
		int64   groupID;
		int64   userID;
		std::vector<int64> rmIDs;
		void init()
		{
			rmIDs.clear();
		}
		CMD_SIZE();
	};

	/**
	 *  \struct req_setGroupSet 消息号 logic_cmd_setGroupSet
	 *  \brief   设置群验证方式
	 */
	struct req_setGroupSet : public _sdkcmd_base
	{
		int64 groupID;
		st_groupSet gs;
		void init()
		{
			groupID = 0;
			gs.verifyType = 0;
			gs.isAllow = 0;
		}
		CMD_SIZE();
	};

	/**
	 *  \struct req_getMemberInfo
	 *  \brief
	 */
	struct req_getMemberInfo : public _sdkcmd_base{
		req_getMemberInfo() :groupid(0), memberid(0) {}
		int64 groupid;
		int64 memberid;
		CMD_SIZE();
	};

	/**
	 *  \struct req_getGroupMemberInfo 消息号 logci_cmd_getGroupMemberInfo
	 *  \brief   获取群成员详细信息
	 */
	struct req_getGroupMemberInfo : public _sdkcmd_base
	{
		req_getGroupMemberInfo() :groupid(0), memberid(0) {}
		int64 groupid;
		int64 memberid;
		CMD_SIZE();
	};

	/**
	 * \struct req_setGroupMemberInfo  消息号 logic_cmd_setGroupMemberInfo
	 * \brief 设置群成员信息
	 */
	struct req_setGroupMemberInfo : public _sdkcmd_base
	{
		req_setGroupMemberInfo() {
			groupId = 0;
			memberId = 0;
			INIT_ISSET(memberName)
			INIT_ISSET(chatContext)
			INIT_ISSET(memType)
			INIT_ISSET(vSign)
			INIT_ISSET(groupMessageContentMode)
		}

		int64 groupId;
		int64 memberId;
		/**
		 * \brief 群成员类型
		 * 1：普通用户 2：管理员 3：超级管理员
		 */
		IS_SET(int8, memType)  
		IS_SET(std::string, memberName)  ///<群名片.
		IS_SET(std::string, chatContext) ///<暂时不用.
		IS_SET(int8, vSign) ///< v标群,0为非v标群，1为v标群.
		IS_SET(int8, groupMessageContentMode) ///< 群通知消息内容模式: 1、通知详情  2、通知源，隐藏内容  3、完全隐藏 , 默认开启模式1.
		CMD_SIZE();

		void init()
		{
			INIT_ISSET(memberName)
			INIT_ISSET(chatContext)
			INIT_ISSET(memType)
			INIT_ISSET(vSign)
			INIT_ISSET(groupMessageContentMode)
		}
	};

	/**
	 * \struct req_getGroupShieldInfo  消息号 logic_cmd_getShieldGroupMessage
	 * \brief 获取群消息提示方式
	 */
	struct req_getGroupShieldInfo : public _sdkcmd_base
	{
		int8  deviceType;		///< 1：pc；2：phone；3：html deviceType.
		int64 groupid;
		void init()
		{
			deviceType = 0;
			groupid = 0;
		}
		CMD_SIZE();
	};

	/**
	 * \struct req_setGroupShieldInfo  消息号 logic_cmd_setShieldGroupMessage
	 * \brief 设置群消息提示方式
	 */
	struct req_setGroupShieldInfo : public _sdkcmd_base
	{
		req_setGroupShieldInfo() :receiveMsgType(0), groupid(0) {}
		int8  receiveMsgType;			///< 1：提示并接收消息；2：不提示，接收仅显示数目；3：屏蔽消息  4:时间段接收 5：插电接收 6:群消息免打扰 7:关闭免打扰
		int64 groupid;
		std::string receiveTimePeriod;
		CMD_SIZE();
	};

	/**
	 * \struct req_setGroupReqForRead  消息号 logic_cmd_setGroupReqForRead
	 * \brief 设置群验证请求消息已读
	 */
	struct req_setGroupReqForRead : public _sdkcmd_base
	{
		req_setGroupReqForRead() :operType(0), groupID(0) {}
		int8 operType;                                   ///< 1 邀请  2 请求 operType.
		int64 groupID;
		std::vector<int64> inviteIDs;					 ///< 邀请 或者 请求 inviteIDs.
		//std::map<int64,std::vector<int64> > reqIDs;	 ///< 请求消息ID，KEY-群ID value-请求ID集合
		void init()
		{
			inviteIDs.clear();
			//reqIDs.clear();
		}
		CMD_SIZE();
	};

	/**
	 * \struct req_sendImg  消息号 logic_cmd_sendImg
	 * \brief 发送图片
	 */
	struct req_sendImg : public _sdkcmd_base
	{
		req_sendImg(){ init(); }
		int64        targetID;      ///< 发送方ID targetID.
		std::string  encryptKey;    ///< 加密ＫＥＹ　不为空的话会对文件进行加密 encryptKey.
		std::string  thumb_path;    ///< 缩略图本地地址 thumb_path.
		std::string  orgi_path;     ///< 大图本地地址 orgi_path.
		bool isShareImg;			///< 是否为朋友圈图片
		std::string loginfoPath;	///< 登录信息保存路径
		void init()
		{
			loginfoPath.clear();
			encryptKey.clear();
			isShareImg = false;
			targetID = 0;
		}
		CMD_SIZE();
	};

	/**
	 * \struct req_recvImg  消息号 logic_cmd_recvImg
	 * \brief 接收图片
	 */
	struct req_recvImg : public _sdkcmd_base
	{
		int64   	targetID; 	///< 发送方对方ＩＤ targetID.
		int64       msgID;      ///< 消息ID msgID.
		std::string imgName;  	///< 文件名称 imgName.
		std::string rPath;  	///< 不带ＵＲＬ的远程路径 rPath.
		std::string encryptKey;	///< 加密密钥，存fileInfo用
		int32		flag;		///< 标识位 0缩略图 1大图 1~9表示九图的位置
		bool        isP2P;		///< 如果为true的话,
		int			fileType;	///< 文件类型 2图片 3视频缩略图 存fileInfo用
		std::string relaPath;	///< iOS专用，相对路径
		bool		isNineBox;	///< 是否下载九图缩略
		int32		width;		///< 图片宽度
		int32		height;		///< 图片高度
		std::string md5Code;    ///< 图片md5校验
		void init()
		{
			targetID = 0;
			msgID = 0;
			flag = 0;
			isP2P = false;
			isNineBox = false;
			width = 0;
			height = 0;
            md5Code.clear();
		}
		CMD_SIZE();
	};

	/**
	* \struct req_sendNineBoxImg  消息号 logic_cmd_sendNineBoxImg
	* \brief 发送九宫格
	*/
	struct req_sendNineBoxImg : public _sdkcmd_base
	{
		req_sendNineBoxImg() :targetID(0){}
		int64        targetID;      ///< 发送方ID targetID.
		std::string  encryptKey;    ///< 加密ＫＥＹ　不为空的话会对文件进行加密 encryptKey.
		std::vector<std::string>  thumb_path;    ///< 缩略图本地地址 thumb_path.
		std::vector<std::string>  orgi_path;     ///< 大图本地地址 orgi_path. 缩略图数量需要和原图一致
		void init()
		{
			thumb_path.clear();
			orgi_path.clear();
			targetID = 0;
		}
		CMD_SIZE();
	};

	/**
	* \struct req_recvNineBoxImg  消息号 logic_cmd_recvNineBoxImg
	* \brief 接收九宫格图片
	*/
	struct req_recvNineBoxImg : public _sdkcmd_base
	{
		req_recvNineBoxImg() :targetID(0), msgID(0){
			init();
		}
		int64   	targetID; 	///< 发送方对方ＩＤ targetID.
		int64       msgID;      ///< 消息ID msgID.
		std::string  encryptKey;///< 加密KEY 存fileInfo库用
		std::vector<std::string> rPath;  	///< 不带ＵＲＬ的远程路径 rPath.
		std::vector<std::string> relaPath;  ///< 相对路径 iOS用
		std::vector<std::string> md5Code;   ///< 加密的md5值，校验用
		void init()
		{
			rPath.clear();
			relaPath.clear();
			md5Code.clear();
			targetID = 0;
			msgID = 0;
		}
		CMD_SIZE();
	};

	/**
	 * \struct req_getSysMsgList  消息号 logic_cmd_getSysMsgList
	 * \brief 获取系统消息列表
	 */
	struct req_getSysMsgList : public _sdkcmd_base
	{
		req_getSysMsgList() :type(0), time(0), msgOffset(0), offsetFlag(0){}
		int8 type;                   ///< 0:全部 1:加好友请求 2:加好友响应 3:加群请求 4:加群响应 type.
		/* 
		  offsetFlag为0 以传入的time起始，向下偏移，拉取小于time的消息 如果time = 0，代表从最新收到的系统消息开始拉取
	      offsetFlag为1 以传入的time起始，向上偏移，拉取大于time的消息.
		*/
		int64 time;                  
		int32 msgOffset;			 ///< 消息列偏移量 msgOffset.
		int8 offsetFlag;             ///< 偏移标志，向上偏移 0；向下偏移 1 offsetFlag.
		CMD_SIZE();
	};

	/**
	* \struct req_deleteSysMsgList  消息号 logic_cmd_deleteSysMsgList
	* \brief 删除系统消息列表
	*/
	struct req_deleteSysMsgList : public _sdkcmd_base
	{
		req_deleteSysMsgList() :type(0) {}
		int8 type;       ///< 0:表示删除所有系统消息， 1:删除加好友请求 2:删除加好友响应 3:删除加群请求 4:删除加群响应 type.
		std::vector<int64> msgIDs;   ///< 当type不为0时，存放需要删除的msgid.
		void init(){
			msgIDs.clear();
		}
		CMD_SIZE();
	};

	/**
	 * \struct req_setSysMsgReaded  消息号 logic_cmd_setSysMsgReaded
	 * \brief 设置系统消息已读
	 *	      1 好友请求验证框已读
	 *	      2 好友请求返回框已读
	 *	      3 设置群验证请求消息已读
	 *	      4 设置群验证响应消息已读
	 */
	struct req_setSysMsgReaded : public _sdkcmd_base {
		req_setSysMsgReaded() :type(0) {}
		int8    type;      			///< 类型 type.
		std::vector<int64> msgIDs;
		void init(){
			msgIDs.clear();
		}
		CMD_SIZE();
	};

	/**
	 * \struct req_setIosNoticeInfo  消息号 logic_cmd_setUpiosRecvNotice
	 * \brief
	 */
	struct req_setIosNoticeInfo : public _sdkcmd_base{
		st_iosNoticeInfo info;
		CMD_SIZE();
	};

	/**
	 * \struct req_getFileList  消息号 logic_cmd_getFileList
	 * \brief  获取文件列表
	 */
	struct req_getFileList : public _sdkcmd_base
	{
		void init() {
			fileTerm = 0;
			fileType = 0;
			targetID = 0;
			msgBeginID = 0;
			msgOffset = 0;
			offsetFlag = 0;
		}
		int64     targetID;		///< 目标ID targetID.
		int64     msgBeginID;	///< 起始ＩＤ号 msgBeginID.
		int32     msgOffset;	///< 消息列偏移量 msgOffset.
		int8      offsetFlag;	///< 偏移标志，向上偏移 0；向下偏移 1 offsetFlag.
		int8      fileTerm;     ///按文件有效期类型获取 0. 获取所有 1.临时 2.永久
		int8	  fileType;		///< 按文件类型获取 0.所有 6.文档 5.图片(九宫格存储是5) 89.视频 3.音频
		CMD_SIZE();
	};

	/**
	* \struct req_delFileInfoList  消息号 logic_cmd_delFileInfoList
	* \brief  删除文件列表
	*/
	struct req_delFileInfoList : public _sdkcmd_base
	{
		req_delFileInfoList() :fileType(0) {}

		std::vector<delFileinfo>  _vt;  ///< 删除的文件信息列表 _vt.
		int8 fileType;            ///< 文件类型(6文档 5图片(九宫格存储是5) 89视频 3音频)
		void init() {
			_vt.clear();
		}
		CMD_SIZE();
	};

	/**
	 * \struct req_delGroupFiles  消息号 logic_cmd_delGroupFiles
	 * \brief  删除群文件
	 */
	struct req_delGroupFiles : public _sdkcmd_base
	{
		std::vector<int64>  _vt;  ///< 删除文件的ＩＤ列表 _vt.
		int64 groupId;            ///< 群ID
		void init() {
			_vt.clear();
			groupId = 0;
		}
		CMD_SIZE();
	};

	/**
	 * \struct req_groupVerifyRespons  消息号 logic_cmd_groupVerifyResp
	 * \brief 群主或管理员收到进群请求时做出的响应，或用户被邀请进群时做出的响应
	 */
	struct req_groupVerifyRespons : public _sdkcmd_base
	{
		void init() {
			reqUserID = 0;
			type = 0;
			reqID = 0;
			groupID = 0;
			respResult = 0;
		}
		int8 type;					///< 1.管理员操作 2.用户操作
		int64 reqID; 				///< 请求信息ID reqID.
		int64 groupID;				///< 群ID groupID.
		int64 reqUserID;			///< 邀请者ID
		int16 respResult; 			///< 参见subType
		std::string refuseReason; 	///< 拒绝理由 refuseReason.
		CMD_SIZE();
	};

	/**
	 * \struct req_setOLtype  消息号
	 * \brief
	 */
	struct req_setOLtype : public _sdkcmd_base
	{
		req_setOLtype() :type(false) {}
		bool type;
		CMD_SIZE();
	};

	/**
	 * \struct req_setTokenAndOlState  消息号 logic_cmd_setTokenAndOlState
	 * \brief IOS设置Token和云后台在线
	 */
	struct req_setTokenAndOlState : public _sdkcmd_base
	{
		void init()
		{
			type = 0;
			appleID = "";
			token = "";
			vb1 = false;
			vb2 = false;
			targetID = 0;
			deviceType = "";
            cloudToken = "";
		}
		/**
		 * \brief type 类型
		 *   0, 默认值，客户端可以不用设置该值，
		 *      设置token和appleID；需要参数appleID，token；返回code
		 *   1. 设置云后台在线状态 . 需要字段vb1设置云后台在线(true 在线, false 不在线),vb2设置应用在线(true在线), 返回code
		     2. 设置当前人的会话对象ID（中电科）
           需要参数targetID：聊天对象，用户ID　或　群ID
		 *   3.设置token 
		    传入参数：
			 appID: "XiaoMi"  不能为空，必填，小米可填写"XiaoMi"
			 token:token值  
			 deviceType: "0"苹果 "1"华为 "2"小米 "3"中电科EMM  "4"小米
		 */
		int8 type;
		std::string appleID;	///< 应用id， 不同的应用所对应的证书是不一样的 appleID.
		std::string token;		///< ios token token.
        std::string cloudToken; ///< 云电话token
		bool vb1;				///< 设置云后台在线 vb1.
		bool vb2;				///< 设置应用在线 vb2.
		int64 targetID;
		std::string deviceType;
		CMD_SIZE();
	};

	/**
	 * \struct req_delReContact  消息号 logic_cmd_delReContact
	 * \brief
	 */
	struct req_delReContact : public _sdkcmd_base
	{
		req_delReContact() :targetID(0) {}
		int64 targetID; ///< 删除聊天对象得ID， 如果为零，则删除全部最近聊天.
		CMD_SIZE();
	};

	/**
	 * \struct req_cancleExec  消息号 logic_cmd_cancleExec
	 * \brief
	 */
	struct req_cancleExec : public _sdkcmd_base
	{
		req_cancleExec() :cmdLocalID(0), cmdType(0) {}
		int64 cmdLocalID;		    ///< 被取消的消息localID cmdLocalID.
		int16 cmdType;			///< 消息类型 cmdType.
		CMD_SIZE();
	};

	/**
	 * \struct req_sendErrLog  消息号 logic_cmd_sendErrLog
	 * \brief
	 */
	struct req_sendErrLog : public _sdkcmd_base
	{
		req_sendErrLog() :osType(0) {}
		int8  osType; 		///< 操作系统类型 osType.
		std::string path; 	///< 错误日志路径 path.
		std::string desc;	    ///< 描述 desc.
	};

	/**
	 * \struct req_getAppinfo  消息号 logic_cmd_getAppInfo
	 * \brief
	 */
	struct req_getAppinfo : public _sdkcmd_base
	{
		req_getAppinfo() :appID(0) {}
		int64  appID;  ///< APPID appID.
		CMD_SIZE();
	};

	/**
	 * \struct req_localSetting  消息号 logic_cmd_localSetting
	 * \brief 本地设置请求结构
	 */
	struct req_localSetting : public _sdkcmd_base
	{
		req_localSetting() :type(0) {}
		int8   type;  			///< 0 : 增加，１：查询 , 2: 修改，３：删除 type.
		/**
		 * \brief type 的值不同，items有不同的意义
		 * 	0: items里面是新插入的值
		 * 	1: items里面带要查询的值，st_localSetting只给key赋值即可
		 * 	2: items带最新的值
		 * 	3: items里面带要删除的值，st_localSetting只给key赋值即可
		 */
		std::vector<st_localSetting> items;
		void init() {
			items.clear();
		}
		CMD_SIZE();
	};

	/**
	 * \struct req_transferOuterMsgDb  消息号 logic_cmd_transferOuterMsgDb
	 * \brief  迁移外部聊天数据库
	 */
	struct req_transferOuterMsgDb : public _sdkcmd_base
	{
		std::string outerDbPath;	///< 外部数据库路径 outerDbPath.
		CMD_SIZE();
	};

	/**
	 * \struct  req_PersonalData 消息号　logic_cmd_setPersonalData
	 * \brief 个人信息设置,
	 */
	struct  req_PersonalData : public _sdkcmd_base
	{
		std::vector<st_personalData> items;
		void init()
		{
			items.clear();
		}
		CMD_SIZE();
	};

	/**
	* \struct  req_msgGlobalSearch 消息号　logic_cmd_msgGlobalSearch
	* \brief 本地消息全局搜索，只返回每个匹配到的群或个人的消息的数目。
	*/
	struct req_msgGlobalSearch : public _sdkcmd_base
	{
		req_msgGlobalSearch() :targetId(0), count(1), msgType(2), isSpecial(0),
		startTime(0), endTime(0), func(NULL)
		{}

		/**
		 * 　\brief targetId为用户Id或群Id，与count字段共同决定搜索的方式，有以下几种组合：
		 *   targetId !=0, count = 1:搜索指定的targetId的聊天记录数目。
		 * 　targetId = 0,count > 1: 从最小的targetId开始向上搜索记录，共搜索到count个匹配的targetId为止。
		 *   targetId !=0, count >1: 从指定的targetId开始向上搜索记录，共搜索到count个匹配的targetId为止。
		 *   count = 0为匹配全部消息，最多匹配10000条
		 */
		int64 targetId;
		int count;	
		int16  msgType;   ///< 搜索消息的类型，1:html 2:文本，3:音频 4: 位置 5:图片6:文件 7:名片 8:弱提示 (当前只支持文本).
		int16  isSpecial; ///< 是否含有特殊字符，比如抖一抖或者橡皮擦，包含特殊字符需要进行特殊字符搜索,0表示不包含，1表示包含抖一抖，2表示包含橡皮擦
		std::string key;  ///< 搜索的关键字.
		int64 startTime;	///< 搜索消息的最小时间,不能大于endTime,单位秒.
		int64 endTime;	///< 搜索消息的最大时间,0为搜索全部时间段,单位秒.
		MatchFunc func;	///< 传入的用户自定义的匹配字符串的函数,为空时使用默认匹配方式
		CMD_SIZE();
	};

	/**
	 * \struct  req_msgDetailSearch 消息号　logic_cmd_msgDetailSearch
	 * \brief 在某个群或个人的聊天记录中搜索关键字。
	 */
	struct req_msgDetailSearch : public _sdkcmd_base
	{
		req_msgDetailSearch() :targetId(0), msgType(2), startTime(0), isSpecial(0), endTime(0), msgId(0), count(0), func(NULL)
		{}
		int64 targetId;	   	 ///< 目标Id.
		int16  msgType;      ///< 搜索消息的类型，1:html 2:文本，3:音频 4: 位置 5:图片6:文件 7:名片 8:弱提示 (当前只支持文本).
		int16  isSpecial; ///< 是否含有特殊字符，比如抖一抖或者橡皮擦，包含特殊字符需要进行特殊字符搜索,0表示不包含，1表示包含抖一抖，2表示包含橡皮擦
		int64  msgId;		 ///< 起始msgId，0为从最早的消息就行搜索.
		int count;			 ///< 一次匹配到最大的消息数量,0为匹配全部消息,最多匹配100000条.
		std::string key;	 ///< 搜索的关键字.
		int64 startTime;	 ///< 搜索消息的最小时间,不能大于endTime，单位秒.
		int64 endTime;	     ///< 搜索消息的最大时间,0为搜索全部时间段, 单位秒.
		MatchFunc func;	///< 传入的匹配字符串的函数,为空时使用默认匹配方式
		CMD_SIZE();
	};

	/**
	 * \struct  req_addToBWlist 消息号　logic_cmd_addToBWlist
	 * \brief 添加用户到黑名单或白名单
	 */
	struct req_addToBWlist : public _sdkcmd_base
	{
		req_addToBWlist() :type(1), enterpriseId(0)
		{}
		int8 type;					 ///< 操作类型，1.黑名单 2.白名单.
		std::vector<int64> memList;	 ///< 添加到名单的成员ID集合.
		int64 enterpriseId;			 ///< 企业ID，当type为2时设置.

		void init()
		{
			memList.clear();
		}
		CMD_SIZE();
	};

	/**
	 * \struct  req_removeFromBWlist 消息号　logic_cmd_removeFromBWlist
	 * \brief 把用户从黑名单或白名单中移除
	 */
	struct req_removeFromBWlist : public _sdkcmd_base
	{
		req_removeFromBWlist() :type(1), enterpriseId(0)
		{}
		int8 type;					 ///< 操作类型，1.黑名单 2.白名单.
		std::vector<int64> memList;	 ///< 移除的成员ID集合,为空时，代表清空名单中的所有用户.
		int64 enterpriseId;			 ///< 企业ID，当type为2时设置.

		void init()
		{
			memList.clear();
		}
		CMD_SIZE();
	};


	/**
	 * \struct  req_getBWlist 消息号　logic_cmd_getBWlist
	 * \brief 获取黑名单或白名单列表
	 */
	struct req_getBWlist : public _sdkcmd_base
	{
		req_getBWlist() :type(1), enterpriseId(0)
		{}

		int8 type;					 ///< 操作类型，1.黑名单 2.白名单.
		int64 enterpriseId;			 ///< 企业ID，当type为2时设置.
		CMD_SIZE();
	};

	/**
	 * \struct  req_delMsg 消息号: logic_cmd_delMessage,logic_cmd_cleanClientData,logic_cmd_delEraserMessage复用此结构
	 * \brief 删除消息结构体 时间上的单位为毫秒
	 * 使用示例:
	 * (1) 删除所有用户的所有时间的消息
	 * 　　　　req_delMsg　param ; ///使用默认值，targetID = 0 ;startTime = endTime = 0;
	 *     bSyncSrv 有效，true为同步删除服务器数据，false为只删除客户端数据.
	 * (2) 删除某个用户(ID=10000)所有的消息
	 *     req_delMsg　param ;
	 *     param.targetID = 10000 ;
	 *	　　　param.startTime = param.endTime = 0 ;
	 *	   bSyncSrv 有效，true为同步删除服务器数据，false为只删除客户端数据.
	 * (3) 删除所有用户某段时间内（st，et）的消息
	 *     param.targetID = 0 ;
	 *     param.startTime = st ;
	 *     param.endTime = et ;
	 * (4) 删除某个用户(ID=10000)下的一些消息(消息号为；10000:10001),如果bSyncSrv为true，传入的msgId对应的消息必须为阅后即焚消息
	 *     param.targetID = 10000 ;
	 *     param.idVt.push_back(10000);
	 *	   param.idVt.push_back(10001);
	 *　(5) 删除某个用户(ID=10000)某段时间(st,et)内的消息
	 *     param.targetID = 10000 ;
	 *     param.startTime = st ;
	 *     param.endTime = et ;
	 *　(6) 删除某个用户(ID=10000)某段时间(st,et)内的消息
	 *     param.targetID = 10000 ;
	 *     param.startTime = st ;
	 *     param.endTime = et ;
	 *
	 * 就以上５种组合方式，其他组合方式暂不支持。
	 */
	struct req_delMsg : public  _sdkcmd_base
	{
		req_delMsg() :targetID(0), startTime(0), endTime(0), bDelContact(false) {}
		int64   targetID;     ///< 删除消息的目标ＩＤ,targetID = 0 为删除所有用户.
		int64 startTime;		///< 起始时间,不能大于endTime，单位毫秒.
		int64 endTime;		///< 结束时间,搜索全部时间段, 单位毫秒,endTime＝０为删除所有时间段的消息.
		std::vector<int64>      idVt; ///< 删除消息的ＩＤ列表.		
		bool     bSyncSrv ;   ///< 是否同步到服务器. 如果是阅后即焚设置为TRUE.
		bool     bDelContact; ///< 当targetID=0时，表示是否删除所有的最近联系人，为ture表示删除.
		void init()
		{
			idVt.clear();
			bSyncSrv = false;
		}
		CMD_SIZE();
	};

	/**
	 * \struct  req_chatTop 消息号　logic_cmd_chatTop
	 * \brief 聊天置顶
	 */
	struct req_chatTop : public  _sdkcmd_base
	{
		req_chatTop() :targetId(0), type(0)
		{}

		int64 targetId;		///< 操作的目标ID.
		int8 type;			///< 操作类型 0不置顶 1置顶.

		CMD_SIZE();
	};
	/**
	* \struct  req_showVerifyUserPassword 消息号　logic_cmd_showVerifyUserPassword
	* \brief 获取注销验证码
	*/
	struct req_showVerifyUserPassword : public _sdkcmd_base
	{
		req_showVerifyUserPassword(){}
		void init(){
			password = "";
		}
		std::string password;
		CMD_SIZE();
	};
	/**
	* \struct  req_getLogoutCode 消息号　logic_cmd_LogoutCode
	* \brief 获取注销验证码
	*/
	struct req_getLogoutCode : public _sdkcmd_base
	{
		req_getLogoutCode() :logout_mode (1),type(0)
		{}
		void init(){
			logout_mode = 1;
			type = 0;
			password = "";
			authenticationCode = "";
		}
		int8 logout_mode;
		int8 type;
		std::string password;
		std::string authenticationCode;
		CMD_SIZE();
	};


	/**
	* \struct  req_getLogoutCode 消息号　logic_cmd_LogoutCode
	* \brief 注销验证
	*/
	struct req_setLogoutAccount : public _sdkcmd_base
	{
		req_setLogoutAccount()
		{}
		std::string authenticationCode;
		int type;
		CMD_SIZE();
		void init(){
			type = 0;
			authenticationCode = "";
		}
	};

	/**
	 * \struct  req_setUserSetting 消息号　logic_cmd_setUserSetting
	 * \brief 特定用户信息设置(是否显示在线，设置用户被查找方式(豆豆号，手机号等),新消息提醒方式等)
	 */
	struct req_setUserSetting : public  _sdkcmd_base
	{
		req_setUserSetting() :type(1), flag(0)
		{}
		/**
		 * \brief
		 *  type = 1: 设置是否显示在线信息 flag: 0显示 1不显示 默认0 
		 *  type = 3: 设置豆豆号查找 flag: 0允许 1不允许 默认0 
		 *  type = 4: 设置手机号查找 flag: 0允许 1不允许 默认0 
		 *  type = 5: 设置邮箱号查找 flag: 0允许 1不允许 默认0 
		 *  type = 6: 设置分享更新   flag: 0提示更新 1不提示更新 默认0 
		 *  type = 7: 新消息通知是否提醒 flag: 0提醒 1不提醒 默认0 
		 *  type = 12: 多服务新消息通知是否提醒 flag: 0不始终提示 1始终提示 默认0
		 *  type = 13: 多服务设置V标好友始终提醒 flag: 0不始终提示 1始终提示 默认0
		 *  type = 14: 多服务设置设置@相关人始终提醒 flag: 0不始终提示 1始终提示 默认0
		 *  type = 22: 设置昵称查找 flag: 0允许 1不允许 默认0 
		 *  type = 23: 设置应用管理权限 0 无权限 1 有权限 默认 0
		 */
		int32 type;	
		int8 flag;
		CMD_SIZE();
	}; 

	/**
	* \struct  req_getUserSetting 消息号　logic_cmd_getUserSetting
	* \brief 获取特定用户信息(是否显示在线，设置用户被查找方式(豆豆号，手机号等),新消息提醒方式等)
	*/
	struct req_getUserSetting : public  _sdkcmd_base
	{
		req_getUserSetting() :type(0)
		{}
		/**
		* \brief
		* 通过类型得到设置信息，返回值为resp_commonResult的value_i64字段.
		* 如果type = 0 ,返回所有字段，每个字段所占的位于type向对应。(如是否在线.
		* 信息type为1，则返回值为value_i64第一位. 
		*/
		int32 type;
		CMD_SIZE();
	};

	/**
	 * \struct  req_msgImport 消息号　logic_cmd_msgImport
	 * \brief 导入外部聊天消息
	 */
	struct req_msgImport : public  _sdkcmd_base
	{
		std::vector<st_msgBean> messages;	///< 需要导入的消息.

		void init()
		{
			messages.clear();
		}

		CMD_SIZE();
	};

	/**
	 * \struct  req_getFileInfos 消息号　logic_cmd_getFileInfos
	 * \brief 得到保存文件信息
	 */
	struct req_getFileInfos : public  _sdkcmd_base
	{
		std::vector<int64> fileMsgIds;	 ///< 需要获取的文件消息ID.

		void init()
		{
			fileMsgIds.clear();
		}

		CMD_SIZE();
	};


	/**
	 * \struct req_offlineLogin  消息号: logic_cmd_offlineLogin
	 * \brief 离线登录结构体
	 */
	struct req_offlineLogin : public _sdkcmd_base
	{
		req_offlineLogin() :userID(0) {}
		int64        userID;  ///< 用户ＩＤ 如果为零，获取最近一次登录成功的用户ＩＤ.
		std::string  pwd ;    ///< 密码.
        std::string  elogo;   ///< 服务器标识
		void init(){;}
		CMD_SIZE();
	};

	/**
	 * \struct  req_getMsgByType 消息号　logic_cmd_getMsgByType
	 * \brief 根据消息类型获得聊天消息
	 */
	struct req_getMsgByType : public _sdkcmd_base
	{
		req_getMsgByType() :targetId(0), msgType(0){}
		int64 targetId;			///< 个人或群ID.
		int8 msgType;			    ///< 获取的消息类型.
		CMD_SIZE();
	};

	/**
	 * \struct  req_getUrlInfo 消息号　logic_cmd_getUrlInfo
	 * \brief 获取网址缩略图信息
	 */
	struct req_getUrlInfo : public _sdkcmd_base
	{
		std::string url;			///< 网址url.
		std::string loginfoPath ;       ///< 登录文件路径
		CMD_SIZE();
	}; 

	/**
	 * \struct  req_faceToFaceJoin 消息号　logic_cmd_faceToFaceJoin
	 * \brief 近距离加好友、群
	 * 
	 * 根据type取值不同进行不同操作:
	 * 1: 创建近距离建群/加好友的房间。根据传入经度, 纬度, 创建房间。 
	 *	  传入参数： st_faceToFaceBean  房间信息,不填password，由服务器生成
	 *    返回：
	 *		code:　0:成功，100:参数错误，11100:内部错误
	 *		resp_faceToFaceJoin 含有randomCode,即服务器产生的password
	 *　		
	 * 2: 加入近距离建群房间。根据传入经度、纬度、房间密码，搜索缓存队列是否存在房间。
	 *    存在：加入房间人员队列，推送通知，通知房间其他人，此人加入此房间返回房间信息和人员队列 
	 *    不存在：返回房间不存在
	 *	  传入参数: st_faceToFaceBean 房间信息,需要填password
	 *	   返回：
	 *	 	code:　0:成功，100:参数错误，11100:内部错误
	 *		resp_faceToFaceJoin
	 *
	 * 3: 退出近距离建群房间。根据房间ID，检索房间信息，看人员是否是创建者
 	 *	  是：删除此房间，推送通知，通知人员队列人员，房间删除
	 *    否：删除此队列中此人员，推送通知，通知其他人员，此人退出房间
   	 *    传入参数： userId, roomId
	 *	  返回:
	 *　	    code:　0:成功，100:参数错误，11100:内部错误
	 *
	 * 4: 近距离建群。根据房间ID，判断房间队列是否存在。
	 *    传入参数： userId，roomId
 	 *				groupLevel等级，userList加入群的用户列表
	 *
	 *		 返回：
	 *　　	code: 0:成功，100:参数错误，302:没有权限创建群（非管理员）
	 *	          344:创建群失败，345:房间不存在，11100:内部错误
	 *
	 * 5: 加入近距离加好友房间。根据传入经度、纬度、房间密码，搜索缓存队列是否存在房间。
	 *    存在：检测与房间主是否是好友，如果是返回已经是好友关系
     *  	　　加入房间人员队列，推送通知给房间创建者，此人加入此房间,返回房间信息和房主信息
     *  不存在：创建房间人员队列,返回房间信息,人员队列的第一个人为创建者。
   	 * 传入参数： st_faceToFaceBean 房间信息,需要填password
	 *	  返回：
	 *		code:　0:成功，100:参数错误，11100:内部错误
	 *　　			resp_faceToFaceJoin
   	 *
	 * 6: 退出近距离加好友房间。根据房间ID，检索房间信息，看人员是否是创建者
	 *	  是：删除此房间，推送通知，通知人员队列人员，房间删除
	 *    否：删除此队列中此人员，推送通知，通知房主，此人退出房间
	 *    传入参数：userId , roomId
	 *    返回:
	 *		code: 0:成功，100:参数错误，11100:内部错误
	 * 
	 * 7: 近距离加好友。根据房间ID，判断房间队列是否存在，
	 *	  调用消息盒子服务，批量给成员发添加好友验证请求。
	 * 传入参数: userId ,roomId, verifyInfo，userList
	 *   返回：
	 *   	code: 0:成功，100:参数错误，340:没有权限操作（非管理员）
	 *           556:操作失败，345:房间不存在，11100:内部错误
	 */
	struct req_faceToFaceJoin : public _sdkcmd_base
	{
		req_faceToFaceJoin() :type(0), userId(0), groupLevel(0)
		{
			INIT_ISSET(userId)
			INIT_ISSET(roomId)
			INIT_ISSET(verifyInfo)
			INIT_ISSET(userList)
			INIT_ISSET(faceToFace)
			INIT_ISSET(groupLevel)
			INIT_ISSET(groupName)
		}
		void init()
		{
			userList.clear();
			faceToFace.init();
			INIT_ISSET(userId)
			INIT_ISSET(roomId)
			INIT_ISSET(verifyInfo)
			INIT_ISSET(userList)
			INIT_ISSET(faceToFace)
			INIT_ISSET(groupLevel)
			INIT_ISSET(groupName)
		}

		int8 type;							///< 操作类型.
		IS_SET(int64, userId)					///< 用户ID.
		IS_SET(std::string, roomId)				///< 房间ID.
		IS_SET(std::string, verifyInfo)			///< 加好友验证信息.
		IS_SET(std::vector<int64>, userList)   	///< 用户Id列表.
		IS_SET(st_faceToFaceBean, faceToFace)	///< 详细信息.
		IS_SET(int8, groupLevel)				///< 群等级，创建群时使用.必须传 
		IS_SET(std::string, groupName)			///< 群等级，创建群时使用.必须传 
		
		CMD_SIZE();
	};

	/**
	* \struct req_delDelayMsg
	* \brief 删除延时消息使用 消息号 logic_cmd_delDelayMsg
	*
	*/
	struct  req_delDelayMsg : public _sdkcmd_base{
		req_delDelayMsg() :targetID(0), msgID(0) {}
		int64   targetID;   ///< 该消息所属用户/群ID.
		int64  	msgID;     ///< 删除消息号.
		CMD_SIZE();
	};

	/**
	* \struct req_updateDelayMsg
	* \brief 更新自己的消息 消息号 logic_cmd_updateDelayMsg
	*
	*/
	struct  req_updateDelayMsg : public _sdkcmd_base {
		req_updateDelayMsg() :targetID(0) {}
		int64   targetID;  ///< 该消息所属用户/群ID.
		st_msgBean  msg;   ///< 更新消息信息.
		CMD_SIZE();
	};


	/**
	* \struct  req_authenticationParam 消息号　logic_cmd_bindEmailOrPhoneNumber1
	* \brief 绑定手机号第1步 请求绑定手机号
	* 返回：code 0: 操作成功/验证码正确（发送成功）	 100:参数不正确
	* 381: 未指定接收者			                   382: 未指定接收者类型
	* 383: 验证码已过期			                   384: 验证码不正确
	* 385: 发送间隔时间太短			               386: 发送失败
	* 387: 未发送过验证码
	*/
	struct req_authenticationParam : public _sdkcmd_base
	{
		req_authenticationParam() :operation(0), userType(0)
		{

		}
		int8 userType;			///<  账号类型 1 手机  2 EMAIL
		int8 operation;			///< 1. 绑定.
		std::string phone;		    ///< 手机号.
		std::string language;      ///< 语言.

		CMD_SIZE();
	};

	/**
	* \struct  req_authenticationServerCode 消息号　logic_cmd_bindEmailOrPhoneNumber2
	* \brief 绑定手机号第2步，验证验证码
	* 返回：code　0: 操作成功/验证码正确（发送成功）	100:参数不正确
	*　　120: 帐号不存在			                  381: 未指定接收者
	*    382: 未指定接收者类型            	         383: 验证码已过期
	*    384: 验证码不正确 			              385: 发送间隔时间太短
	*    386: 发送失败 			                   387：未发送过验证码
	*/
	struct req_authenticationServerCode : public _sdkcmd_base
	{
		req_authenticationServerCode() :operation(0), registryID(0), userType(0)
		{
		}
		int8 userType;		///<  账号类型 1 手机  2 EMAIL
		int8 operation;   ///< 1: 绑定 2: 解绑.
		int64 registryID; ///< 第一步返回的　registryID （豆豆ID）.
		std::string code; ///< 验证码.
		CMD_SIZE();
	};

	/**
	* \struct  req_MultiOpSTParam 消息号　logic_cmd_bindEmailOrPhoneNumber3
	* \brief 绑定手机号第3步，绑定手机号或邮箱
	返回：code　0:成功，100:参数错误，120: 帐号不存在，510:帐号已被使用
	*/
	struct req_MultiOpSTParam : public _sdkcmd_base
	{
		req_MultiOpSTParam() :type(0), operation(0), registryID(0)
		{
		}
		int8 type;         ///< 1：绑定手机 2：绑定邮箱.
		int8 operation;    ///< 1: 绑定 2: 解绑.
		int64 registryID;  ///< 需要验证的那些都需要填写.
		std::string code;
        std::string language;
		CMD_SIZE();
	};

	/**
	* \struct  req_setNoDisturbMode 消息号　logic_cmd_setNoDisturbMode
	* \brief 设置全局勿扰模式开关信息
	*/
	struct req_setNoDisturbMode : public _sdkcmd_base
	{
		req_setNoDisturbMode():type(0) {}
		void init()
		{
			disturbList.clear();
			type = 0;
		}
		std::vector<st_NoDisturbModeInfo> disturbList;
        int8 type;    //0表示老接口请求，只设置单个时间段免打扰，1表示新接口请求，可以设置多条list

		CMD_SIZE();
	};

	/**
	* \struct  req_setUserToTargetSwitch 消息号　logic_cmd_setUserToTargetSwitch
	* \brief 设置个人对目标用户的勿扰模式
	*/
	struct req_setUserToTargetSwitch : public _sdkcmd_base
	{
		req_setUserToTargetSwitch() :targetId(0), type(1), value(1)
		{
		}

		int64 targetId;	    ///< 用户ID.
		int8  type;		    ///< 设置类型 1:个人设置项 2:个人通知消息详情模式.
		/** 
		 * \brief 类型值
		 * 1:个人设置项, value: 1为接收提醒 2表示不提醒仅显示数字 3:为免打扰, 默认1
		 * 2:个人通知消息详情模式, value:1、通知详情 2、通知源，隐藏内容 3、完全隐藏 默认开启模式1
		 */
		int8  value;	

		CMD_SIZE();
	}; 
	
		/**
		* \struct  req_getUserToTargetSwitch 消息号　logic_cmd_getUserToTargetSwitch
		* \brief 获取个人对目标用户的勿扰模式
		*/
	struct req_getUserToTargetSwitch : public _sdkcmd_base
	{
		req_getUserToTargetSwitch() :targetId(0), type(0)
		{
		}

		int64 targetId;	    ///< 获取的用户ID.
		int8 type;		    ///< 获取的设置类型 0:获取全部 1:个人设置项 2:个人通知消息详情模式.

		CMD_SIZE();
	};

	/**
	* \struct  req_postContact 消息号　logic_cmd_postContact
	* \brief 上传通讯录
	*/
	struct req_postContact : public _sdkcmd_base
	{
		req_postContact() :flag(1)
		{
		}

		void init()
		{
			postContact.clear();
		}

		std::vector<st_contactBean> postContact;
		int8 flag;		  ///< 1 服务器推荐逻辑 2 添加通讯录好友.

		CMD_SIZE();
	};

	/**
	* \struct  req_shareOption 消息号　net_cmd_updateShareOption
	* \brief 前端用户设置分享列表
	*/
	struct req_shareOption : public _sdkcmd_base
	{
		req_shareOption()
		{
			shareOpt.clear();
		}
		std::vector<st_shareOptionBean> shareOpt;

		CMD_SIZE();
	};

	/**
	* \struct  req_sharedType 消息号　logic_cmd_getShareOption
	* \brief 前端用户设置分享列表
	*/
	struct req_sharedType : public _sdkcmd_base
	{
		req_sharedType(): sharedType(0) {}
		int8 sharedType;  ///< 要查询的类型：1为不让他人看我的分享，2为不看他的分享.

		CMD_SIZE();
	};

	/**
	* \struct  req_personDefinitionParam 消息号　logic_cmd_setPersonDefinition
	* \brief   用户自定义一些信息， 目前只表示声音
	*/
	struct req_personDefinitionParam : public _sdkcmd_base
	{
		req_personDefinitionParam()
		{
			personDef.defType = 0;
			INIT_ISSET(userID)
		}
		IS_SET(int64, userID) ///< 可以设置其他用户， 不设置默认为自己.
		st_personDefinition personDef;

		CMD_SIZE();
	};

	/**
	* \struct  req_getPersonDef 消息号　 logic_cmd_getPersonDefinition
	* \brief   得到用户自定义一些信息
	*/
	struct req_getPersonDef : public _sdkcmd_base
	{
		req_getPersonDef() : defType(0)
		{
			INIT_ISSET(userID)
		}
		IS_SET(int64, userID) ///< 可以设置其他用户， 不设置默认为自己.
		int8 defType;         
		
		CMD_SIZE();
	};
	
		/**
	* \struct  req_queryExtendedField 消息号　logic_cmd_queryExtendedField
	* \brief  根据条件查询拓展字段信息,根据dicKey和parentId共同查询拓展字段，当parentId为-1时表示查询所有的拓展字段,parentId为-2时表示按dicKey查询
	*/
	struct req_queryExtendedField : public _sdkcmd_base
	{
		req_queryExtendedField()
		{
			dicKey = "";
			parentId = 0;
		}
		std::string dicKey;        ///< Key值
		int64 parentId;            ///< 父组织ID

		CMD_SIZE();
	}; 

	/**
	* \struct  req_setUserGroupImage 消息号　logic_cmd_setUserGroupImage
	* \brief  设置成员群背景图片
	*/
	struct req_setUserGroupImage : public _sdkcmd_base
	{
		req_setUserGroupImage() :groupID(0)
		{

		}
		int64 groupID;
		std::string userBackgroundURL;

		CMD_SIZE();
	};

	/**
	* \struct  req_getUserGroupImage 消息号　logic_cmd_getUserGroupImage
	* \brief  获取成员群背景图片
	*/
	struct req_getUserGroupImage : public _sdkcmd_base
	{
		req_getUserGroupImage() :groupID(0)
		{

		}
		int64 groupID;

		CMD_SIZE();
	};
	

	/**
	* \struct  req_setGroupBeepTone 消息号　logic_cmd_setGroupBeepTone
	* \brief  设置成员群提示音信息
	*/
//#if (defined __aarch64__) && (defined SDK_FOR_ANDROID)
//#pragma pack(push) //保存对齐状态
//#pragma pack(8)//设定为8字节对齐
//#endif
	struct req_setGroupBeepTone : public _sdkcmd_base
	{
		req_setGroupBeepTone() :groupID(0)
		{

		}
		int64 groupID;
		std::string userGroupBeepInfo;

		CMD_SIZE();
	};
//#if (defined __aarch64__) && (defined SDK_FOR_ANDROID)
//#pragma pack(pop)
//#endif

	/**
	* \struct  req_getGroupBeepTone 消息号　logic_cmd_getGroupBeepTone
	* \brief  获取群提示音信息
	*/
	struct req_getGroupBeepTone : public _sdkcmd_base
	{
		req_getGroupBeepTone() :groupID(0)
		{

		}
		int64 groupID;

		CMD_SIZE();
	};


	/**
	 * \struct req_p2pTransferCancle 消息号 logic_cmd_p2pFileTransCancle
	 * \brief P2P文件传输操作 , 如果选择接收，接收端推送上来的进度标识就为本条消息的LOCALid
	 */
	struct req_p2pTransferCancle : public _sdkcmd_base
	{
		req_p2pTransferCancle() :taskID(0) {}
		int64  taskID ;	///< 接收到请求推送里面的.
		CMD_SIZE();
	};


	/**
	* \struct req_queryMarketApplication 消息号 logic_cmd_queryMarketApplication
	* \brief  应用市场分页查询条件添加群应用
	*/
	struct req_queryMarketApplication : public _sdkcmd_base
	{
		req_queryMarketApplication() :pageNum(0), pageSize(0), deviceType(0), jsonStr(""), releaseType(0), gettype(0)
		{
			INIT_ISSET(appName)
		}

		void init()
		{
			INIT_ISSET(appName)
		}
		int32 pageNum;                 ///< 页码.
		int32 pageSize;                ///< 页长.
		int32 deviceType;              ///< 类型 2（IOS），3（Android）.
		IS_SET(std::string, appName)    ///< 应用名称 模糊查询用.
		std::string jsonStr;     ///< json字符串，内部实体，根据查询类型解析
		int8 releaseType;        ///<查询类型;1.工作台应用市场展示应用,3.群应用
		int8 gettype;            ///<是否获取全部应用，默认为0，不获取全部，1 获取全部
		CMD_SIZE();
	};

	/**
	* \struct req_queryTrackInfo 消息号 logic_cmd_queryTrackInfo
	* \brief  应用轨迹查询
	*/
	struct req_queryTrackInfo : public _sdkcmd_base
	{
		req_queryTrackInfo():appID(0)
		{
	       
		}

		int64 appID;            ///应用ID
		std::string trackMsg;              ///< 位置轨迹消息

		CMD_SIZE();
	};
	/**
	* \struct req_addOrDeleteApplication 消息号 logic_cmd_addOrDeleteApplication
	* \brief 添加或删除应用
	*/
	struct req_addOrDeleteApplication : public _sdkcmd_base
	{
		req_addOrDeleteApplication() :type(0), appID(0)
		{

		}
		int8 type;    ///< 2.添加应用  4.删除应用.
		int64 appID;

		CMD_SIZE();
	};

	/**
	* \struct req_IgnoreMarketApp 消息号 logic_cmd_IgnoreMarketApp
	* \brief 忽略/添加群应用
	* \add by jss
	*/
	struct req_IgnoreMarketApp : public _sdkcmd_base
	{
		req_IgnoreMarketApp() :relationId(0), vestAppId(0), relationIdType(0), operatorId(0), operatorType(0){}
		/* 操作关联ID */
		int64 relationId;
		/* 应用号ID */
		int64 vestAppId;
		/* 关联ID类型;1.用户 2.群 */
		int64 relationIdType;
		/* 操作者ID */
		int64 operatorId;
		/* 操作类型1添加 2忽略 */
		int8 operatorType;
		CMD_SIZE();
	};

	/**
	* \struct req_emoticonUnionOne 消息号 logic_cmd_emoticonUnionOne
	* \brief 表情包一期的请求集合
	*/
	struct req_emoticonUnionOne : public _sdkcmd_base
	{
		req_emoticonUnionOne()
		{
			init();
		}

		void init()
		{
			type = 0;
			bIsRead = 0;
			vecStr.clear();
			emotPackageList.clear();
			emoticonList.clear();
		}
		int8 type;    ///< 1,删除表情包 2,设置表情包已读 3,从网络获取信息增加表情包 4,从客户端获取信息增加表情包
		int8 bIsRead;
		std::string packMdCode;
		std::vector<std::string> vecStr;
		std::vector<st_emoticonPackage> emotPackageList;
		std::vector<st_emoticon>  emoticonList;

		CMD_SIZE();
	};

	/**
	* \struct getInstalledApplication 消息号 logic_cmd_getInstalledApplication
	* \brief  获取用户已安装列表信息
	*/
	struct req_getInstalledApplication : public _sdkcmd_base
	{
		req_getInstalledApplication() :deviceType(0)
		{

		}
		int32 deviceType; ///< 2.IOS 3.Android.

		CMD_SIZE();
	};

	
	/**
	* \struct req_getEntAppInfo 消息号 logic_cmd_getEntAppInfo
	* \brief  分页获取企业号或应用号
	*/
	struct req_getEntAppInfo : public _sdkcmd_base
	{
		req_getEntAppInfo() : type(0), pageNum(0), pageSize(0)
		{

		}
		void init()
		{
			type = 0;
			pageNum = 0;
			pageSize = 0;
		}
		int8  type;             ///< 1.企业号 2.应用号
		int32 pageNum;          ///< 页码，从1开始
		int32 pageSize;         ///< 每页大小
		CMD_SIZE();
	};

	/**
	* \struct req_getMarketAppSort 消息号 logic_cmd_getMarketAppSort
	* \brief  获取应用市场应用分类集合
	*/
	struct req_getMarketAppSort : public _sdkcmd_base
	{
		req_getMarketAppSort()
		{
			filterCondition.clear();
		}

		void init()
		{
			filterCondition.clear();
		}
		std::map<std::string, std::string> filterCondition; ///< 过滤条件，暂时没有过滤条件
	};


	/**
	* \struct req_getAuthAccessToken 消息号 logic_cmd_getAuthAccessToken
		传入参数：
		appID         应用ID（appID）
		accountType   登陆账号类型（accountType）
		appSecret     企业应用秘钥一个凭证
	返回：code : 0 : 成功，100 : 参数错误，11100 : 内部错误; 其他值是java内部错误码
			  - 1:系统繁忙
			  10001 : 获取access_token时AppSecret错误，或者access_token无效
			  10002 : 不合法的appID
			  10003 : 不合法的获取访问凭证类型
			  10004 : 不合法的access_token
			  10009 : UserID不存在
			  11001 : 缺少应用标识参数
			  11002 : 缺少应用名称参数
			  11003 : 缺少appID参数
			  11004 : 缺少appSecret参数
			  11005 : 缺少access_token参数
			  12001 : access_token超时
			  13001 : 需要接收者关注
			  14001 : POST数据包为空
			  14002 : 用户账号参数为空
			  14003 : 消息内容为空
			  15001 : 应用标识超过长度限制
			  15002 : 应用名称超过长度限制
			  15003 : 消息内容超过长度限制
			  16001 : 企业ID不存在
			  16002 : 不存在的用户
			  16003 : 企业应用不存在
			  16004 : 用户不存在企业中
			  20001 : 企业应用服务器未响应
			  20002 : 企业应用服务器验证未通过
			  30001 : 企业应用服务器响应url不存在。
			  80001 : 认证码Code失效
			  80002 : AccessToken失效
			  80003 : 获取用户信息失败
		  what : 授权凭证(accessToken（默认90天))
	*/
	struct req_getAuthAccessToken : public _sdkcmd_base
	{
		void init()
		{
			appID = 0;
			accountType = "";
			appSecret = "";
		}
		int64 appID;               ///应用ID
		std::string accountType;   ///账号类型
		std::string appSecret;     ///企业应用秘钥一个凭证,如果appSecret为空，表示获取授权码，如果不为空表示获取授权凭证
		CMD_SIZE();
	};
	/**
	* \struct req_checkOrRefreshAccessToken 消息号 logic_cmd_checkOrRefreshAccessToken
	type:
		10, 校验accessToken是否过期
			传入参数：
			appID         应用ID（appID）
			accessToken   授权凭证（accessToken，上一步骤获取的）
			返回：code 0:未过期，100 : 参数错误，11100 : 内部错误，80002：已过期
			what "Access Token 已过期" or "Access Token 验证通过"
		11, 刷新accessToken有效期
		传入参数：
		appID         应用ID（appID）
		accessToken   授权凭证（accessToken）
		返回：code 参考req_getAuthAccessToken
		what 新accessToken
	*/
	struct req_checkOrRefreshAccessToken : public _sdkcmd_base
	{
		req_checkOrRefreshAccessToken() :type(0), appID(0) {}
		int type;                 /// 10,校验accessToken是否过期 11刷新accessToken,获得新的accessToken
		int64 appID;              ///应用ID
		std::string accessToken;  ///app授权凭证
		CMD_SIZE();
	};

	/**
	* \struct req_getAuthUserBean 消息号 logic_cmd_getAuthUserBean，logic_cmd_checkQrDevice，logic_cmd_authPcBrowserLoginTokenCheck复用
	* \brief  根据应用授权凭证获取用户信息
	*/
	struct req_getAuthUserBean : public _sdkcmd_base
	{
		req_getAuthUserBean() :appID(0) {}
		int64 appID;               ///应用ID（appID）
		std::string accessToken;  ///app授权凭证
		CMD_SIZE();
	};

	/**
	* \struct req_webSiteAuth 消息号 logic_cmd_webSiteAuth
	* \brief  根据网址链接获取授权码，返回的授权码会拼接到网址后面返回,格式为uri&auth_code=授权码或者uri?auth_code=授权码。
	* 要求：
	* 1.webSite中必须有"/conn/oauth?id=","&st=","&sc=","&uri="这些字段,否则认为不是合法的网址，返回错误，code值对应err_sdk_paramInvalidat宏表示的值；
	* 2.如果uri为空，则根据解析出来的appID获取app的首页地址作为uri的地址。
	* 3.如果根据解析出来的appID获取不到app信息，则可能该appID不属于app，则返回code为err_sdk_paramInvalidat宏表示的值。
	* 如：入参：http(s) ://vrv.linkdood/conn/oauth?id=4328614468&st=STATE&sc=SCOPE&uri=xxxxxx
	*     出参：xxxxxx&auth_code=yyyyyy
	* 如果xxxxxx里有?，则用返回xxxxxx&auth_code=yyyyyy否则返回xxxxxx?auth_code=yyyyyy
	*/
	struct req_webSiteAuth : public _sdkcmd_base
	{
		std::string webSite;  ///网址链接
		CMD_SIZE();
	};

	/**
	* \struct req_queryEmotion 消息号 logic_cmd_queryEmoticon
	* \brief  单个表情查询、根据表情包标识查询表情，查询所有用户自定义表情
	*/
	struct req_queryEmoticon : public _sdkcmd_base
	{
		req_queryEmoticon() : type(0)
		{
			INIT_ISSET(mdCode)
		}
		/**
		 *1, 单个查询表情 mdCode表示单个表情的md5, 6,根据表情包标识查询所有表情 mdCode表示表情包的md5, 7,查询用户所有自定义表情 这里mdCode不传值
		 */
		int8 type;               
		IS_SET(std::string, mdCode);      ///< 单个表情或者表情包的md5Code.

		CMD_SIZE();
	};

	/**
	* \struct req_querySingleEmoticon 消息号 logic_cmd_querySingleEmoticon
	* \brief  查询某个表情包里单个表情信息
	*/
	struct req_querySingleEmoticon : public _sdkcmd_base
	{
		req_querySingleEmoticon()
		{

		}
		std::string packMdCode;    ///< 表情包mdCode
		std::string mdCode;        ///< 包内单个表情mdCode

		CMD_SIZE();
	};

	/**
	* \struct req_singleQueryEmoticonPackage 消息号 logic_cmd_singleQueryEmoticonPackage
	* \brief  单个查询表情包
	*/
	struct req_singleQueryEmoticonPackage : public _sdkcmd_base
	{
		req_singleQueryEmoticonPackage()
		{

		}
		std::string mdCode;            ///< 单个查询表情包的mdCode.

		CMD_SIZE();
	};

	/**
	* \struct req_pageQueryEmoticon 消息号 logic_cmd_pageQueryEmoticon
	* \brief  分页查询表情包
	*/
	struct req_pageQueryEmoticon : public _sdkcmd_base
	{
		req_pageQueryEmoticon() :pageNum(0), pageSize(0), LocalEmoServTs(0)
		{

		}
		int64 LocalEmoServTs;
		int32 pageNum;                 ///< 页码.
		int32 pageSize;                ///< 页长.
		CMD_SIZE();
	};

	/**
	* \struct req_addOrDeleteCustomEmoticon 消息号 logic_cmd_addOrDeleteCustomEmoticon
	* \brief  增加或删除用户自定义表情
	*/
	struct req_addOrDeleteCustomEmoticon : public _sdkcmd_base
	{
		req_addOrDeleteCustomEmoticon() : type(0)
		{

		}
		int8 type;            ///< 4 增加， 5删除.
		st_emoticon emot;
		CMD_SIZE();
	};

	/**
	* \struct req_labelQueryEmoticonPackage 消息号 logic_cmd_labelQueryEmoticonPackage
	* \brief  根据表情包标签查询相关表情包集合
	*/
	struct req_labelQueryEmoticonPackage : public _sdkcmd_base
	{
		req_labelQueryEmoticonPackage()
		{

		}
		std::string label;     ///< 表情包标签.
		CMD_SIZE();
	};

	/**
	*
	* \brief 查询机器人（公众号）时间戳，查询数据字典时间戳 消息号 logic_cmd_queryAppOrDictTimestamp
	1, 单个查询机器人（公众号）时间戳
	2, 查询数据字典时间戳 查询字典时间戳appID不用赋值
	*/
	struct req_queryAppOrDictTimestamp : public _sdkcmd_base
	{
		req_queryAppOrDictTimestamp() : type(0), appID(0),modeType(0)
		{

		}
		int8  type;    //1.机器人（公众号） 2.字典
		int64 appID;   //机器人ID
        int64 modeType;
		CMD_SIZE();
	};

	/**
	* \struct resp_setUnReadCount 消息号 logic_cmd_setUnReadCount
	* \brief 设置客户端消息未读数量
	*/
	struct req_setUnReadCount : public _sdkcmd_base
	{
		req_setUnReadCount():type(0),count(0){}
		int8  type;             ///< 0,设置未读数，默认值，客户端可以不用设置该值.
		int32 count;            ///< 未读数量.
		std::string appleID;     ///< 应用id，不同的应用所对应的证书是不一样的.
		std::string token;       ///< ios token.
		std::map<std::string, int32>  entUnread;  ///< 设置企业未读数 key：企业ID， value:消息未读数
		CMD_SIZE();
	};

	/**
	 *
	 */

	/**
	* \struct req_setMsgUnRead 消息号： logic_cmd_setMsgUnRead
	* \brief 设置最后一条已读为未读
	*/
	struct req_setMsgUnRead : public _sdkcmd_base
	{
		req_setMsgUnRead() : targetID(0)
		{

		}
		int64 targetID;        ///目标ID,如果targetID等于0表示设置的是系统消息
		CMD_SIZE();
	};

	/**
	* \struct req_updateDecryptedMsg 消息号 logic_cmd_updateDecryptedMsg
	* \brief  更新解密后的消息到数据库
	*/
	struct req_updateDecryptedMsg : public _sdkcmd_base
	{
		req_updateDecryptedMsg() :targetId(0), msgId(0) {}
		int64 targetId;
		int64 msgId;
		std::string message;
		std::string msgProperty;
		CMD_SIZE();
	};

	/**
	* \struct req_updateDeReconMsg 消息号 logic_cmd_updateDeReconMsg
	* \brief  更新解密后的最近联系人消息到数据库
	*/
	struct req_updateDeReconMsg : public _sdkcmd_base
	{
		req_updateDeReconMsg() :targetId(0) {}
		int64 targetId;
		std::vector<std::string> fieldparam;
		CMD_SIZE();
	};

	/**
	 * \struct req_quickRegister 消息 logic_cmd_quickRegister
	 * \brief 快速注册
	 */
	struct req_quickRegister : public _sdkcmd_base
	{
		req_quickRegister() :type(0) {}
		int8        type ;      ///< 1：电话, 3：邮箱, 4：userID, 5:身份证, 6：豆豆号, 7:自定义帐号(不做限制) .
		std::string name ; 	   ///< 名称/昵称.
		std::string account ;    ///< 账号.
		std::string password ;   ///< 密码.
		/**
 		   只填写 :
		* 1. area
		* 2. usrid 填0
		* 3. version
		* 4. device_info
		*/
		req_LoginParamBean login ; ///< 注册信息.
		
		CMD_SIZE();
	};


	/**
	* \struct req_setPrivateMsgPwd 消息 logic_cmd_setPrivateMsgPwd
	* \brief 设置私信密码
	*/
	struct req_setPrivateMsgPwd : public _sdkcmd_base
	{
		req_setPrivateMsgPwd():targetId(0){}
		int64 targetId;		    ///< 好友或群ID.
		std::string passward;		///< 私信密码  为空代表清除私信密码.
		CMD_SIZE();
	};

	/**
	* \struct req_getIdByAccount 消息 logic_cmd_getIdByAccount
	* \brief 通过账号名获取用户ID
	*/
	struct req_getIdByAccount : public _sdkcmd_base
	{
		void init()
		{
			accounts.clear();
		}
		std::vector<std::string> accounts;				///< 用户accountName集合.
		CMD_SIZE();
	};

	/**
	* \struct req_decryptMsg 解密消息 logic_cmd_decryptMsg
	*  brief 解密消息并更新到数据库
	*/
	struct req_decryptMsg : public _sdkcmd_base
	{
		req_decryptMsg():targetId(0){}
		int64 targetId;				///< 人或群ID.
		std::vector<int64> msgIds;     ///< 要解密的消息集合.
		void init()
		{
			msgIds.clear();
		}
		CMD_SIZE();
	};
	/**
	* \struct req_transferLocalData 导入导出数据 logic_cmd_transferLocalData
	*  brief 导入导出数据
	*/
	struct req_transferLocalData : public _sdkcmd_base{

		req_transferLocalData() :version("0.0.1"), year(0), mon(0), day(0){};
		std::string filePath;  ///< 要导入或导出文件的存放路径.

		std::string version;
		///导出时选择从那天开始. 
		int year;
		int mon;
		int day;
		int8 type;///< 0:导出;1:导入;2:南京数据迁移;3:不删除中间文件
		CMD_SIZE();
	};
	/**
	* \struct req_cmd_upMsgCount 上传消息计数  logic_cmd_upMsgCount
	*  brief 上传消息计数
	*/
	struct req_upMsgCount: public _sdkcmd_base{
		req_upMsgCount() :type(0){};
		int8 type;
		std::string PackName;///<包名
		std::string UserName;///<用户名
		std::string MsgNum;///<消息数
		std::string devtype;///<设备类型
		CMD_SIZE();
	};

	/**
	* \struct req_checkUrlValid 检查URL的是否有效  logic_cmd_checkUrlValid
	*  brief 检查URL的是否有效
	*/
	struct req_checkUrlValid : public _sdkcmd_base
	{
		std::string url;	///< 要检查的url，如果为相对路径，下层会自己拼接为完整路径
		CMD_SIZE();
	};

	/**
	* \struct req_forwardMessage 转发消息  logic_cmd_forwardMessage
	*  brief 转发消息
	*/
	struct req_forwardMessage : public _sdkcmd_base
	{
		req_forwardMessage() :fromTargetId(0), toTargetId(0), messageId(0), securityLevel(0) {}
		int64 fromTargetId;		///< 转发的消息的当前targetId
		int64 toTargetId;		///< 转发的消息的接收targetId
		int64 messageId;    ///< 转发的消息ID
		int32 timeZone;
		int32 securityLevel; //密级
		std::string userDef;	///< 客户端自定义内容
		void init()
		{
			securityLevel = 0;
			timeZone = 33;
			userDef.clear();
		}
		CMD_SIZE();
	};

	/**
	* \struct req_addRecontact 转发消息  logic_cmd_addRecontact
	*  brief 转发消息
	*/
	struct req_addRecontact : public _sdkcmd_base
	{
		st_reContact recontact;	///< 添加的最近联系人
		CMD_SIZE();
	};
	
	/**
	* \struct req_qVerifyCodes  消息号 logic_cmd_qVerifyCodes
	* \brief 邀请码相关
	* \type 操作类型 1 设备下线
        * \devtype设备  1：PC；2：手机；3：pad；4：网页
	 
	*/
	struct req_offline : public _sdkcmd_base
	{
		int8 type;
		int8 devtype;

		void init()
		{
			type = 0;
			devtype = 0;
		}
	
			CMD_SIZE();
	};

	/**
	* \struct req_getAllMsgCount 获取全部消息  logic_cmd_getAllMsgCount
	*  brief 获取全部消息
	*/
	struct req_getAllMsgCount : public _sdkcmd_base
	{
		req_getAllMsgCount() :targetId(0) {}
		int64 targetId;  ///< 为0代表获取所有聊天消息，不为0代表获取相应targetId的全部消息
		CMD_SIZE();
	};
	
	/**
	* \struct req_getMsgDays 获取消息日期数组  logic_cmd_getMsgDays
	*  brief 获取消息日期数组
	*/
	struct req_getMsgDays : public _sdkcmd_base
	{
		///对象ID
		int64   targetID ;
		///是否最近 0是最近 非零是要查询的年份
		int16    bLately  ; 
		void init() {
			bLately = 0 ;
			targetID = 0;		} 
		CMD_SIZE();
	};
	/**
	* \struct req_getMsgsFromDay 获取消息日期数组  logic_cmd_getMsgFromDay
	*  brief 获取消息日期数组
	*/
	struct req_getMsgsFromDay : public _sdkcmd_base
	{
		///对象ID
		int64   targetID ;
		///是否最近 0 是最近，非零的话要设置 YMD
		int8    bLately  ; 
		int64   msgID;          ///< 如果msgID为0则从大到小拉取消息
		int32   count;          ///< 拉取的消息数量,如果count为0，则拉取所有的
		void 	init() {
			bLately = 0 ;
			targetID = 0;
			msgID = 0; 
			count = 0; 
		} 
		///查询的天数
		YMD     ymd ;
		CMD_SIZE();
	};	
	/**
	* \struct req_agoraFunc  logic_cmd_getAgoraFunc
	*  brief  获取声网服务功能
	*/
	struct req_agoraFunc : public _sdkcmd_base
	{
		req_agoraFunc() :channelID(0), chatTime(0), type(0){}
		///channelID
		int64   channelID;
		int64   chatTime;/// 通话时间 type = 5时 填
		int64   uuid;///声网id type = 6时 填
		int8    type;///1,认证 2.呼叫 3.接听 4.重新申请subKey,5.outChat,6,updataID
		CMD_SIZE();
	};
			/**
	* \struct req_upload2Cloud  logic_upload2Cloud
	*  brief  上传文件  新云盘
	*/
	struct req_uploadNewCloud : public _sdkcmd_base {
		req_uploadNewCloud() :pid(0), fileSize(0){}
		int32 type;					// 上传类型 1 秒传 2 正常文件上传3 分片上传文件4 正常文件夹上传
		int64 pid;					// 云盘父目录id 如果没有父目录，传0。
		int64 user;					// 用户id
		int64 sdkid;				// sdkid
		int64 sowner;				// 共享目录拥有者 id
		int64 ssdkid;				// 共享目录拥有者 sdkid
		int64 virtualid;			// 文件id
		std::string ftype;			// 文件类型
		int64 fileSize;				// 文件大小
		std::string sha2;			// sha哈希值
		std::string md5;			// md5
		std::string	encryptKey;		///< 加密秘钥
		std::string  localPath;     ///<本地文件地址
		std::string fileName;		///<文件名，为空时，取localPath的文件名
		bool			isResume;    ///<是否支持断点续传
		bool			isEncrypt;	/// 是否加密
		CMD_SIZE();
	};

	/*
	*  brief  新云盘文件下载
	*/
	struct req_downloadCloud : public _sdkcmd_base {
		req_downloadCloud():localId(0),fileId(0),userId(0),sdkid(0),sowner(0),ssdkid(0), fileSize(0),bisResume(false){}
		int64 localId;				///< 本地 id
		int64 fileId;				///< 文件 Id
		int64 userId;				///< 用户Id
		int64 sdkid;				// sdkid
		int64 sowner;				// 共享目录拥有者ID
		int64 ssdkid;				// 共享目录拥有者 sdk ID
		int64 fileSize;				// 文件大小

		std::string localPath;		///< 文件本地保存路径 localPath.
		std::string uri;			///< 远程路径.
		std::string fileName;		///< 真实的文件名 fileName.
		bool        bisResume;		///<是否断点下载	
		CMD_SIZE();
	};

		/**
	* \struct req_upload2Cloud  logic_upload2Cloud
	*  brief  上传文件到云盘
	*/
	struct req_upload2Cloud : public _sdkcmd_base {
		req_upload2Cloud() :pid(0), fileSize(0), isResume(0){}
		int64 pid;					///< 云盘父目录id。如果没有父目录，传0
		std::string fileCode;		///< 云盘父目录code
		int fileSize;				///< 文件加密前大小
		std::string	encryptKey;		///< 加密秘钥
		std::string  localPath;     ///<本地文件地址
		std::string fileName;		///<文件名，为空时，取localPath的文件名
		bool			isResume;    ///<是否支持断点续传
		CMD_SIZE();
	};
	/**
	* \struct req_operOnlineExt  logic_cmd_setOrDelOnlineExt
	* \brief 操作onlineExt
	* type=4 新增或者修改onlineExt 
	* type=5 删除onlineExt
	*/
	struct req_operOnlineExt : public _sdkcmd_base
	{
		req_operOnlineExt() :type(0) {}
		int8 type;
		std::string str;
		CMD_SIZE();
	};
	
	struct req_insertMessage : public req_sendMessage
	{
		req_insertMessage() :msgId(0), lastMsgId(0), sendTime(0){}
		int64 msgId;
		int64 lastMsgId;
		int64 sendTime;
	};
	
	struct req_feedBack : public _sdkcmd_base
	{
		req_feedBack() :id(0), questionID(0), isNecessary(0), operatingSystem(0), feedbackPersonID(0)
		{}
		int id;							///< 主键ID,可不用设置
		int questionID;					///< 问题ID(1：崩溃；2：掉线；3：卡顿；4：其他问题；5：改进建议)
		std::string questionName;		///< 问题名称
		std::string questionDescription; ///< 问题描述
		int8 isNecessary;				///< 是否必现 (1：是；2：否)
		int8 operatingSystem;			///< 操作系统 1:安卓、2:IOS、3:Windows、4:MAC、5:网页 
		std::string clientVersion;		///< 客户端版本
		int64 feedbackPersonID;			///< 反馈人id
		std::string feedbackPersonName;	///< 反馈人名称
		std::string feedbackPersonOrg;	///< 反馈人所在组织机构 
		std::string createDate;			///<  提交时间 
		std::string screenPic;			///< 反馈截图  (最多四张，以英文分号（;）隔开)
		std::string logUrl;				///< 日志地址	
		std::string operatingSystemVersion;///操作系统版本
		CMD_SIZE();
	};

    struct req_getWBBanners : public _sdkcmd_base
    {
        req_getWBBanners() :type(0)
        {}
        int32 type;     ///< 客户端类型 1:Android 2:iOS
        CMD_SIZE();
    };

    struct req_helpSystem : public _sdkcmd_base
    {
        req_helpSystem() :type(0)
        {}
        int32 type;     ///< 客户端类型 1:PC 2:Android 3:iOS
        int64 parentID; ///< 父Id，查询展示
        CMD_SIZE();
    };

	//动态菜单
	struct req_clientMenu : public _sdkcmd_base
	{
		req_clientMenu() :clientMenuTs(0) {}
		int64 clientMenuTs; ///< 动态菜单时间戳
		CMD_SIZE();
	};

    struct req_groupOnlineStatus : public _sdkcmd_base
    {
        req_groupOnlineStatus() :groupId(0)
        {}
        int64 groupId; ///< 群Id
        CMD_SIZE();
    };

    struct req_userContact : public _sdkcmd_base
    {
        void init()
        {
            contactInfo.clear();
            type = 0;
            status = 0;
            SDKID = 0;
        }
        std::string contactInfo; ///< 帐号名称 手机号前加0086
        int8 type;           ///< 1.电话号码 3.email 4.userID 6.accountName
        int8 status;         ///< 1.启用， 2.禁用, 5.锁定, 6.冻结
        int64 SDKID;         ///< vrv服务器传0    
        std::string mark;   ///< 标识
        CMD_SIZE();
    };

    /**
    * \struct req_regBuddyOnline 消息号:  logic_cmd_regBuddyOnline
    * \brief 获取用户在线状态
    */
    struct req_regBuddyOnline : public _sdkcmd_base
    {
        int64 user;
        void init()
        {
            user = 0;
        }
        CMD_SIZE();
    };

	/**
	* \struct req_OauthPatam 消息号:  logic_cmd_oAuth
	* \brief 获取用户在线状态
	*/
	struct req_OauthParam : public _sdkcmd_base
	{
		int8 operType;		///< 操作类型 1.校验二维码 2.允许授权 3.获取authCode
		///以下参数根据operType具有不同意义
		int64 appId;		///< 1.应用Id  3.公众号Id
		int8 accType;		///< 1.客户端类型 3.登录账户类型
		std::string value_str;	///< 1.二维码Id 2.二维码Id 3.包名
		void init()
		{
			operType = 0;
			appId = 0;
			accType = 0;
			value_str.clear();
		}
		CMD_SIZE();
	};
	/**
	* \struct req_setGroupFileTermParam 消息号:  logic_cmd_setGroupFileTerm
	* \brief 设置群文件永久
	*/
	struct req_setGroupFileTermParam : public _sdkcmd_base
	{
		int64 fileId;   //文件ID
		int64 groupId;		///群ID
		int64 userID;		///上传者ID
		int8 fileTerm;		///< 1.临时 2.永久
		std::string fileUrl;	///群文件url
		void init()
		{
			fileId = 0;
			groupId = 0;
			userID = 0;
			fileTerm = 0;
			fileUrl.clear();
		}
		CMD_SIZE();
	};
	/**
	* \struct req_scanCodeLogin 消息号:  logic_cmd_scanCodeLogin
	* \brief 设置群文件永久
	*/
	struct req_scanCodeLogin : public _sdkcmd_base
	{
		int8 type;		//操作类型： 1.验证扫描  2.二维码登录
		int64 qId;		//二维码ID
		std::string serverUrl;	///后台服务url
		void init()
		{
			qId = 0;
			type = 0;
			serverUrl.clear();
		}
		CMD_SIZE();
	};
	/**
	* \struct req_createAppRoom 消息号:  logic_cmd_createAppRoom
	* \brief 工作台创建应用房间
	*/
	struct req_createAppRoom : public _sdkcmd_base
	{
		int64 id;							 //房间id
		std::string name;				//房间名称
		std::string icon; 
		std::vector<int64> mems;  //房间里成员应用id
		void init()
		{
			id = 0;
			name.clear();
			mems.clear();
		}
		CMD_SIZE();
	};
	/**
	* \struct req_updateAppRoomInfo 消息号:  logic_cmd_updateAppRoomInfo
	* \brief 更新应用房间信息
	*/
	struct req_updateAppRoomInfo : public _sdkcmd_base
	{
		int64 id;							 //房间id
		std::string name;				//房间名称
		std::string icon;               //房间图标
		void init()
		{
			id = 0;
			name.clear();
		}
		CMD_SIZE();
	};
	/**
	* \struct req_updateAppRoomMem 消息号:  logic_cmd_updateAppRoomMem
	* \brief 更新应用房间成员
	*/
	struct req_updateAppRoomMem : public _sdkcmd_base
	{
		int64 id;							 //房间id
		int8 type;						     //1.添加成员 2.删除成员 （删除后房间成员为空，会自动删除房间)
		std::vector<int64> mems;  //房间里成员应用id
		void init()
		{
			id = 0;
			type = 0;
			mems.clear();
		}
		CMD_SIZE();
	};
	/**
	* \struct req_setAppOrder 消息号:  logic_cmd_setAppOrder
	* \brief 更新应用排序信息
	*/
	struct req_setAppOrder : public _sdkcmd_base
	{
		std::vector<st_AppRoomInfo> apps;
		void init()
		{
			apps.clear();
		}
		CMD_SIZE();
	};
	/**
	* \struct req_getIssue 消息号:  logic_cmd_getIssuebyId
	* \brief 获取群议题
	*/
	struct req_getIssue : public _sdkcmd_base
	{
		int64 issueId;
		void init()
		{
			issueId = 0;
		}
		CMD_SIZE();
	};
	/**
	* \struct req_getIssue 消息号:  logic_cmd_searchIssue
	* \brief 查找群议题
	*/
	struct req_searchIssue : public _sdkcmd_base
	{
		int64 groupId;
		std::string key;
		void init()
		{
			groupId = 0;
			key.clear();
		}
		CMD_SIZE();
	};
	/**
	* \struct req_getIssueMsg 消息号:  logic_cmd_getIssueMsg
	* \brief 查找议题消息
	*/
	struct req_getIssueMsg : public _sdkcmd_base
	{
		int64 groupId;
		int64 issueId;
		int64 beginMsgId;
		int count;
		int flag;
		void init()
		{
			groupId = 0;
			issueId = 0;
			beginMsgId = 0;
			count = 0;
			flag = 0;
		}
		CMD_SIZE();
	};
	/**
	* \struct req_deleteIssue 消息号:  logic_cmd_deleteIssue
	* \brief 标记删除群议题
	*/
	struct req_deleteIssue : public _sdkcmd_base
	{
		std::vector<int64> issues;
		void init()
		{
			issues.clear();
		}
		CMD_SIZE();
	};
	/**
	* \struct req_insertJssdkAuth 插入Jssdk认证:  logic_cmd_insertJssdkAuth
	* \brief 插入jsssdk认证信息
	*/
	struct req_insertJssdkAuth : public _sdkcmd_base
	{
		int64 appID;
		int64 timeStamp;
		std::string noncestr;
		std::string url;
		std::string signature;
		std::vector<std::string> jsApiList;
		int64 valiTime;

		void init()
		{
			appID = 0;
			timeStamp = 0;
			noncestr.clear();
			url.clear();
			signature.clear();
			jsApiList.clear();
			valiTime = 0;
		}
		CMD_SIZE();
	};
	struct req_checkJssdkAuth : public _sdkcmd_base
	{
		int64 appID;				//应用ID
		int64 timeStamp;		//时间戳
		std::string noncestr;	//随机字符串
		std::string url;			//当前网页的url，不包含#及其后面的部分
		std::string signature;	//签名信息
		std::vector<std::string> jsApiList;	//需要请求的接口,Stirngp[]数组
		//std::string jsApiList;
		int64 valiTime;

		void init()
		{
			appID = 0;
			timeStamp = 0;
			noncestr.clear();
			url.clear();
			signature.clear();
			jsApiList.clear();
			valiTime = 0;
		}
		CMD_SIZE();
	};

	/**
	* \struct req_getAgencyListFinishCnt 从数据表中获取已完成和未完成数量:  logic_cmd_getAgencyListFinishCnt
	* \brief 待办事项获取已完成和未完成列表数
	*/
	struct req_getAgencyListFinishCnt : public _sdkcmd_base
	{
		int64 userID;
		int64 nCountDone;
		int64 nCountUndone;

		void init()
		{
			userID = 0;    ///< 获取的用户ID.
			nCountDone = 0;
			nCountUndone = 0;
		}
		CMD_SIZE();
	};

	/**
	* \struct  req_setAgencyListRead 消息号　logic_cmd_setAgencyListRead
	* \brief 工作台任务设置已读和未读
	* \date  [12/8/2020 admin]
	*/
	struct req_setAgencyListRead : public _sdkcmd_base
	{
		req_setAgencyListRead() :userId(0), flag(0), msgID(0)
		{
		}

		int64 userId;	    ///< 获取的用户ID.
		int8 flag;
		int64 msgID;

		CMD_SIZE();
	};

	/**
	* \struct  req_getAgencyListScreenItem 消息号　logic_cmd_getAgencyListScreenItem
	* \brief 获取本地筛选条件（来源和标签展示）
	* \date  [12/8/2020 admin]
	*/
	struct req_getAgencyListScreenItem : public _sdkcmd_base
	{
		req_getAgencyListScreenItem() :userId(0)
		{
		}

		int64 userId;	    ///< 获取的用户ID.

		CMD_SIZE();
	};
	/**
	* \struct  req_disHistoryAgencyListRecords 消息号　logic_cmd_disHistoryAgencyListRecords
	* \brief 展示历史搜索记录
	* \date  [12/8/2020 admin]
	*/
	struct req_disHistoryAgencyListRecords : public _sdkcmd_base
	{
		req_disHistoryAgencyListRecords() :userId(0)
		{
		}

		int64 userId;	    ///< 获取的用户ID.

		CMD_SIZE();
	};
	/**
	* \struct  req_delHistoryAgencyListRecords 消息号　logic_cmd_delHistoryAgencyListRecords
	* \brief 清空历史搜索记录
	* \date  [12/8/2020 admin]
	*/
	struct req_delHistoryAgencyListRecords : public _sdkcmd_base
	{
		req_delHistoryAgencyListRecords() :userId(0)
		{
		}

		int64 userId;	    ///< 获取的用户ID.

		CMD_SIZE();
	};

	/**
	* \struct  req_getAppListByMenuCode 消息号　logic_cmd_getAppListByMenuCode
	* \brief 获取栏目的应用列表,多参数，新设计
	* \date  [12/8/2020 admin]
	*/
	struct req_getAppListByMenuCode : public _sdkcmd_base
	{
		req_getAppListByMenuCode() : pageNum(0), pageSize(0), deviceType(0), userID(0){}

		int32 pageNum;			//页码
		int32 pageSize;			//页长
		int32 deviceType;		//类型
		int64 userID;				//用户ID
		std::string appName;		//应用名称，模糊查询用
		std::string channels;		//应用名称发布渠道

		CMD_SIZE();
	};
	/**
	* \struct  req_getAppListByMenuSeq 消息号　logic_cmd_getAppListByMenuSeq
	* \brief 获取栏目的应用列表,单参数，旧设计
	* \date  [12/8/2020 admin]
	*/
	struct req_getAppListByMenuSeq : public _sdkcmd_base
	{
		req_getAppListByMenuSeq() :menuID(0)
		{
		}

		int16 menuID;	    ///< 传入的栏目ID.

		CMD_SIZE();
	};
	/**
	* \struct  req_pushMsgToApp 消息号　logic_cmd_pushMsgToApp
	* \brief 新待办任务用户决策请求信息结构体
	*/
	struct req_pushMsgToApp : public _sdkcmd_base
	{
		req_pushMsgToApp() :appID(0)
		{
		}

		int64 appID;	    ///<传入的应用ID
		std::string  body;  ///<用户决策的信息

		CMD_SIZE();
	};
	/**
	* \struct req_migrateUserData 消息号:  logic_cmd_compress
	* \brief 查找议题消息
	*/
	struct req_migrateUserData : public _sdkcmd_base
	{
		std::string rootZip;//根数据压缩路径
		int type;			//1.压缩 2.解压缩
		std::string passwd; //新增加解密密码
		void init()
		{
			passwd = "";
			type = 0;
			rootZip.clear();
		}
		CMD_SIZE();
	};
	/**
	* \struct req_FileFragmentationInfo 消息号:  logic_cmd_getFileFragmentationInfo
	* \brief 获取文件分片信息
	*/
	struct req_FileFragmentationInfo : public _sdkcmd_base
	{
		std::string path;		//文件路径
		bool isEncrypt;			//是否加密
		int32 burstSize; //分片大小
		void init()
		{
			path.clear();
			isEncrypt = false;
			burstSize = 0;
		}
		CMD_SIZE();
	};
	/**
	* \struct req_FileFragmentationInfo 消息号:  logic_cmd_getFileFragmentationInfo
	* \brief 获取文件分片信息
	*/
	struct req_FileContentByFragmentIndex : public _sdkcmd_base
	{
		std::string fileSrcpath;				//文件路径
		std::vector<int32> fileIndex;			//文件块索引
		int32 burstSize;						//分片大小
		void init()
		{
			fileIndex.clear();
			burstSize = 0;
		}
		CMD_SIZE();
	};
	/**
	* \struct req_migrateUserDataNew 消息号:  
	* \brief 查找议题消息
	*/
	struct req_migrateUserDataNew : public _sdkcmd_base
	{
		std::vector<std::string> dirNameVt;//压缩目录名列表
		std::string rootZip;//根数据压缩路径
		int type;			//1.压缩 2.解压缩
		std::string passwd; //新增加解密密码

		int8 compressType; //压缩类型，0表示全部压缩，1表示可选择的压缩
		int8 hasDb;
		int8 hasFile;
		int8 hasCollect;
		int64 spareSpace; //剩余空间，单位B，仅compressType为1时有用
		int64 singleMaxSize;//单个文件允许迁移的最大限制，低于这个值才允许迁移,仅compressType为1时有用
		void init()
		{
			type = 0;
			passwd = "";
			rootZip.clear();
			dirNameVt.clear();
			compressType = 0;
			hasDb = 0;
			hasFile = 0;
			hasCollect = 0;
			spareSpace = 0;
			singleMaxSize = 0;
		}
		CMD_SIZE();
	};
	/**
	* \struct req_groupAnnouncementParam 消息号:  logic_cmd_qGroupS
	* \brief 群公告相关功能
	*/
	struct req_groupAnnouncementParam : public _sdkcmd_base
	{
		int8 operType;		///< 操作类型 1.添加群公告 2.删除单个群公告 3.校验群公告是否存在 4.分页获取群公告列表
		///以下参数根据operType具有不同意义
		int64 announcementID;   //公告ID, type为4时标识已拉取到的最终群公告id
		int64 groupID;   
		int64 createUserID;
		int64 createDt;        //公告创建时间
		std::string content;  //公告内容
		int64 userID;           //用户id
		int32 pageSize;       ///每页大小 默认20
		void init()
		{
			operType = 0;
			announcementID = 0;
			createUserID = 0;
			createDt = 0;
			userID = 0;
			pageSize = 20;
		}
		CMD_SIZE();
	};
	/**
	* \struct req_setGroupAnnReaded 消息号 logic_cmd_setGroupAnnReaded
	* \brief 设置群公告消息已读到数据库
	*/
	struct req_setGroupAnnReaded : public _sdkcmd_base
	{
		req_setGroupAnnReaded() :targetId(0), msgId(0) {}
		int64 targetId;
		int64 msgId;
		std::string msgProperty;
		CMD_SIZE();
	};
	/**
	* \struct req_addLocalApp 消息号:  logic_cmd_addLocalApp
	* \brief 添加本地应用
	*/
	struct req_addLocalApp : public _sdkcmd_base
	{
		int64 appId;		
		std::string name;				
		std::string icon;     
		std::string url;
		void init()
		{
			appId = 0;
			name.clear();
		}
		CMD_SIZE();
	};
	/**
	* \struct req_delLocalApp 消息号:  logic_cmd_delLocalApp
	* \brief 删除本地应用
	*/
	struct req_delLocalApp : public _sdkcmd_base
	{
		int64 appId;
		void init()
		{
			appId = 0;
		}
		CMD_SIZE();
	};
	/**
	* \struct req_beforeLogin 消息号:  logic_cmd_beforeLogin
	* \brief 登陆前操作接口
	*/
	struct req_beforeLogin : public _sdkcmd_base
	{
		int8 type;
		std::string funcName;
		std::string value_str;
		void init()
		{
			type = 0;
			funcName.clear();
			value_str.clear();
		}
		CMD_SIZE();
	};

	/**
	* \struct req_getqrCode 消息号:  logic_cmd_getQrCode
	* \brief 获取二维码信息接口
	*/
	struct req_getqrCode : public _sdkcmd_base
	{
		std::string elogo;
		std::string Appinfo;
		void init()
		{
			elogo.clear();
			Appinfo.clear();
		}
		CMD_SIZE();
	};


	/**
	* \struct req_getqrCode 消息号:  logic_cmd_pcQuickLogin
	* \brief PC快速登录 
	*/
	struct req_quickLogin : public _sdkcmd_base
	{
		int64 userId;
		int8 pcType;
		std::string Appinfo;
		void init()
		{
			userId = 0;
			pcType = 0;
			Appinfo.clear();
		}
		CMD_SIZE();
	};
	/**
	* \struct req_getqrStatus 消息号:  logic_cmd_getQrStatus
	* \brief 获取二维码登录结果接口
	*/
	struct req_getqrStatus : public _sdkcmd_base
	{
		std::string qr_codeid;
		std::string qr_codeidEv;
		void init()
		{
			qr_codeid.clear();
			qr_codeidEv.clear();
		}
		CMD_SIZE();
	};

	/**
	* \struct req_scanqrCode  消息号 logic_cmd_scanQrCode
	* \brief 二维码登录相关，获取二维码状态信息
	* \ elogo 服务器elogo  二维码唯一id  qr_codeid
	*/
	struct req_scanqrCode : public _sdkcmd_base
	{
		std::string elogo;
		std::string qr_codeid;

		void init()
		{
			qr_codeid.clear();
			elogo.clear();
		}
		CMD_SIZE();
	};

	/**
	* \struct req_confirmPCLogin  消息号 logic_cmd_confirmPCLogin
	* \brief 二维码登录相关，确认二维码登录取消接口
	* \confirm 确认或取消登录  二维码唯一id  qr_codeid
	*/
	struct req_confirmPCLogin : public _sdkcmd_base
	{
		int8 confirm;
		std::string qr_codeid;

		void init()
		{
			confirm = 0;
			qr_codeid.clear();
		}
		CMD_SIZE();
	};

	/**
	* \struct req_verifyUserInfoField 消息号:  logic_cmd_verifyUserInfoField
	* \brief 验证登录后用户信息字段是否正确
	*/
	struct req_verifyUserInfoField : public _sdkcmd_base
	{
		int8 accountType;
		std::string account;
		std::string userField;
		void init()
		{
			accountType = 0;
			account.clear();
			userField.clear();
		}
		CMD_SIZE();
	};

	/**
	* \struct  req_GetDelayMsgSt 消息号　logic_cmd_OpeateDelayMsg
	* \brief 延时消息取消/立即发送结构体
	*/
	struct req_GetDelayMsgSt : public _sdkcmd_base
	{
		int64 nMessageId;
		int8  nType;
		req_GetDelayMsgSt()
		{
			nMessageId = 0;
			nType      = 0;
		}
		CMD_SIZE();
	};

	/**
	* \struct  req_getTaskMsg 消息号　logic_cmd_getTaskMsg
	* \brief 根据timeTask获取任务消息
	*/
	struct req_getTaskMsg : public _sdkcmd_base
	{
		req_getTaskMsg() :targetId(0){}
		int64 targetId;			///< 个人或群ID.
		std::string timeTask;			    ///< 任务时间戳.
		CMD_SIZE();
	};
	/**
	* \struct  req_loginDeviceManage 消息号　logic_cmd_loginDeviceManage
	* \brief 登录设备管理
	*/
	struct req_loginDeviceManage : public _sdkcmd_base
	{
		req_loginDeviceManage(): type(0) {}
		int type;   //3、获取登录设备记录 4、.删除登录设备记录
		std::vector<std::string> macAddrs;  //type为4时有用，删除登录设备列表，
		CMD_SIZE();
	};

	/**
	* \struct  req_getSecurityList 消息号　logic_cmd_getSecurityList
	* \brief 获取密集列表
	*/
	struct req_getSecurityList : public _sdkcmd_base
	{
		CMD_SIZE();
	};
	
		/// logic_cmd_createReminderMsg
	struct req_reminderMsg : public _sdkcmd_base {
		req_reminderMsg()
		{
			reminderMsg.init();
		}

		st_reminderMsg reminderMsg;         
		CMD_SIZE();
	};

	/// logic_cmd_getReminderMsgPage
	struct req_getReminderMsgPage : public _sdkcmd_base {
		req_getReminderMsgPage() :
		pageNo(0), pageSize(0){}

		int32 pageNo;    ///页数
		int32 pageSize;  ///行数
		CMD_SIZE();
	};

	/// logic_cmd_deleteReminderMsg
	struct req_deleteReminderMsg : public _sdkcmd_base {
		req_deleteReminderMsg() :
		reminderId(0){}

		int64 reminderId;    ///消息提醒号
		CMD_SIZE();
	};

	/*
	* \brief 获取云盘传输历史任务
	*/
	struct req_newCloudTransferHistory : public _sdkcmd_base
	{
		req_newCloudTransferHistory(){
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
		std::string md;					/// md5码
		std::string sha;				/// 文件的标记，在删除时需要判断是对应的文件
		std::string downLoadPath;		///< 文件本地保存路径 localPath

		int64 splitSize;    			/// http上传时是总分片数
		int64 splitFinished; 			/// 完成量, http上传时是已上传的分片数

		//bool  isResumeUpload;			///<是否支持断点续传
		//bool  isEncrypt;				/// 是否加密
		//bool  bisResumeDownload;		///<是否断点下载

		int32	transferType;			/// transferType = 1, 上传， transferType = 2, 下载
		int32	transferState;			///	transferState = 1, 成功， transferState = 2, 失败，

	};


	/// logic_cmd_setGroupChatForbid
	struct req_setGroupChatForbid : public _sdkcmd_base {
		req_setGroupChatForbid() :
		groupId(0),targetId(0),timeUtil(0),operateType(0){}
		
		void init()
		{
            groupId = 0;
			targetId = 0;
			timeUtil = 0;
			operateType = 0;
		}
		
		int64 groupId;
		int64 targetId; 
		int64 timeUtil;
		int8 operateType;
		CMD_SIZE();
	};

	/**
	* \struct req_getLoginClientRecord  消息号 logic_cmd_getLoginClientRecord
	* \brief 根据用户ID集合查询用户的设备信息,豆豆版本
	*/
	struct req_getLoginClientRecord : public _sdkcmd_base
	{
		req_getLoginClientRecord(){
			init();
		}
		std::vector<int64> userIDs;

		void init()
		{
			userIDs.clear();
		}
		CMD_SIZE();
	};

	/**
	* \struct req_getSmalAppHelpFlagValue  消息号 logic_cmd_getSmalAppHelpFlagValue
	* \brief 获取客户端应用浏览器的应用服务开关总值
	*/
	struct req_getSmalAppHelpFlagValue : public _sdkcmd_base
	{
		req_getSmalAppHelpFlagValue(){
			init();
		}
		int64 appId;

		void init()
		{
			appId = 0;
		}
		CMD_SIZE();
	};


	/**
	* \struct req_getSmallAppHelpList  消息号 logic_cmd_getSmallAppHelpList
	* \brief 获取客户端应用浏览器的帮助获取帮助列表
	*/
	struct req_getSmallAppHelpList : public _sdkcmd_base
	{
		req_getSmallAppHelpList(){
			init();
		}
		int64 appId;
		int64 parentId;
		void init()
		{
			appId = 0;
			parentId = 0;
		}
		CMD_SIZE();
	};
	/**
	* \struct req_getBuddySetting  消息号 logic_cmd_getBuddySetting
	* \brief 获取用户设置项信息
	*/
	struct  req_getBuddySetting:public _sdkcmd_base
	{
		std::vector<int64> userIds;
		req_getBuddySetting(){
			init();
		}
		void init(){
			userIds.clear();
		}
		CMD_SIZE();

	};

	/**
	* \struct req_setServerAlias  消息号 logic_cmd_setServerAlias
	* \brief 设置服务器别名
	*/
	struct  req_setServerAlias :public _sdkcmd_base
	{
		int64 userId;
		std::string serAlias;
		req_setServerAlias(){
			init();
		}
		void init(){
			userId=0;
			serAlias.clear();
		}
		CMD_SIZE();

	};

	/**
	* \struct req_getServerAlias  消息号 logic_cmd_getServerAlias
	* \brief 获取设置的服务器别名
	*/
	struct  req_getServerAlias :public _sdkcmd_base
	{
		int64 userId;
		std::string serverAlias;
		req_getServerAlias(){
			init();
		}
		void init(){
			userId = 0;
			serverAlias.clear();
		}
		CMD_SIZE();

	};


	/**
	* \struct req_elevatorAuthInfo  消息号 logic_cmd_elevatorAuthInfo
	* \brief     超级用户相关的操作
	type=3, 保存提权人员所有权限 (saveElevatorAuthority)
        参数：elevatorList  提权人员列表
        返回: code ：0:成功  -1:系统异常 -2:参数异常 100:未定义的type类型 11100调用底层接口失败
             what 结果消息
             value_str 保存失败的userID集合

    type=4, 删除提权人员所有权限 (deleteElevator)
        参数：
             value64 超级用户id
             value64_2 提权用户id

        返回: code ：0:成功  -1:系统异常 -2:参数异常 100:未定义的type类型 11100调用底层接口失败
             what 结果消息

    type=5, 查询当前超级用户的所有提权人员以及权限 (selectElevatorAuthorityAll)
        参数:
             value64 查询页数量
             value64_2 查询页序号
             value64_3 超级用户id

        返回：
             code ：0:成功 100:未定义的type类型 11100调用底层接口失败
             value64 当前页数量
             value64_2 当前页序号
             value64_3 总页数
             value64_4 总条数
             elevatorList 提权人员列表

    type=6, 查询提权人员真实所有权限 (queryElevatorAuthorityReal)
        参数： 
              value64 提权人员id
        返回: code ：0:成功  -1:系统异常 -2:参数异常 100:未定义的type类型 11100调用底层接口失败
             what 结果消息
             value_str 权限json

    type=7, 分页查询操作记录信息 (listElevatorRecord)
        参数：
             value64 查询页数量
             value64_2 查询页序号
             value64_3 提权人员id
             value64_4 超级用户id

        返回：
             code ：0 成功 100:未定义的type类型 11100调用底层接口失败
             value64 当前页数量
             value64_2 当前页序号
             value64_3 总页数
             value64_4 总条数
             elevatorList 提权人员列表 
	*/
	struct  req_elevatorAuthInfo :public _sdkcmd_base
	{
		struct st_elevatorAuthority
		{

			int64 elevatorUserId; // 提权人员userId
			int64 superUserId;  // 超级用户userId
			std::string authorityCode; // 权限code/提权记录信息
			int64 createTime; //创建时间
			int64 updateTime; //更新时间
		};

		int16 type;
		std::vector<st_elevatorAuthority> elevatorList;
		int64 value64;
		int64 value64_2;
		int64 value64_3;
		int64 value64_4;
		req_elevatorAuthInfo(){
			init();
		}
		void init(){
			elevatorList.clear();
			type = 0;
			value64 = 0;
			value64_2 = 0;
			value64_3 = 0;
			value64_4 = 0;
		}
		CMD_SIZE();

	};


	/**
	* \struct  req_getTagStrategyFromNet 消息号: logic_cmd_getTagStrategyFromNet
	* \brief   获取用户标签信息
	*/
	struct  req_getTagStrategyFromNet : public _sdkcmd_base
	{
		req_getTagStrategyFromNet() :targetId(0), tagType(0) {}
		int64    targetId;  ///< 用户ＩＤ userid.
		int8 tagType;			///< 1：获取用户标签 2：超级用户高级权限列表 
		CMD_SIZE();
	};

	/**
	* \struct req_getAgencyListFromNet  消息号 logic_cmd_operateAgencyEx
	* \brief 网络分页获取任务代办
	*/
	struct req_getAgencyListFromNet : public _sdkcmd_base
	{
		req_getAgencyListFromNet(){
			init();
		}
		int64 userID;
		int8 type;//0表示默认，1表示未办，2表示已办
		int pageNum;//页码，-1表示全量数
		int pageSize;//每页大小

		void init()
		{
			userID = 0;
			type = 0;
			pageNum = -1;
		}
		CMD_SIZE();
	};

	/**
	* \struct req_getLocalAgencyListFromDb  消息号 logic_cmd_getLocalAgencyListFromDb
	* \brief 本地分页获取任务代办
	*/
	struct req_getLocalAgencyListFromDb : public _sdkcmd_base
	{
		req_getLocalAgencyListFromDb(){
			init();
		}

		int8 type;//1表示getAgencyListExByFlag，2表示disAgencyListScreenResults，3表示searchLocalAgencyListByKey
		int8 flag;//123,待办已办标志，0表示代办，1表示已办
		int64 msgId;//123,起始消息ID，只能从新往旧查询，如果是第一页查询参数传0，如果是第一页之后的页数传入上一页最后一条消息ID减去1
		int count;//123,查询条数
		int64 startTime;//2,起始时间
		int64 endTime;//2,结束时间，开始时间和结束时间要么都有值，要么都是0
		std::vector<int64> appIds;//2,业务来源
		int8 urgeflag;//2,催办状态,0表示不催办，1表示催办
		std::vector<std::string> tags;//2,标签
		std::string keyWord;//3,搜索关键字

		void init()
		{
			type = 0;
			flag = 0;
			msgId = 0;
			count = 0;
			startTime = 0;
			endTime = 0;
			appIds.clear();
			urgeflag = 0;
			tags.clear();
			keyWord.clear();
		}
		CMD_SIZE();
	};

	/**
	* \struct  req_getServerInfo 消息号　logic_cmd_BifactorLoginMessage
	* \brief 设置双因子登录
	*/
	struct req_SetBifactorInfo : public _sdkcmd_base
	{
		int8 nLoginType;
		int8 nStatus;
		int8 nDeviceType;
		int64 nMessageID;
		std::string szUserName;

		req_SetBifactorInfo()
		{
			nLoginType  = 0;
			nStatus     = 0;
			nDeviceType = 0;
			nMessageID  = 0;
			szUserName  = "";
		}
		CMD_SIZE();
	};

	/**
	* \struct req_mQrCodeQuery  消息号 logic_cmd_MQrCodeQuery  logic_cmd_MCircleQrCodeQuery
	* \brief  M盒二维码查询相关接口
	* \deviceflag 设备类型 1:PC，2:移动端
	* \bcircleflag  是否周期查询标志  0：否    1： 是
	* \optflag，param1，param2  param3参考接口说明
	*/
	struct req_mQrCodeQuery : public _sdkcmd_base
	{
		int8 deviceflag;
		int8 optflag;
		int8 bcircleflag;
		std::string param1;
		std::string param2;
		std::string param3;

		std::string querycmd;

		void init()
		{
			bcircleflag = 0;
			deviceflag = 0;
			optflag = 0;
			param1.clear();
			param2.clear();
		}
		CMD_SIZE();
	};

	
		/**
	* \struct  req_UserToAppConfig 
	* \brief   公众号免打扰
	*/
	struct  req_UserToAppConfig : public _sdkcmd_base
	{
		req_UserToAppConfig() :appId(0), timestamp(0), type(1), value(1){}
		int64 appId;  //公共号id
		int64 timestamp;  //时间戳
		int8 type;  //配置类型1消息提醒（勿扰模式）
		int value;  //type=1时 1:为接收提醒 2:表示不提醒仅显示数字 3:为免打扰 
		CMD_SIZE();
	};

	/**
	* \struct  req_AdminRoleInfo
	* \brief   用户绑定的后台管理员角色信息
	*/
	struct  req_AdminRoleInfo : public _sdkcmd_base
	{
		req_AdminRoleInfo(){ superAdmin = false; }
		bool superAdmin;				//是否是超级管理员，true是，false否
		std::string adminName;		//管理后台绑定人员名称
		std::string adminAccount;	//管理后台绑定人员帐号
		CMD_SIZE();
	};

	/**
	* \struct  req_AdminRoleInfoJson
	* \brief   用户绑定的后台管理员角色信息
	*/
	struct  req_AdminRoleInfoJson : public _sdkcmd_base
	{
		req_AdminRoleInfoJson(){}
		std::string roleInfoResult;		//管理后台绑定人员名称
		CMD_SIZE();
	};

	struct req_GetUserSetting : public _sdkcmd_base
	{
		req_GetUserSetting()
		{
			nUserId = 0;
		}

		int64 nUserId;
		CMD_SIZE();
	};

	struct req_SetUserSetting : public _sdkcmd_base
	{
		req_SetUserSetting()
		{
			nUserId = 0;
			nValue = 0;
			szSearchKey = "";
		}

		int64 nUserId;
		int8 nValue;
		std::string szSearchKey;
		CMD_SIZE();
	};

	struct req_commonTokenReq : public _sdkcmd_base {
		req_commonTokenReq()
		{
			commonTokenInfo.init();
		}
		st_commonTokenInfo commonTokenInfo;
		CMD_SIZE();
	};

	struct req_GetCombinationReq:public _sdkcmd_base
	{
		req_GetCombinationReq()
		{
			szTemplateId = "";
			nUserId = 0;
		}
		std::string szTemplateId;
		int64 nUserId;

		CMD_SIZE();
	};

	struct req_SetCombinationReq : public _sdkcmd_base
	{
		req_SetCombinationReq()
		{
			nOperateCmd = 0;
		}

		int nOperateCmd;
		st_CombinationOrder SetTemplateOrder;
	};
}
#endif  //CMD_REQ_DEF_H
