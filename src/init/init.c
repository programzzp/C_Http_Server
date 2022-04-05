#include"include/server.h"
#include"include/https.h"
#include"include/resp.h"
#include"include/service.h"


//请求处理
void messge_handle(char *buf,int fd){
    char resp_buf[0xfff];

    Service_func* func=NULL;
    RequstList* list=(RequstList*)malloc(sizeof(RequstList));
    RequstHead req_head;
    Service_func* node=function_head_;
    char head_information[255];
    split_requst(buf,head_information,list);

    get_http_head(&req_head,head_information);


    /**
     * 业务
     * */

    while(node!=NULL){
        if(strcmp(node->path,req_head.url)==0){
            func=node;
            break;
        }
        node=node->next;
    }


    if(func!=NULL){
        send_server_head_message(&req_head,fd,"200",func->type);


        if(func->file_type){
            void (*function_point)(int,char*)=func->func;
            (*function_point)(fd,func->path);
            memset(resp_buf,0,sizeof(resp_buf));
        }else{
            void (*function_point)()=func->func;
            (*function_point)(resp_buf);
            write(fd,resp_buf,strlen(resp_buf));
            memset(resp_buf,0,sizeof(resp_buf));
        }
    }else{
        send_server_head_message(&req_head,fd,"200","json");
        char body[0xff]="{\"password\":\"400\",\"username\":\"400\"}";
        write(fd,body,strlen(body));
        memset(body,0,sizeof(body));
    }

    memset(req_head.message,0,sizeof(req_head.message));
    memset(req_head.method,0,sizeof(req_head.method));
    memset(req_head.url,0,sizeof(req_head.url));
    memset(req_head.version,0,sizeof(req_head.version));
    memset(head_information,0,sizeof(head_information));
    free(list);
    
}


//socket初始化
static void socket_init(){
    sfd=Socket(AF_INET,SOCK_STREAM);
    Bind(sfd,PORT);
    Listen(sfd,LISTEN);
    printf("socket_init\n");
}


static void epoll_init(){
    epfd=epoll_create(LISTEN);
    event.events=EPOLLIN;
    event.data.fd=sfd;
    epoll_ctl(epfd,EPOLL_CTL_ADD,sfd,&event);
    printf("epoll_init\n");

}

void message_init(){
    int ret=0;
    int n=0;

    int i=0;

    while(true){
        ret=epoll_wait(epfd,ep,LISTEN,-1);

        for(i=0;i<ret;i++){
            if(ep[i].data.fd==sfd){
                cfd=Accept(sfd);
                event.events=EPOLLIN;
                event.data.fd=cfd;
                epoll_ctl(epfd,EPOLL_CTL_ADD,cfd,&event);
            }else{
                n=read(ep[i].data.fd,(void *)buf,sizeof(buf));

                if(n==0){
                    epoll_ctl(epfd,EPOLL_CTL_DEL,ep[i].data.fd,NULL);
                    close(ep[i].data.fd);
                }else if(n<0){
                    epoll_ctl(epfd,EPOLL_CTL_DEL,ep[i].data.fd,NULL);
                    close(ep[i].data.fd);
                }else{
                    messge_handle(buf,ep[i].data.fd);
                    close(ep[i].data.fd);
                }
            }
        }
    }
}

void server_init(){

    printf("start\n");
    socket_init();
    epoll_init();
    message_init();
}