CC=g++ # compilatore
LD=g++ # linker


#Compilazione degli oggetti
Recipe.o: Recipe.cc
	${CC}-c Recipe.cc

RecipeFactory.o: RecipeFactory.cc
	${CC}-c RecipeFactory.cc

RicettaCotta.o: RicettaCotta.cc
	${CC}-c RicettaCotta.cc

RicettaCruda.o: RicettaCruda.cc
	${CC}-c RicettaCruda.cc

main.o: main.cpp
	${CC} -c main.cpp

#Linking progetto
main: Recipe.o RicettaCotta.o RicettaCruda.o RecipeFactory.o  main.o
	${LD} -o main Recipe.o RicettaCotta.o RicettaCruda.o RecipeFactory.o main.o


#cancella tutto quello che é stato compilato
clean :
	rm -f *.o main
