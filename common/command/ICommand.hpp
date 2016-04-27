#pragma once

namespace cc {
	
	class ICommand
	{
	public:
		virtual void runCommand() = 0;
		
		ICommand();
		~ICommand();
		
	private:
		int32_t mDoingId;
		Value 
	};
	
}
