cmake_minimum_required(VERSION 2.6)

# Project configuration
project(ringbuffer)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

# Source files
file(
	GLOB_RECURSE
	source_files
	src/*
)

# Executable declaration
add_executable(
	ringbuffer
	${source_files}
)

