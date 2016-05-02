#include "../../Include.hpp"

namespace cc {
	
	bool AutoupItem::runUncompress()
	{
		zip_file file(argv[1]);
		file.extractall("c:\\first");
	}
	
	bool AutoupItem::runDownload(int16_t nTimeout)
	{
		string updateUrl_ = mDownloadUrl + mPacketName;
		
		HttpCurl httpCurl_;
		FileCurl fileCurl_;
		httpCurl_.runValueCurl(&fileCurl_);
		httpCurl_.runInit(updateUrl_);
		httpCurl_.runTimeout(nTimeout);
		if (!httpCurl_.runPerform()) {
			return false;
		}
		return true;
	}
	
	bool AutoupItem::isUpdate()
	{
		UserDefault& userDefault_ = UserDefault::instance();
		int16_t updateNo_ = userDefault_.getInt16(mUpdateName);
		if (updateNo_ == mUpdateNo) {
			return false;
		}
		return true;
	}
	
	AutoupItem::AutoupItem()
		: mDownloadUrl("")
		, mPacketName("")
		, mUpdateName("")
		, mUpdateNo(0)
	{
	}
	
	AutoupItem::~AutoupItem()
	{		
		mDownloadUrl = "";
		mPacketName = "";
		mUpdateName = "";
		mUpdateNo = 0;
	}
	
}
