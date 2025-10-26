
/** PRIME NUMBERS ON FIBONACCI SPIRAL by MARTE.BET - Sylwester Bogusiak. 2018 AD v 0.9 beta **/

// Each subset of Primes resonate with Golden Number Phi= 1.618033... The Arithmetic Mean aka Average divided by upper Fibonacci from border = F(n) is near to, but below Phi / 2... = 0.89... and closer with bigger values of Primes

// More info in my publication available on Researchgate.net: Arithmetic mean of subsets of prime numbers. A method that counts the convergence to the golden number Phi. 

// Link: https://www.researchgate.net/publication/385384830_Arithmetic_mean_of_subsets_of_prime_numbers_A_method_that_counts_the_convergence_to_the_golden_number_Phi

// See also this thread on MATHFORUMS.COM: https://mathforums.com/t/arithmetic-mean-of-subsets-of-prime-numbers-a-method-that-counts-the-convergence-to-the-golden-number-phi.370710/
 
// SHOW AND CALCULATE PRIMES ON FIBONACCI SPIRAL

// POFSpiral algorithm - Primes On Fibonacci Spiral

// Author: MARTE.BEST - Sylwester Bogusiak aka Sylvi91

// This is free code to calculate Fibonacci numbers and Prime Numbers and distribute it in between Fibonacci on Fibonacci Spiral

// There is no warranty or guarantee of any kind.

// The Allegro library has further restrictions.

// Tested on version Allegro 4.4

// To Compile:

// gcc -o pofspiral pofspiral.c -lm -lalleg

// Usage in command line:

// ./pofspiral  

#include <allegro.h>

#include <time.h>
#include <math.h>

#define BLACK makecol(0,0,0)
#define CLEAR makecol(255,0,255)
#define GREY makecol(127,127,127)
#define WHITE makecol(255,255,255)
#define RED makecol(255,0,0)
#define GREEN makecol(0,255,0)
#define BLUE makecol(0,0,255)


const int Screen_w = 1920;            // size of the screen
const int Screen_h = 1080;

int scroll_x=0;                        
int scroll_y=0;
double scale=1.0;             

int keypres=0;

enum keypres {Key_0,Key_1,Key_2,Key_6,Key_U};

BITMAP * back_screen=NULL;


      


static BITMAP * mouse_cursor = NULL;
static const double PI = M_PI;   // PI= 3.1415926535;
double angle;

double x=0.0,y=0.0,r=0.0;

int i,j;
int natural_number;

#define MAX_NUMBERS 12000 
#define MAX_PRIMES MAX_NUMBERS / 10

int prime_position=0;
int prime_table[MAX_NUMBERS][MAX_PRIMES];
int sum_primes[MAX_NUMBERS];        /// OK
int result=0;
#define CURSORSIZE 15  /// pixels
int numeration=10;      // decimal
#define PHI 1.618033988749894848204586834
#define EULER 2.7182818284590452353602874713527
#define ANGLE 180


//////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                 IS THIS FIBONACCI NUMBER
// A utility function that returns true if x is perfect square
int isPerfectSquare(int x)
{
    int s;

    s = sqrt(x);


    if (s*s == x) {return 0;}
    else
    return 1;

}

