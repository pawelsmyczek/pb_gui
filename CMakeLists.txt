cmake_minimum_required(VERSION 3.5)

project(pb_gui LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)
find_package(Qt5PrintSupport REQUIRED)

add_executable(pb_gui
  main.cpp
  boxwindow.cpp
  boxwindow.h
  boxwindow.ui
  calendar.cpp
  calendar.h
  db_handler.h
  db_handler.cpp
  invoicegen.cpp
  invoicegen.h
  loginwidow.cpp
  loginwidow.h
  loginwidow.ui
  mainwindow.cpp
  mainwindow.h
  mainwindow.ui
  not_rentedboxwindow.cpp
  not_rentedboxwindow.h
  not_rentedboxwindow.ui
  renter_addition.cpp
  renter_addition.h
  renter_addition.ui
)

target_link_libraries(pb_gui PRIVATE Qt5::Widgets Qt5::Sql Qt5::PrintSupport)
