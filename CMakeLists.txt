cmake_minimum_required(VERSION 3.10)
project(tiny-blockchain)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

set(SOURCES
    main.cpp
    src/Block.cpp
    src/Utils.cpp
    src/Blockchain.cpp
)

add_executable(main ${SOURCES})

target_include_directories(main PRIVATE include)