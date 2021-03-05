/*SparseVector header file*/
#include<map>
using namespace std;

template<typename T>
class SparseVector{
	
	private:
		
		//typedef std::map<int,float> DataContainer;
		typedef std::map<int,T> DataContainer;
		DataContainer data;
	
	public:
		
		void Set(int i, T value) {data[i] = value;}
		
		struct Element
		{
			int i;
			T value;
		};
		
	
		class Iterator
		{
			private:
				
				typename DataContainer::const_iterator iter;
				const SparseVector* svector;
				
			public:
			
				Iterator(const SparseVector& svector_)			//A SparseVector is initialized
				{
					svector = &svector_;
					iter = svector->data.begin();
				}
				
				inline Element GetNext()							//It's possible to scan the vector and check if there
				{												
					Element e;
					e.i = iter->first;
					e.value = iter->second;
					++iter;
					return e;
				}
				
				inline bool HasNext() const
				{
					return ( iter != svector->data.end());		//are present other elements
				}
		};
		
		friend class Iterator;									//Friend of the class, to access to private data

};