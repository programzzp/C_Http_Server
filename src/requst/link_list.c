#include"include/https.h"
#include"include/server.h"

void insert_meesage(RequstList* list,char* message){

    RequstList* node=(RequstList*)malloc(sizeof(RequstList));

    strcpy(node->message,message);

    if(list->next==NULL){
        list->next=node;
    }else{
        node->next=list->next;
        list->next=node;
    }
}



static void get_requst_key_value(Requst_key_value* key_value,char* message){
    char* str=message;
    char* key=key_value->key;
    char* value=key_value->value;

    while(*str!=':'){
        *key=*str;
        ++key;
        ++str;
    }
    *key='\0';
    str+=2;

     while(*str!='\0'){
        *value=*str;
        ++value;
        ++str;
    }
    *key='\0';
}

static void insert_requst_key_value(Requst_key_value* list,char* message){

    Requst_key_value* node=(Requst_key_value*)malloc(sizeof(Requst_key_value));
    get_requst_key_value(node,message);

    if(list->next==NULL){
        list->next=node;
    }else{
        node->next=list->next;
        list->next=node;
    }
}

void requst_key_value_print(RequstList* list,Requst_key_value* value){
    RequstList* node=list;
    Requst_key_value* value_node=value;

    while(node!=NULL){
        insert_requst_key_value(value_node,node->message);
        node=node->next;
    }
}

void print(Requst_key_value* value){
    Requst_key_value* node=value;

    while(node!=NULL){
        printf("key=%s    value=%s\n",node->key,node->value);
        node=node->next;
    }
}
