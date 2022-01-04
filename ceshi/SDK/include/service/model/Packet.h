#pragma once
#include "User.h"
#include "Msg.h"
#include "TinyGroup.h"
#include <vector>
#include <string>
#include <map>
#include "LoginInfo.h"

namespace model
{ 
class Msg;
struct AppInfo
{
	AppInfo() :deviceType(1), devMode(0), isUseHttpServer(0)
	{}	
	std::string appVersion;		//应用版本号，如"1.5.0"  *必须设置
	int deviceType;				//设备类型 1：PC；2：手机；3：pad；4：网页  *必须设置
	std::string deviceInfo;		//设备信息 如"pc-windows"  *必须设置
	std::string appName;		//应用信息 需与应用名保持一致 *必须设置
	std::string netType;		//网络信息 如"wifi"  可选
	std::string mac;			//mac地址  windows,mac,linux平台会自动获取，其它平台需手动设置
	std::string mark;			//应用标示 可选
	int         devMode;        //是否调试模式 0 默认模式 1 调试者模式
	appVerifyInfo  verifyInfo;  //验证信息 默认模式下需要填写
	int8 isUseHttpServer;		//是否使用http插件 0不用 1用
	std::string rcPath;  //实际的资源和日志的路径（及为调用setRootPath时的参数），安卓专用
};

///用户设置
struct UserSetting
{
	UserSetting() :isonline(0), issearchbybean(0), issearchbyphone(0), issearchbymail(0),
					isshareupdate(0), isnewmsgtip(0), ismultiservmsgtip(0), ismultiservfrdtip(0), 
					ismultiservpersontip(0), issearchbyname(0), isappmgrauth(0),iscallkitflag(0)
	{
	}

	int8 isonline;				///<否显示在线信息 0显示 1不显示 默认0
	int8 issearchbybean;		///<豆豆号查找  0允许 1不允许 默认0
	int8 issearchbyphone;		///<手机号查找  0允许 1不允许 默认0
	int8 issearchbymail;		///<邮箱号查找  0允许 1不允许 默认0
	int8 issearchbynewfriend;	/// 通过新朋友查找  0允许 1不允许 默认0
	int8 isshareupdate;			///<分享更新   0提示更新 1不提示更新 默认0
	int8 isnewmsgtip;			///<新消息通知是否提醒0提醒 1不提醒 默认0
	int8 ismultiservmsgtip;		///<多服务新消息通知是否提醒0不始终提示 1始终提示 默认0
	int8 ismultiservfrdtip;		///<多服务设置V标好友始终提醒 0不始终提示 1始终提示 默认
	int8 ismultiservpersontip;	///<多服务设置设置@相关人始终提醒0不始终提示 1始终提示 默认0
	int8 issearchbyname;		///<昵称查找  0允许 1不允许 默认0
	int8 isappmgrauth;			///<应用管理权限 0 无权限 1 有权限 默认 0
	int8 iscallkitflag;     //callkit 开关  1开启 0 关闭 默认 0
};

///本地配置条目
struct LocalSetting
{
	LocalSetting(){}
	LocalSetting(const std::string &k, const std::string &v) :key(k), val(v)
	{}
	std::string key; ///<标识
	std::string val; ///<值
};

struct delFileinfoList
{
	delFileinfoList() :fileid(0) {}
	int64 fileid;                 ///<文件ID
	std::string thumbPath;		  ///<缩略图本地路径
	std::string thumbUrl;		  ///<缩略图服务器路径
};

///个人配置项
struct PersonalData
{
	PersonalData(){}
	PersonalData(int16 t, int16 v) :type(t), val(v)
	{}
	int16 type; ///<标识
	int16 val; ///<值
};
///好友验证方式返回
struct ContactVerifyType
{
	ContactVerifyType() :userid(0), type(0)
	{}
	int64 userid;
	int8  type;   ///<验证类型1需要验证信息:2:不允许任何人添加,3:允许任何人添加
};
///在线状态
struct  OnlineState
{
	OnlineState() :userID(0), connectID(0), deviceType(0), flag(0), operTime(0), nStatus(0)
	{
		szExplain = "";
	}
	int64 userID;   ///<用户ID
	int64 connectID;
	int8 deviceType;  ///<在线设备类型  1：PC；2：手机；3：pad；4：网页
	///<在线状态 -1：离线，1:在线；2:隐身,3:忙碌,4:离开,5:请勿打扰,6:想聊天,7:强制下线,8:暂离，
	///<9:未激活 10:删除账号，11:账号冻结,  12:更换绑定账号,  13:重置密码,  14:远程控制PC下线
	int8 flag;        
    int64 operTime;   ///<操作时间
	int8 nStatus; //1:在线；2:会议中,3:忙碌,4:飞机上,5:请勿打扰,6:自定义
	std::string szExplain;
};

///消息查询
struct  MsgSearchProperty 
{
	MsgSearchProperty() :msgtype(2), count(0), targetid(0), start_time(0), end_time(0)
	{}
	int msgtype; ///<消息类型 当前只支持2文本
	int count;   ///<消息数量
	/**
	* 　targetId为用户Id或群Id，与count字段共同决定搜索的方式，有以下几种组合：
	*   targetId !=0, count = 1:搜索指定的targetId的聊天记录数目。
	* 　targetId = 0,count > 1: 从最小的targetId开始向上搜索记录，共搜索到count个匹配的targetId为止。
	*   targetId !=0, count >1: 从指定的targetId开始向上搜索记录，共搜索到count个匹配的targetId为止。
	*   count = 0为匹配全部消息，最多匹配10000条
	*/
	int64 targetid;
	int64 start_time;///<开始时间
	int64 end_time;  ///<结束时间  起始和结束时间全部为0代表搜索全部时间段
};
///查询结构体
struct SimpleSearchInfo
{
	SimpleSearchInfo() :flag(0){}
	int8  flag;			///<0x01男，0x02女, 0x08为群，0x10, 0 非男非女为保密
	std::string name;	///<目标名称
	std::string avatar;	///<目标头像
	std::string avatarUrl;
};
///消息查询结果
struct  MsgSearchResult
{
	MsgSearchResult() :nextTargetId(0)
	{}
	struct info
	{
		info() :count(0), targetId(0), lastTime(0){}
		int64 targetId;			///<搜索到对象的targetId
		int64 lastTime;         ///搜索到的target最新消息时间
		int count;			    ///<消息数量
		SSharedPtr<model::Msg> msg;  //匹配的第一条消息
		SimpleSearchInfo simpleInfo; 
	};

