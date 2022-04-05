#ifndef SERVER_H
#define SERVER_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<error.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/epoll.h>
#include"include/types.h"
#include"include/https.h"

#define PORT 8080
#define LISTEN 1024

char buf[BUFSIZ];



struct epoll_event event,ep[LISTEN];

int cfd,epfd,sfd;

void sys_error(char *str);
int Socket(int domain,int type);
int Bind(int sockfd,int port);
int Listen(int sockfd,int backlog);
int Accept(int sockfd);

void server_init();

#endif