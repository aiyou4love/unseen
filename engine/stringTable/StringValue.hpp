#pragma once

namespace cc {
	
	class StringValue : noncopyable
	{
	public:
		template<class T>
		void serialize(T nSerialize, int8_t nCount)
		{
			nSerialize->runNumber(mValue, "value");
			nSerialize->runNumber(mKey, "key");
		}
		
		const char * getValue();
		const char * getKey();
		
		StringValue();
		~StringValue();
		
	private:
		string mKey;
		string mValue;
	};
	
}
