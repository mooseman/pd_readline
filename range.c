

/*  range.c  */  

/*  See if an int is in a given range.  */ 



#include <string.h>   
#include <stdio.h> 
#include <stdlib.h> 



/* Find if a number is in a given range. */ 
int range(int rstart, int rend, int i)
{
   if ( (rstart <= i) && (i <= rend) ) return 1;
   else return 0;	
	
} 	



int main() 
{ 

/* Within the range. */ 
int a = range(0, 9, 5); 
int b = range(0, 9, 0);
int c = range(0, 9, 9);  
int d = range(20, 40, 32); 


/* Outside the range. */ 
int e = range(0, 9, -15); 
int f = range(20, 40, 75); 
int g = range(50, 80, 91); 

printf("%d %d %d %d %d %d %d \n", a, b, c, d, e, f, g);   


int i = 65; 
char s[2]; 

snprintf(s, 2, "%c", i);  

printf("%s \n" , s ); 

return 0; 


} 








