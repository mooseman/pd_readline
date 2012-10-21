

/*  history.c                                          */ 
/*  Command history.                                   */ 
/*  This code is released to the public domain.        */ 
/*  "Share and enjoy...."  ;)                          */  
/*  See the UNLICENSE file for details.                */ 



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


/* An array to store the command-history file in. */ 
/* Only 20 lines are read. */ 
char hist[20][80];  



/* Read the file into the array of strings.  */ 
void readhistory(char *fname) 
{ 
   int retval = fexists(fname); 
        
   int i; 
   if (retval == 0) { 
	  /* File exists, so open it. */  
	  /* We open it in read-write mode so we can */ 
	  /* append new commands to it. */ 
	  FILE *fptr;  
	  fptr = fopen(fname, "rw"); 
	 	  	   
	  for(i=0; i<20; i++)  
	  {  
		chop(fgets(hist[i], 80, fptr) );  
	  }
	  
   }  /* retval == 0  */   	   
	
	else puts("Error! File does not exist. \n");  
	
} 	




