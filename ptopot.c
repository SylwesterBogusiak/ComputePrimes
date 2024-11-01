// Calculate Primes set at given limit and show it as sum of geometrical set powers of two
// PTOPOT - PRIME TO POWERS OF TWO 
// Author: MARTE.BEST - Sylwester Bogusiak aka Sylvi91
// This is free code
// There is no warranty or guarantee of any kind.

// To Compile:
// gcc -o ptopot ptopot.c -lm

// Usage:
// ./ptopot 1000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#ifdef __APPLE__

#include <mach/mach_time.h>

#else

#include <time.h>

#endif



#define Phi 1.618033988749895

#define BITS 8
#define PIECES 7


// Check whether x is a prime or not
unsigned long long ifnotPrime(char prime[], unsigned long long x)
{

return (prime[x/BITS] & (1 << ((x >> 1) & PIECES) ) );

}


// Set the appropriate bit
unsigned long long makeComposite(char prime[], unsigned long long x)
{
prime[x/BITS] |= (1 << ((x >> 1) & PIECES)); /// ok for test fast ok

return 0;

}

// Returns the powers of two

unsigned long long int* primeToPot(unsigned long long int a, int *len){
        int arrayLen=0;
        unsigned long long i=1;
        while (i<a){
            arrayLen++;
            i*=2;
        }
        *len=arrayLen;
        unsigned long long int *bits;
        bits=(unsigned long long int*)malloc(arrayLen*sizeof(unsigned long long int));
        arrayLen--;
        i=0;
        while(a>0){
       
        
           bits[arrayLen]=a&1;
             
           
           if(bits[arrayLen] != 0)
           {
           bits[arrayLen] = pow(2,i);
           }
          
           i++;
           arrayLen--;
           a>>=1;
        }
        return bits;
     }
////////////////////////////////////////////


int calc(unsigned long long int limit)
{




	unsigned long long i,j,k;
	int len = 32;
	unsigned long long int * bits;
	int a;


	if (limit>=3)

	{

	printf("________________________________________________________________________\n");
	printf("____________THAT APP IS CALCULATING THE PRIME NUMBERS SET_______________\n");
	printf("_____UP TO THE GIVEN LIMIT AND DISPLAYS IT AS SET OF POWERS OF TWO______\n");
	printf("_____________Author: Sylwester B aka Sylvi91____________________________\n");
	printf("________________________________________________________________________\n");
	printf("_______________Please wait for primes generator. Warning!_______________\n");
	printf("___For argument greater than 1000000000 this may take couple minutes.___\n");
	printf("______________Bigger limit consume more and more memory.________________\n");
	printf("________________________________________________________________________\n");



	char * prime;
	prime = (char*) malloc(sizeof(char)*limit/BITS); // memory allocaion

	if (prime==NULL) exit (1);

	memset(prime, 0, sizeof(prime)); // init



	// Eratosthenes Sieve
	for (i = 3; i * i <= limit; i += 2) {
	if (!ifnotPrime(prime, i))
	for ( j = i * i, k = i << 1; j < limit; j += k)
	makeComposite(prime, j);
	}


	// print primes
 	printf(" 2, ");

	for (int i = 3; i <= limit; i += 2)
	if (!ifnotPrime(prime, i))
	{
	printf("%d, ", i);
	}
	printf("\n");

	// Print primes and powers of two
	printf(" 2  2\n");
	
	for (i=3;i<=limit;i+=2) /// main loop
	{
	if (!ifnotPrime(prime, i)) /// prime or not
	{


    	bits = primeToPot(i,&len);
    	printf(" %llu ", i); /// wypisz jak chcesz
	for (a=0;a<len;a++)
    	{
    	printf(" %llu ", bits[a]); /// wypisz jak chcesz
    	};

    	printf("\n");


	}

	}

	free(prime); // zwolnij pamiec

	}




return 0;

}




int main(int argc, char * argv[]) {

 


    	unsigned long long int i;

      	if (argc <= 1)
      	{

        printf ("Usage: %s <limit of integers>\n", argv[0]);

        return 1;

      	}


      	i = atoll(argv[1]);

      	assert(i >= 1);

 	// Get system time START

      	#ifdef __APPLE__

        uint64_t start = mach_absolute_time();

    	#else

        clock_t start = clock();

    	#endif

 

        calc(i);  // Change the argument i to adjust the limit of integers

    
 	// Get system time END

    	#ifdef __APPLE__

        uint64_t end = mach_absolute_time();

        mach_timebase_info_data_t timebase_info;

        mach_timebase_info(&timebase_info);

        long double diff = (end - start) * timebase_info.numer / timebase_info.denom; // nano sec

    
        printf("Your calculations took %.3Lf seconds to run.\n", diff / 1e9 );

    	#else

        clock_t end = clock();

        printf("Your calculations took %.3Lf seconds to run.\n", (long double)(end - start) / CLOCKS_PER_SEC );

    	#endif


    	return 0;

}



