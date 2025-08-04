#include "Block.hpp"
#include "Utils.hpp"
#include "picosha2.h"
#include <sstream>

Block::Block(uint64_t id, const std::string& data, const std::string& prevHash)
  : index(id), data(data), previousHash(prevHash), nonce(0)
{
  timestamp = getCurrentTimestamp();
  hash = calculateHash();
}

std::string Block::calculateHash() const {
  std::stringstream ss;
  ss << index << timestamp << data << previousHash << nonce;
  std::string input = ss.str();
  std::string output;
  picosha2::hash256_hex_string(input, output);
  return output;
}

void Block::mine(int difficulty) {
  std::string target(difficulty, '0');

  while(hash.substr(0, difficulty) != target) {
    // could potentially overflow and run infinetely
    nonce++;
    hash = calculateHash();
  }
}

