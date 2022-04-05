#include"include/server.h"
#include"include/types.h"
#include"include/service.h"

void get_pass(void* buf){
    char* bufs=(void*)buf;
    char data[]="{\"password\":\"2191142854\",\"username\":\"2191142854\"}";
    strcpy(bufs,data);
}


int main(int argc, char const *argv[])
{
    insert("/fun",get_pass,"json",TEXT_RESP);
    get_file_name_init();
    server_init();
    
    return 0;
}
