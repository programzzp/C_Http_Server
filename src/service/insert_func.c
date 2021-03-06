#include"include/service.h"


void insert(char* path,void* function,char* type,int file_type){
    Service_func* node=(Service_func*)malloc(sizeof(Service_func));
    strcpy(node->path,path);
    strcpy(node->type,type);
    node->func=function;
    node->file_type=file_type;

    if(function_head_==NULL){
        function_head_=node;
        node->next=NULL;
    }else{
        node->next=function_head_;
        function_head_=node;
    }
}


/**
 * fd  :文件描述符 
 * path:请求路径
 * */
void read_file(int fd,char* path){
    int file_fd;
    char path_file[0xff];
    char buf[1024];
    strcpy(path_file,"./WEB");
    strcat(path_file,path);

    file_fd=open(path_file,O_RDONLY);
    if(file_fd==-1){
        return;
    }
    int n=0;
    while((n=read(file_fd,buf,1024))!=0){
        write(fd,buf,n);
    }

    memset(path_file,0,strlen(path_file)+2);
    memset(buf,0,strlen(buf)+1);
}

static void get_file_type(char* file_name,char* type_name){
    while(*file_name!='.'){
        ++file_name;
    }

    ++file_name;

     while(*file_name!='\0'){
         *type_name=*file_name;
        ++file_name;
        ++type_name;

    }

    *type_name='\0';
}

void get_file_name_init(){
    char path[0xff];
    char type[0xf];

    DIR* dir;
    struct dirent* f_fd;

    dir=opendir("./WEB");

    if (dir==NULL)
    {
        perror("open error");
    }

    while((f_fd=readdir(dir))!=NULL){

        if(strcmp(f_fd->d_name,".")&&strcmp(f_fd->d_name,"..")){
            strcpy(path,"/");
            strcat(path,f_fd->d_name);
            get_file_type(path,type);
            insert(path,read_file,type,FILE_RESP);
            memset(type,0,strlen(type)+2);
            memset(path,0,strlen(path)+2);
        }
    }
}

//请求数据解析
void request_data_parse(char* message,char (*data)[0xff]){
   char buf[0xff];
   int index=0;

   char message_data[0xff];
   strcpy(buf,message);

   char* str=buf;
   char* data_str;

   char *p;

   start:

   data_str=message_data;

   while(*str!='='){
       ++str;
   }
   ++str;

   while(*str!='&'){
       if(*str=='\0'){
           break;
       }
       *data_str=*str;

       ++data_str;
       ++str;
   }

   *data_str='\0';

   p=data[index];

   strcpy(p,message_data);
   ++index;
   memset(message_data,0,strlen(message_data)+1);
   if(*str=='&'){
       ++str;
       goto start;
   }
}

