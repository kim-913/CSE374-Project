/* CSE 374
 * Homework 6
 * Ziruo Ke, Wufan Xiao
 * Header files for memory management package
 **/

#ifndef MEM_H
#define MEM_H

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
