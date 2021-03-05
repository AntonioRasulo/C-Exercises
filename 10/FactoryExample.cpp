
/*Factory example*/

using namespace std;
#include<cstddef>
#include<string>

class Car{
	public:
		virtual void Sposta(float km) = 0;	
};

class Fiat : public Car{
	public:
		virtual void Sposta(float km);
};

class Volvo : public Car{
	public:
		virtual void Sposta(float km);
};

class Ferrari : public Car{
	public:
		virtual void Sposta(float km);
};

class BMW : public Car{
	public:
		virtual void Sposta(float km);
};

class CarFactory{
	public:
		static Car* Build(const string& tipo)
		{
			if(tipo == "fiat")	return new Fiat();
			else if(tipo == "volvo")	return new Volvo();
			else if(tipo == "Ferrari")	return new Ferrari();
			else if(tipo == "BMW")	return new BMW();
			else return NULL;	
		}
};

int main()
{
	
}