#include"include/server.h"

//出错检查函数
void sys_error(char *str){
    perror(str);
    exit(-1);
}

int Socket(int domain,int type){
    int ret=socket(domain,type,0);
    if (ret==-1)
        perror("socket error:");
    return ret;
}

int Bind(int sockfd,int port){

    struct sockaddr_in socket_server;
    socket_server.sin_family=AF_INET;
    socket_server.sin_port=htons(port);
    socket_server.sin_addr.s_addr=htonl(INADDR_ANY);

    int ret=bind(sockfd,(struct sockaddr *)&socket_server,sizeof(socket_server));
    if (ret==-1)
        perror("bind error:");
    return ret;
}

int Listen(int sockfd,int backlog){
    int ret=listen(sockfd,backlog);
    if (ret==-1)
        perror("listen error:");
    return ret;
}

int Accept(int sockfd){
    struct sockaddr_in socket_client;
    socklen_t server_length;
     server_length=sizeof(socket_client);
    int ret=accept(sockfd,(struct sockaddr *)&socket_client,&server_length);
    if (ret==-1)
        perror("accept error:");
    return ret;
}
