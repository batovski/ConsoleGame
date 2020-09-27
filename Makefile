CC=g++ -g -std=c++11
exe_file=prog

$(exe_file): prog.cpp Event.o Pits.o Wampus.o Bat.o Gold.o Game.o Room.o Player.o
	$(CC) prog.cpp Event.o Pits.o Wampus.o Bat.o Gold.o Game.o Room.o Player.o -o $(exe_file) 

Event.o: Event.cpp Event.h
	$(CC) -c Event.cpp 

Pits.o: Pits.cpp Pits.h
	$(CC) -c Pits.cpp 

Wampus.o: Wampus.cpp Wampus.h
	$(CC) -c Wampus.cpp

Bat.o: Bat.cpp Bat.h
	$(CC) -c Bat.cpp

Gold.o: Gold.cpp Gold.h
	$(CC) -c Gold.cpp
	
Game.o: Game.cpp Game.h
	$(CC) -c Game.cpp

Room.o: Room.cpp Room.h
	$(CC) -c Room.cpp

Player.o: Player.cpp Player.h
	$(CC) -c Player.cpp

clean: 
	rm -f *.o $(exe_file)
