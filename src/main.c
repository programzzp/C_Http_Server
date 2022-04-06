#include"include/server.h"
#include"include/types.h"
#include"include/service.h"

void get_pass(void* buf){
    char* bufs=(void*)buf;
    printf("\033[31m%s\n\033[0m",bufs);
    memset(bufs,0,strlen(bufs)+2);
    char data[]="{\"password\":\"2191142854\",\"username\":\"2191142854\"}";
    strcpy(bufs,data);
}


void get_user(void* buf){
    char* bufs=(void*)buf;
    printf("\033[31m%s\n\033[0m",bufs);
    memset(bufs,0,strlen(bufs)+2);
    char data[]="{\"password\":\"fsdfdsfsdf\",\"username\":\"sdfsdf\"}";
    strcpy(bufs,data);
}


int main(int argc, char const *argv[])
{
    insert("/fun",get_pass,"json",TEXT_RESP);
    insert("/user",get_user,"json",TEXT_RESP);
    get_file_name_init();
    server_init();
    
    return 0;
}
