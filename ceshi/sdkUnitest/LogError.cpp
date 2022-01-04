
#include "LogError.h"
LogError* LogError::m_Logerror = NULL;

bool LogError::logErrorIn(const string& errorInfo, string testCase){
	if (testCase.empty())
		testCase = __FUNCTION__;
	if (errorInfo.empty())
		return false;
	pair<string, string> temp = make_pair(testCase, errorInfo);
	m_vclogInfo.push_back(temp);
	return true;
}
vector<pair<string, string> >& LogError::GetLogError(){
	return m_vclogInfo;
}
const char* LogError::logInfoSearch(const string& caseName){
	vector<pair<string, string> >::iterator  it = m_vclogInfo.begin();

	while (it != m_vclogInfo.end()){
		if (strstr(caseName.c_str(),it->first.c_str())){
			return it->second.c_str();
		}
		++it;
	}
	return NULL;
}

bool LogError::logErrorOut(unsigned int index,pair<string,string>& Info ){
	if (index < 0 || index > m_vclogInfo.size())
		return false;

	Info = m_vclogInfo[index];
	return true;
}