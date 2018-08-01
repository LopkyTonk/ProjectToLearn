#pragma once
#include "Rabbit.h"

class Game_Map{
private:
	const short m_dimensions = 60;
	Rabbit m_gameMap[60][60];
	Rabbit *m_mapPtr[60][60];
public:
	Game_Map();
	~Game_Map();
	Game_Map& addToMap(short, short, Rabbit &);
	Game_Map& printMap();
	Game_Map& printSpace(Rabbit**);
	void findElement(const Rabbit&);
	Rabbit** getSpace(Rabbit&);
};

