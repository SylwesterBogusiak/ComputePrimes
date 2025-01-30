
// Calculate Primes set at given limit and show it as a sets of four in a row (n*10)+1,(n*10)+3,(n*10)+7,(n*10)+9
// 
// PTOQR - PRIME NUMBERS TO QUADRUPLE ROWS
// Author: MARTE.BEST - Sylwester Bogusiak aka Sylvi91
// This is free code to calculate Prime numbers with use std math library
// There is no warranty or guarantee of any kind.

// To Compile:
// gcc -o ptoqr ptoqr.c -lm

// Usage:
// ./ptoqr 1 1000

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




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                 IS THIS PRIME NUMBER CLASSICAL VERSION

int is_this_prime_number(int natural_number)
{


int n, i, flag = 0;

    n=natural_number;

    for(i=2; i<=n/2; ++i)
    {
        // condition for nonprime number
        if(n%i==0)
        {
            flag=1;
            break;
        }
    }

    if (flag==0)
        return 0;           // 0 - jest prime
    else
        return 1;


    //return 0;
    }





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                 IS THIS PRIME NUMBER 3-7 FOR 1379 METHOD


int is_this_prime_number_3_7(unsigned long long int natural_number)
{


unsigned long long int i, n, flag = 0;

        n=natural_number;

   
        // condition for nonprime number
        
        if((n%3==0) || (n%7==0))
        {
            flag=1; // 1 - nonprime
            return 1; 
        }
  
            for(i=11; i<=sqrt(n); i=i+2)
    {
        // condition for nonprime number
        if(n%i==0)
        {
            flag=1;
            break;
        }
    }

    if (flag==0)
        return 0;           // 0 - is prime
    else
        return 1;


}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///  CALCULATE AND DISPLAY PRIMES

int calc_primes_1379(unsigned long long int begin, unsigned long long int end)
{


unsigned long long int i,n; 


unsigned long long int a;
unsigned long long int row_sum=0; // sum of prime numbers in a row
unsigned long long int row_qty=0; // qty of prime numbers in a row
unsigned long long int total_qty=0; // total qty of prime numbers
      
        
int four[4] = {1,3,7,9};


if ((end>=begin) && (begin>=1))


{




printf("________________________________________________________________________\n");
printf("______________________ PTO1379 aka PTOQR v.0.1 BETA ____________________\n");
printf("____________________ PRIME NUMBERS TO QUADRUPLE ROWS ___________________\n");

printf("____________ THAT APP IS CALCULATING THE PRIME NUMBERS _________________\n");

printf("_____ AND DISPLAYS IT AS 4 COLUMNS OF INTEGERS ENDED WITH 1,3,7,9 ______\n");

printf("____________ Author: MARTE.BEST - Sylwester B aka Sylvi91 ______________\n");

printf("________________________________________________________________________\n");

printf("_______________          Please wait. Warning!           _______________\n");
printf("__ For end limit greater than 100000000 this may take couple minutes. __\n");

printf("_______________ Bigger limit consume more and more time. _______________\n");
printf("________________________________________________________________________\n");




//print on screen
printf("* - PRIME, n - natural number\n ");
printf("       integers          sum  qty\n ");

if (begin == 1) 
{
printf("     *2,*3,*5,*7,        17   4,\n ");
total_qty = 4;
}



for (n = begin; n < end; n ++) 

{

row_sum=0;
row_qty=0;

for (i = 0; i < 4; i ++) 

{
a = (n * 10) + four[i];
//a = ((n<<3) + (n<<1)) + four[i];
        
       if (!is_this_prime_number_3_7(a))
        
       // if (!is_this_prime_number(a))
{
row_sum += a; row_qty++;
printf(" *%llu, ", a);
total_qty++;
//printf("*");
} 
else
{
printf(" n%llu, ", a);
//printf(" ");
}

    
        
}

printf(" %llu, ", row_sum); 
printf(" %llu, ", row_qty);
printf("\n ");

}


printf(" Total primes quantity between %llu and %llu is equal to: %llu ", begin, end * 10, total_qty);
printf("\n ");


}
        else
                
        {
           printf("Set properly begin and end of rows\n ");     
        }


return 0;

}




int main(int argc, char * argv[]) {

 


    	unsigned long long int b;
        unsigned long long int e;
        
      	if (argc <= 2)
      	{

        printf ("Usage: %s <begin of rows> <end of rows>\n", argv[0]);

        return 1;

      	}


        b=atol(argv[1]);
        e=atol(argv[2]);
        
      	assert(b >= 1);
        assert(e >= 2);
        
        
 	// Get system time START

      	#ifdef __APPLE__

        uint64_t start = mach_absolute_time();

    	#else

        clock_t start = clock();

    	#endif

 

        calc_primes_1379(b,e);  // Change the arguments b and e to adjust the begin and end of rows [1,3,7,9]

    
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


