CC=gcc

COPTS =-c -O3 -W -Wall -Werror -g -DEBUG

TARGET=line

OBJS=main.o tools.o algo_line.o

all : $(TARGET)
	echo : "Compilation finish"

$(TARGET) : $(OBJS)
	$(CC) $(OBJS) -L/mingw32/lib -o $(TARGET) -lmingw32 -lSDLmain -lSDL

main.o : main.c tools.h algo_line.h
	$(CC) $(COPTS) main.c

tools.o: tools.c tools.h algo_line.h
	$(CC) $(COPTS) tools.c

algo_line.o : algo_line.c algo_line.h tools.h
	$(CC) $(COPTS) algo_line.c

clean :
	del -f *.o *~ *.stackdump *.exe 