cmake_minimum_required(VERSION 3.13.0)
project(libJackWrap VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS jackwrap.hpp)
set(SOURCES jackwrap.cpp)

add_library(JackWrap SHARED ${SOURCES} ${HEADERS})
set_target_properties(JackWrap PROPERTIES PUBLIC_HEADER ${HEADERS})
include(GNUInstallDirs)
install(TARGETS JackWrap
  PUBLIC_HEADER
    DESTINATION include/5FX/
)