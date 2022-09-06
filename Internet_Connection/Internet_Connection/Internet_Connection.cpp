#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <winsock2.h>
#include <windows.h>
#pragma comment(lib,"Ws2_32.lib")
 
#define ADDR "209.85.229.104"
#define PORT 80
 
int main()
{
    link:
    WSADATA wsaDATA;
    SOCKET my_socket;
    sockaddr_in server_addr;
    int len_client_sock;
 
    printf("Scanner address: %s!\n", ADDR);
 
    if(WSAStartup(MAKEWORD(2,2), &wsaDATA) != NO_ERROR)
    {
        printf("Library WinSock not load!\n");
        WSACleanup();
        //system("PAUSE");
        return 1;
    }
    else
    printf("Library WinSock load!");
 
    my_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
 
    server_addr.sin_family = AF_INET;   
    server_addr.sin_addr.s_addr = inet_addr(ADDR);
    server_addr.sin_port = htons(PORT);
    len_client_sock = sizeof(server_addr);

        if(connect(my_socket, (sockaddr*)&server_addr, len_client_sock) != SOCKET_ERROR)
            printf("\nInternet YES!\n");
        else {
            printf("\nInternet NO!\n");
            system("C:\\Users\\User\\Desktop\\Netsh_dis.bat");
            Sleep(1000);
            system("C:\\Users\\User\\Desktop\\Netsh_ena.bat");
            Sleep(5600);
            } 
    
    shutdown(my_socket, SD_BOTH);
    closesocket(my_socket);
    WSACleanup();
    goto link;
    //system("PAUSE");
    return 0;
}
