/*Creare una gerarchia di classi per gestire le persone che lavorano o studiano all'università
	-->Persone sono studenti o ricercatori o docenti o ammistratori
	-->Tutti hanno nome, luogo di nascita, indirizzo di lavoro
	-->Studenti hanno inoltre facoltà e corso che frequentano
	-->Ricercatori l'argomento di ricerca
	-->Docenti i corsi che insegnano
	-->Amministrativi l'ufficio di appartenenza
Definire la gerarchia di classi, i dati membri, i metodi accessors e costruttori*/

using namespace std;
#include <string>
#include <iostream>
#include <fstream>
#include <typeinfo>

class People{
	protected:
		string nome;
		string luogonascita;
		string indirizzolavoro;
	public:
		People():nome(""),luogonascita(""),indirizzolavoro(""){};
		People(const string nome_, const string luogonascita_, const string indirizzolavoro_): nome(nome_), luogonascita(luogonascita_), 
																								indirizzolavoro(indirizzolavoro_){};
		~People(){
			nome.empty();
			luogonascita.empty();
			indirizzolavoro.empty();	
		}		
		
	string ToString() const {
	return nome + "\t" + luogonascita +"\t" + indirizzolavoro;}	
																									
	
	string getNome() const{
		return nome;
	}
	
	string getBornPlace() const{
		return luogonascita;
	}
	
	string getIndirizzoLavoro() const{
		return indirizzolavoro;
	}
	
	void setNome(const string& nome_){
		nome = nome_;
	}
	
	void setBornPlace(const string& luogonascita_){
		luogonascita = luogonascita_;
	}
	
	void setWorkPlace(const string& indirizzolavoro_){
		indirizzolavoro = indirizzolavoro_;
	}
	
	virtual void setFacolta(const string& facolta) = 0;
	virtual void setCorso(const string& corso) = 0;
	virtual void setField(const string& field) = 0;
	virtual void setCourse(const string& course) = 0;
	virtual void Print() = 0;
};

class Student:public People{
	protected:
		string facolta;
		string corso;
	public:
		Student():facolta(""), corso(""){};
		Student(const string facolta_, const string corso_, const string nome_, const string luogonascita_, const string indirizzolavoro_):
			People(nome_,luogonascita_,indirizzolavoro_), facolta(facolta_), corso(corso_){};
	
	~Student(){
			facolta.empty();
			corso.empty();
		}
	
	string ToString() const {
		return	People::ToString()	+"\t"+ facolta +"\t"+ corso;
	}
	
	string getFacolta() const{
		return facolta;
	}
	
	string getCorso() const{
		return corso;
	}	
	
	virtual void setFacolta(const string& facolta_){
		facolta = facolta_;
	}	
	
	virtual	void setCorso(const string& corso_){
		corso = corso_;
	}
		
	virtual void setField(const string& field){}
	virtual void setCourse(const string& course){}
		
	virtual void Print(){
		ofstream of("People.txt");
		if(!of.good())
			cerr << "File non trovato\n";
		else
			of << this->nome<<" " <<this->luogonascita<<" "<< this->indirizzolavoro<<" " << this->corso<<" " << this->facolta;
		of.close();
	}
		
};

class Researcher:public Student{
	protected:
		string field;
	public:
		Researcher():field(NULL){};
		Researcher(const string field_, const string facolta_, const string corso_, const string nome_, const string luogonascita_, 
					const string indirizzolavoro_):
						Student(facolta_,corso_,nome_,luogonascita_,indirizzolavoro_), field(field_){};
	~Researcher(){
		field.empty();
	}
	
	string ToString() const {
		return	Student::ToString()	+"\t"+ field;
	}
	
	string getField() const{
		return field;
	}	
	
	virtual void setField(const string& field_){
		field = field_;
	}
	
	virtual void Print(){
		ofstream of("People.txt");
		if(!of.good())
			cerr << "File non trovato\n";
		else
			of << this->nome<<" " <<this->luogonascita<<" "<< this->indirizzolavoro<<" " << this->corso<<" " << this->facolta<<" " << this->field<<" ";
		of.close();
	}
	
};

class Teacher:public People{
	protected:
		string course;
	public:
		Teacher():course(""){}
		Teacher(const string course_, const string nome_, const string luogonascita_, const string indirizzolavoro_):
			People(nome_,luogonascita_,indirizzolavoro_), course(course_){}
	
	~Teacher(){
		course.empty();
	}
	
	string ToString() const {
		return	People::ToString()	+"\t"+ course;
	}
	
	string getCourse() const{
		return course;
	}	
	
	virtual void setCourse(const string& course_){
		course = course_;
	}
	
	virtual void setFacolta(const string& facolta) {}
	virtual void setCorso(const string& corso) {}
	virtual void setField(const string& field){}
	
	virtual void Print(){
		ofstream of("People.txt");
		if(!of.good())
			cerr << "File non trovato\n";
		else
			of << this->nome<<" " <<this->luogonascita<<" "<< this->indirizzolavoro<<" " << this->course<<" ";
		of.close();
	}
	
};

int main(){
	People* p = NULL;
	string in;
	
	cout<<"Cosa vuoi generare"<<endl;
	cin >>in;
	
	if(in == "Student")
	{
		p = new Student();
		cout << "Inserisci facolta" <<endl;
		cin >> in;
		p->setFacolta(in);
		cout << "Inserisci corso" <<endl;
		cin >> in;
		p->setCorso(in);
	}
	else if(in == "Researcher")
	{
		p = new Researcher();
		cout << "Inserisci campo di ricerca" <<endl;
		cin >> in;
		p->setField(in);
		cout << "Inserisci facolta" <<endl;
		cin >> in;
		p->setFacolta(in);
		cout << "Inserisci corso" <<endl;
		cin >> in;
		p->setCorso(in);
	}
	else if(in == "Teacher")
	{
		p = new Teacher;
		cout << "Inserisci corso di insegnamento" <<endl;
		cin >> in;
		p->setCourse(in);	
	}
	
	cout << "Inserisci nome" <<endl;
	cin >> in;
	p->setNome(in);
	cout << "Inserisci luogo di nascita" <<endl;
	cin >> in;
	p->setBornPlace(in);
	cout << "Inserisci indirizzo di lavoro" <<endl;
	cin >> in;
	p->setWorkPlace(in);
	
	
	p->Print();
	
	People* f = new Student;
	if (dynamic_cast<Teacher*>(f))
		std::cout << "Teacher\n";
	 else if (dynamic_cast<Student*>(f))
	 std::cout << "Student\n";
	 
	 People* a = new Teacher;
	 People* b = new Student;
	 std::cout << "b is: " << typeid(b).name() << "\n";
	 std::cout << "*b is: " << typeid(*b).name() << "\n";
	 
	 if (typeid(*a) != typeid(*b))
	 	std::cout << "a and b are of different types:\n";
	 std::cout << "a is: " << typeid(*a).name() << '\n';
	 std::cout << "b is: " << typeid(*b).name() << '\n';
	
	
}

