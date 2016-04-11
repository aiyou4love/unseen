#include "../../Include.hpp"

#include <ctype.h>

#ifndef __WINDOW__
#include <cxxabi.h>
#include <stdlib.h>
#endif

namespace std {
	
	int32_t __hash32(const char * nValue, int32_t nLength)
	{
		crc_32_type crc32_;
		crc32_.process_bytes(nValue, nLength);
		return crc32_();
	}
	
	int32_t __stringid(const char * nValue)
	{
		return __hash32(nValue, (int32_t)(strlen(nValue)));
	}
	
	int32_t __formatclass(const char * nValue, string& nName)
	{
		int32_t result_ = 0;
	#ifdef __WINDOW__
		nName = nValue + 6;
		result_ = __stringid(nValue + 6);
	#else
		char * realName_ = abi::__cxa_demangle(nValue, 0, 0, 0);
		result_ = __stringid(realName_);
		nName = realName_;
		::free(realName_);
	#endif
		return result_;
	}
	
	int32_t __formatclassid(const char * nValue)
	{
		int32_t result_ = 0;
	#ifdef __WINDOW__
		result_ = __stringid(nValue + 6);
	#else
		char * realName_ = abi::__cxa_demangle(nValue, 0, 0, 0);
		result_ = __stringid(realName_);
		::free(realName_);
	#endif
		return result_;
	}

}
