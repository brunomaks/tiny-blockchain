#include "Utils.hpp"
#include <chrono>
#include <stdexcept>
#include <algorithm>
#include <vector>

uint64_t getCurrentTimestamp() {
  using namespace std::chrono;
  const auto now = high_resolution_clock::now();
  // might need milliseconds
  auto duration = duration_cast<seconds>(now.time_since_epoch());
  return duration.count();
}

bool isValidHex(const std::string &hex_str) {
  if (hex_str.empty()) {
    return false;
  }

  int start_pos = 0;

  if (hex_str.size() > 2 && hex_str[0] == '0' &&
      (hex_str[1] == 'x' || hex_str[1] == 'X')) {
    start_pos = 2;
  }

  for (int i = start_pos; i < hex_str.size(); ++i) {
    char digit = hex_str[i];
    bool is_valid = (digit >= '0' && digit <= '9') ||
                    (digit >= 'a' && digit <= 'f') ||
                    (digit >= 'A' && digit <= 'F');

    if (!is_valid) {
      return false;
    }
  }

  return true;
}

int hexCharToInt(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  if (c >= 'a' && c <= 'f') {
    return 10 + (c - 'a');
  }
  if (c >= 'A' && c <= 'F') {
    return 10 + (c - 'A');
  }
  throw std::invalid_argument("Invalid hexadecimal character");
}

std::string add(const std::string &num1, const std::string &num2) {
  std::string res = "";
  int carry = 0;

  int i = num1.size() - 1;
  int j = num2.size() - 1;

  while (i >= 0 || j >= 0 || carry) {
    int n1 = i >= 0 ? num1[i--] - '0' : 0;
    int n2 = j >= 0 ? num2[j--] - '0' : 0;

    int sum = n1 + n2 + carry;
    res.push_back((sum % 10) + '0');
    carry = sum / 10;
  }

  reverse(res.begin(), res.end());
  return res;
}

std::string multiply(const std::string &num1, const std::string &num2) {
  if (num1 == "0" || num2 == "0")
    return "0";

  int n = num1.size();
  int m = num2.size();
  std::vector<int> result(n + m, 0);

  for (int i = n - 1; i >= 0; --i) {
    int d1 = num1[i] - '0';
    for (int j = m - 1; j >= 0; --j) {
      int d2 = num2[j] - '0';
      int mul = d1 * d2;

      int sum = mul + result[i + j + 1];

      result[i + j + 1] = sum % 10;
      result[i + j] += sum / 10; // carry
    }
  }

  std::string product;
  bool leadingZero = true;
  for (int digit : result) {
    if (digit == 0 && leadingZero)
      continue;
    leadingZero = false;
    product.push_back(digit + '0');
  }

  return product.empty() ? "0" : product;
}

// assuming given hex is valid
std::string hexToDec(const std::string &hex) {

  int hexStart = 0;
  if(hex.size() > 2 && hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X')) {
    hexStart = 2;
  }

  std::string result = "";
  std::string factor = "1";

  for (int i = hex.size() - 1; i >= hexStart; --i) {
    int curr = hexCharToInt(hex[i]);
    if (curr == -1) {
      return "-1";
    }

    std::string product = multiply(std::to_string(curr), factor);
    result = add(product, result);
    factor = multiply(factor, "16");
  }

  return result;
}
