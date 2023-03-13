INC := -I include
STD := -std=c++11
SFML := -lsfml-graphics -lsfml-window -lsfml-system

all: compile link

fresh: dirs compile link

compile:
	g++ $(INC) $(STD) -c -o build/main.o src/main.cpp
	g++ $(INC) $(STD) -c -o build/Common.o src/Common.cpp
	g++ $(INC) $(STD) -c -o build/GameState.o src/GameState.cpp
	g++ $(INC) $(STD) -c -o build/Snake.o src/Snake.cpp
	g++ $(INC) $(STD) -c -o build/SnakeFood.o src/SnakeFood.cpp

dirs:
	mkdir bin build

link:
	g++ build/*.o -o bin/SnakePlusPlus $(SFML)

clean:
	rm bin/*.o build/*.out