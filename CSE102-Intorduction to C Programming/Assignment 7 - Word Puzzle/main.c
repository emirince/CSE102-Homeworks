#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int true(int row,int column,char word[],char gameArea[][15],int direction[],char wordSelected[][20]){

int aspect,i,check,control,save=-1;

for(i=0;i<7;i++){   
    if(strcmp(wordSelected[i],word)==0){    //we are checking if the word user types matches any word in the selected word array.
        save=i; 
    }   
}

if(save==-1){
    return -1;
}

else{
    aspect=direction[save];
}
    if(aspect==1){
        for(i=0;i<strlen(word);i++,row--){          //we are replacing words with x's
            if(word[i]==gameArea[row][column]){
                check++;
                gameArea[row][column]='x';
            }
            else{
                return -1;
            }
        }
    }
    else if(aspect==2){
        for(i=0;i<strlen(word);i++,row--,column++){
            if(word[i]==gameArea[row][column]){     //we are replacing words with x's
                check++;                            
                gameArea[row][column]='x';
            }
            else{
                return -1;
            }
        }
    }
    else if(aspect==3){
        for(i=0;i<strlen(word);i++,column++){
            if(word[i]==gameArea[row][column]){     //we are replacing words with x's
                check++;
                gameArea[row][column]='x';
            }
            else{
                return -1;
            }
        }        
    }
    else if(aspect==4){
        for(i=0;i<strlen(word);i++,column++,row++){
            if(word[i]==gameArea[row][column]){         //we are replacing words with x's
                check++;                        
                gameArea[row][column]='x';
            }
            else{
                return -1;
            }
        }        
    }
    else if(aspect==5){
        for(i=0;i<strlen(word);i++,row++){
            if(word[i]==gameArea[row][column]){     //we are replacing words with x's
                check++;
                gameArea[row][column]='x';
            }
            else{
                return -1;
            }
        }         
    }
    else if(aspect==6){
        for(i=0;i<strlen(word);i++,row++,column--){
            if(word[i]==gameArea[row][column]){     //we are replacing words with x's
                check++;
                gameArea[row][column]='x';
            }
            else{
                return -1;
            }
        }         
    }
    else if(aspect==7){
        for(i=0;i<strlen(word);i++,column--){
            if(word[i]==gameArea[row][column]){        //we are replacing words with x's     
                check++;
                gameArea[row][column]='x';
            }
            else{
                return -1;
            }
        }
    }
    else if(aspect==8){
        for(i=0;i<strlen(word);i++,row--,column--){
            if(word[i]==gameArea[row][column]){         //we are replacing words with x's
                check++;
                gameArea[row][column]='x';
            }
            else{
                return -1;
            }
        }
    }
if(check==strlen(word)){
    return 1;
}  
}        

int RowColumn(){      
    return rand()%15;
}

int ChoosingWord(){
    return rand()%50;
}
int way(){
    return rand()%8+1;
}

void printArea(char gameArea[][15],char wordSelected[][20],int position_row,int position_column){

int i,j;

for(i=0;i<15;i++){
    for(j=0;j<15;j++){   
        if(gameArea[i][j]!=' '){        //we put the words to the game area
            printf("%c ",gameArea[i][j]);
        }
        else{
            if(gameArea[i][j]==' '){
                int letter=rand()%26+97;      //we put random letters to rest of the game area
                gameArea[i][j]=letter;
                printf("%c ",gameArea[i][j]);
            }
        }
    }
    printf("\n");
}
}

int isFree(char wordSelected[][20],char gameArea[][15],int a,int b,int dice,int index){

int i=0,check=0;

    if(dice==1){  
        for(i=0;i<strlen(wordSelected[index]);i++,a--){
            if(gameArea[a][b]==' '){        //we check the map if its avaliable or not to put the words
                check++;
            }
        }
    }
    else if(dice==2){   
        for(i=0;i<strlen(wordSelected[index]);i++,a--,b++){
            if(gameArea[a][b]==' '){            //we check the map if its avaliable or not to put the words
                check++;
            }
        }
    }   
    else if(dice==3){   
        for(i=0;i<strlen(wordSelected[index]);i++,b++){
            if(gameArea[a][b]==' '){            //we check the map if its avaliable or not to put the words
                check++;
            }
        }    
    }
    else if(dice==4){
        for(i=0;i<strlen(wordSelected[index]);i++,a++,b++){
            if(gameArea[a][b]==' '){            //we check the map if its avaliable or not to put the words
                check++;
            }
        } 
    }
    else if(dice==5){   
        for(i=0;i<strlen(wordSelected[index]);i++,a++){
            if(gameArea[a][b]==' '){            //we check the map if its avaliable or not to put the words
                check++;
            }
        } 
    }
    else if(dice==6){   
        for(i=0;i<strlen(wordSelected[index]);i++,a++,b--){
            if(gameArea[a][b]==' '){            //we check the map if its avaliable or not to put the words
                check++;
            }
        }        
    }  
    else if(dice==7){
        for(i=0;i<strlen(wordSelected[index]);i++,b--){
            if(gameArea[a][b]==' '){            //we check the map if its avaliable or not to put the words
                check++;
            }
        }
    }
    else if(dice==8){
        for(i=0;i<strlen(wordSelected[index]);i++,a--,b--){
            if(gameArea[a][b]==' '){            //we check the map if its avaliable or not to put the words
                check++;
            }
        }
    }
    if(check==strlen(wordSelected[index])){     //we return some values depends on every letter's situation
        return 1;
    }
    else{
        return -1;
    }
}

