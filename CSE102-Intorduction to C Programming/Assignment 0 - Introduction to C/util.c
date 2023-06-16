#include <stdio.h>
#include "util.h"

void fraction_print(int numerator, int denominator) {
    printf("%d//%d", numerator, denominator);
}  /* end fraction_print */

void fraction_add(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 + n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_add */

void fraction_sub(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 - n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_sub */

void fraction_mul(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*n2;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_mul */

void fraction_div(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2;
    *d3 = d1*n2;
    fraction_simplify(n3, d3);
} /* end fraction_div */

/* Simplify the given fraction such that they are divided by their GCD */
void fraction_simplify(int * n, int * d) {
    int i;
    int gcd = 1;//This is greatest common divider. By while loop, we calculate this.
   		
    if(*n < 0 && *d < 0){ //Before while loop, we need to turn these numbers to the positive. So, we need this condition.
    *n= *n * (-1);
    *d = *d * (-1);
    }
   
    
    i=1;
    
    /* In this while condition, we try to find the greatest common divider of both numbers. Thus for each divider for both of 
    them we change it to gcd integer. We try this for until lowest of these numbers.*/
    
    while(i <= *n && i <= *d)
    {
    if(*n%i == 0 && *d%i == 0)
    {
        gcd = i;
    }
    
    i++;
    }
  
   *n = *n/gcd;
   *d = *d/gcd;
} /* end fraction_div */
