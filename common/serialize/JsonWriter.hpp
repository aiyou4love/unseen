#pragma once

namespace std {
	
	class JsonWriter : noncopyable
	{
	public:
		template <typename __t0>
		void runNumber(__t0& nValue, const char * nName)
		{
			mValue->AddMember(nName, nValue, mDocument.GetAllocator());
		}
		
		template <typename __t0>
		void runNumbers(__t0& nValue, const char * nName)
		{
			mValue->PushBack(nValue, mDocument.GetAllocator());
		}
		
		void runNumber(string& nValue, const char * nName);
		void runNumbers(string& nValue, const char * nName);
		
		void runTime(int64_t& nValue, const char * nName);
		void runTimes(int64_t& nValue, const char * nName);
		
		void runPush(const char * nName);
		void runPop(const char * nName);
		
		void selectStream(const char * nValue);
		
		void saveFile(const char * nPath);
		
		string stringValue();
		
		bool isText();
		
		JsonWriter();
		~JsonWriter();
		
	private:
		stack<rapidjson::Value *> mValues;
		rapidjson::Document mDocument;
		rapidjson::Value * mValue;
	};
	
}
