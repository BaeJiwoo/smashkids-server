#include <iostream>
#include "TcpClient.hpp"
#include <utility>

#define PORT 9000

int main(int argc, char* argv[])
{
    TcpClient client;
    if (!client.Init(PORT)) // 서버 포트 지정
    {
        return -1;
    }
    if (!client.Connect("127.0.0.1"))
    {
        return -1;
    }
    
    std::string input;
    while (true)
    {
        std::getline(std::cin, input);
        if (input == "exit") break;
        
        for(int i = 0; i < 100; i++)
        {
            client.SendMessage(input);
            Sleep(10);
        }
    }
    client.Stop();

    return 0;
}
