cmake_minimum_required(VERSION 3.12)
project(tiny-blockchain)

set(CMAKE_C_STANDARD 11)

# Find OpenSSL
find_package(OpenSSL REQUIRED)

# List ALL source files
set(SOURCES
    main.c
    block.c
    blockchain.c
)

# Create executable from ALL sources
add_executable(tiny_blockchain ${SOURCES})

# Link OpenSSL
target_include_directories(tiny_blockchain PRIVATE ${OPENSSL_INCLUDE_DIR})
target_link_libraries(tiny_blockchain PRIVATE OpenSSL::Crypto)

# Enable debugging symbols
set(CMAKE_BUILD_TYPE Debug)