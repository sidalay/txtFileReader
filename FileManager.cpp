#include "FileManager.hpp"

FileReader::FileReader(std::string FileName) 
    : Input{FileName} {}

FileReader::~FileReader() {
    Input.close();
}