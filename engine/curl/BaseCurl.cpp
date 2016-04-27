#pragma once

namespace cc {
	
	void BaseCurl::runInit(const char * nUrl)
	{
		mHandle = curl_easy_init();
		
		curl_easy_setopt(mHandle, CURLOPT_URL, nUrl);
	}
	
	bool BaseCurl::runPerform()
	{
		CURLcode curlCode_ = curl_easy_perform(mHandle);
		if(CURLE_OK != curlCode_) {
			LOGERROR("[%s]%s", __METHOD__, curl_easy_strerror(curlCode_));
			return false;
		}
		return true;
	}
	
	BaseCurl::BaseCurl()
		: mHandle (nullptr)
	{
	}
	
	BaseCurl::~BaseCurl()
	{
		curl_easy_cleanup(mHandle);
		mHandle = nullptr;
	}
	
}
