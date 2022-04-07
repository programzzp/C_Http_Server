#include "include/base64.h"


static char* initEncodeMap() {
        char* map =(char*)malloc(64);
        int i;
        for (i = 0; i < 26; i++) {
            map[i] = (char) ('A' + i);
        }
        for (i = 26; i < 52; i++) {
            map[i] = (char) ('a' + (i - 26));
        }
        for (i = 52; i < 62; i++) {
            map[i] = (char) ('0' + (i - 52));
        }
        map[62] = '+';
        map[63] = '/';

        return map;
}


static char encode(int i) {
    char* encodeMap = initEncodeMap();
    return encodeMap[i & 0x3F];
}
static int _printBase64Binary(char* input, int offset, int len, char* buf, int ptr) {
        // encode elements until only 1 or 2 elements are left to encode
        int remaining = len;
        int i;
        for (i = offset;remaining >= 3; remaining -= 3, i += 3) {
            buf[ptr++] = encode(input[i] >> 2);
            buf[ptr++] = encode(
                    ((input[i] & 0x3) << 4)
                    | ((input[i + 1] >> 4) & 0xF));
            buf[ptr++] = encode(
                    ((input[i + 1] & 0xF) << 2)
                    | ((input[i + 2] >> 6) & 0x3));
            buf[ptr++] = encode(input[i + 2] & 0x3F);
        }
        // encode when exactly 1 element (left) to encode
        if (remaining == 1) {
            buf[ptr++] = encode(input[i] >> 2);
            buf[ptr++] = encode(((input[i]) & 0x3) << 4);
            buf[ptr++] = '=';
            buf[ptr++] = '=';
        }
        // encode when exactly 2 elements (left) to encode
        if (remaining == 2) {
            buf[ptr++] = encode(input[i] >> 2);
            buf[ptr++] = encode(((input[i] & 0x3) << 4)
                    | ((input[i + 1] >> 4) & 0xF));
            buf[ptr++] = encode((input[i + 1] & 0xF) << 2);
            buf[ptr++] = '=';
        }
        return ptr;
    }


void _printBase64B(char* input, int offset, int len,char* message) {
    char* buf=(char*)malloc(((len + 2) / 3) * 4);
    int ptr = _printBase64Binary(input, offset, len, buf, 0);
    strcpy(message,buf);
}

/**
 * websocket 编码验证
 * @param Sec_WebSocket_Key  
 * @param Sec_WebSocket_Accept 
 */
void websocket_coding(char* Sec_WebSocket_Key,char* Sec_WebSocket_Accept){
	SHA1_CTX sha; uint8_t results[20]; char *buf; int n;

	char* GUID="258EAFA5-E914-47DA-95CA-C5AB0DC85B11";
	char Sec_WebSocket_Key_Buf[0xfff];
	strcpy(Sec_WebSocket_Key_Buf,Sec_WebSocket_Key);
	strcat(Sec_WebSocket_Key_Buf,GUID);


	n = strlen(Sec_WebSocket_Key_Buf); 
    SHA1Init(&sha); 
    SHA1Update(&sha, (uint8_t *)Sec_WebSocket_Key_Buf, n); SHA1Final(results, &sha);


	 uint8_t message[20];
	_printBase64B(results,0,20,message);

	char data_message[20];
    char* str_massage=data_message;
    char* str=message;
    while(*str!='\0'){
        if(*str=='='){
             *str_massage=*str;
            ++str_massage;
            ++str;
            break;
        }
        *str_massage=*str;
        ++str_massage;
        ++str;
    }

    *str_massage='\0';

	strcpy(Sec_WebSocket_Accept,data_message);

}