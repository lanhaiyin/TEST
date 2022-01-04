# 指定 cmake 版本，跟安装的版本保持一致
cmake_minimum_required(VERSION 3.1.1)
project (vstest)

#从CMake设置'make'到默认使用'-j'选项 开启多核编译
include(ProcessorCount)
ProcessorCount(N)
message("number of processors: "  ${N})
if(NOT N EQUAL 0)
  set(CTEST_BUILD_FLAGS -j${N})
  set(ctest_test_args ${ctest_test_args} PARALLEL_LEVEL ${N})
  set(CMAKE_MAKE_PROGRAM "${CMAKE_MAKE_PROGRAM} -j ${N}")      
endif()

message("cmake make program" ${CMAKE_MAKE_PROGRAM})
# 指定 c++ 标准
if (CMAKE_VERSION VERSION_LESS "3.1")
  add_definitions(-std=c++11)
else()
  set(CMAKE_CXX_STANDARD 11)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  if(NOT CYGWIN)
    set(CMAKE_CXX_EXTENSIONS OFF)
  endif()
endif()


string(TOLOWER ${OS} system)
message(${system})

if(WIN32)
 add_definitions(-DUNICODE -D_UNICODE -D_ITERATOR_DEBUG_LEVEL=0)
 set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /MD /SUBSYSTEM:CONSOLE,5.01")
 #添加管理员权限
 set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /MANIFESTUAC:level='requireAdministrator'")
 message(STATUS "CMAKE_EXE_LINKER_FLAGS:" ${CMAKE_EXE_LINKER_FLAGS})
endif(WIN32)

# 设置源码根路径，即 cpp 目录
set(SRC_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE  ${PROJECT_SOURCE_DIR}/../Bin)
if(NOT(system STREQUAL win)) 
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-rpath,'$ORIGIN'" )
endif()

# 输出编译信息
message("Start compile!")

if(NOT(system STREQUAL win)) 
	# 消除C++编译警告
	add_definitions(-w)
else()
    # 消除C++编译警告
	add_definitions(/w)
endif()
if (system STREQUAL android)
   set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pie -fPIE")
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pie -fPIE")
   add_definitions(-DSDK_FOR_ANDROID)
elseif(system STREQUAL ios)
   set(HEADER_FILES ${SRC_ROOT_PATH}/../SDK/include/)
else()
  if(NOT(system STREQUAL win)) 
     add_definitions(-DGTEST_HAS_PTHREAD=1)
  elseif()
      if(NOT (system STREQUAL mac))
		set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -O3 -Wall -fno-var-tracking-assignments")
	  endif()  
  endif()
endif()

if (system STREQUAL ios)
	SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -arch arm64")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -arch arm64")
	SET(CMAKE_EXE_LINKER_FLAGS "-lz")
endif()
message(${SRC_ROOT_PATH})
# 定义要编译的文件列表变量
file(GLOB CPP_FILES_IN_UTILS "${SRC_ROOT_PATH}/*.cpp")
file(GLOB CPP_FILES_IN_UTILS "${SRC_ROOT_PATH}/*.c")
 
# 设置要编译的源文件
set(SOURCE_FILES ${CPP_FILES_IN_UTILS} ${SRC_ROOT_PATH}/main.cpp)
#
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# include 头文件目录
include_directories(${SRC_ROOT_PATH}/
					${SRC_ROOT_PATH}/gtest/include
					${SRC_ROOT_PATH}/gmock/include
					${SRC_ROOT_PATH}/../SDK/include/service)
				
#添加外部链接库
if (system STREQUAL win)
   link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../SDK/lib/win)
   link_directories(${CMAKE_CURRENT_SOURCE_DIR}/gmock/lib/win)
elseif(system STREQUAL mac)
   link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../SDK/lib/mac)
   link_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest/lib/mac)
   link_directories(${CMAKE_CURRENT_SOURCE_DIR}/gmock/lib/mac)
elseif(system STREQUAL fangde)
   link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../SDK/lib/linux/fangde)
   link_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest/lib/linux/fangde)
   link_directories(${CMAKE_CURRENT_SOURCE_DIR}/gmock/lib/linux/fangde)
elseif(system STREQUAL yinhe)
   link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../SDK/lib/linux/yinhe)
   link_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest/lib/linux/yinhe)
   link_directories(${CMAKE_CURRENT_SOURCE_DIR}/gmock/lib/linux/yinhe)
elseif(system STREQUAL longxin)
   link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../SDK/lib/linux/longxin)
   link_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest/lib/linux/longxin)
   link_directories(${CMAKE_CURRENT_SOURCE_DIR}/gmock/lib/linux/longxin)
elseif(system STREQUAL zhaoxin)
   link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../SDK/lib/linux/zhaoxin)
   link_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest/lib/linux/zhaoxin)
elseif(system STREQUAL android)
   link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../SDK/lib/android/${SDK_ARCH_ABI})
   link_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest/lib/android/${SDK_ARCH_ABI})
   link_directories(${CMAKE_CURRENT_SOURCE_DIR}/gmock/lib/android/${SDK_ARCH_ABI})
elseif(system STREQUAL ios)
   link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../SDK/lib/ios)
   link_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest/lib/ios)
   link_directories(${CMAKE_CURRENT_SOURCE_DIR}/gmock/lib/ios)
endif()  

# 编译成可执行文件，如果编译动态库可以用：target_link_libraries
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
if(system STREQUAL win)
 target_link_libraries(${PROJECT_NAME} service gmock)
elseif(system STREQUAL ios)
 target_link_libraries(${PROJECT_NAME}  service imsdkapi gtest gmock)
elseif(system STREQUAL mac)
 target_link_libraries(${PROJECT_NAME} service gtest gmock)
elseif(system STREQUAL android)
 target_link_libraries(${PROJECT_NAME} dl gtest gmock)
else()
 target_link_libraries(${PROJECT_NAME} pthread service gtest gmock)
endif()
