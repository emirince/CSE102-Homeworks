#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMap();
int dice();
int startGame();
void red();
void blue();
void yellow();
void green();
void reset();

int main(){

int player;

srand(time(NULL));

char track[15][30];
int i,j;

for (i=0;i<15;i++)
{
    for (j=0;j<30;j++)
    {   
        track[i][j]=' ';       
    }
}
for (i=0;i<15;i++)              //assigning the biggest track boundaries
{
    for (j=0;j<30;j++)
    {   
        track[0][j]='.';
        track[14][j]='.';
        track[i][0]=':';
        track[i][29]=':';
    }
}   
for (i=2;i<13;i++)          
{   
    for (j=2;j<28;j++)
    {       
        track[2][j]='.';            //assigning the middle track boundaries
        track[12][j]='.';   
        track[i][2]=':';
        track[i][27]=':';
    }
}    
for (i=4;i<11;i++)
{                                    //assigning the smallest track boundaries
    for (j=4;j<26;j++)
    {       
        track[4][j]='.';
        track[10][j]='.';   
        track[i][4]=':';
        track[i][25]=':';
    }
}  

track[1][14]='X';
track[7][28]='X';
track[13][14]='X';           //Assigning the penalty points to the track
track[3][10]='X';
track[3][18]='X';
track[5][26]='X';
track[10][26]='X';
track[11][10]='X';
track[11][18]='X';
track[2][1]='-';
track[4][3]='-';
track[1][1]=49;                //Assingning players to the track             
track[3][3]=50;

printMap(track);
printf("\n\n");
player=startGame();

int a=1,b=1,c=3,d=3,x,y,temp,check1_total=0,check2_total=0;

if(player==1){          //Checking which player stars first. In this condition player 1 stars.
do{
    temp=0;
    track[a][b]=' ';             //Deleting the previous location from the track

    blue();
    printf("PLAYER 1... press ENTER to dice");
    while(getchar() != '\n');
    x=dice();
    printf("DICE: %d\n",x);
    reset();
 
    if(check1_total==0){        
        if(b+x>=28){        //Checking if the players takes turn or not
            temp=28-b;
            b=b+temp;
            x=x-temp;
            a=a+x;
            track[a][b]=49;
            check1_total++;
            }
        else{
            b=b+x;
            if(a==1 && b==14){
                blue(); printf("Penalty for player ...1\n"); reset();     //Giving penalty to player
                a=1,b=12;
                track[a][b]=49;   
            }    
            else{
                track[a][b]=49;
            }
        }          
    }

    else if(check1_total==1){
        if(a+x>=13){        //Checking if the players takes turn or not
            temp=13-a;
            a=a+temp;
            x=x-temp;
            b=b-x;
            track[a][b]=49;
            check1_total++;
        }
        else{
        a=a+x;
            if(a==7 && b==28){              //Giving penalty to player
                blue(); printf("Penalty for player 1...\n"); reset();
                a=5,b=28;
                track[a][b]=49;   
            }    
            else{
                track[a][b]=49;
            }
        }  
    }
    else if(check1_total==2){
        if(b-x<=1){         //Checking if the players takes turn or not
            temp=b-1;
            b=b-temp;
            x=x-temp;
            a=a-x;
            track[a][b]=49;
            check1_total++;
        }
        else{
            b=b-x;
            if(a==13 && b==14){
                blue(); printf("Penalty for player 1...\n"); reset();        //Giving penalty to player
                a=13,b=16;
                track[a][b]=49;   
            }    
            else{
                track[a][b]=49;
            }
        }   
    }
    else if(check1_total==3){
        if(a-x<=1){         //Checking if the players takes turn or not
            temp=a-1;
            a=a-temp;
            x=x-temp;
            b=b+x;
            check1_total++;                
            track[a][b]=49;
            break;
        }
        else{
            a=a-x;
            if(a==2 && b==1){
                check1_total++;
                track[a][b]=49;             //checking if the player is on the finish line or not
                break;
            }
            else{
                track[a][b]=49;
            }  
        }         
    }
    
    track[c][d]=' ';     //Deleting the previous location from the track
    yellow();
    printf("PLAYER 2... press ENTER to dice");
    while(getchar() != '\n');
    y=dice();
    printf("DICE: %d\n",y);    
    reset();

    if(check2_total==0){
        if(d+y>=26){        //Checking if the players takes turn or not
            temp=26-d;
            d=d+temp;
            y=y-temp;
            c=c+y;
            if(c==5 && d==26){                         //Giving penalty to player
                yellow(); printf("Penalty for player 2...\n"); reset();
                c=3,d=26;
                track[c][d]=50;
                check2_total++;
            }
            else{   
            track[c][d]=50;
            check2_total++;
            }
        }
        else{
            d=d+y;
            if(c==3 && d==10){
                yellow(); printf("Penalty for player 2...\n"); reset();   //Giving penalty to player               
                c=3,d=8;
                track[c][d]=50;   
            }
            else if(c==3 && d==18){
                yellow(); printf("Penalty for player 2...\n"); reset();   //Giving penalty to player
                c=3,d=16;
                track[c][d]=50;   
            }
            
            else{
                track[c][d]=50;
            }
        }    
    }    

    else if(check2_total==1){
        if(c+y>=11){
            temp=11-c;          //Checking if the players takes turn or not
            c=c+temp;
            y=y-temp;
            d=d-y;
            track[c][d]=50;
            check2_total++;
        }
        
        else{
            c=c+y;
            if(c==5 && d==26){
                yellow(); printf("Penalty for player 2...\n"); reset();   //Giving penalty to player               
                c=3,d=26;
                track[c][d]=50;   
            }

            else if(c==10 && d==26){                            //Giving penalty to player
                yellow(); printf("Penalty for player 2...\n"); reset();
                c=8,d=26;
                track[c][d]=50;   
            } 

            else{
                track[c][d]=50;
            }
        }    
    }
    else if(check2_total==2){
        if(d-y<=3){         //Checking if the players takes turn or not
            temp=d-3;
            d=d-temp;
            y=y-temp;
            c=c-y;
            track[c][d]=50;
            check2_total++;
        }
        else{
            d=d-y;
            if(c==11 && d==10){
                yellow(); printf("Penalty for player 2...\n"); reset();            //Giving penalty to player               
                c=11,d=12; 
                track[c][d]=50;   
            }
            else if(c==11 && d==18){   //Giving penalty to player
                yellow(); printf("Penalty for player 2...\n"); reset();
                c=11,d=20;
                track[c][d]=50;   
            } 
            else{
                track[c][d]=50;
            }
        }    
    }    
    else if(check2_total==3){
        if(c-y<=3){         //Checking if the players takes turn or not
            temp=c-3;
            c=c-temp;
            y=y-temp;
            d=d+y;
            check2_total++;                
            track[c][d]=50;
            break;
        }
        else{
            c=c-y;
            track[c][d]=50;
            if(c==4 && d==3){           //checking if the player is on the finish line or not
                check2_total++;
                track[c][d]=50;
                break;
            }
            else{
                track[c][d]=50;
            }
        }  
    }  
    printMap(track);        
    }while((check1_total!=4) &&  (check2_total!=4));
}

else if(player==2){              //Checking which player stars first. In this condition player 2 stars.
a=1,b=1,c=3,d=3;
do{
    temp=0;
    
    track[c][d]=' ';
    yellow();
    printf("PLAYER 2... press ENTER to dice");
    while(getchar() != '\n');
    y=dice();
    printf("DICE: %d\n",y);    
    reset();
    if(check2_total==0){        //Checking if the players takes turn or not
        if(d+y>=26){
            temp=26-d;
            d=d+temp;
            y=y-temp;
            c=c+y;
            if(c==5 && d==26){                         //Giving penalty to player
                yellow(); printf("Penalty for player 2...\n"); reset();
                c=3,d=26;
                track[c][d]=50;
                check2_total++;
            }
            else{   
            track[c][d]=50;
            check2_total++;
            }
        }
        else{
            d=d+y;
            if(c==3 && d==10){
                yellow(); printf("Penalty for player 2...\n"); reset();   //Giving penalty to player
                c=3,d=8;
                track[c][d]=50;   
            }
            else if(c==3 && d==18){
                yellow(); printf("Penalty for player 2...\n"); reset(); //Giving penalty to player
                c=3,d=16;
                track[c][d]=50;   
            } 

            else{
                track[c][d]=50;
            }
        }    
    }    

    else if(check2_total==1){
        if(c+y>=11){
            temp=11-c;          //Checking if the players takes turn or not
            c=c+temp;
            y=y-temp;
            d=d-y;
            track[c][d]=50;
            check2_total++;
        }
        else{
            c=c+y;
            if(c==5 && d==26){
                yellow(); printf("Penalty for player 2...\n"); reset();     //Giving penalty to player
                c=3,d=26;
                track[c][d]=50;   
            }
            else if(c==10 && d==26){
                yellow(); printf("Penalty for player 2...\n"); reset();  //Giving penalty to player    
                
                c=8,d=26;           
                track[c][d]=50;   
            } 
            else{
                track[c][d]=50;
            }
        }    
    }
    else if(check2_total==2){
        if(d-y<=3){
            temp=d-3;           //Checking if the players takes turn or not
            d=d-temp;
            y=y-temp;
            c=c-y;
            track[c][d]=50;
            check2_total++;
        }
        else{
            d=d-y;
            if(c==11 && d==10){
                yellow(); printf("Penalty for player 2...\n"); reset();  //Giving penalty to player
                c=11,d=12;
                track[c][d]=50;   
            }
            else if(c==11 && d==18){
                yellow(); printf("Penalty for player 2...\n"); reset();  //Giving penalty to player
                c=11,d=20;
                track[c][d]=50;   
            } 
            else{
                track[c][d]=50;
            }
        }    
    }    
    else if(check2_total==3){
        if(c-y<=3){         //Checking if the players takes turn or not
            temp=c-3;
            c=c-temp;           
            y=y-temp;
            d=d+y;
            check2_total++;                
            track[c][d]=50;
            break;
        }
        else{
            c=c-y;
            track[c][d]=50;
            if(c==4 && d==3){
                check2_total++;
                track[c][d]=50;             //checking if the player is on the finish line or not
                break;
            }

            else{
                track[c][d]=50;
               
            }
        }  
    }
    track[a][b]=' ';
    blue();
    printf("PLAYER 1... press ENTER to dice");
    while(getchar() != '\n');
    x=dice();
    printf("DICE: %d\n",x);
    reset();

    if(check1_total==0){
        if(b+x>=28){            //Checking if the players takes turn or not
            temp=28-b;
            b=b+temp;
            x=x-temp;
            a=a+x;
            track[a][b]=49;
            check1_total++;
            } 
        else{
            b=b+x;
            if(a==1 && b==14){
                blue(); printf("Penalty for player 1...\n"); reset();         //Giving penalty to player
                a=1,b=12;
                track[a][b]=49;   
            }    
            else{
                track[a][b]=49;
            }
        }          
    }
    else if(check1_total==1){
        if(a+x>=13){                //Checking if the players takes turn or not
            temp=13-a;
            a=a+temp;
            x=x-temp;
            b=b-x;
            track[a][b]=49;
            check1_total++;
        }
        
        else{
            a=a+x;
            if(a==7 && b==28){
                blue(); printf("Penalty for player 1...\n"); reset();  //Giving penalty to player
               
                a=5,b=28;
                track[a][b]=49;   
            }    
            else{
                track[a][b]=49;
            }
        }  
    }
    else if(check1_total==2){
        if(b-x<=1){                         //Checking if the players takes turn or not
            temp=b-1;
            b=b-temp;
            x=x-temp;
            a=a-x;
            track[a][b]=49;
            check1_total++;
        }
        else{
            b=b-x;
            if(a==13 && b==14){
                blue(); printf("Penalty for player 1...\n"); reset();  //Giving penalty to player   
                a=13,b=16;
                track[a][b]=49;   
            }    
            else{
                track[a][b]=49;
            }
        }   
    }

    else if(check1_total==3){
        if(a-x<=1){                 //Checking if the players takes turn or not
            temp=a-1;
            a=a-temp;
            x=x-temp;
            b=b+x;
            check1_total++;                
            track[a][b]=49;
            break;
        }
        
        else{
            a=a-x;
            if(a==2 && b==1){
                check1_total++;         //checking if the player is on the finish line or not
                track[a][b]=49;
                break;
            }
            else{
                track[a][b]=49;
            }  
        }         
    }
    printMap(track);        
    }while((check1_total!=4) &&  (check2_total!=4));   
}
    if(check1_total==4){
    blue(); printf("\n\n\n *** PLAYER 1 WON THE GAME ***\n"); reset();
    }
    else if(check2_total==4){
    yellow(); printf("\n\n\n *** PLAYER 2 WON THE GAME ***\n"); reset();
    }
    printMap(track);
}

