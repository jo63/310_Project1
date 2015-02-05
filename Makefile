EXECUTABLES = deli 
CC = g++ -m32
FLAG= -o -Wall -ldl

all: $(EXECUTABLES)

debug: FLAGS += $(DEBUGFLAG)
debug: $(EXECUTABLES)
	for dbg in ${EXECUTABLES}; do \
		gdb ./$$dbg ; \
	done

deli: deli.cc dthreads.h dthreads.o libinterrupt.a
		$(CC) $(FLAG) deli deli.cc dthreads.h dthreads.o libinterrupt.a
		



clean:
	rm -f *.o ${EXECUTABLES} a.out
