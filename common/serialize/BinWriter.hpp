#pragma once

namespace std {
	
	class BinWriter : noncopyable
	{
	public:
		template <typename __t0>
		void runNumber(__t0& nValue, const char * nName)
		{
			mStream.write((char *)(&nValue), sizeof(__t0));
		}
		
		template <typename __t0>
		void runNumbers(__t0& nValue, const char * nName)
		{
		}
		
		void runNumber(string& nValue, const char * nName);
		void runNumbers(string& nValue, const char * nName);
		
		void runTime(int64_t& nValue, const char * nName);
		void runTimes(int64_t& nValue, const char * nName);
		
		void runPush(const char * nName);
		void runPop(const char * nName);
		
		void selectStream(const char * nValue);
		
		void openFile(const char * nPath);
		void closeFile();
		
		bool isText();
		
		BinWriter();
		~BinWriter();
		
	private:
		fstream mStream;
	};
	
}
