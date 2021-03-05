/*Decorator Example Design Pattern
*/

class WriterBase{
	public:
		virtual bool Write(const string& str, const string& file) = 0;
};

class WriterPlan : public WriterBase{	//semplice writer che stampa stringhe sul file
	public:
		virtual bool Write(const string& str, const string& file);
};

bool WriterPlan::Write(const string& str, const string& file){
	ofstream of(file.c_str());
	if(!of.good())
	{
		cerr<<"Errore\n";
		return false;
	}
	
	of << str;
	return true;
	
}

class WriteEncoded : public WriterBase{	//write encoded
	private:
		WriterBase* writer;		//istanza generica di classe padre
		
	protected:
		string Encode(const string& str){}	//metodo protected che effettua encryptting
		
	public:
		//Costruttore setta l'istanza con stessa classe padre
		WriteEncoded(WriterBase* writer_):writer(writer_){}
		
		bool Write(const string& str, const string& file){	//implementa interfaccia
			// Chiamo il Write specifico dell'oggetto interno su stringa Encoded
			return writer->Write(Encode(str), file);	
		}
};

class WriteZipped : public WriterBase{	//write zipped
	private:
		WriterBase* writer;		//istanza generica di classe padre
		
	protected:
		string Zip(const string& str){}	//metodo protected che effettua la compressione
		
	public:
		//Costruttore setta l'istanza interna con stessa classe padre
		WriteZipped(WriterBase* writer_):writer(writer_){}
		
		bool Write(const string& str, const string& file){	//implementa interfaccia
			// Chiamo il Write specifico dell'oggetto interno su stringa Encoded
			return writer->Write(Zip(str), file);	
		}
};

