#pragma once
#include <string>

class Rabbit {
private:
	static const int nameLength = 15;
	static const int colorLength = 5;
	static const std::string rabbitNames[3][nameLength];	// 3, lebo dve pohlavia a 1 radioaktivny, druhy parameter je pohlavie (0/1)
	static const std::string rabbitColor[colorLength];	// prvy riadok su male, druhy su female, treti su radioaktivny

	std::string m_name;
	const std::string m_color;
	int m_age;
	const bool m_gender;
	bool m_isRadioactiveMutant;

public:
	static Rabbit getRandomRabbit();

	//Rabbit(); nie je potrebny				//default constructor
	Rabbit(const Rabbit& rab);	//copy consttructor
	Rabbit(std::string, std::string, int, bool, bool);
	~Rabbit();

	friend std::ostream& operator <<(std::ostream&, Rabbit&);
	bool isRadioactive() { return m_isRadioactiveMutant; }
	void printRabbit();
};

