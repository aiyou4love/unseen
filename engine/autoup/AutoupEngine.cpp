#include "../../Include.hpp"

namespace cc {
	
	bool AutoupEngine::runAutoup()
	{
		ConfigEngine& configEngine_ = ConfigEngine::instance();
		configEngine_->runConfig<AutoupEngine *>(this, streamUrl(), streamName());
		
		boost::format format_(mUpdateUrl);
		format_ % mAgentName;
		format_ % mVersionNo;
		HttpCurl httpCurl_;
		JsonCurl jsonCurl_;
		httpCurl_.runValueCurl(&jsonCurl_);
		httpCurl_.runInit(format_.str());
		httpCurl_.runTimeout(mTimeout);
		if (!httpCurl_.runPerform()) {
			return false;
		}
		jsonCurl_.runClass<AutoupEngine *>(this, updateName());
		
		if ( mVersionNo != mUpdateNo ) {
			return false;
		}
		List<AutoupItemPtr>::iterator it = mAutoupItems.begin();
		for ( ; it != mAutoupItems.end(); ++it ) {
			AutoupItemPtr& autoupItem_ = (*it);
			if ( !this->runAutoItem(autoupItem_) ) {
				return false;
			}
		}
		return true;
	}
	
	bool AutoupEngine::runAutoItem(AutoupItemPtr& nAutoupItem)
	{
		const char * updateUrl_= nAutoupItem->getDownloadUrl();
		const char * packetName_= nAutoupItem->getPacketName();
		
		HttpCurl httpCurl_;
		FileCurl fileCurl_;
		httpCurl_.runValueCurl(&fileCurl_);
		httpCurl_.runInit(updateUrl_);
		httpCurl_.runTimeout(mTimeout);
		if (!httpCurl_.runPerform()) {
			return false;
		}
		return true;
	}
	
	const char * AutoupEngine::streamName()
	{
		return "autoupEngine";
	}
	
	const char * AutoupEngine::streamUrl()
	{
		return "autoupEngine.json";
	}
	
	const char * AutoupEngine::updateName()
	{
		return "updateEngine";
	}
	
	AutoupEngine::AutoupEngine()
		: mAgentName("")
		, mUpdateUrl("")
		, mVersionNo(0)
		, mTimeout(10)
		, mUpdateNo(0)
	{
		mAutoupItems.clear();
	}
	
	AutoupEngine::~AutoupEngine()
	{
		mAutoupItems.clear();
		
		mAgentName = "";
		mUpdateUrl = "";
		mVersionNo = 0;
		mTimeout = 10;
		mUpdateNo = 0;
	}
	
}
