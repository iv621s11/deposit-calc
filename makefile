.PHONY: all clean

all: calc

calc:build/main.o build/depositcalc.o src/depositcalc.h
	mkdir bin -p
	gcc -Wall build/main.o build/depositcalc.o -o bin/calc
	
build/main.o: src/main.c src/depositcalc.h 
	mkdir build -p
	gcc -I scr -Wall -c src/main.c -o build/main.o
	
build/depositcalc.o: src/depositcalc.c src/depositcalc.h
	mkdir build -p
	gcc -Wall -c src/depositcalc.c -o build/depositcalc.o
	
clean:
	rm -f build/* build/* calc*
