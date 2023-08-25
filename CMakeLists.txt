project(chameleon)
	set(CMAKE_CXX_STANDARD 17)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG 	.)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE 	.)

	message(STATUS "build hiberlite")
	add_subdirectory(chameleon/hiberlite)
	message(STATUS "build chameleon")
	add_subdirectory(chameleon)

	message(STATUS "build manage")
	find_package(Threads)
	add_executable(manage main.cpp)
	target_link_libraries(manage hiberlite chameleon ${CMAKE_THREAD_LIBS_INIT} dl)
