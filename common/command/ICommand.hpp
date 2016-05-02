#pragma once

namespace cc {
	
	class ICommand : noncopyable
	{
	public:
		virtual void runCommand() = 0;
	};
	
}
