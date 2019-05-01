#include <stdio.h>

#include "geartron.h"

const int VERSION = 0x1;

typedef struct BlockHeader {
    unsigned version;
    char prevBlock[32]; // hash of previous block
    char target[32]; // target difficulty
    unsigned nonce[32];
} BlockHeader;


int main(void) {
    
    
    
    return 0;
}
