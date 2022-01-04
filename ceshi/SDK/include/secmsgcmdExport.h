#ifndef  SEC_CMDEXPORT_H
#define SEC_CMDEXPORT_H

#include <cmdComDef.h>
#include <cmdReqDef.h>


using namespace imsdk;

namespace imsdksecmsg{
	enum {
		secmsg_logic_cmd_min = 26000,

		/// [in] req_secmsgSetRule		[out] resp_commonResult
		secmsg_logic_cmd_setRule = 26001,          

		/// [in] req_secmsgMsgCheck	                [out] resp_secmsgFileOrMsgCheck
		secmsg_logic_cmd_checkMsg = 26002,              

		/// [in] req_secmsgFileCheck	            [out] resp_secmsgFileOrMsgCheck
		secmsg_logic_cmd_checkFile = 26003,         

		secmsg_logic_cmd_max =26999
	};

	struct req_secmsgFileCheck :public _sdkcmd_base{

		req_secmsgFileCheck(){}
		void init(){
			filepath = "";
			localID = 0;
		}
		std::string filepath;
		CMD_SIZE();
	};

	struct resp_secmsgFileOrMsgCheck :public _sdkrespcmd_base{
		resp_secmsgFileOrMsgCheck() :fileCheckType(0) {}

		std::map<std::string, int64>  badWords;
		int fileCheckType;
		void init(){
			badWords.clear();
			fileCheckType = 0;
			localID = 0;
		}
		CMD_SIZE();
		COPY_OTHER(resp_secmsgFileOrMsgCheck);
	};


	struct req_secmsgMsgCheck :public _sdkcmd_base{

		req_secmsgMsgCheck(){}
		void init(){
			context = "";
			localID = 0;
		}
		std::string context;
		CMD_SIZE();
	};


	struct req_secmsgSetRule :public _sdkcmd_base{

		req_secmsgSetRule(){}

		std::string rule;
		int type;
		void init(){
			rule = "";
			localID = 0;
			type = 0;
		}
		CMD_SIZE();
	};

};




#endif
