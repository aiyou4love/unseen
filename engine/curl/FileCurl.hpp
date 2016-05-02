#pragma once

namespace cc {
	
	class FileCurl : public ValueCurl
	{
	public:
		CurlFun_t getCurlFun();
		void * getCurlValue();
		
		FileCurl();
		~FileCurl();
		
	private:
		static size_t curlFun(void *, size_t, size_t, void *);
		
	protected:
		FILE * mHandle;
	};
	
}
