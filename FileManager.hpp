#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class FileReader {
private:
    std::ifstream Input{};
    std::string Fill{};
    std::string Buffer{};
    std::vector<std::string> Container{};
public:
    FileReader(std::string FileName);
    FileReader(const FileReader& ref) = delete;
    FileReader(FileReader&& ref) = default;
    FileReader& operator=(const FileReader& ref) = delete;
    FileReader& operator=(FileReader&& ref) = default;
    ~FileReader();

    // print entire file
    // grab line by line
    // grab if isdigit
    // grab if isalpha
    // grab with specified filter
    // grab with digits and alphas filtered separately
    // 
};

#endif