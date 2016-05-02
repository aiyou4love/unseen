#pragma once

namespace cc {
	
	class StringTable : noncopyable
	{
	public:
		static StringTable& instance();
		
		StringTable();
		~StringTable();
		
	private:
		list<
		string mPath;
		
		static StringTable mStringTable;
	};
	
}
