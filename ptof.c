// Calculate Primes set at given limit and show it as set of fibonacci numbers
// Use Zeckendorf's theorem. It finds representation of n as sum of non-neighbouring Fibonacci Numbers.
// PTOF - PRIMES TO FIBONACCI 
// Author: MARTE.BEST - Sylwester Bogusiak aka Sylvi91
// There is no warranty or guarantee of any kind.

// To Compile:
// gcc -o ptof ptof.c

// Usage:
// ./ptof 1000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
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
prime[x/BITS] |= (1 << ((x >> 1) & PIECES));

return 0;

}

// Returns the greatest Fibonacci Number smaller than
// or equal to n.
unsigned long long int nearestSmallerEqFib(int n)
{
    // Corner cases
    if (n == 0 || n == 1)
        return n;
 
    // Find the greatest Fibonacci Number smaller
    // than n.
    unsigned long long int f1 = 0, f2 = 1, f3 = 1;
    while (f3 <= n) 
    {
        f1 = f2;
        f2 = f3;
        f3 = f1 + f2;
    }
    return f2;
}
 
// Prints Fibonacci Representation of n using
// greedy algorithm
void printFibRepresntation(unsigned long long int n)
{
        
        
        printf(" %llu       ", n);
        
    while (n > 0)
    {
        // Find the greates Fibonacci Number smaller
        // than or equal to n
        unsigned long long int f = nearestSmallerEqFib(n);
 
        // Print the found fibonacci number
        printf(" %llu ", f);
            
        // Reduce n
        n = n - f;
    }
        printf("\n");
}


// Calculate
int calc(unsigned long long int limit)
{


unsigned long long i,j,k;


	if (limit>2)


	{



	printf("________________________________________________________________________\n");

	printf("____________THAT APP IS CALCULATING THE PRIME NUMBERS SET_______________\n");

	printf("______UP TO THE GIVEN LIMIT AND DISPLAYS IT AS SET OF FIBONACCI_________\n");


	printf("_____________Author: Sylwester B aka Sylvi91____________________________\n");

	printf("________________________________________________________________________\n");

	printf("_______________Please wait for primes generator. Warning!_______________\n");
	printf("___For argument greater than 1000000000 this may take couple minutes.___\n");

	printf("______________Bigger limit consume more and more memory.________________\n");
	printf("________________________________________________________________________\n");



	char * prime;
	prime = (char*) malloc(sizeof(char)*limit/BITS); // alokacja pamieci

	if (prime==NULL) exit (1);

	memset(prime, 0, sizeof(prime)); // init with 0

	// Eratosthenes sieve.

	for (i = 3; i * i <= limit; i += 2) {
	if (!ifnotPrime(prime, i))
	for ( j = i * i, k = i << 1; j < limit; j += k)
	makeComposite(prime, j);
	}


	// print
	printf("2, ");

	
	for (int i = 3; i <= limit; i += 2)
	if (!ifnotPrime(prime, i))
	{
	printf("%d, ", i);
	}
	printf("\n");

	printf(" 2        2\n");
	for (i=3;i<=limit;i+=2) // main loop
	{
	if (!ifnotPrime(prime, i)) /// prime or not

	{

        printFibRepresntation(i);
        
	}

	}

	free(prime); // zwolnij pamiec

	}


	return 0;

}



// Main function
int main(int argc, char * argv[]) {

 


    	unsigned long long int i;

      	if (argc <= 1)
      	{

        printf ("Usage: %s <limit of integers>\n", argv[0]);

        return 1;

      	}


      	i = atoll(argv[1]);

      	assert(i >= 2);
      	
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



