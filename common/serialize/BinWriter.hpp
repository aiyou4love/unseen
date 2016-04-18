#pragma once

namespace std {
	
	class BinWriter : noncopyable
	{
	public:
		template <typename T>
		void runNumber(T& nValue, const char * nName)
		{
			mStream.write((char *)(&nValue), sizeof(T));
		}
		
		template <typename T>
		void runNumbers(T& nValue, const char * nName)
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
