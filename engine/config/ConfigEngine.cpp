#include "../../Include.hpp"

namespace std {
		
	ConfigEngine& ConfigEngine::instance()
	{
		return mConfigEngine;
	}
	
	ConfigEngine::ConfigEngine()
	{
	}
	
	ConfigEngine::~ConfigEngine()
	{
	}
	ConfigEngine ConfigEngine::mConfigEngine;
	
}
