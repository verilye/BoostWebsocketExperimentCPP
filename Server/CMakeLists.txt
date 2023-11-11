# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
project ("WebSocketChatAppServer")

# Include sub-projects.
find_package(Boost)
# find_package(Boost 1.45.0 COMPONENTS *boost libraries here*) 

if(Boost_FOUND)
	include_directories(${Boost_INCLUDE_DIRS})
	# Add source to this project's executable.
	add_executable (WebSocketChatAppServer "main.cpp" "server.cpp" )
	target_link_libraries(WebSocketChatAppServer ${Boost_Libraries})

	message(Boost_LOADED)
endif()
