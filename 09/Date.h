using namespace std;
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
			
			friend bool operator<(const Date& a, const Date& b);
		//	friend struct CmpDateDecr;
};

/*struct CmpDateDecr{
	bool operator<(const Date& a, const Date& b)
	{
		if(a.GetYear() != b.GetYear())
			return a.GetYear() < b.GetYear();
		else if(a.GetMonth() != b.GetMonth())
			return a.GetMonth() < b.GetMonth();
		else
			return a.GetDay() < b.GetDay();
	}
};*/

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
