cmake_minimum_required(VERSION 3.5)

project(ObserverPattern)

set(SOURCES
    ./main.cpp
    ./observer.cpp
    ./subject.cpp
)

add_executable(observer ${SOURCES})

target_include_directories(observer
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

