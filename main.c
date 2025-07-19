#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "blockchain.h"

int main() {
    Blockchain bc;
    Blockchain_init(&bc);
    
    printf("Mining block 1...\n");
    Blockchain_add_block(&bc, "Alice pays Bob 5 BTC");
    
    printf("Mining block 2...\n");
    Blockchain_add_block(&bc, "Bob pays Charlie 3 BTC");
    
    printf("Blockchain valid? %s\n", 
           Blockchain_is_valid(&bc) ? "YES" : "NO");
    
    // Tamper test
    Block* tampered = bc.blocks[1];
    free(tampered->data);
    tampered->data = strdup("Bob pays Charlie 500 BTC");
    Block_calculate_hash(tampered);
    
    printf("After tampering: %s\n",
           Blockchain_is_valid(&bc) ? "VALID" : "INVALID");
    
    Blockchain_destroy(&bc);
    return 0;
}