#pragma once

namespace cc {
	
	size_t StringCurl::curlFun(void * nPtr, size_t nSize, size_t nMemb, void * nStream)
	{
		string * value_ = (string *)nStream;
		value_->append((const char *)nPtr);
		return (nSize * nMemb);
	}
	
	CurlFun_t StringCurl::getCurlFun()
	{
		return curlFun;
	}
	
	void * StringCurl::getCurlValue()
	{
		return (&mValue);
	}
	
	StringCurl::StringCurl()
		: mValue ("")
	{
	}
	
	StringCurl::~StringCurl()
	{
		mValue = "";
	}
	
}
