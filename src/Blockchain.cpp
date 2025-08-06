#include "Blockchain.hpp"
#include "Constants.hpp"
#include <iostream>

Blockchain::Blockchain(uint32_t difficulty) 
  : difficulty(difficulty) 
{
  chain.push_back(Block(0, "Genesis", "0"));
}

void Blockchain::addBlock(const std::string& data) {
  const Block& latestBlock = chain.back();

  if((latestBlock.getIndex() + 1) % ADJUST_DIFFICULTY_INTERVAL == 0) {
    adjustDifficulty();
  }
  Block newBlock(latestBlock.getIndex() + 1, data, latestBlock.getHash());
  newBlock.mine(difficulty);
  chain.push_back(newBlock);
}

void Blockchain::adjustDifficulty() {
  const int targetTime = ADJUST_DIFFICULTY_INTERVAL * TARGET_TIME_PER_BLOCK;

  uint64_t latestTimestamp = chain.back().getTimestamp();
  uint64_t prevTimestamp = chain[chain.size() - ADJUST_DIFFICULTY_INTERVAL].getTimestamp();

  uint64_t actualTime = latestTimestamp - prevTimestamp;

  std::cout << "Actual mining time for last " << ADJUST_DIFFICULTY_INTERVAL << " blocks: " << actualTime << " seconds\n";

  if (actualTime > targetTime) {
      if (difficulty > 1) {
          difficulty--;
          std::cout << "Difficulty decreased to " << difficulty << std::endl;
      }
  } else if (actualTime < targetTime) {
      if (difficulty < MAX_DIFFICULTY) {
          difficulty++;
          std::cout << "Difficulty increased to " << difficulty << std::endl;
      }
  } else {
      std::cout << "Difficulty stays the same: " << difficulty << std::endl;
  }
}

bool Blockchain::isValid() const {
  for(size_t i = 1; i < chain.size(); i++) {
    const Block& curr = chain[i];
    const Block& prev = chain[i - 1];

    if(curr.getHash() != curr.calculateHash()) {
      return false;
    }

    std::string target(difficulty, '0');
    if(curr.getHash().substr(0, difficulty) != target) {
      return false;
    }

    if(curr.getPreviousHash() != prev.getHash()) {
      return false;
    }
  }

  return true;
}
