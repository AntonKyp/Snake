cmake_minimum_required(VERSION 3.16)
project(QtOpenGLApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.8.2/mingw_64")

find_package(Qt6 REQUIRED COMPONENTS Widgets OpenGL OpenGLWidgets)

add_executable(snake main.cpp MainWindow.cpp GLWidget.cpp StartScreen.cpp Label.cpp)

target_link_libraries(snake PRIVATE Qt6::Widgets Qt6::OpenGL Qt6::OpenGLWidgets)