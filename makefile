.PHONY: all clean test 


all: bin/calc
test: bin/test/calc

#all-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

bin/calc:build/main.o build/depositcalc.o src/depositcalc.h bin
	gcc -Wall -Werror -o bin/calc build/main.o build/depositcalc.o


bin:
	mkdir "bin"

build:
	mkdir "build"


build/main.o: src/main.c src/depositcalc.h build
	gcc -I src -Werror -Wall -c -o build/main.o src/main.c 

build/depositcalc.o: src/depositcalc.c src/depositcalc.h build
	gcc -Wall -Werror -c -o build/depositcalc.o src/depositcalc.c 

#test----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

bin/test/calc:build/test/main_test.o build/test/deposit-test.o build/test/validation-test.o build/depositcalc.o bin bin/test 
	gcc -Wall -Werror -o bin/test/calc_test build/test/main_test.o build/test/deposit-test.o build/test/validation-test.o build/depositcalc.o


bin/test:
	mkdir "bin/test"

build/test:
	mkdir "build/test"


build/test/main_test.o:test/main.c thirdparty/ctest.h build build/test
	gcc -Wall -Werror -I thirdparty -c test/main.c -o build/test/main_test.o

build/test/deposit-test.o: test/deposit-test.c src/depositcalc.h thirdparty/ctest.h build build/test
	gcc -Wall -Werror -I thirdparty -I src -c test/deposit-test.c -o build/test/deposit-test.o 

build/test/validation-test.o:test/validation-test.c src/depositcalc.h thirdparty/ctest.h build build/test
	gcc -Wall -Werror -I thirdparty -I src -c test/validation-test.c -o build/test/validation-test.o 

#clean---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

clean:
	rm -rf build/*.o bin/calc bin/test/calc_test build/test/*.o
