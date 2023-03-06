#include "main.h"
#define HELLO "AT+CNETSCAN"

int main(){
    char *message;
    char return_buffer [1048];
    int port = uart_init();
    puts("here");
    uart_write(port,HELLO);
    message = uart_read(port, return_buffer);
    printf("%s",message);
    uart_close();
    return 0;
}