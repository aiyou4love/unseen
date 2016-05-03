##############################################################
cmake_minimum_required(VERSION 3.0)
##############################################################
project(${__PROJECT__})
string(TOUPPER ${__PROJECT__} __PROJNAME__)
add_definitions(-D__${__PROJNAME__}__)
##############################################################
include_directories( $ENV{BOOST_ROOT} )
##############################################################
set( ROOT_PATH ${CMAKE_SOURCE_DIR}/.. )
set( SRC_PATH ${ROOT_PATH} )
##############################################################
add_subdirectory(lua)
link_directories(${SRC_PATH}/lua)
add_subdirectory(url)
add_subdirectory(log)
##############################################################
set( MAIN_SRC ${SRC_PATH}/Main.cpp )
##############################################################
add_executable(${PROJECT_NAME} ${MAIN_SRC})
##############################################################
target_link_libraries(${PROJECT_NAME} 
	liblua lua51 liburl
	liblog)
##############################################################
资产目录	更新目录	下载目录	存储目录	运营商	版本号
assertPath	updatePath	downloadPath	savePath	agentName	versionNo
