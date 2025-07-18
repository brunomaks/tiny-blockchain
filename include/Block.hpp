#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <string>
#include <cstdint>

class Block {
public:
  Block(int id, const std::string& data, const std::string& prevHash);

  std::string calculateHash() const;

private:
  uint64_t index;
  uint64_t timestamp;
  std::string data;
  std::string previousHash;
  std::string hash;
  uint64_t nonce;
};

#endif

