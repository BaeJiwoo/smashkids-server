#include "UserManager.hpp"

void UserManager::Init(const UINT32 maxClient)
{
    for(int i = 0; i < maxClient; i++)
    {
        mUsers.emplace_back(new User(i));
    }
}

void UserManager::Connect(const UINT32 u32ClientIndex)
{
    mUsers[u32ClientIndex]->Connect();
}

void UserManager::DisConnect(const UINT32 u32ClientIndex)
{
    mUsers[u32ClientIndex]->DisConnect();
}

User* UserManager::GetUserInfo(const UINT32 u32ClientIndex)
{
    return mUsers[u32ClientIndex];
}