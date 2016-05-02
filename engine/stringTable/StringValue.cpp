#include "../../Include.hpp"

namespace cc {
	
	const char * StringValue::getValue()
	{
		return mValue.c_str();
	}
	
	const char * StringValue::getKey()
	{
		return mKey.c_str();
	}
	
	StringValue::StringValue()
		: mValue ("")
		, mKey ("")
	{
	}
	
	StringValue::~StringValue()
	{
		mValue = "";
		mKey = "";
	}
		
}
