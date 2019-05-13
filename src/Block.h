#ifndef __block__
#define __block__

#include <iostream>
#include <sstream>
#include <cstdint>

using namespace std;

class Block {
public:
    string hash;
    string prevHash;

    Block(const string &dataIn);
    void mineBlock();

private:
    uint32_t version;
    uint32_t nonce;
    uint32_t targetInt;
    string data;
    string merkle_root;
    string target;
    string calculateHash() const;
    uint32_t difficultyInt() const;
};

#endif
