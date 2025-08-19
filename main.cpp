#include "Blockchain.hpp"
#include "Transaction.hpp"
#include <chrono>
#include <iostream>


int main(void) {
    Blockchain chain(10); // initial difficulty

    std::vector<std::vector<Transaction>> transactions = {
        {Transaction("Alice", "Bob", "5")},
        {Transaction("Bob", "Charlie", "3")},
        {Transaction("Charlie", "Alice", "1")},
        {Transaction("Dave", "Eve", "4")},
        {Transaction("Eve", "Frank", "2")},
        {Transaction("Frank", "George", "7")},
        {Transaction("George", "Helen", "6")},
        {Transaction("Helen", "Ivan", "1")},
        {Transaction("Ivan", "Judy", "3")},
        {Transaction("Judy", "Kevin", "8")},
        {Transaction("Kevin", "Laura", "2")},
        {Transaction("Laura", "Mallory", "5")},
        {Transaction("Mallory", "Neil", "4")},
        {Transaction("Neil", "Olivia", "9")},
        {Transaction("Olivia", "Paul", "1")}
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
        std::cout << "Data: " << block.getTransactions().size() << " transactions" << std::endl;
        std::cout << "Hash: " << block.getHash() << std::endl;
        std::cout << "Previous hash: " << block.getPreviousHash() << std::endl;
        std::cout << "Nonce: " << block.getNonce() << std::endl;
        std::cout << "------------------------------------------" << std::endl;
    }

    std::cout << "Is Blockchain valid? " << (chain.isValid() ? "Yes" : "No") << std::endl;

    return 0;
}
