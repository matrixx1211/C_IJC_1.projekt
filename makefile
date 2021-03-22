# makefile
# Řešení IJC-DU1, příklad a), 23. 3. 2021
# Autor: Marek Bitomský, FIT
# Přeloženo: MinGW GCC 6.3.0
# ...popis příkladu - poznámky, omezení, atd

# proměnné
COMPILER = gcc
CFLAGS = -std=c11 -pedantic -Wall -Wextra -g 
MATH = -lm

all: primes primes-i steg-decode

run: primes primes-i
	time ./primes
	time ./primes-i

steg-decode: error.o eratosthenes.o bitset.h ppm.o steg-decode.o	
	$(COMPILER) $(CFLAGS) steg-decode.o error.o eratosthenes.o bitset.h ppm.o -o steg-decode $(MATH)

primes: primes.o error.o eratosthenes.o bitset.h
	$(COMPILER) $(CFLAGS) primes.o error.o eratosthenes.o bitset.h -o primes $(MATH)

primes-i: primes.o error.o eratosthenes.o bitset.h
	$(COMPILER) $(CFLAGS) primes.o error.o eratosthenes.o bitset.h -o primes-i $(MATH)

#########################
#		  PRIMES  		#
#########################

primes.o: primes.c
	$(COMPILER) $(CFLAGS) -c primes.c -o primes.o

eratosthenes.o: eratosthenes.c eratosthenes.h
	$(COMPILER) $(CFLAGS) -c eratosthenes.c -o eratosthenes.o

primes-i.o: primes.c
	$(COMPILER) $(CFLAGS) -DUSE_INLINE -c primes.c -o primes-i.o

#########################
#		STEGDECODE		#
#########################

error.o: error.c error.h
	$(COMPILER) $(CFLAGS) -c error.c -o error.o 

ppm.o: ppm.c ppm.h
	$(COMPILER) $(CFLAGS) -c ppm.c -o ppm.o

steg-decode.o: steg-decode.c
	$(COMPILER) $(CFLAGS) -c steg-decode.c -o steg-decode.o

#########################
#		  CLEAR 		#
#########################
clean: clear

clear:
	clear
	rm *.o primes primes-i steg-decode
