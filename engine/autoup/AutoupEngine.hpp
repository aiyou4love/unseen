#pragma once

namespace std {
	
	class AutoupEngine : noncopyable
	{
	public:
		static AutoupEngine& instance();
		
		AutoupEngine();
		~AutoupEngine();
		
	private:
		string mUpdateUrl;
		string mDownUrl;
		
		static AutoupEngine mAutoupEngine;
	};
	
}
