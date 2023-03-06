SRC:= main.c uartcoms.c

LDFLAGS:= 
CFLAGS:= -o
.PHONY:all clean

all:simloc

simloc: $(SRC)
	$(CC) $(CFLAGS) $@ $^ $(LDFLAGS)

clean:
	rm -rf simloc