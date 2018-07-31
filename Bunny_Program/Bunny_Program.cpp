#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include "Game_Map.h"

int main() {
	clock_t c1(clock());
	//musime initializovat random(), inac nebudu nahodne vysledky
	srand(time(0));
	rand();
	Game_Map map;
	Rabbit rab = Rabbit::getRandomRabbit();
	map.addToMap(rand() % 60,rand() % 60, rab).printMap().getSpace(rab);
	std::cout << "\n\n\n\nTotal time : " << (clock() - c1) / CLOCKS_PER_SEC << "\n\n";
    return 0;
}

