#ifndef SERVICE_H_
#define SERVICE_H_

#define FILE_RESP 1
#define TEXT_RESP 0

#include<malloc.h>
#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

struct add_service_func{
    char path[0xff];
    void* func;
    char type[0xf];
    int file_type;
    struct add_service_func* next;
};

typedef struct add_service_func Service_func;

Service_func* function_head_;

void insert(char* path,void* function,char* type,int file_type);

void get_file_name_init();

void read_file(int fd,char* path);

#endif