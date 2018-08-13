#pragma once
#ifndef GAME_MANAGER
#define GAME_MANAGER

#include "Game_Map.h"
#include <vector>
class Game_Manager {
private:

public:
	Game_Manager();
	~Game_Manager();
	void start(Game_Map&);
	void nextRound(Game_Map&);
	void printStats();
};
#endif // !GAME_MANAGER
