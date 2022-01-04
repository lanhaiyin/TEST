/*
 * mrtccmdExport.h
 *
 *  Created on: 2018年10月25日
 *  Author: wangYan
 */

#ifndef _MRTC_CMDEXPORT_H_
#define _MRTC_CMDEXPORT_H_

#include "cmdReqDef.h"
#include "cmdComDef.h"

//在线消息
#define MRTC_ONLINE_MSG 15
//必达消息
#define MRTC_MUST_MSG 14
//弱提示消息
#define WEAK_HINT_MSG 8
//模板消息
#define TEMP_MSG 26
//文本消息
#define TEXT_MSG 2

#define MSGDELETEFLAG		-10001
#define MSGTRANS10001FLAG	-10002

using namespace imsdk;

namespace imsdkmrtc{

/**
 * 导出业务类消息号，各个平台的ＡＰＩ层要统一
 * ** [in] 标识输入参数
 * ** [out] 标识返回参数
 * ** 只有[out]没有[in] 标识该消息ＳＤＫ纯推送，只有reponse没有request
 */
enum {
	//呼叫 
	mrtc_logic_cmd_call = 24001,		///< [in] req_mrtc_request [out]resp_commonResult.
	//邀请
	mrtc_logic_cmd_invite = 24002,		///< [in] req_mrtc_request [out]resp_commonResult.
	//进房
	mrtc_logic_cmd_intoroom = 24003,	///< [in] req_mrtc_request [out]resp_commonResult.
	//加入
	mrtc_logic_cmd_join = 24004,		///< [in] req_mrtc_request [out]resp_commonResult.
	//挂断
	mrtc_logic_cmd_hungup = 24005,		///< [in] req_mrtc_request [out]resp_commonResult.
	//扩展
	mrtc_logic_cmd_extra = 24006,		///< [in] req_mrtc_extra [out]resp_commonResult.
	//事件通知
	mrtc_logic_cmd_eventNotify = 24007,	///< [in] NULL[out] resp_mrtcEvent.
	//心跳
	mrtc_logic_cmd_keepalive = 24008,	///< [in] req_mrtc_extra [out]resp_commonResult.
	//连接状态
	mrtc_logic_cmd_connectstate = 24009,	///< [in] req_mrtc_request [out]resp_commonResult.
	//模板加入
	mrtc_logic_cmd_templetjoin = 24010,	///< [in] req_mrtc_request [out]resp_commonResult.

	mrtc_logic_cmd_max
};

/// =========================================================================================

//请求
struct req_mrtc_request : public _sdkcmd_base {

	int8 reqType;					///< 请求类型(1.call 2.invite 3.intoroom 4.join 5.hungup 6.keepalive 7.roomconnect)
	std::string annotation;			///< 请求注释
	int64 groupId;					///< 群ID
	std::string roomId;				///< 房间ID
	std::string roomName;			///< 房间名称
	std::vector<int64> members;		///< 呼叫/邀请成员列表
	std::string extendJson;			///< 扩展Json

	req_mrtc_request() : reqType(0), groupId(0){}
	CMD_SIZE();
};

//请求
struct req_mrtc_extra : public _sdkcmd_base {

	int8 type;						///< 请求类型
	std::string cmdJson;			///< 请求参数
	std::string extendJson;			///< 扩展Json

	req_mrtc_extra() : type(0) {}
};

//通知
struct resp_mrtcEvent : public _sdkrespcmd_base {
	
	//命令数据
	int8 type;							///<事件类型.
	std::string annotation;				///<事件注释.
	int64 userId;						///<事件发起者ID.
	std::vector<int64> selects;			///<选中成员(呼叫成员/邀请成员).

	//通话状态
	int64 groupId;						///<群ID.
	int64 onwerId;						///<主人ID.
	std::string roomId;					///<房间ID.
	std::string roomName;				///<房间名称.
	std::vector<int64> members;			///<全部成员.

	//其他数据
	std::string extendJson;				///<扩展Json.
	
	resp_mrtcEvent() : type(0), groupId(0), onwerId(0){}
	CMD_SIZE();
	COPY_OTHER(resp_mrtcEvent);
};
}

#endif // _MRTC_CMDEXPORT_H_