/* CSE 374
 * Homework 6
 * Ziruo Ke, Wufan Xiao
 * Source file print_heap.c
 **/

#include "mem.h"
#include "mem_impl.h"

void print_heap(FILE *f) {
    freeListNode* temp = freeList;
    while (temp != NULL) {
        uintptr_t add_new = (uintptr_t)temp;
        fprintf(f, "The address of tempent block is: %lu and the size of this block is: %lu.\n", add_new, temp->size);
        temp = temp->next;
  }
}

