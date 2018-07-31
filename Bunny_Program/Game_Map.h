#pragma once
#include "Rabbit.h"

class Game_Map{
private:
	const short m_dimensions = 60;
	Rabbit m_gameMap[60][60];
	Rabbit *ptr[60][60];
public:
	Game_Map();
	~Game_Map();
	Game_Map& addToMap(short, short, Rabbit &);
	Game_Map& printMap();
	void findElement(const Rabbit&);
	int** getSpace(Rabbit&);
};

