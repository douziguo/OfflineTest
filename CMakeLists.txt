cmake_minimum_required(VERSION 3.15)
project(OfflineTestModule LANGUAGES CXX)

# 设置编译标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找依赖包
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(Qt5_DIR $ENV{QT_GCC_DIR})
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(Qt5_DIR $ENV{QT_MSVC_DIR})
endif()

find_package(Qt5 COMPONENTS Core Gui Widgets Network REQUIRED)
SET(QT_LIBS Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Network)
list(APPEND LINK_LIBS ${QT_LIBS})

message(STATUS "qtPath:${Qt5_DIR}")

# 查找OpenCV
if(DEFINED ENV{OPENCV455_DIR})
    set(OpenCV_DIR $ENV{OPENCV455_DIR})
    message(STATUS "使用环境变量中的 OpenCV 路径: ${OpenCV_DIR}")
else()
    set(OpenCV_DIR "E:/Environment/OpenCV455/build/install")
    message(STATUS "使用默认 OpenCV 路径: ${OpenCV_DIR}")
endif()

find_package(OpenCV REQUIRED)

if(OpenCV_FOUND)
    message(STATUS "OpenCV 版本: ${OpenCV_VERSION}")
    message(STATUS "OpenCV 包含目录: ${OpenCV_INCLUDE_DIRS}")
else()
    message(FATAL_ERROR "OpenCV 库未找到")
endif()


# ========== 查找VDD库 ==========
set(VDD_LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/VDD/Lib/VDDevelopKitC.x64.lib")
if(NOT EXISTS ${VDD_LIB_PATH})
    message(FATAL_ERROR
            "VDD库文件不存在: ${VDD_LIB_PATH}\n"
            "请检查: ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/VDD/Lib/ 目录下是否有VDDevelopKitC.x64.lib文件"
    )
else()
    message(STATUS "找到VDD库: ${VDD_LIB_PATH}")
endif()

# 收集.cpp文件
file(GLOB SRC_FILES_CPP "*.cpp")

# 收集.ui文件
file(GLOB UI_FILES "*.ui")

# 设置头文件
set(HEADER_FILES mainwindow.h)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

# 添加Qt资源文件
set(RESOURCES
        "resources.qrc"
)

# Windows应用程序图标
if(WIN32)
    set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/app.rc")
endif()


# 添加到动态库
add_executable(OfflineTestModule
        ${SRC_FILES_CPP}
        ${UI_FILES}
        ${HEADER_FILES}
        ${RESOURCES}
        ${APP_ICON_RESOURCE_WINDOWS}
)

# 设置目标属性
set_target_properties(OfflineTestModule PROPERTIES
        DEBUG_POSTFIX "d"
        OUTPUT_NAME "OfflineTestModule"
)

# ========== 包含目录 ==========
target_include_directories(OfflineTestModule PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}  # 添加构建目录以包含生成的UI头文件
        ${OpenCV_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/VDD/Include
)

# 如果glog头文件存在，添加包含目录
if(HAVE_GLOG_INCLUDES)
    target_include_directories(OfflineTestModule PUBLIC
            ${GLOG_INCLUDE_PATH}
    )
endif()

# ========== 链接目录 ==========
target_link_directories(OfflineTestModule PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/VDD/Lib
)

# ========== 链接库 ==========
target_link_libraries(OfflineTestModule PRIVATE
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Network
        ${OpenCV_LIBS}
        VDDevelopKitC.x64.lib
)


# 打印详细信息
message(STATUS "===========================================")
message(STATUS "动态库配置信息:")
message(STATUS "项目名称: ${PROJECT_NAME}")
message(STATUS "目标名称: OfflineTestModule")
message(STATUS "C++源文件: ${SRC_FILES_CPP}")
message(STATUS "UI文件: ${UI_FILES}")
message(STATUS "头文件: ${HEADER_FILES}")
message(STATUS "===========================================")