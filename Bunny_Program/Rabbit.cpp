#include "stdafx.h"
#include "Rabbit.h"

//static definition
static int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
																				 // evenly distribute the random number across our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

const std::string Rabbit::rabbitNames[][Rabbit::nameLength] = {
	{ "Charlie" ,"Peanut", "Jack", "Rocky", "Gizmo", "Toby ", "Oliver", "Oreo", "Pepper", "Jake", "Bear", "Dexter", "Snickers", "Romeo", "Sam" },
{ "Bella" ,"Molly", "Daisy", "Chloe", "Lily", "Harley ", "Luna", "Baby", "Zoe", "Missy", "Mia", "Kitty", "Abby", "Juliet", "Murphy" },
{ "Joker" ,"Darth Maul", "Voldemort", "Magneto", "Johnny", "Terminator ", "Sauron", "Michael Meyers", "Loki", "Bane", "Alien", "Darth Vader", "Davy Jones", "Khan", "Thanos" }
};

Rabbit Rabbit::getRandomRabbit() {
	std::string name, color;
	bool gender, isRadioactive;
	int age(0);

	gender = rand() % 2;
	isRadioactive = rand() % 101 < 2;

	name = rabbitNames[(isRadioactive ? 2 : gender)][rand() % nameLength];
	color = rabbitColor[rand() % colorLength];
	return Rabbit(name, color, age, gender, isRadioactive);
}

const std::string Rabbit::rabbitColor[Rabbit::colorLength] = {
	 "black" ,"white", "brown", "spotted", "grey"
};

Rabbit::Rabbit()
	:m_name(""), m_color(""), m_age(0), m_gender(0), m_isRadioactiveMutant(0)
{
}
Rabbit::Rabbit(std::string name, std::string color, int age, bool gender, bool isRadioactive)
	:m_name(name), m_color(color), m_age(age), m_gender(gender), m_isRadioactiveMutant(isRadioactive)
{
}
Rabbit::Rabbit(const Rabbit& rab)
	: m_name(rab.m_name), m_color(rab.m_color), m_age(rab.m_age), m_gender(rab.m_gender), m_isRadioactiveMutant(rab.m_isRadioactiveMutant)
{
}
/*
std::ostream& operator <<(std::ostream& out, Rabbit& rabbit){
	out << rabbit.m_name << " of color " << rabbit.m_color << " is " << (rabbit.m_gender ? "female" : "male")
		<< ", " << rabbit.m_age << " years old and " << (rabbit.m_isRadioactiveMutant ? "is" : "isn't") << " radioactive.\n";
	return out;
}*/
std::ostream& operator <<(std::ostream& out, Rabbit& rabbit) {
	char c;
	if (rabbit.m_gender)
		c = 'm';
	else
		c = 'f';
	if (rabbit.m_age >= 2)
		c = toupper(c);
	out << c;
	return out;
}
bool operator ==(const Rabbit& r1, const Rabbit& r2) {
	return (r1.m_name == r2.m_name &&
		r1.m_color == r2.m_color &&
		r1.m_age == r2.m_age&&
		r1.m_gender == r2.m_gender&&
		r1.m_isRadioactiveMutant == r2.m_isRadioactiveMutant);
}
void Rabbit::operator =(const Rabbit& r) {
	this->m_name = r.m_name;
	this->m_color = r.m_color;
	this->m_age = r.m_age;
	this->m_gender = r.m_gender;
	this->m_isRadioactiveMutant = r.m_isRadioactiveMutant;
}
Rabbit::~Rabbit()
{
}

void Rabbit::printRabbit(){

}

