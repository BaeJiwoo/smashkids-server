#ifndef SMASHKIDS_USER_HPP
#define SMASHKIDS_USER_HPP

#include "RingBuffer.hpp"
#include "PacketDefine.hpp"

#include <Windows.h>

#include <format>
#include <iostream>

enum class USERSTATE{
    DISCONNECTED,
    CONNECTED,
    LOGIN
};

class User
{
public:
    User(const UINT32 u32ClientIndex) : mUserIndex(u32ClientIndex) { }
    ~User() = default;

    void Init(const UINT32 u32UserIndex)
    {
        mUserIndex = u32UserIndex;
        mRingBuffer = std::make_unique<RingBuffer>(4096);
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

    void SetPacket()
    {
        // TODO: push data to user ring buffer
    }

    PacketInfo GetPacket()
    {
        // TODO: check packet is completed via packet info
        // NOTE: first data of buffer would be packet size&type info.
        //          if you read it from buffer another packet info would going will places at head;
    }

    bool IsEmpty() { return mUserState == USERSTATE::DISCONNECTED ? true : false; }
    
private:
    USERSTATE mUserState = USERSTATE::DISCONNECTED;

    UINT32 mUserIndex = -1;

    std::unique_ptr<RingBuffer> mRingBuffer;
};

#endif