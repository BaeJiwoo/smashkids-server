#ifndef ISLEWRIGHTER_SERVER_H
#define ISLEWRIGHTER_SERVER_H

#include "IOCPServer.hpp"
#include "PacketManager.hpp"

class SmashKidsServer : public IOCPServer
{
    public:
    SmashKidsServer() {}
    ~SmashKidsServer() {}


    void Run(const UINT32 maxClient) 
    {
        StartServer(maxClient);
        mPacketManager.Init(maxClient);

        std::cout << "[SYSTEM] Server Started...\n";
    }

    void End() 
    {
        DestroyThread();
    }
     
    void OnConnect(const UINT32 u32ClientIndex) override 
    {
        std::string message = std::format("Client {0} connected\n", u32ClientIndex);
        std::cout << message;
        mPacketManager.Connect(u32ClientIndex);
    }

    void OnDisConnect(const UINT32 u32ClientIndex) override 
    {
        
        mPacketManager.DisConnect(u32ClientIndex);
    }

    void OnReceive(const UINT32 u32ClientIndex, const char* pMessage, const DWORD dwTrasferredSize) override 
    {
        std::string_view msg(pMessage, dwTrasferredSize);

        std::string message = std::format("Message from Client{0}: {1}\n", u32ClientIndex, msg);
        std::cout << message;
    }

    void OnSend(const UINT32 u32ClientIndex, const char* pMessage, const DWORD dwTrasferredSize) override 
    {
        std::string_view msg(pMessage, dwTrasferredSize);

        std::string message = std::format("Message from Client{0}: {1}\n", u32ClientIndex, msg);
        std::cout << message;
    }

    private:
    PacketManager mPacketManager;

};

#endif