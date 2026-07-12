add_executable(smashkids-mockclient 
    src/main.cpp
    src/TcpClient.hpp
)

target_link_libraries(smashkids-mockclient 
    PRIVATE
        ws2_32
)
