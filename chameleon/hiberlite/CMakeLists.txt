project(hiberlite)
	set(CMAKE_CXX_STANDARD 17)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE 	.)
	include_directories(.)
	aux_source_directory(. SRC_LIST)
	
	add_library(hiberlite STATIC ${SRC_LIST})
