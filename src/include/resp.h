#ifndef RESP_H_
#define RESP_H_

#include"include/contexttype.h"
#include"include/server.h"
#include"include/types.h"



struct service
{
    void* funcation;
    char path[0xff];
};



void send_server_head_message(RequstHead* head,int fd,char* code,char* type);
#endif