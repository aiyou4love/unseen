#include "../../Include.hpp"

namespace std {
	
	void JsonWriter::runNumber(string& nValue, const char * nName)
	{
		mValue->AddMember(nName, nValue, mDocument.GetAllocator());
	}
	
	void JsonWriter::runNumbers(string& nValue, const char * nName)
	{
		mValue->PushBack(nValue, mDocument.GetAllocator());
	}
	
	void JsonWriter::runTime(int64_t& nValue, const char * nName)
	{
		LocalTime localTime_(nValue);
		string value_ = localTime_.stringTime();
		this->runNumber(value_, nName);
	}
	
	void JsonWriter::runTimes(int64_t& nValue, const char * nName)
	{
		LocalTime localTime_(nValue);
		string value_ = localTime_.stringTime();
		this->runNumbers(value_, nName);
	}
	
	void JsonWriter::runBuffer(char *& nValue, int16_t nLength)
	{
		LOGERROR("[%s]%d", __METHOD__, nLength);
	}
	
	void JsonWriter::runPush(const char * nName)
	{
		mValues.push(mValue);
		Value value_(kObjectType);
		rapidjson::Value& value0_ = mValue->AddMember(nName, value_, mDocument.GetAllocator());
		mValue = &value0_;
	}
	
	void JsonWriter::runPop(const char * nName)
	{
		mValue = mValues.top();
		mValues.pop();
	}
	
	void JsonWriter::selectStream(const char * nValue)
	{
		mValue = &mDocument;
	}
	
	void JsonWriter::saveFile(const char * nPath)
	{
		rapidjson::StringBuffer stringBuffer_;
		rapidjson::Writer<rapidjson::StringBuffer> writer_(stringBuffer_);
		mDocument.Accept(writer_);
		FILE * fHandle_ = fopen(nPath, "wb");
		if (nullptr == fHandle_) return;
		fputs(stringBuffer_.GetString(), fHandle_);
		fclose(fHandle_);
	}
	
	string JsonWriter::stringValue()
	{
		rapidjson::StringBuffer stringBuffer_;
		rapidjson::Writer<rapidjson::StringBuffer> writer_(stringBuffer_);
		mDocument.Accept(writer_);
		return stringBuffer_.GetString();
	}
	
	bool JsonWriter::isText()
	{
		return true;
	}
	
	JsonWriter::JsonWriter()
		: mDocument (kObjectType)
		, mValue (nullptr)
	{
	}
	
	JsonWriter::~JsonWriter()
	{
		mValue = nullptr;
	}
	
}
