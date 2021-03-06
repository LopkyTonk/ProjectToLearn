#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include "Game_Manager.h"

int main() {
	clock_t c1(clock());
	srand(time(0));
	rand();
	Game_Map map;
	Game_Manager manager;
	int i(0);
	manager.start(map);
	map.updateVectors();
	while (true) {
		if (i == 13)
			break;
		manager.nextRound(map);
		i++;
	}
	std::cout << "\n\n\n\nTotal time : " << (clock() - static_cast<double>(c1)) / CLOCKS_PER_SEC << "\n\n";
    return 0;
}