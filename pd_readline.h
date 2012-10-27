

/*  pd_readline.h                                      */  
/*  Header file for pd_readline.                       */ 
/*  This code is released to the public domain.        */ 
/*  "Share and enjoy...."  ;)                          */  
/*  See the UNLICENSE file for details.                */ 


/*  Buffer typedef.  */ 
typedef struct { 
	int index; 
	char array[80] ; 
} buf;  



/*  Cursor movement funcs. */ 
buf up(int i); 
buf down(int i); 
buf left(buf b); 
buf right(buf b); 
buf delch(buf b); 
buf insch(buf b); 
void enter(void);  
int range(int rstart, int rend, int i);
int type(int i); 


/*  Special key handling.  */ 
void spec(void); 


/*  Other funcs.  */  
void readhistory(char *fname); 
void keyhandler(buf b);  