int main(){
srand(time(NULL));

char wordBank[50][20],wordSelected[7][20],gameArea[15][15];
int direction[7],i,j;

for(i=0;i<15;i++){
    for(j=0;j<15;j++){
        gameArea[i][j]=' ';
    }
}

FILE *txt;
txt=fopen("wordlist.txt","r+");

for (i=0;i<50;i++){
    fscanf (txt, "%s", wordBank[i]);
}

fclose(txt);

int selection[7],a,checkSame;

do{
checkSame=0;

for(i=0;i<7;i++){
    selection[i]=rand()%50;
}
                                        //With this do-while block, we eliminate the same word problem that rand funtion makes.
for(i=0;i<7;i++){
    for(j=i+1;j<7;j++){
        if(selection[i]==selection[j]){
            checkSame++;
        }
    }
}
}while(checkSame!=0);

for(i=0;i<7;i++){   
    a=selection[i];         //we copy the words from wordlist.txt to wordSelected array
    strcpy(wordSelected[i],wordBank[a]); 
}

int dice=0,position_row,position_column,check,rowCheck,columnCheck;

for(i=0;i<7;i++){
    dice=way();
    direction[i]=dice;
    
    if(dice==1){
        do{
            position_row=RowColumn(); 
            position_column=RowColumn();        //we are checking if the word fits in the game area properly
            check=isFree(wordSelected,gameArea,position_row,position_column,dice,i);
            rowCheck=position_row+1-strlen(wordSelected[i]);
        }while((rowCheck<0) || check==-1);

        printf("Word %d: %s ",i+1,wordSelected[i]);
        printf("Coordinates: %d %d\n",position_row,position_column); 

        for(a=0;a<strlen(wordSelected[i]);a++,position_row--){  //if word requires all conditions, we put it in the game area.
            gameArea[position_row][position_column]=wordSelected[i][a];
        }  
    }
    else if(dice==2){
        do{
            position_row=RowColumn();       //we are checking if the word fits in the game area properly
            position_column=RowColumn();
            check=isFree(wordSelected,gameArea,position_row,position_column,dice,i);
            rowCheck=position_row+1-strlen(wordSelected[i]);
            columnCheck=position_column-1+strlen(wordSelected[i]);
        }while((rowCheck<0) || (columnCheck>14) || check==-1);        

        printf("Word %d: %s ",i+1,wordSelected[i]);
        printf("Coordinates: %d %d\n",position_row,position_column);

        for(a=0;a<strlen(wordSelected[i]);a++){     //if word requires all conditions, we put it in the game area.
            gameArea[position_row][position_column]=wordSelected[i][a];
            position_row--;
            position_column++;
        } 
    }
    else if(dice==3){
        do{                                    //we are checking if the word fits in the game area properly                 
            position_row=RowColumn();
            position_column=RowColumn();
            check=isFree(wordSelected,gameArea,position_row,position_column,dice,i);
            columnCheck=position_column-1+strlen(wordSelected[i]);
        }while((columnCheck>14) || check==-1);        

        printf("Word %d: %s ",i+1,wordSelected[i]);
        printf("Coordinates: %d %d\n",position_row,position_column);

        for(a=0;a<strlen(wordSelected[i]);a++){         //if word requires all conditions, we put it in the game area.
            gameArea[position_row][position_column]=wordSelected[i][a];
            position_column++;
        }
    }
    else if(dice==4){
        do{                                     //we are checking if the word fits in the game area properly            
            position_row=RowColumn();
            position_column=RowColumn();
            check=isFree(wordSelected,gameArea,position_row,position_column,dice,i);
            rowCheck=position_row-1+strlen(wordSelected[i]);
            columnCheck=position_column-1+strlen(wordSelected[i]);
        }while((rowCheck>14) || (columnCheck>14) || check==-1);        
        
        printf("Word %d: %s ",i+1,wordSelected[i]);
        printf("Coordinates: %d %d\n",position_row,position_column);

        for(a=0;a<strlen(wordSelected[i]);a++){         //if word requires all conditions, we put it in the game area.
            gameArea[position_row][position_column]=wordSelected[i][a];
            position_column++;
            position_row++;
        }
    }
    else if(dice==5){
        do{                                 //we are checking if the word fits in the game area properly
            position_row=RowColumn();
            position_column=RowColumn();
            check=isFree(wordSelected,gameArea,position_row,position_column,dice,i);
            rowCheck=position_row-1+strlen(wordSelected[i]);
        }while((rowCheck>14) || check==-1);        

        printf("Word %d: %s ",i+1,wordSelected[i]);
        printf("Coordinates: %d %d\n",position_row,position_column);

        for(a=0;a<strlen(wordSelected[i]);a++){         //if word requires all conditions, we put it in the game area.
            gameArea[position_row][position_column]=wordSelected[i][a];
            position_row++;
        }  
    }
    else if(dice==6){   
        do{                             //we are checking if the word fits in the game area properly
            position_row=RowColumn();
            position_column=RowColumn();
            check=isFree(wordSelected,gameArea,position_row,position_column,dice,i);
            rowCheck=position_row-1+strlen(wordSelected[i]);
            columnCheck=position_column+1-strlen(wordSelected[i]);
        }while((rowCheck>14) || (columnCheck<0) || check==-1);        
        
        printf("Word %d: %s ",i+1,wordSelected[i]); 
        printf("Coordinates: %d %d\n",position_row,position_column);

        for(a=0;a<strlen(wordSelected[i]);a++){         //if word requires all conditions, we put it in the game area.
            gameArea[position_row][position_column]=wordSelected[i][a];
            position_row++;
            position_column--;
        } 
    }
    else if(dice==7){
        do{                             //we are checking if the word fits in the game area properly
            position_row=RowColumn();
            position_column=RowColumn();
            check=isFree(wordSelected,gameArea,position_row,position_column,dice,i);
            columnCheck=position_column+1-strlen(wordSelected[i]);
        }while((columnCheck<0) || check==-1);        
        
        printf("Word %d: %s ",i+1,wordSelected[i]);
        printf("Coordinates: %d %d\n",position_row,position_column);

        for(a=0;a<strlen(wordSelected[i]);a++){     //if word requires all conditions, we put it in the game area.
            gameArea[position_row][position_column]=wordSelected[i][a];
            position_column--;
        }
    }
    else if(dice==8){
        do{                             //we are checking if the word fits in the game area properly
            position_row=RowColumn(); 
            position_column=RowColumn();
            check=isFree(wordSelected,gameArea,position_row,position_column,dice,i);
            rowCheck=position_row+1-strlen(wordSelected[i]);
            columnCheck=position_column+1-strlen(wordSelected[i]);
        }while((rowCheck<0) || (columnCheck<0) || check==-1);        

        printf("Word %d: %s ",i+1,wordSelected[i]);
        printf("Coordinates: %d %d\n",position_row,position_column);

        for(a=0;a<strlen(wordSelected[i]);a++){         //if word requires all conditions, we put it in the game area.
            gameArea[position_row][position_column]=wordSelected[i][a];
            position_column--;
            position_row--;
        }
    }
}
printf("\n");
printArea(gameArea,wordSelected,position_row,position_column);

int points=0,fails=0,row,column,valid,wrong=3;
char row_value[3],column_value[3],word[20];

do{
    printf("Enter the coordinates and word: \n");    
    for(i=0;i<3;i++){
        if(i==0){
            scanf("%s",row_value);
            if(row_value[0]==':' && row_value[1]=='q'){     //we end the game if user inputs ':q'
                printf("Game Ended. Your total points: %d\n",points);
                return 0;
            }
            else{   
                row=atoi(row_value);        //if not, we turn the string value to int value.
            }
        }
        else if(i==1){
            scanf("%s",column_value);
            if(column_value[0]==':' && column_value[1]=='q'){     
                printf("Game Ended. Your total points: %d\n",points);
                return 0;
            }
            else{
                column=atoi(column_value);       
            }
        }   
        else if(i==2){
            scanf("%s",word);
            if(word[0]==':' && word[1]=='q'){
                printf("Game Ended. Your total points: %d\n",points);
                return 0;
            }
        }
    }
    valid=true(row,column,word,gameArea,direction,wordSelected);

    if(valid==-1){   
        wrong--;
        fails++;
        if(wrong!=0)
        printf("Wrong choice! You have only %d lefts\n",wrong);
    }
    else{
        points=points+2;
        printf("Founded! You got 2 points. Your total points: %d\n",points);
    }

printArea(gameArea,wordSelected,position_row,position_column);
}while(points!=14 &&  fails!=3);

if(points==14)
printf("You won the game! Your total points: %d\n",points);
else

printf("You lost the game! Your total points: %d\n",points);
return 0;
}