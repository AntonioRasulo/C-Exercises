CC=g++ # compilatore
LD=g++ # linker


#Compilazione degli oggetti
ComplexNumber.o: ComplexNumber.cc
	${CC}-c ComplexNumber.cc

VectorCN.o: VectorCN.cc
	${CC}-c VectorCN.cc

main.o: main.cpp
	${CC} -c main.cpp

#Linking progetto
main: VectorCN.o ComplexNumber.o main.o
	${LD} -o main VectorCN.o ComplexNumber.o main.o


#cancella tutto quello che é stato compilato
clean :
	rm -f *.o main
