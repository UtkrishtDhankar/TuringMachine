OBJS = TuringMachine.o Card.o Instruction.o main.o
CC = g++
DEBUG = -g
CFLAGS = -std=c++11 -Wall -c
LFLAGS = -std=c++11 -Wall

tm : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o tm

Instruction.o :
	$(CC) $(CFLAGS) Instruction.cpp

Card.o :
	$(CC) $(CFLAGS) Card.cpp

TuringMachine.o :
	$(CC) $(CFLAGS) TuringMachine.cpp

main.o :
	$(CC) $(CFLAGS) main.cpp

debug: CFLAGS+=$(DEBUG)
debug: LFLAGS+=$(DEBUG)
debug: tm

clean:
	-@rm *.o *~ tm 2>/dev/null || true
