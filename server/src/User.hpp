#ifndef USER_HPP
#define USER_HPP

#include <Windows.h>
#include <format>
#include <iostream>

enum class USERSTATE{
    DISCONNECTED,
    CONNECTED,
    LOGIN
};

//TODO: Packet
class User
{
    public:
    User(const UINT32 u32ClientIndex) : mUserIndex(u32ClientIndex) { }
    ~User() = default;

    void Init(const UINT32 u32UserIndex)
    {
        mUserIndex = u32UserIndex;
    }

    void Connect() 
    {
        mUserState = USERSTATE::CONNECTED;
        
        std::string message = std::format("[LOG] User {0} connected\n", mUserIndex);
        std::cout << message;
    }

    void DisConnect()
    {
        mUserState = USERSTATE::DISCONNECTED;

        std::string message = std::format("[LOG] User {0} DisConnected\n", mUserIndex);
        std::cout << message;
    }

    bool IsEmpty() { return mUserState == USERSTATE::DISCONNECTED ? true : false; }
    
    private:
    USERSTATE mUserState = USERSTATE::DISCONNECTED;

    UINT32 mUserIndex = -1;
};

#endif