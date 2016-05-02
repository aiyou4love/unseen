#pragma once

namespace cc {
	
	#define UTF8HEADER "content-type:application/json;charset=utf-8"
	#define XMLHEADER "content-type:application/xml;charset=utf-8"
	
	void HttpCurl::runHttpPost(const char * nValue)
	{
		curl_easy_setopt(mHandle, CURLOPT_POSTFIELDS, nValue);
		curl_easy_setopt(mHandle, CURLOPT_POST, 1);
	}
	
	void HttpCurl::runHttpHeader(int8_t nType)
	{
		if (1 == nType) {
			curl_slist * curlList_ = curl_slist_append(NULL, XMLHEADER);
			curl_easy_setopt(mHandle, CURLOPT_HTTPHEADER, curlList_);
		} else {
			curl_slist * curlList_ = curl_slist_append(NULL, UTF8HEADER);
			curl_easy_setopt(mHandle, CURLOPT_HTTPHEADER, curlList_);
		}
	}
	
	void HttpCurl::runTimeout(int16_t nTimeout)
	{
		curl_easy_setopt(mHandle, CURLOPT_TIMEOUT, nTimeout);
	}
	
	void HttpCurl::runSSL()
	{
		curl_easy_setopt(mHandle, CURLOPT_SSL_VERIFYPEER, false);
		curl_easy_setopt(mHandle, CURLOPT_SSL_VERIFYHOST, true);
	}
	
	HttpCurl::HttpCurl()
	{
	}
	
	HttpCurl::~HttpCurl()
	{	
	}
	
}
