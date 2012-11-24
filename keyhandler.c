


/*  keyhandler.c                                       */ 
/*  Handle keystrokes for pd_readline.                 */ 
/*  This code is released to the public domain.        */ 
/*  "Share and enjoy...."  ;)                          */  
/*  See the UNLICENSE file for details.                */ 


#include <string.h>   
#include <stdio.h> 
#include <stdlib.h> 
#include <termios.h>  
#include "pd_readline.h"  


/* This implementation of getch() is from here - */ 
/* http://wesley.vidiqatch.org/                  */ 
/* Thanks, Wesley!                               */  
static struct termios old, new;

/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
    tcgetattr(0, &old); /* grab old terminal i/o settings */
    new = old; /* make new settings same as old settings */
    new.c_lflag &= ~ICANON; /* disable buffered i/o */
    new.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
    tcsetattr(0, TCSANOW, &new); /* use these new terminal i/o settings now */
}


/* Restore old terminal i/o settings */
void resetTermios(void) 
{
    tcsetattr(0, TCSANOW, &old);
}


/* Read 1 character - echo defines echo mode */
char getch_(int echo) {
    char ch;
    initTermios(echo);
    ch = getchar();
    resetTermios();
    return ch;
}


/* Read 1 character without echo */
char getch(void) {
    return getch_(0);
}


/* Read 1 character with echo */
char getche(void) {
    return getch_(1);
} 



/*  Arrow keys are esc [ A to esc [ D                       */ 
/*  Alt keys are just esc then key (e.g. Alt-g is esc g ).  */   
/*  Ctrl (then letter) keys are just Dec 1 to Dec 26        */ 

void keyhandler(buf b, hist h) 
{ 
    
  int a = getch();    
  
  int t = type(a); 
    
  switch(t)
  { 
	  
	case (1):   break;     /*  Ctrl a  */   
	case (2):   break;     /*  Ctrl b  */   
	case (3):   getch();  spec(h); break;   /*  Ctrl c  */     
	case (4):   set(b, a);   break;    /*  Printable chars.  */    
	case (5):   delch(b);  break;  
	case (6):   break;  
	default:    break; 
		     
  }   
   
}    






