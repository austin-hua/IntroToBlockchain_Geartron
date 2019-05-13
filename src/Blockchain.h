#ifndef __blockchain__
#define __blockchain__

#include <vector>
#include <cstdint>
#include "Block.h"

using namespace std;

class Blockchain {
public:
	vector<Block> longestChain; 
	/*
	for the purposes of this project, 
	we are making the blockchain public
	*/
    Blockchain();
    void addBlock(Block newBlock);

private:
    Block getLastBlock() const;
};

#endif
