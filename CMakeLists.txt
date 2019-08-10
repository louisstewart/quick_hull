cmake_minimum_required(VERSION 3.13)
project(quickhull)

include_directories(/usr/local/include)

if(APPLE AND EXISTS /usr/local/opt/qt)
    # Homebrew installs Qt5 (up to at least 5.9.1) in
    # /usr/local/qt, ensure it can be found by CMake since
    # it is not in the default /usr/local prefix.
    list(APPEND CMAKE_PREFIX_PATH "/usr/local/opt/qt")
endif()

set(CMAKE_CXX_STANDARD 17)

set (DEPS src/Vector2d.inl src/Vector2d.h src/quickhull.cpp src/quickhull.h src/Line2d.inl src/Line2d.h)
set(UIDEPS src/ui/Window.cpp src/ui/Helper.cpp src/ui/Helper.h src/ui/Widget.cpp src/ui/Widget.h)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(quickhull src/main.cpp ${DEPS})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
add_executable(quick src/ui/main.cpp ${DEPS} ${UIDEPS})
target_link_libraries(quick ${Qt5Widgets_LIBRARIES})

add_subdirectory(test)