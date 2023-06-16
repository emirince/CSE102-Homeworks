#include <stdio.h>
#include "util.h"

int find_divisible(int x,int y,int z){

int dividend;
int i;
int check=0;

for(i=x+1;i<y;i++)
{	
	if(i%z==0)
	{
	check++;     //We need to find the first divided number. So when we find it, we stop the loop.
	dividend=i;
	break;
	}

}

if(check==0)
{
	return 0;    //If we can't find, we return the 0 value.
}

if(check==1)
{
	return dividend; //If we find the dividend number, we return this integer.	
}
}

int find_nth_divisible(int n,int f_i,int z){

int i,check=0;

for(i=1;i<=n;i++)
{
	f_i=f_i+z;    //We add the divisor how many times the user asks to first dividend number.
}
	
return f_i;	//We return the value that we find in the previous for loop.
}

int validate_identify_number(char identify_number[20]){

int check=0;

int i=0;

int size=0;

while(identify_number[i]!='\0')
{
	size++;
	i++;		//We check if the user's input's length is 11.
}

if(size==11)
{
	check++;
}	

if(identify_number[0]!='0')
{
	check++;	//We check if the user's input's starts with 0 or not.
}

int control=0;

int j;

for(j=0;j<11;j++)	//We check if the user's input's consist of only numbers or not.
{
	if((identify_number[j]-48)<=9 && (identify_number[j]-48)>=0)
	{
		control++;
	}
}

if(control==11)
{
	check++;
}

int odd=0,even=0;

for(i=0;i<=8;i++){	

if(i%2==0)
{
	odd=odd+(identify_number[i]-48);
}

if(i%2==1)
{
	even=even+(identify_number[i]-48);
}
}


if((7*odd-even)%10==(identify_number[9]-48))
{
	check++;
}

int sum=0;

for(i=0;i<=9;i++)
{
	sum=sum+identify_number[i];
}

if(sum%10==(identify_number[10]-48))
{
	check++;
}

if(check==5)
{ 
	return 1;	//If the user's input meets all the conditions, we return 1 value,
}
	
if(check!=5)		//If the user's input doensn't meet all the conditions, we return 0 value,
{
	return 0;
}
}



int create_customer(char identify_number[],int password){ 	//We create a file and print the user's input the file.

	
	FILE *fp;
	fp=fopen("customeraccount.txt","w");
	fprintf(fp,"%s,%d",identify_number,password);
	fclose(fp);
	
	
return 0;

}

int check_login(char identify_number[],int password){
	
	char identify_txt[11];
	int password_txt;

	FILE *fs;
	if(fs=NULL){
		printf("Unable to open the customeraccount.txt");
	}
	
	else{
		fs=fopen("customeraccount.txt","r");
		fscanf(fs,"%[^,],%d",identify_txt,&password_txt);	//We scan the files and get input from the file.
		fclose(fs);
		
		}
	int i,id_check=0,password_check;
	
	for(i=0;i<11;i++){
		
		if(identify_txt[i]==identify_number[i])	//We compare the input and the received data from the file
		{						// and we check them wheter they are same or not.
			id_check++;
		}
		
	
	}
	
	for(i=0;i<4;i++){
		
		if(password_txt!=password)
		{						//We compare the input and the received data from the file
								// and we check them wheter they are same or not.
		password_check=1;
		}	
		
		else
		{
    		password_check=0;
     		}
	
     }
     
     if(id_check==11 && password_check==0)
     {
     	return 1;				//If they are same, we return 1 value.
     }
     
     if(id_check!=11|| password_check==1)
     {
     	return 0;				//If they are not same, we return 0 value.
     }
     
     
     }
  

int withdrawable_amount(float cash_amount){

int i,money;
			
for(i=cash_amount;i>0;i--)			//We find the withdrawble amount thanks to this loop.
{
	if(i%10==0)
	{
		money=i;
		break;
	}
}

return money;					//We return the withdrawble money

}











