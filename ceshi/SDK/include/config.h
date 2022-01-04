/*
 * config.h
 *
 *  Created on: 2015年7月22日
 *      Author: sharp
 */

#ifndef CONFIG_H_
#define CONFIG_H_
#include <string>
#ifdef  _WIN32
typedef   char   int8;
typedef   unsigned char  uint8;
typedef   short  int16 ;
typedef   unsigned short uint16 ;
typedef   int    int32 ;
typedef   unsigned int   uint32 ;
typedef   __int64   int64 ;
typedef   unsigned  __int64  uint64 ;
#elif  defined(__linux__)
#include <stdint.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <semaphore.h>
#include <stdarg.h>

typedef   int8_t     int8   ;
typedef   uint8_t    uint8  ;
typedef   int16_t    int16  ;
typedef   uint16_t   uint16 ;
typedef   int32_t    int32  ;
typedef   uint32_t   uint32  ;
typedef   int64_t    int64  ;
typedef   uint64_t   uint64 ;
#elif  defined(__APPLE__)
#include <stdint.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <semaphore.h>
#include <stdarg.h>

typedef   int8_t     int8   ;
typedef   uint8_t    uint8  ;
typedef   int16_t    int16  ;
typedef   uint16_t   uint16 ;
typedef   int32_t    int32  ;
typedef   uint32_t   uint32  ;
typedef   int64_t    int64  ;
typedef   uint64_t   uint64 ;
#endif
#ifdef  _WIN32
	#ifndef WIN32_LEAN_AND_MEAN
		#define WIN32_LEAN_AND_MEAN
	#endif
	#include <windows.h>

	#include <process.h>
	#define  THRED_RETURN  uint32
#else
	#define __stdcall
	#define  THRED_RETURN  void *
#endif
struct thread_info {
	std::string name;
	///线程ID
#ifndef _WIN32
	pthread_t tid ;
#else
	uint32     tid ;
	HANDLE    handle ;
#endif
	thread_info() {
		clear();
	}
	void clear() {
		name = "";
		tid = 0;
#ifdef _WIN32
		handle = INVALID_HANDLE_VALUE;
#endif
	}
};

/**
 * 最大终端数量
 */
#define  MAX_CLI_CNT      512

//#define  ENCRYPT_DB

#ifdef _WIN32
	#ifdef IMSDK_EXPORT
        #define  IMSDK_EXPORT_API __declspec(dllexport)
	#else
        #define  IMSDK_EXPORT_API __declspec(dllimport)
	#endif
#else
	#define  IMSDK_EXPORT_API
#endif

#ifdef _WIN32
    #ifdef  PLUGIN_EXPORT
        #define EXPORT_PLUGIN extern "C" _declspec(dllexport)
    #else
        #define EXPORT_PLUGIN extern "C" _declspec(dllimport)
    #endif
#else
	#define EXPORT_PLUGIN extern "C"
#endif

#ifdef _WIN32
    #ifdef COMM_EXPORT
        #define  COMM_EXPORT_API __declspec(dllexport)
    #else
        #define  COMM_EXPORT_API __declspec(dllimport)
    #endif
#else
    #define  COMM_EXPORT_API
#endif

#ifdef _WIN32
#ifdef CORE_EXPORT
#define  CORE_EXPORT_API __declspec(dllexport)
#else
#define  CORE_EXPORT_API __declspec(dllimport)
#endif
#else
#define  CORE_EXPORT_API
#endif
/**
 *    终端类型宏定义
 */
//#define  SDK_FOR_IOS
//#define  SDK_FOR_ANDROID
//#define  SDK_FOR_PC
//#define  WITHOUT_SSL  //打开该宏，就是不使用SSL
//#define  OEM_OS_YUANXIN  //元心系统专用

#endif /* CONFIG_H_ */
