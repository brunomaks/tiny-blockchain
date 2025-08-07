#include <iostream>
#include <sstream>
#include "Block.hpp"
#include "picosha2.h"
#include "BigInt.hpp"

typedef BigInt uint256_t;

static const uint256_t MAX_TARGET("0x00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF");

Block::Block(const uint64_t id, const std::string& data, const uint64_t timestamp, const std::string& prevHash)
  : index(id), data(data), timestamp(timestamp), previousHash(prevHash), nonce(0)
{
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
  const uint256_t target = MAX_TARGET / (2 * difficulty_bits);

  while(true) {
    std::string hex_hash = calculateHash();

    uint256_t hash_as_int(hex_hash);

    if(hash_as_int <= target) {
      hash = hex_hash;
      break;
    }

    // Potential nonce overflow, very low chance
    nonce++;
  }
}

bool Block::meetsDifficulty(uint32_t difficulty_bits) const {
  const uint256_t target = MAX_TARGET / (2 * difficulty_bits);
  uint256_t hash_as_int(calculateHash());
  return hash_as_int <= target;
}
