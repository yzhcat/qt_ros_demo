cmake_minimum_required(VERSION 3.8)
project(ros_qt_demo LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()
# find dependencies
# ROS
find_package(roscpp REQUIRED)
find_package(std_msgs REQUIRED)
# QT
find_package(Qt5 COMPONENTS Widgets REQUIRED)
# find_package(<dependency> REQUIRED)

# 项目目录下的目标配置文件
file(GLOB PRO_SOURCE_DIR RELATIVE ${CMAKE_SOURCE_DIR} FOLLOW_SYMLINKS src/*.cpp include/*.hpp)
file(GLOB PRO_UI_DIR RELATIVE ${CMAKE_SOURCE_DIR} FOLLOW_SYMLINKS ui/*.ui)
file(GLOB PRO_INCLUDE_DIR RELATIVE ${CMAKE_SOURCE_DIR} FOLLOW_SYMLINKS include/*.h *.hpp)
file(GLOB PRO_RESOURCE_DIR RELATIVE ${CMAKE_SOURCE_DIR} FOLLOW_SYMLINKS resource/*.qrc)

#搜索头文件的位置
include_directories(
       include
       ${roscpp_INCLUDE_DIRS}
       ${CMAKE_CURRENT_BINARY_DIR}
       ${CMAKE_CURRENT_SOURCE_DIR}
)
# include_directories(${roscpp_INCLUDE_DIRS})
# （输出， 输入）
QT5_WRAP_UI(QT_UI_HPP ${PRO_UI_DIR})
QT5_WRAP_CPP(QT_MOC_HPP ${PRO_INCLUDE_DIR})
QT5_ADD_RESOURCES(QT_RESOUCE_HPP ${PRO_RESOURCE_DIR})

# 导入可执行的目标文件
add_executable(${PROJECT_NAME}
    ${PRO_SOURCE_DIR}
    ${PRO_INCLUDE_DIR}
    ${PRO_UI_DIR}
    ${PRO_RESOURCE_DIR}
    ${QT_UI_HPP} # UI的文件应该不需要添加在这里
    ${QT_MOC_HPP}
    ${QT_RESOUCE_HPP}
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets ${roscpp_LIBRARIES})
# install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
