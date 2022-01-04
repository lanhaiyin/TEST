#ifndef _LOG_ERROR_H_
#define _LOG_ERROR_H_
#include <vector>
#include <string>
#include <cstring>
using namespace std;

#ifdef __linux__
#define Sleep(x) sleep(x/1000)
#endif

class LogError{
public:
  static LogError* getInstance(){
	  if (m_Logerror == NULL)
		  m_Logerror =  new LogError();
	  return m_Logerror;
  }
  bool logErrorIn(const string& errorInfo, string testCase = "");
  bool logErrorOut(unsigned int, pair<string, string>&);
  vector<pair<string, string> >& GetLogError();
  const char* logInfoSearch(const string& caseName);
private:
	LogError(){}
	vector<pair<string,string> > m_vclogInfo;//1 用例名 ，2，错误信息
	static LogError* m_Logerror;
};

#define ERRORIN(case,format, ...)  char info[150] = {0};\
									sprintf(info, format, ##__VA_ARGS__); \
									printf("%s\n", info);\
								LogError::getInstance()->logErrorIn(std::string(info), case);
#endif