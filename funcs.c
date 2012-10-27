

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



/*  Function for special key combinations  */ 
/*  (Ctrl, Alt, function keys.             */ 
int spec(int i)
{ 
	
	

} 	





