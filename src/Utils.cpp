#include "Utils.hpp"
#include <chrono>

uint64_t getCurrentTimestamp() {
  using namespace std::chrono;
  const auto now = high_resolution_clock::now();
                // might need milliseconds
  auto duration = duration_cast<seconds>(now.time_since_epoch());
  return duration.count();
}
