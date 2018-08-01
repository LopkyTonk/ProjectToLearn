#pragma once
#include "Game_Map.h"
#include <vector>
class Game_Manager {
private:
	Rabbit** m_rabbitsArray;
	int m_arrCurLength;
	int m_arrLength;

public:
	Game_Manager();
	~Game_Manager();
	void start();
	void addElement(Game_Map&, Rabbit&);
	void addElement(Game_Map&, Rabbit[], int);
	void printStats();
	void printArray();
	void resizeArray();
};

