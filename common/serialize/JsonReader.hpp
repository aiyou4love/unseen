#pragma once

namespace std {
	
	class JsonReader : noncopyable
	{
	public:
		template <typename T>
		void runNumber(T& nValue, const char * nName)
		{
			Value& value_ = (*mValue)[nName];
			nValue = value_.Get<T>();
		}
		
		template <typename T>
		void runNumbers(T& nValue, const char * nName)
		{
			LOGERROR("[%s]%s", __METHOD__, nName);
		}
		
		void runNumber(string& nValue, const char * nName);
		void runNumbers(string& nValue, const char * nName);
		
		void runTime(int64_t& nValue, const char * nName);
		void runTimes(int64_t& nValue, const char * nName);
		
		void runPush(const char * nName);
		bool readChild(const char * nName);
		bool runNext(const char * nName);
		void runPop(const char * nName);
		
		void pushClass(const char * nName);
		void popClass(const char * nName);
		
		void selectStream(const char * nValue);
		
		void loadFile(const char * nPath);
		
		void stringValue(const char * nValue);
		
		bool isText();
		
		JsonReader();
		~JsonReader();
		
	private:
		stack<rapidjson::Value *> mValues;
		rapidjson::Document mDocument;
		rapidjson::Value * mValue;
		int16_t mIndex;
		int16_t mMax;
	};
	
}
