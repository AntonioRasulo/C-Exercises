using namespace std;
#include<iostream>
#include<string>
#include<fstream>

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
	virtual void PrintScreen() = 0;
	
	virtual People* Clone() const = 0;
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
	
	Student(const Student& stu)
	{
		nome=stu.nome;
		luogonascita=stu.luogonascita;
		indirizzolavoro=stu.indirizzolavoro;
		facolta = stu.facolta;
		corso = stu.corso;
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
		ofstream of("People.txt", ios::app);
		if(!of.good())
			cerr << "File non trovato\n";
		else
			of <<"Student: "<< this->nome<<" " <<this->luogonascita<<" "<< this->indirizzolavoro<<" " << this->corso<<" " << this->facolta<<"\n";
		of.close();
	}
	
	virtual void PrintScreen(){
		cout<<"Student: "<< this->nome<<" " <<this->luogonascita<<" "<< this->indirizzolavoro<<" " << this->corso<<" " << this->facolta<<"\n";
	}
	
	virtual People* Clone() const
	{
		return new Student(*this);	
	}
		
};

class Researcher:public Student{
	protected:
		string field;
	public:
		Researcher():field(" "){};
		Researcher(const string field_, const string facolta_, const string corso_, const string nome_, const string luogonascita_, 
					const string indirizzolavoro_):
						Student(facolta_,corso_,nome_,luogonascita_,indirizzolavoro_), field(field_){};
	~Researcher(){
		field.empty();
	}
	
	Researcher(const Researcher& res)
	{
		nome=res.nome;
		luogonascita=res.luogonascita;
		indirizzolavoro=res.indirizzolavoro;
		facolta = res.facolta;
		corso = res.corso;
		field = res.field;
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
		ofstream of;
		of.open("People.txt", ios::app);
		if(!of.good())
			cerr << "File non trovato\n";
		else
			of <<"Researcher: "<<this->nome<<" " <<this->luogonascita<<" "<< this->indirizzolavoro<<" " << this->corso<<" " << this->facolta<<" " << this->field<<"\n";
		of.close();
	}
	
	virtual void PrintScreen(){
		cout<<"Researcher: "<<this->nome<<" " <<this->luogonascita<<" "<< this->indirizzolavoro<<" " << this->corso<<" " << this->facolta<<" " << this->field<<"\n";
	}
	
	virtual People* Clone() const
	{
		return new Researcher(*this);
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
	
	Teacher(const Teacher& tea)
	{
		nome=tea.nome;
		luogonascita=tea.luogonascita;
		indirizzolavoro=tea.indirizzolavoro;
		course = tea.course;
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
		ofstream of("People.txt", ios::app);
		if(!of.good())
			cerr << "File non trovato\n";
		else
			of <<"Teacher: "<<this->nome<<" " <<this->luogonascita<<" "<< this->indirizzolavoro<<" " << this->course<<"\n";
		of.close();
	}
	
	virtual void PrintScreen(){
		cout<<"Teacher: "<<this->nome<<" " <<this->luogonascita<<" "<< this->indirizzolavoro<<" " << this->course<<"\n";
	}
	
	virtual People* Clone() const
	{
		return new Teacher(*this);
	}
	
};
