/*Creare una gerarchia di classi per gestire le persone che lavorano o studiano all'università
	-->Persone sono studenti o ricercatori o docenti
	-->Tutti hanno nome, luogo di nascita, indirizzo di lavoro
	-->Studenti hanno inoltre facoltà e corso che frequentano
	-->Ricercatori l'argomento di ricerca
	-->Docenti i corsi che insegnano
Realizzare una classe dipartimento per gestire un insieme di persone:
	-->Fornire una modalità per scandire le persone
	-->Suggerimento: usare design pattern Iterator
*/



template<typename T>
class VectorDepartment
{
	private:
		
		typedef std::vector<T> Container;
		Container data;
		
	public:
		
		void Set(T value) {data.push_back(value);}
		
		struct Element
		{
			T value;
		};
		
		class Iterator
		{
			private:
				
				typename Container::const_iterator iter;
				const VectorDepartment* vec;
				
			public:
				
				Iterator(const VectorDepartment& vec_)			
				{
					vec = &vec_;
					iter = vec->data.begin();
				}
				
				inline Element GetNext()
				{
					Element e;
					e.value = *iter;
					++iter;
					return e;
				}
				
				void Delete()
				{
					delete *iter;
					iter++;
				}
				
				inline bool HasNext() const
				{
					return ( iter != vec->data.end());		
				}
		};
		
		friend class Iterator;
		
};
