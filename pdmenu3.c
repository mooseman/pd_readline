

/*  pdmenu.c                                                */  
/*  This code is aimed at helping those who would like to   */ 
/*  create menus without using the curses library.          */ 
/*  It creates a count variable (which could be used to     */ 
/*  keep track of which item is highlighted). Using the     */ 
/*  up and down arrow keys increments and decrements the    */ 
/*  count variable. Finally, when you press Enter, the      */ 
/*  value of the count variable is printed and the program  */ 
/*  exits.                                                  */       
/*  This code is released to the public domain.             */ 
/*  "Share and enjoy...."  ;)                               */  


#include <string.h>   
#include <stdio.h> 
#include <termios.h>  /* For getch()  */  

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



/*  Helper function, to let us see if a .history file */ 
/*  exists in the current directory.  */ 
int fexists(char *fname)
{  

   FILE *fptr ;  	
	
   fptr = fopen(fname, "r") ;  
   
   if ( !fptr )  return -1 ;  /* File does not exist in dir. */ 	
	 
   fclose(fptr);  
   return 0;    /* File DOES exist in dir.  */  	

} 


 /* Struct to store key sequences */ 
typedef struct { 
	   int fnkey; 
	   int ctrl; 
	   int alt ; 
       int shf ; 
       int esc ; 
       int lbr ;  /* For left-bracket ([) of escape sequences */ 
       int key; 
   } keyseq ;         





int main(void)
{
	
  printf("Public Domain Menu Program \n");              
 
    
  keyseq myseq;      
       
  
  /* Buffer */  
  keyseq buffer[80] ;   
  
  /* Buffer "pointer"  */ 
  int bufpnt = 0; 
  
  
  /* Test for existence of history file. */  
  int exists;  
  exists = fexists(".history"); 
  printf("Result: %d \n", exists);  
  
  while(1) 
    {  
                   
      int key = getch(); 
       
      /* Printable chars. */  
      if ( (key >= 32)  && (key <= 126) ) 
      { 
		myseq.key = key;   
        buffer[bufpnt] = myseq;  
        bufpnt += 1; 
      }  
                                                                       
      /* Up arrow is 27, 91, 65.    ( ESC [ A )   */   
      /* Down arrow is 27, 91, 66.  ( ESC [ B )   */ 
      /* Right arrow is 27, 91, 67. ( ESC [ C )   */ 
      /* Left arrow is 27, 91, 68.  ( ESC [ D )   */    
      /* Function keys.     */ 
      /* F2 is 27, 79, 81.  */  
      /* F3 is 27, 79, 82.  */  
      /* F4 is 27, 79, 83.  */  
           
                
      else if(key == 27)        
          {  
			  myseq.key = key; 
			  buffer[bufpnt] = myseq; 
			  bufpnt += 1; 
			  key = getch(); 
              if(key == 91) 
              myseq.key = key; 
              buffer[bufpnt] = myseq;  
              bufpnt += 1; 			                
              key = getch(); 
              if( (key >= 65) && (key <= 68) )  
               { 
				 myseq.key = key;   
				 buffer[bufpnt] = myseq;  
                 bufpnt += 1; 	
               }				  
          }
              
                                          
                                                 
    /* The Enter key exits. Enter is 10 decimal */	  
        else if(key == 10)  
		{ 
			 int j ; 
		   /* Print the array of structs. */ 
		     for (j=0; j<10; j++) 	
		     { 
			    printf("Fnkey: %d ", buffer[j].fnkey  ) ; 
			    printf("Ctrl:  %d ", buffer[j].ctrl   ) ;   
			    printf("Alt:   %d ", buffer[j].alt    ) ; 
			    printf("Shf:   %d ", buffer[j].shf    ) ; 
			    printf("Esc:   %d ", buffer[j].esc    ) ; 
			    printf("Lbr:   %d ", buffer[j].lbr    ) ;  
	            printf("Key:   %d \n", buffer[j].key  ) ; 
	         } 		  	
					  
             break;           
         }  /* Key = Enter */   
    }                
                                      
	return 0;
}  




