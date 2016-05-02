#include "../../Include.hpp"

namespace cc {
	
	ConfigEngine& ConfigEngine::instance()
	{
		return mConfigEngine;
	}
	
	ConfigEngine::ConfigEngine()
		: mAsset ("")
	{
	}
	
	ConfigEngine::~ConfigEngine()
	{
		mAsset = "";
	}
	
	ConfigEngine ConfigEngine::mConfigEngine;
	
}
