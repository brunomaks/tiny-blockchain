#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <cstdint>

uint64_t getCurrentTimestamp();
bool isValidHex(const std::string& hex);
std::string hexToDec(const std::string& hex);

#endif
