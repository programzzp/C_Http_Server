#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include <dirent.h>
struct requst_head{
    char method[255];
    char url[1024];
    char version[255];
    char message[255];
};



typedef struct requst_head RequstHead;


void get_http_head(RequstHead* http_head,char* buf){
    char* str=buf;
    char* method=http_head->method;
    char* url=http_head->url;
    char* message=http_head->message;
    char* version=http_head->version;

    while(*str!=' '){
        *method=*str;
        ++method;
        ++str;
    }
    ++str;
    method='\0';

    while(*str!=' '){
        if(*str=='?'){
            break;
        }
        *url=*str;
        ++url;
        ++str;
    }
    url='\0';


    if(strcmp(http_head->method,"GET")==0){
        if(*str=='?'){
            ++str;
            while(*str!=' '){
                *message=*str;
                ++message;
                ++str;
            }
            message='\0';
        }
    }

    ++str;

    while((*str!='\r')){
        if(*str=='\n'||*str=='\0'){
            break;
        }
        *version=*str;
        ++version;
        ++str;
        printf("%c",*str);
    }

    version='\0';
}


static void get_file_type(char* file_name,char* type_name){
    

    while(*file_name!='.'){
        ++file_name;
    }

    ++file_name;

     while(*file_name!='\0'){
         *type_name=*file_name;
        ++file_name;
        ++type_name;

    }

    *type_name='\0';
}
int main(int argc, char const *argv[])
{
    char *name="index.html";
    char buf[0xf];
    get_file_type(name,buf);

    printf("buf=%s\n",buf);
    return 0;
}
