#include "Block.hpp"
#include <iostream>

int main(void) {
  Block block(0, "Genesis", "0");

  std::string hash = block.calculateHash();
  std::cout << hash << std::endl;
  return 0;
}
