#ifndef CONTEXT_TYPE_H_
#define CONTEXT_TYPE_H_

struct memory_requst 
{
    char data[0xff];
};



struct type{
    char key[0xff];
    char value[0xff];
};

struct respon
{
    char key[0xff];
    char value[0xff];
};


typedef struct type Type;

typedef struct respon Respon;

typedef struct memory_requst MemoryRequst;

#define TYPE_LEN 0xB
#define RESPON_LEN 0x3


#endif