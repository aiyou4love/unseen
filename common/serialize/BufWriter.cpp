#include "../../Include.hpp"

namespace cc {
	
	void BufWriter::runNumber(string& nValue, const char * nName)
	{
		int16_t count_ = int16_t(nValue.length());
		this->runNumber(count_, nName);
		if ((mLength + sizeof(int16_t)+ nValue.length()) > PACKETSIZE) {
			LOGERROR("[%s]%s", __METHOD__, nName);
			return;
		}
		memcpy((mBuffer + mLength + sizeof(int16_t)), &nValue[0], nValue.length());
		mLength += (int16_t(nValue.length()));
	}
	
	void BufWriter::runTime(int64_t& nValue, const char * nName)
	{
		this->runNumber(nValue, nName);
	}
	
	void BufWriter::runTimes(int64_t& nValue, const char * nName)
	{
		LOGERROR("[%s]%s", __METHOD__, nName);
	}
	
	void BufWriter::runBuffer(char * nValue, int16_t nLength)
	{
		if ((mLength + sizeof(int16_t)+nLength) > PACKETSIZE) {
			LOGERROR("[%s]%d", __METHOD__, nLength);
			return;
		}
		memcpy((mBuffer + mLength + sizeof(int16_t)), nValue, nLength);
		mLength += nLength;
	}
	
	void BufWriter::runPush(const char * nName)
	{
		LOGERROR("[%s]%s", __METHOD__, nName);
	}
	
	void BufWriter::runPop(const char * nName)
	{
		LOGERROR("[%s]%s", __METHOD__, nName);
	}
	
	void BufWriter::selectStream(const char * nValue)
	{
	}
	
	int16_t BufWriter::getSize()
	{
		return (mLength + sizeof(int16_t));
	}
	
	char * BufWriter::getValue()
	{
		return mBuffer;
	}
	
	void BufWriter::runClear()
	{
		memset(mBuffer, 0, sizeof(mBuffer));
		mLength = 0;
	}
	
	void BufWriter::runEnd()
	{
		memcpy(mBuffer, &mLength, sizeof(int16_t));
	}
	
	bool BufWriter::isText()
	{
		return false;
	}
	
	BufWriter::BufWriter()
	{
	}
	
	BufWriter::~BufWriter()
	{
	}
	
}
