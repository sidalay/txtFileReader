#include <iostream>
#include <fstream>

int main() {
    std::ifstream input {"Expenses.txt", std::ifstream::in};

    char letter = input.get();

    while (input.good()) {
        std::cout << letter;
        letter = input.get();
    }

    input.close();

    return 0;
}

/* 
std::ifstream file{"input.txt"};
std::vector<int> data {std::istream_iterator<int>{file}, {}};
*/