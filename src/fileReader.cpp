#include <fstream>
#include <string>
#include <iostream>

using namespace std;

string targetConfig() {
    std::ifstream fs;
    fs.open("config.json");
    
    
    int length = 326;
    char * buffer = new char [length];
    char *buffer2 = new char [100];
    
    // read data as a block:
    fs.read(buffer, length);
    fs.read(buffer2, 67);
    
    // ...buffer contains the entire file...
    
    string s = string(buffer2);
    delete[] buffer;
    delete[] buffer2;
    
    fs.close();
    
    return buffer2;
    
}


int main(void) {
    string target = targetConfig();
    cout << target;
    
}



