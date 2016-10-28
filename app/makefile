
CC = gcc
#OPTION = -Wall -g -fPIC
OPTION = -Wall -g -fpic
OPTION1 = -shared
INC = -I${HOME}/sqfc/inc

#src=$(wildcard *.c $HOME/sqfc/app/*.c)
#dir=$(notdir $(src))
#obj=$(patsubst %.c,%.o,$(dir) )
obj = hello.o 


libapp.so:$(obj)
	$(CC) $(OPTION1) $(obj) -o $@
	mv $@ ${HOME}/sqfc/lib

%.o:%.c
	$(CC) -c $(OPTION) $(INC) $< -o $@

clear:
	rm *.o
