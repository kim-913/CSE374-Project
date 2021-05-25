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
void check_heap();
#endif
