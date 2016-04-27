#pragma once

namespace cc {
	
	typedef size_t curl(void * nPtr, size_t nSize, size_t nMemb, void * nStream);
	
	class UrlCommand : public ICommand
	{
	public:
		void runInit(const char * nUrl, int16_t nTimeout);
		void runClose();
		
		void runCommand();
	};
	
}
