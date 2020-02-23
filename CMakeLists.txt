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
  boxeslist.cpp
  boxeslist.h
  boxeslist.ui
  boxwindow.cpp
  boxwindow.h
  boxwindow.ui
  calendar.cpp
  calendar.h
  clientslist.cpp
  clientslist.h
  clientslist.ui
  db_handler.cpp
  db_handler.h
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
  qsortfiltersqlquerymodel.cpp
  qsortfiltersqlquerymodel.h
  renter_addition.cpp
  renter_addition.h
  renter_addition.ui
  reservation_list.cpp
  reservation_list.h
  reservation_list.ui
  tablemodel.cpp
  tablemodel.h
)

target_link_libraries(pb_gui PRIVATE Qt5::Widgets Qt5::Sql Qt5::PrintSupport)
