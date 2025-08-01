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

// Calculates SHA-256 hash of the block's contents
// Ensures that even a small change in the block's content changes the hash, supporting data integrity
// Used to validate the block during mining and linking
std::string Block::calculateHash() const {
  std::stringstream ss;
  ss << index << timestamp << data << previousHash << nonce;
  std::string input = ss.str();
  std::string output;
  picosha2::hash256_hex_string(input, output);
  return output;
}

uint64_t Block::getIndex() const noexcept {
  return index;
}

uint64_t Block::getTimestamp() const noexcept {
  return timestamp;
}

const std::string& Block::getData() const noexcept {
  return data;
}

const std::string& Block::getHash() const noexcept {
  return hash;
}

const std::string& Block::getPreviousHash() const noexcept {
  return previousHash;
}

uint64_t Block::getNonce() const noexcept {
  return nonce;
}

void Block::setNonce(uint64_t newNonce) {
  nonce = newNonce;
  hash = calculateHash(); // Recalculate hash when nonce changes
}

