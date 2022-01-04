#ifndef HTTPSERVERPLUGIN_EXPORT_H
#define HTTPSERVERPLUGIN_EXPORT_H

#include "interfaceExport.h"
#include "stdio.h"

/// 声明
EXPORT_PLUGIN CREATE_PLUGIN(httpServerplugin);
EXPORT_PLUGIN RELEASE_PLUGIN(httpServerplugin);
namespace imsdkhttpServer {
	enum
	{
		/**
		* \brief 登陆跳转url,返回code推送
		*[in] NULL
		*[out] url
		*/
		http_logic_cmd_oAuthInfo = 21001,
	};
}
#endif
