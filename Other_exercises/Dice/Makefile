CC=g++ # compilatore
LD=g++ # linker


#Compilazione degli oggetti
Dice.o: Dice.cc
	${CC}-c Dice.cc

main.o: main.cpp 
	${CC} -c main.cpp
	

#Linking progetto
main: Dice.o main.o
	${LD} -o main Dice.o main.o

	
#cancella tutto quello che é stato compilato
clean :
	rm -f *.o main
