﻿cmake_minimum_required (VERSION 3.8)

project ("Profiling")

add_executable (Profiling "src/main.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Profiling PROPERTY CXX_STANDARD 20)
endif()