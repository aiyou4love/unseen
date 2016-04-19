#pragma once

namespace std {
	
	extern int32_t crc32Value(const char * nValue, int32_t nLength);
	
	extern int32_t crc32String(const char * nValue);
	
	struct SclassInfo
	{
		int32_t mClassId;
		string mClassName;
	};
	
	extern void formatClass(const char * nValue, SclassInfo& nName);
	
	extern int32_t formatClassId(const char * nValue);
	
	template<typename T>
	void classInfo(SclassInfo& nClassInfo)
	{
		const char * className_ = typeid(T).name();
		formatClass(className_, nClassInfo);
	}
	
	template<typename T>
	int32_t crc32Class()
	{
		const char * className_ = typeid(T).name();
		return formatClassId(className_);
	}
	
}
