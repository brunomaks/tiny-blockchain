#include "blockchain.h"
#include <stdlib.h>
#include <string.h>

void Blockchain_init(Blockchain* bc) {
    bc->size = 0;
    bc->capacity = INITIAL_CAPACITY;
    bc->difficulty = 4;
    bc->blocks = malloc(sizeof(Block*) * bc->capacity);
    
    // Create genesis block
    Blockchain_add_block(bc, "Genesis Block");
}

void Blockchain_add_block(Blockchain* bc, const char* data) {
    // Resize if needed
    if(bc->size >= bc->capacity) {
        bc->capacity *= 2;
        bc->blocks = realloc(bc->blocks, sizeof(Block*) * bc->capacity);
    }
    
    // Create new block
    Block* new_block = malloc(sizeof(Block));
    const char* prev_hash = (bc->size == 0) ? "0" : Blockchain_get_latest_block(bc)->hash;
    Block_init(new_block, bc->size, data, prev_hash);
    
    // Mine block (Proof-of-Work)
    char target[bc->difficulty + 1];
    memset(target, '0', bc->difficulty);
    target[bc->difficulty] = '\0';
    
    while(strncmp(new_block->hash, target, bc->difficulty) != 0) {
        new_block->nonce++;
        Block_calculate_hash(new_block);
    }
    
    // Add to chain
    bc->blocks[bc->size++] = new_block;
}

Block* Blockchain_get_latest_block(const Blockchain* bc) {
    if(bc->size == 0) return NULL;
    return bc->blocks[bc->size - 1];
}

int Blockchain_is_valid(const Blockchain* bc) {
    for(size_t i = 1; i < bc->size; i++) {
        Block* current = bc->blocks[i];
        Block* prev = bc->blocks[i-1];
        
        // Validate current hash
        char test_hash[65];
        strcpy(test_hash, current->hash);  // Save original
        Block_calculate_hash(current);     // Recompute
        if(strcmp(test_hash, current->hash) != 0) 
            return 0;
        
        // Validate chain link
        if(strcmp(current->previous_hash, prev->hash) != 0)
            return 0;
    }
    return 1;
}

void Blockchain_destroy(Blockchain* bc) {
    for(size_t i = 0; i < bc->size; i++) {
        Block_destroy(bc->blocks[i]);
        free(bc->blocks[i]);
    }
    free(bc->blocks);
}