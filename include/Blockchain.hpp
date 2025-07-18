#ifndef BLOCKCHAIN_HPP
#define BLOCKCHAIN_HPP

#include "Block.hpp"
#include <vector>

class Blockchain {
public:
  Blockchain();

  void addBlock(const std::string& data);
  const Block& getLatestBlock() const;
  bool isValid() const;
  const std::vector<Block>& getChain() const;

private:
  std::vector<Block> chain;
  Block createGenesisBlock();
};

#endif
