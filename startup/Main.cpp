#include "../Include.hpp"
#include "Preinit.hpp"

int main( int argc, char * argv[] )
{
	using namespace std;
	
	runPreinit();
	
	LifeCycle& lifeCycle_ =
		LifeCycle::instance();
		
	lifeCycle_.runLuaApi();
	lifeCycle_.runConfig();
	
	lifeCycle_.runInitDb();
	lifeCycle_.runInitTb();
	
	lifeCycle_.loadBegin();
	lifeCycle_.loading();
	lifeCycle_.loadEnd();
	
	lifeCycle_.initBegin();
	lifeCycle_.initing();
	lifeCycle_.initEnd();
	
	lifeCycle_.startBegin();
	lifeCycle_.starting();
	lifeCycle_.startEnd();
	
	lifeCycle_.running();
	
	lifeCycle_.stopBegin();
	lifeCycle_.stoping();
	lifeCycle_.stopEnd();
	
	lifeCycle_.runClear();
	
	return 0;
}
