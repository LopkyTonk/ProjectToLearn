#pragma once
#ifndef RABBIT
#define RABBIT
#include <string>

class Rabbit {
private:
	static const int nameLength = 15;
	static const int colorLength = 5;
	static const std::string rabbitNames[3][nameLength];	// 3, lebo dve pohlavia a 1 radioaktivny, druhy parameter je pohlavie (0/1)
	static const std::string rabbitColor[colorLength];	// prvy riadok su male, druhy su female, treti su radioaktivny

	std::string m_name;
	std::string m_color;
	int m_age;
	int m_generation;
	int m_x, m_y;
	bool m_gender;
	bool m_isRadioactiveMutant;
	bool m_isEmpty;

public:
	static Rabbit getRandomRabbit();
	Rabbit();				//default constructor
	Rabbit(const Rabbit& rab);	//copy consttructor
	Rabbit(std::string, std::string, int, int, bool, bool);
	~Rabbit();

	friend std::ostream& operator <<(std::ostream&, Rabbit&);
	friend bool operator ==(const Rabbit&, const Rabbit&);
	friend bool operator !=(const Rabbit&, const Rabbit&);
	/*const bool operator <=(const Rabbit&);
	const bool operator >=(const Rabbit&);*/
	const bool operator <(const Rabbit&);
	const bool operator >(const Rabbit&);
	void operator =(const Rabbit&);
	void operator %(Rabbit&);	//swapCoordinates
	Rabbit reproduce();
	bool isRadioactive() { return m_isRadioactiveMutant; }
	bool isEmpty() { return m_isEmpty; }
	bool getGender() { return m_gender; }	//0 je male, 1 je female
	int get_X() const { return m_x; }
	int get_Y() const { return m_y; }
	int getAge() const { return m_age; }
	void makeRadioactive() { m_isRadioactiveMutant = true; }
	void move(int x, int y);
	void age();
	void emptyRabbit();
	void printRabbit();
};
#endif //!RABBIT

