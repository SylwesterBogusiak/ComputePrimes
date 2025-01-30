// Calculate Primes set at given limit and show it as a sets of four in a row (n*10)+1,(n*10)+3,(n*10)+7,(n*10)+9
// 
// PTOQRL - PRIME NUMBERS TO QUADRUPLE ROWS LONG
// Author: MARTE.BEST - Sylwester Bogusiak aka Sylvi91
// This is free code to calculate Prime numbers with use MPFR library
// There is no warranty or guarantee of any kind.

// To Compile:
// gcc -o ptoqrl ptoqrl.c -lm -lmpfr

// Usage:
// ./ptoqrl 1 1000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#include <mpfr.h>


#ifdef __APPLE__

#include <mach/mach_time.h>

#else

#include <time.h>

#endif




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                 IS THIS PRIME NUMBER - CLASSICAL VERSION

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
///                                                 IS THIS PRIME NUMBER 3-7 FOR 1379 METHOD STD MATH


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
///                                                 IS THIS PRIME NUMBER 3-7 FOR 1379 METHOD MPFR VERSION


int is_this_prime_number_3_7_mpfr(mpfr_t natural_number)
{


	mpfr_t r, i, n, one, three, seven, eleven, temp, sqrt_n; 

	int flag = 0;
	int decimals = 100;
	
	mpfr_inits2(decimals, one, three, seven, eleven, temp, sqrt_n, i, n, NULL);
	mpfr_set_ui(one,1, MPFR_RNDN);
	mpfr_set_ui(three,3, MPFR_RNDN);
	mpfr_set_ui(seven,7, MPFR_RNDN);
    	mpfr_set_ui(eleven,11, MPFR_RNDN);
       // n=natural_number;

   
        // conditions for nonprime number
        
    
	mpfr_fmod(three ,natural_number, three, MPFR_RNDN); 
	
	mpfr_fmod(seven ,natural_number, seven, MPFR_RNDN); 
	
	
	if((mpfr_cmpabs_ui(three,0)==0) || (mpfr_cmpabs_ui(seven,0)==0))
	
	
	
	
        {
            flag=1; // 1 - nonprime
            return 1; 
        }
  
	
    
  
    
    	mpfr_sqrt(sqrt_n, natural_number, MPFR_RNDN);
    
        
    	while(mpfr_cmpabs(eleven, sqrt_n) <= 0)
    	{
        	
        mpfr_fmod(temp, natural_number, eleven, MPFR_RNDN); 
	
	
	if((mpfr_cmpabs_ui(temp,0)==0))
	
    	{
            flag=1; // 1 - nonprime
        
        return 1;
        
           break; 
       // break;
        
        
    	}
        
        mpfr_add_si(eleven, eleven, 2, MPFR_RNDN);
        
    
    	}
    
    

    
    
    	mpfr_clears(one, three, seven, eleven, temp, sqrt_n, i, n, NULL);
    	if (flag==0)
        return 0;           // 0 - is prime
    	else
        return 1;

	
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///  CALCULATE AND DISPLAY PRIMES LONG VERSION

int calc_primes_1379_mpfr(char *b, char *e)
{


	int decimals;
	decimals = 100; 
	mpfr_t n, a, begin, end, row_sum, total_qty;
	
	mpfr_inits2(decimals, n, a, begin, end, row_sum, total_qty, NULL);
	
	
	
        
int four[4] = {1,3,7,9};
int i, row_qty;
	
	
mpfr_set_str(begin, b, 10, MPFR_RNDN);    // init of the loop begin
mpfr_set_str(end, e, 10, MPFR_RNDN);      // init of the loop end

mpfr_pow_ui(begin, begin, 3, MPFR_RNDN);  // Attention!!! power of 3
mpfr_add(end, begin, end, MPFR_RNDN);     // number of rows
	
mpfr_set_ui(total_qty, 0, MPFR_RNDN);
mpfr_set_ui(row_sum, 0, MPFR_RNDN);	
        
if (mpfr_cmpabs(end,begin) >0)


{




mpfr_printf("________________________________________________________________________\n");
mpfr_printf("____________________ PTO1379L aka PTOQRL v.0.2 BETA ____________________\n");
mpfr_printf("_____________ PRIME NUMBERS TO QUADRUPLE ROWS LONG VERSION _____________\n");

mpfr_printf("____________ THAT APP IS CALCULATING THE PRIME NUMBERS _________________\n");

mpfr_printf("_____ AND DISPLAYS IT AS 4 COLUMNS OF INTEGERS ENDED WITH 1,3,7,9 ______\n");

mpfr_printf("____________ Author: MARTE.BEST - Sylwester B aka Sylvi91 ______________\n");

mpfr_printf("________________________________________________________________________\n");

mpfr_printf("_______________          Please wait. Warning!           _______________\n");
mpfr_printf("__ For end limit greater than 100000000 this may take couple minutes. __\n");

mpfr_printf("_______________ Bigger limit consume more and more time. _______________\n");
mpfr_printf("________________________________________________________________________\n");




//print on screen
mpfr_printf("* - PRIME, n - natural number\n ");
mpfr_printf("       integers          sum  qty\n ");

	
	
	
if (mpfr_cmpabs_ui(begin,1) == 0)
{
    mpfr_printf("     *2,*3,*5,*7,        17   4,\n ");

		mpfr_set_ui(total_qty, 4, MPFR_RNDN);  // 4
}

  mpfr_set(n, begin, MPFR_RNDN);


while(mpfr_cmpabs(n, end) < 0)
{

   
  mpfr_set_ui(row_sum, 0, MPFR_RNDN);

  row_qty=0;

for (i = 0; i < 4; i ++) 

{

  mpfr_mul_ui(a,n,10,MPFR_RNDN);
  mpfr_add_si(a,a,four[i], MPFR_RNDN);
    
  
		
if (!is_this_prime_number_3_7_mpfr(a))
{


  mpfr_add(row_sum, row_sum, a, MPFR_RNDN);
  row_qty++;
  mpfr_add_si(total_qty, total_qty, 1, MPFR_RNDN);
  mpfr_printf(" *%.0RNf, ", a);
	   

} 
else
{

  mpfr_printf(" n%.0RNf, ", a);

}

    
        
}

    
    mpfr_printf(" %.0RNf, ", row_sum);
    mpfr_printf(" %d, ", row_qty);
    mpfr_printf("\n ");
	

    mpfr_add_si(n, n, 1, MPFR_RNDN); // increment n for while loop
 
}

  mpfr_printf(" Total primes quantity between %.0RNf and %.0RNf rows is equal to: %.0RNf ", begin, end, total_qty);
  printf("\n ");


}
        else
                
        {
           printf("Set properly begin and end of rows\n ");     
        }

  mpfr_clears(n, a, begin, end, row_sum, total_qty, NULL);
    
    
	
return 0;

}




int main(int argc, char * argv[]) {

 

		//unsigned long long int d; 	// decimals
    	char * b;   				// begin
        char * e;					// end
        
      	if (argc <= 2)
      	{

        printf ("Usage: %s <begin of rows(Attention!!! To the power of 3!)> <number of rows>\n", argv[0]);

        return 1;

      	}


        b=argv[1];
        e=argv[2];
        
      	assert(b != NULL);
        assert(e != NULL);
        
		    //d = atol(argv[3]);
		    //assert (d>=1);
	
        
 	      // Get system time START

      	#ifdef __APPLE__

        uint64_t start = mach_absolute_time();

    	  #else

        clock_t start = clock();

    	  #endif

 

        calc_primes_1379_mpfr(b,e);  // Change the arguments b and e to adjust the begin and end of rows [1,3,7,9]

    
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
        
      mpfr_free_cache();
    	return 0;

}


