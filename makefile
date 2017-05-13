.PHONY: all clean test

all: bin/calc
test: bin/calc_test

bin/calc:build/main.o build/depositcalc.o 
	gcc -Wall build/main.o build/depositcalc.o -o bin/calc
	
build/main.o: src/main.c src/depositcalc.h 
	gcc -I scr -Wall -c src/main.c -o build/main.o
	
build/depositcalc.o: src/depositcalc.c src/depositcalc.h
	gcc -Wall -c src/depositcalc.c -o build/depositcalc.o
	
clean:
	rm -f build/* build/* bin/calc*
	
bin/calc_test:build/main_test.o build/depositcalc_test.o build/depositcalc.o
	gcc -Wall build/main_test.o build/depositcalc_test.o build/depositcalc.o -o bin/calc_test
	
build/main_test.o:test/main_test.c src/depositcalc.h thirdparty/ctest.h
	gcc -I thirdparty -I src -Wall test/main_test.c src/depositcalc.h thirdparty/ctest.h -o build/main_test.o
	
build/depositcalc_test.o:test/depositcalc_test.c src/depositcalc.h thirdparty/ctest.h
	gcc -I thirdparty -I rc -Wall test/depositcalc_test.c src/depositcalc.h thirdparty/ctest.h -o build/depositcalc_test.o
