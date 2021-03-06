#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

class Matrix{
	
	public:
		typedef float T;
	
	private:
		int N, M;
		T** data;
		bool Init(const int N_, const int M_);	//Inizializza la matrice N*M
		void Clear();	//Svuota e dealloca la matrice
		
		typedef std::vector<Matrix> MatrixContainer;
		MatrixContainer container;
		
	public:
		Matrix();							//Costruttore di default, matrice vuota
		Matrix(const int N_, const int M_);	//crea matrice N*M, chiama Init
		Matrix(const Matrix& matrix);		//Copia matrix, chiama Init
		~Matrix();							//distrugge Matrix, chiama Clear
		
		void Set(Matrix m){container.push_back(m);}
	
		/*struct Element
		{
			Matrix value;
		};*/
	
		class Iterator
		{
			private:
				MatrixContainer::const_iterator iter;
				const Matrix* mat;
			
			public:
				Iterator(const Matrix& mat_)
				{
					mat = &mat_;
					iter = mat->container.begin();
				}
			
				inline /*Element*/Matrix GetNext()							//It's possible to scan the vector and check if there
				{												
					Matrix tmp;	//Element e;
					tmp/*e.value*/= *iter;
					++iter;
					return tmp;
				}
				
				inline bool HasNext() const
				{
					return ( iter != mat->container.end());		//are present other elements
				}
			
		};
	
		friend class Iterator;
	
		//Getters
		inline int GetM()const{
			return M;
		}
		
		inline int GetN()const{
			return N;
		}
		
		inline T Get(const int i1, const int i2) const
		{
			return data[i1][i2];
		}
		
		//Setters
		inline void Set(const int i1, const int i2, const T& val);	//Setta un elemento a val
		
		//Operazioni
		void Print() const;		//stampa istanza
		Matrix operator+(const Matrix& m);
		Matrix operator*(const Matrix& m);
		bool operator==(const Matrix& right);
		Matrix& operator+=(const Matrix& right);
		Matrix& operator*=(const Matrix& right);
		Matrix& operator*=(const T& val);
		Matrix& operator=(const Matrix& m);


		friend ostream& operator<<(ostream& out, const Matrix& m);
		friend istream& operator>>(istream& in, Matrix& m);
		
		friend ifstream& operator>>(ifstream& in,  Matrix& m);
		friend ofstream& operator<<(ofstream& out, const Matrix& m);
};


Matrix::Matrix(){
	N = 0;
	M = 0;
	data = NULL;
}

Matrix::Matrix(const int N_, const int M_){
	N = 0;
	M = 0;
	data = NULL;
	this->Init(N_, M_);	//Costruttore chiama Init e riusa codice

}

Matrix::~Matrix(){	//Distruttore, usa codice Clear
	this -> Clear();
}

Matrix::Matrix(const Matrix& matrix){
	N = 0;
	M = 0;
	data = NULL;
	this->Init(matrix.N, matrix.M);	//Si sfrutta il metodo Init
	
	for(int i = 0; i<N; ++i)		//Si fa la copia
		for(int j = 0; j<M; ++j)  
			data[i][j] = matrix.Get( i, j);
}

void Matrix::Clear(){	//Dealloca e azzera puntatori e dati
	if(data != NULL){
		for( int i = 0; i < N; ++i)
			if(data[i] != NULL) delete[] data[i];
				delete[] data;
	}
	M = 0;
	N = 0;
	data = NULL;
}

bool Matrix::Init(const int N_, const int M_){	//Inizializza la matrice. Funziona sia se la matrice era già esistente o se viene creata adesso
	this->Clear();	//Prima si dealloca, necessario se la matrice era gia' allocata
	M = M_;
	N = N_;
	if(N <= 0 || M <= 0){
		cerr << "Can not generate matrix" << N << "x" << M << endl;
		return false;
	}
	
	if( M>0 && N>0){
		data = new T*[N];
		for(int i = 0; i < N; ++i)
			data[i] = new T[M];
	}
	
	return true;
	
}

void Matrix::Set(const int i1, const int i2, const T& val){
	data[i1][i2] = val;
}

