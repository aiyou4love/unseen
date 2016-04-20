#include "Include.hpp"

#include "Preinit.hpp"

void runPreinit()
{
	LogEngine::instance();
	
	ConfigEngine::instance();
}
