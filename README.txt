
Put your answers to non-coding questions in this file as described in
the assignment description.

All answers are to be in plain text ASCII.

a. An array of long with 8 rows and 128 columns, a direct-mapped cache, and the function sumA from the program cache-test provided in the first part of the assignment.
    Sum = 786944
    Miss rate =   0.2500

    In this case, the miss rate is 1/4 because the first access is a compulsory miss. After, because each block is 32 bytes and can fit 4 longs, the next 3 accesses will be cache hits.

    There are 64 blocks, at 32 bytes per block -> 2048 bytes in the cache. 
    The array has 8 rows * 128 columns * 8 bytes per long = 8,192 bytes.
    Therefore we know that the cache can store 1/4th of the total array. 

b. An array of long with 8 rows and 128 columns, a direct-mapped cache, and the function sumB from the program cache-test provided in the first part of the assignment.
    Sum = 786944
    Miss rate =   1.0000

    In this case, we are caching in column major order.

    The first access at a[0][0] will be a compulsory miss because the cache is empty. The cache will put the first block (4 longs) at set 0.
    The cache will keep storing array data 16 sets (16 * 8 = 128) at a time till the the 8th block at a[0][8]. 
    Then it will cycle back to set 0 which will get replaced by a[0][8], causing misses to all of the accesses in the block. 
    The next cache access will all replace old blocks because they map to blocks that will have been replaced due to being evenly divisible.

c. An array of long with 8 rows and 128 columns, a direct-mapped cache, and the function sumC from the program cache-test provided in the first part of the assignment.
    Sum = 786944
    Miss rate =   0.5000

    This case, we are caching in column major order with a stride of 2.

    Since each block can fit 2 longs, and the stride is 2, every block will have 2 accessses, a compulsory miss, followed by a cache hit.
    Since the cache is evenly divisible, this will occur throughout the loop, and the entire cache will have a miss rate of 1/2

d. An array of long with 8 rows and 128 columns, a two-way set-associative cache with LRU replacement, and the function sumB from the program cache-test provided in the first part of the assignment.
    Sum = 786944
    Miss rate =   1.0000

    In this case, we have a column major order with two-way set-associative cache. 
    
    From this we can conclude that our cache will have half the amount of sets (16) when compared to a direct-mapped cache.
    When we go to read a[0][1], the block from a[0][0] will be replaced already, causing misses to all of the accesses in the block. 
    This pattern follows for the rest of the loop.
    Therefore all the cache accesses will always be cold misses and the miss rate = 1.0000.

e. An array of long with 8 rows and 128 columns, a four-way set-associative cache with LRU replacement, and the function sumB from the program cache-test provided in the first part of the assignment.
    Sum = 786944
    Miss rate =   1.0000

    In this case, we have a column major order with four-way set-associative cache. 

    From this we can conclude that our cache will have a fourth the amount of sets (8) when compared to a direct-mapped cache.
    When we go to read a[0][1], the block from a[0][0] will be replaced already, causing misses to all of the accesses in the block.
    This pattern follows for the rest of the loop.
    Therefore all the cache accesses will always be cold misses and the miss rate = 1.0000.

f. An array of long with 8 rows and 128 columns, a four-way set-associative cache with random replacement, and the function sumB from the program cache-test provided in the first part of the assignment.
    Sum = 786944
    Miss rate =   1.0000

    In this case, we have a column major order with four-way set-associative cache. 

    From this we can conclude that our cache will have a fourth the amount of sets (8) when compared to a direct-mapped cache.
    When we go to read a[0][1], the block from a[0][0] will be replaced already, causing misses to all of the accesses in the block.
    This pattern follows for the rest of the loop.
    Therefore all the cache accesses will always be cold misses and the miss rate = 1.0000.

g. An array of long with 8 rows and 120 columns, a direct-mapped cache, and the function sumB from the program cache-test provided in the first part of the assignment.
    Sum = 707040
    Miss rate =   0.2500