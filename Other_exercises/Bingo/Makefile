CC=g++ # compilatore
LD=g++ # linker


#Compilazione degli oggetti
Table.o: Table.cc
	${CC}-c Table.cc

main.o: main.cpp 
	${CC} -c main.cpp
	

#Linking progetto
main: Table.o main.o
	${LD} -o main Table.o main.o

	
#cancella tutto quello che é stato compilato
clean :
	rm -f *.o main
