#pragma once

#include <cstdint>
#include <cstdarg>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <iostream>
#include <stack>
#include <deque>
#include <random>
#include <thread>
#include <atomic>
#include <mutex>

#include <errno.h>
#include <errmsg.h>
#include <mysql.h>

#include <boost/smart_ptr.hpp>
#include <boost/utility.hpp>
#include <boost/crc.hpp>
#include <boost/signals2.hpp>

#pragma warning(push)
#pragma warning(disable:4819)
#include <boost/format.hpp>
#pragma warning(pop) 

#include <boost/bind.hpp>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using namespace std;
using namespace boost;

#define STD_SIGNAL signals2::signal

#if defined(_WIN32) ||  defined(_WIN64)
#define __WINDOW__
#endif

#ifdef __WINDOW__
#define __METHOD__ __FUNCTION__
#else
#define __METHOD__ __PRETTY_FUNCTION__
#endif

#ifdef APIEXPORT
#define __funapi __declspec(dllexport)
#else
#define __funapi
#endif

#define ORGANIZATION "unseen"

#define PACKETSIZE 8192

#include "common/log/LogEngine.hpp"

#include "common/utility/ConvertMethod.hpp"
#include "common/utility/StringMethod.hpp"
#include "common/utility/Default.hpp"
#include "common/utility/ClassMethod.hpp"
#include "common/utility/Instance.hpp"

#include "common/value/Buffer.hpp"
#include "common/value/Value.hpp"

#include "engine/lifecycle/LifeCycle.hpp"

#include "engine/handle/IContext.hpp"
#include "engine/handle/Handle.hpp"
#include "engine/handle/HandleMgr.hpp"

#include "engine/time/LocalTime.hpp"
#include "engine/time/TimeEngine.hpp"

#include "engine/url/core/EurlType.hpp"
#include "engine/url/core/UrlInfo.hpp"
#include "engine/url/core/UrlMgr.hpp"

#include "engine/url/io/rapidxml.hpp"
#include "engine/url/io/rapidxml_utils.hpp"
#include "engine/url/io/rapidxml_print.hpp"

using namespace rapidxml;

#include "engine/url/io/IoReader.hpp"
#include "engine/url/io/IoWriter.hpp"
#include "engine/url/io/XmlReader.hpp"
#include "engine/url/io/XmlWriter.hpp"
#include "engine/url/io/BinReader.hpp"
#include "engine/url/io/BinWriter.hpp"
#include "engine/url/io/BufReader.hpp"
#include "engine/url/io/BufWriter.hpp"

#include "engine/db/EdbError.hpp"
#include "engine/db/FdConfig.hpp"
#include "engine/db/TbConfig.hpp"
#include "engine/db/DbTables.hpp"
#include "engine/db/CmdConfig.hpp"
#include "engine/db/DbCommands.hpp"
#include "engine/db/DbConfig.hpp"
#include "engine/db/DbResult.hpp"
#include "engine/db/DbStatement.hpp"
#include "engine/db/DbPreResult.hpp"
#include "engine/db/DbConnection.hpp"
#include "engine/db/DataBase.hpp"
#include "engine/db/DbEngine.hpp"

#include "engine/io/IoService.hpp"

#include "engine/tcp/Message.hpp"
#include "engine/tcp/Packet.hpp"
#include "engine/tcp/PacketMgr.hpp"
#include "engine/tcp/Session.hpp"
#include "engine/tcp/SessionMgr.hpp"
#include "engine/tcp/TcpServer.hpp"
#include "engine/task/Task.hpp"
#include "engine/task/TaskMgr.hpp"
