#include "stdafx.h"
#include "Game_Map.h"
#include <iostream>
#include <algorithm>
Game_Map::Game_Map()
	:m_dimensions(60)
{
	for (int i = 0; i < m_dimensions; ++i) {
		for (int j = 0; j < m_dimensions; ++j) {
			m_gameMap[i][j] = Rabbit();
			m_gameMap[i][j].emptyRabbit();
			m_gameMap[i][j].move(i, j);
		}
	}
}

Game_Map::~Game_Map(){
}
Game_Map& Game_Map::addToMap(short x, short y, Rabbit &rabbit) {
	m_gameMap[x][y] = rabbit;
	m_gameMap[x][y].move(x, y);
	std::cout << "\n\n\n";
	m_rabbitsArray.push_back(&m_gameMap[x][y]);
	addToGroup(m_rabbitsArray.back());
	return *this;
}
Game_Map& Game_Map::removeFromMap(Rabbit &rabbit) {
	int position(0);
	for (; position < m_rabbitsArray.size(); ++position) {
		if (m_rabbitsArray[position] == &rabbit)
			break;
	}
	m_rabbitsArray[position]->emptyRabbit();
	return *this;
}
Game_Map& Game_Map::printArray() {
	for (int i = 0; i < m_rabbitsArray.size(); ++i)
		if (m_rabbitsArray[i]->isEmpty())
			throw;
	return *this;
}
Game_Map& Game_Map::printMap() {
	for (int i = 0; i < m_dimensions; ++i) {
		for (int j = 0; j < m_dimensions; ++j) {
			if (m_gameMap[i][j].isEmpty())
				std::cout << "- ";
			else {
				std::cout << m_gameMap[i][j] << ' ';
			}
		}
		std::cout << '\n';
	}
	return *this;
}
std::vector<Rabbit*> Game_Map::getSpace(const Rabbit& r) {
	std::vector<Rabbit*> rabbits(9);
	int count(0);					//abu sme dostali	0 - -
	int x(r.get_X() - 1);			//					- - -
	int y(r.get_Y() - 1);			//					- - -
	for (int iii = x;  iii < x + 3; ++iii) {
		for (int jjj = y; jjj < y + 3; ++jjj) {
			if (iii >= m_dimensions || jjj >= m_dimensions || iii < 0 || jjj < 0)
				rabbits[count] = nullptr;
			else
				rabbits[count] = &m_gameMap[iii][jjj];
			++count;
		}
	}
	return rabbits;
}
Rabbit* Game_Map::getRandomSpace(const Rabbit& r) {
	for (int rabbitCount = 0; rabbitCount < m_rabbitsArray.size(); ++rabbitCount) {
		std::vector<Rabbit*> space = getSpace(*m_rabbitsArray[rabbitCount]);

		int randomPosition[10]{ 0,1,2,3,4,5,6,7,8,9 };
		std::random_shuffle(&randomPosition[0], &randomPosition[9]);
		for (int j = 0; j < 9; ++j) {
			int curNum(randomPosition[j]);
			if (!space[curNum])
				continue;
			if (space[j] != m_rabbitsArray[rabbitCount] && space[curNum]->isEmpty()) {
				return space[j];
			}
		}
	}
	return nullptr;
}
void Game_Map::moveRabbit(Rabbit& rabbit) {
	Rabbit* toMove(getRandomSpace(rabbit));
	int position(0);
	for (; position < m_rabbitsArray.size(); ++position) {
		if (m_rabbitsArray[position] == &rabbit)
			break;
	}
	if (toMove) {
		std::swap(rabbit, *toMove);
		rabbit % *toMove;	// swap postions
		m_rabbitsArray[position] = toMove;	// change pointer
	}
}
void Game_Map::addToGroup(Rabbit* rabbit) {
	if ((rabbit)->isRadioactive()) {
		m_radioactive.push_back(&rabbit);
	}
	else if ((rabbit)->getGender()) {
		m_female.push_back(&rabbit);;
	}
	else {
		m_male.push_back(&rabbit);
	}
}
Game_Map& Game_Map::doRound() {
	bool canBreed(false);
	Rabbit* curRabbit;
	for (int i = 0; i < m_male.size(); ++i) {
		curRabbit = *m_male[i];
		if ((curRabbit->getAge()) > 10) {
			removeFromMap(*curRabbit);
			continue;
		}
		if ( (curRabbit->getAge()) >= 2 && !canBreed)
			canBreed = true;
		(curRabbit)->age();
		moveRabbit(*curRabbit);
	}
	for (int i = 0; i < m_female.size(); ++i) {
		curRabbit = *m_female[i];
		if ((curRabbit->getAge()) > 10) {
			removeFromMap(*curRabbit);
			continue;
		}
		if ((curRabbit->getAge()) >= 2 && canBreed) {
			Rabbit* placeToBorn(getRandomSpace(*curRabbit));
			if (placeToBorn) {	//no nullptr
				Rabbit newRabbit = curRabbit->reproduce();
				addToMap(placeToBorn->get_X(), placeToBorn->get_Y(), newRabbit);
			}
		}
		curRabbit->age();
		moveRabbit(*curRabbit);
	}
	//radioactive
	for (int i = 0; i < m_radioactive.size(); ++i) {
		curRabbit = *m_radioactive[i];
		if ((curRabbit->getAge()) > 50) {
			removeFromMap(*curRabbit);
			continue;
		}
		Rabbit* rabbitToMutate(getRandomSpace(*curRabbit));
		if (rabbitToMutate) {	//no nullptr
			rabbitToMutate->makeRadioactive();
			int position(0);
			for (; position < m_rabbitsArray.size(); ++position) {
				if (m_rabbitsArray[position] == rabbitToMutate) {
					addToGroup(m_rabbitsArray[position]);
					break;
				}
			}
		}
		curRabbit->age();
		moveRabbit(*curRabbit);
	}
	updateGroups();
	return *this;
}
void Game_Map::updateGroups() {
	Rabbit* curRabbit;
	//male
	for (int i = 0; i < m_male.size(); ++i) {
		curRabbit = *m_male[i];
		if (curRabbit->isRadioactive() || curRabbit->isEmpty()) {
			m_male.erase(m_male.begin() + i);
		}
	}
	std::sort(m_male.begin(), m_male.end());
	//female
	for (int i = 0; i < m_female.size(); ++i) {
		curRabbit = *m_female[i];
		if (curRabbit->isRadioactive() || curRabbit->isEmpty());
	}
	std::sort(m_female.begin(), m_female.end());
	//radioactive
	for (int i = 0; i < m_radioactive.size(); ++i) {
		curRabbit = *m_radioactive[i];
		if (curRabbit->isEmpty())
			m_radioactive.erase(m_male.begin() + i);
	}
	std::sort(m_female.begin(), m_female.end());
}
void Game_Map::iterate() {
	int count(0);
	for (int i = 0; i < m_dimensions; ++i) {
		for (int j = 0; j < m_dimensions; ++j) {
			if (!m_gameMap[i][j].isEmpty())
				++count;
		}
	}
	std::cout << "There are " << count << " rabbits\n";
}
void Game_Map::updateVectors() {
	m_male.clear();
	m_female.clear();
	m_radioactive.clear();
	for (auto obj : m_rabbitsArray) {
		addToGroup(obj);
	}
}
