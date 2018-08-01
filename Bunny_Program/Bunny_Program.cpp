#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include "Game_Manager.h"
int main() {
	clock_t c1(clock());
	//musime initializovat random(), inac nebudu nahodne vysledky
	srand(time(0));
	rand();
	Game_Manager manager;
	Game_Map map;
	const int x = rand() % 3600;
	Rabbit rabbits[3600];
	Rabbit* rab;
	for (int i = 0; i < x; ++i) {
		rabbits[i] = Rabbit::getRandomRabbit();
		if (rabbits[i].isRadioactive())
			rab = &rabbits[i];
	}
	manager.addElement(map, rabbits, x);
	map.printMap();
	manager.printStats();
	Rabbit** rabbbb = map.getSpace(*rab);
	map.printSpace(rabbbb);
	map.findElement(*rab);
	std::cout << "\n\n\n\nTotal time : " << (clock() - c1) / CLOCKS_PER_SEC << "\n\n";
    return 0;
}