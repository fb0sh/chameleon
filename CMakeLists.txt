project(chameleon)
	set(CMAKE_CXX_STANDARD 17)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG 	.)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE 	.)
	LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/chameleon)
	LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/chameleon/hiberlite)
	message(STATUS "build hiberlite")
	add_subdirectory("chameleon/hiberlite")
	message(STATUS "build chameleon")
	add_subdirectory("chameleon")

	message(STATUS "build manage")
	add_executable(manage main.cpp)
	target_link_libraries(manage libchameleon.a libhiberlite.a)

#	set(CHAMELEON_PATH "/home/bash/chameleon")
	
