/* CSE 374
 * Homework 6
 * Ziruo Ke, Wufan Xiao
 * bench.c, the main function
 **/

#include "mem.h"
<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv){
    //define total_size, total_free, and n_free_block
    uintptr_t ts = 0;
    uintptr_t tf = 0;
    uintptr_t nfb = 0;
    uintptr_t* tsp = &ts;
    uintptr_t* tfp = &tf;
    uintptr_t* nfbp = &nfb;
    
    
    int new_args[] = {10000, 50, 10, 200, 20000, time(NULL)};
    for (int i = 0; i < argc-1; i++) {
        new_args[i] = atoi(argv[i+1]);
    }
    srand(new_args[5]);

    clock_t start = clock();
    double total_time;
      double time_passed;
    int probability;
    int cur_ptr = 0;
    int temp_tenth = args[0] / 10;
    void** get_mem_ptr = (void**)malloc(new_args[0]*sizeof(void*));

    for (int i = 0; i < new_args[0]; i++) {
        if (i % temp_tenth == 0 && i != 0) {
            printf("Percentage done: %d.\n", i / temp_tenth * 10);
            get_mem_stats(total_size, total_free, n_free_blocks);
            total_time = ((double) (clock() - start)) / CLOCKS_PER_SEC;
            printf("CPU TIME: %f seconds\n", total_time);
            printf("Total amount of storage acquired from the underlying system: %lu.\n", ts);
            printf("Total number of blocks on the free list: %lu.\n", nfb);
            if (nfb != 0) {
                printf("Average number of bytes in the free list: %lu.\n", tf / nfb);
            } else {
                printf("Average number of bytes is zero since there is no block.\n");
            }
        }
        probability = rand() % 100;
        if (probability < new_args[1]) {  // getmem
            probability = rand() % 100;
            uintptr_t new_size;
            if (probability < new_args[2]) {
                new_size = (uintptr_t) (rand() % (new_args[4] - new_args[3]) + new_args[3]);
            } else {
                new_size = (uintptr_t) (rand() % new_args[3]);
            }
            get_mem_ptr[cur_ptr] = getmem(new_size);
            cur_ptr++;
        } else {  // freemem
            if (cur_ptr > 0) {
                int index = rand() % cur_ptr;
                freemem(get_mem_ptr[index]);
                get_mem_ptr[index] = get_mem_ptr[cur_ptr - 1];
                cur_ptr--;
            }
        }
    }
    printf("100% done\n");
    get_mem_stats(total_size, total_free, n_free_blocks);
    total_time = ((double) (clock() - start)) / CLOCKS_PER_SEC;
    printf("CPU TIME: %f seconds\n", total_time);
    printf("Total amount of storage acquired from the underlying system: %lu.\n", ts);
    printf("Total number of blocks on the free list: %lu.\n", nfb);
    if (nfb != 0) {
        printf("Average number of bytes in the free list: %lu.\n", tf / nfb);
    } else {
        printf("Average number of bytes is zero since there is no block.\n");
    }
    printf("All tests passed\n");
    free(get_mem_ptr);
    return EXIT_SUCCESS;
=======

int main(int argc, char** argv){

>>>>>>> 7b3ea6ba7ea6b48c9a90325a7c47545f856d0842
}

