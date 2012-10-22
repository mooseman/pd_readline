

#  Makefile for pd_readline    


CC = gcc

CFLAGS = -O2 -Wall -g -c $(DEFINES)


# INCPATH = -I.
INCPATH = .  

LDFLAGS = $(SYSLDFLAGS) $(MYLDFLAGS)

# LIBS = -l$(SYSLIBS) $(MYLIBS)

RM = rm -f 

HEADERS= pd_readline.h 

OBJECTS =  keyhandler.o  funcs.o  history.o pd_readline.o

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

pd_readline: $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBS)

keyhandler.o: $(HEADERS)
funcs.o: $(HEADERS)
history.o: $(HEADERS)
pd_readline.o: $(HEADERS)


.PHONY: clean
clean:
	rm *.o 



