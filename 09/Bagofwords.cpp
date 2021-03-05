/*Esercizio su composizione: bag of words
	--> Leggere un testo in ingresso da file
	--> Creare bag of words
	--> Stampare le parole in ordine decrescente
		di frequenza
	Consiglio: usare map<int, vector<string>> e comparatore
Nome testo: LoremIpsum.txt*/

using namespace std;
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<fstream>

struct Cmp
{
	bool operator()(const int& a, const int&b){
		return b<a;	
	}
};

class Reader{
	private:
		map<int, vector<string>, Cmp> m;
		ifstream is;
	public:
		Reader()
		{
			map<string, int> tmp;
			vector<string> v;
			int max;
			string word;
			is.open("LoremIpsum.txt");
			if(!is.good())
			{
				cerr<<"File non trovato\n";	
			}
			
			while(is>>word)
			{
				tmp[word]++;
			}
			
			map<string,int>::const_iterator iter = tmp.begin();
			max = iter->second;
			do{
				if((iter->second) > max)
					max = iter->second;
				++iter;
			}while(iter!=tmp.end());
			
			
			for(int i = max; i != 0; --i)
			{
				for( iter = tmp.begin(); iter!=tmp.end(); ++iter)
					if((iter->second) == i)
						v.push_back(iter->first);
				m.insert(make_pair(i,v));
				v.clear();
			}
			
		}
	
	void Print()
	{
		map<int, vector<string>, Cmp>::const_iterator it;
		vector<string>::const_iterator v_it;
		for(it = m.begin(); it!=m.end(); ++it)
		{
			cout<<it->first<<" ";
			for(v_it=((it->second).begin()); v_it!=((it->second).end()); ++v_it)
				cout<<*v_it<<" ";
			cout<<endl;
		}
	}
	
};

int main()
{
	Reader r;
	r.Print();
}