#include "Include.hpp"

#include "Preinit.hpp"

void runPreinit()
{
	LogEngine::instance();

	TimeEngine& timeEngine_ = TimeEngine::instance();
	timeEngine_.runPreinit();

	UrlMgr& urlMgr_ = UrlMgr::instance();
	urlMgr_.runPreinit();

	DbEngine& dbEngine_ = DbEngine::instance();
	dbEngine_.runPreinit();
	
	IoService& ioService_ = IoService::instance();
	ioService_.runPreinit();

	TcpServer& tcpServer_ = TcpServer::instance();
	tcpServer_.runPreinit();
	
	SessionMgr::instance();

	HandleMgr& handleMgr_ = HandleMgr::instance();
	handleMgr_.runPreinit();

	TaskMgr& taskMgr_ = TaskMgr::instance();
	taskMgr_.runPreinit();

	PacketMgr::instance();
}
