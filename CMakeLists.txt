cmake_minimum_required(VERSION 3.23)
project(Demo1)

set(CMAKE_CXX_STANDARD 14)

# 设置静态库路径(wpcap.lib所在目录)
link_directories(${CMAKE_SOURCE_DIR}/npcap/Lib/x64)

# 创建可执行目标
add_executable(${PROJECT_NAME} main.cpp)

# 添加头文件目录
target_include_directories(${PROJECT_NAME} PRIVATE
        "${CMAKE_SOURCE_DIR}//npcap//Include//pcap")
target_include_directories(${PROJECT_NAME} PRIVATE
        "${CMAKE_SOURCE_DIR}//npcap//Include")

# 添加 wpcap 静态库
target_link_libraries(${PROJECT_NAME} PRIVATE wpcap)

# 设置 Windows 系统下 socket 网络编程库 ws2_32
if(WIN32)
    # 将 ws2_32 动态库添加到链接路径
    target_link_libraries(${PROJECT_NAME} PRIVATE ws2_32)
endif()
