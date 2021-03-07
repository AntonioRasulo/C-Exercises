/*Implementare una classe libreria per la gestione di matrici (classe Matrix) che
	--> Usa typedef per specificare il tipo di dato memorizzato
	--> Permette di inizializzare una matrice NxM di elementi
		 (assumiamo che il typedef sia fatto per float)
	--> permette di leggere o modificare un valore
	--> permette di sommare due matrici
	--> permette di moltiplicare la matrice per uno scalare a
	--> permette di moltiplicare la matrice con un'altra di dimensione MxK
*/

using namespace std;
#include <iostream>

class Matrix{
	private:
		typedef float Element;
		Element** data;
		int N, M;
	public:
		
	/*	Matrix()
		{
			N=0;
			M=0;
		};*/
		
		explicit Matrix(int N_, int M_){
			N = N_;
			M = M_;
			data = new Element*[N];	
			for(int i=0; i<N; i++)
				data[i] = new Element[M];
		};
		
		explicit Matrix(const Matrix& mat){	//Copy constructor va definito altrimenti di mat viene copiato il puntatore,
			N = mat.N;						// e le due matrici punterebbero allo stesso data
			M = mat.M;				
			data = new Element*[N];
			for(int i=0; i<N; i++)
				data[i] = new Element[M];
			for(int i = 0; i<N; i++)
				for(int j = 0; j<M; j++)
					data[i][j] = mat.data[i][j];
		};
		
		~Matrix() { 			// Distruttore va definito per deallocare quello che era stato allocato dinamicamente
			for(int i = 0; i<N; i++)
				delete[] data[i];
			delete[] data; 
		}
		
		Element Get(int i, int j) const{
			return data[i][j];
		}
		
		void Set(int i, int j, const Element& el){
			data[i][j] = el;
		}
		
		void Sum(const Matrix& m){
			
			if(N == m.N && M == m.M)
			{
			
				for(int i =0; i<N; i++)
					for(int j=0; j<M; j++)
						data[i][j]+=m.data[i][j];
			}
			else
				cout << "Le matrici hanno dimensione diversa" << endl;
		}
		
		void Stampa(){
			for(int i=0; i<N; i++)
				{
					for(int j=0; j<M; j++)
						cout<<data[i][j]<< " ";
					cout << endl;
				}
		}
		
		void Scalar(const Element& el){
			for(int i =0; i<N; i++)
				for(int j=0; j<M; j++)
					data[i][j]*=el;
		}
		
	/*	Matrix Prod( Matrix m1, Matrix m2)
		//void Prod(const Matrix& m1, const Matrix& m2)
		{
			if(m1.M == m2.N)
			{
				Matrix mprod( m1.N, m2.M);
				//N = m1.N;
				//M = m2.M;
				for(int i =0; i<mprod.N; i++)
					for(int j=0; j<mprod.M; j++)
						data[i][j] = 0;
				for(int i = 0; i < m1.N; i++)
					for( int k=0; k < m2.M; k++)
						for(int j = 0; j<m1.M; j++)
								mprod.data[i][k] += m1.data[i][j]*m2.data[j][k]; 
				return mprod;
			}
		}*/
		
		Matrix Prod(Matrix& m)
		{
			if(M == m.N)
			{
				Matrix mprod(N, m.M);
				for(int i =0; i<mprod.N; i++)
					for(int j=0; j<mprod.M; j++)
						data[i][j] = 0;
				
				for(int i = 0; i < N; i++)
					for( int k=0; k < m.M; k++)
						for(int j = 0; j<M; j++)
								mprod.data[i][k] += data[i][j]*m.data[j][k]; 
				return mprod;
			}
			
			//return m;
		}
		
};

int main()
{
	Matrix m1(3,3);
	Matrix m2(3,3);
	float in;
	
	cout << "Inserisci valori matrice m1" <<endl;
	for(int i = 0; i<3; i++)
				for(int j = 0; j<3; j++)
				{
					cout << "m1[" << i << "]" << "[" << j << "]:";
					cin >> in;
					m1.Set( i, j, in);
				}
				
	cout << "Inserisci valori matrice m2" <<endl;
	for(int i = 0; i<3; i++)
				for(int j = 0; j<3; j++)
				{
					cout << "m2[" << i << "]" << "[" << j << "]:";
					cin >> in;
					m2.Set( i, j, in);
				}
	
	cout<<"m1:"<<endl;				
	m1.Stampa();
	
	cout<<"m2:"<<endl;
	m2.Stampa();
	
	Matrix msum(m1);
	msum.Sum(m2);
	cout<<"msum:"<<endl;
	msum.Stampa();
	
	msum.Scalar(2);
	cout<<"msum:"<<endl;
	msum.Stampa();
	
	Matrix mprod = m1.Prod(m2);
	//mprod.Prod(m1,m2);
	mprod.Stampa();
}
