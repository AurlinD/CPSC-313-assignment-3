
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

Part 3:
mask0 results :
c0f0b@anvil:a3_c0f0b_e1d0b$ ./timemask-mask0 galaxy.pgm 10 galaxyTestMask0.pgm
Processing a mask for a 2048x2048 image for 10 trials (check must be: 158581069)

Base run  0 done, check    158581069, took      2803781 usec
Base run  1 done, check    158581069, took      2778138 usec
Base run  2 done, check    158581069, took      2709853 usec
Base run  3 done, check    158581069, took      2669435 usec
Base run  4 done, check    158581069, took      2688988 usec
Base run  5 done, check    158581069, took      3093382 usec
Base run  6 done, check    158581069, took      3050108 usec
Base run  7 done, check    158581069, took      3022733 usec
Base run  8 done, check    158581069, took      3054379 usec
Base run  9 done, check    158581069, took      3088507 usec

The base implementation took:
	Best   :      2669435 usec
	Average:      2895930 usec

Starting the optimized version

Optimized run  0 done, check    158581069, took       475793 usec
Optimized run  1 done, check    158581069, took       477459 usec
Optimized run  2 done, check    158581069, took       481114 usec
Optimized run  3 done, check    158581069, took       481194 usec
Optimized run  4 done, check    158581069, took       481250 usec
Optimized run  5 done, check    158581069, took       479580 usec
Optimized run  6 done, check    158581069, took       478080 usec
Optimized run  7 done, check    158581069, took       479639 usec
Optimized run  8 done, check    158581069, took       482177 usec
Optimized run  9 done, check    158581069, took       478864 usec

The optimized implementation took:
	Best   :       475793 usec
	Average:       479515 usec

16.5 % of time taken compared to base

mask1 results:

c0f0b@anvil:a3_c0f0b_e1d0b$ ./timemask-mask1 galaxy.pgm 10 galaxyTestMask1.pgm
Processing a mask for a 2048x2048 image for 10 trials (check must be: 158581069)

Base run  0 done, check    158581069, took      2702910 usec
Base run  1 done, check    158581069, took      2693428 usec
Base run  2 done, check    158581069, took      3058560 usec
Base run  3 done, check    158581069, took      3040475 usec
Base run  4 done, check    158581069, took      3028557 usec
Base run  5 done, check    158581069, took      3055513 usec
Base run  6 done, check    158581069, took      2999036 usec
Base run  7 done, check    158581069, took      3011791 usec
Base run  8 done, check    158581069, took      3073719 usec
Base run  9 done, check    158581069, took      3029163 usec

The base implementation took:
	Best   :      2693428 usec
	Average:      2969315 usec

Starting the optimized version

Optimized run  0 done, check    158581069, took       454675 usec
Optimized run  1 done, check    158581069, took       455790 usec
Optimized run  2 done, check    158581069, took       452704 usec
Optimized run  3 done, check    158581069, took       452696 usec
Optimized run  4 done, check    158581069, took       452861 usec
Optimized run  5 done, check    158581069, took       452698 usec
Optimized run  6 done, check    158581069, took       452506 usec
Optimized run  7 done, check    158581069, took       452606 usec
Optimized run  8 done, check    158581069, took       452495 usec
Optimized run  9 done, check    158581069, took       452453 usec

The optimized implementation took:
	Best   :       452453 usec
	Average:       453148 usec

15.2 % time taken compared to base

mask2 results:
c0f0b@anvil:a3_c0f0b_e1d0b$ ./timemask-mask2 galaxy.pgm 10 galaxyTestMask2.pgm
Processing a mask for a 2048x2048 image for 10 trials (check must be: 158581069)

Base run  0 done, check    158581069, took      2838517 usec
Base run  1 done, check    158581069, took      2701013 usec
Base run  2 done, check    158581069, took      2678467 usec
Base run  3 done, check    158581069, took      2702846 usec
Base run  4 done, check    158581069, took      2711851 usec
Base run  5 done, check    158581069, took      2695623 usec
Base run  6 done, check    158581069, took      2678759 usec
Base run  7 done, check    158581069, took      2695215 usec
Base run  8 done, check    158581069, took      2710287 usec
Base run  9 done, check    158581069, took      2691815 usec

The base implementation took:
	Best   :      2678467 usec
	Average:      2710439 usec

Starting the optimized version

Optimized run  0 done, check    158581069, took       439712 usec
Optimized run  1 done, check    158581069, took       439695 usec
Optimized run  2 done, check    158581069, took       439698 usec
Optimized run  3 done, check    158581069, took       439844 usec
Optimized run  4 done, check    158581069, took       440030 usec
Optimized run  5 done, check    158581069, took       439669 usec
Optimized run  6 done, check    158581069, took       440535 usec
Optimized run  7 done, check    158581069, took       439911 usec
Optimized run  8 done, check    158581069, took       439943 usec
Optimized run  9 done, check    158581069, took       439829 usec

The optimized implementation took:
	Best   :       439669 usec
	Average:       439886 usec

16.2 % of time taken compared to base
