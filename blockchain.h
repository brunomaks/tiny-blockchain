#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "block.h"

#define INITIAL_CAPACITY 10

typedef struct {
    Block** blocks;       // Array of Block pointers
    size_t size;          // Current blocks count
    size_t capacity;      // Current array capacity
    int difficulty;       // PoW difficulty
} Blockchain;

void Blockchain_init(Blockchain* bc);
void Blockchain_add_block(Blockchain* bc, const char* data);
Block* Blockchain_get_latest_block(const Blockchain* bc);
int Blockchain_is_valid(const Blockchain* bc);
void Blockchain_destroy(Blockchain* bc);

#endif