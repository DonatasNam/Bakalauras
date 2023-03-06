#include "uartcoms.h"

int tty_open(){
    int uart_instance = open("/dev/ttyUSB0",O_RDWR);
    return uart_instance;
}

void uart_close(int port){
    close(port);
    return;
}

struct termios *tty_setup(){
    struct termios *tty;
    tty->c_cflag &= ~PARENB; //disable parity
    tty->c_cflag &= ~CSTOPB; //clear stop field
    tty->c_cflag &= ~CSIZE;
    tty->c_cflag |= CS8; //set 8 bits per byte
    tty->c_cflag |= CREAD | CLOCAL;
    tty->c_lflag &= ~ICANON;
    tty->c_lflag &= ~ECHO; // Disable echo
    tty->c_lflag &= ~ECHOE; // Disable erasure
    tty->c_lflag &= ~ECHONL; 
    tty->c_lflag &= ~ISIG;
    tty->c_iflag &= ~(IXON | IXOFF | IXANY); 
    tty->c_iflag &= ~(IXON | IXOFF | IXANY); 
    tty->c_oflag &= ~OPOST; // Prevent special interpretation of output bytes (e.g. newline chars)
    tty->c_oflag &= ~ONLCR; 
    tty->c_cc[VTIME] = 10;   
    tty->c_cc[VMIN] = 2; 
    //seta buad rate
    cfsetispeed(tty, B9600);
    cfsetospeed(tty, B9600);
    return tty;
}

int uart_set(int uart_instance, struct termios *tty){
    
    int rc = tcsetattr(uart_instance, TCSANOW, tty);
    return rc;
}

int uart_init(){
    int port = 0;
    struct termios *tty;

    port = tty_open();
    if(port < 0){
        return -1;
    }
    tty = tty_setup();
    if (tty == NULL){
        return -1;
    }
    int rc = uart_set(port,tty);
    if (rc != 0){
        return -1;
    }
    
    return port;
}




int uart_write(int uart_instance, char *message){

    write(uart_instance,message,sizeof(message));
    return errno;
}

char *uart_read(int uart_instance, char* buf){

    int bytes;
    memset(&buf, '\0', sizeof(buf));
    bytes = read(uart_instance, &buf, sizeof(buf));
    if (bytes <0){
        return NULL;
    }
    return buf;
}


