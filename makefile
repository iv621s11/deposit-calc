.PHONY: all clean test


all: bin/calc
test: bin/calc_test


bin/calc:build/main.o build/depositcalc.o src/depositcalc.h
	gcc -Wall -Werror -o bin/calc build/main.o build/depositcalc.o


build/main.o: src/main.c src/depositcalc.h 
	gcc -I src -Werror -Wall -c -o build/main.o src/main.c 

build/depositcalc.o: src/depositcalc.c src/depositcalc.h
	gcc -Wall -Werror -c -o build/depositcalc.o src/depositcalc.c 


bin/calc_test:build/main_test.o build/deposit-test.o build/validation-test.o build/depositcalc.o
	gcc -Wall -Werror -o bin/calc_test build/main_test.o build/deposit-test.o build/validation-test.o build/depositcalc.o


build/main_test.o:test/main.c thirdparty/ctest.h
	gcc -Wall -Werror -I thirdparty -c -o build/main_test.o test/main.c

build/deposit-test.o: test/deposit-test.c src/depositcalc.h thirdparty/ctest.h
	gcc -Wall -Werror  -c -o build/deposit-test.o test/deposit-test.c

build/validation-test.o:test/validation-test.c src/depositcalc.h thirdparty/ctest.h
	gcc -Wall -Werror -I thirdparty  -c -o build/validation-test.o test/validation-test.c


clean:
	rm -rf build/*.o bin/calc bin/calc_test
