#include <iostream>
#include <fstream>
#include <string>

int main(void) {
    std::ofstream myFile;
    myFile.open ("data.cvs");
    myFile << "\n";
    myFile << "a,b,c\n";
    myFile << std::to_string(2) + ",";
    myFile.close();

    return 0;
}