	std::vector<info> infos;  ///<搜索到的消息信息集合
	int64 nextTargetId;	    ///<后续查找的targetId，0代表已搜索全部消息
    std::string key;        ///<搜索用的key
};

struct MsgDetailSearchProperty
{
	MsgDetailSearchProperty() :msgtype(2), messageId(0), targetid(0), count(0), start_time(0), end_time(0)
	{}
	int msgtype;	///<消息类型 当前只支持2文本
	int64 targetid; ///<目标Id
	int messageId;  ///<起始msgId，0为从最早的消息就行搜索
	int count;		///<一次匹配到最大的消息数量,0为匹配全部消息,最多匹配100000条
	int64 start_time;///<开始时间
	int64 end_time;  ///<结束时间  起始和结束时间全部为0代表搜索全部时间段
};

struct  MsgDetailSearchResult
{
	MsgDetailSearchResult() :nextMsgId(0){}
	int64 nextMsgId;  ///<后续查找的消息ID，0代表已搜索全部消息
	std::map<int64, SimpleSearchInfo> senderInfos; ///<存放此次搜索结果中的所有发送者信息,key为senderUserId
	std::vector<SSharedPtr<Msg> > msgs; ///<保存所有消息内容信息
};

struct UploadShareImageProperty
{
	std::string thumbImg;		///< 缩略图
	std::string srcImg;			///< 原图
	std::string encryptkey;		///< 加密秘钥
	std::string loginfoPath;	///< 登录信息保存路径
};

struct DownloadImageParam
{
	DownloadImageParam() :targetID(0), msgID(0), flag(0), fileType(0), isNineBox(false), width(0), height(0) 
	{
		md5Code.clear();
	}
	int64   	targetID; 	///< 发送方对方ＩＤ targetID.
	int64       msgID;      ///< 消息ID 存fileInfo用.
	std::string rPath;  	///< 远程路径
	std::vector<std::string> nineBoxUrl;	///< 九图Url路径，一般就传缩略图
	std::string encryptKey;	///< 加密密钥，存fileInfo用
	std::vector<std::string> relaPath;	///< 相对路径 下载九图时和nineBoxUrl字段一一对应，单张图片就放在下标0 存fileInfo
	int32		flag;		///< 标识位 0缩略图 1大图 1~9表示九图的位置 存fileInfo用 isNineBox=true时存缩略图
	int			fileType;	///< 文件类型 0.所有 6文档 5图片 89视频 3音频 与msgType一致
	bool		isNineBox;	///< 是否下载九图缩略图 只有在下九图缩略图时置为true 此时flag表示九图位置 传1~9
	int32		width;		///< 图片宽度 像素 --视频分辨率下载缩略图时传入
	int32		height;		///< 图片高度 像素
	std::vector<std::string> md5Code; ///<增加md5校验 --下载九图时传入多个，单张图片or大图传入一个
};

///< 上传文件附件类型(对应UploadFileProperty中的type, 只上传文件，不发送文件消息时使用)
enum UploadType
{
	eFileType_app = 10020,	
	eFileType_share = 10021,
};

struct UploadFileProperty
{
	UploadFileProperty() :isP2p(0), isJS(0), localid(0), targetid(0), type(0), noStore(0), isResume(false),securityLevel(0){}
	int64 targetid;			///<对方的targetId(人或群)
	int64 localid;			///<标示文件的唯一localId 通过time()生成
	int16 type;				///<附件类型
	std::string localPath;	///<上传文件的本地路径
	std::string dirPath;	///<文件夹本地路径，上传文件夹时使用
	std::string msg;		///<用于存储自定义信息
	std::string encryptKey; ///<秘钥  ///断点上传的key必须一致
	int8  isP2p;            ///<是否点对点 0 否， 1 是.
	int8   isJS;             ///< 是否JS上传图片,0 否， 1 是
	int8	  noStore;		///< 是否不存消息和文件信息到数据库0 否， 1 是
	bool  isResume;         ///<是否断点上传
	int securityLevel;      ///<密级
};

struct DownloadFileProperty
{
	DownloadFileProperty() :bisP2P(false), bIsResume(true), localId(0), fromUserId(0), threadCount(1), securityLevel(0), isGroupDoc(0), docid(0){}
	int64 msgid;				///<文件的消息ID
	int64 targetId;				///<个人文件为发送者用户ID，群文件为群ID
	int64 localId;				///<标示文件的唯一localId
	int64 fromUserId;			///<发送者ID，个人文件时和targetId相同	
	std::string fileName;		// 文件名
	std::string localPath;		///<本地保存地址
	std::string url;			///<服务器地址
	std::string encryptKey;      ///<加密KEY
	bool        bisP2P;	 ///< 是否接收局域网直传文件.
	bool        bIsResume;///<是否断点续传下载
	int			threadCount;	///< 下载的线程数量 bIsResume为true且threadCount>1时生效 最大允许5个线程
	int			fileType;		///< 文件类型 0.所有 6文档 5图片 89视频 3音频 与msgType一致
	std::string relaPath;		///iOS专用，相对路径
	int64 mediaTime;	///< 视频、音频时长 秒  --视频宽高size下载缩略图时传入
	int securityLevel;///<密级
	std::string md5Code;		///< 文件MD5值，从文件消息中获取，为空则不校验
	int8 isGroupDoc; //是否群文档  0：否 1：是
	int64 docid; //群文档的docid
};

struct Fileinfo
{
	Fileinfo() :fileid(0), userid(0), targetid(0), size(0), time(0), fileTerm(1), fileType(0), mediaTime(0), width(0), height(0), securityLevel(0)
	{}
	int64 fileid;                 ///<文件ID
	int64 userid;                 ///<发送者ID
	int64 targetid;               ///<目标ID,可以是群,也可以是用户
	int64 size;                   ///<文件大小
	int64 time;                   ///<上传时间
	int8	 fileTerm;		///群文件有效期< 1.临时 2.永久
	int8 fileType;				  ///<文件类型 0.所有 6文档 5图片 89视频 3音频 与msgType一致
	std::string path;             ///<本地路径
	std::string name;             ///<文件名
	std::string url;              ///<文件url
	std::string encrypt_key;      ///<加密KEY
	std::string thumbPath;		  ///<缩略图本地路径
	std::string thumbUrl;		  ///<缩略图地址
	std::string thumbRelaPath;	  ///<缩略图相对路径
	std::string relaPath;		  ///<相对路径
	int64 mediaTime;
	int32 width;
	int32 height;
	int securityLevel;          ///<密级
};

struct OfflineMsg
{
	OfflineMsg() :offline_type(0), count(0)
	{}
	int offline_type;  ///<1未读消息 2设备已读消息
	int count;      ///<数量
	SSharedPtr<model::Msg> msg;
};

struct stupdateInfo
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

///版本升级信息
struct UpgradeInfo
{
	UpgradeInfo() :gradeType(0){}
	std::string hasCode;	///< 升级包的HAXI值
	int8 gradeType;			///< 升级类型 0建议升级,1强制升级 gradeType.
	std::string version;    ///< 服务器版本号 version.
	std::string updateAddr; ///< 升级的地址
	std::vector<stupdateInfo> upAddr;///<新预登录信息
	std::string desc;		///< 升级描述信息
	std::string clientInfo; ///< 客户端信息
};


/// 企业信息(搜索中使用)

struct EntInfo
{
	EntInfo() :
	enterpriseID(0){}

	int64 enterpriseID;         ///< 企业ID enterpriseID.
	std::string fullName;       ///< 企业全称 fullName.
	std::string shortName;      ///< 企业简称 shortName.
	std::string keyWords;       ///< 企业关键字 keyWords.
	std::string phone;          ///< 企业电话 phone.
};


struct OrGroupinfo
{
	OrGroupinfo() :
	groupid(0),
	orderid(0){}

	int64    groupid;
	int32    orderid;
	std::string groupname;
	std::string orgname;
};


/**
* \struct st_orgUserinfo
* \brief  组织用户信息（搜索中使用）
*/
struct OrgUserinfo
{
	OrgUserinfo() :
	userid(0){}

	int64   userid; 	                        ///< 用户ID      userid.
	std::string name;                           ///< 用户名称 	 name.
	//std::vector<std::string>  phonenumbers;     ///< 电话号码清单 phonenumbers.
	//std::vector<std::string>  emails;           ///< 电子邮件清单 emails.
	std::string orgname;                        ///< orgname 组织名称.
	std::string userHead;                        ///< 头像.
};


/**
* \struct st_entAppinfo
* \brief 应用信息
*/
struct  EntAppinfo
{
	EntAppinfo() :appID(0), entID(0), openIDEncoded(0), appSubType(0),recommend(0),
		defaultInstall(0),appType(0),status(0),subOrAppType(0),ownerId(0),forceGrant(0),CSID(0) {}
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
	///1:订阅号2：企业号 3：应用号
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
	int64 CSID;  //客服id
};

struct LocalSearchMemberInfo
{
	LocalSearchMemberInfo() :groupID(0), groupMemberNum(0), matchFlag(0), userID(0), status(0), securityLevel(0), lastTime(0){}

	int64 groupID;				//所在群ID
	int groupMemberNum;			//所在群人数
	int matchFlag;				//匹配类型 1.通过用户名匹配到 2.通过备注匹配到
	int64 userID;               //匹配到的用户ID
	std::string name;			//匹配到的用户名
	std::string remark;         //匹配到的用户备注
	int securityLevel;     //工作密级
	int status;               //<是否为外服成员（4 外服成员）
	int64 lastTime;           //所在群的最新消息时间
};

struct SearchResult
{
    std::string key;
	std::vector<model::User> users;
	std::vector<model::TinyGroup> groups;

	std::vector<EntInfo> vtent;     	            ///< 企业列表 vtent.
	std::vector<OrGroupinfo> vtOrgroup;     	    ///< 企业组织列表 vtOrgroup.
	std::map<std::string, std::vector<OrgUserinfo> > mporgUser;///< 组织用户列表 vtorgUser
	std::vector<EntAppinfo> vtEntApp;       	    ///< 企业应用列表 vtEntApp
	std::vector<LocalSearchMemberInfo> members;     ///<匹配到的群成员

};

/**************************************工作台应用群应用*********************************************************/
struct QueryMarketApplication{

	QueryMarketApplication() :pageNum(0), pageSize(0), deviceType(0), userID(0), appName(""), jsonStr(""), releaseType(0), gettype(0){}

