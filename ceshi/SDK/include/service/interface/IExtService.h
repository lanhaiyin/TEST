#pragma once

#include "../model/SDKTypes.h"
#include "../model/Packet.h"
#include "../model/Msg.h"
#include "IService.h"
#include "../extModel/packet.h"
#include "../extModel/extpacket.h"

#include <string>
#include <vector>

#define VER_EXT INTERFACE_VERSION(1,0)
static const VRVIID IID_IExtService = { 0x5dd084b3, 0x19f, 0x4109, 0x88, 0x92, 0x8f, 0xf9, 0x77, 0xa9, 0xac, 0xa2 };

namespace service
{

class IExtService : public IService
{
public:
	
	virtual ~IExtService(){}

	/*****************************************注册通知回调*******************************************/

    /**
     * \brief 登陆成功后会给推送所有房间,这个推送比联系人，群都要早
     * @param[out] cb
     */
    virtual void regGetAllRoomsCb(SFunction< void(std::vector<room> &)> cb) = 0;

	/**
	 *\brief 注册企业成员更新完成回调，收到回调代表更新完成
	 * @param[out] cb _1 暂无意义
	 */
	virtual void regEntUpdateFinishCb(SFunction< void(int)> cb) = 0;

	/**
	 * \brief 监听组织成员头像更新
	 * @param[in] cb 传入结果回掉 _1 传入目标ID，人或者群; _2 传入头像
	 */
	virtual void regOrgMemHeadImgUpdateCb(SFunction < void(int64, const std::string&) > cb) = 0;

	/**
	* \brief 监听客服会话列表更新
	* @param[in] cb 传入结果回掉 _1 更新标识; _2 更新列表
	*   0x08  更新
	*	0x10  新增
	*	0x20  删除
	*/
	virtual void regCustomChatListCb(SFunction< void(int, std::vector<CustomChat>&) > cb) = 0;

	/**
	* \brief 监听任务颜色提醒
	* @param[in] cb 传入结果回掉 _1 颜色提醒标识
	*	1 没有任务 不显示
	*	2 自己有未回复任务 red
	*	3 别人有未回复任务 yellow
	*	4 有未完成任务 blue
	*	5 全部完成 white55K
	*/
	virtual void regTaskStateCb(SFunction<void(int)> cb) = 0;

	/*****************************************请求接口*******************************************/

