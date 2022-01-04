#pragma once

#include "../extModel/packet.h"

//�������ṹ
namespace model
{
	/*
	* �������
	* 
	* [��������]:
	*  1.reqType=1: groupId/roomId/roomName/members
	*  2.reqType=2: groupId/roomId/members
	*  3.reqType=3: groupId/roomId/members
	*  4.reqType=4: groupId/roomId
	*  5.reqType=5: groupId/roomId/annotation="click/busy/..."
	*/
	struct multiRequest {
		multiRequest() : reqType(0), groupId(0) {}
		int8 reqType;					///< ��������(1.call 2.invite 3.intoroom 4.join 5.hungup 6.keepalive)
		std::string annotation;			///< ����ע��
		int64 groupId;					///< ȺId
		std::string	roomId;				///< ����Id
		std::string roomName;			///< ��������
		std::vector<int64> members;		///< ��Ա�б�
		std::string extendJson;			///< ��չJson
	};
}
