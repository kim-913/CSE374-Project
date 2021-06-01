/* CSE 374
 * Homework 6
 * Ziruo Ke, Wufan Xiao
 * Source file freemem.c
 **/

#include "mem_impl.h"
#include "mem.h"

void freemem(void* p) {
check_heap();
    if (p) {
        freeListNode* curr = freeList;
        freeListNode* prev = NULL;
        freeListNode* exist = (freeListNode*) ((uintptr_t) p - sizeof(freeListNode));
        freeListNode* e_block = (freeListNode*) ((uintptr_t) exist + exist->size + sizeof(freeListNode));
        totalFree += exist->size + sizeof(freeListNode);
        while (curr && (e_block > curr)) {
            prev = curr;
            curr = curr->next;
        }
        // Looking at the beginning of free storage
        if (prev == NULL) {
            if (e_block == freeList) {
                exist->next = freeList->next;
                exist->size = exist->size + freeList->size + sizeof(freeListNode);
            } else {
                exist->next = freeList;
                nFreeBlocks++;
            }
            freeList = exist;
            return;
        }
        freeListNode* last_block = (freeListNode*) ((uintptr_t) prev + prev->size
                                        + sizeof(freeListNode));
        //Looking at the end of the free storage
        if (curr == NULL) {
            prev->next = exist;
            exist->next = NULL;
            nFreeBlocks++;
            return;
        }
        // Looking inside of free storage
        if (e_block == curr && exist == last_block) {
            prev->size = prev->size + exist->size + curr->size + 32;
            prev->next = curr->next;
            nFreeBlocks--;
        } else if (exist == last_block) {
            prev->size = prev->size + exist->size + 16;
        } else if (e_block == curr) {
            exist->next = curr->next;
            prev->next = exist;
            exist->size = exist->size + curr->size + 16;
        } else {
            exist->next = curr;
            prev->next = exist;
            nFreeBlocks++;
        }
    }
    check_heap();
}
