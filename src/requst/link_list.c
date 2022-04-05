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

void http_head_print(RequstList* list){
    RequstList* node=list;

    while(node!=NULL){
        printf("%s\n",node->message);
        node=node->next;
    }
}

