#pragma once

namespace cc {
	
	namespace default_value {
		
		template<typename T>
		struct DefaultValue
		{
			T operator () () const
			{
				return 0;
			}
		};
		
		template<>
		struct DefaultValue<bool>
		{
			bool operator () () const
			{
				return false;
			}
		};
		
		template<>
		struct DefaultValue<float>
		{
			float operator () () const
			{
				return 0.f;
			}
		};
		
		template<>
		struct DefaultValue<double>
		{
			double operator () () const
			{
				return 0.;
			}
		};
		
		template<>
		struct DefaultValue<const char *>
		{
			const char * operator () () const
			{
				return "";
			}
		};
		
		template<>
		struct DefaultValue<string>
		{
			const char * operator () () const
			{
				return "";
			}
		};
		
		template<>
		struct DefaultValue<shared_ptr<T> >
		{
			T * operator () () const
			{
				return nullptr;
			}
		};
		
	}
	
	template<typename T>
	T defaultValue()
	{
		return default_value::DefaultValue<T>()();
	}
	
}
