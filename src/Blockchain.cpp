#include "Blockchain.hpp"

Blockchain::Blockchain() {
  chain.push_back(createGenesisBlock());
}

Block Blockchain::createGenesisBlock() {
  return Block(0, "Genesis", "0");
}

void Blockchain::addBlock(const std::string& data) {
  const Block& latestBlock = getLatestBlock();
  Block newBlock(latestBlock.getIndex() + 1, data, latestBlock.getHash());
  chain.push_back(newBlock);
}

const Block& Blockchain::getLatestBlock() const {
  return chain.back();
}

const std::vector<Block>& Blockchain::getChain() const {
  return chain;
}

bool Blockchain::isValid() const {
  for(size_t i = 1; i < chain.size(); i++) {
    const Block& current = chain[i];
    const Block& previous = chain[i - 1];

    if(current.getHash() != current.calculateHash()) {
      return false;
    }

    if(current.getPreviousHash() != previous.getHash()) {
      return false;
    }
  }

  return true;
}
