#pragma once

namespace cc {
	
	class BaseCurl : noncopyable
	{
	public:
		void runInit(const char * nUrl);
		bool runPerform();
		
		BaseCurl();
		~BaseCurl();
		
	private:
		CURL * mHandle;
	};
	
}
