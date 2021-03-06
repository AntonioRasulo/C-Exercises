#ifndef DATE_H
#define DATE_H
//using namespace std;
#include<iostream>
class Date
{
		private:
		
			int year;
			int month;
			int day;
		
		public:
			
			Date();

			Date(const int day_, const int month_,const int year_);
             
			Date(const Date& d);
             
			inline int GetYear() const;

			inline int GetMonth() const;
		
		    inline int GetDay() const;
             
			void SetYear(int year_);
            
			void SetMonth(int month_);
            
			void SetDay(int day_);
			
			friend bool operator<(const Date& a, const Date& b);
		//	friend struct CmpDateDecr;
};

#endif