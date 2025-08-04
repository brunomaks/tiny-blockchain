#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <string>
#include <cstdint>

class Block {
public:
  Block(uint64_t id, const std::string& data, const std::string& prevHash);

  std::string calculateHash() const;
  uint64_t getIndex() const noexcept { return index; };
  uint64_t getTimestamp() const noexcept { return timestamp; };
  const std::string& getData() const noexcept { return data; };
  const std::string& getHash() const noexcept { return hash; };
  const std::string& getPreviousHash() const noexcept { return previousHash; }
  int getDifficulty() const noexcept { return difficulty; };
  uint64_t getNonce() const noexcept { return nonce; };

private:
  uint64_t index;
  uint64_t timestamp;
  std::string data;
  std::string previousHash;
  std::string hash;
  int difficulty;
  uint64_t nonce; // "number used once"
};

#endif

