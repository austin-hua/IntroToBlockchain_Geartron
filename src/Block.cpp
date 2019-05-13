#include "Block.h"
#include "sha256.h"

Block::Block(const string &dataIn) {
    data = dataIn;
    nonce = 0;
    merkle_root = "00000000000000000000000000000000"; /*change to match config.json*/
    target = "0001000000000000000000000000000000000000000000000000000000000000";
    targetInt = difficultyInt();
    hash = calculateHash();
}

void Block::mineBlock() {
    char tmp[targetInt];
    for(int i = 0; i < targetInt; i++) {
        tmp[i] = '0';
    }
    tmp[targetInt] = '\0';
    string str(tmp);

    do {
        nonce++;
        hash = calculateHash();
    } while(hash.substr(0, targetInt) != str);
}

inline string Block::calculateHash() const {
    stringstream ss;
    string ver = "00000001";
    ss << ver << version << prevHash << merkle_root << target << nonce;
    string test = ss.str();

    return sha256(test);
}

inline uint32_t Block::difficultyInt() const {
    uint32_t difficulty = 0;
    for(int i = 0; i < target.length(); i++) {
        if(target.substr(i, 1) != "0") break;
        difficulty++;
    }
    return difficulty;
}