  #include<stdio.h>

    void yellow(){
    printf("\033[1;33m");
    }

    void reset(){
    printf("\033[0m");              //By this functions, we make text different colours.
    }

    void red(){
    printf("\033[1;31m");
    }

    int main(){

    int x,y,a,b,c,operation;

    do{

    printf("Select a operation\n");
    printf("1 -> Enter the coefficients.\n");
    printf("2 -> Draw the graph.\n");                           //By this menu, we pick the operation that we want.
    printf("3 -> Print the graph in to a .txt file.\n");
    printf("4 -> Exit\n\n");

    printf("Choice: ");
    scanf("%d",&operation);

    switch(operation){

    case 1:

    printf("a: ");
    scanf("%d",&a);

    printf("b: ");                      //In this part, we choose coefficient of the parabola
    scanf("%d",&b);

    printf("c: ");
    scanf("%d",&c);

    FILE *txt;
    txt=fopen("Coefficients.txt","w");
    fprintf(txt,"%d\n",a);                  // In this part, we print the coefficients to the file
    fprintf(txt,"%d\n",b);
    fprintf(txt,"%d",c);
    fclose(txt);

    break;

    FILE *dosya;

    case 2:

    dosya=fopen("Coefficients.txt","r");
    fscanf(dosya,"%d",&a);                  // In this part, we scan the coefficients from the coefficients.txt file
    fscanf(dosya,"%d",&b);
    fscanf(dosya,"%d",&c);
    fclose(dosya);

    printf("\nCoefficients has been read from the coefficient.txt file.\n");

    printf("Printing the graph of x=%d(y*y) + %d*y + %d\n",a,b,c);

    for(y=16;y>=-15;y--)
    {

           for(x=-50;x<=50;x++)                 //In this part, we print the graph by the coefficients that we get from the file.
           {


               if(x==-50 && y==0)
               printf("<");

               if(x==50 && y==0)
               printf(">");

               if(y==0 && x!=0 && x!=-50 && x!=50)
               printf("-");

               if(y!=0 && x==0 && y!=16)
               printf("|");

	       if(x==0 && y==16)
	       printf("^");

	       red();
	       if(x%10==0 && y==-1)
	       printf("\b\b\b%d",x);

		if(y==15 && x==-1)
		printf("\b\b15");

		if(y==10 && x==-1)
		printf("\b\b10");

		if(y==5 && x==-1)
		printf("\b5");

		if(y==-5 && x==-1)
		printf("\b\b-5");

		if(y==-10 && x==-1)
		printf("\b\b\b-10");

		if(y==-15 && x==-1)
		printf("\b\b\b-15");

		reset();

		yellow();

               if(x==a*y*y+b*y+c)
               printf("#");
	       reset();

               if(x!=0 && y!=0)
               printf(" ");

           }

           printf("\n");
    }

    break;

    FILE *file;

    case 3:

    file=fopen("Coefficients.txt","r");
    fscanf(file,"%d",&a);
    fscanf(file,"%d",&b);                           // In this part, we scan the coefficients from the coefficients.txt file
    fscanf(file,"%d",&c);
    fclose(file);

    printf("\nCoefficients has been read from the coefficient.txt file.\n");

    FILE *graph;
    graph=fopen("graph.txt","w");

    int x,y;

    for(y=16;y>=-15;y--)
    	{
                                                //In this part, we print the graph to the graph.txt.
           for(x=-50;x<=50;x++)
           {


               if(x==-50 && y==0)
               fprintf(graph,"<");

               if(x==50 && y==0)
               fprintf(graph,">");

               if(y==0 && x!=0 && x!=-50 && x!=50)
               fprintf(graph,"-");

               if(y!=0 && x==0 && y!=16)
               fprintf(graph,"|");

	       if(x==0 && y==16)
	       fprintf(graph,"^");

               if(x==a*y*y+b*y+c)
               fprintf(graph,"#");

               if(x!=0 && y!=0)
               fprintf(graph," ");


           }

           fprintf(graph,"\n");
    }

    fclose(graph);

    printf("The graph of x=%d(y*y) + %d*y + %d has been written to graph.txt file.\n\n",a,b,c);

    break;

    case 4:

    break;

    }

}while(operation!=4);

     return 0;

}

