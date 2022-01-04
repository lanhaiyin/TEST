#pragma once

#include <string>
#include "../model/Account.h"
#include "../model/Packet.h"
#include "../model/Emoticon.h"
#include "IService.h"

#define VER_USER INTERFACE_VERSION(1,0)
static const VRVIID IID_IUserService = { 0x92d87e13, 0x463c, 0x4406, 0x8d, 0xfd, 0x28, 0x1f, 0xe7, 0x45, 0xac, 0xb };

namespace service 
{

class IUserService : public IService
{
public:
		
	virtual ~IUserService(){};

	/*****************************************注册通知回调*******************************************/

	/**
	* \brief 朋友圈消息推送
	* @param[out] cb 注册的推送回调 _1 类型 1:朋友圈消息未读数量 _2 接收内容json串
	*/
	virtual void regCircleOfFriendNotifyCb(SFunction < void(int32, const std::string&) > cb) = 0;


	/**
	* \brief 消息json推送
	* @param[out] cb 注册的推送回调 _1 类型 105:设置管理员或取消管理员 _2 接收内容json串 _112 表情包变更通知 8按群名片修改全部群成员名称
	*/
	virtual void regNotifyMessageJsonCb(SFunction < void(int32, const std::string&) > cb) = 0;
	/**
	* \brief 监听用户头像更新
	* @param[out] cb 注册的推送回调 _1 头像有更新的UserID，联系人或者群   _2 更新的头像文件
	*/
	virtual void regUserHeadImgUpdateCb(SFunction < void(int64, const std::string&) > cb) = 0;

	/**
	* \brief 设置监听用户信息更新的回调，服务器推送
	* @param[out] cb 注册的推送回调 _1 用户信息
	*/
	virtual void regOperateUserCb(SFunction< void(Account&) > cb) = 0;

	/**
	* \brief 监听自己用户信息修改，登录更新后会主动推送
	* @param[out] cb 注册的推送回调 _1 用户信息
	*/
	virtual void regGetMyselfCb(SFunction< void(Account&) > cb) = 0;
	
	/**
	* \brief 监听登录后，数据更新完成推送,收到推送代表更新完成
	 * @param[out] cb _1 1.代表主逻辑数据更新完成推送(目前只有此类型)
	*/
	virtual void regUpdateFinished(SFunction< void(int)> cb) = 0;
	
	/**
	* \brief 设置监听待办事项增加后的回调，服务器推送
	* @param[out] cb 待办事项增加后的推送回调, _1 备用，暂时没有使用
	*/
	virtual void regAppShow(SFunction< void(int)> cb) = 0;

	/**
	* \brief 设置监听  用户标签和动态菜单的回调，服务器推送或者sdk从数据库获取最终推送给客户端
	* @param[out] cb 用户标签和动态菜单的推送回调, _1 用户标签json字符串，_2动态菜单ClientMenu  结构体的vecotr
	*/
	virtual void regGetUTagCMenu(SFunction < void(ErrorInfo, const std::string&, std::vector<ClientMenuSet>&) > cb) = 0;

	/**
	* \brief 设置监听  app免打扰配置回调，服务器推送或者sdk从数据库获取最终推送给客户端
	* @param[out] cb app免打扰配置推送回调, app配置
	*/
	virtual void regAppConfigUpdate(SFunction < void(std::vector<strc_UserToAppConfig>&) > cb) = 0;

	/**
	* \brief 设置监听  表情包配置回调，服务器前台页面推送给客户端 表情包 增加修改删除按位或
	* @param[out] cb 表情包配置回调推送回调,  页面前台推送
	*/
	virtual void regEmoPackPropel(SFunction < void(int8,std::string&) > cb) = 0;
	/*****************************************请求接口*******************************************/


	/**
	* \brief 获取账户信息，同步接口
	* @param[out] info 用户信息
	*/
	virtual void getAccountInfo(Account& info) = 0;


	/**
	* \brief 更新用户信息
	* @param[in] user 传入用户信息
	* @param[out] cb  更新信息结果回调  _1错误信息
	*/
	virtual void updateAccountInfo(Account& user, SFunction<void(ErrorInfo)> cb) = 0;

	
	/**
	* \brief 设置账号设置项
	* @param[in] flag 传入设置项属性
	* @param[in] type 传入设置项类型
	* @param[out] cb  账号设置结果回调 _1 错误信息
	*
	*  type = 1: 设置是否显示在线信息 flag: 0显示 1不显示 默认0
	*  type = 3: 设置豆豆号查找 flag: 0允许 1不允许 默认0
	*  type = 4: 设置手机号查找 flag: 0允许 1不允许 默认0
	*  type = 5: 设置邮箱号查找 flag: 0允许 1不允许 默认0
	*  type = 6: 设置分享更新   flag: 0提示更新 1不提示更新 默认0
	*  type = 7: 新消息通知是否提醒 flag: 0提醒 1不提醒 默认0
	*  type = 12: 多服务新消息通知是否提醒 flag: 0不始终提示 1始终提示 默认0
	*  type = 13: 多服务设置V标好友始终提醒 flag: 0不始终提示 1始终提示 默认0
	*  type = 14: 多服务设置设置@相关人始终提醒 flag: 0不始终提示 1始终提示 默认0
	*  type = 20: 设置新朋友查找 flag: 0允许 1不允许 默认0
	*  type = 22: 设置昵称查找 flag: 0允许 1不允许 默认0
	*  type = 27: callkit标志 flag: 1开启 0关闭 默认1
	*/
	virtual void setSetting(int8 flag, int type, SFunction<void(ErrorInfo)> cb) = 0;


	/**
	* \brief 获取账号设置项
	* @param[in] type 传入获取的设置项类型
	* type为1，则返回值为value_i64第一位 如果type=0,返回所有字段，每个字段所占的位于type相对应\n
	* @param[out] cb 传入接收结果回调  _1错误信息  _2用户设置
	*/
	virtual void getSetting(int type, SFunction<void(ErrorInfo, UserSetting&)> cb) = 0;


	/**
	* \brief 通过密码获取隐藏对象(好友或群)
	* @param[in] passwd 之前设置过的密码
	* @param[out] cb 传入接收结果回调  _1错误信息  _2返回对象ID合集  _3 true代表存在此密码，false代表不存在
	*/
	virtual void getHiddenTarget(const std::string &passwd, SFunction<void(ErrorInfo, std::vector<int64>&, bool)> cb) = 0;

