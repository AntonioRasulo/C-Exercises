/*Realizzare del software per rappresentare generici rettangoli, di cui sia possibile calcolare area, perimetro e centro.*/
using namespace std;
#include <math.h>
#include <iostream>

class Point{
	private:
		float x;
		float y;	
	public:
		Point()
		{
			x = 0.0;
			y = 0.0;	
		};
		
		Point(float x_in, float y_in){
			x = x_in;
			y = y_in;
		};
		
	//	float Dist(const Point& pt);
		
		float Dist(const Point& pt)
		{
			return sqrt(pow(x-pt.x, 2) + pow(y-pt.y, 2));
		}
		
		float X (){
			return x;
		};
		
		float Y(){
			return y;	
		};
		
		void setX(float x_)
		{
			x = x_;
		}
		
		void setY(float y_)
		{
			y = y_;
		}
		
};

class Rectangle{
	private:
		Point anchor;
		float width, height;
	
	public:
		Rectangle()
		{
			//anchor.Point();
			width = 0.0;
			height = 0.0;	
		};
		
		Rectangle(float width_in, float height_in, Point point_in)
		{
			anchor = point_in;
			width = width_in;
			height = height_in;
		};
		
	/*	float Area();
		float Perimeter();
		Point Center();*/
		
		float Area()
		{
			return width*height;
		}
		
		float Perimeter()
		{
			return 2*width + 2*height;
		}
		
		Point Center()
		{
			Point pt(anchor.X() + width/2, anchor.Y() + height/2);
			
			return pt;
		}
		
		void PCenter(Point* center)
		{
			center->setX(anchor.X() + width/2);
			center->setY(anchor.Y() + height/2);
		}
		
		void setWidth(float width_)
		{
			width = width_;
		}
		
		void setHeight(float height_)
		{
			height = height_;
		}
		
		void setAnchor(float x_, float y_)
		{
			anchor.setX(x_);
			anchor.setY(y_);
		}
};


int main()
{
	Rectangle ret;
	Point ct;
	float altezza, larghezza;
	float x, y;
	
	cout << "Inserire altezza del rettangolo"<<endl;
	cin >> altezza;
	ret.setHeight(altezza);
	
	cout << "Inserire larghezza del rettangolo"<<endl;
	cin >> larghezza;
	ret.setWidth(larghezza);
	
	cout << "Inserisci coordinata x dell'angolo in basso a sinistra" << endl;
	cin >> x;
	
	cout << "Inserisci coordinata y dell'angolo in basso a sinistra" << endl;
	cin >> y;
	
	ret.setAnchor(x,y);
	
	cout <<"Area del rettangolo" << ret.Area()<<endl;
	cout <<"Perimetro del rettangolo" << ret.Perimeter()<<endl;

	//	ct = ret.Center();	Si puo utilizzare uno di questi due
	ret.PCenter(&ct);	

	cout <<"Centro del rettangolo " << "x:" << ct.X() << "y:" << ct.Y() <<endl;
	
}
