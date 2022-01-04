// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

// TODO: 在此处引用程序需要的其他头文件
#ifdef _WIN32
#include <Windows.h>
#endif
#include "tools.h"
#include "sdk_unitest.h"
using namespace service;
using namespace serviceTest;
const int64 err_sdk_unknownMethod = 100008008;		//未知的方法名，可能是服务器还没上线该功能(此枚举不能为负数)
#define MAC_ADDRESS "10:EC:9F:7A:8F:7F"
#define MAC_ADDRESS_PHONE "1F:EC:9F:7A:8F:7F"
const int64 MB = 1024 * 1024;

