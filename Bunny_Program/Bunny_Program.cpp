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
	Rabbit**rabb;
	for (int i = 0; i < 5; ++i) {
		Rabbit rab = Rabbit::getRandomRabbit();
		map.addToMap(9, rand() % 9, rab);
		std::cout << '\n';
		rabb = map.getSpace(rab);
		map.printSpace(rabb);
	}
	map.printMap();
	std::cout << "\n\n\n\nTotal time : " << (clock() - c1) / CLOCKS_PER_SEC << "\n\n";
    return 0;
}