	//Task
	/**
	* @brief 发送任务消息
	* @param[in] msg 任务消息
	* @param[in] cb  传入接收结果回调 _1 错误号; _2 msgID; _3 sendTime;
	*/
	virtual void sendTaskMsg(Msg& msg, SFunction<void(ErrorInfo,int64, int64)> cb) = 0;
	/**
	* @brief 置顶任务
	* @param[in] msgId 传入TaskId
	* @param[in] isTop 是否置顶  0：不置顶 1：置顶
	* @param[in] cb  传入接收结果回调 _1 错误号;
	*/
	virtual void topTask(int64 msgId,int8 isTop,SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* @brief 获取指派的任务
 	* @param[in] cb  传入接收结果回调 _1 错误号; _2 任务集;
	*/
	virtual void getApTask(SFunction<void(ErrorInfo, std::vector<Task>&)> cb) = 0;
	/**
	* @brief 获取接收的任务
	* @param[in] cb  传入接收结果回调  _1 错误号; _2 任务集;
	*/
	virtual void getRecvTask(SFunction<void(ErrorInfo, std::vector<Task>&)> cb) = 0;
	/**
	* @brief 获取历史任务
	* @param[in] cb  传入接收结果回调 _1 错误号; _2 任务集;
	*/
	virtual void getHistoryTask(SFunction<void(ErrorInfo, std::vector<Task>&)> cb) = 0;
	/**
	* @brief 获取任务上下文
	* @param[in] taskId  指定的TaskID
	* @param[in] cb  传入接收结果回调 _1 错误号; _2 任务上下文;
	*/
	virtual void getBodyTask(int64 taskId, SFunction<void(ErrorInfo, std::string&)> cb) = 0;
	/**
	* @brief 恢复任务
	* @param[in] taskId  需要恢复的TaskID
	* @param[in] cb  传入接收结果回调 _1 错误号;
	*/
	virtual void recoveryTask(int64 taskId, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* @brief 完成任务
	* @param[in] taskId  需要完成的任务 id
	* @param[in] cb  传入接收结果回调 _1 错误号;
	*/
	virtual void finishTask(int64 taskId, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* @brief 设置任务已读
	* @param[in] taskId  需设置已读的任务id
	* @param[in] cb  传入接收结果回调 _1 错误号;
	*/
	virtual void setReadTask(int64 taskId, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* @brief 获取任务回复消息
	* @param[in] type    1:根据msgID获取; 2:根据timeTask获取
	* @param[in] msgID    type = 1时赋值
	* @param[in] timeTask type = 2时赋值
 	* @param[in] count  要获取的的任务id
	* @param[in] begin  从第几条开始 如果从第一条开始就传0
	* @param[in] cb  传入接收结果回调 _1 错误号;_2 回复消息;
	*/
	virtual void getRecvMsg(int8 type, int64 msgID, std::string timeTask, int count, int begin, SFunction<void(ErrorInfo, std::vector<MsgPtr>&, std::vector<model::Task>&)> cb) = 0;
	/**
	* @brief 获取任务颜色提醒
	* @param[in] cb 传入结果回掉 _1 颜色提醒标识
	*	1 没有任务 不显示
	*	2 自己有未回复任务 red
	*	3 别人有未回复任务 yellow
	*	4 有未完成任务 blue
	*	5 全部完成 white55K
	*/
	virtual void getTaskState(SFunction<void(int)> cb) = 0;

	//room
	/**
	* @brief 创建房间
	* @param[in] roomName 房间名
	* @param[in] ids  成员集合
	* @param[in] flag  是否置顶 0：不置顶 1：置顶
	* @param[in] url  头像url
	* @param[in] cb  传入接收结果回调 _1 错误号;
	*/
	virtual void createRoom(std::string& roomName, std::vector<int64>& ids, int8 flag, std::string& url, SFunction<void(ErrorInfo,int32)> cb) = 0;
	/**
	* @brief 修改房间名称
	* @param[in] roomId  要修改的roomID
	* @param[in] newName   新名称
	* @param[in] cb  传入接收结果回调 _1 错误号;
	*/
	virtual void changRoomName (int roomId, std::string& newName, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* @brief changRoomIcon
	* @param[in] roomId 要修改的roomID
	* @param[in] icoURL 头像的URL
	* @param[in] cb  传入接收结果回调 _1 错误号;
	*/
	virtual void changRoomIcon (int roomId, std::string& icoURL, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* @brief 删除房间
	* @param[in] roomID  房间ID
	* @param[in] cb  传入接收结果回调 _1 错误号;
	*/
	virtual void deleRoom(int roomID, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* @brief 获取房间信息
	* @param[in] roomID  房间ID
	* @param[in] cb  传入接收结果回调 _1 错误号; _2 获取的房间信息;
	*/
	virtual void getRoom(int roomID, SFunction<void(ErrorInfo, std::vector<room>&)> cb) = 0;
	/**
	* @brief 获取所有房间信息
	* @param[in] cb  传入接收结果回调 _1 错误号; _2 获取的房间信息集合;
	*/
	virtual void getAllRoom( SFunction<void(ErrorInfo, std::vector<room>&)> cb) = 0;

	/**
	* \brief 获取所有房间信息(同步接口)
	*/
	virtual std::vector<room> getAllRoomSync() = 0;
	/**
	* @brief 房间置顶
	* @param[in] roomId  房间ID
	* @param[in] isTop  是否置顶
	* @param[in] cb  传入接收结果回调 _1 错误号;
	*/
	virtual void topRoom(int roomId,int8 isTop,SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* @brief 房间增加人员
	* @param[in] roomId  房间ID
	* @param[in] vt  加入的成员
	* @param[in] cb  传入接收结果回调 _1 错误号;
	*/

	virtual void addRoomMember(int64 roomId, std::vector<int64> vt, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* @brief 房间删除人员
	* @param[in] roomId  房间ID
	* @param[in] vt  删除的成员
	* @param[in] cb  传入接收结果回调 _1 错误号;
	*/
	virtual void delRoomMember(int64 roomId, std::vector<int64> vt, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* @brief 获取组织机构
    * @param[in] flag 一般都传 0, 只有离线登陆的时候传 1
	* @param[in] type 
	* 0:获取登陆时刻的组织机构，如果登陆后对后台组织机构进行了修改，本次登陆拉取不到，下次登陆才可以拉取到 \n
	* 1:获取当前时刻的组织机构 =1 比 =0 速度上慢了很多，建议使用 =0\n
	* @param[in] orgID  组织ID  传 0 表示获取根组织
	* @param[in] cb  传入接收结果回调 _1 错误号; _2 组织集合; _3 企业用户信息;
	*/
	virtual void getVisibleOrgUsers(int8 flag, int8 type, int64 orgId, SFunction<void(ErrorInfo, int8, int8, std::vector<OrganizationInfo>&, std::vector<EntpriseUserInfo>&)> cb) = 0;
	//获取企业列表 同步接口
	virtual void getVisibleOrgUsersSync(int64 orgId, std::vector<OrganizationInfo>&, std::vector<EntpriseUserInfo>&) = 0;

	/**
	* @brief 根据条件查询企业用户列表
	* @param[in] EnterpriseUserQueryInfo  查询信息 见Packet.h
	* @param[in] cb  传入接收结果回调 _1 错误号; _2 total 总数; _3 totalPage 总页数; _4 用户信息集合;
	*/
	virtual void queryEnterpriseUserlist(EnterpriseUserQueryInfo& enterpriseUserQueryInfo, SFunction<void(ErrorInfo, int64, int64, std::map<std::string,std::vector<EntpriseUserInfo> >&)>  cb) = 0;
	/**
	* @brief 获取企业所有用户信息
	* @param[in] vt  需要获取的用户集合
	* @param[in] cb  传入接收结果回调 _1 错误号;_2 返回企业用户信息;
	*/
	virtual void queryEntUserAll(std::vector<int64> vt, SFunction<void(ErrorInfo, std::vector<EntpriseUserInfo>&)> cb) = 0;
	/**
	* @brief 查询企业用户信息
    * @param[in] flag 一般都传 0, 只有离线登陆的时候传 1
	* @param[in] userId  用户id
	* @param [in] cb  传入接收结果回调 _1 错误号;_2 返回企业用户信息;
	*/
	virtual void queryEntUserOneById(int8 flag, int64 userId, SFunction<void(ErrorInfo, std::vector<EntpriseUserInfo>&)> cb) = 0;
	/**
	* @brief 查询企业用户信息
    * @param[in] flag 一般都传 0, 只有离线登陆的时候传 1
	* @param[in] userName  用户名
	* @param [in] cb  传入接收结果回调 _1 错误号;_2 返回企业用户信息;
	*/
    virtual void queryEntUserOneByName(int8 flag, std::string& userName, SFunction<void(ErrorInfo, std::vector<EntpriseUserInfo>&)> cb) = 0;
	/**
	* @brief 获取组织信息
    * @param[in] flag 一般都传 0, 只有离线登陆的时候传 1
	* @param[in] orgId 组织Id
	* @param [in] cb  传入接收结果回调 _1 错误号;_2 组织信息;
	*/
	virtual void getOrgInfo(int8 flag, int64 orgId, SFunction<void(ErrorInfo, OrganizationInfo&)> cb) = 0;
	virtual void getOrgInfos(std::vector<int64>& orgId, SFunction<void(ErrorInfo,std::vector<OrganizationInfo>&)> cb) = 0;
    virtual void getOrgInfoSync(int64 orgId, OrganizationInfo & org) = 0;

    /**
     * @brief 组织机构模糊查找
     * @param[in] type 4：组织机构模糊查找 5：搜索人员接口
     */
    virtual void orgAndUserSearch(OrgAndUserSearchIn& orgAndUser, SFunction<void(ErrorInfo, int64, std::vector<OrganizationInfo>&, std::vector<OrgSearchUserInfo>&)> cb) = 0;

	//msg
	/**
	* @brief 获取对应targetId中的所有消息数目
	* @param[in] targetId  targetId
	* @param[in] cb  传入接收结果回调 _1 错误号;_2 消息数目;
	*/
	virtual void getMsgCountByTargetID(int64 targetId,SFunction<void(ErrorInfo,int32)> cb) = 0;
	/**
	* @brief 获取聊天数量前topN的群组
	* @param[in] topN   获取聊天数量前topN的群组
	* @param[in] cb  传入接收结果回调 _1 错误号;_2 targetID集合;_3 消息数目;
	*/
	virtual void getMsgTopNGroup(int topN, SFunction<void(ErrorInfo, std::vector<int64>&, std::vector<int>&)> cb) = 0;
	/**
	* @brief 获取聊天数目前topN的单聊
	* @param[in] topN   获取聊天数目前topN的单聊
	* @param[in] cb  传入接收结果回调 _1 错误号;_2 targetID集合;_3 消息数目;
	*/
	virtual void getMsgTopNSession(int topN, SFunction<void(ErrorInfo, std::vector<int64>&, std::vector<int>&)> cb) = 0;
	/**
	* @brief 获取@自己最多的topN个群
	* @param[in] topN    获取前topN会话的群组
	* @param[in] cb  传入接收结果回调 _1 错误号;_2 targetID集合;_3 消息数目;
	*/
	virtual void getMsgTopNAtGroup(int topN, SFunction<void(ErrorInfo, std::vector<int64>&, std::vector<int>&)> cb) = 0;


	//收藏
	/**
	* @brief 添加记事本
	* @param[in] noteInfo  记事本信息 见Packet.h
	* @param[in] cb  传入接收结果回调 _1 错误号;
	*/
	virtual void addNote(BaseNoteInfo& noteInfo, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* @brief 获取记事本
	* @param[in] beginID  起始消息ID offsetFlag = 0 msgBeginID = 0时，代表从最大的消息Id进行查找
	* @param[in] offset  查询的数量
	* @param[in] offsetFlag  偏移标志；0.消息Id由大到小偏移 1.消息Id由小到大偏移 offsetFlag.
	* @param[in] cb  传入接收结果回调 _1 错误号; _2 记事本集合
	*/
	virtual void getNote(int64 beginID, int32 offset, int8 offsetFlag, SFunction<void(ErrorInfo, std::vector<BaseNoteInfo>&)> cb) = 0;
	/**
	* @brief 删除记事本
	* @param[in] noteId  需删除noteID集合
	* @param[in] cb  传入接收结果回调 _1 错误号;
	*/
	virtual void delNote(std::vector<int64>& noteId,SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* @brief 修改记事本
	* @description: 修改记事本
	* @param[in] baseInfo  新的note信息
	* @param[in] cb  传入接收结果回调 _1 错误号;
	*/
	virtual void editNote(BaseNoteInfo& baseInfo, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* @brief 归档记事本
	* @param[in] noteId  要归档的note id
    *  低4位：表示是否归档 0. 不归档，1. 归档
    *  高4位：表示是否置顶 0. 不置顶，1. 置顶
	* @param[in] isArchive
	* @param[in] cb  传入接收结果回调 _1 错误号;
	*/
	virtual void archiveNote(int64 noteId,int8 isArchive ,SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* @brief 置顶记事本
	* @param[in] noteId  要置顶的note id
	* @param[in] isTop  是否置顶
	* @param[in] cb  传入接收结果回调 _1 错误号;
	*/
	virtual void topNote(int64 noteId, int8 isTop, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* @brief 搜索记事本
	* @param[in] info  搜索的信息 见Packet.h
	* @param[in] cb  传入接收结果回调 _1 错误号; _2 搜索的记事本集合
	************************************************************************/
	virtual void searchNote(searchNoteInfo& info, SFunction<void(ErrorInfo, std::vector<BaseNoteInfo>&)> cb) = 0;

	////智能客服
	/**
	* @brief 判断当前用户是否为客服
	* @param[out] cb  传入接收结果回调 _1 错误号; _2 true为是，false为否  
	************************************************************************/
	virtual void isCustomer(SFunction<void(ErrorInfo, bool)> cb) = 0;
	/**
	* @brief 获取客服正在服务的用户列表
	* @param[in] appId  公众号Id
	* @param[out] cb  传入接收结果回调 _1 错误号; _2 正在服务的用户列表
	************************************************************************/
	virtual void getUserByAppIdAndCustomId(int64 appId, SFunction<void(ErrorInfo, std::vector<User>& )> cb) = 0;
	/**
	* @brief 获取客户池列表
	* @param[in] appId  公众号Id
	* @param[out] cb  传入接收结果回调 _1 错误号; _2 客户池列表
	************************************************************************/
	virtual void getCustomerPoolByAppID(int64 appId, SFunction<void(ErrorInfo, std::vector<CustomerPoolBean>&)> cb) = 0;
	/**
	* @brief 客服关闭会话
	* @param[in] appId 公众号Id csid 客服ID(EntAppinfo结构体中的CSID),  userId客户的userID
	* @param[out] cb  传入接收结果回调 _1 错误号
	************************************************************************/
	virtual void closeConversation(int64 appId, int64 csid, int64 userId, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* @brief 客服接入客户
	* @param[in] csid 客服ID(EntAppinfo结构体中的CSID),  userId客户的userID
	* @param[out] cb  传入接收结果回调 _1 错误号
	************************************************************************/
	virtual void accessCustom(int64 appID, int64 csid, int64 userId, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* @brief 获取最后一条消息
	* @param[in] appID csid 客服ID(EntAppinfo结构体中的CSID),  userId客户的userID
	* @param[out] cb  传入接收结果回调 _1 错误号 _2 最后一条消息
	************************************************************************/
	virtual void getLastMessage(int64 appID, int64 csid, int64 userId, SFunction<void(ErrorInfo, SSharedPtr<Msg>)> cb) = 0;
	/**
	* @brief 获取客户池大小
	* @param[in] appId 公众号Id
	* @param[out] cb  传入接收结果回调 _1 错误号 _2 客户池大小
	************************************************************************/
	virtual void getCustomPoolCount( int64 appId, SFunction<void(ErrorInfo, int64 )> cb) = 0;
	/**
	* @brief 修改客服信息
	* @param[in] appId: 公众号Id Cisd, 客服id(appInfo里的CSID)status: 客服接待状态 1:客服在线（可接待用户）
	                            ，2:客服离线（不可接待用户）curMaxCount: 当前最大可接待数
	* @param[out] cb  传入接收结果回调 _1 错误号 
	************************************************************************/
	virtual void updateCustomerService(int64 appId, int64 csid, int8 status, int32 curMaxCount, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* @brief 获取客服公众号信息列表
	* @param[out] cb  传入接收结果回调 _1 错误号 _2 公众号列表
	************************************************************************/
	virtual void getAppListByUserID(SFunction<void(ErrorInfo, std::vector<CustomAppInfo>&)> cb) = 0;
	/**
	* \brief 获取客户的消息
	* @param[in] appId 传入公众号
	* @param[in] userId 传入客户的userID
	* @param[in] msgid 如果是按消息Id查询传入查询消息的起始消息ID，如果是按消息时间查询传入查询消息的起始时间。返回的结果会包含这条消息。
	* @param[in] count 传入查询消息总数
	* @param[in] flag  传入上一页还是下一页
		偏移标志 0.消息Id由大到小偏移 1.消息Id由小到大偏移 offsetFlag 2.按msgId精准查询
		如果msgId代表的是消息时间的话，或上0xF0,如果是消息ID的话就不用或上0xF0
	* @param[in] cb  传入接收结果回调 _1 错误信息 _2会话APPId _3客户id， _4消息集合
	*/
	virtual void getCustomMessages(int64 appId, int64 userId, int64 msgId, int count, int flag, SFunction<void(ErrorInfo, int64,int64, std::vector<MsgPtr>&)> cb) = 0;
	/**
	* @brief 获取客服信息
	* @param[in] csid 传入客服ID
	* @param[out] cb  传入接收结果回调 _1 错误号 _2 客服信息
	************************************************************************/
	virtual void getAppCustomerInfo(int64 csid, SFunction<void(ErrorInfo, AppCustomerInfo&)> cb) = 0;
	/**
	* @brief 获取智能客服数据库最后一条消息
	* @param[in] appId 传入公众号id 为0则表示获取智能客服最后一条消息，否则获取对应公众号的一条消息
	* @param[out] cb  传入接收结果回调 _1 错误号 _2 消息
	************************************************************************/
	virtual void getCustomerLastMessageByDB(int64 appId, SFunction<void(ErrorInfo, SSharedPtr<Msg>)> cb) = 0;

	/**
	* @brief 设置客户消息已读
	* @param[in] appID userID msgID
	* @param[out] cb  传入接收结果回调 _1 错误号 _2 客服信息
	************************************************************************/
	virtual void setCustomMsgReaded(int64 appID, int64 userID, int64 msgID, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* @brief 获取客服会话列表
	* @param[in] appId 传入公众号id 
	* @param[out] cb  传入接收结果回调 _1 错误号 _2 会话列表
	************************************************************************/
	virtual void getCustomChatList(int64 appId, SFunction<void(ErrorInfo, std::vector<CustomChat>& )> cb) = 0;
	//新版记事本
	/**
	* @brief 添加记事本
	* @param[in] note  记事本信息 见extpacket.h
	* @param[in] cb  传入接收结果回调 _1 错误号 _2 noteId
	*/
	virtual void addNotebook(Notebook& note, SFunction<void(ErrorInfo, int64)> cb) = 0;
	/**
	* @brief 获取记事本（直接获取所有记事本，没必要分页）
	* @param[in] type  排序方式 0.id 1.创建时间 2.修改时间
	* @param[in] offsetFlag  排序方向 0.由大到小 1.由小到大
	* @param[in] cb  传入接收结果回调 _1 错误号 _2 记事本信息
	*/
	virtual void getNotebook(int8 type, int8 offsetFlag, const std::string& hiddenKey, SFunction<void(ErrorInfo, std::vector<Notebook>&)> cb) = 0;
	/**
	* @brief 删除记事本
	* @param[in] notebookId  记事本id
	* @param[in] cb  传入接收结果回调 _1 错误号;
	*/
	virtual void delNotebook(std::vector<int64>& notebookId, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* @brief 删除记事本
	* @param[in] notebookId  记事本id
	* @param[in] enKey	  	 记事本密钥
	* @param[in] cb  传入接收结果回调 _1 错误号;
	*/
	virtual void delNotebookById(int64 notebookId, const std::string& enKey, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* @brief 修改记事本
	* @param[in] note  记事本信息 见extpacket.h（这个方法不会修改记事本的加密状态，传了也没用）
	* @param[in] cb  传入接收结果回调 _1 错误号;
	*/
	virtual void editNotebook(Notebook& note, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* @brief 修改记事本标签
	* @param[in] notebookId 记事本id
	* @param[in] label		标签
	* @param[in] cb  传入接收结果回调 _1 错误号;
	*/
	virtual void editNotebookLabel(int64 notebookId, const std::string& label, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* @brief 加密记事本
	* @param[in] noteId  记事本Id
	* @param[in] type  	 加密类型 1.字符加密 2.手势加密
	* @param[in] enKey   秘钥信息
	* @param[in] cb  传入接收结果回调 _1 错误号;
	*/
	virtual void encryptNotebook(int64 noteId, int8 type, const std::string& enKey, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* @brief 解密记事本
	* @param[in] noteId  记事本Id
	* @param[in] enKey   秘钥信息
	* @param[in] cb  传入接收结果回调 _1 错误号;
	*/
	virtual void decryptNotebook(int64 noteId, const std::string& enKey, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* @brief 搜索记事本
	* @param[in] label  标签
	* @param[in] cb  传入接收结果回调 _1 错误号; _2 搜索结果
	*/
	virtual void searchNotebook(const std::string& label, SFunction<void(ErrorInfo, std::vector<Notebook>&)> cb) = 0;
	/**
	* @brief 校验记事本密码
	* @param[in] noteId  记事本Id
	* @param[in] enKey   秘钥信息
	* @param[in] cb  传入接收结果回调 _1 错误号 0.正确 -9.密码错误
	*/
	virtual void checkNoteEnkey(int64 noteId, const std::string& enKey, SFunction<void(ErrorInfo)> cb) = 0; 
	/**
	* @brief 隐藏记事本
	* @param[in] noteId	 记事本Id
	* @param[in] hiddenKey   隐藏秘钥信息
	* @param[in] type   操作类型 3.隐藏 0.显示
	* @param[in] cb  传入接收结果回调 _1 错误号 0.正确 -3.sql执行错误 -9.密码错误
	*/
	virtual void hideNotebook(int64 noteId, const std::string& hiddenKey, int8 type, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* @brief 校验隐藏秘钥
	* @param[in] enKey   隐藏秘钥信息
	* @param[in] cb  传入接收结果回调 _1 错误号  _2 隐藏记事本数量
	*/
	virtual void checkHiddenKey(const std::string& hiddenKey, SFunction<void(ErrorInfo, int64)> cb) = 0;
	/**
	* @brief 添加记事内容
	* @param[in] entry  记事内容 见extpacket.h
	* @param[in] cb  传入接收结果回调 _1 错误号 _2记事内容id;
	*/
	virtual void addNoteEntry(NoteEntry& entry, SFunction<void(ErrorInfo, int64)> cb) = 0;
	/**
	* @brief 获取记事内容（加密记事本则需要传入enKey）
	* @param[in] param  获取参数 见extpacket.h
	* @param[in] cb  传入接收结果回调 _1 错误号 _2 记事内容
	*/
	virtual void getNoteEntry(GetNoteEntryParam& param, SFunction<void(ErrorInfo, std::vector<NoteEntry>&)> cb) = 0;
	/**
	* @brief 删除记事内容
	* @param[in] noteEntryId  记事条目Id
	* @param[in] cb  传入接收结果回调 _1 错误号;
	*/
	virtual void delNoteEntry(std::vector<int64>& noteEntryId, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* @brief 编辑记事内容
	* @param[in] entry  记事内容信息 见extpacket.h
	* @param[in] cb  传入接收结果回调 _1 错误号;
	*/
	virtual void editNoteEntry(NoteEntry& entry, SFunction<void(ErrorInfo)> cb) = 0;
	/**
	* @brief 搜索记事内容
	* @param[in] notebookId  记事本Id 
	* @param[in] searchText  搜索关键字 
	* @param[in] cb  传入接收结果回调 _1 错误号 _2记事内容
	*/
	virtual void searchNoteEntry(int64 notebookId, const std::string& searchText, SFunction<void(ErrorInfo, std::vector<NoteEntry>&)> cb) = 0;
	/**
	* @brief 根据账号信息获取手机盾信息
	* @param[in] eventType  事件类型：查询为1 登录为2
	* @param[in] accountInfo  用户的账号信息
	* @param[in] cb  传入接收结果回调 _1 错误号; _2 获取的用户手机盾数据信息
	***ErrorInfo:100008010：成功；100008011：手机盾开关未开启；100008012：手机账号不能为空；100008013：手机格式不正确； 100008014:账号类型不正确；100008015:事件类型不正确；100008016:该手机未绑定任何用户； 100008017：该用户未开通手机盾；100008018：获取eventData失败
	************************************************************************/
	//virtual void getUserShieldByAccount(int8 eventType, AccountType& accountInfo, SFunction<void(ErrorInfo, UserShield&)> cb) = 0;




	/**
	* @brief 设置会话开启或关闭端到端(同步接口)
	* @param[in] targetId  对方的ID，仅限单聊
	* @param[in] devType   设备类型：0表示所有设备更新，1表示更新PC，2表示更新Mobile，使用默认值0即可
	* @param[in] openFlag  开关标记：0表示关闭端到端，1表示开启端到端
	***int:0:成功；100:参数错误；11100:内部错误；100010050：入参校验失败；100010051：对方身份秘钥不存在；100010053:无法打开端到端开关，因为服务器总开关关闭；-16777134:无法打开端到端，因为本地初始化出错;
	*/
	virtual int setSecSessionOnOff(int64 targetId, int8 devType, int8 openFlag) = 0;


	/**
	* @brief 获取会话开启或关闭端到端状态(同步接口)
	* @param[in] targetId  对方的ID，仅限单聊
	* @param[in] devType   设备类型：0,pc和mobile的开关是一致的，所以给0即可
	* @param[out] openFlag  开关标记：0表示端到端会话关闭状态，1表示端到端会话开启状态
	***int:0:成功；100:参数错误；11100:内部错误；-16777134:如果状态是开，因为本地初始化端到端出错，报此错误;-16777125 端到端会话开关和总开关冲突;
	*/
	virtual int getSecSessionOnOff(int64 targetId, int8 devType, int8& openFlag) = 0;

	/**
	* @brief 每次收到解密失败的错误码时调用此接口(同步接口)
	* @param[in] targetId  对方的ID，仅限单聊
	* @param[in] devType   设备类型：1表示PC，2表示Mobile；解密失败根据解密失败的设备类型给值，如果解密失败的是自己的另一台设备，则根据自己的设备类型给另外一个设备类型值
	***int:0:成功；
	*/
	virtual int checkSecSession(int64 targetId, int8 devType) = 0;

	/**
	* @brief 人员组织机构搜索
	* @param[in] keyword 关键字(通用于用户/组织名称)
	* @param[in] orgIDs  选择的部门ID集合---该参数暂时未处理,默认搜索范围是全企业组织
	* @param[in] cb  传入接收结果回调 _1 错误号; _2 保留未使用; _3 组织信息列表; _4搜索的用户信息列表;
	***ErrorInfo:0：成功；100:参数错误；11100:内部错误；
	*/
	virtual void orgAndUserSearchEx(const std::string &keyword,const std::vector<int64> &orgIDs, SFunction<void(ErrorInfo, int64, std::vector<OrganizationInfo>&, std::vector<OrgSearchUserInfo>&)> cb) = 0;



	/**
	* @brief 消息检查
	* @param[in] message 消息内容
	* @param[in] cb  传入接收结果回调 _1 错误号; 检查结果
	***ErrorInfo:0：成功
	*/
	virtual void meessageSecurityCheck(const std::string &message, SFunction<void(ErrorInfo,std::map<std::string, int64>&)> cb) = 0;


	/**
	* @brief 文件检查
	* @param[in] 文件路径
	* @param[in] cb  传入接收结果回调 _1 错误号;_2 违规文件项 （多项违规 type值为按位或关系）
	*												0:没有违规项
	*												1: 文件内容违规
	*												2：文件名违规
	*												4：其他信息违规
	*								; _3 检查结果
	***ErrorInfo:0：成功
	*/
	virtual void fileSecurityCheck(const std::string &path, SFunction<void(ErrorInfo,int,std::map<std::string, int64>&)> cb) = 0;


	/**
	* @brief 设置检查规则
	* @param[in] 规则字符换
	* @param[in] 规则类型, 1:消息规则 2:文件规则 3:ckconfig.xml路径更新
	* @param[in] cb  传入接收结果回调 _1 错误号; 检查结果
	***ErrorInfo:0：成功
	*/
	virtual void setFileOrMsgRule(const std::string &rule, int type, SFunction<void(ErrorInfo)> cb) = 0;



};

} /*namespace service*/
