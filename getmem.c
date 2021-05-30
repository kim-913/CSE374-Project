/* CSE 374
 * Homework 6
 * Ziruo Ke, Wufan Xiao
 * Source file getmem.c
 **/

#include "mem.h"
#include "mem_impl.h"

//#define h_size=16;
#define threshold=96;
#define resize = 4096;
freeListNode* make_n_block(uintptr_t size);

freeListNode* freeList = NULL;
uintptr_t total_size = 0;
uintptr_t total_free = 0;
uintptr_t n_free_blocks = 0;

// list helper function out to reduce redundancy
// this method helps to allocate new block memory
freeListNode* make_n_block(uintptr_t size) {
  if (resize > size) {
    size = resize;
  }
  freeListNode* n_block = (freeListNode*)(malloc(size + h_size));
  n_block->size = size;
  n_block->next = NULL;
  total_size += size + h_size;
  total_free += size + h_size;
  n_free_blocks += 1;
  return n_block;
}

void* getmem(uintptr_t size) {
    check_heap();
    if(size <= 0){
        return NULL;
    }
    // since memory will be aligned on 16 byte boundary
    if(size % 16 != 0){
        size = size + (16-size%16)
    }

    // if there's no block on freelist
    if(freeList == NULL){
        freeList = make_n_block(size);
    }
    freeListNode* n_block;
    void* curr_block;
    if (freeList->size >= size) {
        if (freeList->size >= size + threshold + h_size) {
        n_block = split(freeList, size);
        } else {
        n_block = freeList->next;
        n_free_blocks -= 1;
    }
    total_free -= (size + h_size);
    curr_block = (void*)(((uintptr_t)freeList) + h_size);
    freeList = n_block;
    return curr_block;
    }

    freeListNode* tempList = freeList;
    while (tempList != NULL && tempList->next != NULL) {
        freeListNode* next = tempList->next;
        uintptr_t cur_size = next->size;
        if (cur_size >= size) {
            if (cur_size >= size + threshold + h_size) {
                n_block = split(next, size);
            } else {
                n_block = next->next;
                n_free_blocks -= 1;
            }
            total_free -= (size + h_size);
            curr_block = (void*)(((uintptr_t) next) + h_size);
            tempList->next = n_block;
            return curr_block;
        } else {
            tempList = tempList->next;
        }
    }
    freeListNode* make_New = make_n_block(size);
    if (make_New->size >= size + h_size + threshold) {
        n_block = split(make_New, size);
        insert(n_block);
    } else {
        n_free_blocks -= 1;
    }
    curr_block = (void*)(((uintptr_t)make_New) + h_size);
    total_free -= (size + h_size);
    return curr_block;
}