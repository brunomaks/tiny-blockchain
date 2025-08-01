#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <string>
#include <cstdint>

class Block {
public:
  Block(uint64_t id, const std::string& data, const std::string& prevHash);

  std::string calculateHash() const;
  uint64_t getIndex() const noexcept;
  uint64_t getTimestamp() const noexcept;
  const std::string& getData() const noexcept;
  const std::string& getHash() const noexcept;
  const std::string& getPreviousHash() const noexcept;
  uint64_t getNonce() const noexcept;
  void setNonce(uint64_t newNonce);

private:
  uint64_t index;        // Identifies the block's position in the chain
  uint64_t timestamp;    // Records the time of block creation
  std::string data;      // Holds the actual transaction or information stored in the block
  std::string previousHash; // Links the block to the one before it, ensuring chain integrity
  std::string hash;      // A unique identifier generated based on the block's contents; helps detect tampering
  uint64_t nonce;        // A number used in mining (proof-of-work) to find a valid hash
};

#endif

