#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include <string>
#include <cstdint>

class Transaction {
  public:
    Transaction(const std::string& sender, const std::string& recipient, const std::string& value);
    std::string calculateHash() const;
    

  private:
    const std::string hash;
    const std::string sender;
    const std::string recipient;
    const std::string value;
    const uint64_t timestamp;
};

#endif