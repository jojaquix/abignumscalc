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
  if(NOT DEFINED Boost_LIBRARY_DIRSN)
		message("Setting manualy boost library dir")  
		set(Boost_LIBRARY_DIRS "${Boost_INCLUDE_DIRS}/x86/lib")
	else()
		message("boost library dir not empty" ${Boost_LIBRARY_DIRS})  
  endif()  
  message("Boost lib dir :" ${Boost_LIBRARY_DIRS})  
endif()

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

#set(SRC main.cpp)
#add_executable(main ${SRC})

#client
set(CLIENT_HDR serializer.h)
set(CLIENT_SRC serializer.cpp client.cpp)

add_executable(bncl ${CLIENT_HDR} ${CLIENT_SRC})
target_link_libraries(bncl ${Boost_LIBRARIES})





#server
set(SERVER_HDR calculator.h serializer.h)
set(SERVER_SRC calculator.cpp serializer.cpp)

add_executable(bnsrv ${SERVER_HDR} ${SERVER_SRC} server.cpp)
target_link_libraries(bnsrv ${Boost_LIBRARIES})

add_executable(bnsrvtest ${SERVER_HDR} ${SERVER_SRC} servertest.cpp)
add_test(bnsrvtest_basic bnsrvtest)





