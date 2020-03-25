CC=gcc
CFLAGS=-Wall -Wextra -g
LIBS= -lm

FILES=data.c liste.c learn.c premier_tp.c 
HEADER = data.h liste.h learn.h
FILESOBJ=$(FILES:.c=.o)


output: $(FILESOBJ) $(HEADER)
		$(CC) $(CFLAGS) $(FILESOBJ) -o $@ $(LIBS)
	

%.o:	%.c
		$(CC) $(CFLAGS) -c $<

clean	:
		rm -rf *.o *.out output