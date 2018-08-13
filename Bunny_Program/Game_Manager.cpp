#include "stdafx.h"
#include "Game_Manager.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <algorithm>
Game_Manager::Game_Manager()
{
}


Game_Manager::~Game_Manager()
{
}
void Game_Manager::start(Game_Map& map){
	Rabbit rabbits[5];
	for (int i = 0; i < 5; ++i) {
		rabbits[i] = Rabbit::getRandomRabbit();
		map.addToMap(rand() % 60,i*i*((rand()%2)+1) ,rabbits[i]);
	}
}
void Game_Manager::nextRound(Game_Map& map) {
	map.doRound();
	map.printMap();
	std::cout << "\n\n\n";
}
void Game_Manager::printStats() {
/*	int male(m_male.size()), female(m_female.size()), radioactive(m_radioactive.size());
	int sum (male + female + radioactive);
	std::cout << std::setprecision(3) << "\t\t STATS\n"
		<< "Populated: \t" << sum << '\t' << (static_cast<double>(sum) / 3600) * 100 << "%\n"
		<< "Empty: \t\t" << 3600 - sum << '\t' << (static_cast<double>(3600 - sum) / 3600) * 100 << "%\n"
		<< "Males: \t\t" << male << '\t' << (static_cast<double>(male) / sum) * 100 << "%\n"
		<< "Females: \t" << female << '\t' << (static_cast<double>(female) / sum) * 100 << "%\n"
		<< "Radioactive: \t" << radioactive << '\t' << (static_cast<double>(radioactive) / sum) * 100 << "%\n";*/
}
