cmake_minimum_required(VERSION 3.24)
project(smashkids-server)

project(
    smashkids-server
    VERSION 0.1.0
    DESCRIPTION "A 2D top down based shooting game"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)



add_executable(smashkids-server 
    src/main.cpp
)


target_link_libraries(smashkids-server 
    PRIVATE
        ws2_32
)