#pragma once

namespace std {
	
	extern int32_t __hash32(const char * nValue, int32_t nLength);
	
	extern int32_t __stringid(const char * nValue);
	
	extern int32_t __formatclass(const char * nValue, string& nName);
	
	extern int32_t __formatclassid(const char * nValue);
	
	template<typename __t>
	int32_t __classid()
	{
		const char * className_ = typeid(__t).name();
		return __formatclassid(className_);
	}
	
	template<typename __t>
	int32_t __classinfo(string& nClassName)
	{
		const char * className_ = typeid(__t).name();
		return __formatclass(className_, nClassName);
	}
	
}
