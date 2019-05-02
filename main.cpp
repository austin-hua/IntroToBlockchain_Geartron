#include "Blockchain.h"

using namespace std;

int main() {
    Blockchain quantumChain = Blockchain();

    while(true) { // continue to add blocks
	    quantumChain.addBlock(Block("Block datum"));
	    cout << quantumChain.longestChain[quantumChain.longestChain.size()-1].hash << endl;
	}
    return 0;
}
