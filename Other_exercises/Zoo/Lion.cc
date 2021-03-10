using namespace std;

#include <string>
#include <iostream>
#include "Lion.h"


Lion::Lion(const string& name_, const float weight_, const int num_leg_, const int dangerous_grade_, const int eaten_person_)
{
        name = name_;
        weight = weight_;
        num_leg = num_leg_;
        dangerous_grade = dangerous_grade_;
	eaten_person = eaten_person_;
}

Lion::Lion(const Lion& leo)
{
        name = leo.name;
        weight = leo.weight;
        num_leg = leo.num_leg;
        dangerous_grade= leo.dangerous_grade;
	eaten_person = leo.eaten_person;
}

void Lion::Sound()
{
        cout<<"Lion Sound"<<endl;
}

Animal* Lion::Clone() const
{
        return new Lion(*this);
}

void Lion::EatPerson()
{
	eaten_person++;
}
