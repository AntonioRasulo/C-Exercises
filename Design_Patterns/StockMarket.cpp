/*Observer Design Pattern example: stock market*/
#include "StockMarket.h"

int main()
{
	Stock c1("Ebay", 123.0);
	Investor* i1 =  new Investor("Billy");
	c1.Attach(i1);
	cout<<"Created investor Billy following Ebay\n"<<endl;
	c1.SetPrice(125.0);
	
	Investor* i2 = new Investor("Timmy");
	c1.Attach(i2);
	cout<<"\nCreated investor Timmy following Ebay\n"<<endl;
	c1.SetPrice(145.0);
	c1.Detach(i1);
	cout<<"\nInvestor Billy not interested in Ebay anymore\n"<<endl;
	c1.SetPrice(165.0);
	delete i1;
	delete i2;
	return 0;
}