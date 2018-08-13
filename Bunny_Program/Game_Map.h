#pragma once
#ifndef GAME_MAP
#define GAME_MAP

#include "Rabbit.h"
#include <vector>
#include <iostream>
class Game_Map {
private:
	const short m_dimensions = 60;
	Rabbit m_gameMap[60][60];
	std::vector<Rabbit*> m_rabbitsArray;
	std::vector<Rabbit**> m_male;
	std::vector<Rabbit**> m_female;
	std::vector<Rabbit**> m_radioactive;
public:
	Game_Map();
	~Game_Map();
	Game_Map& addToMap(short, short, Rabbit &);
	Game_Map& removeFromMap(Rabbit &);
	Game_Map& printMap();
	Game_Map& printArray();
	Game_Map& doRound();
	std::vector<Rabbit*> getSpace(const Rabbit&);
	Rabbit* getRandomSpace(const Rabbit&);
	void moveRabbit(Rabbit&);
	void addToGroup(Rabbit*);
	void updateGroups();
	void updateVectors();
	void iterate();
};
#endif // !GAME_MAP

