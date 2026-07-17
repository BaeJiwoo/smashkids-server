#ifndef SMASHKIDS_USERMANAGER_HPP
#define SMASHKIDS_USERMANAGER_HPP

#include "User.hpp"
#include <vector>

class UserManager
{
public:
    UserManager() = default;
    ~UserManager()
    {
        for(int i = 0; i < mUsers.size(); i++)
        {
            delete mUsers[i];
        }
        mUsers.clear();
    }

    void Init(const UINT32 maxClient);

    void Connect(const UINT32 u32ClientIndex);

    void DisConnect(const UINT32 u32ClientIndex);

    User* GetUserInfo(const UINT32 u32ClientIndex);

private:
    std::vector<User*> mUsers;
};

#endif