#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "util.h"
#define CLOSE_ENOUGH 0.001

int main() {
    int problem;   	
	
    printf("Please Select The Problem: ");	//In this part, we are requesting infos from user about PL,PW,SW,SL values.
    scanf("%d",&problem);
   
    if(problem==1){

    double PL,PW,SL,SW;
    		    
    printf("Please enter the PL: ");
    scanf("%lf",&PL);
    
    printf("Please enter the PW: ");
    scanf("%lf",&PW);
    
    printf("Please enter the SL: ");
    scanf("%lf",&SL);
    
    printf("Please enter the SW: ");
    scanf("%lf",&SW);   
	    
    char flower_1=dt1a(PL,PW,SL,SW);		//In this part, we're sending PL,PW,SW,SL numbers to util.c file
    char flower_2=dt1b(PL,PW,SL,SW);	
    
 
    if(flower_1==flower_2){		//In this part, we printf name of flower if the return values are same. 
    	if(flower_1=='v'){
    	printf("Flower is virginica\n");
	}
    	if(flower_1=='e'){
    	printf("Flower is versicolor\n");
	}
	if(flower_1=='s'){
    	printf("Flower is setosa\n");
	}
	    
    }
    
    else{
    	if(flower_1=='v' && flower_2=='e'){
    	printf("First flower is: Virginica Second Flower is: Versicolor\n");		//In this part, we print name of flowers according to return values if return values are not same.
    	}
    	
    	if(flower_1=='v' && flower_2=='s'){
    	printf("First flower is: Virginica Second Flower is: Setosa\n");
    	}
    	
    	if(flower_1=='e' && flower_2=='v'){
    	printf("First flower is: Versicolor Second Flower is: Virginica\n");
    	}
    	
    	if(flower_1=='e' && flower_2=='s'){
    	printf("First flower is: Versicolor Second Flower is: Setosa\n");
    	}
    	
    	if(flower_1=='s' && flower_2=='v'){
    	printf("First flower is: Setosa Second Flower is: Virginica\n");
    	}
    	
    	if(flower_1=='s' && flower_2=='e'){
    	printf("First flower is: Setosa Second Flower is: Versicolor\n");
    	}
    	
    }	
  } 	
///////////////////////////////////////////////////////////////////////////////////
    else if(problem==2){
    
    double x1,x2,x3;	//In this part, we are requesting infos from user about x1,x2,x3,x4 and x5 numbers.
    int x4,x5;
    
    printf("Please Enter the x1: ");
    scanf("%lf",&x1);
    
    printf("Please Enter the x2: ");
    scanf("%lf",&x2);
    
    printf("Please Enter the x3: ");
    scanf("%lf",&x3);
    
    printf("Please Enter the x4: ");
    scanf("%d",&x4);
    while(x4!=1 && x4!=0)
   {
   	printf("Please enter just 1 or 0 for x4 : ");
   	scanf("%d",&x4);
   }
    
    printf("Please Enter the x5: ");
    scanf("%d",&x5);
    while(x5!=1 && x5!=0)
   {
   	printf("Please enter just 1 or 0 for x5: ");
   	scanf("%d",&x5);
   }
    
    double first,second;
    
    first=dt2a(x1,x2,x3,x4,x5);	 //In this part, we're sending x1,x2,x3,x4 and x5 numbers to util.c file
    second=dt2b(x1,x2,x3,x4,x5);

    if(first==second)
    {
    	printf("%lf",first);		
    }
    
    else{
    	if(abs(dt2a-dt2b)<=CLOSE_ENOUGH){
    		double average=(first+second)/2;	//If they're close enough, we get average of two return values and print it.
    		printf("%lf\n",average);
    	}
    	
    	else{
    		printf("First Result: %lf\nSecond Result: %lf\n",first,second);	//If they're not close enough, we print both of them.
    	}
    }
}
    
///////////////////////////////////////////////////////////////////////////////////
   else if(problem==3){
   
   int meal_dessert,diet,eating_habit; //In this part, we're requesting users informations to recommend best possible meal or dessert to user
   double body_mass_index,hours;
   
   printf("If you want meal, enter 1; If you want dessert, enter 2: ");
   scanf("%d",&meal_dessert);
   printf("\n");
   while(meal_dessert!=1 && meal_dessert!=2)
   {
   	printf("Please enter just 1 or 2: ");
   	scanf("%d",&meal_dessert);
   	printf("\n");
   }
   
   
   printf("Please enter your body mass index: ");
   scanf("%lf",&body_mass_index);
   printf("\n");
   while(body_mass_index<=0)
   {
   	printf("Please enter a positive integer: ");
   	scanf("%lf",&body_mass_index);
   	printf("\n");
   }
   
   
   printf("Please enter how many hours ago you ate your previous meal: ");
   scanf("%lf",&hours);
   printf("\n");
   while(hours<=0)
   {
   	printf("Please enter a positive integer: ");
   	scanf("%lf",&hours);
   	printf("\n");
   }
   
   
   printf("1-Vegeterian\n2-Meat Eater\n");
   printf("Please enter 1 or 2 depends on your eating habit: ");
   scanf("%d",&eating_habit);
   printf("\n");
   while(eating_habit!=1 && eating_habit!=2)
   {
   	printf("Please enter just 1 or 2: ");
   	scanf("%d",&eating_habit);
   	printf("\n");
   }
   
   
   printf("Are you on diet? If you're please, enter 1; if you aren't please, enter 0\n");
   printf("(If you're on diet, your meal or dessert will be under 500 calories): ");
   scanf("%d",&diet);
   printf("\n");
   while(diet!=1 && diet!=0)
   {
   	printf("Please enter just 1 or 0: ");
   	scanf("%d",&diet);
   	printf("\n");
   }
   
dt3a(meal_dessert,diet,eating_habit,body_mass_index,hours);  //In this part, we're sending user's informations to util.c file
dt3b(meal_dessert,diet,eating_habit,body_mass_index,hours);
   
   }  
///////////////////////////////////////////////////////////////////////////////////     
   else{
     	printf("Please enter 1,2 or 3\n");
     }	
   
   
   
    return 0;
}
