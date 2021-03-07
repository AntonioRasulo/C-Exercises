/*Se una classe ha allocazione dinamica, come reinizializzare la memoria allocata dell’istanza?
Possibile Soluzione
1)Definire metodo Clear() che dealloca l'istanza
2)Definire metodo Init() che prima chiama Clear()  e poi alloca/inizializza l'istanza
3)Distruttore chiama Clear() e riusa il suo codice
4)Costruttori chiamano Init() risfruttando il suo  codice

Cambiamo la classe Matrix in modo che
	implementi ed utilizzi i metodi Init, Clear;
	usi un metodo static per realizzar Add e Product*/

using namespace std;
#include <iostream>

class Matrix{
	public:
		typedef float T;
		
	private:
		int N, M;
		T** data;
		bool Init(const int N_, const int M_);	//Inizializza la matrice N*M
		void Clear();	//Svuota e dealloca la matrice
		
	public:
		Matrix();							//Costruttore di default, matrice vuota
		Matrix(const int N_, const int M_);	//crea matrice N*M, chiama Init
		Matrix(const Matrix& matrix);		//Copia matrix, chiama Init
		~Matrix();							//distrugge Matrix, chiama Clear
		
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
		void Set(const T& val);	//Setta tutti gli elementi a val
		
		//Operazioni
		Matrix* Add(const Matrix& m1, const Matrix& m2);	//Ritorna una matrice m1+m2
		static bool Add(const Matrix& m1, const Matrix& m2, Matrix* m3); //m3=m1+m2
		void Multiply(const T& val);	//istanza * val
		void Print() const;		//stampa istanza
		static bool Prod(const Matrix& m1, const Matrix& m2, Matrix* m3);	//m3 = m1 * m2
};	//end Matrix

void Matrix::Set(const int i1, const int i2, const T& val){
	data[i1][i2] = val;
}

void Matrix::Set(const T& val){
	for(int i=0; i<N; ++i)
		for(int j=0; j<M; ++j)
			data[i][j] = val;
}

void Matrix::Multiply(const T& val){
	for(int i=0; i<N; ++i)
		for(int j=0; j<M; ++j)
			data[i][j] *= val;
}

void Matrix::Print() const{
	for(int i=0; i<N; ++i)
	{
		for(int j=0; j<M; ++j)
			cout <<	data[i][j] << " ";
		cout << endl;
	}	
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

bool Matrix::Prod(const Matrix& m1, const Matrix& m2, Matrix* m3){
	if(m1.M != m2.N) return false;
	m3 -> Init (m1.N, m2.M);
	for(int i=0; i<m1.N; ++i)
		for(int j=0; j<m2.M; ++j)
			for(int k=0; k<m1.M; ++k)
				m3->Set(i,j, m3->Get(i,j)+ m1.Get(i,k)*m2.Get(k,j));
	return true;			
}

bool Matrix::Add(const Matrix& m1, const Matrix& m2, Matrix* m3){	//ATTENZIONE: Init e Clear e la gestione della reinizializzazione non sono strettamente
	if(m1.N != m2.N || m1.M != m2.M) return false;					//necessari. Servono a gestire elegantemente questo caso.
	m3 -> Init(m1.N, m1.M);											//Allocate direttamente in costruttore e deallocate in distruttore altrimenti.
	for(int i=0; i<m3->N; ++i)
		for(int j=0; j<m3->M; ++j)
			m3->Set( i, j, m1.Get(i,j) + m2.Get(i,j));
	return true;
}

Matrix* Matrix::Add(const Matrix& m1, const Matrix& m2){			//In questo caso non serve Init() e Clear(). Però chi chiama il metodo deve gestire
	if (m1.N != m2.N || m1.M != m2.M) return NULL;					//il puntatore allocato dinamicamente e ricordarsi di deallocarlo. Design classe semplice
	Matrix* m3 = new Matrix(m1.N, m1.M);							//ma maggiore attenzione richiesta al chiamante.
	for(int i = 0; i < m3->N; ++i)
		for(int j = 0; j < m3->M; ++j)
			m3->Set( i, j, m1.Get( i, j) + m2.Get(i,j));
	return m3;
}

int main()
{
	Matrix m1(3,3);
	Matrix m2(3,3);
	Matrix mProd;
	Matrix mSum;
	float in;
	
	cout << "Inserisci valori matrice m1" <<endl;
	for(int i = 0; i<m1.GetN(); i++)
		for(int j = 0; j<m1.GetM(); j++)
		{
			cout << "m1[" << i << "]" << "[" << j << "]:";
			cin >> in;
			m1.Set( i, j, in);
		}
		
	cout << "Inserisci valori matrice m2" <<endl;
	for(int i = 0; i<m2.GetN(); i++)
		for(int j = 0; j<m2.GetM(); j++)
		{
			cout << "m2[" << i << "]" << "[" << j << "]:";
			cin >> in;
			m2.Set( i, j, in);
		}
		
	cout<<"m1:"<<endl;				
	m1.Print();
	
	cout<<"m2:"<<endl;
	m2.Print();	
		
	mSum.Add(m1, m2, &mSum);
	
	cout<<"mSum:"<<endl;
	mSum.Print();
	
	mProd.Prod(m1,m2,&mProd);
	
	cout<<"mProd:"<<endl;
	mProd.Print();
		
}
