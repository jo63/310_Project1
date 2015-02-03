EXECUTABLES = deli 

all: $(EXECUTABLES)

debug: FLAGS += $(DEBUGFLAG)
debug: $(EXECUTABLES)
	for dbg in ${EXECUTABLES}; do \
		gdb ./$$dbg ; \
	done

CC = g++ -m32
FLAG= -o -Wall -Werror -ggdb3 -ldl
deli: deli.cc dthreads.h dthreads.o libinterrupt.a
        $(CC) $(FLAG) -o deli deli.cc dthreads.h dthreads.o libinterrupt.a
		
		
	
	
clean:
	rm -f *.o ${EXECUTABLES} a.out