	int32 pageNum;                 ///<页码
	int32 pageSize;                ///<页长
	int32 deviceType;              ///<类型 2（IOS），3（Android）
	int64 userID;                 ///<用户ID，预留类型，暂时不用输入
	std::string appName;  ///<应用名称 模糊查询用
	std::string jsonStr;     ///< json字符串，内部实体，根据查询类型解析
	int8 releaseType;        ///<查询类型;1.工作台应用市场展示应用,3.群应用（默认为1）
	int8 gettype;           ///<获取方式，默认为0，获取全部和隐藏应用，1 获取所有未忽略的应用
};
/**************************************工作台应用群应用*********************************************************/
/**************************************群主/管理员忽略/添加群应用入参*********************************************************/
struct IgnoreMarketAppBean{
	IgnoreMarketAppBean() :relationId(0), vestAppId(0), relationIdType(0), operatorId(0), operatorType(0){}
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
};
/**************************************群主/管理员忽略/添加群应用入参*********************************************************/

///查询标签
struct queryTag
{
	queryTag() :key(0) {}
	int32 key;
	std::string value;
};
///应用市场信息
struct SmallMarketAppInfo
{
	SmallMarketAppInfo() :appID(0), entID(0), ownerId(0), status(0), appType(0), defaultInstall(0), showInMy(0){}
	int64 appID;                   ///<应用ID
	int64 entID;                   ///<企业ID
	int64 ownerId;                 ///<所有者id
	int8 status;                   ///<状态 1或12启用，2或16停用，3或15删除，11、应用待审核 12、审核通过及启用 13、应用创建审核驳回 15应用删除 16、应用停用 20、应用号下架 21、应用号应用强制下架
	int8 appType;                  ///<类型：1(H5应用), 2(IOS应用), 3(Android应用), 4(内部应用), 5(快捷应用) 6(本地添加的快捷应用)
	int8 defaultInstall;            ///<默认安装 1 是 ，2 否
	int8 showInMy;                 ///<个人安全中心是否展示 1 是 ，2 否
	std::string appSign;            ///<应用标识
	std::string appName;            ///<应用名称
	std::string appIcon;            ///<应用图标		
	std::string appIconUrl;            ///<应用图标url地址	
	std::string appFunctintroduce;   ///<应用功能介绍
	std::string version;            ///<版本号	
	std::string mainUrl;            ///<H5首页
	std::string adminUrl;           ///<后台管理地址
	std::string myUrl;              ///<个人中心地址
	std::string packageName;         ///<包名
	std::string downloadUrl;         ///<下载地址
	std::string urlScheme;           ///<urlScheme
	std::string quickUrl;            ///<快捷应用地址
	std::string extend;              ///<扩展字段
	std::string activityName;         ///<activity
	std::vector<queryTag> tags; ///< 查询标签
	int8 sourceType;               ///< 应用来源 1：后台管理应用 2：开放平台应用
	int64 vestAppID;               ///< 应用对应的应用号id 
	int64 appTypeID;               ///< 应用分类id
	std::string appTypeName;       ///< 应用分类名称
	std::string introduce;         ///< 应用简介（edit by jss 2021/04/27）
};
/**********************************************应用市场分页查询,添加群应用*******************************/
struct SmallMarketAppPage{
	SmallMarketAppPage() : pageNum(0), pageSize(0), count(0), totalPage(0)
	{
		appInfoList.clear();
		extMap.clear();
	}
	int32 pageNum;                               ///<页码
	int32 pageSize;                              ///<页长
	int32 count;                                 ///<总数
	int32 totalPage;                             ///<总页数
	std::vector<SmallMarketAppInfo> appInfoList;  ///<应用列表
	std::map<int8, std::map<int64, SmallMarketAppInfo>> extMap; ///<为以后考虑，标识暂时1为工作台隐藏应用3为群隐藏应用（修订）
};
/**********************************************应用市场分页查询,群应用*******************************/

struct EnterpriseDictionary
{
	EnterpriseDictionary() :id(0), parentId(0) {}
	int32 id;                ///<组织ID
	int32 parentId;          ///<父组织ID
	std::string dicValue;    ///<字段的名字
	std::string dickey;      ///<字段的键值
	/** 扩展字段，格式为{"isEdit":0,"isFriend":0,"isInput":0,"isLogin":0,"isShow":0,"isStrange":0},
	isEdit:是否客户端可编辑;
	isFriend:客户端是否好友可见;
	isInput:是否必填字段;
	isLogin:是否登录项字段;
	isShow:客户端组织架构是否可见;
	isStrange:客户端是否陌生人可见*/
	std::string extend;      
};

///通讯录
class  PhoneBookContact
{
public:
	PhoneBookContact() :source(0)
	{}

public:
	std::string contactNum;   ///<联系人号码
	std::string name;         ///<联系人姓名
	int8 source;              ///<数据来源 1：手机通讯录； 2：qq好友；
    int8 area;                ///<号码归属地 1：国内； 2：国际；
};

///本地通讯录
class  localPhoneBook
{
public:
	localPhoneBook() :userId(0), flag(0), status(0)
	{}

public:
	std::string phone;   ///<联系人号码
	int64 userId;         ///<联系人ID
	int8 flag;            ///<标示
	std::string phoneName; ///<手机通讯录里的名称
	std::string userName; ///< 用户名称
	std::string userHead; ///< 用户头像
	int status;              ///外服人员为4
};

///上传通讯录后的推荐者
class RecommendContact
{
public:
	RecommendContact() :isBuddy(0){}
	PhoneBookContact pbContact;	//上传的联系人
	User contact;				//联系人信息
	User recommend;				//推荐者信息
	int8 isBuddy;               ///< 是否是好友标识，1表示是好友关系，2表示不是好友关系, 3表示等待验证
};

struct transferLocalData{
	transferLocalData() :version("0.0.1"), year(0), mon(0), day(0){};
	std::string filePath;///<要导入或导出文件的存放路径 

	std::string version;///<当前0.0.1
	/**导出时选择从那天开始 */
	int year;
	int mon;
	int day;
	int8 type;///<0:导出;1:导入;2:南京数据迁移
};

///p2p传文件请求
struct P2pSendFileReq
{
	P2pSendFileReq() :fileType(0), fileSize(0), fileSign(0), sendUserID(0){}
	int8        fileType; ///1:文件, 2:目录
	std::string fileName; ///文件名称
	int64       fileSize; ///文件大小
	/**
	* 发送文件的标识,响应的时候需要回传回去
	*/
	int64       fileSign; ///发送标识
	int64       sendUserID;///发送者ID
};

///p2p对象
struct p2pUser
{
	p2pUser() :userid(0), flag(0){}
	int64 userid; ///<用户ID
	int8  flag; ///<PC 0x01，移动 0x02
};

struct downloadFileInfo {
	downloadFileInfo() {
		fileType = 1;
		size = 0;
		finished = 0;
	}

	int8   fileType; /* 1:文件, 2:文件夹 */
	int64  size;    /* 当前文件大小, http上传时是总分片数 */
	int64  finished; /* 完成量, http上传时是已上传的分片数 */
	std::string   remotePath; /* 远端路径 */
	std::string   localPath;  /* 本地路径 */
};
//文件分片结果
struct fileFragmentationInfo {
	fileFragmentationInfo() {
		fileNumber = 1;
		burstSize = 0;
		isEncrypt = false;
	}

	std::string   fileID; /* 文件id */
	int64  fileNumber;    /* 分片数 */
	std::string   fileName; /*文件名 */
	std::string   fileHash; /* 文件hash */
	std::string   fileSize;  /* 文件大小 */
	std::string   filePath; /* 文件路径 */
	int32 burstSize;  /* 分片大小 */
	std::string   encryptKey;  /* 秘钥 */
	bool isEncrypt;  /* 是否加密 */
};
//子账号信息
struct SubServerInfo 
{
	SubServerInfo() :userId(0), type(0),topTime(0),serverHead(""){}
	std::string  addr;		///< 服务器地址
	int64        userId;	///< 用户ＩＤ
	std::string  name;		///< 登录账号名称
	std::string  avatar;	///< 头像
	std::string  account;	///< 账号
	std::string remark;		///< 备注
	int8         type;		///< 账号类型
	int64		topTime;  ///<置顶时间(毫秒)，0标识没有置顶
	std::string verImgPath; ///智能客服信息
	std::string serverHead; ///服务器头像
};
 struct upMsgCt {
	upMsgCt() :type(0){}
	int8 type;
	std::string PackName;///<包名
	std::string UserName;///<用户名
	std::string MsgNum;///<消息数
	std::string devtype;///<设备类型
};

 ///敏感词
 struct BadWord
 {
	 BadWord() : badWordType(0){}
	 int8 badWordType;     ///< 0不过滤 1使用*号 2禁止发送
	 std::vector<std::string> badWordList;   ///< 敏感词列表
 };
 struct reqEntAppInfo{
	 reqEntAppInfo() :pageNum(0), pageSize(0), type(0){}
	 int8  type;             ///< 1.企业号 2.应用号
	 int32 pageNum;          ///< 页码
	 int32 pageSize;         ///< 每页大小
 };

 struct oauthReq{
	 std::string appID;            ///< 应用ID
	 std::string userID;           ///< 用户ID
	 std::string accountType;      ///< 账户类型
	 Optional< std::string> account; ///< 账户
	 Optional< std::string> password;///< 密码
 };

 struct qVerifyCodes
 {
	 qVerifyCodes() :type(0), isSetUserIDs(false){}
	 Optional<int8> type;  ///< 类型 1.根据用户ID向用户发送短信(只根据语言发送，不处理内容)
	 std::vector<int64> userIDs; ///< 用户ID集合
	 bool               isSetUserIDs;
 };
 struct AuthUserBean 
 {
	 AuthUserBean() :userID(0), sex(0), year(0), month(0), day(0)
	 {
		 name = "";
		 area = "";
		 school = "";
		 portraitURL = "";
		 phoneNums.clear();
		 emails.clear();
	 }
	 int64 userID;                              ///用户ID
	 std::string name;                          ///用户名
	 int8 sex;                                  ///性别
	 std::string area;                          ///区域
	 int16  year;                               ///生日
	 int8   month;
	 int8   day;
	 std::string school;                        ///毕业学校
	 std::string portraitURL;                   ///头像地址
	 std::vector<std::string> phoneNums;        ///电话号码清单
	 std::vector<std::string> emails;           ///邮箱清单
 };

