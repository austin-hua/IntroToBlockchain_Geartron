#include "Blockchain.h"

Blockchain::Blockchain() {
    longestChain.push_back(Block("Genesis block"));
}

void Blockchain::addBlock(Block newBlock) {
    newBlock.prevHash = getLastBlock().hash;
    newBlock.mineBlock();
    longestChain.push_back(newBlock);
}

Block Blockchain::getLastBlock() const {
    return longestChain.back();
}