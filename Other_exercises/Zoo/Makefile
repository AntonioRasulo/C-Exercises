CC=g++ # compilatore
LD=g++ # linker


#Compilazione degli oggetti
Animal.o: Animal.cc
	${CC}-c Animal.cc

Cat.o: Cat.cc
	${CC}-c Cat.cc

Elephant.o: Elephant.cc
	${CC}-c Elephant.cc

Lion.o: Lion.cc
	${CC}-c Lion.cc

main.o: main.cpp 
	${CC} -c main.cpp
	

#Linking progetto
main: Lion.o Elephant.o Cat.o Animal.o main.o
	${LD} -o main Lion.o Elephant.o Cat.o Animal.o main.o

	
#cancella tutto quello che é stato compilato
clean :
	rm -f *.o main
