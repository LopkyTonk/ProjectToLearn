#include "stdafx.h"
#include "Game_Manager.h"
#include <iostream>
#include <iomanip>
Game_Manager::Game_Manager()
	:m_arrLength(50), m_arrCurLength(0)
{
	delete[] m_rabbitsArray;
	m_rabbitsArray = new Rabbit*[m_arrLength];
}


Game_Manager::~Game_Manager()
{
}
void Game_Manager::start(){
}
void Game_Manager::addElement(Game_Map& map, Rabbit& rabbit) {
	map.addToMap(0,0,rabbit);
	m_rabbitsArray[m_arrCurLength] = &rabbit;
	m_arrCurLength++;
	resizeArray();
}
void Game_Manager::addElement(Game_Map& map, Rabbit rabbits[], int ammount) {
	for (int i = 0; i < ammount; ++i) {
		map.addToMap(rand() % 60, rand() % 60, rabbits[i]);
		m_rabbitsArray[m_arrCurLength] = &rabbits[i];
		m_arrCurLength++;
		resizeArray();
	}
}
void Game_Manager::printArray() {
	for (int i = 0; i < m_arrCurLength; ++i) {
		std::cout << m_rabbitsArray[i] << ' ';
	}
	std::cout << "\n\n";
}
void Game_Manager::resizeArray(){
	int diff(m_arrLength - m_arrCurLength);
	if (diff >= 60)		//reduce
		m_arrLength -= 50;
	else if (diff <= 10) 	//magnify
		m_arrLength += 50;
	else
		return;

	Rabbit** tempArray = new Rabbit*[m_arrLength];
	for (int i = 0; i < m_arrCurLength; ++i) {
		tempArray[i] = m_rabbitsArray[i];
	}
	delete[] m_rabbitsArray;
	m_rabbitsArray = tempArray;
}
void Game_Manager::printStats() {
	int male(0), female(0), radioactive(0), sum(0);
	for (int i= 0; i < m_arrCurLength; i++) {
		Rabbit r = *m_rabbitsArray[i];
		if (r.getGender() && !r.isRadioactive())
			male++;
		else if (!r.getGender() && !r.isRadioactive())
			female++;
		if (r.isRadioactive())
			radioactive++;
	}
	sum = male + female + radioactive;
	std::cout << std::setprecision(3) << "\t\t STATS\n"
		<< "Poppulated: \t" << sum << '\t' << (static_cast<float>(sum) / 3600) * 100 << "%\n"
		<< "Empty: \t\t" << 3600 - sum << '\t' << (static_cast<float>(3600 - sum) / 3600) * 100 << "%\n"
		<< "Males: \t\t" << male << '\t' << (static_cast<float>(male) / sum) * 100 << "%\n"
		<< "Females: \t" << female << '\t' << (static_cast<float>(female) / sum) * 100 << "%\n"
		<< "Radioactive: \t" << radioactive << '\t' << (static_cast<float>(radioactive) / sum) * 100 << "%\n";
}