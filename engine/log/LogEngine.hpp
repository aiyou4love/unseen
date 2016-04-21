#pragma once

namespace std {
	
	class LogEngine : noncopyable
	{
	public:
		void logError(const char * nValue, ...);
		void logInfo(const char * nValue, ...);
		void logWarn(const char * nValue, ...);
		
		static LogEngine& instance();
		
		LogEngine();
		~LogEngine();
		
	private:
		static LogEngine mLogEngine;
	};
	
#define LOGERROR LogEngine::instance().logError
#define LOGINFO LogEngine::instance().logInfo
#define LOGWARN LogEngine::instance().logWarn

}
