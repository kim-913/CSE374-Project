/* CSE 374
 * Homework 6
 * Ziruo Ke, Wufan Xiao
 * Source file mem_utils.c
 **/

#include <assert.h>
#include "mem_impl.h"
#include "mem.h"

void check_heap() {
    freeListNode* curr = freeList;
    while (curr != NULL && curr->next != NULL) {
        assert(curr->addr < curr->next->addr);
        assert(curr->size > 0);
        assert((curr->addr + curr->size) + 16 < (curr->next->addr));
        assert((curr->addr + curr->size) + 16 != (curr->next->addr));
        curr = curr->next;
    }
  return;
}

void insert(freeListNode* curr_block) {
    if (freeList == NULL || curr_block == NULL) {
        return;
    }
    uintptr_t add_new_block= (uintptr_t) curr_block;
    if (add_new_block< (uintptr_t)freeList) {
        curr_block->next = freeList;
        freeList = curr_block;
        return;
    }
    freeListNode* curr = freeList;
    freeListNode* next = curr->next;
    while (curr != NULL && next != NULL) {
        uintptr_t curr_add = (uintptr_t) curr;
        uintptr_t next_add = (uintptr_t) next;
        if (curr_add < add_new_block&& add_new_block< next_add) {
            curr->next = curr_block;
            curr_block->next = next;
        return;
        }
        curr = curr->next;
        next = next->next;
    }
    curr->next = curr_block;
    return;
}

freeListNode* split(freeListNode* curr_block, uintptr_t size) {
    uintptr_t split_size = curr_block->size - size - h_size;
    uintptr_t split_add = ((uintptr_t)curr_block) + h_size + size;
    freeListNode* split_block = (freeListNode*) split_add;
    split_block->size = split_size;
    split_block->next = curr_block->next;
    curr_block->size = size;
    curr_block->next = NULL;
    return split_block;
}