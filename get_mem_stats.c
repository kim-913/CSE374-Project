/* CSE 374
 * Homework 6
 * Ziruo Ke, Wufan Xiao
 * Source file get_mem_stats.c
 **/

#include "mem.h"
#include "mem_impl.h"

void get_mem_stats(uintptr_t* total_size,
                   uintptr_t* total_free,
                   uintptr_t* n_free_blocks) {
    *totalsize = total_size;
    *totalfree = total_free;
    *nfreeblocks = n_free_blocks;
}

