

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
int up(int i); 
int down(int i); 
buf left(buf b); 
buf right(buf b); 
buf delch(buf b); 
buf insch(buf b); 

/*  Escape-key handling.  */ 
int esc(int i); 

/*  Other funcs.  */  
void readhistory(char *fname); 
int keyhandler(void);  









