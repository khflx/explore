VPATH   = ../wrapper:../unit:../libfree

CFLAGS = -c -g
bin = ../bin
daytimecli = daytimetcpcli.o Socket.o error.o
daytimesrvl = daytimetcpsrvl.o Socket.o error.o

cli: $(daytimecli)
	gcc -g $(daytimecli) -o $(bin)/daytimecli
srvl: $(daytimesrvl)
	gcc -Wall -pedantic -g $(daytimesrvl) -o $(bin)/daytimesrvl
Socket.o: Socket.c Socket.h
error.o: error.c error.h
daytimetcpcli.o: daytimetcpcli.c
daytimetcpsrvl.o: daytimetcpsrvl.c

clean:
	rm -rf $(bin)/daytime*;\
	rm -rf ./*.o
