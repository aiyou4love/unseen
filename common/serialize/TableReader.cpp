#include "../../Include.hpp"

namespace cc {
	
	void TableReader::runNumber(string& nValue, const char * nName)
	{
		Value & value_ = (*mValue)[nName];
		nValue = value_.GetString();
	}
	
	void TableReader::runNumbers(string& nValue, const char * nName)
	{
		LOGERROR("[%s]%s", __METHOD__, nName);
	}
	
	void TableReader::runTime(int64_t& nValue, const char * nName)
	{
		string value_ = "";
		this->runNumber(value_, nName);
		LocalTime localTime_(value_);
		nValue = localTime_.numberTime();
	}
	
	void TableReader::runTimes(int64_t& nValue, const char * nName)
	{
		LOGERROR("[%s]%s", __METHOD__, nName);
	}
	
	void TableReader::runBuffer(char *& nValue, int16_t nLength)
	{
		LOGERROR("[%s]%d", __METHOD__, nLength);
	}
	
	void TableReader::runPush(const char * nName)
	{
		mValues.push(mValue);
		mValue = &((*mValue)[nName]);
	}
	
	bool TableReader::runChild(const char * nName)
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
	
	bool TableReader::runNext(const char * nName)
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
	
	void TableReader::runPop(const char * nName)
	{
		mValue = mValues.top();
		mValues.pop();
	}
	
	void TableReader::pushClass(const char * nName)
	{
	}
	
	void TableReader::popClass(const char * nName)
	{
	}
	
	void TableReader::selectStream(const char * nValue)
	{
		mValue = &mDocument;
	}
	
	void TableReader::loadFile(const char * nPath)
	{
		if (nullptr == nPath) return;
		FILE * fHandle_ = ::fopen(nPath, "r");
		if (nullptr == fHandle_) return;
		rapidjson::FileStream fileStream_(fHandle_);
		mDocument.ParseStream<0>(fileStream_);
		::fclose(fHandle_);
	}
	
	void TableReader::stringValue(const char * nValue)
	{
		mDocument.Parse<0>(nValue);
	}
	
	bool TableReader::isText()
	{
		return true;
	}
	
	TableReader::TableReader()
		: mValue (nullptr)
		, mIndex (0)
		, mMax (0)
	{
	}
	
	TableReader::~TableReader()
	{
		mValue = nullptr;
		mIndex = 0;
		mMax = 0;
	}
	
}
