CC=cc
CLAGS=-Os -Wall -g -std=gnu99
SOURCES=$(wildcard *.c)
OBJS=$(SOURCES:.c=.o)
BINARY=CANcontrol

all: $(OBJS)
	$(CC) $(CFLAGS) -o $(BINARY) $(OBJS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@ 

clean:
	rm -fr $(OBJS) $(BINARY)


#CANcontrol: CANcontrol.o crc.o cmds.o ring_buffer.o
#	cc CANcontrol.o crc.o cmds.o ring_buffer.o -o CANcontrol
#
#CANcontrol.o: CANcontrol.c
#	cc -c CANcontrol.c

#crc.o: crc.c
#	cc -c crc.c

#cmds.o: cmds.c
#	cc -c cmds.c

#ring_buffer.o: ring_buffer.c
#	cc -c ring_buffer.c

#clean: 
#	rm -rf *o CANcontrol

