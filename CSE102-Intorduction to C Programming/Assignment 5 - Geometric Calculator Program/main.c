#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14

enum shapes {first_1,Triangle,Quadrilateral,Circle,Pyramid,Cylinder};       //These are the names of the shapes and calculates that we use in this code
enum calculators {first_2,Area,Perimeter,Volume};

int calc_triangle(int n);
int calc_quadrilateral(int n);
int calc_circle(int n);
int calc_pyramid(int n);
int calc_cylinder(int n);

int isValid(){

fflush(stdin); 
int num=0;
int ch;
int check=0;
 
ch=getchar();
while(ch!='\n')         //this loop goes until user inputs enter key
{   
    if(ch>=48 && ch<=57)
    {
        num=num*10+(ch-48);
    }
            
    else 
    check++;
    ch=getchar();
}
   
if(check==0)        //if input is valid, we return the number
return num;

else 
return -100;        //if input is not valid, we return -100 

}

int select_shape(){

int input,control;

printf("Select a shape to calculate: \n");
printf("----------------------------\n");
printf("1. Triangle\n");
printf("2. Quadrilateral\n");
printf("3. Circle\n");
printf("4. Pyramid\n");
printf("5. Cylinder\n");
printf("0. Exit\n");
printf("----------------------------\n");
printf("Input: ");

control=isValid();
while (control==-100 || control<0 || control>5)
{                                                           //if input is not valid or its higher than 5 or lower than 0, code requests another input
    printf("ERROR ! Please enter a valid entry.\n");
    control=isValid();
}

printf("\n");

return control;

}

int select_calc(){

int num=0,kontrol;

printf("Select Calculator\n");
printf("----------------------------\n");
printf("1. Area\n");
printf("2. Perimeter\n");
printf("3. Volume\n");
printf("0. Exit\n");
printf("----------------------------\n");
printf("Input: ");

kontrol=isValid();
while (kontrol==-100 || kontrol<0 || kontrol>3)
{
    printf("ERROR ! Please enter a valid entry.\n");        //if input is not valid or its higher than 3 or lower than 0, code requests another input
    kontrol=isValid();
}

printf("\n");  
return kontrol;
}

int calculate(int (*a)(),int(*b)()){

int x,y;

x = a();
if (x==0)
{
    return 0;
}
y = b();
if (y==0)
{
    return 0;
}

switch (x)
{
case Triangle:
calc_triangle(y); 
break;
    
case Quadrilateral:
calc_quadrilateral(y);
break;

case Circle:
calc_circle(y);
break;
    
case Pyramid:
calc_pyramid(y);
break;

case Cylinder:
calc_cylinder(y);
break;

default:
break;
} 
}

int calc_triangle(int n){

float perimeter=0,area=0;
int a,b,c;
float s;

if(n!=3){

printf("Please enter three sides of Triangle :\n");

a=isValid();
while (a==-100){
    printf("ERROR ! Please enter a valid entry.\n");                //if input is not valid, code requests another input
    a=isValid();
}

b=isValid();
while (b==-100){
    printf("ERROR ! Please enter a valid entry.\n");
    b=isValid();
}

c=isValid();
while (c==-100){
    printf("ERROR ! Please enter a valid entry.\n");
    c=isValid();
}

printf("\n");

while (a+b<c || a+c<b || b+c<a)             //This is the general triangle rule that we need to take care of
{
    printf("Sum of any two sides of must be greater than the third side\n");
    printf("Please enter three sides of Triangle :\n");

    a=isValid();   
    while (a==-100){
    printf("ERROR ! Please enter a valid entry.\n");
    a=isValid();
    }

    b=isValid();
    while (b==-100){
    printf("ERROR ! Please enter a valid entry.\n");
    b=isValid();
    }

    c=isValid();
    while (c==-100){
    printf("ERROR ! Please enter a valid entry.\n");
    c=isValid();
    }   
}
}

switch(n){

case Perimeter:

perimeter=a+b+c;
printf("Perimeter of TRIANGLE: %.2f\n",perimeter);

break;

case Area:

s=(a+b+c)/2;

area=sqrt(s*(s-a)*(s-b)*(s-c));

printf("Area of TRIANGLE: %.2f\n",area);

break;

case Volume:

printf("ERROR ! You cannot calculate the volume of a triangle. Please try again.\n");
}
}

