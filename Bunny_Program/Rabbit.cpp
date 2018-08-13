#include "stdafx.h"
#include "Rabbit.h"
#include <iostream>
#include <algorithm>
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

const std::string Rabbit::rabbitColor[Rabbit::colorLength] = {
	 "black" ,"white", "brown", "spotted", "grey"
};
Rabbit Rabbit::getRandomRabbit() {
	std::string name, color;
	bool gender, isRadioactive;
	int age(0);

	gender = rand()%2;
	isRadioactive = rand() % 101 < 2;

	name = rabbitNames[(isRadioactive ? 2 : gender)][rand() % nameLength];
	color = rabbitColor[rand() % colorLength];
	return Rabbit(name, color, age, 1, gender, isRadioactive);
}

Rabbit::Rabbit(){
	this->emptyRabbit();
}
Rabbit::Rabbit(std::string name, std::string color, int age,int generation, bool gender, bool isRadioactive)
	:m_name(name), m_color(color), m_age(age), m_generation(generation), m_gender(gender), m_isRadioactiveMutant(isRadioactive),m_isEmpty(0)
{
	this->move(0, 0);
}
Rabbit::Rabbit(const Rabbit& rab)
	: m_name(rab.m_name), m_color(rab.m_color), m_age(rab.m_age), m_generation(rab.m_generation), m_gender(rab.m_gender), m_isRadioactiveMutant(rab.m_isRadioactiveMutant),m_isEmpty(0)
{
	this->move(rab.m_x, rab.m_y);
}
std::ostream& operator <<(std::ostream& out, Rabbit& rabbit) {
	char c;
	if (rabbit.isRadioactive())
		c = 'x';
	else if(rabbit.m_gender)
		c = 'f';
	else
		c = 'm';
	if (rabbit.m_age >= 2)
		c = toupper(c);
	out << c;
	return out;
}
bool operator ==(const Rabbit& r1, const Rabbit& r2) {
	return (r1.m_name == r2.m_name &&
		r1.m_color == r2.m_color &&
		r1.m_age == r2.m_age &&
		r1.m_gender == r2.m_gender &&
		r1.m_isRadioactiveMutant == r2.m_isRadioactiveMutant);
}
bool operator !=(const Rabbit& r1, const Rabbit& r2) {
	return (r1.m_name != r2.m_name ||
		r1.m_color != r2.m_color ||
		r1.m_age != r2.m_age ||
		r1.m_gender != r2.m_gender ||
		r1.m_isRadioactiveMutant != r2.m_isRadioactiveMutant);
}
const bool Rabbit::operator <(const Rabbit& r) {
	if (this->m_age != r.m_age)
		return this->m_age < r.m_age;
	else {
		for (int i = 0; i < this->m_name.length() && i < r.m_name.length(); ++i) {
			if (this->m_name.at(i) != r.m_name.at(i))
				return  static_cast<int>(this->m_name.at(i)) < static_cast<int>(r.m_name.at(i));
		}
		return this->m_name.length() < r.m_name.length();

	}
}
const bool Rabbit::operator >(const Rabbit& r) {
	if (this->m_age != r.m_age)
		return this->m_age > r.m_age;
	else {
		for (int i = 0; i < this->m_name.length() && i < r.m_name.length(); ++i) {
			if (this->m_name.at(i) != r.m_name.at(i))
				return  static_cast<int>(this->m_name.at(i)) > static_cast<int>(r.m_name.at(i));
		}
		return this->m_name.length() > r.m_name.length();

	}
}
/*
const bool Rabbit::operator <=(const Rabbit& r) {
	for (int i = 0; i < this->m_name.length() && i < r.m_name.length(); ++i) {
		std::cout << "what";
		if (this->m_name.at(i) != r.m_name.at(i))
			return  static_cast<int>(this->m_name.at(i)) <= static_cast<int>(r.m_name.at(i));
	}
	return this->m_name.length() <= r.m_name.length();
}
const bool Rabbit::operator >=(const Rabbit& r) {
	for (int i = 0; i < this->m_name.length() && i < r.m_name.length(); ++i) {
		std::cout << "what2";
		if (this->m_name.at(i) != r.m_name.at(i))
			return  static_cast<int>(this->m_name.at(i)) >= static_cast<int>(r.m_name.at(i));
	}
	return this->m_name.length() >= r.m_name.length();
}
*/
void Rabbit::operator =(const Rabbit& r) {
	this->m_name = r.m_name;
	this->m_color = r.m_color;
	this->m_age = r.m_age;
	this->m_generation = m_generation;
	this->m_gender = r.m_gender;
	this->m_isRadioactiveMutant = r.m_isRadioactiveMutant;
	this->m_isEmpty = r.m_isEmpty;
	this->move(r.m_x, r.m_y);
}
void Rabbit::operator %(Rabbit& r) {
	std::swap(this->m_x, r.m_x);
	std::swap(this->m_y, r.m_y);
}

Rabbit::~Rabbit()
{
}
Rabbit Rabbit::reproduce() {
	Rabbit newRabbit(getRandomRabbit());
	newRabbit.m_color = this->m_color;
	newRabbit.m_generation = this->m_generation + 1;
	return newRabbit;
}
void Rabbit::age() {
	m_age++;
}
void Rabbit::move(int x, int y) {
	m_x = x; 
	m_y = y; 
}
void Rabbit::printRabbit(){
	std::cout << '\t' << this->m_age << ' ' << this->m_name << " of generation " << this->m_generation << ".\n";
}

void Rabbit::emptyRabbit() {
	m_name = "";
	m_color = "";
	m_age = 0;
	m_generation = 0;
	m_gender = 0;
	m_isRadioactiveMutant = 0;
	m_isEmpty = 1;
}

