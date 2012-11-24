

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


/*  History. */ 
typedef struct { 
	int curindex; 
	char array[20][80]; 
} hist;    




/*  Termios funcs.  */ 
void initTermios(int echo) ;
void resetTermios(void) ;
char getch_(int echo);
char getch(void);
char getche(void);


/*  Buffer funcs. */ 
void error(void); 
void show(buf b);
buf set(buf b, int i);
buf get(hist h); 

hist up(hist h); 
hist down(hist h); 
buf left(buf b); 
buf right(buf b); 
buf delch(buf b); 
buf insch(buf b); 
void enter(void);  
int range(int rstart, int rend, int i);
int type(int i); 


/*  Special key handling.  */ 
void spec(hist h); 


/*  Other funcs.  */  
hist readhistory(char *fname); 
void keyhandler(buf b, hist h);  









