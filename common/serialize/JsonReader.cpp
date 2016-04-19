#include "../../Include.hpp"

namespace std {
	
	void JsonReader::runNumber(string& nValue, const char * nName)
	{
		Value & value_ = (*mValue)[nName];
		nValue = value_.GetString();
	}
	
	void JsonReader::runNumbers(string& nValue, const char * nName)
	{
		nValue = mValue->GetString();
	}
	
	void JsonReader::runTime(int64_t& nValue, const char * nName)
	{
		string value_ = "";
		this->runNumber(value_, nName);
		LocalTime localTime_(value_);
		nValue = localTime_.numberTime();
	}
	
	void JsonReader::runTimes(int64_t& nValue, const char * nName)
	{
		string value_ = "";
		this->runNumbers(value_, nName);
		LocalTime localTime_(value_);
		nValue = localTime_.numberTime();
	}
	
	void JsonReader::runBuffer(char *& nValue, int16_t nLength)
	{
		LOGERROR("[%s]%d", __METHOD__, nLength);
	}
	
	void JsonReader::runPush(const char * nName)
	{
		mValues.push(mValue);
		mValue = &((*mValue)[nName]);
	}
	
	bool JsonReader::runChild(const char * nName)
	{
		if ( mValue->Size() <= 0){
			return false;
		}
		mIndex = 0;
		mMax = mValue->Size();
		mValues.push(mValue);
		mValue = &((*mValue)[0]);
		return true;
	}
	
	bool JsonReader::runNext(const char * nName)
	{
		if ( mIndex >= mMax){
			mValue = mValues.top();
			mValues.pop();
			return false;
		}
		mIndex++;
		rapidjson::Value * value_ = mValues.top();
		mValue = &((*value_)[mIndex]);
		return true;
	}
	
	void JsonReader::runPop(const char * nName)
	{
		mValue = mValues.top();
		mValues.pop();
	}
	
	void JsonReader::pushClass(const char * nName)
	{
		mValues.push(mValue);
		mValue = &((*mValue)[nName]);
	}
	
	void JsonReader::popClass(const char * nName)
	{
		mValue = mValues.top();
		mValues.pop();
	}
	
	void JsonReader::selectStream(const char * nValue)
	{
		mValue = &mDocument;
	}
	
	void JsonReader::loadFile(const char * nPath)
	{
		if (nullptr == nPath) return;
		FILE * fHandle_ = ::fopen(nPath, "r");
		if (nullptr == fHandle_) return;
		rapidjson::FileStream fileStream_(fHandle_);
		mDocument.ParseStream<0>(fileStream_);
		::fclose(fHandle_);
	}
	
	void JsonReader::stringValue(const char * nValue)
	{
		mDocument.Parse<0>(nValue);
	}
	
	bool JsonReader::isText()
	{
		return true;
	}
	
	JsonReader::JsonReader()
		: mValue (nullptr)
		, mIndex (0)
		, mMax (0)
	{
	}
	
	JsonReader::~JsonReader()
	{
		mValue = nullptr;
		mIndex = 0;
		mMax = 0;
	}
	
}
