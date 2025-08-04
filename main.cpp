#include "Blockchain.hpp"
#include <iostream>

int main(void) {
  Blockchain chain;

  chain.addBlock("Alice sends Bob 5 coins");
  chain.addBlock("Bob sends Charlie 3 coins");
  chain.addBlock("Charlie sends Alice 1 coin");

  for(const Block& block : chain.getChain()) {
    std::cout << "Block #" << block.getIndex() << std::endl;
    std::cout << "Timestamp: " << block.getTimestamp() << std::endl;
    std::cout << "Data: " << block.getData() << std::endl;
    std::cout << "Hash: " << block.getHash() << std::endl;
    std::cout << "Previous hash: " << block.getPreviousHash() << std::endl;
    std::cout << "------------------------------------------" << std::endl;
  }

  std::cout << "Is Blockchain valid? " << (chain.isValid() ? "Yes" : "No") << std::endl;

  std::cout << std::endl;
  return 0;
}
