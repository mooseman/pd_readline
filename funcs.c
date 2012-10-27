

/*  funcs.c                                          */ 
/*  Functions to handle cursor movement for          */ 
/*  pd_readline.                                     */      
/*  This code is released to the public domain.      */ 
/*  "Share and enjoy...."  ;)                        */  
/*  See the UNLICENSE file for details.              */ 


#include <string.h>   
#include <stdio.h> 
#include <stdlib.h> 
#include "pd_readline.h"  

/* Note - make the up and down funcs return a buffer.     */ 
/* A line from the history file can be put into the       */ 
/* array member of the buffer.                            */ 
/* Also test for the top and bottom of the history file.  */     


/* Move up in history list. */ 
buf up(int i) 
{ 
  


} 


/* Move down in history list. */ 
buf down(int i) 
{ 


} 


/* Move cursor to left. */ 
buf left(buf b) 
{


} 


/* Move cursor to right. */ 
buf right(buf b) 
{ 


} 


/* Delete a char. */ 
buf delch(buf b) 
{ 


} 


/* Insert a char. */ 
buf insch(buf b) 
{ 


} 


void enter(void) 
{ 
	printf("Enter ");   		
} 	


/* Find if a number is in a given range. */ 
int range(int rstart, int rend, int i)
{
   if ( (rstart <= i) && (i <= rend) ) return 1;
   else return 0;	
	
} 	


/* Assign a type depending on the range that a  */ 
/* number is in.                                */ 
int type(int i)
{ 
   int ret; 
   
        if ( range(0, 9, i) == 1 )       ret = 1; 
   else if ( range(10, 10, i) == 1 )     ret = 2; 
   else if ( range(27, 27, i) == 1 )     ret = 3; 
   else if ( range(32, 126, i) == 1 )    ret = 4;  	   
   else if ( range(127, 127, i) == 1 )   ret = 5;
   else ret = 6;  	   
    
   return ret; 
   
}     
	

/*  Function for special key combinations  */ 
/*  (Ctrl, Alt, function keys.             */ 
void spec(void)
{ 
	
  int j = getch();  
   
       if ( ( j == 65 )	)  printf("Up ");  
  else if ( ( j == 66 )	)  printf("Down "); 
  else if ( ( j == 67 )	)  printf("Right "); 
  else if ( ( j == 68 )	)  printf("Left "); 
   		
} 	





