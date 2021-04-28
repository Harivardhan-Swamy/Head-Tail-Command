
#include<stdio.h>
#include"server1.h"
#include <string.h>
#include <stdlib.h>
#include<unistd.h>
int read_file(char a[],int from_top,int from_bottom)
{   
    //INITIALLIZATION
    int j;
    int i;
    int n;
    char chr;
    int count;
    char buff[BUFFER_SIZE];
    FILE *fptr;
 
    //OPENING FILES
    fptr=fopen(a,"r");
    
    
    if(fptr==NULL)
    {
        printf("   ***ERROR IN OPENING FILE***\n   ***FILE DOES NOT EXIST***\n");
	goto ENDING;
	
    }
    else
    {  
	//COUNTING THE NUMBER OF LINES IN THE FILE 
        chr=getc(fptr);
        while(chr!=EOF)
        {
             if(chr=='\n')
             {
	        count++;
             }
	     chr=getc(fptr);
        }
        printf("There are %d lines\n\n",count);
        fseek(fptr, 0, SEEK_SET);

	//PRINTING THE TOP "N" LINES
	printf("   ***From the top***\n\n");
	for(j=1;j<=from_top;j++)
	{   
            if(fgets(buff,BUFFER_SIZE,fptr)!=NULL)
	         puts(buff);     
	    
        }
	
	fseek(fptr, 0, SEEK_SET);

	//PRINTING THE BOTTOM "N" LINES
	printf("   ***From the bottom***\n\n");
	i=0;
	while(fgets(buff,BUFFER_SIZE,fptr)!=NULL)
	{
		i++;
		if(i>count-from_bottom && i<=count)
			puts(buff);
	}
        
    }
    
    fclose(fptr);
    ENDING:printf("\n");
    return 0;    
  
}
