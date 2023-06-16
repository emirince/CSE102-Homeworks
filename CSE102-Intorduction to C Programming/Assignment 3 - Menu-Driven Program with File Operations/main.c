#include <stdio.h>
#include <math.h>

void write_file(int number){
    FILE *result;
    result = fopen("results.txt","a");
    fprintf(result,"%d ",number);
    fclose(result);
}

void print_file(){
    int num = 0;
    FILE *result;
    result = fopen("results.txt","r");

    while (!feof(result))
    {
       fscanf(result,"%d ", &num);
       printf("%d ", num);
    }
    fclose(result);
}

void temporary_file(int number_1, int number_2, int number_3, int length){
    FILE *temporary;
    temporary = fopen("temporary.txt","a");
    if(length == 3) fprintf(temporary,"%d %d %d ", number_1,number_2,number_3);
    else if(length == 2) fprintf(temporary,"%d %d ", number_1,number_2);
    else if(length == 1) fprintf(temporary,"%d ", number_1);
    fclose(temporary);
}

void sort_file(){
int temp,min1 = 0,min2 = 0,min3 = 0,max = 0;
    int length = 0;
    int num;
    int count = 0;
    int count2 = 0;
    FILE *result;
    result = fopen("results.txt","r");
    
    while(!feof(result)){
       fscanf(result,"%d ", &num);
       if(num > max) max = num;
       length++;
    }
    fclose(result);
    min1 = max;
    min2 = max;
    min3 = max;
    result = fopen("results.txt","r");
    
    while(!feof(result)){
       fscanf(result,"%d ", &num);
       if(num < min1){
          min3 = min2;
          min2 = min1;
          min1 = num;
       }else if(num < min2){
          min3 = min2;
          min2 = num;
       }else if(num < min3){
          min3 = num;
       }
    }
    fclose(result);
    
    if(length>=3){
       temporary_file(min1,min2,min3,3);
       length-=3;
       count+=3;
    }
    else if(length == 2){
       temporary_file(min1,min2,min3,2);
       length-=2;
    }
    else if(length == 1){
       temporary_file(min1,min2,min3,1);
       length-=1;
    }
    
    result = fopen("results.txt","r");
    FILE *temporary;
    temporary = fopen("temporary.txt","a");
    int a = 0,b = 0,c = 0;
    while(!feof(result)){
       fscanf(result,"%d ",&num);
       if(num == min1 && a == 0) a++;
       else if(num == min2 && b == 0) b++;
       else if(num == min3 && c == 0) c++;
       else{
          fprintf(temporary,"%d ",num);
       }
    }
    fclose(temporary);
    fclose(result);
    
    temporary = fopen("temporary.txt","r");
    result = fopen("results.txt","w");
    while(!feof(temporary)){
       fscanf(temporary,"%d ",&num);
       fprintf(result,"%d ",num);
    }
    fclose(temporary);
    fclose(result);

    while(length > 0 ){
    count2 = 0;
    min1 = max;
    min2 = max;
    min3 = max;
    
    result = fopen("results.txt","r");
    while(count2 < count) {
    fscanf(result,"%d ",&num);
    count2++;
    }

    while(!feof(result)){
       fscanf(result,"%d ", &num);
       if(num < min1){
          min3 = min2;
          min2 = min1;
          min1 = num;
       }else if(num < min2){
          min3 = min2;
          min2 = num;
       }else if(num < min3){
          min3 = num;
       }
    }

    fclose(result);

    temporary = fopen("temporary.txt","w");
    result = fopen("results.txt","r");
    count2 = 0;
    while(count2 < count){
       fscanf(result,"%d ", &num);
       fprintf(temporary,"%d ", num);
       count2++;
    }
    fclose(temporary);
    fclose(result);
    if(length>=3){
       temporary_file(min1,min2,min3,3);
       length-=3;
    }
    else if(length == 2){
       temporary_file(min1,min2,min3,2);
       length-=2;
    }
    else if(length == 1){
       temporary_file(min1,min2,min3,1);
       length-=1;
    }
    
    
    result = fopen("results.txt","r");
    FILE *temporary;
    temporary = fopen("temporary.txt","a");
    count2 = 0;
    while(count2 < count){
       fscanf(result,"%d ",&num);
       count2++;
    }
    a = 0;
    b = 0;
    c = 0;
    while(!feof(result)){
       fscanf(result,"%d ",&num);
       if(num == min1 && a == 0) a++;
       else if(num == min2 && b == 0) b++;
       else if(num == min3 && c == 0) c++;
       else{
          fprintf(temporary,"%d ",num);
       }
    }
    fclose(temporary);
    fclose(result);
    
    temporary = fopen("temporary.txt","r");
    result = fopen("results.txt","w");
    while(!feof(temporary)){
       fscanf(temporary,"%d ",&num);
       fprintf(result,"%d ",num);
    }
    fclose(temporary);
    fclose(result);
    count+=3;
    }
    
    printf("Sorting is complete.\n");
    printf("Result :\n");
    
    print_file();
}


