CC=g++ # compilatore
LD=g++ # linker


#Compilazione degli oggetti
CmpDate.o: CmpDate.cc
	${CC}-c CmpDate.cc

Date.o: Date.cc 
	${CC} -c Date.cc

Person.o: Person.cc 
	${CC} -c Person.cc

Handler.o: Handler.cc 
	${CC} -c Handler.cc

main.o: main.cpp 
	$[CC] -c main.cpp
	

#Linking progetto
main: CmpDate.o Date.o Person.o Handler.o main.o
	${LD} -o main CmpDate.o Date.o Person.o Handler.o main.o

	
#cancella tutto quello che é stato compilato
clean :
	rm -f *.o main
