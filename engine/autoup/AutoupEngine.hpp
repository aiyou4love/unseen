#pragma once

namespace cc {
	
	class AutoupEngine : noncopyable
	{
	public:
		bool runAutoup();
		
		template<class __t>
		void headSerialize(__t& nSerialize, const char * nName)
		{
			if ( 0 == strcmp(streamName(), nName) ) {
				nSerialize.runNumber(mVersionNo, "versionNo");
				nSerialize.runNumber(mAgentName, "agentName");
				nSerialize.runNumber(mUpdateUrl, "updateUrl");
				nSerialize.runNumber(mTimeout, "timeout");
			} else if ( 0 == strcmp(updateName(), nName) ) {
				nSerialize.runStreamPtrs(mAutoupItems, "mUpdateItems", "updateItem");
				nSerialize.runNumber(mUpdateNo, "mVersionNo");
			} else {
				LOGERROR("[%s]%s", __METHOD__, nName);
			}
		}
		const char * streamName();
		const char * streamUrl();
		
		const char * updateName();
		
		AutoupEngine();
		~AutoupEngine();
		
	private:
		bool runAutoItem(AutoupItemPtr& nAutoupItem);
		
	private:
		List<AutoupItemPtr> mAutoupItems;
		int16_t mUpdateNo;
		
		int16_t mVersionNo;
		string mAgentName;
		string mUpdateUrl;
		int16_t mTimeout;
	};
	
}
