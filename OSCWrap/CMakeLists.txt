cmake_minimum_required(VERSION 3.13.0)
project(libOSCWrap VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS oscwrap.hpp)
set(SOURCES oscwrap.cpp)

add_library(OSCWrap SHARED ${SOURCES} ${HEADERS})
set_target_properties(OSCWrap PROPERTIES PUBLIC_HEADER ${HEADERS})
include(GNUInstallDirs)
install(TARGETS OSCWrap
  PUBLIC_HEADER
    DESTINATION include/5FX/
)