int is_this_fibonacci_number(int natural_number)
{


int n, i, flag1 = -1, flag2 = -1;

    n=natural_number;

    flag1 = isPerfectSquare(5*n*n + 4);

    flag2 = isPerfectSquare(5*n*n - 4);

    if ((flag1==0) || (flag2==0))
      { return 0;           // 0 - is fibonacci
      }
    else
        return 1;


    }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                 IS THIS PRIME NUMBER

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
///                                                 CENTER PICTURE
int center_picture()
{
                    scroll_x=Screen_w/2;                        
                    scroll_y=Screen_h/2;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                 SAVE PRIME TO LIST
void save_prime_to_list(int prime_number, int index_prime, int index_fibo)

{
    prime_table[index_fibo][index_prime]=prime_number;



}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                 FIND PRIMES BETWEEN FIBO


int find_primes_between_fibo(int fibo_previous, int fibo_present, int index_fibo)
{
        int j;

	int index_primes=0;
	index_primes=0;
        int natural_number;
        sum_primes[index_fibo]=0;

        for(j = fibo_previous+1; j <= fibo_present; j++)
        {
        natural_number=j;


        if (((is_this_prime_number(natural_number)==0) && natural_number>1))

        {  
        index_primes++;
	sum_primes[index_fibo]+=natural_number;    /// sum of primes
        save_prime_to_list(natural_number,index_primes,index_fibo);  /// save from 1
	}
	}

	return index_primes;              /// max_primes

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                 CHECK MOUSE POSITION AND HOVER

int check_mouse_position_and_hover(int xx,int yy, int scroll_x, int scroll_y,int cursor_size)

{

 
    int ix,iy;
    int mx,my;
    mx=scroll_x+mouse_x;

    my=scroll_y+mouse_y;

    for (ix=0;ix<cursor_size;ix++)
    for (iy=0;iy<cursor_size;iy++)

    if (mx<xx+ix+scroll_x && mx>xx-(2*ix)+scroll_x && my < yy+iy+scroll_y && my > yy-(2*iy)+scroll_y ) return 1;
    return 0;

}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                 DRAW FIBONACCI SPIRAL AND DISTRIBUTE PRIMES


int draw_primes_on_fibonacci_spiral()
{

   
    int direction=0;
    int direction_p=0;
    int index_primes=0;
    int max_primes[MAX_NUMBERS];
    double cx1[MAX_NUMBERS],cy1[MAX_NUMBERS];

    natural_number=-1;
   
    int queue=0;
    int previous_number=0;

    double x1[MAX_NUMBERS],x2[MAX_NUMBERS],y1[MAX_NUMBERS],y2[MAX_NUMBERS];
    double px1,py1;  //prime posxy
    int position=0;
    int index_fibo;
    index_fibo=-1;     
    index_primes=0;

    prime_position=1;  /// for table
    position=0;
    px1=py1=0.0;

    for(j = 0; j <= MAX_NUMBERS; j++)

    {

    x1[j]=0.0;
    x2[j]=0.0;
    y1[j]=0.0;
    y2[j]=0.0;

    //////////////////////////////////////////

    natural_number++;

    if ((is_this_fibonacci_number(natural_number) == 0) && (natural_number >=2))

    {  
        position=0; /// needed
       
        index_fibo++;

        double temp_natural,temp_prev;
        temp_natural=natural_number;
        temp_prev=previous_number;
        temp_natural*=scale;
        temp_prev*=scale;

        switch(direction)
        {

        case 0:         /// up just once
       
        break;

        case 1: /// bottom
        x1[index_fibo]=x1[index_fibo-1];
        y1[index_fibo]=y1[index_fibo-1]+temp_prev;
        x2[index_fibo]=x1[index_fibo]+temp_natural;
        y2[index_fibo]=y1[index_fibo]+temp_natural;

         break;

        case 2: /// right
        x1[index_fibo]=x1[index_fibo-1]+temp_prev;
        y1[index_fibo]=y1[index_fibo-1]-(temp_natural-temp_prev);
        x2[index_fibo]=x1[index_fibo]+temp_natural;
        y2[index_fibo]=y1[index_fibo]+temp_natural;
        break;

        case 3: /// up
        x1[index_fibo]=x1[index_fibo-1]-(temp_natural-temp_prev);           
        y1[index_fibo]=y1[index_fibo-1]-temp_natural;
        x2[index_fibo]=x1[index_fibo]+temp_natural;
        y2[index_fibo]=y1[index_fibo]+temp_natural;
        break;
        
        case 4: /// left
        x1[index_fibo]=x1[index_fibo-1]-temp_natural;
        y1[index_fibo]=y1[index_fibo-1];
        x2[index_fibo]=x1[index_fibo]+temp_natural;
        y2[index_fibo]=y1[index_fibo]+temp_natural;
        break;

        }

        int ai,bi,max_natural;
        int fix_x=0,fix_y=0;
        int old=0;       /// temp

        if (natural_number>=2)

        {

        double avg, phi_f1, phi_f2, sum_f;    
        max_natural=natural_number-previous_number;         /// actual difference between Fibonacci
        max_primes[index_fibo]=find_primes_between_fibo(previous_number, natural_number, index_fibo);     // actual max primes (quantiny in the subset between Fibonacci)
        avg = sum_primes[index_fibo] / max_primes[index_fibo];
        sum_f = sum_primes[index_fibo] / natural_number; 
        phi_f2 = avg / natural_number;
	phi_f1 = avg / previous_number;
	
        if (check_mouse_position_and_hover(scroll_x+x+x1[index_fibo],scroll_y+y+y1[index_fibo],scroll_x+x+x1[index_fibo]+temp_natural,scroll_y+y+y1[index_fibo]+temp_natural,CURSORSIZE))
        {
        textprintf_centre_ex(back_screen, font, scroll_x+x+x1[index_fibo]+temp_natural/2,scroll_y+y+y1[index_fibo]+temp_natural/2, RED, -1, "QTY = %d", max_primes[index_fibo]);      ///show qty of primes
        textprintf_centre_ex(back_screen, font, scroll_x+x+x1[index_fibo]+temp_natural/2,scroll_y+y+y1[index_fibo]+temp_natural/2+10, RED, -1, "SUM = %d", sum_primes[index_fibo]);      ///show sum primes
        textprintf_centre_ex(back_screen, font, scroll_x+x+x1[index_fibo]+temp_natural/2,scroll_y+y+y1[index_fibo]+temp_natural/2+20, BLACK, -1, "AVG = %10.2f", avg);      
        ///show average aka arithmetic mean 
        textprintf_centre_ex(back_screen, font, scroll_x+x+x1[index_fibo]+temp_natural/2,scroll_y+y+y1[index_fibo]+temp_natural/2+30, BLACK, -1, "SUM/F(n) = %.2f", sum_f);      ///show SUM / F(n)
        textprintf_centre_ex(back_screen, font, scroll_x+x+x1[index_fibo]+temp_natural/2,scroll_y+y+y1[index_fibo]+temp_natural/2+40, BLACK, -1, "AVG/F(n) = %.9f", phi_f2);      ///show that AVG / F(n) close to Phi / 2
        textprintf_centre_ex(back_screen, font, scroll_x+x+x1[index_fibo]+temp_natural/2,scroll_y+y+y1[index_fibo]+temp_natural/2+50, BLACK, -1, "AVG/F(n-1) = %.9f", phi_f1);      ///show that AVG / F(n-1) close to phi / 2
        
    }



        if (direction==1)      /// bottom
        {
        rect(back_screen,scroll_x+x+x1[index_fibo],scroll_y+y+y1[index_fibo],scroll_x+x+x2[index_fibo]-fix_x,scroll_y+y+y2[index_fibo]-fix_y, WHITE);
        /* Draw a white arc */
        arc(back_screen, scroll_x+x+x1[index_fibo]+temp_natural, scroll_y+y+y1[index_fibo], itofix(128), itofix(192), temp_natural, WHITE);

        bi=0;
        for (ai=previous_number+1;ai<=natural_number;ai++)
        {
        bi++;
        angle= (double) 90/max_natural*bi-(90*(direction))-90;
        r= (double) temp_natural;
        cx1[index_fibo] = r * cos(angle * PI / 180);
        cy1[index_fibo] = -r * sin(angle * PI / 180);

        if (((is_this_prime_number(ai)==0) && ai>1))
        {
        circlefill(back_screen,scroll_x+x+x1[index_fibo]+cx1[index_fibo]+temp_natural,scroll_y+y+y1[index_fibo]+cy1[index_fibo],2, WHITE);
        textprintf_centre_ex(back_screen, font,scroll_x+x+x1[index_fibo]+cx1[index_fibo]+temp_natural-10,scroll_y+y+y1[index_fibo]+cy1[index_fibo]+10, WHITE, -1, "%d", ai);      ///show sum primes
        }

        }
        }

        if (direction==2)         /// right
        {
        rect(back_screen,scroll_x+x+x1[index_fibo],y+scroll_y+y1[index_fibo],scroll_x+x+x2[index_fibo]-fix_x,scroll_y+y+y2[index_fibo]-fix_y, BLACK);
        arc(back_screen, scroll_x+x+x1[index_fibo], scroll_y+y+y1[index_fibo], itofix(192), itofix(256), temp_natural, BLACK);
        
        bi=0;
        for (ai=previous_number+1;ai<=natural_number;ai++)
        {
        bi++;
        angle= (double) 90/max_natural*bi-(90*(direction))+90;
        r= (double) temp_natural;
        cx1[index_fibo] = r * cos(angle * PI / 180);
        cy1[index_fibo] = -r * sin(angle * PI / 180);

        if (((is_this_prime_number(ai)==0) && ai>1))
        {
        circlefill(back_screen,scroll_x+x+x1[index_fibo]+cx1[index_fibo],scroll_y+y+y1[index_fibo]+cy1[index_fibo],2, BLACK);
        textprintf_centre_ex(back_screen, font,scroll_x+x+x1[index_fibo]+cx1[index_fibo]+10,scroll_y+y+y1[index_fibo]+cy1[index_fibo]+10, BLACK, -1, "%d", ai);      ///show sum primes

        if (ai==natural_number)
        line(back_screen,scroll_x+x+3*scale,scroll_y+y+1*scale,scroll_x+x+x1[index_fibo]+cx1[index_fibo],scroll_y+y+y1[index_fibo]+cy1[index_fibo],BLACK);
        }
        }
        }

        if (direction==3)        ///up
        {
        rect(back_screen,scroll_x+x+x1[index_fibo],y+scroll_y+y1[index_fibo],scroll_x+x+x2[index_fibo]-fix_x,scroll_y+y+y2[index_fibo]-fix_y, BLUE);
        arc(back_screen, scroll_x+x+x1[index_fibo], scroll_y+y+y1[index_fibo]+temp_natural, itofix(0), itofix(64), temp_natural, BLUE);

        bi=0;
        for (ai=previous_number+1;ai<=natural_number;ai++)
        {
        bi++;
        angle= (double) 90/max_natural*bi-(90*(direction))-90;
        r= (double) temp_natural;
        cx1[index_fibo] = r * cos(angle * PI / 180);
        cy1[index_fibo] = -r * sin(angle * PI / 180);

        if (((is_this_prime_number(ai)==0) && ai>1))
        {
        circlefill(back_screen,scroll_x+x+x1[index_fibo]+cx1[index_fibo],scroll_y+y+y1[index_fibo]+cy1[index_fibo]+temp_natural,2, BLUE);
        textprintf_centre_ex(back_screen, font, scroll_x+x+x1[index_fibo]+cx1[index_fibo]+10,scroll_y+y+y1[index_fibo]+cy1[index_fibo]+temp_natural-10, BLUE, -1, "%d", ai);      ///show sum primes
        }
        }
        }

        if (direction==4)          ///left
        {
        rect(back_screen,scroll_x+x+x1[index_fibo],y+scroll_y+y1[index_fibo],scroll_x+x+x2[index_fibo]-fix_x,scroll_y+y+y2[index_fibo]-fix_x, GREEN);
        arc(back_screen, scroll_x+x+x1[index_fibo]+temp_natural, scroll_y+y+y1[index_fibo]+temp_natural, itofix(64), itofix(128), temp_natural, GREEN);

        bi=0;
        for (ai=previous_number+1;ai<=natural_number;ai++)
        {
        bi++;
        angle= (double) 90/max_natural*bi-(90*(direction))+90;
        r= (double) temp_natural;
        cx1[index_fibo] = r * cos(angle * PI / 180);
        cy1[index_fibo] = -r * sin(angle * PI / 180);
        if (((is_this_prime_number(ai)==0) && ai>1))
        {
        circlefill(back_screen,scroll_x+x+x1[index_fibo]+cx1[index_fibo]+temp_natural,scroll_y+y+y1[index_fibo]+cy1[index_fibo]+temp_natural,2, GREEN);
        textprintf_centre_ex(back_screen, font,scroll_x+x+x1[index_fibo]+cx1[index_fibo]+temp_natural-10,scroll_y+y+y1[index_fibo]+cy1[index_fibo]+temp_natural-10, GREEN, -1, "%d", ai);      ///show sum primes

        if (ai==natural_number)
        line(back_screen,scroll_x+x+fix_x+3*scale,scroll_y+y+fix_y+1*scale,scroll_x+x+x1[index_fibo]+cx1[index_fibo]+temp_natural,scroll_y+y+y1[index_fibo]+cy1[index_fibo]+temp_natural,GREEN);
        }
        }
        }

        if (numeration == 10) textprintf_centre_ex(back_screen, font, x+x1[index_fibo]+20+scroll_x, y+y1[index_fibo]+10+scroll_y, RED, -1, "%d", natural_number);

        }       



        previous_number=natural_number;
       

        //////////////////////////////////////
        direction++;
        if (direction>4) direction=1;

        }    /// fibo

       

        }

/////////////////////////////////////////////// fibo


        if(key[KEY_W])
        {
        if (scale>0.05) scale-=0.01;
        }

        if(key[KEY_S])
        {
        if (scale<5) scale+=0.01;
        }

    return 0;




}






////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                 SHOW INFO
 
int show_info()
{

    if(!(key[KEY_I]))
    {
textout_ex(back_screen, font,"Press I for more info.", 830, 30, BLACK, -1);
    };

if((key[KEY_I]))
{




    textout_ex(back_screen, font,"Keyboard control:", 10, 0, BLACK, -1);

    textout_ex(back_screen, font,"Arrows (Left,Right,Up,Down) - move diagram.", 10, 10, BLACK, -1);

    textout_ex(back_screen, font,"C - center the picture.", 10, 20, BLACK, -1);
    textout_ex(back_screen, font,"W and S - scale picture.", 10, 30, BLACK, -1);
    textout_ex(back_screen, font,"ESC - exit the program.", 10, 50, BLACK, -1);
};

return 0;

};






////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                 SHOW WELCOME MESSAGE

int show_welcome_message()
{

while(!(key[KEY_SPACE]))

{

textout_ex(screen, font,"    Prime Numbers In 2D Geometry on Fibonacci spiral.             ", 700, 240, makecol(0,0,0), -1);

textout_ex(screen, font,"                   POFSPIRAL Version 0.9 (beta)                   ", 700, 260, makecol(0,0,0), -1);
textout_ex(screen, font,"This program is presenting prime numbers distributed in 2D space. ", 700, 280, makecol(0,0,0), -1);
textout_ex(screen, font,"   On next screen please use keyboard and mouse to manipulate.    ", 700, 450, makecol(0,0,0), -1);
textout_ex(screen, font,"                        Please press SPACE                        ", 700, 500, makecol(0,0,0), -1);
textout_ex(screen, font,"  Thank You. MARTE.BEST - Sylwester Bogusiak aka Sylvi91 AD 2018  ", 700, 520, makecol(0,0,0), -1);

textout_ex(screen, font," This program is using Allegro 4.2 library by Shawn Hargreaves    ", 700, 560, makecol(0,0,0), -1);



};
return 0;

};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                     KEYBOARD AND MOUSE

int keyboard_mouse_and_drawings()
   {


    if(key[KEY_LEFT]) scroll_x=scroll_x-10;
    if(key[KEY_RIGHT]) scroll_x=scroll_x+10;
    if(key[KEY_UP]) scroll_y=scroll_y-10;
    if(key[KEY_DOWN]) scroll_y=scroll_y+10;


    if(key[KEY_C])       //center spiral
    {
    center_picture();
    }

    draw_primes_on_fibonacci_spiral();

    // draw mouse cursor

    draw_sprite(back_screen,mouse_cursor,mouse_x,mouse_y);

    return 0;


}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                 MAIN


int main(void)
{

    keypres==Key_0;   ///

   /* you should always do this at the start of Allegro programs */
   if (allegro_init() != 0)
      return 1;

   /* set up the keyboard handler */
   install_timer();      //before install_mod

   install_keyboard();
   install_mouse();


   /* set a graphics mode sized 320x200 */
   set_color_depth(32);

   if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, Screen_w, Screen_h, 0, 0) != 0) {
    if (set_gfx_mode(GFX_SAFE, 320, 200, 0, 0) != 0) {
    set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
    allegro_message("Unable to set any graphic mode\n%s\n", allegro_error);
    return 1;
    }
    }

   /* set the color palette */
   set_palette(desktop_palette);

    if (back_screen==NULL)
    {
    back_screen=create_bitmap(Screen_w,Screen_h);
    clear_to_color(back_screen,CLEAR);  //wyczysc i ustaw przezroczyste tlo
    };

    if ( mouse_cursor==NULL)
    {
    mouse_cursor=create_bitmap(25,25);

    clear_to_color( mouse_cursor,CLEAR);
    circle( mouse_cursor,12,12,12,BLACK);
    circle( mouse_cursor,12,12,10,BLACK);

    line( mouse_cursor,0,12,25,12,BLACK);
    line( mouse_cursor,12,0,12,25,BLACK);

    };

    clear_to_color(screen,GREY);

    show_welcome_message();


    while(!(key[KEY_ESC]))
    {
        clear_to_color(back_screen,GREY);

        keyboard_mouse_and_drawings();
        show_info();
        blit(back_screen,screen,0,0,0,0,Screen_w,Screen_h); 

    }




    return 0;

};

END_OF_MAIN();

