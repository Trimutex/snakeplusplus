INC := -I include
STD := -std=c++11
SFML := -lsfml-graphics -lsfml-window -lsfml-system

all: compile link

fresh: dirs compile link

compile:
	g++ $(INC) $(STD) -c -o build/main.o src/main.cpp
	g++ $(INC) $(STD) -c -o build/common.o src/common.cpp
	g++ $(INC) $(STD) -c -o build/display.o src/display.cpp
	g++ $(INC) $(STD) -c -o build/game.o src/game.cpp
	g++ $(INC) $(STD) -c -o build/gamestate.o src/gamestate.cpp
	g++ $(INC) $(STD) -c -o build/snake.o src/snake.cpp
	g++ $(INC) $(STD) -c -o build/snakefood.o src/snakefood.cpp

dirs:
	mkdir bin build

link:
	g++ build/*.o -o bin/SnakePlusPlus $(SFML)

clean:
	rm bin/*.o build/*.out