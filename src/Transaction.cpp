#include "Transaction.hpp"
#include "picosha2.h"
#include "Utils.hpp"
#include <string>

Transaction::Transaction(const std::string& sender, const std::string& recipient, const std::string& value)
  : sender(sender), recipient(recipient), value(value), timestamp(getCurrentTimestamp()), hash(calculateHash()) {}


std::string Transaction::calculateHash() const {
  std::stringstream ss;
  ss << sender << recipient << value << timestamp;
  std::string input = ss.str();
  std::string output;
  picosha2::hash256_hex_string(input, output);
  return output;
}