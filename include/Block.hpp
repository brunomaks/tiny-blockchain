#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <string>
#include <cstdint>
#include <vector>
#include "Transaction.hpp"

class Block {
public:
  Block(const uint64_t id, const std::vector<Transaction>& transactions, const uint64_t timestamp, const std::string& prevHash);

  void mine(uint32_t difficulty);

  std::string calculateHash() const;
  bool meetsDifficulty(const uint32_t target) const;

  uint64_t getIndex() const noexcept { return index; };
  uint64_t getTimestamp() const noexcept { return timestamp; };
  const std::vector<Transaction>& getTransactions() const noexcept { return transactions; };
  const std::string& getHash() const noexcept { return hash; };
  const std::string& getPreviousHash() const noexcept { return previousHash; }
  uint64_t getNonce() const noexcept { return nonce; };

private:
  std::string hash;
  uint64_t nonce; // "number used once"
  const uint64_t index;
  const uint64_t timestamp;
  const std::vector<Transaction> transactions;
  const std::string previousHash;
};

#endif

