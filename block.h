#ifndef BLOCK_H
#define BLOCK_H

#include <time.h>

typedef struct {
    int index;
    char timestamp[20];  // Fixed-width string
    char* data;          // Heap-allocated
    char previous_hash[65]; // SHA256 is 64 chars + null
    char hash[65];
    int nonce;
} Block;

void Block_init(Block* block, int index, const char* data, const char* previous_hash);
void Block_calculate_hash(Block* block);
void Block_destroy(Block* block);

#endif