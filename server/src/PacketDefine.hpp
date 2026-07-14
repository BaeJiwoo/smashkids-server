#ifndef PACKETDEFINE_HPP
#define PACKETDEFINE_HPP

#include <Windows.h>

enum class PLAYEROPERATION
{
    MOVE = 0,
};

struct SYS_PACKET
{
    UINT32 clientIndex;
    char* msg;
};
#endif