#include "block.h"
#include <openssl/sha.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void Block_init(Block* block, int index, const char* data, const char* previous_hash) {
    // Set primitive values
    block->index = index;
    block->nonce = 0;
    
    // Copy timestamp
    time_t now = time(NULL);
    strftime(block->timestamp, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));
    
    // Copy data (heap allocation)
    block->data = malloc(strlen(data) + 1);
    strcpy(block->data, data);
    
    // Copy previous hash
    strncpy(block->previous_hash, previous_hash, 64);
    block->previous_hash[64] = '\0';
    
    // Calculate initial hash
    Block_calculate_hash(block);
}

void Block_calculate_hash(Block* block) {
    char input[1024];
    // Format all block data into a single string
    int len = snprintf(input, sizeof(input), "%d%s%s%s%d", 
                      block->index, 
                      block->timestamp,
                      block->data,
                      block->previous_hash,
                      block->nonce);
    
    // Compute SHA256
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)input, len, hash);
    
    // Convert to hex string
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(block->hash + (i*2), "%02x", hash[i]);
    }
    block->hash[64] = '\0';
}

void Block_destroy(Block* block) {
    free(block->data);  // Free heap-allocated data
}