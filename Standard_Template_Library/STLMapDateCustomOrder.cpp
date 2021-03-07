/*Ordinamento custom di STL Map con Map<Date, int, Cmp>, nel caso in cui Date non ha operator< definito*/

using namespace std;
#include<map>
#include<iostream>

class Date
{
		private:
		
			int year;
			int month;
			int day;
		
		public:
			
			Date()
			{
				day=1;
				month=1;
				year=1;
			};

			Date(const int day_, const int month_,const int year_)
            {
				day=day_;
				month=month_;
            	year=year_;
            };
             
			Date(const Date& d)
			{
				day = d.day;
				month = d.month;
				year = d.year;
			}
             
			inline int GetYear() const
			{
				return year;
			};

			inline int GetMonth() const
			{
				return month;
			};
		
		    inline int GetDay() const
			{
				return day;
			};
             
			void SetYear(int year_)
			{
				year = year_;
			};
            
			void SetMonth(int month_)
			{
				month = month_;
			};
            
			void SetDay(int day_)
			{
				day = day_;
			};
			
		
};

struct Cmp{
	bool operator()(const Date& a, const Date& b)const{
		if (a.GetYear() != b.GetYear()) return a.GetYear() > b.GetYear();
		if (a.GetMonth() != b.GetMonth()) return a.GetMonth() > b.GetMonth(); 
		return a.GetDay() > b.GetDay();
	}
};


int main()
{
	std::map<Date, int, Cmp> mappa;
	mappa[Date(1,1,2011)] = 1;
	mappa[Date(1,1,2010)] = 5;
	mappa[Date(3,3,2007)] = 4;
	std::map<Date, int, Cmp>::const_iterator iter = mappa.begin();
	for (; iter != mappa.end(); ++iter)
	{
		std::cout << iter->first.GetYear() << iter->first.GetMonth()
				<< iter->first.GetDay() << "->" << iter->second << endl;
	}
}

