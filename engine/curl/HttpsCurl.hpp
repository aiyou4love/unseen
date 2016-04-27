#pragma once

namespace cc {
	
	typedef size_t (* curlMethod_t)(void *, size_t, size_t, void *);
	
	class HttpCommand : public ICommand
	{
	public:
		void runInit(const char * nUrl, int16_t nTimeout);
		
		virtual curlMethod_t getcurlMethod() = 0;
		
		void runClose();
		
		void runCommand();
	};
	
}
