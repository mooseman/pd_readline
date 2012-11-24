

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

/*  Error function.  */ 
void error(void)
{ 
   printf("Error \n"); 	
} 	



/*  Display a buffer  */ 
void show(buf b)
{ 
   printf("%s", b.array); 			
} 	



/* Enter a char into a buffer and display the buffer array.  */ 
buf set(buf b, int i)
{ 
  if ( (b.index < 80)  )  
    { 
	   b.array[b.index] = i;	
	   b.index += 1	;
    } 
  else
    { 
	   memset(&b.array[0], 0, sizeof(b.array) ); 
	   b.array[0] = i;
	   b.index += 1	;	    	
    }		
  
  show(b); 
  return b; 	
	
} 


/*  Return a line from hist.  */ 
buf get(hist h)
{ 
   buf b; 
   memcpy(&b.array[0], h.array[h.curindex], 80); 
   return b;		
}	 



/* Move up in history list. */ 
hist up(hist h) 
{ 
	
  buf b;  	  
	
  if ( (h.curindex > 0) )  
    { 
		h.curindex -= 1; 
		memset(&b.array[0], 0, sizeof(b.array) ); 
		memcpy(&b.array[0], h.array[h.curindex], 80); 	
		show(b);          	
        return h;  		
    }    
     
  else error();  
  
} 


/* Move down in history list. */ 
hist down(hist h) 
{ 
	
  buf b; 	  
	
  if ( (h.curindex < 19) )  
    { 
		h.curindex += 1; 
		memset(&b.array[0], 0, sizeof(b.array) ); 
		memcpy(&b.array[0], h.array[h.curindex], 80); 
		show(b);    
        return h;  			
    }  
    
  else error();     
  
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
void spec(hist h)
{ 
	
  int j = getch();  
    
       if ( ( j == 65 )	)  up(h); 
  else if ( ( j == 66 )	)  down(h); 
  else if ( ( j == 67 )	)  printf("Right "); 
  else if ( ( j == 68 )	)  printf("Left "); 
   		
} 	





