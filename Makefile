INC := -I include
STD := -std=c++11
SFML := -lsfml-graphics -lsfml-window -lsfml-system

all: compile link

fresh: dirs compile link

compile:
	g++ $(INC) $(STD) -c -o build/main.o src/main.cpp
	g++ $(INC) $(STD) -c -o build/playerinterface.o src/playerinterface.cpp
	g++ $(INC) $(STD) -c -o build/gamestate.o src/gamestate.cpp
	g++ $(INC) $(STD) -c -o build/snake.o src/snake.cpp

dirs:
	mkdir bin build

link:
	g++ build/*.o -o bin/SnakePlusPlus.out $(SFML)

clean:
	rm bin/*.out build/*.o
