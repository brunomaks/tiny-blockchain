#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <string>
#include <cstdint>

class Block {
public:
  Block(int id, const std::string& data, const std::string& prevHash);

  std::string calculateHash() const;
  uint64_t getIndex() const noexcept;
  uint64_t getTimestamp() const noexcept;
  const std::string& getData() const noexcept;
  const std::string& getHash() const noexcept;
  const std::string& getPreviousHash() const noexcept;

private:
  uint64_t index;
  uint64_t timestamp;
  std::string data;
  std::string previousHash;
  std::string hash;
  uint64_t nonce;
};

#endif

