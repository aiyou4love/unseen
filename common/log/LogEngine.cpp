#include "../../Include.hpp"

namespace std {
	
	void LogEngine::logError(const char * nValue, ...)
	{
		char buf[1024]; memset(buf, 0, sizeof(buf));
		va_list argList_; va_start(argList_, nValue);
		vsprintf(buf, nValue, argList_);
		va_end(argList_);
		cout << "[error]" << buf << endl;
	}
	
	void LogEngine::logInfo(const char * nValue, ...)
	{
		char buf[1024]; memset(buf, 0, sizeof(buf));
		va_list argList_; va_start(argList_, nValue);
		vsprintf(buf, nValue, argList_);
		va_end(argList_);
		cout << "[info]" << buf << endl;
	}
	
	void LogEngine::logWarn(const char * nValue, ...)
	{
		char buf[1024]; memset(buf, 0, sizeof(buf));
		va_list argList_; va_start(argList_, nValue);
		vsprintf(buf, nValue, argList_);
		va_end(argList_);
		cout << "[warn]" << buf << endl;
	}
	
	LogEngine& LogEngine::instance()
	{
		return mLogEngine;
	}
	
	LogEngine::LogEngine()
	{
	}
	
	LogEngine::~LogEngine()
	{
	}
	LogEngine LogEngine::mLogEngine;
	
}
