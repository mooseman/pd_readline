

/*  pd_readline.c                                           */  
/*  Status (as at 26th Aug 2012) : useful progress.         */ 
/*  Keystroke sequences (along with the special flags       */ 
/*  like Esc, Ctrl, Alt etc are now stored in a buffer      */ 
/*  ( an array of structs ).                                */    
/*  It will still be some time before this is a REAL        */ 
/*  readline, but we are "on the way"......                 */     
/*  This code is released to the public domain.             */ 
/*  "Share and enjoy...."  ;)                               */  


#include <string.h>   
#include <stdio.h> 


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
	
  printf("Public Domain Readline \n");              
  printf("NOTE! - at the moment, we are using \n");  
  printf("NON-echoing reads, storing the keystrokes \n");  
  printf("in a buffer \n");   
    
  
  /* Buffer - an array of keyseq structs.                     */  
  /* Note - now that we store the keystrokes in here,         */ 
  /* we can look at the various flags and decide whether to   */ 
  /* "echo" the key (as normal) or suppress it (as with an    */ 
  /* arrow key).                                              */    
  keyseq buffer[80] ;   
  
  /* Buffer "pointer"  */ 
  int bufpnt = 0; 
  
  
  /* Test for existence of history file. */  
  int exists;  
  exists = fexists(".history"); 
  printf("Result: %d \n", exists);  
  
  while(1) 
    {  
                   
      int key = getchar(); 
       
      /* Printable chars. */  
      if ( (key >= 32)  && (key <= 126) ) 
      { 
		putchar(key);    		
        buffer[bufpnt].key = key;  
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
			  buffer[bufpnt].esc = 1; 			 
			  key = getchar(); 
              if(key == 91)               
              buffer[bufpnt].lbr = 1;                
              key = getchar(); 
              if( (key >= 65) && (key <= 68) )  
               { 				 
				 buffer[bufpnt].key = key;                  
               }				  
            bufpnt += 1; 	    
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




