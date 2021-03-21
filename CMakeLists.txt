# Copyright 2021 Yeolar

cmake_minimum_required(VERSION 3.6)

# Define project
project(trending VERSION 0.1.0)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake-scripts)

include(GNUInstallDirs)
include(Functions)

# Required packages
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
find_package(Threads REQUIRED)

# Optional packages
find_package(GTest)

# Setup environment
set(CMAKE_BUILD_TYPE RelWithDebInfo)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")    # memcheck
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_VERBOSE_MAKEFILE OFF)

# Link libraries
link_libraries(
  ${CMAKE_THREAD_LIBS_INIT}
  ${CMAKE_DL_LIBS}
)

include_directories(
  ${PROJECT_SOURCE_DIR}
  ${CMAKE_PREFIX_PATH}/include
)

# Check and setup configurations
include(CheckCXXSourceCompiles REQUIRED)
include(CheckFunctionExists REQUIRED)

configure_file(
  ${PROJECT_SOURCE_DIR}/trending/trending-config.h.in
  ${PROJECT_SOURCE_DIR}/trending/trending-config.h
)

# Work on all sub directories
build_directory(trending _base)

add_library(trending
  $<TARGET_OBJECTS:trending_base>
)

# Binary

# Test
if(GTEST_FOUND)
  enable_testing()
endif()

