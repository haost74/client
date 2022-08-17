#pragma once

#undef UNICODE

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#include <string>
using std::string;

#include <iostream>

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "8887"

//#include <json/json.h>
#include "../json/jsoncpp/include/json/json.h"


namespace clientAsync
{
    class client
    {
    private:
      WSADATA wsaData;
    SOCKET ConnectSocket = INVALID_SOCKET;
    struct addrinfo *result = NULL,
                    *ptr = NULL,
                    hints;
    const char *sendbuf = "this is a test";
    char recvbuf[DEFAULT_BUFLEN];
    int iResult;
    int recvbuflen = DEFAULT_BUFLEN;
    string address;
      
    public:
        client(string address = "192.168.8.1");
        ~client();
    };
}