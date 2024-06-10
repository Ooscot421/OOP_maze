all: brave_tour
.PHONY: clean
CC = g++
FLAGS = -std=c++11 -g

brave_tour: main.o maze.o block.o player.o wall.o empty.o goal.o
	$(CC) $(FLAGS) main.o maze.o block.o player.o wall.o empty.o goal.o -o brave_tour

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -c

maze.o: maze.cpp maze.h
	$(CC) $(FLAGS) maze.cpp -c
 
block.o: block.cpp block.h
	$(CC) $(FLAGS) block.cpp -c
 
player.o: player.cpp player.h
	$(CC) $(FLAGS) player.cpp -c

wall.o: wall.cpp wall.h
	$(CC) $(FLAGS) wall.cpp -c
 
empty.o: empty.cpp empty.h
	$(CC) $(FLAGS) empty.cpp -c

goal.o: goal.cpp goal.h
	$(CC) $(FLAGS) goal.cpp -c

clean:
	rm -rf *.o
