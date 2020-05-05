//
//  KcbServer.cpp
//  TunderClass
//
//  Created by Amy Zhou on 2020/5/5.
//  Copyright © 2020 Amy Zhou. All rights reserved.
//

#include "KcbServer.hpp"
#include <sys/unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>

void
server(){
    int socketFd = socket(AF_INET, SOCK_STREAM, 0);
    // ip 和 端口
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = 0x00000000;
    serverAddress.sin_port = 0xBEAF;
    
    // 向OS申请端口
    bind(socketFd, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
    //开始监听请求, 第二个参数无脑写6
    listen(socketFd, 6);
    
    // 接受客户端连接
    struct sockaddr_in clientAddress;
    socklen_t len = sizeof(clientAddress);
    int connection = accept(socketFd, (struct sockaddr *)&clientAddress, &len);
    
    //执行到这里,说明已经创建了连接,可以直接读取客户端发送来的数据
    const int size = 100;
    char data[size];
    recv(connection, data, size, 0);
    printf("recv: (%s)\n", data);
}
int main(){
    server();
    return 0;
}
