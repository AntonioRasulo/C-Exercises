/*Composite example*/

class ClassifierBase{	//classe padre comune a foglia e composite
	public:
		virtual bool Classify(const string& text) const = 0;
};

class Classifier : public ClassifierBase{	//classe foglia
	public:
		Classifier(const vector<string>& words_):words(words_){}
		virtual bool Classify(const string& text) const{
		/* cerca le parole chiave in text, se ve ne sono almeno n% ritorna true */
		}
	
	private:
		//Lista di parole chiave
		vector<string> words;
	
};

class ClassifierComposite : public ClassifierBase{	//composite
	private:
		std::vector<ClassifierBase*>	sottoclassificatori;	//lista di foglie
	
	public:
		void AddClassifier(ClassifierBase* c){
			sottoclassificatori.push_back(c);
		}
		
		virtual bool Classify(const string& text) const{			//lista di foglie chiamate in sequenza per realizzare il comportamento composto:
			for(int i = 0; i < sottoclassificatori.size(); ++i)		//OR tra le classificazioni. La logica è specifica del problema da risolvere.
				if (sottoclassificatori[i]->Classifiy(text))
					return true;
			return false;
		}
		
		~ClassifierComposite(){
			for(int i=0; i<sottoclassificatori.size(); ++i)				
				for(int i = 0; i < sottoclassificatori.size(); ++i)		//Se ownership delle sottoparti è interna, il composite dealloca le sue sottoparti.
					delete sottoclassificatori[i];						//Se Composite non ha ownership, il distruttore va tolto.
		}

		

};