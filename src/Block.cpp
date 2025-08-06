#include "Block.hpp"
#include "Utils.hpp"
#include "picosha2.h"
#include "BigInt.hpp"
#include <sstream>

typedef BigInt uint256_t;

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

void Block::mine(uint32_t difficulty_bits) {
  uint256_t max_target("0x0000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF");
  std::cout << max_target;

  std::string target(difficulty_bits, '0');

  while(hash.substr(0, difficulty_bits) != target) {
    // could potentially overflow and run infinetely
    nonce++;
    hash = calculateHash();
  }
}

