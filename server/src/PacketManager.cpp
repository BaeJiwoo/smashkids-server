#include "PacketManager.hpp"

void PacketManager::Init(const UINT32 maxClient)
{
    mUserManager.Init(maxClient);
}

void PacketManager::Connect(const UINT32 u32ClientIndex)
{
    mUserManager.Connect(u32ClientIndex);
}

void PacketManager::DisConnect(const UINT32 u32ClientIndex)
{
    mUserManager.DisConnect(u32ClientIndex);
}