#include "Date.h"

Date::Date()
{
	day=1;
	month=1;
	year=1;
}

Date::Date(const int day_, const int month_,const int year_)
{
	day=day_;
	month=month_;
   	year=year_;
}

Date::Date(const Date& d)
{
	day = d.day;
	month = d.month;
	year = d.year;
}

inline int Date::GetYear() const
{
	return year;
}

inline int Date::GetMonth() const
{
	return month;
}
		
inline int Date::GetDay() const
{
	return day;
}
             
void Date::SetYear(int year_)
{
	year = year_;
}
            
void Date::SetMonth(int month_)
{
	month = month_;
}
            
void Date::SetDay(int day_)
{
	day = day_;
}

bool operator<(const Date& a, const Date& b)
{
	if(a.GetYear() != b.GetYear())
		{
			//cout<<a.GetYear() <<"<"<<b.GetYear()<<endl;
			return a.GetYear() < b.GetYear();
		}
	
	else if(a.GetMonth() != b.GetMonth())
		return a.GetMonth() < b.GetMonth();
	else
		return a.GetDay() < b.GetDay();
}