void Matrix::Print() const{
	for(int i=0; i<N; ++i)
	{
		for(int j=0; j<M; ++j)
			cout <<	data[i][j] << " ";
		cout << endl;
	}	
}

Matrix Matrix::operator+(const Matrix& m){
	if(N != m.N || M != m.M) return *this;
	//Matrix* mout = new Matrix(N,M);
	Matrix mout;
	mout.Init(m.N, m.M);
	for(int i=0; i<N; ++i)
		for(int j=0; j<M; ++j)
			mout.Set(i,j, this->Get(i,j) + m.Get(i,j));
	return mout;
}

Matrix Matrix::operator*(const Matrix& m){
	if(M != m.N) return *this;
	//Matrix* mout = new Matrix(N,m.M);
	Matrix mout;
	mout.Init(N, m.M);
	for(int i=0; i<N; ++i)
		for(int j=0; j<m.M; ++j)
			for(int k=0; k<M; ++k)
				mout.Set(i,j, mout.Get(i,j) + this->Get(i,k) * m.Get(k,j));
	return mout;
}


bool Matrix::operator==(const Matrix& right)
{
	if (N != right.N || M != right.M)	return false;
	for (int i = 0; i< N; ++i)
		for(int j = 0; j<right.M; ++j)
			if (data[i][j] != right.data[i][j])	return false;
	return true;	
}

Matrix& Matrix::operator+=(const Matrix& right){
	if( N != right.N || M != right.M)	return *this;
	for( int i=0; i<N; ++i)
		for( int j=0; j<M; ++j)
			data[i][j] += right.Get(i,j);
	return *this;
}

Matrix& Matrix::operator*=(const T& val){
	for(int i=0; i<N; ++i)
		for(int j=0; j<M; ++j)
			data[i][j]*=val;
	return *this;
}

Matrix& Matrix::operator*=(const Matrix& right){
	if(M!=right.N) return *this;
	Matrix tmp(*this);
	
	this->Init(N, right.M);
	//Matrix* mout = new Matrix(N, right.M);
	
	for(int i=0; i<N; ++i)
		for(int j=0; j<right.M; ++j)
			for(int k=0; k<M; ++k)
				//mout->Set(i,j,data[i][k]*right.Get(k,j));
				data[i][j] += tmp.Get(i,k)*right.Get(k,j);
	return *this;
}

Matrix& Matrix::operator=(const Matrix& m)
{
	if(this == &m)	return *this;		//evita self-alignment
	this -> Init(m.N, m.M);				//dealloca eventuali dati precedenti e rialloca lo spazio
	for(int i=0; i<N; ++i)
		for(int j=0; j<M; ++j)
			data[i][j] = m.data[i][j];
	return *this;
}

ostream& operator<<(ostream& out, const Matrix& m)
{
	for(int i=0; i<m.N; ++i)
	{
		for(int j=0; j<m.M; ++j)
			cout <<	m.data[i][j] << " ";
		cout << endl;
	}
	
	return out;
}

istream& operator>>(istream& in, Matrix& m){
	float val;
	for(int i=0; i<m.N; ++i)
		for(int j=0; j<m.M; ++j)
		{
			cout << "m[" << i << "]" << "[" << j << "]:";
			in >> val;
			m.Set(i,j, val);
		}
	return in;
}

ofstream& operator<<(ofstream& out, const Matrix& m){
	for(int i=0; i<m.N; ++i)
		for(int j=0; j<m.M; ++j)
			out << m.Get(i,j) << " ";
	return out;
}

ifstream& operator>>(ifstream& in, Matrix& m){
	//string str;
	float val;
	//in >> str;
	//cout << str <<endl;
	for (int i=0; i<m.N; ++i)
		for(int j=0; j<m.M; ++j)
		{
			//in >> val;
			//cout << str[m.N*i+j]<<endl;
			//val =(double)str[m.N*i+j];
			//cout << val<<endl;
			//m.Set(i,j,str[m.N*i+j]/25);
			in >> val;
			m.data[i][j] = val;
		}
	return in;
}