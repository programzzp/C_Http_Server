```c
#include"include/server.h"
#include"include/types.h"
#include"include/service.h"

//buf 用于传入参数与传出
void get_pass(void* buf){
    char* bufs=(void*)buf;
    char data[]="{\"password\":\"2191142854\",\"username\":\"2191142854\"}";
    strcpy(bufs,data);
}


int main(int argc, char const *argv[])
{
    //注册服务
    insert("/fun",get_pass,"json",TEXT_RESP);
    //初始化文件
    get_file_name_init();
    //初始化web服务器
    server_init();
    
    return 0;
}
```

**#include“include/service.h"**

 void insert(char* path,void* function,char* type,int file_type) 



- path:     虚拟路径
- function:   服务函数
- type: 文件类型
- file_type:  文件属性，1--->WEB下的时普通文件    0----->json文件 
  - FILE_RESP 1
  - TEXT_RESP 0

