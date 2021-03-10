using namespace std;

#include <string>
#include <iostream>
#include "Cat.h"

Cat::Cat(const string& name_, const float weight_, const int num_leg_, const int dangerous_grade_)
{
	name = name_;
	weight = weight_;
	num_leg = num_leg_;
	dangerous_grade = dangerous_grade_;
}

Cat::Cat()
{
	name = "";
	weight = 0.0;
	num_leg = 4;
	dangerous_grade = 0;
}

Cat::Cat(const Cat& cat)
{
	name = cat.name;
	weight = cat.weight;
	num_leg = cat.num_leg;
	dangerous_grade= cat.dangerous_grade;
}

void Cat::EatPerson()
{}

void Cat::setEatenPerson(const int& eaten)
{

}

void Cat::Sound()
{
	cout<<"Miao"<<endl;
}

Animal* Cat::Clone() const
{
	return new Cat(*this);
}
