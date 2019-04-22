
OBJ = app.o main.o Actor.o Cell.o Continent.o EmptyCell.o Environment.o Human.o RandomGenerator.o Resource.o Zombie.o Trap.o  Obstacle.o   

EXE = Zombi_Simulation
CC = g++
LFLAGS  = $(shell wx-config --libs all) 
CFLAGS  = -c $(shell wx-config --cxxflags) 
all:game

game:	$(OBJ)
	$(CC) $(OBJ) $(LFLAGS) -o $(EXE) 

app.o:	Zombi_SimulationApp.cpp Zombi_SimulationApp.h
	$(CC) $(CFLAGS) Zombi_SimulationApp.cpp -o app.o

main.o: Zombi_SimulationMain.cpp Zombi_SimulationMain.h
	$(CC) $(CFLAGS) Zombi_SimulationMain.cpp -o main.o  

Actor.o: Actor.cpp Actor.h Utils.h
	$(CC) $(CFLAGS) Actor.cpp -o Actor.o  

Cell.o: Cell.cpp Cell.h
	$(CC) $(CFLAGS) Cell.cpp -o Cell.o

Continent.o: Continent.cpp Continent.h
	$(CC) $(CFLAGS) Continent.cpp -o Continent.o

EmptyCell.o: EmptyCell.cpp EmptyCell.h
	$(CC) $(CFLAGS) EmptyCell.cpp -o EmptyCell.o

Environment.o: Environment.cpp Environment.h
	$(CC) $(CFLAGS) Environment.cpp -o Environment.o

Human.o: Human.cpp Human.h
	$(CC) $(CFLAGS) Human.cpp -o Human.o

Obstacle.o: Obstacle.cpp Obstacle.h
	$(CC) $(CFLAGS) Obstacle.cpp -o Obstacle.o

RandomGenerator.o: RandomGenerator.cpp RandomGenerator.h
	$(CC) $(CFLAGS) RandomGenerator.cpp -o RandomGenerator.o

Resource.o: Resource.cpp Resource.h
	$(CC) $(CFLAGS) Resource.cpp -o Resource.o

Trap.o: Trap.cpp Trap.h
	$(CC) $(CFLAGS) Trap.cpp -o Trap.o

Zombie.o: Zombie.cpp Zombie.h
	$(CC) $(CFLAGS) Zombie.cpp -o Zombie.o

