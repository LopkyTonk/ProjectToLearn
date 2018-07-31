#pragma once
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
	int m_coordinate_x, m_coordinate_y;
	bool m_gender;
	bool m_isRadioactiveMutant;

public:
	static Rabbit getRandomRabbit();
	Rabbit();				//default constructor
	Rabbit(const Rabbit& rab);	//copy consttructor
	Rabbit(std::string, std::string, int, bool, bool);
	~Rabbit();

	friend std::ostream& operator <<(std::ostream&, Rabbit&);
	friend bool operator ==(const Rabbit&, const Rabbit&);
	void operator =(const Rabbit&);
	bool isRadioactive() { return m_isRadioactiveMutant; }
	bool isEmpty() { return m_name == ""; }
	void setCoordinates(int x, int y) { m_coordinate_x = x; m_coordinate_y = y; }
	int get_X() { return m_coordinate_x; }
	int get_Y() { return m_coordinate_y; }
	void printRabbit();
};

