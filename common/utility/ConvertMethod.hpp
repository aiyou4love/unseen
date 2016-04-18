#pragma once

namespace std {
	
	extern int32_t strToInt32(const char * nValue);
	extern string int32ToStr(int32_t nValue);
	extern int64_t strToInt64(const char * nValue);
	extern string int64ToStr(int64_t nValue);
	extern double strToDouble(const char * nValue);
	extern string doubleToStr(double nValue);
	
	namespace convert_namespace {
		
		template<typename __t1, typename __t2>
		struct Convert
		{
			__t2 operator () (__t1 nValue) const
			{
				return static_cast<__t1>(nValue);
			}
		};
		
		template<typename __t1>
		struct Convert<__t1, string>
		{
			string operator () (__t1 nValue) const
			{
				return int32ToStr(nValue);
			}
		};
		
		template<>
		struct Convert<int64_t, string>
		{
			string operator () (int64_t nValue) const;
		};
		
		template<>
		struct Convert<float, bool>
		{
			bool operator () (float nValue) const;
		};
		
		template<>
		struct Convert<float, string>
		{
			string operator () (float nValue) const;
		};
		
		template<>
		struct Convert<double, bool>
		{
			bool operator () (double nValue) const;
		};
		
		template<>
		struct Convert<double, string>
		{
			string operator () (double nValue) const;
		};
		
		template<typename __t2>
		struct Convert<const char *, __t2>
		{
			__t2 operator () (const char * nValue) const
			{
				int32_t value_ = strToInt32(nValue);
				return static_cast<__t2>(value_);
			}
		};

		template<>
		struct Convert<const char *, bool>
		{
			bool operator () (const char * nValue) const;
		};
		
		template<>
		struct Convert<const char *, int64_t>
		{
			int64_t operator () (const char * nValue) const;
		};
		
		template<>
		struct Convert<const char *, float>
		{
			float operator () (const char * nValue) const;
		};
		
		template<>
		struct Convert<const char *, double>
		{
			double operator () (const char * nValue) const;
		};
		
		template<>
		struct Convert<const char *, string>
		{
			string operator () (const char * nValue) const;
		};
		
	}
	
	template<typename __t1, typename __t2>
	__t2 __convert(__t1 nValue)
	{
		return convert_namespace::Convert<__t1, __t2>()(nValue);
	}
	
}
