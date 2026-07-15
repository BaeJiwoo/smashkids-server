#ifndef PACKETMANAGER_HPP
#define PACKETMANAGER_HPP

#include "proto\session.pb.h"
#include <queue>
#include <thread>
#include "PacketDefine.hpp"
#include "UserManager.hpp"

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
    
    private:
    UserManager mUserManager;
};
#endif