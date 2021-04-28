#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include"server1.h"
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
