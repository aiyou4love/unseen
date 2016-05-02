#pragma once

namespace cc {
	
	class StringCurl : public ValueCurl
	{
	public:
		CurlFun_t getCurlFun();
		void * getCurlValue();
		
		StringCurl();
		~StringCurl();
		
	private:
		static size_t curlFun(void *, size_t, size_t, void *);
		
	protected:
		string mValue;
	};
	
}
