CC=g++ # compilatore
LD=g++ # linker


#Compilazione degli oggetti
Team.o: Team.cc
	${CC}-c Team.cc

main.o: main.cpp 
	${CC} -c main.cpp
	

#Linking progetto
main: Team.o main.o
	${LD} -o main Team.o main.o

	
#cancella tutto quello che é stato compilato
clean :
	rm -f *.o main
