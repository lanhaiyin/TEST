#pragma once
#include <memory>
#include "interface/IMClient.h"
#include "interface/IAuthService.h"
#include "interface/IChatService.h"
#include "interface/IContactService.h"
#include "interface/IGroupService.h"
#include "interface/IUserService.h"
#include "interface/IConfigService.h"
#include "interface/ISearchService.h"
#include "interface/ISysMsgService.h"
#include "interface/IFileService.h"
#include "interface/IRtcService.h"
#include "interface/IExtService.h"
#include "interface/IGaInterService.h"
#include "interface/ICloudService.h"
#include "TestConfig.h"
#include "semer.hpp"
struct CommABInfo {
	CommABInfo():sendTime(0),RecvTime(0),uuid(""){
		semer = new MySemer;
	}
	CommABInfo(const CommABInfo&obj) {
		sendTime = obj.sendTime;
		RecvTime = obj.RecvTime;
		uuid = obj.uuid;
		semer = obj.semer;
	}
	int64		sendTime;   //消息发送时间
	int64		RecvTime;	//消息接收时间
	std::string uuid;
	MySemer*	semer;      //同步信号量
};
using namespace service;
using namespace serviceTest;
	class sdkUniTest
	{
	public:
		sdkUniTest();
		~sdkUniTest();
		static CommABInfo makeSemperUuid();
		static CommABInfo getSemperUuid(const std::string&uuid);
		void initCallBack();
		void clearCllBack();
		void msgNotifyCallBack(SSharedPtr<Msg> msg);
		void msgUpdateFinishCallBack(int code);
		int loginByIndex(const int index);
		int loginOutByIndex(const int index);
		inline std::shared_ptr<IAuthService> AUTHSERVICE() {
			return SERVICE_GET(IAuthService, m_client, IID_IAuthSrvice, VER_IAUTH);
		}
		inline std::shared_ptr<IContactService> CONTACTSERVICE() {
			return SERVICE_GET(IContactService, m_client, IID_IContactService, VER_CONTACT);
		}
		inline std::shared_ptr<IGroupService> GROUPSERVICE() {
			return SERVICE_GET(IGroupService, m_client, IID_IGroupService, VER_GROUP);
		}
		inline std::shared_ptr<IConfigService> CONFIGSERVICE() {
			return SERVICE_GET(IConfigService, m_client, IID_IConfigService, VER_CONFIG);
		}
		inline std::shared_ptr<IUserService> USERSERVICE() {
			return SERVICE_GET(IUserService, m_client, IID_IUserService, VER_USER);
		}
		inline std::shared_ptr<IChatService> CHATSERVICE() {
			return SERVICE_GET(IChatService, m_client, IID_IChatService, VER_IChatService);
		}
		inline std::shared_ptr<ISearchService> SEARCHSERVICE() {
			return SERVICE_GET(ISearchService, m_client, IID_ISearchService, VER_SEARCH);
		}
		inline std::shared_ptr<IFileService> FILESERVICE() {
			return SERVICE_GET(IFileService, m_client, IID_IFileService, VER_FILE);
		}
		inline std::shared_ptr<ISysMsgService> SYSMSGSERVICE() {
			return SERVICE_GET(ISysMsgService, m_client, IID_ISysMsgService, VER_SYSMSG);
		}
		inline std::shared_ptr<IRtcService> RTCSERVICE() {
			return SERVICE_GET(IRtcService, m_client, IID_IRtcSrvice, VER_IRTC);
		}
		inline std::shared_ptr<IExtService> EXTSERVICE() {
			return SERVICE_GET(IExtService, m_client, IID_IExtService, VER_EXT);
		}
		inline std::shared_ptr<IGaInterService> GAISERVICE() {
			return SERVICE_GET(IGaInterService, m_client, IID_IGaInterService, VER_GAINTER);
		}
		inline std::shared_ptr<ICloudService> CLOUDSERVICE() {
			return SERVICE_GET(ICloudService, m_client, IID_ICloudService, VER_ICLOUD);
		}
		inline CTestConfig * getConfig() {
			return m_configPtr;
		}
	private:
		std::shared_ptr<IMClient> m_client;
		std::shared_ptr<IExtService> m_lddservice;
		std::shared_ptr<IChatService> m_chatservice;
		std::shared_ptr<IConfigService> m_configservice;
		std::shared_ptr<IFileService> m_fileservice;
		CTestConfig * m_configPtr;
		std::promise<int> m_reqProm;
		std::future<int>  m_reqFut;
		bool m_waitUpdate;
		static std::mutex m_mutex;
		static std::map<std::string, CommABInfo> m_mapSemper;
	};
	extern int64 g_sta_groupid;
	extern int64 g_sta_workRoom;
#ifdef SDK_FOR_ANDROID
	extern volatile bool g_isExitAndriodRspThd;
	extern void* g_handle;
#endif
	extern sdkUniTest g_test[2];
	#define m_config  g_test[0].getConfig()
