#include "../../Include.hpp"

namespace std {
	
	void BinReader::runNumber(string& nValue, const char * nName)
	{
		int16_t count_ = 0;
		this->runNumber<int16_t>(count_, nName); 
		nValue.resize(count_);
		mStream.read((char *)(&nValue[0]), count_);
	}
	
	void BinReader::runNumbers(string& nValue, const char * nName)
	{
		this->runNumber(nValue, nName);
	}
	
	void BinReader::runTime(int64_t& nValue, const char * nName)
	{
		this->runNumber(nValue, nName);
	}
	
	void BinReader::runTimes(int64_t& nValue, const char * nName)
	{
		this->runNumber(nValue, nName);
	}
	
	void BinReader::runPush(const char * nName)
	{
	}
	
	bool BinReader::runChild(const char * nName)
	{
		return false;
	}
	
	bool BinReader::runNext(const char * nName)
	{
		return false;
	}
	
	void BinReader::runPop(const char * nName)
	{
	}
	
	void BinReader::pushClass(const char * nName)
	{
	}
	
	void BinReader::popClass(const char * nName)
	{
	}
	
	void BinReader::selectStream(const char * nValue)
	{
	}
	
	void BinReader::openFile(const char * nPath)
	{
		mStream.open(nPath, ios::binary | ios::in);
	}
	
	void BinReader::closeFile()
	{
		mStream.close();
	}
	
	bool BinReader::isText()
	{
		return false;
	}
	
	BinReader::BinReader()
	{
	}
	
	BinReader::~BinReader()
	{
	}
	
}
