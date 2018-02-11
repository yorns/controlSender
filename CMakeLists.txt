cmake_minimum_required(VERSION 3.1.0)
project(controlSender VERSION 1.0 LANGUAGES CXX)

if(EXISTS /opt/boost/include/boost/function.hpp)
    set(BOOST_ROOT /opt/boost)
endif()

find_package(Boost 1.61.0 REQUIRED COMPONENTS system thread)
find_package(Threads REQUIRED)

find_library(snc_client_LIBRARIES NAMES snc_client)
find_path(snc_client_INCLUDE_DIRS NAMES snc/client.h)

set(CONTROLSENDER_SRC src/controlSender.cpp)

add_executable(controlSender ${CONTROLSENDER_SRC})

target_link_libraries(controlSender ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} ${snc_client_LIBRARIES})
target_include_directories(controlSender PRIVATE ${Boost_INCLUDE_DIRS} ${snc_client_INCLUDE_DIRS})
set_target_properties(controlSender PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
        )

