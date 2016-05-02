#pragma once

namespace cc {
	
	class HttpCurl : public BaseCurl
	{
	public:
		void runHttpPost(const char * nValue);
		void runHttpHeader(int8_t nType);
		void runTimeout(int16_t nTimeout);
		void runSSL();
		
		HttpCurl();
		~HttpCurl();
	};
	
}
