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
  uint256_t max_target("0x00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF");

  // each bit increase doubles the difficulty
  uint256_t target = max_target / (16 * difficulty_bits);

  std::cout << "Mining with target: " << target << std::endl;

  while(true) {
    std::string hex_hash = calculateHash();

    uint256_t hash_as_int(hex_hash);

    if(hash_as_int <= target) {
      break;
    }

    nonce++;

    if(nonce == 0) {
      std::cout << "Nonce overflowed, updating the timestamp..." << std::endl;
      timestamp = getCurrentTimestamp();
    }
  }
}

