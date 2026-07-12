add_executable(smashkids-server 
    src/main.cpp
    src/IOCPServer.hpp
    src/SmashKidsServer.hpp
    src/ClientInfo.hpp
    src/Define.hpp
)

target_link_libraries(smashkids-server 
    PRIVATE
        ws2_32
)