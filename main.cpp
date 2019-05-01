#include <iostream>
#include <cstdlib>

#include "geartron.h"

const int VERSION = 0x1;

char *hash(

typedef struct BlockHeader {
    unsigned version;
    char prevBlock[32]; // hash of previous block
    char target[32]; // target difficulty
    unsigned nonce[32];
    int merkel = 0;
} BlockHeader;


int main(void) {
    
    
    
    return EXIT_SUCCESS;
}
