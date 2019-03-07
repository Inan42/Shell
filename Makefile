#compile and run tests

FILES := procline.c userin.c runcommand.c handlers.c shell.h  
CC		= gcc
CFLAGS := -g -Og -std=gnu99 

all: handlers test_run test_run_loop

shell: $(FILES)
	cc -o shell  $(FILES) 
    
test_run: test_run.c 
	cc -o test_run test_run.c 	
	
test_run_loop: test_run_loop.c 
	cc -o test_run_loop test_run_loop.c 
	
test_run_sleep: test_run_sleep.c 
	cc -o test_run_sleep test_run_sleep.c 
	
test_run_pause: test_run_pause.c 
	cc -o test_run_pause test_run_pause.c 

clean: 
	rm -f *~ shell shell.o *.o a.out test_run test_run_loop test_run_pause test_run_sleep core
