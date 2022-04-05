#ifndef HTTPS_H_
#define HTTPS_H_

struct requst_head{
    char method[255];
    char url[1024];
    char version[255];
    char message[255];
};


struct requst_list{
    char message[1024];
    struct requst_list* next;
};

typedef struct requst_head RequstHead;
typedef struct requst_list RequstList;


void split_requst(char* message,char* head_information,RequstList* list);
void get_http_head(RequstHead* http_head,char* buf);
void insert_meesage(RequstList* list,char* message);
void http_head_print(RequstList* list);

#endif