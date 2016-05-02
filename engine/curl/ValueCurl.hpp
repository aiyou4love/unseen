#pragma once

namespace cc {
	
	typedef size_t (* CurlFun_t)(void *, size_t, size_t, void *);
	class ValueCurl : noncopyable
	{
	public:
		virtual CurlFun_t getCurlFun() = 0;
		virtual void * getCurlValue() = 0;
		
		ValueCurl();
		~ValueCurl();
	};
	
}
