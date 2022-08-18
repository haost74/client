cmake_minimum_required(VERSION 3.2...3.5)
project(app LANGUAGES CXX)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)


# ------------------------------------------------------

# BOOST_INCLUDEDIR C:\SDKs\boost_1_58_0\
# BOOST_LIBRARYDIR C:\SDKs\boost_1_58_0\lib64-msvc-12.0
# BOOST_ROOT C:\SDKs\boost_1_58_0\boost

# C:\boost\boost_1_80_0

# BOOST_LIBRARYDIR C:/local/boost_1_73_0/lib64-msvc-14.2

# C:\boost\boost_1_80_0

# The following directory should be added to linker library paths:

#     C:\boost\boost_1_80_0\stage\lib

set (Boost_DETAILED_FAILURE_MSG ON)
set (Boost_THREADAPI win32)
set (BOOST_ROOT "C:/boost/boost_1_80_0")
set (Boost_LIBRARY_DIR  "C:/boost/boost_1_80_0/stage/lib")
set (Boost_COMPILER "-vc")
set (Boost_USE_STATIC_RUNTIME ON)  
set (Boost_DEBUG ON)  #<---------- Real life saver
set (Boost_USE_STATIC_RUNTIME ON)  
set (Boost_DEBUG ON)

set(Boost_USE_STATIC_LIBS ON)

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

if (Boost_FOUND)
    include_directories (SYSTEM ${Boost_INCLUDE_DIR}) # подключаем заголовочные файлы
    
endif ()

# -------------------------------------------------------

find_package(Threads)

# -------------------------------------------------------

add_subdirectory(lib/client)


# -------------------------------------------------------

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

set(JSONCPP_WITH_TESTS OFF CACHE BOOL "")
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/json/jsoncpp/ EXCLUDE_FROM_ALL)
get_target_property(JSON_INC_PATH jsoncpp_lib INTERFACE_INCLUDE_DIRECTORIES)
include_directories(${JSON_INC_PATH})

set(JSONCPP_INCLUDE_DIRS
	"${CMAKE_CURRENT_SOURCE_DIR}/lib/json/jsoncpp/include")
set(JSONCPP_LIBRARIES jsoncpp_lib)

# -------------------------------------------------------

# set (CLIENT_LIBRARIES lib/client/Debug/client) 
# link_directories(build/lib/client/Debug/)

set (CLIENT_LIBRARIES client)

add_executable(app main.cpp)
target_link_libraries(app 
	${JSONCPP_LIBRARIES} 
	${CLIENT_LIBRARIES}
	${Boost_LIBRARY_DIR}
	Boost::boost
	Threads::Threads)