# kompilator c
CCOMP = gcc

# konsolidator
LOADER = gcc

# opcje optymalizacji:
# wersja do debugowania
#OPT = -g -DEBUG 
# wersja zoptymalizowana do mierzenia czasu
OPT = -O3

# pliki naglowkowe
INC =

# biblioteki
LIB =  -lm 

F = -fopenmp 

zad8: zad8.o 
	$(LOADER) $(F) $(OPT) zad8.o -o zad8 $(LIB)

zad8.o: zad8.c 
	$(CCOMP) $(F) -c $(OPT) zad8.c $(INC)

zad9: zad9.o 
	$(LOADER) $(F) $(OPT) zad9.o -o zad9 $(LIB)

zad9.o: zad9.c 
	$(CCOMP) $(F) -c $(OPT) zad9.c $(INC)


test: test.o 
	$(LOADER) $(F) $(OPT) test.o -o test $(LIB)

test.o: test.c 
	$(CCOMP) $(F) -c $(OPT) test.c $(INC)


clean:
	rm -f *.o
