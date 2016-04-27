#pragma once

namespace cc {
	
	class AutoupEngine : noncopyable
	{
	public:
		bool runAutoup();
		
		template<class __t>
		void headSerialize(__t& nSerialize)
		{
			nSerialize.runNumber(mVersionNo, "versionNo");
			nSerialize.runNumber(mAgentName, "agentName");
			nSerialize.runNumber(mUpdateUrl, "updateUrl");
			nSerialize.runNumber(mTimeout, "timeout");
		}
		const char * streamName();
		const char * streamUrl();
		
		AutoupEngine();
		~AutoupEngine();
		
	private:
		size_t curlWriteData(void * nPtr, size_t nSize, size_t nMemb, void * nStream);
		
	private:
		int16_t mVersionNo;
		string mAgentName;
		string mUpdateUrl;
		int16_t mTimeout;
	};
	
}
