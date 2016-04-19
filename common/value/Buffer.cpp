#include "../../Include.hpp"

namespace std {
	
	int16_t Buffer::getLength()
	{
		return mLength;
	}
	
	char * Buffer::getValue()
	{
		return mValue;
	}
	
	Buffer::Buffer()
		: mValue (nullptr)
		, mLength (0)
	{
	}
	
	Buffer::Buffer(char * nValue, int16_t nLength)
		: mValue (nValue)
		, mLength (nLength)
	{
		mValue = new char[nLength];
		memset(mValue, 0, nLength);
		memcpy(mValue, nValue, nLength);
	}
	
	Buffer::~Buffer()
	{
		if (nullptr != mValue) {
			delete mValue;
		}
		mValue = nullptr;
		mLength = 0;
	}
	
}
