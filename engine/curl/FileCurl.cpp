#pragma once

namespace cc {
	
	size_t FileCurl::curlFun(void * nPtr, size_t nSize, size_t nMemb, void * nStream)
	{
		FILE * handle_ = (FILE *)nStream;
		size_t write_ = fwrite(nPtr, nSize, nMemb, handle_);
		return write_;
	}
	
	CurlFun_t FileCurl::getCurlFun()
	{
		return curlFun;
	}
	
	void * FileCurl::getCurlValue()
	{
		return mHandle;
	}
	
	FileCurl::FileCurl()
		: mHandle (nullptr)
	{
	}
	
	FileCurl::~FileCurl()
	{
		mHandle = nullptr;
	}
	
}
