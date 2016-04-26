#include "../../Include.hpp"

namespace cc {
	
	size_t AutoupEngine::curlWriteData(void * nPtr, size_t nSize, size_t nMemb, void * nStream)
	{
		string * value_ = (string *)nStream;
		value_->append((const char *)nPtr);
		return (nSize * nMemb);
	}
	
	bool AutoupEngine::runAutoup()
	{
		ConfigEngine& configEngine_ = ConfigEngine::instance();
		configEngine_->runConfig<AutoupEngine *>(this);
		
		string value_("");
		
		CURL* curl_ = curl_easy_init();
		
		curl_easy_setopt(curl_, CURLOPT_URL, mUpdateUrl.c_str());
		curl_easy_setopt(curl_, CURLOPT_TIMEOUT, 15);
		curl_easy_setopt(curl_, CURLOPT_WRITEFUNCTION, curlWriteData);
		curl_easy_setopt(curl_, CURLOPT_WRITEDATA, value_);
		
		CURLcode curlCode_ = curl_easy_perform(curl_);
		curl_easy_cleanup(curl_);
		if(CURLE_OK != curlCode_) {
			LOGERROR("[%s]%s", __METHOD__, curl_easy_strerror(curlCode_));
			return false;
		}
		
	}
	
	const char * AutoupEngine::streamName()
	{
		return "autoupEngine";
	}
	
	const char * AutoupEngine::streamUrl()
	{
		return "autoupEngine.json";
	}
	
	AutoupEngine::AutoupEngine()
		: mAgentName("")
		, mUpdateUrl("")
	{
	}
	
	AutoupEngine::~AutoupEngine()
	{
		mAgentName = "";
		mUpdateUrl = "";
	}
	
}
