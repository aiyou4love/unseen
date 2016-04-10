#include "../../Include.hpp"

namespace std {
	
	void BinWriter::runNumber(string& nValue, const char * nName)
	{
		int16_t count_ = (int16_t)(nValue.size());
		this->runNumber(count_, nName);
		mStream.write((char *)(&nValue[0]), count_);
	}
	
	void BinWriter::runNumbers(string& nValue, const char * nName)
	{
		this->runNumber(nValue, nName);
	}
	
	void BinWriter::runTime(int64_t& nValue, const char * nName)
	{
		this->runNumber(nValue, nName);
	}
	
	void BinWriter::runTimes(int64_t& nValue, const char * nName)
	{
		this->runNumber(nValue, nName);
	}
	
	void BinWriter::runPush(const char * nName)
	{
	}
	
	void BinWriter::runPop(const char * nName)
	{
	}
	
	void BinWriter::selectStream(const char * nValue)
	{
	}
	
	void BinWriter::openFile(const char * nPath)
	{
		mStream.open(nPath, ios::binary | ios::out);
	}
	
	void BinWriter::closeFile()
	{
		mStream.close();
	}
	
	bool BinWriter::isText()
	{
		return false;
	}
	
	BinWriter::BinWriter()
	{
	}
	
	BinWriter::~BinWriter()
	{
	}
	
}
