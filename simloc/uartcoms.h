#include <fcntl.h> 
#include <errno.h> 
#include <termios.h> 
#include <unistd.h> 
#include <string.h>
int tty_open();
struct termios *tty_setup();
int uart_set(int uart_instance, struct termios *tty);
//initialize and setup uart. Returns a uart serial port number or -1 on errors for further info use errno
int uart_init();
//write to serial port returns errno
int uart_write(int uart_instance, char *message);
//read form serial port returns, a buffer of 1048 size 
char *uart_read(int uart_instance, char *buf);
//close uart instace
void uart_close();