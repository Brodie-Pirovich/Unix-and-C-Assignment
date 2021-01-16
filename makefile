CC=gcc
CFLAGS=-Wall -g
OBJ=Main.o Menu.o LinkedList.o Game.o
EXEC=test_assignment

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o: Main.c Menu.h LinkedList.h
	$(CC) $(CFLAGS) -c Main.c Menu.h LinkedList.h

menu.o: Menu.c Menu.h LinkedList.h Game.h
	$(CC) $(CFLAGS) -c Menu.c Menu.h LinkedList.h Game.h

LinkedList.o: LinkedList.c 
	$(CC) $(CFLAGS) -c LinkedList.c 

Game.o: Game.c
	$(CC) $(CFLAGS) -c Game.c

clean :
	rm -f $(EXEC) $(OBJ)