#include "tools.h"
#include "Environment.h"
#include "parson.h"
std::string Tools::GetModulePath()
{
	std::string strPath;
#ifdef _WIN32
	char path[260] = { 0 };
	_getcwd(path, sizeof(path));
	strPath = path;
	strPath += "\\";
#else
	strPath = getcwd(NULL, 0);
	strPath += "/";
#endif // 
	
	return strPath;
}
void Tools::sleep(int32 msec) {
#ifndef _WIN32
	usleep(msec * 1000);
#else
	Sleep(msec);
#endif
}
int64 Tools::strToInt64(const char * pNumber) {
	if (pNumber != NULL)
#ifdef WIN32
		return _atoi64(pNumber);
#else
		return strtoll(pNumber, NULL, 10);
#endif
	else
		return 0;
}
std::string Tools::int64_To_Str(int64 i) {
	char buffer[32] = "";
	sprintf(buffer, "%lld", i);
	return buffer;
}
std::shared_ptr<IMClient> Tools::getServiceClient() {
	std::shared_ptr<IMClient> result = nullptr;
#ifndef SDK_FOR_ANDROID 
	result = getClient();
#else
	std::string path = Tools::GetModulePath() + "libjniVimServicePresets.so";
	if (nullptr == g_handle) {
		g_handle = dlopen(path.c_str(), RTLD_NOW);
		if (nullptr == g_handle) {
			std::cout << "load failed,err msg=" << dlerror() << "dll Path=" << path.c_str() << std::endl;
			return result;
		}
	}
	SERVICE_FUC_PTR funcPtr = (SERVICE_FUC_PTR)dlsym(g_handle, "_ZN7service9getClientEv");
	if (nullptr == funcPtr) {
		std::cout << "load failed,err msg=" << dlerror() << " dll Path=" << path.c_str()<< std::endl;
		return result;
	}
	result = funcPtr();
#endif
	std::cout << "result=" << result.get() << std::endl;
	return result;
}
std::string Tools::int64ToStr(const int64 val){
	char buffer[32] = "";
	sprintf(buffer, "%lld", val);
	return buffer;
}
int64 Tools::getPID() {
#ifndef _WIN32
	int64 pid = getpid();
#else
	unsigned long pid = GetCurrentProcessId();
#endif
	return pid;
}
std::string Tools::getGUID() {
	char szBase[128] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	int  baseLen = strlen(szBase);
	char szBuffer[33] = "";
	for (int i = 0; i < 32; i++) {
		int tmp = rand();
		szBuffer[i] = szBase[tmp%baseLen];
	}
	std::string ret = szBuffer;
	return ret;
}
std::string Tools::getGUIDJson(const std::string&uuid){
	std::string result;
	JSON_Value * pJson = json_value_init_object();
	JSON_Object *root_object = json_value_get_object(pJson);

	json_object_set_string(root_object, "uuid", uuid.c_str());
	char *ptemp = json_serialize_to_string(pJson);
	if (nullptr != ptemp) {
		result = std::string(ptemp);
		json_free_serialized_string(ptemp);
	}
	return result;
}
std::string Tools::prasonGUIDJson(const std::string&json) {
	std::string result;
	JSON_Value * pJson = json_parse_string(json.c_str());
	if (pJson == nullptr) {
		result = "";
		return result;
	}
	JSON_Object *root_object = json_value_get_object(pJson);
	if (root_object == nullptr) {
		json_value_free(pJson);
		result = "";
		return result;
	}
	const char* uuidStr = json_object_get_string(root_object, "uuid");
	if (nullptr != uuidStr) {
		result = std::string(uuidStr).c_str();
	}
	json_value_free(pJson);
	return result;
}
int64 Tools::GetTime_t(int32 year, int32 month, int32 day) {
	struct tm date = { 0 };
	time_t	time = 0;

	if (year == 0 || month == 0 || day == 0) {
		return 0;
	}
	date.tm_year = year - 1900;
	date.tm_mon = month - 1;
	date.tm_mday = day;

	time = mktime(&date);

	return time;
}
int64 Tools::get_mill_sec() {
#ifndef  _WIN32
	struct timeval tv;
	gettimeofday(&tv, 0);
	int64 temp1 = tv.tv_sec;
	temp1 = temp1 * 1000;
	return temp1 + tv.tv_usec / 1000;
#else
	SYSTEMTIME systime;
	GetLocalTime(&systime);
	int64 dayTime = GetTime_t(systime.wYear, systime.wMonth, systime.wDay);

	int hour = systime.wHour;
	int minute = hour * 60 + systime.wMinute;
	int second = minute * 60 + systime.wSecond;
	int64 mills = second * 1000 + systime.wMilliseconds;

	return dayTime * 1000 + mills;
#endif
}
std::string Tools::GBToUTF8(const char* str) {
	std::string result;
#ifdef _WIN32
	WCHAR *strSrc;
	char *szRes;

	//获得临时变量的大小
	int i = MultiByteToWideChar(936, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(936, 0, str, -1, strSrc, i);

	//获得临时变量的大小
	i = WideCharToMultiByte(CP_UTF8, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new char[i + 1];
	int j = WideCharToMultiByte(CP_UTF8, 0, strSrc, -1, szRes, i, NULL, NULL);

	result = szRes;
	delete[]strSrc;
	delete[]szRes;
#else  //TODO
	result = str;
#endif
	return result;
}

std::string Tools::getFileNameByPath(const std::string &fullPath, bool postFix)
{
	int index = fullPath.rfind('/');
	int index1 = fullPath.rfind('\\');
	index = index > index1 ? index : index1;

	if (postFix)
	{
		return fullPath.substr(index + 1);
	}
	else
	{
		std::string fileName = fullPath.substr(index + 1);
		index = fileName.find('.');
		if (index != std::string::npos)
		{
			return fileName.substr(0, index);
		}
		return fileName;
	}
}

std::wstring Tools::SToWS(const std::string &str)
{
#ifndef SDK_FOR_XP
	int len = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
	wchar_t* wide = new wchar_t[len + 1];
	memset(wide, '\0', sizeof(wchar_t) * (len + 1));
	MultiByteToWideChar(936, 0, str.c_str(), -1, wide, len);
	std::wstring w_str(wide);
	delete[] wide;
	return w_str;
	///与平台无关的实现，但是setlocale在win7系统上存在未知原因导致死锁问题http://www.voidcn.com/article/p-aullgpdy-bue.html
#else
	size_t i;
	std::string curLocale = setlocale(LC_ALL, NULL);
	setlocale(LC_ALL, "chs");
	const char* _source = str.c_str();
	size_t _dsize = str.size() + 1;
	wchar_t* _dest = new wchar_t[_dsize];
	wmemset(_dest, 0x0, _dsize);
	mbstowcs_s(&i, _dest, _dsize, _source, _dsize);
	std::wstring result = _dest;
	delete[] _dest;
	setlocale(LC_ALL, curLocale.c_str());
	return result;
#endif
}
int64 Tools::getFileSize(const char * pSrc) {
#ifdef _WIN32
	struct __stat64 st64;
#ifdef _WIN32
	if (_wstat64(SToWS(pSrc).c_str(), &st64) == -1)
#else
	if (_stat64(pSrc, &st64) == -1)
#endif
	{
		return -1;
	}
	return st64.st_size;
#else
	struct stat st;
	if (stat(pSrc, &st) == -1) {
		return -1;
	}
	return st.st_size;
#endif
}