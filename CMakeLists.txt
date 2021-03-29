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

install(TARGETS trending
  EXPORT trending-targets
  DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

# Binary

# Test
if(GTEST_FOUND)
  enable_testing()
  include_directories(${GTEST_INCLUDE_DIR})
  add_subdirectory(trending/test)
endif()

# CmakeConfig
include(CMakePackageConfigHelpers)

install(
  EXPORT trending-targets
  NAMESPACE trending::
  FILE trending-targets.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/trending
)

configure_package_config_file(
  ${CMAKE_MODULE_PATH}/trending-config.cmake.in
  trending-config.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/trending
  NO_CHECK_REQUIRED_COMPONENTS_MACRO
  PATH_VARS CMAKE_INSTALL_INCLUDEDIR
)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/trending-config.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/trending
)

# Pack
set(CPACK_SYSTEM_NAME "amd64")
find_program(DPKG_CMD dpkg)
if(DPKG_CMD)
  execute_process(
    COMMAND "${DPKG_CMD}" --print-architecture
    OUTPUT_VARIABLE CPACK_SYSTEM_NAME
    OUTPUT_STRIP_TRAILING_WHITESPACE)
endif()

include(InstallRequiredSystemLibraries)
if(DPKG_CMD)
  set(CPACK_GENERATOR "DEB;TXZ")
else()
  set(CPACK_GENERATOR "TXZ")
endif()
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT "yeolar@qq.com")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Trending library.")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "")
include(CPack)