 ///用户注销信息
 struct UserAuthenticationInfo
 {
	 UserAuthenticationInfo() :logout_mode(1), type(0)
	 {
		 password = "";
		 authenticationCode = "";
	 }
	 int8 logout_mode;                        //注销模式   1:注销用户密码认证，自动注销模式 2:申请注销密码认证，手动注销模式
	 int8 type;                               ///类型
	 std::string password;                    ///密码
	 std::string authenticationCode;          ///注销验证码，type为5必须传
 };


 /*******************cloudService begin***********************/

 // 云盘上传查重信息
 struct CloudPreUpload
 {
	 CloudPreUpload()
	 {
		 user = 0;
		 sdkid = 0;
		 fsize = 0;
		 pid = 0;
		 sowner = 0;
		 ssdkid = 0;
	 }

	 int64 user;		//用户id
	 int64 sdkid;		// sdkid
	 std::string sha2;	// sha256 哈希值
	 std::string md5;	// md5
	 int64 fsize;		// 文件大小
	 int64 pid;			// 父节点id
	 std::string fname;	// 文件名
	 std::string ftype;	// 文件类型
	 std::string filePath; // 文件路径
	 int64 sowner;		// 共享目录拥有者 id
	 int64 ssdkid;		// 共享目录拥有者 id

 };

 // 云盘文件通用结构体
 struct CloudCommonParam
 {
	 CloudCommonParam()
	 {
		 user = 0;
		 sdkid = 0;
		 sowner = 0;
		 ssdkid = 0;
		 virtualid = 0;
		 dstpid = 0;
	 }
	 int64 user;		// 用户id
	 int64 sdkid;		// sdkid
	 int64 virtualid;	// 虚拟文件id
	 std::string name;	// 新文件 或 文件夹名
	 int64 sowner;		// 共享目录拥有者 id
	 int64 ssdkid;		// 共享目录拥有者 id
	 int64 dstpid;		// 目标id, 新的父节点 id

 };

 struct cloudCommonRet
 {
	 cloudCommonRet()
	 {
		 virtualid = 0;
		 atime = 0;
		 mtime = 0;
		 groupid = 0;
		 chtime = 0;
	 }
	 int64 virtualid;		// 虚拟文件id   -1 不存在需要 上传
	 int64 atime;			// 时间戳
	 int64 mtime;			// 创建时间
	 int64 chtime;			// 改变时间
	 std::string fname;		// 新文件名
	 int64 groupid;			// 共享组id

 };

 // 新云盘，返回被删除的文件信息
 struct delFileRet
 {
	 delFileRet()
	 {
		 virtualid = 0;
		 dtime = 0;
		 atime = 0;
	 }
	 int64 virtualid;
	 int64 dtime;
	 int64 atime;
 };

 struct returnSuc
 {
	 returnSuc()
	 {
		 virtualid = 0;
		 rtime = 0;
		 atime = 0;
		 mvtime = 0;
		 newVirtualid = 0;
		 cptime = 0;
		 ctime = 0;
	 }
	 int64 virtualid;
	 int64 rtime;
	 int64 atime;
	 int64 mvtime;
	 int64 newVirtualid;
	 int64 cptime;
	 int64 ctime;
	 int64 chtime;				// 改变时间
	 std::string msg; 
	 std::string fname;
 };

 typedef returnSuc returnFail;


 // 云盘 同步文件/文件夹
 struct cloudSyncFile
 {
	 cloudSyncFile()
	 {
		 type = 0;
		 user = 0;
		 sdkid = 0;
		 atime = 0;
	 }
	 int32 type;
	 int64 user;
	 int64 sdkid;
	 int64 atime;
 };

 // 云盘文件基本信息
 struct newCloudFileInfo
 {
	 newCloudFileInfo()
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
	 std::string fname;     //名字  (可能为空)
	 int32 type;			// 1 文件， 2 文件夹
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
	 int64 createid;		// 共享创建者id
	 int32 permission;		// 读写
	 int32 isShare;			// 0 未被共享， 1 被共享
	 int64 uploadid;		// 上传者 id
 };


 //云盘上传信息
 struct NewCloudUploadFileInfo
 {
	 NewCloudUploadFileInfo()
	 {
		 type = 0;
		 pid = 0;
		 user = 0;
		 sdkid = 0;
		 sowner = 0;
		 ssdkid = 0;
		 fileSize = 0;
		 localId = 0;
		 virtualid = 0;
	 }
	 int32 type;					// 上传类型 1 秒传 2 正常文件上传3 分片上传文件4 正常文件夹上传
	 int64 pid;						// 云盘父目录id 如果没有父目录，传0。
	 int64 user;					// 用户id
	 int64 sdkid;					// sdkid
	 int64 sowner;					// 共享目录拥有者 id
	 int64 ssdkid;					// 共享目录拥有者 sdkid
	 int64 virtualid;				// 文件id
	 std::string ftype;				// 文件类型
	 int64 fileSize;				//文件大小
	 int64 localId;					//唯一标识ID
	 std::string encryptKey;		//加密key
	 std::string  localPath;		///<本地文件地址
	 std::string fileName;			///<文件名，为空时，取localPath的文件名
	 
	 bool	isResume;				///<是否支持断点续传
	 bool   isEncrypt;				/// 是否加密
 };

 //云盘下载信息
 struct CloudDownloadFileInfo
 {
	 CloudDownloadFileInfo(){
		 localId = 0;
		 fileId = 0;
		 userId = 0;
		 sdkid = 0;
		 sowner = 0;
		 ssdkid = 0;
		 fileSize = 0;
		 bisResume = false;
	 }

	 int64  localId;				//唯一标识ID
	 int64  fileId;					// 文件id
	 int64  userId;					// 用户id
	 int64  sdkid;					// sdkid
	 int64  sowner;					// 共享目录拥有者ID
	 int64  ssdkid;					// 共享目录拥有者 sdk ID
	 std::string localPath;			///< 文件本地保存路径 localPath.
	 std::string uri;				///< 远程路径.   先预留，应该没有用
	 std::string fileName;			///< 真实的文件名 fileName
	 int64 fileSize;				/// 文件大小
	 bool        bisResume;			///<是否断点下载
 };

 // 云盘 共享文件
 struct cloudShare
 {
	 cloudShare()
	 {
		 user = 0;
		 sdkid = 0;
		 virtualid = 0;
		 vecRead.clear();
		 vecWrite.clear();
		 srcUser = 0;
		 newPermission = -1;
		 groupid = 0;
		 dstUser = 0;
		 srcsdkid = 0;
		 sowner = 0;
		 ssdkid = 0;
		 vecChangeuser.clear();
	 }
	 int64 user;
	 int64 sdkid;
	 int64 virtualid;					// 目标文件 id
	 std::vector<int64> vecRead;
	 std::vector<int64> vecWrite;
	 int64 srcUser;						// 共享提供者 userid
	 //  = -1, 请求所有用户 提供的共享目录信息
	 //  >0  请求 userid 用户 提供的共享目录信息
	 int64 srcVirtualid;				// 共享目录文件 id
	 //  = -1, 忽略
	 // 若 srcuser > 0 && srcvid > 0，则服务端返回用户srcuser 共享给我的srcvid目录信息
	 int64 srcsdkid;					// 共享提供者 sdkid
	 int32 newPermission;				// 0 读权限， 1  写权限， 2 取消共享
	 int64 groupid;						// 共享组id
	 int64 dstUser;						// 改变目标用户
	 int64 sowner;						// 共享目录拥有者id
	 int64 ssdkid;						// 共享目录拥有者 sdkid
	 std::vector<int64> vecChangeuser;	// 共享人 userid

 };

 struct cloudShareRet
 {
	 cloudShareRet()
	 {
		 userid = 0;
		 code = 0;
		 virtualid = 0;
		 permission = 0;
		 sdkid = 0;
		 createid = 0;
	 }
	 int64 userid;									// 共享失败的 userid
	 int32 code;
	 std::string msg;
	 int64 virtualid;
	 int32 permission;
	 std::string targetids;
	 int64 sdkid;									// 共享提供者 id
	 int64 createid;								// 共享创建者 id				
	// std::vector<newCloudFileInfo> vecShareFile;	// 获取别人共享文件信息
 };

 // 返回 共享给别人的文件信息
 struct cloudShareOtherRet
 {
	 cloudShareOtherRet()
	 {
		 virtualid = 0;
		 atime = 0;
		 groupid = 0;
		 vecRead.clear();
		 vecWrite.clear();
	 }
	 int64 virtualid;						// 目录
	 int64 atime;
	 int64 groupid;							// 共享组id
	 std::vector<int64> vecRead;
	 std::vector<int64> vecWrite;
 };

 struct cloudContactInfo{
	 cloudContactInfo(){
		 user = 0;
		 roleid = 0;
		 orgId = 0;
		 //createAt = 0;
		 //updateAt = 0;
		 //deleteAt = 0;
	 }
	 int64 user;							// 用户id
	 std::string userName;					// 用户名
	 int64 roleid;							// 角色名
	 //int64 createAt;						// 创建用户时间
	 //int64 updateAt;
	 //int64 deleteAt;
	 std::string companyTag;					// 公司标志
	 std::string department;				// 部门
	 //std::string email;						// 邮箱
	 //std::string phoneNum;					// 手机号
	 int64 orgId;						// 组织id

 };

