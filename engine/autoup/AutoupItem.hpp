#pragma once

namespace std {
	
	class AutoupItem : noncopyable
	{
	public:
		void logError(const char * nValue, ...);
		void logInfo(const char * nValue, ...);
		void logWarn(const char * nValue, ...);
		
		static LogEngine& instance();
		
		AutoupItem();
		~AutoupItem();
		
	private:
		static LogEngine mLogEngine;
	};
	
}
