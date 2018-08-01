#include "stdafx.h"
#include "Game_Map.h"
#include <iostream>
#include <vector>
#include <cassert>

Game_Map::Game_Map()
	:m_dimensions(10)
{
	for (int i = 0; i < m_dimensions; ++i) {
		for (int j = 0; j < m_dimensions; ++j) {
			m_gameMap[i][j] = Rabbit();
			m_mapPtr[i][j] = &(m_gameMap[i][j]);
		}
	}
}


Game_Map::~Game_Map(){
}
Game_Map& Game_Map::addToMap(short x, short y, Rabbit &rabbit) {
	if (x < m_dimensions && y < m_dimensions) {
		rabbit.setCoordinates(x, y);
		m_gameMap[x][y] = rabbit;
	}
	return *this;
}
Game_Map& Game_Map::printMap() {
	for (int i = 0; i < m_dimensions; ++i) {
		for (int j = 0; j < m_dimensions; ++j) {
			if (m_mapPtr[i][j]->isEmpty())
				std::cout << "- ";
			else {
				std::cout << *m_mapPtr[i][j] << ' ';
			}
		}
		std::cout << '\n';
	}
	return *this;
}
void Game_Map::findElement(const Rabbit& r) {
	for (int i = 0; i < m_dimensions; ++i)
		for (int j = 0; j < m_dimensions; ++j)
			if (r == m_gameMap[i][j])
				std::cout << '(' << i + 1 << ',' << j + 1 << ")\n";
}
Rabbit** Game_Map::getSpace(Rabbit& r) {
	Rabbit** rabbits = new Rabbit*[9];
	int count(0);			//abu sme dostali	0 - -
	int x(r.get_X() - 1);	//					- - -
	int y(r.get_Y() - 1);	//					- - -
	for (int iii = x;  iii < x + 3; ++iii) {
		for (int jjj = y; jjj < y + 3; ++jjj) {
			if (iii >= m_dimensions || jjj >= m_dimensions || iii < 0 || jjj < 0)
				rabbits[count] = nullptr;
			else
				rabbits[count] = m_mapPtr[iii][jjj];
			++count;
		}
	}
	return rabbits;
}
Game_Map& Game_Map::printSpace(Rabbit** r) {
	int count(0);
	for (int i = 0; i < 9; ++i) {
		if (i == 3 || i == 6)
			std::cout << '\n';
		if (r[i]) {
			if(r[i]->isEmpty())
				std::cout << "- ";
			else
				std::cout << *r[i] << ' ';
		}
		else
			std::cout << "0 ";
	}
	std::cout << "\nfinished1\n";
	return *this;
}


