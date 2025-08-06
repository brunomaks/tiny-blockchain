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
  constexpr uint32_t getDifficulty() const { return difficulty; }

private:
  std::vector<Block> chain;
  uint32_t difficulty = 2; // by default, set difficulty for mining blocks
  static constexpr size_t DIFFICULTY_ADJUSTMENT_INTERVAL = 10; // every 10 blocks
  static constexpr uint64_t TARGET_BLOCK_TIME = 60; // each 60 seconds
  void adjustDifficulty();
};

#endif
