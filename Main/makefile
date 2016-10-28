
CC = gcc
OPT = -Wall -g


INC = -I${HOME}/sqfc/inc/ \
      -I/usr/include/mysql  
LIB = -L${HOME}/sqfc/lib -lapp \
			 -lmysql \
      -L/usr/lib64/mysql/ -lmysqlclient  \
                          -lz 

all:
	$(CC) $(OPT)  main.c -o main $(INC) $(LIB)
clear:
	rm main core.*
