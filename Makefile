# Ziruo Ke, Wufan Xiao
# CSE 374 Homework 6
# 05/20/2021
# Makefile

all: bench

bench: bench.o getmem.o get_mem_stats.o print_heap.o freemem.o mem_utils.o makeNode.o
		gcc -Wall -std=c11 -g -o bench bench.o getmem.o get_mem_stats.o print_heap.o mem_utils.o freemem.o makeNode.o

bench.o: bench.c mem.h mem_impl.h
		gcc -Wall -std=c11 -g -c bench.c

getmem.o: getmem.c mem.h
	gcc -Wall -std=c11 -g -c getmem.c

get_mem_stats.o: get_mem_stats.c mem.h
	gcc -Wall -std=c11 -g -c get_mem_stats.c

print_heap.o: print_heap.c mem.h
	gcc -Wall -std=c11 -g -c print_heap.c

freemem.o: freemem.c mem.h
	gcc -Wall -std=c11 -g -c freemem.c

mem_utils.o: mem_utils.c mem_impl.h
	gcc -Wall -std=c11 -g -c mem_utils.c

makeNode.o: makeNode.c mem.h
	gcc -Wall -std=c11 -g -c makeNewNode.c

test: bench
	./bench 10 1000

clean:
		rm -f *.o bench *~