

/*  pd_readline.c                                      */  
/*  Some code to allow the editing of a command-line.  */ 
/*  You can also move around with the left and right   */ 
/*  arrow keys, and recall previous commands with the  */ 
/*  up-arrow key.                                      */ 
/*  This code is released to the public domain.        */ 
/*  "Share and enjoy...."  ;)                          */  
/*  See the UNLICENSE file for details.                */ 

/*  TO DO -                                            */ 
/*  a) Fix the "stack smash" problem.                  */  
/*  b) Put much of the code into a header file.        */    
/*  c) Change so that pressing Enter adds the current  */  
/*     line of commands to the command-history.        */ 
/*     ( May look at using Ctrl-D to exit, as Python   */ 
/*     does with its command-line. )                   */           
/*  d) Add support for copying and pasting text via    */ 
/*     Ctrl-C and Ctrl-V.                              */  


#include <string.h>   
#include <stdio.h> 
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
void readfile(char *fname) 
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


/* Helper function to print the command-history file. */  
void printfile(void) 
{ 
  int j; 
  	
  for(j=0; j<20; j++) 
     { 
        puts(hist[j]);     	
     }    	
} 	




/* Helper function. Print a previous command-line WITHOUT */ 
/* a newline. */ 
void putline(char *str) 
{   
  char *line = chop(str); 	
  printf("%s", line);          		
} 	 




int main(void) 
{ 

/* Our "command-history" file.  */ 
readfile("test.txt"); 

/* Main buffer for the command-line. */ 
char buffer[80];  
    
/* Main buffer "pointer"  */ 
int bufpnt = 0; 
      
/* "Pointer" for the history file. */ 
int histpnt = 20;       
      
  
  while(1) 
    {  
                   
      int key = getch();      
      buffer[bufpnt] = key; 				       
      bufpnt += 1;        
       
      /* Printable chars. */  
      if ( (key >= 32)  && (key <= 126) ) 
      { 
		/* We have a printable key so print it. */   
		putchar(key);   
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
      
      /* Backspace */ 
      else if(key == 127) 
      { 
		 /* Move left 1 char and delete that char */ 
		 bufpnt -= 1;  	
		 printf("\033[1D");
		 printf("\040"); 
		 printf("\033[1D");		 
		 /* Move 1 char to left again */  
		 bufpnt -= 1;  		
	  } 	      
        
     /* We have an escape key-sequence */                           
      else if(key == 27) 
        {
           key = getch(); 
           if(key == 91)               
           key = getch(); 
           
           if (key == 65)   /* Up Arrow */ 
          {   
			  /* Move one command "back" in history. */  
			  histpnt -= 1; 			  		  		
			  /* Clear to end of line. */ 
			  printf("\033[80D"); 
			  printf("\033[K"); 
			  /* Move buffer pointer to start of line */ 
			  bufpnt = 0;  
			  /* Clear the array. */ 
			  memset(buffer, 0, sizeof(char)*80);  			  			  
			  /* Print the pointed-at command-sequence. */ 
			  putline(hist[histpnt]); 			 
          }  
          
          if(key == 66)    /* Down Arrow */   			  
		  {  
			  /* Move one command "forward" in history. */  
			  histpnt += 1;  							  			 
			  /* Clear to end of line. */ 
			  printf("\033[80D"); 
			  printf("\033[K"); 
			  /* Move buffer pointer to start of line */ 
			  bufpnt = 0; 
			  /* Clear the array. */ 
			  memset(buffer, 0, sizeof(char)*80);  			  			   			  
			  /* Print the pointed-at command-sequence. */ 
			  putline(hist[histpnt]); 			  
		  }  
		  
		  if(key == 67)  /* Left arrow */ 
          { 	
			 /* Move one character to the left. */ 			 			 			  
			  printf("\033[1C"); 
          }
          
          if(key == 68)  /* Right arrow */ 
          { 	
			/* Move one character to the right. */ 			 			 						 			 			  			 
			  printf("\033[1D"); 
          }
		 		  	  		
      }  /* End of key=27 key sequence. */ 
					  			                                                   
                                                 
     /* The Enter key exits. Enter is 10 decimal */	  
        else if(key == 10)  
		{ 
			 puts("\n");  
			 puts("Exiting... \n"); 					  					
             break;           
         }  /* Key = Enter */   
    }                
                                      
	return 0;

}  






