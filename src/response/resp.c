#include"include/resp.h"


static Type tyeps_req[TYPE_LEN]={{"html","text/html"}, \
                {"css","text/css"}, \
                {"js","application/x-javascript"}, \
                {"plain","text/plain"}, \
                {"xml","text/xml"}, \
                {"ico","image/ico"}, \
                {"gif","image/gif"}, \
                {"jpeg","image/jpeg"}, \
                {"png","image/png"}, \
                {"jpg","image/jpg"}, \
                {"json","application/json"}};
        

static Respon respons_req[RESPON_LEN]={{"200","OK"}, \
                {"400","Not Foubd"},    \
                {"500","Internal Server Error"}};


// GET
// /
// HTTP/1.1

// HTTP/1.1 200 OK
// Server: Nginx_Server
// Accept-Ranges: bytes
// Context-Type: application/json
static void set_head_meesage(MemoryRequst* memory,char* version,char* code,char* type){
    strcpy(memory[0].data,version);
    strcat(memory[0].data," ");
    int i=0;
    for(i=0;i<RESPON_LEN;i++){
        if(strcmp(code,respons_req[i].key)==0){
            break;
        }
    }
    strcat(memory[0].data,respons_req[i].key);
    strcat(memory[0].data," ");
    strcat(memory[0].data,respons_req[i].value);
    strcat(memory[0].data,"\r\n");

    strcpy(memory[1].data,"Server: Nginx_Server\r\n");
    strcpy(memory[2].data,"Accept-Ranges: bytes\r\n");

    for(i=0;i<TYPE_LEN;i++){
        if(strcmp(type,tyeps_req[i].key)==0){
            break;
        }
    }

    strcpy(memory[3].data,"Context-Type: ");
    strcat(memory[3].data,tyeps_req[i].value);
    strcat(memory[3].data,"\r\n\r\n");
}



void send_server_head_message(RequstHead* head,int fd,char* code,char* type){
    MemoryRequst memory[4];
    int i=0;
    set_head_meesage(memory,head->version,code,type);
    char resp_head[0xff];
    strcpy(resp_head,memory[0].data);
    for(i=1;i<4;i++){
        strcat(resp_head,memory[i].data);
    }

    write(fd,resp_head,strlen(resp_head));
}

