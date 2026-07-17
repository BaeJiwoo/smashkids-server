#ifndef SMASHKIDS_PACKETDEFINE_HPP
#define SMASHKIDS_PACKETDEFINE_HPP

#include <Windows.h>

enum class USEROPERATION
{
    LOGIN = 0,
    
};

struct PacketInfo
{
    UINT32 clientIndex;
    char* msg;
};



#endif