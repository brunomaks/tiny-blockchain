#include "include/Blockchain.hpp"
#include <iostream>

int main(void) {
  Blockchain chain;

  // test mining, difficulty 4 is too high for the current implementation (it will take a long time to mine)
  for (int i = 0; i < 20; ++i) {
    chain.addBlock("Block " + std::to_string(i + 1) + " data");
  }
  std::cout << "Blockchain created with " << chain.getChain().size() << " blocks." << std::endl;
  std::cout << "Latest Block Index: " << chain.getLatestBlock().getIndex() << std::endl;
  std::cout << "Latest Block Hash: " << chain.getLatestBlock().getHash() << std::endl;
  std::cout << "Blockchain Difficulty: " << chain.getChain().back().getNonce() << std::endl;
  std::cout << "Blockchain Size: " << chain.getChain().size() << std::endl;
  std::cout << "Blockchain Difficulty: " << chain.getDifficulty() << std::endl;

  std::cout << "Is Blockchain valid? " << (chain.isValid() ? "Yes" : "No") << std::endl;

  std::cout << std::endl;
  return 0;
}
