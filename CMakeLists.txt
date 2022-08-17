cmake_minimum_required(VERSION 3.2...3.5)
project(app LANGUAGES CXX)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

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
	Threads::Threads)