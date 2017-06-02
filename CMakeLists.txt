cmake_minimum_required(VERSION 3.0)
enable_testing()
project(bignumsops)


set( ${PROJECT_NAME}_MAJOR_VERSION 0 )
set( ${PROJECT_NAME}_MINOR_VERSION 1 )
set( ${PROJECT_NAME}_PATCH_LEVEL 0 )


find_package(Boost
  1.36.0 
  REQUIRED             # Fail with error if Boost is not found
)    

if(Boost_FOUND)
  message("Boost include dir :" ${Boost_INCLUDE_DIRS})  
  if(NOT DEFINED Boost_LIBRARY_DIRS)
		message("Setting manualy boost library dir")  
		set(Boost_LIBRARY_DIRS "${Boost_INCLUDE_DIRS}/x86/lib")
	else()
		message("boost library dir not empty" ${Boost_LIBRARY_DIRS})  
  endif()  
  message("Boost lib dir :" ${Boost_LIBRARY_DIRS})  
endif()

if(CMAKE_COMPILER_IS_GNUCXX)
        add_definitions(-DBOOST_TEST_DYN_LINK) 
	add_definitions("-std=c++11")
	set( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -lboost_system -lboost_thread -lboost_unit_test_framework" )    
endif()

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})





#client
set(CLIENT_HDR client.h)
set(CLIENT_SRC client.cpp)

add_executable(bncl ${CLIENT_HDR} ${CLIENT_SRC} client_main.cpp)
target_link_libraries(bncl ${Boost_LIBRARIES})


#server
set(SERVER_HDR calculator.h server.h)
set(SERVER_SRC calculator.cpp server.cpp)

add_executable(bnsrv ${SERVER_HDR} ${SERVER_SRC}  server_main.cpp)
target_link_libraries(bnsrv ${Boost_LIBRARIES})

add_executable(tests ${SERVER_HDR} ${SERVER_SRC} tests.cpp)
add_test(big_nums_ops tests )




