#include "../../Include.hpp"

namespace std {
	
	int32_t strToInt32(const char * nValue)
	{
        return strtol(nValue, nullptr, 0);
	}
	
	string int32ToStr(int32_t nValue)
	{
		char result_[30];
		memset(result_, 0, sizeof(result_));
		sprintf(result_, "%d", nValue);
		return result_;
	}
	
	int64_t strToInt64(const char * nValue)
	{
        return strtoll(nValue, nullptr, 0);
	}
	
	string int64ToStr(int64_t nValue)
	{
		char result_[30];
		memset(result_, 0, sizeof(result_));
		sprintf(result_, "%lld", nValue);
		return result_;
	}
	
	double strToDouble(const char * nValue)
	{
		return strtod(nValue, nullptr);
	}
	
	string doubleToStr(double nValue)
	{
		char result_[30];
		memset(result_, 0, sizeof(result_));
		sprintf(result_, "%f", nValue);
		return result_;
	}
	
	namespace convert_namespace {
		
		string ConvertValue<int64_t, string>::operator () (int64_t nValue) const
		{
			return int64ToStr(nValue);
		}
		
		bool ConvertValue<float, bool>::operator () (float nValue) const
		{
			return ( (0.001f > nValue) && (-0.001f < nValue) );
		}
		
		string ConvertValue<float, string>::operator () (float nValue) const
		{
			return doubleToStr(nValue);
		}
		
		bool ConvertValue<double, bool>::operator () (double nValue) const
		{
			return ((0.001 > nValue) && (-0.001 < nValue));
		}
		
		string ConvertValue<double, string>::operator () (double nValue) const
		{
			return doubleToStr(nValue);
		}
		
		bool ConvertValue<const char *, bool>::operator () (const char * nValue) const
		{
			int32_t value_ = strToInt32(nValue);
			return (1 == value_);
		}

		int64_t ConvertValue<const char *, int64_t>::operator () (const char * nValue) const
		{
			return strToInt64(nValue);
		}
		
		float ConvertValue<const char *, float>::operator () (const char * nValue) const
		{
			double value_ = strToDouble(nValue);
			return static_cast<float>(value_);
		}
		
		double ConvertValue<const char *, double>::operator () (const char * nValue) const
		{
			return strToDouble(nValue);
		}
		
		string ConvertValue<const char *, string>::operator () (const char * nValue) const
		{
			return nValue;
		}
		
	}
	
}