void printMap(char track[][30]){

int i,j;

for (i=0;i<15;i++)
{
    for (j=0;j<30;j++)
    {   
        
        if(track[i][j]=='X'){
            red(); printf("%c",track[i][j]); reset(); //We are coloring the "Penalty Points" with red.
        }
        else if(track[i][j]==49){
            blue(); printf("%c",track[i][j]); reset(); //We are coloring the "Player 1" with blue.
        }
        else if(track[i][j]==50){
            yellow(); printf("%c",track[i][j]); reset();    //We are coloring the "Player 2" with yellow.
        }
        else if(track[i][j]=='-'){
            green(); printf("%c",track[i][j]); reset(); //We are coloring the "Finish Line" with green.
        }
        else{
            printf("%c",track[i][j]);       //If the character that we print is not any above of them, then we print it white.
        }
    }
    printf("\n");
}
}    

int dice(){
int n;
n= (rand() % 6) + 1;  
return n;
}

int startGame(){
int x,y;
printf("To start the game, players should dice and decide who is going to start...\n");

blue();
printf("PLAYER 1... press ENTER to dice");
while( getchar() != '\n' );
x=dice();
printf("DICE: %d\n",x);
reset();

yellow();
printf("PLAYER 2... press ENTER to dice");
while( getchar() != '\n' );
y=dice();
printf("DICE: %d\n",y);
reset();

while(x==y){                                                //We roll the dice if two players's dice values are same.
    printf("Same dice value... Please try again.\n");

    blue();
    printf("PLAYER 1... press ENTER to dice");
    while( getchar() != '\n' );
    x=dice();
    printf("DICE: %d\n",x);
    reset();
    
    yellow();
    printf("PLAYER 2... press ENTER to dice");
    while( getchar() != '\n' );
    y=dice();
    printf("DICE: %d\n",y);
    reset();
}

if(x>y){
    printf("\n *** PLAYER 1 will start the game... ***\n");    //We are comparing the dice values of two players to decide who starts first
    return 1;
}
else if(y>x){
    printf("\n *** PLAYER 2 will start the game... ***\n");
    return 2;
}
}

void red (){
    printf("\033[1;31m");
}
void blue(){
    printf("\033[0;36m");
}
void yellow(){
    printf("\033[1;33m");
}
void green(){
    printf("\033[0;32m");
}
void reset (){
    printf("\033[0m");
}