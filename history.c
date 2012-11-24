

/*  history.c                                          */ 
/*  Command history.                                   */ 
/*  This code is released to the public domain.        */ 
/*  "Share and enjoy...."  ;)                          */  
/*  See the UNLICENSE file for details.                */ 

#include <string.h>   
#include <stdio.h> 
#include <stdlib.h> 
#include <malloc.h>
#include "pd_readline.h"  


/*  Helper function, to let us see if a file */ 
/*  exists in the current directory.  */ 
int fexists(char *fname)
{  
   FILE *fptr;  
   fptr = fopen(fname, "r") ;     
   if ( !fptr )  return -1 ;  /* File does not exist in dir. */ 		 
   fclose(fptr);  
   return 0;    /* File DOES exist in dir.  */   
} 


/* Helper function to chop newlines off the lines read in. */ 
/* Without this being done, an extra newline is inserted */ 
/* (which is usually not what is wanted). */ 
char *chop(char *s)
{
  s[strcspn(s,"\n")] = '\0'; 
  return s; 
}



/* Read the file into the array of strings.   */ 
hist readhistory(char *fname) 
{ 
	
   /*  Create a history buffer.  */ 
   hist h; 	
	
   int retval = fexists(fname); 
        
   int i; 
   if (retval == 0) { 
	  /* File exists, so open it. */  
	  /* We open it in read-write mode so we can */ 
	  /* append new commands to it. */ 
	  FILE *fptr;  
	  fptr = fopen(fname, "rw"); 
	 	
      char line[80] ; 
	 		 	  	   
	  for(i=0; i<20; i++)  
	  { 
		fgets(line, 80, fptr);    		 
		chop(line) ;  
		
		/* TO DO: fix the "too few arguments" bug here.... */  
		memcpy(&h.array[i], line, 80) ;   
		puts(h.array[i]); 
	  }
	  
   }  /* retval == 0  */   	   
	
	else puts("Error! File does not exist. \n");  
		
	/*  Set the curindex to 19.  */	    
	    h.curindex = 19; 	   
            	
	return h;
	
} 	

                                           

 



