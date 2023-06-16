#include <stdio.h>
#include "util.h"


int main() {

    /* A fractional number: 13/7 */
    int num1 = 13, den1 = 7;
    /* A fractional number: 30/11 */
    int num2 = 30, den2 = 11;
    /* An unitilized fractional number */
    int num3, den3;

    printf("First number: ");
    fraction_print(num1, den1);
    printf("\n");

    printf("Second number: ");
    fraction_print(num2, den2);
    printf("\n");

    printf("Addition: ");
    fraction_add(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Subtraction: ");
    fraction_sub(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Multiplication: ");
    fraction_mul(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Division: ");
    fraction_div(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");
    
    int num_a,den_a;
    int num_b,den_b;
    int num_c,den_c;
    printf("Please type number's 1 numerator and denominator:\n");
    scanf("%d %d",&num_a,&den_a);
    while(den_a == 0){//We use this while loop because if user types 0 to denominator it makes this fraction undefined so
    printf("Please enter a number except 0 for denominator:\n");//this loop works until user types a number except 0.
    scanf("%d",&den_a);
    }
    
    
    printf("Please type number's 2 numerator and denominator:\n");
    scanf("%d %d",&num_b,&den_b);
    
    while(den_b == 0){ //we use this while loop because of the same reason
    printf("Please enter a number except 0 for denominator:\n");
    scanf("%d",&den_b);
    }

    printf("First number: ");
    fraction_print(num_a, den_a);
    printf("\n");

    printf("Second number: ");
    fraction_print(num_b, den_b);
    printf("\n");

    printf("Addition: ");
    fraction_add(num_a, den_a, num_b, den_b, &num_c, &den_c);
    fraction_print(num_c, den_c);
    printf("\n");

    printf("Subtraction: ");
    fraction_sub(num_a, den_a, num_b, den_b, &num_c, &den_c);
    fraction_print(num_c, den_c);
    printf("\n");

    printf("Multiplication: ");
    fraction_mul(num_a, den_a, num_b, den_b, &num_c, &den_c);
    fraction_print(num_c, den_c);
    printf("\n");

    printf("Division: "); 
    fraction_div(num_a,den_a,num_b, den_b, &num_c, &den_c);
    fraction_print(num_c, den_c);
    printf("\n");
    return(0);
}
    
