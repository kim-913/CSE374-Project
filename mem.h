/* CSE 374
 * Homework 6
 * Ziruo Ke, Wufan Xiao
 * Header files for memory management package
 **/

<<<<<<< HEAD
#define h_size=16;
=======
#ifndef MEM_H
#define MEM_H
>>>>>>> 7b3ea6ba7ea6b48c9a90325a7c47545f856d0842

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void* getmem(uintptr_t size);

void freemem(void* p);

void get_mem_stats(uintptr_t* total_size,
                   uintptr_t* total_free,
                   uintptr_t* n_free_blocks);

void print_heap(FILE *f);
#endif
