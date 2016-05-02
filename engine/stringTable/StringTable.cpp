#include "../../Include.hpp"

namespace cc {
	
	StringTable& StringTable::instance()
	{
		return mStringTable;
	}
	
	StringTable::StringTable()
		: mAsset ("")
	{
	}
	
	StringTable::~StringTable()
	{
		mAsset = "";
	}
	
	StringTable StringTable::mStringTable;
	
}
