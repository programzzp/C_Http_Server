#include"include/types.h"
#include"include/server.h"
#include"include/https.h"

void split_requst(char* message,char* head_information,RequstList* list){
    char *delim = "\r\n";
    char *p;
    strcpy(head_information,strtok(message, delim));
    while((p = strtok(NULL, delim))){
        insert_meesage(list,p);
    }
}


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
    }


    version='\0';
}