
/** PRIME NUMBERS AND COMPOSITE NUMBERS SUBSETS BETWEEN FIBONACCI WORDS by MARTE.BEST - Sylwester Bogusiak. 2019 AD v 0.9 beta **/

// Check how each subset of Primes resonate with Golden Number Phi= 1.618033... The Arithmetic Mean aka Average divided by upper Fibonacci from border = F(n) is near to, but lesser than Phi / 2... = 0.89... and closer with bigger values of Primes

// But Composite Numbers Average divided by Fib(n+1) is greater than Phi /2

// More info in my publication available on Researchgate.net: Arithmetic mean of subsets of prime numbers. A method that counts the convergence to the golden number Phi. 

// See also this thread on MATHFORUMS.COM: https://mathforums.com/t/arithmetic-mean-of-subsets-of-prime-numbers-a-method-that-counts-the-convergence-to-the-golden-number-phi.370710/
 
// PRIMES AND COMPOSITE SUBSETS 

// PACS algorithm - Primes And Composite Subsets

// Author: MARTE.BEST - Sylwester Bogusiak aka Sylvi91

// This is free code to calculate Fibonacci numbers and Prime Numbers and Composite Numbers

// There is no warranty or guarantee of any kind.

// To Compile:

// gcc -o pacs pacs.c -lm

// Usage in command line:

// ./pacs 10 30

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>



#define Phi 1.618033988749895


unsigned long long fib(int n) {
if ((n == 1) || (n == 2))
return 1;
else
return fib(n - 1) + fib(n - 2);
}


int main( int argc, const char* argv[] )
{

time_t start;

time_t end; // Get the system time

bool print = false;

int x;
int y;
unsigned long long i,j,k;

unsigned long long sum_p=0; 		/// sum of prime numbers
unsigned long long qty_p=0; 		/// qty of primes numbers in subset

unsigned long long sum_c=0; 		/// sum of composite numbers
unsigned long long qty_c=0; 		/// qty of composite numbers in subset


unsigned long long limit; 		/// limit of primes from fib

unsigned long long subset_start=0; 	/// 

unsigned long long subset_end=1;
unsigned long long tempNumber=0;


double approx_p_phi;
double approx_c_phi;
double avg_p=0;
double avg_c=0;

qty_p=0;
qty_c=0;


if ( argc >= 3 )
{
x = atoi( argv[1] );
y = atoi( argv[2] );


if ( argc == 4 )
{
if (!(strcmp(argv[3],"print")))
{
print = true;
}
}


time(&start); // Get the system time





if ((y>x) && (x>=4))


{




printf("________________________________________________________________________\n");

printf("____________THAT APP IS CALCULATING THE PRIME NUMBERS SUBSETS___________\n");

printf("_______________________AND COMPOSITE NUMBERS SUBSETS____________________\n");

printf("____________BETWEEN FIBONACCI AND FINDING APPROXIMATION_________________\n");

printf("______________________TO THE GOLDEN NUMBER_PHI._________________________\n");

printf("___________Author: MARTE.BEST - Sylwester Bogusiak aka Sylvi91__________\n");

printf("________________________________________________________________________\n");

printf(" Please wait for prime numbers generator. Warning! For second argument f2 greater than 45 this may take couple minutes. Bigger f2 consume more and more time and memory.\n");





limit = fib(y); /// only once

    // Allocate memory for prime array and initialize all
    // elements as true
    bool* prime = malloc((limit + 1) * sizeof(bool));
    for (int i = 0; i <= limit; i++)
        prime[i] = true;

    // 0 and 1 are not prime numbers
    prime[0] = prime[1] = false;

    // For each number from 2 to sqrt(n)
    for (int p = 2; p <= sqrt(limit); p++) {
        // If p is prime
        if (prime[p]) {
            // Mark all multiples of p as non-prime
            for (int i = p * p; i <= limit; i += p)
                prime[i] = false;
        }
    }


if (print)
{
    // Print all prime numbers up to n
    printf("Prime numbers up to %lld:\n", limit);
    for (int p = 2; p <= limit; p++) {
        if (prime[p])
            printf("%d ", p);
    }
    printf("\n");
}






subset_start=fib(x-1); /// For start

subset_end=fib(x); /// 




for (i=x;i<y;i++) /// Main loop
{

/// Fibo iteration
tempNumber = subset_start;

subset_start = subset_end;

subset_end = tempNumber + subset_start;

/// Zero values for new subset
sum_p = 0;
qty_p = 0;
sum_c = 0;
qty_c = 0;

avg_p = 0;
approx_p_phi = 0;
avg_c = 0;
approx_c_phi = 0;

if (print)

{
printf("\n Fib(%llu) = %llu - Fib(%llu) = %llu ",i, subset_start,i+1,subset_end);

printf("\n Primes and composite list: \n");
}


for (j = subset_start+1; j <= subset_end; j++) /// Count every single element
{


if (prime[j])
{

if (print)
printf(" p%llu ",j); /// Print if you need

sum_p += j;
qty_p += 1;

}
else
{

if (print)
printf(" n%llu ",j); /// Print if you need
sum_c +=j;
qty_c +=1;

}

}

if (j>=4)
{
avg_p = sum_p/qty_p;
avg_c = sum_c/qty_c;


approx_p_phi = ((avg_p/subset_end) *2);
approx_c_phi = ((avg_c/subset_end) *2);

printf("\n");

printf(" Fib(%llu) = %llu - Fib(%llu) = %llu SUM P = %llu QTY P = %llu AVG P = %.2f Phi P = %f\n",i,subset_start,i+1, subset_end, sum_p, qty_p, avg_p, approx_p_phi);
printf(" Fib(%llu) = %llu - Fib(%llu) = %llu SUM C = %llu QTY C = %llu AVG C = %.2f Phi C = %f\n",i,subset_start,i+1, subset_end, sum_c, qty_c, avg_c, approx_c_phi);
printf("\n");


if (approx_p_phi > Phi)
{
printf(" Phi P = %f > Phi\n", approx_p_phi);
}
else
if (approx_p_phi < Phi)
{
printf(" Phi P = %f < Phi\n", approx_p_phi);
}
else
if (approx_p_phi == Phi)
{
printf(" Phi P = %f = Phi\n", approx_p_phi);
}


if (approx_c_phi > Phi)
{
printf(" Phi C = %f > Phi\n", approx_c_phi);
}
else
if (approx_c_phi < Phi)
{
printf(" Phi C = %f < Phi\n", approx_c_phi);
}
else
if (approx_c_phi == Phi)
{
printf(" Phi C = %f = Phi\n", approx_c_phi);
}

printf("\n");
}

}


// Free allocated memory
free(prime);


time(&end); // End time


double dif;


dif = difftime (end,start); // time difference
printf ("Your calculations took %.2lf seconds to run.\n", dif ); // 

return 0;

}

} // if

printf(" Simple usage: pacs f1 f2 \n where f1 and f2 are natural numbers and Fibonacci words in sequence Fib(n) Fib(n+1) and f1 >= 4 and f2 > f1\n Warning! f2 should not exceed 50 for 8 GB RAM otherwise you will reach memory limit.\n");
printf(" Additionally to print all natural numbers use: pacs f1 f2 print\n");

 
 
return 0;

}
