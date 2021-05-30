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

typedef struct freeNode {
    uintptr_t size;
    uintptr_t addr;
    struct freeNode* next;
    struct freeNode* front;
}freeNode;

extern freeNode* freeList;
<<<<<<< HEAD
extern uintptr_t total_size;
extern uintptr_t total_free;
extern uintptr_t n_free_blocks;
void check_heap();
freeListNode* split(freeListNode* curr_block, uintptr_t size);
freeListNode* split(freeListNode* curr_block, uintptr_t size);
void insert(freeListNode* insertion_block);

=======
void check_heap();
>>>>>>> 7b3ea6ba7ea6b48c9a90325a7c47545f856d0842
#endif
