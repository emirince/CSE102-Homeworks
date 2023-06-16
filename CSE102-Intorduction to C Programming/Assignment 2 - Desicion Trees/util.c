#include <stdio.h>
#include <math.h>
#include "util.h"

char dt1a(double PL, double PW, double SL,double SW){
   	
    if(PL<2.45){	//In this part, we return char values according to if else blocks
    return 's'; 		
    }
    
    else{
    	if(PW<1.75){
    		if(PL<4.95){
			if(PW<1.65){	
			return 'e';	    			
    			}
    			else{
    			return 'v';
    			}	
    		}
    		else{
    		return 'v';
    		}		
    	}
    	else{
    	return 'v';	
    	}
   }
}
char dt1b(double PL, double PW, double SL,double SW){

    if(PL<2.55){	//In this part, we return char values that we found according to if else blocks
    return 's';
    }

    else{
	if(PW<1.75){
		if(PL<4.95){
			if(PW<1.65){
			return 'e';
			}
			else{
			return 'v';
		        }
		}
		else{
		return 'v';
		}
		
	}
	else{
	return 'v';
	}
		}
	}

double dt2a(double x1,double x2,double x3, int x4, int x5){

	if(x1<31.5){			//In this part, we return values that we found according to if else blocks
		if(x2>-2.5){
		return 5.0;
		}
		else{
			if(x2<=x1+0.1 && x1<=x2+0.1){
			return 2.1;
			}
			else{
			return -1.1;
			}
		}	
	}	
	
	
	else{
		if(x3>=-1 && x3<=2){
		return 1.4;
		}
		
		else{
			if(x1==1 && x2==1){
			return -2.23;
			}
			else{
			return 11.0;
			}
		}	
	}
	
}	
double dt2b(double x1,double x2,double x3, int x4, int x5){	
	
	
	if(x1>12 && x1<22){			//In this part, we return values that we found according to if else blocks
		if(x3>5/3){
		return -2.0;
		}
		else{
			if(x3>=x1-0.1 && x3<=x1+0.1){
			return 1.01;
			}
			else{
			return -8;
			}
		}			
	}
	
	else{
		if(x4==1 && x5==1){
			return -1;
		}
		
		else{
			if(x2>=-1 && x2<=2){
			return -0.142;
			}
			
			else{
			return 0.471;
			}
		}
	}
}	
	

void dt3a(int meal_dessert,int diet,int eating_habit,double body_mass_index,double hours){

	if(meal_dessert==1){	
		if(body_mass_index<=25){
			if(hours<=6)			//In this part, we print menus that we found in if else blocks according to users inputs
			{
				if(diet==1){
					if(eating_habit=1){
						printf("According to first tree your meal: Broccoli Soup and Greek Salad(396 Calories)\n");
					}
					else{
						printf("According to first tree your meal: Chicken Soup and Baked Salmon(479 Calories)\n");
					}								
				}				
				else{
					if(eating_habit=1){
						printf("According to first tree your meal: Curried Pumpkin Soup and Falafel(645 Calories)\n");
					}
					else{
					 	printf("According to first tree your meal: Ground Beef Soup and Adana Kebab(768 Calories)\n");	
					}
				}				
			}			
			else{
				if(eating_habit=1){
					printf("According to first tree your meal: Broccoli Soup and Greek Salad(396 Calories)\n");
				}
				else{
					printf("According to first tree your meal: Chicken Soup and Baked Salmon(479 Calories)\n");
				}
			}				
		}		
		else{
			if(eating_habit=1){
				printf("According to first tree your meal: Broccoli Soup and Greek Salad(396 Calories)\n");
			}
			else{
				printf("According to first tree your meal: Chicken Soup and Baked Salmon(479 Calories)\n");
			}				
		}					
	}
	else{
		if(body_mass_index<=25){		
			if(diet==1){
				printf("According to first tree your dessert: Oatmeal Muffins and Black Coffee(330 Calories)\n"); 	
			}
			
			else{
				printf("According to first tree your dessert: Red Velvet Cake and Chocolate Milkshake(570 Calories)\n");
			}			
		}		
		else{
			printf("According to first tree your dessert: Oatmeal Muffins and Black Coffee(330 Calories)\n");		
		}		
	}		
}





void dt3b(int meal_dessert,int diet,int eating_habit,double body_mass_index,double hours){
	
if(meal_dessert==1){	
		if(body_mass_index<=30){	//In this part, we print menus that we found in if else blocks according to users inputs
			if(hours<=8)
			{
				if(diet==1){
					if(eating_habit=1){
						printf("According to second tree your meal: Broccoli Soup and Greek Salad(396 Calories)\n");
					}
					else{
						printf("According to second tree your meal: Chicken Soup and Baked Salmon(479 Calories)\n");
					}								
				}				
				else{
					if(eating_habit=1){
						printf("According to second tree your meal: Curried Pumpkin Soup and Falafel(645 Calories)\n");
					}
					else{
					 	printf("According to second tree your meal: Ground Beef Soup and Adana Kebab(768 Calories)\n");	
					}
				}				
			}			
			else{
				if(eating_habit=1){
					printf("According to second tree your meal: Broccoli Soup and Greek Salad(396 Calories)\n");
				}
				else{
					printf("According to second tree your meal: Chicken Soup and Baked Salmon(479 Calories)\n");
				}
			}				
		}		
		else{
			if(eating_habit=1){
				printf("According to second tree your meal: Broccoli Soup and Greek Salad(396 Calories)\n");
			}
			else{
				printf("According to second tree your meal: Chicken Soup and Baked Salmon(479 Calories)\n");
			}				
		}					
	}
	else{
		if(body_mass_index<30){		
			if(diet==1){
				printf("According to second tree your dessert: Oatmeal Muffins and Black Coffee(330 Calories)\n"); 	
			}
			
			else{
				printf("According to second tree your dessert: Red Velvet Cake and Chocolate Milkshake(570 Calories)\n");
			}			
		}		
		else{
			printf("According to second tree your dessert: Oatmeal Muffins and Black Coffee(330 Calories)\n");		
		}		
	}		
}	

	
	
	
	
	
		
		
		
		
	

/* Provide your implementations for all the requested functions here */
