#ifndef SMASHKIDS_PACKETMANAGER_HPP
#define SMASHKIDS_PACKETMANAGER_HPP

#include "proto\session.pb.h"
#include "PacketDefine.hpp"
#include "UserManager.hpp"

#include <queue>
#include <thread>

class PacketManager {
public:
    PacketManager()
    {
        GOOGLE_PROTOBUF_VERIFY_VERSION;
    }

    ~PacketManager() = default;

    void Init(const UINT32 maxClient);

    void Connect(const UINT32 u32ClientIndex);

    void DisConnect(const UINT32 u32ClientIndex);
    
    void ReceivePacketData(const UINT32 u32ClientIndex, const char* pMessage, const DWORD dwTrasferredSize);
    
private:
    UserManager mUserManager;
};
#endif