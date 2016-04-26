#include "Engine.hpp"

int main( int argc, char * argv[] )
{
	LogEngine& logEngine_ 
		= LogEngine::instance();
	ConfigEngine& configEngine_ 
		= ConfigEngine::instance();
	
	AutoupEngine autoupEngine_;
	autoupEngine_.runAutoup();
	
	return 0;
}
