#include "../../Include.hpp"

#include <ctype.h>

#ifndef __WINDOW__
#include <cxxabi.h>
#include <stdlib.h>
#endif

namespace std {
	
	int32_t crc32Value(const char * nValue, int32_t nLength)
	{
		crc_32_type crc32_;
		crc32_.process_bytes(nValue, nLength);
		return crc32_();
	}
	
	int32_t crc32String(const char * nValue)
	{
		return crc32Value(nValue, (int32_t)(strlen(nValue)));
	}
	
	void formatClass(const char * nValue, SclassInfo& nClassInfo)
	{
	#ifdef __WINDOW__
		nClassInfo.mClassId = crc32String(nValue + 6);
		nClassInfo.mClassName = nValue + 6;
	#else
		char * realName_ = abi::__cxa_demangle(nValue, 0, 0, 0);
		nClassInfo.mClassId = crc32String(realName_);
		nClassInfo.mClassName = realName_;
		::free(realName_);
	#endif
	}
	
	int32_t formatClassId(const char * nValue)
	{
		int32_t result_ = 0;
	#ifdef __WINDOW__
		result_ = crc32String(nValue + 6);
	#else
		char * realName_ = abi::__cxa_demangle(nValue, 0, 0, 0);
		result_ = crc32String(realName_);
		::free(realName_);
	#endif
		return result_;
	}

}
