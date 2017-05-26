.PHONY: all clean test

all: bin/calc
test: bin/test/calc_test

bin/calc:build/main.o build/depositcalc.o src/depositcalc.h
	gcc -Wall -Werror build/main.o build/depositcalc.o -o bin/calc
	
build/main.o: src/main.c src/depositcalc.h 
	gcc -I scr -Werror -Wall -c src/main.c -o build/main.o
	
build/depositcalc.o: src/depositcalc.c src/depositcalc.h
	gcc -Wall -Werror -c src/depositcalc.c -o build/depositcalc.o
	
clean:
	rm -f build/* build/* bin/calc*
	
bin/test/calc_test:build/main.o build/test/deposit-test.o build/test/validation-test.o
	gcc -Wall -Werror build/main.o build/deposit-test.o build/validation-test.o -o bin/test/calc_test
	
build/test/main.o:test/main.c 
	gcc -Wall -Werror -I thirdparty -I src test/main.c -o build/test/main.o
	
build/test/deposit-test.o: test/deposit-test.c src/depositcalc.h
	gcc -Wall -Werror test/deposit-test.c -o build/test/deposit-test.o
	
build/test/validation-test.o:test/validation-test.c
	gcc -Wall -Werror -I thirdparty -I rc test/validation-test.c -o build/test/validation-test.o
