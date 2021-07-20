# cse374-project
Ziruo Ke, Wufan Xiao

Ziruo Ke: responsible for bench.c, getmem.c, get_mem_stats.c, mem.h, mem_impl.h, mem_utils.c, print_heap.c

WufanXiao: responsible for bench.c, freemem.c, mem.h, mem_utils.c, get_mem_stats.c, mem_impl.h

The freeList: That is organized in ascending order based on the address of blocks. In the struct, we create size, address, the front and next node. In order to make sure the getmem can run, the size of it must be larger than 16 because the blocks are 16-byte aligned. When calling getmem, it will go through the list and find the enough size for the requirement. When the freemem is called, it will go through the free storage until the location of the given block is discovered. 

We did not do any extra credit. 

bench: with 10000 trials, takes 0.04 seconds to run. The amount of bytes for freelistnode is around 26000. Increasing the lagre block of memory tends to increase the run time of bench

Resources: Searched online resources to implement getmem and freemen. Others we just used the lecture slides. # CSE374-Project
