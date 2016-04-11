#pragma once

namespace std {
	
	template<typename __t1, typename __t2>
	void stringSplit(const char * nValue, __t1& nResult, const char * nSplit)
	{
		size_t size_ = strlen(nValue);
		size_t start_ = 0, end_ = 0;
		while (start_ < size_) {
			end_ = strcspn(nValue + start_, nSplit);
			string value_(nValue + start_, end_);
			__t2 t_ = __convert<const char *, __t2>(value_.c_str());
			nResult.push_back(t_);
			start_ += (end_ + 1);
		}
	}
	
	template<typename __t1>
	void stringCrcSplit(const char * nValue, __t1& nResult, const char * nSplit)
	{
		size_t size_ = strlen(mValue);
		size_t start_ = 0, end_ = 0;
		while (start_ < size_) {
			end_ = strcspn(mValue + start_, nSplit);
			string value_(mValue + start_, end_);
			int32_t crcValue_ = __stringid(value_.c_str());
			nResult.push_back(crcValue_);
			start_ += (end_ + 1);
		}
	}
	
	template<typename __t1, typename __t2>
	string stringCombine(__t1& nValue, const char * nCombine)
	{
		bool first_ = true; string result_("");
		auto it = nValue.begin();
		for ( ; it != nValue.end(); ++it ) {
			__t2 value_ = (*it);
			if ( first_ ) {
				result_ += __convert<__t2, string>(value_);
				first_ = false;
			} else {
				result_ += nCombine;
				result_ += __convert<__t2, string>(value_);
			}
		}
		return result_;
	}
	
	extern string stringTrim(const string& nValue, const string& nTrim);
	extern string stringBackslant(const string& nValue);
	
}
