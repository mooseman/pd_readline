

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



/*  Buffer funcs. */ 
buf set(buf b, int i);
void show(buf b);
buf up(buf b); 
buf down(buf b); 
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
buf readhistory(char *fname); 
void keyhandler(buf b);  