 // 查询云盘上传/下载 信息
 struct cloudTransferInfo{
	 cloudTransferInfo(){
		 pid = 0;
		 user = 0;
		 sdkid = 0;
		 sowner = 0;
		 ssdkid = 0;
		 virtualid = 0;
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

	 int64 virtualid;					// 文件id
	 int64 fileSize;				// 文件大小	 
	 std::string fileName;			///<文件名，为空时，取localPath的文件名
	 std::string encryptKey;		// 加密key 
	 std::string uploadPath;		///<本地文件地址
	 std::string md;				/// 文件 md5码
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

 //云盘上传信息
 struct CloudUploadFileInfo
 {
	 CloudUploadFileInfo() : pid(0),fileSize(0), isResume(false)
	 {}
	 int64 pid;						//云盘父目录id 如果没有父目录，传0。
	 std::string fileCode;			///< 云盘父目录code
	 int64 fileSize;					//文件大小
	 int64 localId;					//唯一标识ID
	 std::string encryptKey;		//加密key
	 std::string  localPath;		///<本地文件地址
	 std::string fileName;			///<文件名，为空时，取localPath的文件名
	 bool	isResume;				///<是否支持断点续传
 };


//云盘添加文件信息
 struct CloudAddFileInfo
 {
	 CloudAddFileInfo() : pid(0), ownerId(0), encryptFileSize(0),
						 fileSize(0), fileType(0), fileId(0)
	 {}
	 int64 pid;						//云盘父目录id 如果没有父目录，传0。
	 int64 ownerId;					//拥有者id
	 int64 uploaderId;				//上传者id
	 std::string uploaderName;		//上传者名字
	 int64 encryptFileSize;			//加密文件大小
	 int64 fileId;					//文件ID
	 std::string fileCode;			//文件code
	 std::string fileName;			//文件名
	 std::string filePath;			//文件路径
	 std::string fileRemark;		//文件备注
	 std::string fileClass;			//文件分类
	 int64 fileSize;					//文件大小
	 std::string fileSuffix;		//文件后缀名
	 int8 fileType;					//类型 1.文件  2.文件夹  3.团队文件夹  4 特殊文件夹
	 std::string md5Hash;			//md5码	
	 std::string encryptKey;		//加密key
 };

 //云盘文件信息
 struct CloudFileInfo : public CloudAddFileInfo
 {
	 CloudFileInfo() : createTime(0), updateTime(0),image(false),validity(0)
	 {}
	 int64 createTime;				//创建时间
	 int64 updateTime;				//更新时间
	 bool image;					//是否为图片
	 int64 validity;					//有效性 天
     int64 roleId;
 };

 //云盘用户信息
 struct CloudUserInfo
 {
	 CloudUserInfo() : userId(0), sdkid(0),createdAt(0), updatedAt(0), useSpace(0), totalSpace(0), status(1)
	 {
		 uploadNum = 1;
		 downloadNum = 1;
		 keepTime = 7;
		 uploadMaxSpeed = 0;
		 downloadMaxSpeed = 0;
		 systemNotify = 0;
	 }
	 int64 userId;
	 int64 sdkid;
	 std::string userName;
	 std::string headImg;
	 int64 createdAt;
	 int64 updatedAt;
	 ///已使用容量(KB)
	 int64 useSpace;
	 ///用户云盘总容量(KB)
	 int64 totalSpace;
	 ///状态 1.未升级 2.升级中 3.正常
	 int8 status;
	 ///最大同时上传文件个数
	 int32 uploadNum;
	 ///最大同时下载文件个数
	 int32 downloadNum;
	 ///文件在回收站保留多久后自动删除
	 int32 keepTime;
	 ///上传最大速度
	 int64 uploadMaxSpeed;
	 ///下载最大速度
	 int64 downloadMaxSpeed;
	 ///是否开启通知推送  0 关闭系统推送， 1，开启系统推送
	 int32 systemNotify;
 };
 struct TeamMemberInfo
 {
	 TeamMemberInfo() :fileId(0), createTime(0), updateTime(0), userId(0), roleId(0)
	 {}
	 int64 fileId;			//文件信息
	 std::string headImg;	//头像
	 int64 createTime;		//创建时间
	 int64 updateTime;		//上传时间
	 int64 userId;			//用户id
	 std::string userName;  //用户名
	 int64 roleId;	
	 std::string roleName;	
 };

 struct BaseRoleInfo
 {
	 BaseRoleInfo() :isShow(0), orderNum(0), totalSize(0), uploadSize(0)
	 {}
	 int8 isShow;
	 std::string name;	
	 int64 orderNum;		
	 std::string permission;
	 int64 totalSize;
	 int64 uploadSize;
 };

 struct CloudRoleInfo : public BaseRoleInfo
 {
	 CloudRoleInfo() :createTime(0), roleId(0), roleType(0), status(0), updatedTime(0)
	 {}
	 int64 createTime;	
	 int64 roleId;
	 int8 roleType;
	 int8 status;
	 int64 updatedTime;
 };

 struct CloudPermission
 {
	 CloudPermission() :isCreateTeam(0), isDelete(0), isDownLoad(0), isManager(0),
	 isReName(0), isRead(0), isUpload(0), roleId(0), totalSize(0), uploadSize(0)
	 {
	 }
	 int8 isCreateTeam;
	 int8 isDelete;
	 int8 isDownLoad;
	 int8 isManager;
	 int8 isReName;
	 int8 isRead;
	 int8 isUpload;
	 int64 roleId;
	 int64 totalSize;
	 int64 uploadSize;
 };

 struct FolderOpenBean {
	 FolderOpenBean() : pid(0), ownerId(0), fileType(0), timestamp(0), pageNum(0), 
		 pageSize(0), userId(0), roleId(0)
	 {
	 }
	 int64         pid; // 文件夹Id
	 int64         ownerId; // 所有者Id
	 int           fileType;// 文件类型 1 文件 2 文件夹 3.团队文件夹
	 int64         timestamp; // 时间戳 只查询更新时间>时间戳的数据
	 std::string   sort; // 排序方式
	 int           pageNum; // 页码
	 int           pageSize; // 页长
	 int64         userId;
	 int64         roleId;
	 std::string   fileCode;
 };

 struct smallMarketAppType
 {
	 smallMarketAppType() :appTypeID(0){}
	 int64 appTypeID;         ///< 应用分类id
	 std::string appTypeName; ///< 应用分类名称
 
 };
 

 /*******************cloudService end***********************/

  //日志文件头信息
 struct LogHeadTag
 {
	 LogHeadTag() :id(0) {}
	 int64 id;							
	 std::string project;				
	 std::string deviceType;			
	 std::string os;					
	 std::string osVersion;				
	 std::string appVersion;			
	 std::string sdkVersion;			
	 std::string netType;				
 };
 
 struct getReqAtMsg{
	 getReqAtMsg() :groupID(0), beginTime(0), endTime(0), maxCount(0), atType(0){}

	 int64    groupID;           ///< 群ID
	 int64    beginTime;         ///< 起始时间
	 int64    endTime;           ///< 结束时间
	 int32    maxCount;          ///< 最大返回的消息数量,消息排序按时间倒叙排列。
	 int8     atType;            ///< 0.别人@我，1.我@别人
 };

 struct UserContact
 {
	 UserContact() :type(0), status(0)
	 {}
	 int8 type;			///< 账号类型 1.电话号码 3.email 4.userID 6.accountName
	 std::string name;	///< 帐号名称
	 int8 status;		///< 状态 1.启用， 2.禁用, 5.锁定, 6.冻结 
 };

 ///获取邀请码参数
 struct InviteCodeParam
 {
	 InviteCodeParam() :createUserID(0), digit(0), effectiveSeconds(0), effectiveCount(0), value_byte(0){}
	 
	 int64 createUserID;			///< 生成邀请码的用户的userid
	 int32 digit;					///< 生成邀请的位数
	 int64 effectiveSeconds;		///< 有效秒数（默认2天） 
	 int32 effectiveCount;			///< 有效次数（默认无数次）
	 std::vector<UserContact> consumeAccount; ///< 有效账号 不传时默认任何账号都能使用
	 int8 value_byte;				///<二维码分享加好友开关//  [10/27/2020 admin]
	 std::string extData;			///<好社工邀请码参数
	 std::string groupName;         ///< 群名称
 };
 ///修改邀请码参数
 struct setInviteCodeParam
 {
	setInviteCodeParam():inviteCode(""), setupUserID(0), operationType(0), effertiveTime(0), inviteCount(0),buddySwitch(0), deviceType(0){}
	 std::string inviteCode;           // 邀请码 
	 int64 setupUserID;                // 用户id（生成该邀请码的人）
	 int8 operationType;               // 操作类型（1-修改邀请码；2-设置邀请码失效）
	 int64 effertiveTime;              //邀请码有效期（秒，永久传-1）
	 int32 inviteCount;                //邀请人数
	 int8 buddySwitch;                 //是否自动添加好友
	 int8 deviceType;                  //设备类型 1：PC；2：手机；3：pad；4：网页
 };

 ///获取邀请码分享列表入参
 struct inviteCodeShareParam
 {
	 inviteCodeShareParam() :setupUserID(0), groupID(0) {}
	 int64 setupUserID;        // 用户id（生成该邀请码的人）
	 int64 groupID;            // 用户所查询的群id
 };

 ///邀请码分享记录信息
 struct inviteCodeShareList
 {
	 inviteCodeShareList() :inviteCode(""), setupUserID(0), shareTime(0), effectiveTime(0), inviteCount(0), invalidTime(0), buddySwitch(0), registerCount(0), buddyCount(0), addGroupCount(0), inviteCodeStatus(0), groupName(""), inviteCodePic(""){}
	 std::string inviteCode;           // 邀请码
	 int64 setupUserID;                // 用户id（生成该邀请码的人）
	 int64 shareTime;                  // 分享时间(时间戳)
	 int64 effectiveTime;              // 有效期
	 int64 invalidTime;                // 停止时间
	 int32 inviteCount;                // 邀请人数
	 int8 buddySwitch;                 // 是否与被邀请人添加好友
	 int32 registerCount;              // 已注册人数
	 int32 buddyCount;                 // 已加为好友人数
	 int32 addGroupCount;              // 已被邀请加群人数
	 int8 inviteCodeStatus;            // 邀请码状态（1-分享中；2-已结束）
	 std::string groupName;            // 群名称
	 std::string inviteCodePic;        // 邀请码图片
 };

 ///意见反馈
 struct IssueFeedBack
 {
	 IssueFeedBack() :id(0), questionID(0), isNecessary(0), operatingSystem(0), feedbackPersonID(0){}
	 ///< 主键ID,可不用设置
	 int id;
	 ///< 问题ID(1：崩溃；2：掉线；3：卡顿；4：其他问题；5：改进建议)
	 int questionID;
	 ///< 问题名称
	 std::string questionName;
	 ///< 问题描述
	 std::string questionDescription;
	 ///< 是否必现 1：是；2：否
	 int8 isNecessary;
	 ///< 操作系统 1:安卓、2:IOS、3:Windows、4:MAC、5:网页
	 int8 operatingSystem;
	 std::string clientVersion;
	 int64 feedbackPersonID;
	 std::string feedbackPersonName;
	 std::string feedbackPersonOrg;
	 ///< 提交时间
	 std::string createDate;
	 ///< 反馈截图 最多四张,以英文分号;隔开
	 std::string screenPic;
	 ///< 日志地址
	 std::string logUrl;
	 ///操作系统版本
	 std::string operatingSystemVersion;
 };

 ///工作台轮播图实体 返回类型  
 struct WorkbenchBanner
 {
     WorkbenchBanner() : type(0), displayStatus(0), sortNum(0), createTime(0), updateTime(0)
     {}
     std::string id;
     std::string title;         ///< 标题 
     std::string cover;         ///< 封面  只支持jpg、png 
     int32 type;                ///< 类型  1：外链，2:非外链 
     ///< 显示状态  1：显示，2：隐藏. 
     int32 displayStatus;
	 std::string linkUrl;		// 外链地址
     ///< 地址（外链-完整路径；非外-存轮播图详情页的相对地址. 
     std::string detailUrl;
     ///< 富文本内容. 
     std::string content;
     ///< 排序 
     int32 sortNum;     
     int64 createTime;          ///< 创建时间 
     int64 updateTime;          ///< 更新时间 
 };

 ///帮助系统信息 返回类型  
 struct HelpSystemInfo
 {
     HelpSystemInfo() : id(0), parentId(0), helpType(0), linkType(0),
     displayStatus(0), sortNum(0), createTime(0), updateTime(0), status(0)
     {}
     int64 id;               ///< 帮助ID 
     std::string title;      ///< 标题 
     int64 parentId;         ///< 父帮助ID 
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

 ///查询文件是否过期或者文件延期返回
 struct DelayFileResp
 {
	 DelayFileResp() :delayCode(0) {}
	 ///< 当入参delayType=1时，0.全部未过期   1.部分过期   -1.链接地址错误 -2.传的delayType错误
	 ///< 当入参delayType=2时，0.全部延期成功 1.部分延期成功 -1.链接地址错误 -2.传的delayType错误
	 int32 delayCode;
	 std::vector<std::string> fileUrls; ///过期的文件链接路径
 };

 struct OAuthResult
 {
	 OAuthResult() :scope(0), silentAuth(0) {}
	 std::string appName;	///< 应用名
	 std::string appIcon;	///< 应用图标
	 int32 scope;			///< 授权范围
	 std::string authCode;	///< 授权码
	 int8 silentAuth;		///< 静默授权开关 1.开 2.关
 };
 /**
 * \brief 设置群文件永久入参
 */
 struct SetGroupFileTermParam
 {
	 SetGroupFileTermParam() : fileId(0),groupId(0), userID(0), fileTerm(0)
	 {}
	 int64 fileId;         ///文件id
	 int64 groupId;		   ///群ID
	 int64 userID;		   ///上传者ID
	 int8 fileTerm;		   ///< 1.临时 2.永久
	 std::string fileUrl;  ///群文件url
 };
 /**
 * \brief 获取群文件入参
 */
 struct GetGroupFile
 {
	 GetGroupFile() : targetID(0), msgBeginID(0), msgOffset(0), offsetFlag(0), fileTerm(0)
	 {}
	 int64     targetID;	///< 目标ID 
	 int64     msgBeginID;	///< 起始消息号  or 起始时间
	 int32     msgOffset;	///< 消息列偏移量
	 int8      offsetFlag;	///< 偏移标志  0.降序  1.升序 
	 int8      fileTerm;    ///按文件有效期类型获取 0. 获取所有 1.临时 2.永久
	 int8	   fileType;	///< 按文件类型获取 0.所有 6文档 5图片 89视频 3音频 与msgType一致
 };

 struct GroupDocAttribute:public Fileinfo{
	 GroupDocAttribute() : status(0)
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

	 std::string encryptAlgorithm; // 加密算法optional
	 std::string hashcode; // 文件hash值 optional
	 int8 status; // 1: 新增 2: 改名 3: 删除
	 int64 createAt;
	 int64 updateAt;
	 int64 deleteAt;
	 int64 version;
	 int64 lastModifiedBy;//optional 
	 int64 validityDays;  // 群文档有效期
	 int8_t permission;//0 只读 1可读可写 默认是0
	 int64_t modContentVersion; //最后一次在线编辑 version
 };

 struct FileExpiryAttribute :public Fileinfo{
	 FileExpiryAttribute() : isSwitchOn(0)
	 {
		 fileID = 0;
		 fileUrl = "";
		 targetID = 0;
		 targetName = "";
		 fromUserID = 0;
		 fileName = "";
		 uploadAt = 0;
		 validDays = 3;
	 }
	 int64 fileID;											///<文件ID, 主键
	 std::string fileUrl;									///< 文件url,也具有唯一性
	 int64 targetID;									    ///< 人/群ID
	 std::string targetName;							///< 人/群名称
	 int isSwitchOn;     						            ///<过期文件提醒开关，用不到
	 int64 fromUserID;									///<人/群名称
	 std::string fileName;								///< 文件名称
	 int64 uploadAt;										///< 上传时间
	 int validDays;										///< 有效期天数
	 //int flag;												///< 0未下载，1已下载
	 //int status;											///< 0未过期，1已过期
	 //std::string md5Code;
	 //std::string hashCode;
	// int fileCount;										///< 过期文件数量
	// int64 ext1;											///< 扩展字段1
	// int64 ext2;											///<扩展字段2
	// std::string ext3;									///<文扩展字段3
	// std::string ext4;									///<扩展字段4
	//int64 expiryDate;									///< 过期时间
 };

 struct FileExpiryResult :public Fileinfo{
	 FileExpiryResult() 
	 {
		 targetID = 0;
		 status = 0;
	 }
	 int64 targetID;									///<人/群ID,
	 int status;     						            ///<是否有新未下载文件将过期文件需要提醒，0不需要提醒，1需要提醒
 };

 struct FileExpiryInfoStore :public Fileinfo{
	 FileExpiryInfoStore()
	 {
		 fileID = 0;
		 targetID = 0;
		 isSwitchOn = 0;
		 strDate = "";
	 }
	 int64 fileID;									///<maxMsgID, 主键
	 int64 targetID;								///< 人/群ID
	 int isSwitchOn;     						    ///<过期文件提醒开关
	 std::string strDate;   						///<2021-11-01
	// int status;				//是否需要提醒
 };

 //群文档上传下载结构体  edit by :jss
 struct GroupDocUpdownInfo :public Fileinfo{
	 GroupDocUpdownInfo() :status(0), version(0)
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
	 int64 validityDays;                             // 群文档有效期
	 int8_t permission;//0 只读 1可读可写 默认是0
	 int64_t modContentVersion; //最后一次在线编辑 version
 };

 /**
 * \brief 工作台应用房间信息
 */
 struct AppRoomInfo
 {
	 AppRoomInfo() :id(0) {}
	 int64 id;							 //房间id
	 std::string name;				//房间名称
	 std::string icon;                //房间图标
	 std::vector<int64> mems;  //房间里成员应用id
 };
 /**
 * \brief 设置工作台应用顺序信息
 */
 struct  AppOrderInfo
 {
	 AppOrderInfo() :id(0), type(0), order(0){}
	 int64 id;		//房间id或应用id
	 int8 type;		// 1、房间 2、应用 3、本地应用
	 int32 order; //排序位置
	 std::vector<int64> apps;  //type是房间时，房间成员的顺序，按vector的下标顺序为排序位置信息
 };
 /**
 * \brief 工作台应用列表信息
 */
 struct MarketAppGroup
 {
	 MarketAppGroup() :id(0), type(0){}
	 int64 id;				//房间id或应用id
	 int8 type;				// 1、房间 2、应用 3、本地应用
	 std::string name;  //房间名称或应用名称
	 std::string icon;   //房间图标
	 std::string url;   //本地应用Url
	 std::vector<SmallMarketAppInfo> apps; ////type是房间时,为房间成员应用信息，type为应用时，为应用详细信息
 };
 /**
 * \brief 本地应用信息
 */
 struct LocalAppInfo
 {
	 LocalAppInfo() :appId(0){}

	 int64 appId;					   //本地应用id
	 std::string name;				//本地应用名称
	 std::string icon;                //本地应用图标
	 std::string url;                  //应用对应的url
 };
 /**
 * \brief 群议题结构
 */
 struct GroupIssue
 {
	 GroupIssue() :id(0), groupId(0),createrId(0),createTime(0) {}
	 int64 id;			//议题id
	 int64 groupId;		//群id
	 int64 createrId;	//创建者id
	 int64 createTime;	//议题创建时间
	 std::string name;  //议题名称
 };

 ///JssdkAuth认证信息
 struct JssdkAuthInfo{
	 JssdkAuthInfo() :appID(0), timeStamp(0){}
	 int64 appID;
	 int64 timeStamp;
	 std::string noncestr;
	 std::string url;
	 std::string signature;
	 std::vector<std::string> jsApiList;
 };

 ///AppListMenuCode 栏目的应用列表
 struct AppListMenuCode{
	 AppListMenuCode() :pageNum(0), pageSize(0), deviceType(0),userID(0){}
	 int32 pageNum;			//页码
	 int32 pageSize;			//页长
	 int32 deviceType;		//类型
	 int64 userID;				//用户ID
	 std::string appName;		//应用名称，模糊查询用
	 std::string channels;		//应用名称发布渠道
 };

 /**
 * \brief jssdk认证
 */
 struct GroupJssdkAuth
 {
	 GroupJssdkAuth() :appID(0),  timeStamp(0) {}
	 int64 appID;		//
	 std::string url;		    //url
	 std::vector<std::string> jsApiList;	//
	 //std::string jsApiList;
	 int64 timeStamp;	//时间戳
 };

 /**
 * \brief 自定义菜单栏目信息
 */
 struct GroupAppListMenuResult
 {
	 GroupAppListMenuResult() :appID(0), appType(0){}
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
 struct AppListMenuInfo{
	 AppListMenuInfo() :resultCode(0){}
	 int8 resultCode;		//0成功 - 1失败

	 std::vector<GroupAppListMenuResult> menuInfos;	 //resultData:Array

 };
 /**
 * \brief 群公告信息
 */
 struct GroupAnnouncementInfo
 {
	 GroupAnnouncementInfo() : announcementID(0), groupID(0), createUserID(0), createDt(0)
	 {}
	 int64 announcementID;  //公告Id
	 int64 groupID;             //群Id
	 int64 createUserID;     //创建者Id
	 int64 createDt;           //创建时间
	 std::string content;        //公告内容
 };
 /**
 * \brief 获取群公告列表入参
 */
 struct GetGroupAnnouncementListParam
 {
	 GetGroupAnnouncementListParam() : lastSourceID(0), groupID(0), userID(0), pageSize(20)
	 {}
	 int64 lastSourceID;  /*已拉取到的最终群公告id*/
	 int64 groupID;        /*群id*/
	 int64 userID;          /*用户id*/
	 int32 pageSize;      /*每页大小 默认20*/
 };
 /**
 * \brief 获取群公告列表返回
 */
 struct GroupAnnouncementList
 {
	 GroupAnnouncementList(){}
	 std::vector<GroupAnnouncementInfo> list;
 };


 ///全局免打扰模式信息
 struct globalNoDisturbModeInfo
 {
	 globalNoDisturbModeInfo(): startTime(0),endTime(0),isOpen(false){}
	 int32 startTime;
	 int32 endTime;
	 std::string name;
	 bool isOpen;
 };
 ///设置登录记录
 struct DeviceLoginRecord
 {
	 DeviceLoginRecord() : userID(0), loginTime(0), deviceType(0){}
	 int64 userID;  // 用户ID
	 int64 loginTime;  //登录时间 
	 int8 deviceType;  //设备类型 
	 std::string deviceInfo; //设备信息 
	 std::string macCode;  //mac地址 
	 std::string loginIP;  // 登录IP 
	 std::string loginCity;  //登录地址 
 };

 ///工作密集
 struct Security
 {
	 Security() : userID(0), level(0), operateTime(0), operateUserId(0){}
	 int64 userID;  // 用户ID
	 int32 level;  //等级
	 int64 operateTime;  //操作时间
	 int64 operateUserId; //操作人用户ID
	 std::string name;  //密级名称
	 std::string color;  //密级颜色
 };

 /**
 * \brief 消息提醒结构
 */
 struct reminderMsg
 {
	 reminderMsg() :reminderId(0), receiverUserId(0), reminderSendTime(0), reminderMsgId(0), sourceId(0) {}
	 int64 reminderId;                                ///消息提醒id，发送时不赋值
	 int64 receiverUserId;                            ///接收者用户ID,设置消息提醒的人，a用户设置了消息提醒，时间戳到达时服务器会发送给a用户
	 int64 reminderSendTime;                          ///消息提醒发送时间（时间戳）
	 int64 reminderMsgId;                             ///需要提醒的消息ID，关联消息id
	 int64 sourceId;                                  ///原消息发送者ID（用户或群），原消息所在的会话id，跳转或显示头像使用
	 SSharedPtr<model::Msg> msg;                                 ///原始消息数据
 };

 /**
 * 待办事项
 */
 struct agencymsg{
	 agencymsg() :appId(0), userId(0), agencyCount(0), agencyStatus(0), updateAtTime(0){}
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
 struct ToDoTaskMsg {
	 ToDoTaskMsg() : targetID(0), appID(0), taskID(0), messageID(0), urgent(0), finished(0), createTime(0), updateTime(0) {
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

	 std::string title; // 标题
	 std::string	content; // 内容说明
	 std::string	bID; //  业务方自己的唯一主键
	 std::string	fileds; // 补充的内容, markdown形式展示
	 std::string	button; // 业务动作，确定；其他业务可以扩展多个动作
	 std::string	detailUrl; //  消息正文的链接URL
	 std::string	picUrl; // 消息中的图片
	 std::string	userList; //  参与人员, 多个人员逗号分隔
	 int	isShowSession; // 客户端根据该字段判断展示位置(1展示会话不展示工作台; 2不展示会话, 展示工作台; 3展示会话和工作台; 4不展示会话和工作台)
	 std::string tag; // 消息标签，最多支持4个中文字符，12个英文字符, 最多支持6个
 };
 struct agencyTaskMsg{
	 agencyTaskMsg() :totalCount(0), totalPage(0){}
	 void init()
	 {
		 ToDoTaskMsgs.clear();
	 }
	 std::vector<ToDoTaskMsg>  ToDoTaskMsgs;
	 int64 totalCount;
	 int64 totalPage;
 };
 /* 新待办事项结构体END */
 /**
 *  \biref  根据用户ID获取用户登录的设备信息,豆豆版本
 */
 struct LoginClientRecord{
	 LoginClientRecord() :userID(0), loginTime(0), clientType(0), deviceType(0){}
	 int64 userID;				//用户ID
	 int64 loginTime;			//登录时间
	 int8  deviceType;			//登录设备类型
	 int8  clientType;			//client类型
	 std::string deviceInfo;	//登录设备信息
	 std::string clientVersion; //client版本
	 std::string SDKID;			//SDKID
 };

 /**
 * 应用帮助查询
 */
 struct SmallAppHelp{
	 SmallAppHelp() :id(0), appId(0), parentId(0), helpType(0), articleType(0), sortNum(0) {}
	 int64 id;//帮助id
	 int64 appId;// 公共号（应用号）id 
	 int64 parentId;//帮助父id 
	 std::string title;//标题
	 int8 helpType;//帮助类别（1：分类，2：文章）
	 int8 articleType;//1:外链；2:文件；3:自定义图文
	 std::string linkUrl;//外链地址
	 std::string fileUrl;//文件地址（客户端原生预览）
	 std::string detailUrl;//文章地址（vrvxin web预览）/vrvxin/help/toDetails.do?id={id} 
	 int32 sortNum;//排序值
 };

 /*
 * 用户对公共号的设置
 */
 struct strc_UserToAppConfig {
	strc_UserToAppConfig() :appId(0), timestamp(0), type(1), value(1)
	{}
	int64 appId;      
	int64 timestamp;  
	int8 type;        
	int32 value;
 };
 /*
 用户绑定的后台管理员角色信息
  [2/25/2021 zhuohc]
 */
 struct AdminRoleInfo{
	 bool superAdmin;				//是否是超级管理员，true是，false否
	 std::string adminName;		//管理后台绑定人员名称
	 std::string adminAccount;	//管理后台绑定人员帐号
 };
 /*
 用户绑定的后台管理员角色信息
 [3/8/2021 zhuohc]
 */
 struct AdminRoleInfoJson{
	 std::string roleInfoResult;		//管理后台绑定人员信息
 };
 //用户设置信息结构体
 struct PersonalDataSwitch{
	 PersonalDataSwitch() :currentUserId(0), switchType(0), SDKID(0) {}
	 /** 用户 id **/
	 int64 currentUserId;
	 /** 21:群验证方式 **/
	 int32 switchType;
	 /**
	 *	switchType = 21 :1 群邀请需要验证   2  不允许群邀请  3 群邀请不需要验证
	 **/
	 std::string value;
	 /** SDKID **/
	 int64 SDKID;
	 /** 扩展字段 **/
	 std::string extendValue;
 };


 struct ClientMenuSet{
	 ClientMenuSet() :id(0), type(0), isShow(0), isDefaultPage(0), isOriginIcon(0), sortId(0) {}
	 /* id */
	 int32 id;
	 /* 客户端菜单类型 1.内置不可关闭菜单;2.内置可关闭菜单;3.用户自定义菜单 */
	 int8 type;
	 /* 客户端菜单code 唯一 */
	 std::string code;
	 /* 客户端菜单name JSON格式字符串 {"zh":"zhname","en":"enname"} */
	 std::string name;
	 /* 客户端菜单是否开启 1.是;2.否 */
	 int8 isShow;
	 /* 客户端默认展示页 1.是;2.否 */
	 int8 isDefaultPage;
	 /* 是否是原生内置图标 */
	 int8 isOriginIcon;
	 /* 客户端默认展示图标 */
	 std::string defaultIcon;
	 /* 客户端选中展示图标 */
	 std::string clickIcon;
	 /* 客户端菜单拓展字段 */
	 std::string extend;
	 /* 客户端菜单排序字段 */
	 int32 sortId;
 };
 struct OutEntNodeInfo {
	std::string nodeID;     ///< 节点ID（唯一)
	std::string nodeName;   ///<节点名
	std::string nodeType;  ///< 企业类型
 };

 struct BifactorSt
 {
	 BifactorSt() :bTips(0), nSubType(0), nTargetId(0), nOperater(0), nMessageId(0), nSendLoginTime(0) {}
	 bool bTips;       //是否要弹框
	 int8 nSubType;   //子消息类型
	 int8 nOperater; //用户操作 1同意 2拒绝
	 int64 nMessageId; //消息ID
	 int64 nTargetId;  //目标ID
	 int64 nSendLoginTime;
	 std::string szAdminName; //管理员姓名
 };

 struct ElevatorAuthority
 {
	 int64 elevatorUserId; // 提权人员userId
	 int64 superUserId;  // 超级用户userId
	 std::string authorityCode; // 权限code/提权记录信息
	 int64 createTime; //创建时间
	 int64 updateTime; //更新时间
 };
 ///应用市场信息
 struct MarketAppInfo
 {
	 MarketAppInfo() :appID(0), mustUpdate(2) {}
	 int64 appID;                   ///<应用ID
	 int8 appType;                  ///< 类型：1(H5应用), 2(IOS应用), 3(Android应用), 4(内部应用), 5(快捷应用)
	 std::string appSign;            ///<应用标识
	 std::string appName;            ///<应用名称
	 std::string appIcon;            ///<应用图标		
	 std::string appIconUrl;            ///<应用图标url地址	
	 std::string version;            ///<版本号	
	 std::string packageName;         ///<包名
	 std::string downloadUrl;         ///<下载地址
	 std::string activityName;        ///<activity
	 std::string urlScheme;           ///<urlScheme
	 std::string updateExplain;       ///<更新说明
	 int8 mustUpdate;               ///< 1,必须升级，2不必须 默认为2
 };

 //隐私中搜索信息
 struct stPersionSearchSetting
 {
	 stPersionSearchSetting()
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

 struct TokenInfo {
	 TokenInfo()
	 {
		 expireTime = 0;
		 userId = 0;
	 }
	 std::string commonToken; //返回的值
	 int64 userId;
	 int64 expireTime;
 };

 struct CommonTokenRsp {
	 std::string message;//返回码描述
	 TokenInfo commonTokenInfo; //返回结果结构体
 };

//组合指令消息提醒
 struct stCombinationOrderRemind
 {
	 stCombinationOrderRemind()
	 {
		 delayTime = "";
		 remindType = 0;
	 }
	 std::string delayTime;//等待提醒的时间 加时间单位 比如10m 表示10分钟
	 int8 remindType;//位开关 对应的二进制位为1表示开启 0表示关闭 从右往左第1位表示响铃 第2位表示振动  第3位表示短信
 };

 //组合指令模板
 struct stCombinationOrder
 {
	 stCombinationOrder()
	 {
		 bitSwitch = 0;
		 delayTime = 0;
		 userId    = 0;
		 id        = "";
		 name      = "";
		 remindVt.clear();
	 }
	 
	 int32 bitSwitch;//位开关 对应的二进制位为1表示开启 0表示关闭 从右往左第1位延时消息 第2位 阅后回执 第3位消息提醒 第4位发布任务
	 int64 delayTime;//延迟消息的发送时间
	 int64 userId;
	 std::string id; //最大值为5 0:获取全部模板 1：获取1号模板 2:获取2号模板
	 std::string name;//模板名称
	 std::vector<stCombinationOrderRemind> remindVt;
 };

struct LoginResult {
	 LoginResult()
	 {
		 init();
	 }
	 int64 userid;					  ///< 用户ID userid.
	 std::string what;                 ///< code非零的情况下有效 what.
	 std::string verImgPath;           ///< 验证码 verImgPath.
	 std::string area;                 ///< 地区 area.
	 int32 sessionTimeout;             ///< 超时时间 sessionTimeout.
	 int64 serverTime;                 ///< 服务器时间 serverTime.
	 int64 remainLockTime;             ///< 账号锁定剩余时长,只有在账号被锁定时才有效
	 int64 inviteUserID;
	 int64 registerTime;				  ///< 用户注册时间
	 int8 value_byte;					///< 二维码加好友开关
	 std::string extinfo;              ///登录扩展信息。（防诈骗使用）
	 void init()
	 {
		 userid = 0;
		 sessionTimeout = 0;
		 serverTime = 0;
		 remainLockTime = 0;
		 inviteUserID = 0;
		 registerTime = 0;
		 what = "";
		 verImgPath = "";
		 area = "";
		 value_byte = 0;
		 extinfo = "";
	 }
 };
/**
* \brief 设置群配置新增结构体
*/
struct extendGroupSetting
{
	extendGroupSetting() : groupID(0), verifyType(0), isAllow(0), isAllowTransferOwner(0), isAllowAdminInvite(1), isChase(0), isShake(0)
	{}
	int64 groupID;
	int8 verifyType;		///< 验证类型:1:不允许任何人添加,2：需要验证信息,3：允许任何人添加 verifyType.
	int8 isAllow;			///< 是否允许群成员邀请好友加入群:1,允许 2,不允许 isAllow.
	int8 isAllowTransferOwner;///<企业群群主是否可以转让群 0否(默认), 1是
	int8 isAllowAdminInvite;  ///企业群管理员是否可以邀请入群  0否, 1是(默认)
	int8 isChase;	///< 是否开启追一下;2-关闭；1-开启(默认)
	int8 isShake;	///< 是否开启抖一抖;2-关闭(默认)；1-开启
};
/**
* \struct  addBuddyResponseExt 消息号: logic_cmd_addBuddyResponse
* \brief 发送好友请求
*/
struct addBuddyResponseExt
{
	addBuddyResponseExt() :userID(0), inviteCode("")
	{
		verifyInfo.clear();
	}

	int64 userID;                         ///< 被请求好友的ＩＤ userID.
	std::string inviteCode;               ///< 被请求好友的邀请码
	std::string verifyInfo;               ///< 验证信息 verifyInfo.
	std::string remark;                   ///< 好友备注 remark.
};
//群发记录请求参数
struct massRecordInfo {
	massRecordInfo() :type(0), id(0), deviceType(0), userID(0), targetUserMessageIds(""), msgBean("") {}
	int8  type;                            //操作类型,1:新增 2:删除
	int64 id;                              //群发记录id
	int64 userID;                          //用户ID
	std::string targetUserMessageIds;      //目标用户和消息id映射Map的json字符串
	int32 status;                          //群发状态：0默认，1撤回
	int64 sendTime;                        //发送时间
	std::string msgBean;                   //消息体
	int32 deviceType;				       //设备类型 1：PC；2：手机；3：pad；4：网页
};

//查询群发记录列表
struct massRecordPageST {
	massRecordPageST() :startRecorfId(0), pageSize(0), userID(0) {}
	int64 startRecorfId;             //起始记录ID
	int32 pageSize;                  //每页条数
	int64 userID;                    //用户ID
	//int32 totalCount;                //总条数
	//std::vector<massRecordInfo>  massRecordList;  //群发记录集合
};
} /*namespace service*/
