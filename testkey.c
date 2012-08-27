

/*  testkey.c  */ 

/*  Prints the keycode for a given key */  



#include <stdio.h> 
#include <stdlib.h> 



int main (void) 
{

int c; 

while( (c == getchar() ) ) 
{
   printf("%d 0x%02X\n", c );
} 

return 0; 

}
