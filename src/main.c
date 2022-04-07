#include"include/server.h"
#include"include/types.h"
#include"include/service.h"
#include"include/https.h"

void get_pass(void* buf){
    char* bufs=(void*)buf;
    memset(bufs,0,strlen(bufs)+2);
    char data[]="{\"password\":\"2191142854\",\"username\":\"2191142854\"}";
    strcpy(bufs,data);
}


void get_user(void* buf){
    char* bufs=(void*)buf;
    char message[2][0xff];
    request_data_parse(bufs,message);
    memset(bufs,0,strlen(bufs)+2);
    char data[0xff];
    sprintf(data,"{\"password\":\"%s\",\"username\":\"%s\"}",message[0],message[1]);
    strcpy(bufs,data);
    memset(message,0,sizeof(message));
}


int main(int argc, char const *argv[])
{
    insert("/fun",get_pass,"json",TEXT_RESP);
    insert("/user",get_user,"json",TEXT_RESP);
    get_file_name_init();
    server_init();
    
    return 0;
}
