//Author: lixuyang
//Date: 2020-10-113
//Description:工具类
#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <stdint.h>
#include <stdlib.h>
#include <future>
#include <memory>
#include "interface/IMClient.h"
#ifdef _WIN32
#include <direct.h>
#include <Windows.h>
#else
#include <unistd.h>
#include <dlfcn.h>
#endif
#ifdef  _WIN32
typedef   char					int8;
typedef   unsigned char			uint8;
typedef   short					int16;
typedef   unsigned short		uint16;
typedef   int					int32;
typedef   unsigned int			uint32;
typedef   __int64				int64;
typedef   unsigned  __int64		uint64;
#elif  defined(__linux__)
#include <stdint.h>
typedef   int8_t     int8;
typedef   uint8_t    uint8;
typedef   int16_t    int16;
typedef   uint16_t   uint16;
typedef   int32_t    int32;
typedef   uint32_t   uint32;
typedef   int64_t    int64;
typedef   uint64_t   uint64;
#elif  defined(__APPLE__)
#include <stdint.h>
typedef   int8_t     int8;
typedef   uint8_t    uint8;
typedef   int16_t    int16;
typedef   uint16_t   uint16;
typedef   int32_t    int32;
typedef   uint32_t   uint32;
typedef   int64_t    int64;
typedef   uint64_t   uint64;
#endif
// TODO: 在此处引用程序需要的其他头文件
using namespace service;
typedef std::shared_ptr<IMClient>(* SERVICE_FUC_PTR)();
class Tools
{
public:
	static std::string GetModulePath();
	static void sleep(int32 msec);
	static int64 strToInt64(const char * pNumber);
	static std::string int64_To_Str(int64 i);
	static std::shared_ptr<IMClient> getServiceClient();
	static std::string int64ToStr(const int64 val);
	static int64 getPID();
	static std::string getGUID();
	static std::string getGUIDJson(const std::string&uuid);
	static std::string prasonGUIDJson(const std::string&json);
	static int64 GetTime_t(int32 year, int32 month, int32 day);
	static int64 get_mill_sec();
	static std::string GBToUTF8(const char* str);
	/// 从文件路径获取文件名
	static std::string getFileNameByPath(const std::string &fullPath, bool postFix = true);
	static std::wstring Tools::SToWS(const std::string &str);
	//获取文件大小
	static int64 Tools::getFileSize(const char * pSrc);
};

