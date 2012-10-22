

/*  pd_readline.c                                      */  
/*  Some code to allow the editing of a command-line.  */ 
/*  You can also move around with the left and right   */ 
/*  arrow keys, and recall previous commands with the  */ 
/*  up-arrow key.                                      */ 
/*  This code is released to the public domain.        */ 
/*  "Share and enjoy...."  ;)                          */  
/*  See the UNLICENSE file for details.                */ 

/*  TO DO -                                            */ 
/*  a) Add support for Home and End (of line) keys.    */ 
/*  b) Add support for function keys.                  */ 
/*  c) Add support for Insert key so that text can be  */ 
/*     inserted.                                       */   
/*  d) Put much of the code into a header file.        */    
/*  e) Change so that pressing Enter adds the current  */  
/*     line of commands to the command-history.        */ 
/*     ( May look at using Ctrl-D to exit, as Python   */ 
/*     does with its command-line. )                   */           
/*  f) Add support for copying and pasting text via    */ 
/*     Ctrl-C and Ctrl-V.                              */  


#include "pd_readline.h"    


int main(void) 
{ 
  
  /* Read in the command history file. */ 
  readhistory("test.txt");  
  
  
  while(1) 
  {  
       
    keyhandler();   
        
  }         
                                      
  return 0;
	
}  






