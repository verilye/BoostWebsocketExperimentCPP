# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()
project ("WebSocketChatAppClient")

# Include sub-projects.
# add_subdirectory ("WebSocketChatApp")

find_package(Boost)
# find_package(Boost 1.45.0 COMPONENTS *boost libraries here*) 

if(Boost_FOUND)
	include_directories(${Boost_INCLUDE_DIRS})
	# Add source to this project's executable.
	add_executable (WebSocketChatAppClient "main.cpp" "client.cpp" )
	target_link_libraries(WebSocketChatAppClient ${Boost_Libraries})

	message(Boost_LOADED)
endif()
