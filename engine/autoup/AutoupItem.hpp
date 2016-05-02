#pragma once

namespace cc {
	
	class AutoupItem : noncopyable
	{
	public:
		bool runUncompress();
		bool runDownload();
		bool isUpdate();
		
		const char * getDownloadUrl();
		const char * getPacketName();
		const char * getUpdateName();
		int16_t getUpdateNo();
		
		template<class T>
		void serialize(T nSerialize, int8_t nCount)
		{
			nSerialize->serialize(mUpdateNo, "mUpdateNo");
			nSerialize->serialize(mUpdateName, "mUpdateName");
			nSerialize->serialize(mPacketName, "mPacketName");
			nSerialize->serialize(mDownloadUrl, "mDownloadUrl");
		}
		
		AutoupItem();
		~AutoupItem();
		
	private:
		string mDownloadUrl;
		string mPacketName;
		string mUpdateName;
		int16_t mUpdateNo;
	};
	typedef shared_ptr<AutoupItem> AutoupItemPtr;
	
}
