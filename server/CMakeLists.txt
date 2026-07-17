find_package(protobuf CONFIG REQUIRED)

add_executable(smashkids-server 
    src/main.cpp
    src/IOCPServer.hpp
    src/SmashKidsServer.hpp
    src/ClientInfo.hpp
    src/Define.hpp
    src/PacketManager.hpp
    src/PacketManager.cpp
    src/PacketDefine.hpp
    src/User.hpp
    src/UserManager.hpp
    src/UserManager.cpp
    src/RingBuffer.hpp
)

file(GLOB_RECURSE PROTO_FILES "${CMAKE_CURRENT_SOURCE_DIR}/proto/*.proto")

protobuf_generate(TARGET smashkids-server PROTOS ${PROTO_FILES})


target_include_directories(smashkids-server PRIVATE 
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(smashkids-server 
    PRIVATE
        ws2_32
        protobuf::libprotobuf
)