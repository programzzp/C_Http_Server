#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include <dirent.h>
#include"include/base64.h"
#include"include/sha1.h"

int main(int argc, char const *argv[])
{

    char buf[0xff];
    websocket_coding("UjxPJpGjxC4JH5+0znrYBg==",buf);
    printf("%s\n",buf);

    return 0;
}
