#include<stdio.h>
#include<stdlib.h>
//FUNCTION TO READ FROM FILE
int read_file(char a[],int from_top,int from_bottom)
{   
    //INITIALLIZATION
    int j;
    int i;
    int n;
    char chr;
    int count;
    char buff[1000];
 
    //OPENING FILES
    FILE *fp;
    fp=fopen(a,"r");
    
    
    if(fp==NULL)
    {
        printf("   ***ERROR IN OPENING FILE***\n   ***FILE DOES NOT EXIST***\n");
	exit(0);
	
    }
    else
    {  
	//COUNTING THE NUMBER OF LINES IN THE FILE 
        chr=getc(fp);
        while(chr!=EOF)
        {
             if(chr=='\n')
             {
	        count++;
             }
	     chr=getc(fp);
        }
        printf("There are %d lines\n\n",count);
        fseek(fp, 0, SEEK_SET);

	//PRINTING THE TOP "N" LINES
	printf("   ***From the top***\n\n");
	for(j=1;j<=from_top;j++)
	{   
            if(fgets(buff,1000,fp)!=NULL)
	         puts(buff);     
	    
        }
	
	fseek(fp, 0, SEEK_SET);

	//PRINTING THE BOTTOM "N" LINES
	printf("   ***From the bottom***\n\n");
	i=0;
	while(fgets(buff,1000,fp)!=NULL)
	{
		i++;
		if(i>count-from_bottom && i<=count)
			puts(buff);
	}
        
    }
    
    fclose(fp);
    return 0;    
  
}



//MAIN FUNCTION
int main(int argc,char **argv)
{

    //INITIALIZATION
    int tflag;
    int bflag;
    int fflag;
    int index;
    int c;
    int b;
    int t;
    int qflag=0;
    int i=1;
    opterr=0;



    //PARSING THE USERS INPUT
    while((c=getopt(argc,argv,"qt:b:"))!=-1)
    {   
        switch(c)
        {
            case 'b':
            b=atoi(optarg);
            printf("Number of lines from BOTTOM of the file:%s\n",optarg);
            bflag = 1;
            printf ("bflag = %d\n\n",bflag);
            break;
            
            case 't':
            t=atoi(optarg);
            printf("Number of lines from TOP of the file:%s\n",optarg);
            tflag=1;
            printf("tflag = %d\n\n",tflag);
            break;
            
            case 'q':
            qflag=1;
	    printf("qflag = %d\n",qflag);
	    printf("***PRINTING WITHOUT FILE HEADERS***\n\n");
            break;
            
            case '?':
            printf("unknown option: %c\n\n", optopt);
            break;
            
            default:
            abort();
        }
        
    }
    


    //CHECKING FOR -q COONDITIONS FOR OUTPUT
    printf("   **************************************************\n\n");
    if(qflag==1){	
	for(index=optind;index<argc;index++)
	    read_file(argv[index],t,b);
    }
    else if(qflag==0){    
        for(index = optind; index<argc; index++)
        {          
	    printf("FILE NUMBER %d %s\n\n",i,argv[index]);
            read_file(argv[index],t,b);
	    printf("   **************************************************\n\n");
            i++;
	}
    }
    else{;}
    
    return 0;
    
}
