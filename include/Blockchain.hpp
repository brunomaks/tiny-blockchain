#ifndef BLOCKCHAIN_HPP
#define BLOCKCHAIN_HPP

#include "Block.hpp"
#include <vector>

class Blockchain {
public:
  Blockchain(uint32_t difficulty);

  void addBlock(const std::string& data);
  bool isValid() const;
  void adjustDifficulty();

  const std::vector<Block>& getChain() const noexcept { return chain; };
  int getDifficulty() const noexcept { return difficulty; };

private:
  std::vector<Block> chain;
  int difficulty;
};

#endif
