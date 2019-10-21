cmake_minimum_required(VERSION 3.5)

project(pb_gui LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(pb_gui
  main.cpp
  boxwindow.cpp
  boxwindow.h
  boxwindow.ui
  mainwindow.cpp
  mainwindow.h
  mainwindow.ui
)

target_link_libraries(pb_gui PRIVATE Qt5::Widgets)