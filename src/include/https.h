#ifndef HTTPS_H_
#define HTTPS_H_

struct requst_head{
    char method[255];
    char url[1024];
    char version[255];
    char message[255];
};

struct requst_key_value{
    char key[0xff];
    char value[0xff];
    struct requst_key_value* next;
};


struct requst_list{
    char message[1024];
    struct requst_list* next;
};

typedef struct requst_head RequstHead;
typedef struct requst_list RequstList;
typedef struct requst_key_value Requst_key_value;


void split_requst(char* message,char* head_information,RequstList* list);
void get_http_head(RequstHead* http_head,char* buf);
void insert_meesage(RequstList* list,char* message);

void requst_key_value_print(RequstList* list,Requst_key_value* value);
void print(Requst_key_value* value);

#endif