#pragma once

namespace cc {
	
	class BaseCurl : noncopyable
	{
	public:
		void runValueCurl(ValueCurl * nValueCurl);
		void runDebugInfo();
		void runInit(const char * nUrl);
		bool runPerform();
		
		BaseCurl();
		~BaseCurl();
		
	protected:
		CURL * mHandle;
	};
	
}