	/**
	* \brief 设置隐藏对象(好友或群)
	* @param[in] passwd 设置的密码
	* @param[in] hiddenIDs 设置的隐藏对象ID集合
	* @param[out] cb 传入接收结果回调  _1错误信息
	*/
	virtual void setHiddenTarget(const std::string &passwd, std::vector<int64>& hiddenIDs, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 删除隐藏对象(好友或群)
	* @param[in] passwd 密码
	* @param[in] hiddenIDs 要删除的对象ID集合
	* @param[out] cb 传入接收结果回调  _1错误信息 
	*/
	virtual void delHiddenTarget(const std::string &passwd, std::vector<int64>& hiddenIDs, SFunction<void(ErrorInfo)> cb) = 0;


	/**
	* \brief 更改隐藏密码
	* @param[in] oldPwd 旧密码
	* @param[in] newPwd 新密码
	* @param[out] cb 传入接收结果回调  _1错误信息
	*/
	virtual void changeHiddenPasswd(const std::string &oldPwd, const std::string &newPwd, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 获取全局勿扰模式（旧版），仅支持单个时间段勿扰模式获取，新老版本兼容，共用ap接口
	* @param[out] cb 传入接收结果回调  _1错误信息 _2起始时间  _3结束时间  _4是否打开
	*/
	virtual void getGlobalNoDisturbMode(SFunction<void(ErrorInfo, int32, int32, bool)> cb) = 0;

	/**
	* \brief 设置全局勿扰模式（旧版），仅支持单个时间段勿扰模式设置，新老版本兼容，共用ap接口
	* @param[in] startTime  起始时间
	* @param[in] endTime 结束时间
	* @param[in] isOpen 是否打开
	* @param[out] cb 传入接收结果回调  _1错误信息
	*/
	virtual void setGolbalNoDisturbMode(int32 startTime, int32 endTime, bool isOpen, SFunction<void(ErrorInfo)> cb) = 0;


	/**
	* \brief 获取全局勿扰模式(新版)，支持多个时间段勿扰模式获取，新老版本兼容，共用ap接口
	* @param[out] cb 传入接收结果回调  _1错误信息 _2勿扰模式list（包含起始时间，结束时间，是否打开，name）
	*/
	virtual void getGlobalNoDisturbListMode(SFunction<void(ErrorInfo, std::vector<globalNoDisturbModeInfo>&)> cb) = 0;

	/**
	* \brief 设置全局勿扰模式，可设置多个时间段模式（新版），支持多个时间段勿扰模式设置，新老版本兼容，共用ap接口
	* @param[in] item[index].startTime  起始时间
	* @param[in] item[index].endTime 结束时间
	* @param[in] item[index].isOpen 是否打开
	* @param[in] item[index].name 名称
	* @param[out] cb 传入接收结果回调  _1错误信息
	*/
	virtual void setGolbalNoDisturbListMode(std::vector<globalNoDisturbModeInfo> &items, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 获取针对目标用户的勿扰模式
	* @param[in] targetId  用户ID
	* @param[out] cb 传入接收结果回调  _1错误信息  _2用户ID  _3设置的值:  1为接收提醒 2表示不提醒仅显示数字 3:为免打扰
	*/
	virtual void getUserNoDisturbMode(int64 targetId, SFunction<void(ErrorInfo, int64, int8)> cb) = 0;

	/**
	* \brief 设置针对目标用户的勿扰模式
	* @param[in] targetId  用户ID
	* @param[in] value 设置的值:  1为接收提醒 2表示不提醒仅显示数字 3:为免打扰, 默认1
	* @param[out] cb 传入接收结果回调  _1错误信息
	*/
	virtual void setUserNoDisturbMode(int64 targetId, int8 value, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 获取针对目标消息的通知模式
	* @param[in] targetId  用户ID
	* @param[out] cb 传入接收结果回调  _1错误信息  _2用户ID _3设置的值:  1.通知详情 2.通知源，隐藏内容 3.完全隐藏 
	*/
	virtual void getMsgNotifyMode(int64 targetId, SFunction<void(ErrorInfo, int64, int8)> cb) = 0;

	/**
	* \brief 设置针对目标消息的通知模式
	* @param[in] targetId  用户ID
	* @param[in] value 设置的值:  1.通知详情 2.通知源，隐藏内容 3.完全隐藏  默认开启模式1
	* @param[out] cb 传入接收结果回调  _1错误信息
	*/
	virtual void setMsgNotifyMode(int64 targetId, int8 value, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 获取服务器时间
	* @param[in] cb 传入接收结果回调  _1错误信息   _2服务器时间，单位毫秒
	*/
	virtual void getServerTime(SFunction<void(ErrorInfo, int64)> cb) = 0;
    /**
    * \brief 获取服务器时间(同步接口)
    * @param[out] _1服务器时间，单位毫秒
    */
    virtual bool getServerTimeSync(int64& serverTime) = 0;
	/**
	* \brief 增加本地配置，以键值对方式保存
	* @param[in] items  配置信息集合
	* @param[out] cb 传入接收结果回调  _1错误信息
	*/
	virtual void addLocalSetting(std::vector<LocalSetting> &items, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* \brief 增加本地配置，以键值对方式保存(同步接口)
	* @param[in] items  配置信息集合
	*/
	virtual bool addLocalSettingSync(std::vector<LocalSetting> &items) = 0;

	/**
	* \brief 获取本地配置
	* @param[in] keys 获取的配置信息的键集合
	* @param[out] cb 传入接收结果回调  _1错误信息  _2获取的配置信息键值对集合
	*/
	virtual void getLocalSetting(std::vector<std::string> &keys, SFunction<void(ErrorInfo, std::vector<LocalSetting>&)> cb) = 0;
	/**
	* \brief 获取本地配置(同步接口)
	* @param[in] keys 获取的配置信息的键集合
	* @param[out] result 返回的配置信息键值对集合
	*/
	virtual bool getLocalSettingSync(std::vector<std::string> &keys, std::vector<LocalSetting> &result) = 0;

	/**
	* \brief 更新本地配置
	* @param[in] newItems 插入的新的配置信息集合
	* @param[out] cb 传入接收结果回调  _1错误信息
	*/
	virtual void updateLocalSetting(std::vector<LocalSetting> &newItems, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* \brief 更新本地配置(同步接口)
	* @param[in] newItems 插入的新的配置信息集合
	*/
	virtual bool updateLocalSettingSync(std::vector<LocalSetting> &newItems) = 0;

	/**
	* \brief 设置本地配置
	* @param[in] newItems 插入或更新新的配置信息集合
	* @param[out] cb 传入接收结果回调  _1错误信息
	*/
	virtual void setLocalSetting(std::vector<LocalSetting> &newItems, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* \brief 设置本地配置(同步接口)
	* @param[in] newItems 插入或更新新的配置信息集合
	*/
	virtual bool setLocalSettingSync(std::vector<LocalSetting> &newItems) = 0;

	/**
	* \brief 删除本地配置
	* @param[in] keys 删除的配置信息的键集合
	* @param[out] cb 传入接收结果回调  _1错误信息
	*/
	virtual void deleteLocalSetting(std::vector<std::string> &keys, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* \brief 删除本地配置(同步接口)
	* @param[in] keys 删除的配置信息的键集合
	* @param[out] cb 传入接收结果回调  _1错误信息
	*/
	virtual bool deleteLocalSettingSync(std::vector<std::string> &keys) = 0;


	/**
	* \brief 设置个人设置项\n
    * @param[in] items 个人设置项集合
	*		type: 1 生日，２ 电话，３ 邮件 \n
	* 　　　　　　value:  1：所有人可见 2：仅好友可见 3：仅自己可见，默认1\n
	*		type: 4 好友验证方式 \n
	* 　　　　　　value:   1：需要验证信息, 2:不允许任何人添加, 3:允许任何人添加，默认1\n
	*		type: 5 V标好友消息提示模式\n
	*			value: 1:表示始终有声音提醒，2：表示始终无声音提醒 3:不始终提醒，默认1\n
	*		type: 6 @相关人消息提醒模式\n
	*			value: 1:表示始终有声音提醒，2：表示始终无声音提醒 3:不始终提醒，默认1\n
	*		type: 7 全局通知消息内容展现模式\n
	*           value: 1:通知详情，2：通知源，隐藏内容 3:完全隐藏，默认2\n
	*		type: 24 语音视频消息提醒开关\n
	*           value：1：开启，2：关闭，默认2\n
	* @param[out] cb 传入接收结果回调  _1错误信息
	*/
	virtual void setPersonalData(std::vector<PersonalData> items, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 获取个人设置项
	* @param[out] cb 传入接收结果回调  _1错误信息  _2个人设置项集合
	*/
	virtual void getPersonalData(std::vector<int16> &types, SFunction<void(ErrorInfo, std::vector<PersonalData>&)> cb) = 0;

	/**
	* \brief 通过应用ID获取应用信息
	* @param[in] appId 应用程序ID
	* @param[out] cb 传入接收结果回调  _1错误信息  _2应用信息
	*/
	virtual void getAppInfo(int64 appId, SFunction<void(ErrorInfo, EntAppinfo&)> cb) = 0;
	/**
	* \brief 查询应用市场应用信息新增群应用功能
	* @param[in] qData 传入应用市场分页查询条件
	* @param[out] cb 传入接收结果回调  _1错误信息  _2查询到的结果，应用信息列表
	*/
	virtual void queryMarketApplication(QueryMarketApplication& qData, SFunction<void(ErrorInfo, SmallMarketAppPage&)> cb) = 0;

	/**
	* \brief 查询应用轨迹位置信息
	* @param[in] appID 查询轨迹的appID
	   @param[in] posMessage 轨迹消息posMessage
	* @param[out] cb 传入接收结果回调  _1错误信息 
	*/
	virtual void sendTrackInfo(int64 appID,std::string &posMessage,SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 删除添加应用
	* @param[in] type 传入的查询类型： 2.添加应用  4.删除应用
	* @param[in] appID 操作的appID
	* @param[out] cb 传入接收结果回调  _1错误信息 
	*/
	virtual void addOrDeleteApplication(int8 type, int64 appID, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 客户端(工作台)群主/管理员忽略/添加群应用接口
	* @param[in] struct IgnoreMarketAppBean {
	*								int64 relationId;  操作关联ID 
	*								int64 vestAppId;    应用号ID 
	*								int64 relationIdType;   关联ID类型;1.用户 2.群 
	*								int64 operatorId;       操作者ID 
	*								int8 operatorType;     操作类型1添加 2忽略 
	*                                       }
	* @param[out] cb 传入接收结果回调  _1错误信息
	*/
	virtual void IgnoreMarketApp(IgnoreMarketAppBean AppBean, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 获取已安装的应用
	* @param[in] deviceType: 2.IOS 3.Android
	* @param[out] cb 传入接收结果回调  _1错误信息 _2应用信息列表
	*/
	virtual void getInstalledApplication(int32 deviceType, SFunction<void(ErrorInfo, std::vector<SmallMarketAppInfo>&)> cb) = 0;
	/**
	* \brief 通过标签查询表情包
	* @param[in] label 表情包标签
	* @param[out] cb  传入接收结果回调  _1错误信息 _2查询表情包结果集合
	*/
	virtual void QueryEmoticonPackageByLabel(std::string label, SFunction<void(ErrorInfo, std::vector<EmoticonPackage>&)> cb) = 0;
	/**
	* \brief 单个表情查询、根据表情包标识查询表情，查询用户自定义表情
	* @param[in] type  1, 单个查询表情 md5Code表示单个表情的md5, 6,根据表情包标识查询所有表情 md5Code表示表情包的md5, 7,查询用户所有自定义表情 这里md5Code不传值
	* @param[in] md5   md5值
	* @param[out] cb 传入接收结果回调  _1错误信息 _2查询的表情结果信息
	*/
	virtual void queryEmoticon(int8 type, std::string md5, SFunction<void(ErrorInfo, std::vector<Emoticon>&)> cb) = 0;
	/**
	* \brief 查询单个表情包
	* @param[in] md5   md5值
	* @param[out] cb 传入接收结果回调  _1错误信息 _2查询表情包结果
	*/
	virtual void singleQueryEmoticonPackage(std::string md5, SFunction<void(ErrorInfo, EmoticonPackage&)> cb) = 0;
	/**
	* \brief 分页查询表情包
	* @param[in] localEmoSerTS   本地服务器表情包时间戳
	* @param[in] pageNum   页码
	* @param[in] pageSize   页长
	* @param[out] cb 传入接收结果回调  _1错误信息 _2返回的分页查询信息
	*/
	virtual void pageQueryEmoticon(int64 localEmoSerTS,int32 pageNum, int32 pageSize, SFunction<void(ErrorInfo, PageQueryEmoticon&)> cb) = 0;

	/**
	*\brief 查选单个表情包内的单个表情
	*@param[in] packageCode 表情包md5 
	*@param[in] emotCode  表情md5
    * @param[out] cb 传入接收结果回调  _1错误信息 _2查询表情结果
	*/
	virtual void queryEmotionInPackage(std::string packageCode, std::string emotCode, SFunction<void(ErrorInfo, singleEmoticonResult&)>) = 0;

	/**
	*\brief 表情包一期接口，删除表情包本地存储，卸载使用
	*@param[in] packageCode 表情包md5
	* @param[out] cb 传入接收结果回调  _1错误信息
	*/
	virtual void deleteEmoticonPackageLocal(std::string&, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	*\brief 表情包一期接口，设置表情包已读
	*@param[in] packageCode 表情包md5
	* @param[out] cb 传入接收结果回调  _1错误信息
	*/
	virtual void setEmoticonPackageRead(std::string&, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	*\brief 表情包一期接口，将用户需要的表情包加载到本地，表情包信息需要从网络获取
	*@param[in] vecPackCode 需要加载到本地的表情包md5的集合
	*@param[in] bIsRead false表示未读，true表示已读
	* @param[out] cb 传入接收结果回调  _1错误信息 _2成功的表情包列表 _3失败的表情包列表
	*/
	virtual void addEmoticonPackageNetToDb(std::vector<std::string>&, bool bIsRead, SFunction<void(ErrorInfo, std::vector<std::string>&, std::vector<std::string>&)> cb) = 0;

	/**
	*\brief 表情包一期接口，将用户需要的表情包加载到本地，表情包信息从本地获取
	*@param[in] vecPackage 需要加载到本地的表情包的集合
	* @param[out] cb 传入接收结果回调  _1错误信息 _2成功的表情包列表 _3失败的表情包列表
	*/
	virtual void addEmoticonPackageLocalToDb(std::vector<EmoticonPackage>&, SFunction<void(ErrorInfo, std::vector<std::string>&, std::vector<std::string>&)> cb) = 0;



	/**
	* \brief 获取所有已下载的自定义表情，仅支持本服务器查看，因为自定义表情排序无法修改其他服务器的orderNum
	* @out   表情列表
	* @return 是否正常返回
	*/
	virtual bool getAllEmoticonLocal(std::vector<Emoticon>& vecEmoticon) = 0;
	/**
	*\brief 表情包一期接口，获取所有已下载的表情包,如果服务器允许多服务器查看，其他在线服务器的表情包也在里面
	* @out   表情包列表
	* @return 是否正常返回
	*/
	virtual bool getAllEmoticonPackageLocal(std::vector<EmoticonPackage>& vecEmoticonPack) = 0;

	/**
	* \brief 增删自定义表情
	* @param[in] type   类型  4 自定义表情的收藏操作通知到服务器， 5自定义表情的取消收藏操作通知到服务器
	* @param[in] emot   表情   
	* @param[out] cb 传入接收结果回调  _1错误信息（
	*0:操作成功
	*100026500:表情包参数错误
	*100026501:表情包添加数据库错误
	*100026502:表情包删除数据库错误
	*100026503:表情包时间戳错误
	*100026504:批量表情超过最大数量
	*100026505:表情包需要拉取
	*100026506:表情已存在）
	*       如果出现code为100026505说明服务器跟客户端没有完全同步，需要调用获取服务器的接口继续同步更新
	*/
	virtual void addOrDeleteCustomEmoticon(int8 type, Emoticon &emot, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 下载或卸载表情包
	* @param[in] type   类型  4 下载安装表情包通知服务器， 5卸载表情包通知服务器
	* @param[in] emot   表情包   
	* @param[out] cb 传入接收结果回调  _1错误信息（
	*0:操作成功
	*100026500:表情包参数错误
	*100026501:表情包添加数据库错误
	*100026502:表情包删除数据库错误
	*100026503:表情包时间戳错误
	*100026504:批量表情超过最大数量
	*100026505:表情包需要拉取
	*100026506:表情已存在）
	*       如果出现code为100026505说明服务器跟客户端没有完全同步，需要调用获取服务器的接口继续同步更新
	*/
	virtual void installOrUninstallEmoticonPackage(int8 type, EmoticonPackage &emot, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 表情包二期接口，根据userid和本地表情时间戳,获取表情包的增量信息进行同步
	* @param[out] cb 传入接收结果回调  _1错误信息（
	*0:操作成功
	*100026500:表情包参数错误
	*100026501:表情包添加数据库错误
	*100026502:表情包删除数据库错误
	*100026503:表情包时间戳错误
	*100026504:批量表情超过最大数量
	*100026505:表情包需要拉取
	*100026506:表情已存在）
	*_2表情包结果列表 _3自定义表情结果列表
	*       如果出现Code为100026505说明服务器跟客户端没有完全同步，需要调用获取服务器的接口继续同步更新
	*/
	virtual void syncEmoticonFromNet(SFunction<void(ErrorInfo, std::vector<EmoticonResult>&, std::vector<EmoticonResult>&)> cb) = 0;


	/**
	* \brief 表情包二期接口，排序自定义表情
	*@param[in] vecEmoticon 需要重新排序的本地的自定义表情的集合
	* @param[out] cb 传入接收结果回调  _1错误信息（
	*0:操作成功
	*100026500:表情包参数错误
	*100026501:表情包添加数据库错误
	*100026502:表情包删除数据库错误
	*100026503:表情包时间戳错误
	*100026504:批量表情超过最大数量
	*100026505:表情包需要拉取
	*100026506:表情已存在）
	*       如果出现code为100026505说明服务器跟客户端没有完全同步，需要调用获取服务器的接口继续同步更新
	*/
	virtual void sortCustomEmoticon(std::vector<Emoticon>&, SFunction<void(ErrorInfo)> cb) = 0;


	/**
	* \brief 表情包二期接口，批量导入自定义表情
	*@param[in] vecEmoticon 需要批量导入的本地的表情的集合
	* @param[out] cb 传入接收结果回调  _1错误信息（
	*0:操作成功
	*100026500:表情包参数错误
	*100026501:表情包添加数据库错误
	*100026502:表情包删除数据库错误
	*100026503:表情包时间戳错误
	*100026504:批量表情超过最大数量
	*100026505:表情包需要拉取
	*100026506:表情已存在）
	*       如果出现code为100026505说明服务器跟客户端没有完全同步，需要调用获取服务器的接口继续同步更新
	*/
	virtual void addCustomEmoticons(std::vector<Emoticon>&, SFunction<void(ErrorInfo)> cb) = 0;


	/**
	* \brief 本地数据导入导出
	* @param[in] req   导入导出数据的路径等参数信息
	* @param[out] cb 传入接收结果回调  _1错误信息 
	* @param[out] pro _1  进度标示 _2进度 _3 已经导入文件数量/导入文件总数量
	*/
	virtual void transLocalData(transferLocalData &req, SFunction<void(ErrorInfo)> cb, SFunction<void(int32, int32, const std::string&)> pro) = 0;
	/**
	* \brief 设置自定义提示音
	* @param[in] userId   用户ID id为0代表设置自己
	* @param[in] voiceName   声音文件
	* @param[out] cb 传入接收结果回调  _1错误信息
	*/
	virtual void setUserDefineVoice(int64 userId, const std::string &voiceName, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* \brief 获取用户自定义提示音
	* @param[in] userId   用户ID id为0代表获取用户自己
	* @param[out] cb 传入接收结果回调  _1错误信息 _2声音文件
	*/
	virtual void getUserDefineVoice(int64 userId, SFunction<void(ErrorInfo, const std::string&)> cb) = 0;
	/**
	* \brief 通过账号名获取用户ID
	* @param[in] accounts   用户accountName集合
	* @param[out] cb 传入接收结果回调  _1错误信息 _2用户ID集合，key为account value为用户ID
	*/
	virtual void getIdByAccount(std::vector<std::string> &accounts, SFunction<void(ErrorInfo, std::map<std::string, int64>&)> cb) = 0;
	/**
	* \brief 设置在线状态
	* @param[in] flag  1:在线,2:隐身,3:忙碌,4:离开,5:请勿打扰
	@param[in] nOnlineStatus  1:在线；2:会议中,3:忙碌,4:飞机上,5:请勿打扰,6:自定义
	@param[in] szExplain  当nOnlineStatus设置为自定义时，该字段表示状态说明(可以为空)
	* @param[out] cb 传入接收结果回调 _1错误信息 -3:空指针  -4：flag值不在范围内 -5：nOnlineStatus值不在范围内
	100008008：服务器功能未上线   -1：其他错误
	*/

	virtual void setOnlineState(int8 flag, int8 nOnlineStatus, const std::string& szExplain, SFunction<void(ErrorInfo)> cb) = 0;

	/**************IOS专用接口 begin***************/

	/**
	* \brief IOS设置Token
	* @param[in] appleId  需要设置的appleId
	* @param[in] token  需要设置的token
	* @param[in] isDev  是否是开发版
	* @param[out] cb 传入接收结果回调  _1错误信息
	*/
    virtual void setToken(const std::string &appleId, const std::string &token, const std::string& cloudToken, bool isDev, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 设置后台在线状态
	* @param[in] vb1  设置云后台在线(true 在线, false 不在线)
	* @param[in] vb2  设置应用在线(true在线)
	* @param[out] cb 传入接收结果回调  _1错误信息
	*/
	virtual void setOnlineStatus(bool vb1,bool vb2, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 设置当前人的会话对象ID（中电科）
	* @param[in] targetId  对象的id 聊天对象，用户ID　或　群ID
	* @param[out] cb 传入接收结果回调  _1错误信息
	*/
	virtual void setSessionPeerId(int64 targetId, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* \brief  批量设置token 
		    传入参数：
	*@param[in]  
				 appID: "XiaoMi"  不能为空，必填，小米可填写"XiaoMi"
				 token:token值  
				 deviceType:"0"苹果 "1"华为 "2"小米 "3"中电科EMM  "4"小米
	* @param[out] cb 传入接收结果回调  _1错误信息
	*/
	virtual void setTokens(std::string& appId,std::string& token,std::string& deviceType, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* \brief ios设置是否推送
	* @param[in] isPush 是否推送
	* @param[out] cb 传入接收结果回调  _1错误信息
	*/
	virtual void setPushSwitch(bool isPush, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief  ios设置客户端消息未读数量
	* @param[in] count 未读数量
	* @param[in] appleId  应用id，不同的应用所对应的证书是不一样的.
	* @param[in] token  ios token
	* @param[in] entUnread  设置企业未读数 key：企业ID， value:消息未读数
	* @param[out] cb 传入接收结果回调  _1错误信息
	*/
	virtual void setUnReadCount(int count, const std::string &appleId, const std::string &token, std::map<std::string, int32> &entUnread, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief  获取用户应用安装天数
	* @param[out] cb 传入接收结果回调  _1错误信息 _2使用天数
	*/
	virtual void getInstallDays(SFunction<void(ErrorInfo, int32)> cb) = 0;
	
	/**
	*\brief 根据用户id分页获取企业号或应用号
	* @param[in] req 分页获取条件（页码，每页大小）
	*@param[out] cb 传入接收结果回调 _1错误信息 _2总数量 _3总页数 _4 获取结果集合
	*/
	virtual void getEntAppInfo(reqEntAppInfo& req,SFunction<void(ErrorInfo, int64, int64, std::vector<model::EntAppinfo>&)> cb) = 0;

	/**
	*\brief 朋友圈接口
	*@Param[in] reqJson 请求json
	*@Param[in] loginfoPath 登录信息保存路径
	*@Param[out] cb 传入接收结果回调 _1错误信息 _2响应json
	*/
	virtual void circleOfFriend(const std::string& reqJson, std::string &loginfoPath, SFunction<void(ErrorInfo, std::string&)> cb) = 0;

	/**
	* \brief 根据用户账号批量获取userID
	*@Param[in] accounts 帐号名称集合 手机号前加0086
	*@Param[in] type   1.电话号码 3.email 4.userID 6.accountName
	*@Param[in] status 状态  1.启用， 2.禁用, 5.锁定, 6.冻结
	*@Param[in] SDKID 服务器ID  vrv服务器传0
	*@Param[out] cb 传入接收结果回调 _1错误信息 _2批量获取结果(key:type+"-"+contactInfo+"-"+SDKID, value:UserID)
	*/
	virtual void queryUserIDByAccount(std::vector<std::string>& accounts, int8 type, int8 status, int64 SDKID, SFunction<void(ErrorInfo, std::map<std::string,int64>&)> cb) = 0;

	/**
	* \brief 新增更新或者删除在线扩展信息，如客户端的ip，mac地址等，内容是客户端自己设定，通过DDIO获取
	*@Param[in] type 4,新增或更新， 5 删除
	*@Param[in] str
	*@Param[out] cb 传入接口结果回调，_1错误信息
	*/
	virtual void operOnlineExt(int8 type, std::string str, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* \brief 查询在线扩展信息，不需要入参，返回所有设备设置的在线拓展信息
	*@Param[out] cb 传入接口结果回调，_1错误信息 _2批量查询结果，key是devicetype，value是jsonExt
	*/
	virtual void queryOnlineExt(SFunction<void(ErrorInfo, std::map<std::string, std::string>&)> cb) = 0;

    /**
    * \brief 透传JSON格式请求
    *@Param[in] reqJson  请求Json串
    *@Param[in] type    服务类型  1:调用声网服务 2:原生朋友圈 3:原生云盘 4:豆豆邮件
    *@Param[out] cb 传入接口结果回调，_1错误信息  _2返回的json
    */
    virtual void queryJson(const std::string& reqJson, int8 type, SFunction<void(ErrorInfo, const std::string&)> cb) = 0;

	/**
	* \brief 意见反馈
	*@Param[in] feedBackParam 反馈信息
	*@Param[out] cb 传入接口结果回调，_1错误信息
	*/
	virtual void feedBack(IssueFeedBack &feedBackParam, SFunction<void(ErrorInfo)> cb) = 0;

    /**
    * \brief 获取工作台轮播图
    *@Param[in] cliType 客户端类型   1：Android 2：iOS
    *@Param[out] cb 传入接口结果回调，_1错误信息 _2轮播图结果
    */
    virtual void getWorkBenchBanners(int32 cliType, SFunction<void(ErrorInfo, std::vector<WorkbenchBanner>&)> cb) = 0;

    /**
    * \brief 获取帮助系统信息
    *@Param[in] cliType 客户端类型   1：PC 2:Android 3:iOS
    *@Param[in] parentId 父帮助ID    获取初始信息传0
    *@Param[out] cb 传入接口结果回调，_1错误信息 _2帮助信息结果
    */
    virtual void getHelpSystemInfo(int32 cliType, int64 parentId, SFunction<void(ErrorInfo, std::vector<HelpSystemInfo>&)> cb) = 0;

    /**
    * \brief 设置用户扩展信息
    *@Param[in] account 帐号名称 手机号前加0086
    *@Param[in] type   1.电话号码 3.email 4.userID 6.accountName
    *@Param[in] status 状态  1.启用， 2.禁用, 5.锁定, 6.冻结
    *@Param[in] SDKID 服务器ID  vrv服务器传0
    *@Param[in] mark 标识
    *@Param[out] cb 传入接收结果回调 _1错误信息 
    */
    virtual void updateExtendInfo(const std::string& account, int8 type, int8 status, int64 SDKID, const std::string& mark, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 判断目标用户是否在用户设置名单中(黑名单, 或者白名单)      
    *@Param[in] queryType   1.黑名单 2.白名单
    *@Param[in] entId       当queryType==2的时候设置， 表示企业ID
    *@Param[in] targetId    目标ID,如果查询自己是否在别人黑名单中,targetId传自己ID,entId传对方ID
	*@Param[out] cb 传入接收结果回调 _1错误信息 _2查询结果 1.在名单中, 2.不在名单中
	*/
	virtual void queryUserIsExistList(int8 queryType, int64 entId, int64 targetId, SFunction<void(ErrorInfo, int8)> cb) = 0;
	
	/**
	* \brief 授权登录接口
	*@Param[in] operType	操作类型 1.校验二维码 2.允许授权 3.获取授权码
	*****以下参数根据operType具有不同意义*****
	*@Param[in] cliType		1.账户类型(1,手机 3,邮箱...) 3.客户端类型(2,Android 3,iOS)
	*@Param[in] appId		应用Id，operType=2时不用传
	*@Param[in] param		1.2.二维码uuId 3.应用包名
	*@Param[out] cb 传入接收结果回调 _1错误信息 _2授权结果
	*/
	virtual void getOauthCode(int8 operType, int8 cliType, int64 appId, const std::string& param, SFunction<void(ErrorInfo, OAuthResult&)> cb) = 0;

	/**
	* \brief 创建工作台应用房间
	*@Param[in] info   房间信息
	*@Param[out] cb 传入接收结果回调 _1错误信息 _2房间id
	*/
	virtual void createAppRoom(AppRoomInfo info, SFunction<void(ErrorInfo, int64)> cb) = 0;

	/**
	* \brief 工作台房间信息更新
	*@Param[in] id   房间id
	*@Param[in] name   房间名称
	*@Param[out] cb 传入接收结果回调 _1错误信息
	*/
	virtual void updateAppRoomInfo(int64 id, const std::string& name, const std::string& icon, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 工作台应用房间成员更新
	*@Param[in] id   房间id
	*@Param[in] type   更新类型 1.添加成员 2.删除成员 （删除后房间成员为空，会自动删除房间)
	*@Param[out] cb 传入接收结果回调 _1错误信息
	*/
	virtual void updateAppRoomMem(int64 id, int type, std::vector<int64> memIds, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 设置工作台排序信息
	*@Param[in] orderInfo   全量的排序信息
	*@Param[out] cb 传入接收结果回调 _1错误信息
	*/
	virtual void setAppOrder(std::vector<AppOrderInfo> orderInfo, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 获取工作台已安装应用排好序(没有设置过排序信息, 则时未排序的bool标识)
	*@Param[in] deviceType: 1.pc 2.IOS 3.Android
	*@Param[out] cb 传入接收结果回调 _1错误信息 _2是否排序 _3应用列表
	*/
	virtual void getInstalledApplicationSorted(int32 deviceType, SFunction<void(ErrorInfo, bool, std::vector<MarketAppGroup>&)> cb) = 0;

	/**
	* \brief 添加本地应用
	*@Param[in] info   应用信息
	*@Param[out] cb 传入接收结果回调 _1错误信息 _2应用id
	*/
	virtual void addLocalApp(LocalAppInfo info, SFunction<void(ErrorInfo, int64)> cb) = 0;
	/**
	* \brief 删除本地应用
	*@Param[in] appId   应用id
	*@Param[out] cb 传入接收结果回调 _1错误信息
	*/
	virtual void deleteLocalApp(int64 appId, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 获取本地应用列表
	*@Param[out] cb 传入接收结果回调 _1错误信息 _2应用列表
	*/
	virtual void getLocalAppList( SFunction<void(ErrorInfo, std::vector<LocalAppInfo>&)> cb) = 0;

	/**
	* \brief 获取登录设备记录
	*@Param[out] cb 传入接收结果回调 _1错误信息 _2应用列表
	*/
	virtual void getDeviceLoginRecord(SFunction<void(ErrorInfo, std::vector<DeviceLoginRecord>&)> cb) = 0;

	/**
	* \brief 获取工作密集列表
	*@Param[out] cb 传入接收结果回调 _1错误信息 _2应用列表
	*/
	virtual void getSecurityList(SFunction<void(ErrorInfo, std::vector<Security>&)> cb) = 0;

	/**
	* \brief 删除登录设备记录
	*@param[in] macAddrs 用户登录设备mac地址列表
	*@Param[out] cb 传入接收结果回调 _1错误信息 
	*/
	virtual void deleteDeviceLoginRecord(std::vector<std::string> macAddrs, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	*\brief 获取应用市场应用分类集合
	*@Param[in] filterCondition 过滤条件，暂时没有过滤条件
	*@Param[out]  _1 int64 应用分类id _2 string 应用分类名称
	*/
	//virtual void getMarketAppSort(std::map<std::string, std::string> &filterCondition, SFunction<void(ErrorInfo, std::vector<smallMarketAppType>&)> cb) = 0;
	/**************IOS专用接口 end***************/

	/**************安卓专用接口 begin***************/
    /**
    *\brief 安卓事件通知
    *@Param[out]  cb 传入接收结果回调 _1错误信息
    */
	virtual void wakeUp(SFunction<void(ErrorInfo)> cb) = 0;
	/**************安卓专用接口 end***************/
	/**
	* \brief 拉取待办事项列表
	*@Param[out] cb 传入接收结果回调 _1错误信息 _2待办事项列表
	*/
	virtual void getAgencyList(SFunction<void(ErrorInfo, std::vector<agencymsg>&)> cb) = 0;

	/**
	* \brief 根据用户ID集合查询用户的设备信息,豆豆版本
	*@Param[in] userIDVt 用户的userID集合
	*@Param[out] cb 传入接收结果回调 _1错误信息 _2返回的设备信息和豆豆版本信息列表
	*/
	virtual void getLoginClientRecord(const std::vector<int64> userIDVt, SFunction<void(ErrorInfo, std::map<int64,std::vector<LoginClientRecord> >&)> cb) = 0;

	/**
	*\brief 获取客户端应用浏览器的应用服务开关总值
	* @param[in] appId appId应用Id
	*@param[out] cb 传入接收结果回调 _1错误信息 _2开关总值
	*/
	virtual void getSmallAppHelpFlagValue(int64 appId, SFunction<void(ErrorInfo, int32)> cb) = 0;

	/**
	*\brief 获取客户端应用浏览器的帮助获取帮助列表
	* @param[in] appId appId应用Id
	* @param[in] parentId 帮助父Id
	*@param[out] cb 传入接收结果回调 _1错误信息 _2帮助列表
	*/
	virtual void getSmallAppHelpList(int64 appId, int64 parentId, SFunction<void(ErrorInfo, std::vector<SmallAppHelp>&)> cb) = 0;

	/**
	*\brief 备份数据库
	*@param[out] cb 传入接收结果回调 _1错误信息 
	*@param[out] pro 进度回调 _1extra_req  _2process _3title
	*/
	virtual void backupDB(SFunction<void(ErrorInfo)> cb, SFunction<void(int32, int32, const std::string&)> pro = SNull) = 0;
	/**
	* \brief 从网络拉取新待办事项列表
	* @param[in] userId 当前用户id
	* @param[in] type 任务状态 1待办 2已办
	* @param[in] pageNum 页码 如果-1 查询全量数
	* @param[in] pageSize 每页大小
	*@Param[out] cb 传入接收结果回调 _1错误信息 _2待办事项列表
	*/
	virtual void getAgencyListEx(int64 userID, int8 type, int pageNum, int pageSize, SFunction<void(ErrorInfo, agencyTaskMsg&)> cb) = 0;
	/**
	* \brief 本地同步获取已完成和未完成列表数
	* @param[in] userId 当前用户id
	*@Param[out] cb 传入接收结果回调 _1错误信息 _2已完成 _3未完成
	*/
	virtual void getAgencyListCompleteCnt(int64 userId, SFunction<void(ErrorInfo, int64, int64)> cb) = 0;
	/**
	* \brief 拉取本地待办事项列表分页展示
	* @param[in] flag 待办已办标志，代办传0，已办传1
	* @param[in] msgId 起始消息ID，只能从新往旧查询，如果是第一页查询参数传0，如果是第一页之后的页数传入上一页最后一条消息ID减去1
	* @param[in] count 查询的条数
	*@Param[out] cb 传入接收结果回调 _1错误信息 0表示成功，100表示参数错误，其他返回码表示失败 _2待办事项列表
	*/
	virtual void getAgencyListExByFlag(int8 flag, int64 msgId, int count, SFunction<void(ErrorInfo, std::vector<ToDoTaskMsg>&)> cb) = 0;

	/**
	* \brief 工作台任务设置已读和未读
	* @param[in] userId 当前用户id
	* @param[in] flag 当前用户设置待办任务已读状态
	* @param[in] msgID 消息ID
	*@Param[out] cb 传入接收结果回调 _1错误信息
	*/
	virtual void setAgencyListRead(int64 userId, int8 flag, int64 msgID, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* \brief 获取本地筛选条件（来源和标签展示）
	* @param[in] userId 当前用户id
	*@Param[out] cb 传入接收结果回调 _1错误信息 _2来源 _3标签
	*/
	virtual void getAgencyListScreenItem(int64 userId, SFunction<void(ErrorInfo, std::vector<int64>&, std::vector<std::string>&)> cb) = 0;
	/**
	* \brief 任务代办分页展示本地筛选结果
	* @param[in] flag 待办已办标志，代办传0，已办传1
	* @param[in] msgId 起始消息ID，只能从新往旧查询，如果是第一页查询参数传0，如果是第一页之后的页数传入上一页最后一条消息ID减去1
	* @param[in] count 查询的条数
	* @param[in] startTime 开始时间
	* @param[in] endTime 结束时间，开始时间和结束时间要么都有值，要么都是0
	* @param[in] appIds 业务来源
	* @param[in] urgeflag 催办状态,0表示不催办，1表示催办
	* @param[in] tags 标签
	*@Param[out] cb 传入接收结果回调 _1错误信息 0表示成功，100表示参数错误，其他返回码表示失败 _2待办事项列表
	*/
	virtual void disAgencyListScreenResults(int8 flag, int64 msgId, int count, int64 startTime, int64 endTime, std::vector<int64> appIds, int8 urgeflag, std::vector<std::string> tags, SFunction<void(ErrorInfo, std::vector<ToDoTaskMsg>&)> cb) = 0;
	/**
	* \brief 任务代办本地搜索分页展示结果（关键词按标题和内容搜索）
	* @param[in] flag 待办已办标志，0表示代办，1表示已办
	* @param[in] msgId 起始消息ID，只能从新往旧查询，如果是第一页查询参数传0，如果是第一页之后的页数传入上一页最后一条消息ID减去1
	* @param[in] count 查询条数
	* @param[in] keyWord 搜索关键词
	*@Param[out] cb 传入接收结果回调 _1错误信息 0表示成功，100表示参数错误，其他返回码表示失败 _2待办事项列表
	*/
	virtual void searchLocalAgencyListByKey(int8 flag, int64 msgId, int count, std::string keyWord, SFunction<void(ErrorInfo, std::vector<ToDoTaskMsg>&)> cb) = 0;
	/**
	* \brief 展示历史搜索记录
	* @param[in] userId 当前用户id
	*@Param[out] cb 传入接收结果回调 _1错误信息 _2待办事项列表
	*/
	virtual void disHistoryAgencyListRecords(int64 userId, SFunction<void(ErrorInfo, std::vector<std::string>&)> cb) = 0;
	/**
	* \brief 清空历史搜索记录
	* @param[in] userId 当前用户id
	*@Param[out] cb 传入接收结果回调 _1错误信息 _2待办事项列表
	*/
	virtual void delHistoryAgencyListRecords(int64 userId, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* \brief 获取栏目的应用列表
	* @param[in] menuCode 选择的栏目
	*@Param[out] cb 传入接收结果回调 _1错误信息 _2栏目对应的信息
	*	code 0:成功
	*/
	virtual void getAppListByMenuCode(AppListMenuCode menuCode, SFunction<void(ErrorInfo, AppListMenuInfo&)> cb) = 0;
	/**
	* \brief 获取栏目的应用列表 [入参有变,接口废弃]
	* @param[in] menuCode 选择的栏目
	*@Param[out] cb 传入接收结果回调 _1错误信息 _2栏目对应的信息
	*/
	virtual void getAppListByMenuSeq(int32 menuCode, SFunction<void(ErrorInfo, AppListMenuInfo&)> cb) = 0;
	/**
	* \brief 待办任务点击按钮根据用户的决策，回馈消息给应用
	* @param[in] appID 应用号
	* @param[in] body  用户决策信息
	*@Param[out] cb 传入接收结果回调 _1错误信息 0表示成功，100表示参数错误，其他返回码表示失败
	*/
	virtual void pushMsgToApp(int64 appID, std::string body, SFunction<void(ErrorInfo)> cb) = 0;
	
	
	
		/*
	用户设置公共号配置项(setUserToAppConfig)
	* @param[in]：userToAppConfig.appId公共号id
	              userToAppConfig.type配置类型1消息提醒（勿扰模式）
	              userToAppConfig.value 1:为接收提醒 2:表示不提醒仅显示数字 3:为免打扰
	*@param[out] cb 传入接收结果回调 _1错误信息: 0:成功
	                                             100:参数错误
	                                             11100:内部错误
	                                             100013006:失败
	*/
	virtual void setUserToAppConfig(int64 appID, int8 type, int value, SFunction<void(ErrorInfo)> cb) = 0;

	/*
	获取用户设置的公共号配置项列表(getUserToAppConfigList)
	* @param[in]：userToAppConfig.timestamp时间戳 （客户端给0获取本地配置表）
	              userToAppConfig.type类型 1消息提醒（勿扰模式）
	*@param[out] cb 传入接收结果回调 _1错误信息: 0:成功            _2用户配置集合
	                                             100:参数错误
	                                             11100:内部错误
	*/
	virtual void getUserToAppConfigList(int64 timestamp, int8 type, SFunction<void(ErrorInfo, std::vector<strc_UserToAppConfig>&)> cb) = 0;
	/**
	* \brief 获取服务器已安装的应用返回给客户端，客户端判断更新
	* @param[in] deviceType: 1.PC 2.IOS 3.Android
	* @param[out] cb 传入接收结果回调  _1错误信息 _2应用信息列表
	*/
	virtual void getInstalledAppFromNet(int32 deviceType, SFunction<void(ErrorInfo, std::vector<MarketAppInfo>&)> cb) = 0;
	/*
	 获取当前用户绑定的后台管理员角色信息，返回结构体[返回类型有变改成json,此接口废弃]
	 * @param[in]：无
	 *@param[out] cb 传入接收结果回调  _1错误信息 _2授权结果
	 民情通 [2/25/2021 zhuohc]
	*/
	virtual void getAdminRoleInfo(SFunction<void(ErrorInfo,AdminRoleInfo&)> cb)=0;
	/*
	获取当前用户绑定的后台管理员角色信息，返回json字符串
	* @param[in]：无
	*@param[out] cb 传入接收结果回调  _1错误信息 _2授权结果({"superAdmin":false,"adminName":"","adminAccount":""})
	民情通 [3/8/2021 zhuohc]
	*/
	virtual void getAdminRoleInfoJson(SFunction<void(ErrorInfo, std::string&)> cb) = 0;

	/**
	* \brief 搜索获取后台配置可搜索字段信息
	* @param[in] nUserId  用户Id
	* @param[out] cb 传入接收结果回调  _1错误信息 0设置成功
	                                             100005001 参数错误
	                                             100005002 失败
                                      _2搜索信息列表
	*/
	virtual bool GetClientSearchSetting(int64 nUserId, SFunction<void(ErrorInfo, std::vector<stPersionSearchSetting>&)> cb) = 0;

	/**
	* \brief 设置隐私中搜索字段信息
	* @param[in] nUserId  用户Id
	* @param[in] szSearchKey  设置开关key
	* @param[in] nValue  开关值 1开2关
	* @param[out] cb 传入接收结果回调  _1错误信息 0设置成功
	                                              100005001 参数错误
	                                              100005002 失败
	*/
	virtual bool SetClientSearchSetting(int64 nUserId, const std::string& szSearchKey, int8 nValue, SFunction<void(ErrorInfo)> cb) = 0;
};

} /*namespace service*/
