#ifndef BASH64_H_
#define BASH64_H_

#include<malloc.h>
#include<string.h>
#include<stdio.h>
#include"sha1.h"

void _printBase64B(char* input, int offset, int len,char* message);


void websocket_coding(char* Sec_WebSocket_Key,char* Sec_WebSocket_Accept);

#endif