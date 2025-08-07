#include "Blockchain.hpp"
#include <chrono>
#include <iostream>


int main(void) {
    Blockchain chain(10); // initial difficulty

    std::vector<std::string> transactions = {
        "Alice sends Bob 5 coins",
        "Bob sends Charlie 3 coins",
        "Charlie sends Alice 1 coin",
        "Dave sends Eve 4 coins",
        "Eve sends Frank 2 coins",
        "Frank sends George 7 coins",
        "George sends Helen 6 coins",
        "Helen sends Ivan 1 coin",
        "Ivan sends Judy 3 coins",
        "Judy sends Kevin 8 coins",
        "Kevin sends Laura 2 coins",
        "Laura sends Mallory 5 coins",
        "Mallory sends Neil 4 coins",
        "Neil sends Olivia 9 coins",
        "Olivia sends Paul 1 coin"
    };

    for (const auto& tx : transactions) {
        auto start = std::chrono::high_resolution_clock::now();
        chain.addBlock(tx);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;

        std::cout << "Mined block in " << duration.count() << " seconds." << std::endl;
    }

    std::cout << "\n--- Blockchain Content ---\n";
    for (const Block& block : chain.getChain()) {
        std::cout << "Block #" << block.getIndex() << std::endl;
        std::cout << "Timestamp: " << block.getTimestamp() << std::endl;
        std::cout << "Data: " << block.getData() << std::endl;
        std::cout << "Hash: " << block.getHash() << std::endl;
        std::cout << "Previous hash: " << block.getPreviousHash() << std::endl;
        std::cout << "Nonce: " << block.getNonce() << std::endl;
        std::cout << "------------------------------------------" << std::endl;
    }

    std::cout << "Is Blockchain valid? " << (chain.isValid() ? "Yes" : "No") << std::endl;

    return 0;
}
