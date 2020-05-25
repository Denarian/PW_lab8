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

F =  -fopenmp 

zad5: zad5.o 
	$(LOADER) $(F) $(OPT) zad5.o -o zad5 $(LIB)

zad5.o: zad5.c 
	$(CCOMP) $(F) -c $(OPT) zad5.c $(INC)

zad4: zad4.o 
	$(LOADER) $(F) $(OPT) zad4.o -o zad4 $(LIB)

zad4.o: zad4.c 
	$(CCOMP) $(F) -c $(OPT) zad4.c $(INC)

zad3: zad3.o 
	$(LOADER) $(F) $(OPT) zad3.o -o zad3 $(LIB)

zad3.o: zad3.c 
	$(CCOMP) $(F) -c $(OPT) zad3.c $(INC)

test: test.o 
	$(LOADER) $(F) $(OPT) test.o -o test $(LIB)

test.o: test.c 
	$(CCOMP) $(F) -c $(OPT) test.c $(INC)


clean:
	rm -f *.o
