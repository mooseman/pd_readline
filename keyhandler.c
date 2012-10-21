


/*  keyhandler.c                                       */ 
/*  Handle keystrokes for pd_readline.                 */ 
/*  This code is released to the public domain.        */ 
/*  "Share and enjoy...."  ;)                          */  
/*  See the UNLICENSE file for details.                */ 


#include <string.h>   
#include <stdio.h> 
#include <stdlib.h> 
#include <termios.h>  


/* This implementation of getch() is from here - */ 
/* http://wesley.vidiqatch.org/                  */ 
/* Thanks, Wesley!                               */  
static struct termios old, new;

/* Initialize new terminal i/o settings */
void initTermios(int echo) {
    tcgetattr(0, &old); /* grab old terminal i/o settings */
    new = old; /* make new settings same as old settings */
    new.c_lflag &= ~ICANON; /* disable buffered i/o */
    new.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
    tcsetattr(0, TCSANOW, &new); /* use these new terminal i/o settings now */
}


/* Restore old terminal i/o settings */
void resetTermios(void) {
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



int keyhandler(void) 
{ 
  int i = getch(); 
  
  switch(i); 
  { 
    case (27):  escape() ; 
    case (33):  dosomething();  
    case (42):  something();
    default:    stuff(): 
  }   
  
} 




