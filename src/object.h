
//
// object.h
//
// Copyright (c) 2012 TJ Holowaychuk <tj@vision-media.ca>
//

#ifndef JSON_OBJECT_HASH
#define JSON_OBJECT_HASH

#include "khash.h"

// value hash

KHASH_MAP_INIT_STR(value, void *);

/*
 * Luna hash.
 */

typedef khash_t(value) json_object_t;

/*
 * Allocate a new hash.
 */

#define json_object_new() kh_init(value)

/*
 * Destroy the hash.
 */

#define json_object_destroy(self) kh_destroy(value, self)

/*
 * Hash size.
 */

#define json_object_size kh_size

/*
 * Iterate hash keys and values, populating
 * `key` and `val`.
 */

#define json_object_each(self, block) { \
   char *key; \
   void *val; \
    for (khiter_t k = kh_begin(self); k < kh_end(self); ++k) { \
      if (!kh_exist(self, k)) continue; \
      key = kh_key(self, k); \
      val = kh_value(self, k); \
      block; \
    } \
  }

/*
 * Iterate hash keys, populating `key`.
 */

#define json_object_each_key(self, block) { \
    char *key; \
    for (khiter_t k = kh_begin(self); k < kh_end(self); ++k) { \
      if (!kh_exist(self, k)) continue; \
      key = kh_key(self, k); \
      block; \
    } \
  }

/*
 * Iterate hash values, populating `val`.
 */

#define json_object_each_val(self, block) { \
    void *val; \
    for (khiter_t k = kh_begin(self); k < kh_end(self); ++k) { \
      if (!kh_exist(self, k)) continue; \
      val = kh_value(self, k); \
      block; \
    } \
  }

// protos

void
json_object_set(khash_t(value) *self, char *key, void *val);

void *
json_object_get(khash_t(value) *self, char *key);

int
json_object_has(khash_t(value) *self, char *key);

void
json_object_remove(khash_t(value) *self, char *key);

#endif /* JSON_OBJECT_HASH */