int calc_quadrilateral(int n){

float perimeter=0,area=0;
int a,b,c,d;
float s;

if(n!=3){

printf("Please enter four sides of quadrilateral:\n");

a=isValid();
while (a==-100){                                                        //if input is not valid, code requests another input
    printf("ERROR ! Please enter a valid entry.\n");
    a=isValid();
}

b=isValid();
while (b==-100){
    printf("ERROR ! Please enter a valid entry.\n");
    b=isValid();
}

c=isValid();
while (c==-100){
    printf("ERROR ! Please enter a valid entry.\n");
    c=isValid();
}

d=isValid();
while (d==-100){
    printf("ERROR ! Please enter a valid entry.\n");
    d=isValid();
}
}
switch(n){

case Perimeter:

perimeter=a+b+c+d;

printf("Perimeter of QUADRILATERAL: %.2f\n",perimeter);

break;

case Area:

s=(a+b+c+d)/2;

area=sqrt((s-a)*(s-b)*(s-c)*(s-d));

printf("Area of QUADRILATERAL: %.2f\n",area);

break;

case Volume:

printf("ERROR ! You cannot calculate the volume of a quadrilateral. Please try again.\n");

break;

}

}

int calc_circle(int n){

float perimeter=0,area=0,radius=0;

if(n!=3){
printf("Please enter the radius of the Circle :\n");

radius=isValid();                                                   //if input is not valid, code requests another input
while (radius==-100){
    printf("ERROR ! Please enter a valid entry.\n");
    radius=isValid();
}
}

switch(n){

case Perimeter:

perimeter=2*pi*radius;

printf("Perimeter of CIRCLE: %.2f\n",perimeter);

break;

case Area:

area=pi*radius*radius;

printf("Area of CIRCLE: %.2f\n",area);

break;

case Volume:

printf("ERROR ! You cannot calculate the volume of a circle. Please try again.\n");

}

}

int calc_pyramid(int n){

float total_area=0,base_area=0,lateral_area=0,volume=0,cevre=0;

float a,h,l;

switch(n){

case Area:

printf("Please enter the base side and slant height of a Pyramid :\n");

a=isValid();
while (a==-100){                                                            //if input is not valid, code requests another input
    printf("ERROR ! Please enter a valid entry.\n");
    a=isValid();
}

l=isValid();
while (l==-100){
    printf("ERROR ! Please enter a valid entry.\n");
    l=isValid();
}

base_area=a*a;

lateral_area=2*a*l;

total_area=base_area+lateral_area;

printf("Base surface area of a PYRAMID : %.2f\n\n",base_area);
printf("Lateral surface area of a PYRAMID : %.2f\n\n",lateral_area);
printf("Surface area of a PYRAMID : %.2f\n",total_area); 

break;

case Perimeter:

printf("Please enter the base side of a Pyramid : \n");

a=isValid();
while (a==-100){                                                                //if input is not valid, code requests another input
    printf("ERROR ! Please enter a valid entry.\n");
    a=isValid();
}

cevre=4*a;

printf("Perimeter of a PYRAMID: %.2f\n",cevre);

break;

case Volume:

printf("Please enter the base side and height of a Pyramid :\n");

a=isValid();
while (a==-100){                                                                //if input is not valid, code requests another input
    printf("ERROR ! Please enter a valid entry.\n");
    a=isValid();
}

h=isValid();
while (h==-100){
    printf("ERROR ! Please enter a valid entry.\n");
    h=isValid();
}

volume=(a*a*h)/3;

printf("Volume of a PYRAMID : %.2f\n",volume);

break;
}

}

int calc_cylinder(int n){

float height,radius;

float volume=0,base_area=0,lateral_area=0,total_area=0,perimeter=0;

if(n==1 || n==3)
{
    printf("Please enter the height and the radius of a Cylinder :\n");

    height=isValid();
    while (height==-100){                                                           //if input is not valid, code requests another input
        printf("ERROR ! Please enter a valid entry.\n");
        height=isValid();
    }

    radius=isValid();
        while (radius==-100){
        printf("ERROR ! Please enter a valid entry.\n");
        radius=isValid();
    }
}

else if (n==2)
{
    radius=isValid();
        while (radius==-100){
        printf("ERROR ! Please enter a valid entry.\n");
        radius=isValid();
    }
}

switch(n){

case Area:

base_area=pi*radius*radius;

lateral_area=2*pi*radius*height;

total_area=2*base_area+lateral_area;

printf("Base surface area of a CYLINDER : %.2f\n\n",base_area);
printf("Lateral surface area of a CYLINDER : %.2f\n\n",lateral_area);
printf("Surface area of a CYLINDER : %.2f\n",total_area);

break;

case Perimeter:

perimeter=4*pi*radius;

printf("Base surface perimeter of a CYLINDER : %.2f\n",perimeter);

break;

case Volume:

volume=pi*radius*radius*height;

printf("Volume of a CYLINDER: %.2f\n",volume);

break;

}

}

int main(){

int shape;

printf("Welcome to the geometric calculator\n\n");

calculate(select_shape,select_calc);

return 0;
}
