#include "stdafx.h"
#include "Game_Map.h"
#include <iostream>

Game_Map::Game_Map()
	:m_dimensions(60)
{
	for (int i = 0; i < m_dimensions; ++i) {
		for (int j = 0; j < m_dimensions; ++j) {
			m_gameMap[i][j] = Rabbit();
			ptr[i][j] = &(m_gameMap[i][j]);
		}
	}
}


Game_Map::~Game_Map(){
}
Game_Map& Game_Map::addToMap(short x, short y, Rabbit &rabbit) {
	if (x < m_dimensions && y < m_dimensions) {
		m_gameMap[x][y] = rabbit;
		rabbit.setCoordinates(x, y);
	}
	return *this;

}
Game_Map& Game_Map::printMap() {
	for (int i = 0; i < m_dimensions; ++i) {
		for (int j = 0; j < m_dimensions; ++j) {
			if (ptr[i][j]->isEmpty())
				std::cout << '0' << ' ';
			else
				std::cout << *ptr[i][j] << ' ';
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
int** Game_Map::getSpace(Rabbit& r) {
	int** space = new int*[9];
	int x(r.get_X()), y(r.get_Y());
	for (int i = 0;  i < 9; ++i) {
		space[i] = new int[2];
		for (int y = 0; y < 2; ++y) {
			//space[i][y] = 
		}
	}
}

