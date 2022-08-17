# add_subdirectory(../json/jsoncpp/ EXCLUDE_FROM_ALL)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(client client.cpp client.hpp)

#target_link_libraries(client ../json/jsoncpp)