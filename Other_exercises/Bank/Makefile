CC=g++ # compilatore
LD=g++ # linker


#Compilazione degli oggetti
Bank.o: Bank.cc
	${CC}-c Bank.cc

BankNote.o: BankNote.cc
	${CC}-c BankNote.cc

main.o: main.cpp
	${CC} -c main.cpp

#Linking progetto
main: BankNote.o Bank.o  main.o
	${LD} -o main BankNote.o Bank.o main.o


#cancella tutto quello che é stato compilato
clean :
	rm -f *.o main
