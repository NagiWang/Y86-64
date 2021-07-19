cmake_minimum_required(VERSION 3.10)
#set(CMAKE_TOOLCHAIN_FILE "G:/vcpkg/scripts/buildsystems/vcpkg.cmake")
#
#if(DEFINED ENV{VCPKG_DEFAULT_TRIPLET} AND NOT DEFINED VCPKG_TARGET_TRIPLET)
#  set(VCPKG_TARGET_TRIPLET
#      "$ENV{VCPKG_DEFAULT_TRIPLET}"
#      CACHE STRING "")
#endif()

project(Y86-64)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CXX_STANDARD 20)

# set(Boost_ARCHITECTURE -x64)
# set(Boost_USE_STATIC_LIBS ON)
# set(Boost_INCLUDE_DIR ${_VCPKG_INSTALLED_DIR}/x64-windows-static/include)
# find_package(
#   Boost
#   COMPONENTS serialization thread atomic
#   REQUIRED)

# if(WIN32) set(BOOST_LIBRARIES ${Boost_LIBRARY_DIRS}) if(CMAKE_BUILD_TYPE
# MATCHES "Debug") set(BOOST_LIBRARIES ${Boost_LIBRARY_DIRS}/../debug/lib/)
# endif() endif()

# if(Boost_FOUND)
#   include_directories(${Boost_INCLUDE_DIRS})
#   link_directories(${Boost_LIBRARY_DIRS})
#   message("\nBoost Include Success!\n")
# endif()


# find_package(Microsoft.GSL CONFIG REQUIRED) target_link_libraries(main PRIVATE
# Microsoft.GSL::GSL)

# set(CMAKE_CXX_FLAGS "-ftemplate-depth=2000 -fno-exceptions -fno-rtti -Wall
# -Werror -pedantic-errors") set(CMAKE_CXX_FLAGS "-fno-exceptions -fno-rtti
# -Wall -Werror -pedantic-errors")

# add_library(boostdi STATIC ./src/di.hpp)

if(CMAKE_BUILD_TYPE STREQUAL Debug)
  add_definitions(-DDEBUG)
endif()


include_directories("${PROJECT_SOURCE_DIR}/src/")
add_subdirectory(./src)
# add_subdirectory(./test)

# include(GNUInstallDirs)

# # Adding the install interface generator expression makes sure that the
# include # files are installed to the proper location (provided by
# GNUInstallDirs)
# add_library(${PROJECT_NAME} INTERFACE)
# target_include_directories(
#   ${PROJECT_NAME}
#   INTERFACE $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}/include>
#             $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

# target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_20)

# enable_testing()
