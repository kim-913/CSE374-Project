/* CSE 374
 * Homework 6
 * Ziruo Ke, Wufan Xiao
 * Header files for memory management package
 **/

#ifndef MEM_IMPL_H
#define MEM_IMPL_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct freeListNode {
    uintptr_t size;
    uintptr_t addr;
    struct freeListNode* next;
    struct freeListNode* front;
}freeListNode;

extern freeListNode* freeList;
extern uintptr_t total_size;
extern uintptr_t total_free;
extern uintptr_t n_free_blocks;
freeListNode* split(freeListNode* curr_block, uintptr_t size);
void insert(freeListNode* insertion_block);
void check_heap();
#endif