int sum(int n1, int n2, int flag){

int i;
int sum=0;

switch(flag){
	case 0:
	for(i=n1+1;i<n2;i++){
		if(i%2==0){
		printf("%d ",i);
		sum=sum+i;
			if(i+1!=n2 && i+2!=n2){
				printf("+ ");
			}
		}
	}
	break;

	case 1:
	for(i=n1+1;i<n2;i++){
		if(i%2!=0){
		printf("%d ",i);
		sum=sum+i;
			if(i+1!=n2 && i+2!=n2){
				printf("+ ");
			}
		}
	}
	break;
}	
	return sum;
}

int multi(int n1, int n2, int flag){	

int i;
int product=1;

switch(flag){
	case 0:
	for(i=n1+1;i<n2;i++){
		if(i%2==0){
		printf("%d ",i);
		product=product*i;
			if(i+1!=n2 && i+2!=n2){
				printf("* ");
			}
		}
	}
	break;

	case 1:
	for(i=n1+1;i<n2;i++){
		if(i%2!=0){
		printf("%d ",i);
		product=product*i;
			if(i+1!=n2 && i+2!=n2){
				printf("* ");
			}
		}
	}
	break;
}	
	return product;

}

int isprime(int a){

double root=0;
root=sqrt(a);

int i;

int divisive;

for(i=2;i<=root;i++){
	if(a%i==0){
	return i;
	}
}
return 0;
}

int main(){

printf("Select Operation\n");
printf("1. Calculate sum/multiplication between two numbers\n");
printf("2. Calculate prime numbers\n");
printf("3. Show numbers sequence in file\n");
printf("4. Sort numbers sequence in file\n");
printf("-----------------------\n");

int operation; 
int sum_multi;
int flag;
int n1,n2;

scanf("%d",&operation);
while(operation!=1 && operation!=2&& operation!=3 && operation!=4){
printf("Your number must be between 1 and 4. Please enter again\n");
scanf("%d",&operation);
}


switch(operation){

case 1:
 
printf("Please enter '0' for sum, '1' for multiplication\n");
scanf("%d",&sum_multi);
while(sum_multi!=0 && sum_multi!=1){
printf("Your number must be 0 or 1. Please enter again\n");
scanf("%d",&sum_multi);
}

printf("Please enter '0' to work on even numbers, '1' to work on odd numbers\n");
scanf("%d",&flag);
while(flag!=0 && flag!=1){
printf("Your number must be 0 or 1. Please enter again\n");
scanf("%d",&flag);
}

printf("Please enter two different number: \n");
printf("Number 1: ");
scanf("%d",&n1);
printf("Number 2: ");
scanf("%d",&n2);

while(n1==n2){
printf("Your numbers must be different. Please enter a new number 2\n");
scanf("%d",&n2);
}


while(n1>n2){
int temp=0;
temp=n1;
n1=n2;
n2=temp;
}

int result=0;

switch(sum_multi){

case 0: 

printf("Result\n");
result=sum(n1,n2,flag);
printf("= %d\n",result);
write_file(result);
printf("The result is written to the result.txt file");
 
break; 

case 1:

printf("Result\n");
result=multi(n1,n2,flag);
printf("= %d\n",result);
write_file(result);
printf("The result is written to the result.txt file");

break;
}

break;


int prime;
int a;
int integer;

case 2:

printf("Please enter an integer: ");
scanf("%d",&integer);

for(a=2;a<integer;a++){
prime=isprime(a);

if(prime!=0){
	printf("%d is not a prime number, it is dividible by %d\n",a,prime);
}

else{
	printf("%d is a prime number\n",a);
}

}
 	
break;


case 3: 

print_file();

break;


case 4:

sort_file();

break;

}


}























