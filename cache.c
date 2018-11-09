/*
 * cache.c
 */
#include "cache.h"
#include <stdlib.h>
#include <string.h>

/*
 * Initialize a new cache set with the given associativity and block
 * size.
 */
static void cache_set_init(cache_set_t *cache_set, unsigned int associativity,
			   size_t block_size) {
  int i;
  cache_set->cache_lines = (cache_line_t **) malloc(associativity * sizeof (cache_line_t *));
  
  size_t malloc_size = sizeof(cache_line_t) + block_size;
  void *block_data = malloc(malloc_size * associativity);
  
  for (i = 0; i < associativity; i++) {
    cache_set->cache_lines[i] = block_data;
    cache_set->cache_lines[i]->is_valid = 0;
    block_data += malloc_size;
  }
}

/*
 * Compute the shift and mask given the number of bytes/sets.
 */
static void get_shift_and_mask(int value, unsigned int *shift, uint64_t *mask,
			       int init_shift) {
  
  *mask = 0;
  *shift = init_shift;
  
  while (value > 1) {
    (*shift)++;
    value >>= 1;
    *mask = (*mask << 1) | 1;
  }
}

/*
 * Create a new cache that contains a total of num_blocks blocks, each
 * of which is block_size bytes long, with the given associativity,
 * and the given set of cache policies for replacement and write
 * operations.
 */
cache_t *cache_new(size_t num_blocks, size_t block_size,
		   unsigned int associativity, int policies) {
  
  int i;
  
  // Create the cache and initialize constant fields.
  cache_t *cache = (cache_t *) malloc(sizeof(cache_t));
  cache->access_count = 0;
  cache->miss_count = 0;
  
  // Initialize size fields.
  cache->policies = policies;
  cache->block_size = block_size;
  cache->associativity = associativity;
  cache->num_sets = num_blocks / associativity;
  
  // Initialize shifts and masks.
  get_shift_and_mask(block_size, &cache->cache_index_shift,
		     &cache->block_offset_mask, 0);
  get_shift_and_mask(cache->num_sets, &cache->tag_shift,
		     &cache->cache_index_mask, cache->cache_index_shift);
  
  // Initialize cache sets.
  cache->sets = (cache_set_t *) malloc(cache->num_sets * sizeof (cache_set_t));
  for (i = 0; i < cache->num_sets; i++) {
    cache_set_init(&cache->sets[i], cache->associativity, cache->block_size);
  }
  
  // Done.
  return cache;
}

/*
 * Determine whether or not a cache line is valid for a given tag.
 */
static int cache_line_check_validity_and_tag(cache_line_t *cache_line, intptr_t tag) {
  
  /* TO BE COMPLETED BY THE STUDENT */
  return (cache_line->is_valid && cache_line->tag == tag) ? 1 : 0;
}

/*
 * Return long integer data from a cache line.
 */
static long cache_line_retrieve_data(cache_line_t *cache_line, size_t offset) {
  
  /* TO BE COMPLETED BY THE STUDENT */
  long data = cache_line->data[offset];
  data += cache_line->data[offset + 1] << 8;
  data += cache_line->data[offset + 2] << 16;
  data += cache_line->data[offset + 3] << 24;
  return data;
}

/*
 * Move the cache lines inside a cache set so the cache line with the
 * given index is tagged as the most recently used one. The most
 * recently used cache line will be the 0'th one in the set, the
 * second most recently used cache line will be next, etc.  Cache
 * lines whose valid bit is 0 will occur after all cache lines whose
 * valid bit is 1.
 */
static cache_line_t *cache_line_make_mru(cache_set_t *cache_set, size_t line_index) {
  
  int i;
  cache_line_t *line = cache_set->cache_lines[line_index];
  
  for (i = line_index - 1; i >= 0; i--) {
    cache_set->cache_lines[i + 1] = cache_set->cache_lines[i];
  }
  
  cache_set->cache_lines[0] = line;
  return line;
}

/*
 * Retrieve a matching cache line from a set, if one exists.
 */
static cache_line_t *cache_set_find_matching_line(cache_t *cache, cache_set_t *cache_set,
						  uintptr_t tag) {
  
  /* TO BE COMPLETED BY THE STUDENT */
  
  /* Don't forget to call cache_line_make_mru(cache_set, i) if you
   * find a matching cache line.
   */
  for (int i = 0; i < cache->associativity; i++) {
    if (cache_line_check_validity_and_tag(cache_set->cache_lines[i], tag)) {
      return cache_line_make_mru(cache_set, i);
    }
  }
  return NULL;
}

/*
 * Function to find a cache line to use for new data. Uses either a
 * line not being used, or a suitable line to be replaced, based on
 * the cache's replacement policy.
 */
static cache_line_t *find_available_cache_line(cache_t *cache, cache_set_t *cache_set) {

  /* TO BE COMPLETED BY THE STUDENT */
  
  /* Don't forget to call cache_line_make_mru(cache_set, i) once you
   * have selected the cache line to use.
   */

  for (int = 0; i < cache->associativity; i++) {
    if (cache_set->cache_lines[i]->is_valid) {
      return cache_line_make_mru(cache_set, i);
    }
  }
  return cache_line_make_mru(cache_set, cache->associativity - 1); // Added to remove warning; remove once function is implemented.
}

/*
 * Add a block to a given cache set.
 */
static cache_line_t *cache_set_add(cache_t *cache, cache_set_t *cache_set,
				   uintptr_t address, uintptr_t tag) {
  
  // First locate the cache line to use.
  cache_line_t *line = find_available_cache_line(cache, cache_set);
  
  // Now set it up.
  line->tag = tag;
  line->is_valid = 1;
  memcpy(line->data, (void *) (address & ~cache->block_offset_mask), cache->block_size);
  
  // And return it.
  return line;
}

/*
 * Read a single long integer from the cache.
 */
long cache_read(cache_t *cache, long *address) {
  
  /* TO BE COMPLETED BY THE STUDENT */

  uintptr_t tagCache = (uintptr_t) address >> cache->tag_shift;
  uintptr_t indexCache = ((uintptr_t) address >> cache->set_index_shift) & cache->cache_index_mask;
  uintptr_t offsetCache = (uintptr_t) address & cache>block_offset_mask;

  cache_line_t *line = cache_set_find_matching_line(cache,set,tagCache);

  if (line == NULL){
    cache->miss_count++;
    line = cache_set_add(cache,set, (uintptr_t) address, tagCache);
  }
  else {
    if ((line->is_valid == 0) || (line->tag != tag)) {
      cache_miss_count++;
      line = cache_set_add(cache,set,(uintptr_t) address, tag);
    }
  }

  cache_access_count++;

  return cache_line_retrieve_data(line, offset); // Added to remove warning; remove once function is implemented.
}

/*
 * Read a single integer from the cache.
 */
void cache_write(cache_t *cache, long *address, long value) {
  
  /* OPTIONAL FUNCTION, YOU ARE NOT REQUIRED TO IMPLEMENT IT */
}


/*
 * Return the number of cache misses since the cache was created.
 */
int cache_miss_count(cache_t *cache) {
  
  return cache->miss_count;
}

/*
 * Return the number of cache accesses since the cache was created.
 */
int cache_access_count(cache_t *cache) {
  
  return cache->access_count;
}
