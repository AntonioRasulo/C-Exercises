using namespace std;

#include <string>
#include <iostream>
#include "Elephant.h"

Elephant::Elephant(const string& name_, const float weight_, const int num_leg_, const int dangerous_grade_)
{
        name = name_;
        weight = weight_;
        num_leg = num_leg_;
        dangerous_grade = dangerous_grade_;
}

Elephant::Elephant(const Elephant& ele)
{
        name = ele.name;
        weight = ele.weight;
        num_leg = ele.num_leg;
        dangerous_grade= ele.dangerous_grade;
}

Elephant::Elephant()
{
	name="";
	weight= 0.0;
	num_leg = 4;
	dangerous_grade = 5;
}

void Elephant::setEatenPerson(const int& eaten)
{

}

void Elephant::EatPerson()
{}

void Elephant::Sound()
{
        cout<<"Elephant Sound"<<endl;
}

Animal* Elephant::Clone() const
{
        return new Elephant(*this);
}
