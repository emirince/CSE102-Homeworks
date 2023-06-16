#include <stdio.h>
#include "util.h"

int main() {

int x,y,z;
int dividend;
printf("Enter the first integer: ");
scanf("%d",&x);

printf("Enter the second integer: ");
scanf("%d",&y);

printf("Enter the dividor integer: ");
scanf("%d",&z);

dividend=find_divisible(x,y,z);
if(dividend==0)
{
printf("There is not any integer between %d and %d divided by %d\n",x,y,z);
}

else 
{
printf("The first integer between %d and %d divided by %d is %d\n",x,y,z,dividend);
}

/////////////////////////////////////////////

int n,f_i,next;
if(dividend!=0){
printf("Enter the how many next: ");
scanf("%d",&n);


f_i=dividend;

next=find_nth_divisible(n,f_i,z);

if(next<y)	//We check the return value if it's lower or greater than second integer
{
	printf("The %d. integer between %d and %d divided by %d is %d\n",n+1,x,y,z,next);
}

else
{
	printf("No possible to find %d. divisible between %d and %d divided by %d\n",n+1,x,y,z);
}
}
/////////////////////////////////////////////

char identify_number[20];
int id;
printf("Enter your identify number: ");
scanf("%s",identify_number);

id=validate_identify_number(identify_number);

while(id!=1)	//We want new input if user's input doesn't meet the requirments
{	printf("The id you entered is unvalid. Please try again: ");
	scanf("%s",identify_number);
	id=validate_identify_number(identify_number);
}





//////////////////////////////////////////////

int password;
int account;
int password_check;

if(id==1){
printf("Enter your password: ");
scanf("%d",&password);

while(password<1000 || password>9999){ 
	printf("Your password must be 4 digits. Please enter a new password: ");
	scanf("%d",&password);
	}


}

password_check=create_customer(identify_number,password);



//////////////////////////////////////////////
int id_check;

printf("Enter your identify number to login: ");
scanf("%s",identify_number);

printf("Enter your password to login: ");
scanf("%d",&password);



id_check=check_login(identify_number,password);

if(id_check==0)	//We check the login values that user enters.
{
	printf("Invalid identity number or password\n");

}

if(id_check==1)
{
	printf("Login successful\n");
}


//////////////////////////////////////////////


float cash_amount;
int money;
if(id_check==1){
printf("Enter the withdraw amount: ");
scanf("%f",&cash_amount);

money=withdrawable_amount(cash_amount);



while(cash_amount<0)
{
	printf("Your withdraw amount must be positive. Please try again: ");
	scanf("%f",&cash_amount);
	money=withdrawable_amount(cash_amount);
}

if(cash_amount>=0 && cash_amount<10)
{	
	printf("Withdrawble amount is 0. If you want to draw money, your request must be above 10.");
}

if(cash_amount >=10)
{
printf("Withdrawable amount is: %d\n",money);
}
}

}













