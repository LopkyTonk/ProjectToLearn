#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include "Rabbit.h"
int main() {
	clock_t c1(static_cast<double>(clock()));
	//musime initializovat random(), inac nebudu nahodne vysledky
	srand(time(0));
	rand();
	Rabbit rab(Rabbit::getRandomRabbit());
	std::cout << "Moj zajac je: " << rab;
	std::cout << "\n\n\n\nTotal time : " << (static_cast<double>(clock()) - c1) / CLOCKS_PER_SEC << "\n\n";
    return 0;
}

