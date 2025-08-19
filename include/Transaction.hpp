#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include <string>
#include <cstdint>

class Transaction {
  public:
    Transaction(const std::string& sender, const std::string& recipient, const std::string& value);
    
    std::string calculateHash() const;
    const std::string& getHash() const noexcept { return hash; }
    const std::string& getSender() const noexcept { return sender; }
    const std::string& getRecipient() const noexcept { return recipient; }
    const std::string& getValue() const noexcept { return value; } 

  private:
    const std::string sender;
    const std::string recipient;
    const std::string value;
    const uint64_t timestamp;
    const std::string hash;
};

#endif