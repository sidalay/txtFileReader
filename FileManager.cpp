#include "FileManager.hpp"

FileReader::FileReader(std::string FileName) 
    : Input{FileName}, 
      FilePath{FileName}, 
      AllContainer{GrabLines(std::ifstream{FileName})} 
      {
          if (Input.good()) {
              std::cout << "-----------------------------------------------\n"
                        << "File has sucessfully been processed and loaded.\n"
                        << "-----------------------------------------------\n\n";
          }
          else {
              std::cout << "-----------------!-------------!-----------------\n"
                        << "File could not be loaded. Double check file path,\n" 
                        << "file name, or if file is empty.\n"
                        << "-----------------!-------------!----------------\n\n";
          }
      }

FileReader::~FileReader() {
    Input.close();
    if (Input.fail()) {
        std::cout << "--------!--------!--------\n"
                  << "Error with file closing.\n"
                  << "Something went wrong.\n"
                  << "--------!--------!--------\n" << std::endl;
    }
    else {
        std::cout << "-------------------------\n"
                  << "File closed successfully.\n"
                  << "-------------------------\n" << std::endl;
    }
}

std::vector<std::string> FileReader::GrabLines(std::ifstream File) {
    std::vector<std::string> Buffer {std::istream_iterator<std::string>{File}, {}};
    return Buffer;
}

void FileReader::Print(Storage ContainerType) {
    switch (ContainerType) {
        case Storage::Input: {
            std::ifstream InputCopy{FilePath}; // make copy of Input because .get() moves
            while (InputCopy.good()) {
                std::cout << Character;
                Character = InputCopy.get();
            }
            std::cout << "\n\n";
            InputCopy.close();
            break;
        }
        case Storage::All: {
            for (auto i:AllContainer) {
                std::cout << i << '\n';
            }
            std::cout << '\n';
            break;
        }
        case Storage::Digits: {
            for (auto i:DigitsContainer) {
                std::cout << i << '\n';
            }
            std::cout << '\n';
            break;
        }
        case Storage::Words: {
            for (auto i:WordsContainer) {
                std::cout << i << '\n';
            }
            std::cout << '\n';
            break;
        }
        case Storage::Alpha: {
            for (auto i:AlphaContainer) {
                std::cout << i << '\n';
            }
            std::cout << '\n';
            break;
        }
        default: {
            std::cout << "--------------------------\n"
                      << "\nInvalid option.\n"
                      << "--------------------------\n\n";
            break;
        }
    }
}

void FileReader::Clear(Storage ContainerType) {
    switch (ContainerType) {
        case Storage::All: {
            std::cout << "------------------------------------------\n" 
                      << "AlphaNum Container can not be cleared.\n"
                      << "------------------------------------------\n\n"; 
            break;
        }
        case Storage::Digits: {
            if (DigitsContainer.empty()) {
                std::cout << "------------------------------------------\n"
                          << "DigitsContainer is already empty.\n"
                          << "------------------------------------------\n\n";
                break;
            }

            DigitsContainer.clear();
            std::cout << "------------------------------------------\n"
                      << "DigitsContainer has been cleared.\n"
                      << "------------------------------------------\n\n";
            break;
        }
        case Storage::Words: {
            if (WordsContainer.empty()) {
                std::cout << "------------------------------------------\n"
                          << "WordsContainer is already empty.\n"
                          << "------------------------------------------\n\n";
                break;
            }

            WordsContainer.clear();
            std::cout << "------------------------------------------\n"
                      << "WordsContanier has been cleared.\n"
                      << "------------------------------------------\n\n";
            break;
        }
        case Storage::Alpha: {
            if (AlphaContainer.empty()) {
                std::cout << "------------------------------------------\n"
                          << "AlphaContainer is already empty.\n"
                          << "------------------------------------------\n\n";
                break;
            }

            AlphaContainer.clear();
            std::cout << "------------------------------------------\n"
                      << "AlphaContanier has been cleared.\n"
                      << "------------------------------------------\n\n";
            break;
        }
        default: {
            std::cout << "------------------------------------------\n"
                      << "Incorrect type passsed in. Error.\n"
                      << "------------------------------------------\n\n";
            break;
        }
    }
}

void FileReader::GrabDigits(Modifier Type) {

    std::ifstream InputCopy{FilePath}; // make copy of Input because .get() moves

    switch (Type) {
        case Modifier::TS: {
            while (InputCopy.good()) {
                Character = InputCopy.get();
                if (isdigit(Character)) {
                    Buffer += Character;
                }
                else {
                    if (!Buffer.empty()) {
                        DigitsContainer.emplace_back(std::stoi(Buffer));
                        Buffer.clear();
                    }
                }
            }
            InputCopy.close();
            break;
        }

        case Modifier::TNL: {
            while (InputCopy.good()) {
                Character = InputCopy.get();
                if (isdigit(Character)) {
                    Buffer += Character;
                }
                else if (Character == '\n') {
                    if (!Buffer.empty()) {
                        DigitsContainer.emplace_back(std::stoi(Buffer));
                        Buffer.clear();
                    }
                }
            }
            InputCopy.close();
            break;
        }

        case Modifier::TSNL: {
            while (InputCopy.good()) {
                Character = InputCopy.get();
                if (isdigit(Character)) {
                    Buffer += Character;
                }
                else if (Character == ' ' || Character == '\n') {
                    if (!Buffer.empty()) {
                        DigitsContainer.emplace_back(std::stoi(Buffer));
                        Buffer.clear();
                    }
                }
            }
            InputCopy.close();
            break;
        }
        default: {
            std::cout << "Incorrect type provided. Error.\n\n";
            break;
        }
    }

    Buffer.clear();
}

void FileReader::GrabWords(Modifier Type) {

    std::ifstream InputCopy{FilePath}; // make copy of Input because .get() moves

    switch (Type) {
        case Modifier::TS: {
            while (InputCopy.good()) {
                Character = InputCopy.get();
                if (isalpha(Character)) {
                    Buffer += Character;
                }
                else {
                    if (!Buffer.empty()) {
                        WordsContainer.emplace_back(Buffer);
                        Buffer.clear();
                    }
                }
            }
            InputCopy.close();
            break;
        }
        case Modifier::TNL: {
            while (InputCopy.good()) {
                Character = InputCopy.get();
                if (isalpha(Character) || Character == ' ') {
                    Buffer += Character;
                }
                else if (Character == '\n') {
                    if (!Buffer.empty()) {
                        WordsContainer.emplace_back(Buffer);
                        Buffer.clear();
                    }
                }
            }
            InputCopy.close();
            break;
        }
        case Modifier::TSNL: {
            while (InputCopy.good()) {
                Character = InputCopy.get();
                if (isalpha(Character)) {
                    Buffer += Character;
                }
                else if (Character == ' ' || Character == '\n') {
                    if (!Buffer.empty()) {
                        WordsContainer.emplace_back(Buffer);
                        Buffer.clear();
                    }
                }
            }
            InputCopy.close();
            break;
        }
    }
    
    Buffer.clear();
}

void FileReader::GrabAlpha(char Alpha, Modifier Type) {

    std::ifstream InputCopy{FilePath}; // make copy of Input because .get() moves

    switch (Type) {
        case Modifier::TS: {
            while (InputCopy.good()) {
                Character = InputCopy.get();
                if (Character == Alpha) {
                    Buffer += Character;
                }
                else {
                    if (!Buffer.empty()) {
                        AlphaContainer.emplace_back(Buffer);
                        Buffer.clear();
                    }
                }
            }
            InputCopy.close();
            break;
        }

        case Modifier::TNL: {
            while (InputCopy.good()) {
                Character = InputCopy.get();
                if (Character == Alpha || Character == ' ') {
                    Buffer += Character;
                }
                else if (Character == '\n') {
                    if (!Buffer.empty()) {
                        AlphaContainer.emplace_back(Buffer);
                        Buffer.clear();
                    }
                }
            }
            InputCopy.close();
            break;
        }

        case Modifier::TSNL: {
            while (InputCopy.good()) {
                Character = InputCopy.get();
                if (Character == Alpha) {
                    Buffer += Character;
                }
                else if (Character == ' ' || Character == '\n') {
                    if (!Buffer.empty()) {
                        AlphaContainer.emplace_back(Buffer);
                        Buffer.clear();
                    }
                }
            }
            InputCopy.close();
            break;
        }
    }
    
    Buffer.clear();
}

int FileReader::CountDigits(int Number) {
    std::ifstream InputCopy{FilePath}; // make copy of Input because .get() moves
    int Counter{};

    for (auto i:DigitsContainer) {
        if (i == Number) {
            ++Counter;
        }
    }
    std::cout << "The number '" << Number << "' appears " << Counter << " times.\n\n"; 
    InputCopy.close();
    return Counter;
}

int FileReader::CountWords(std::string Word) {
    std::ifstream InputCopy{FilePath}; // make copy of Input because .get() moves
    int Counter{};

    for (auto i:WordsContainer) {
        if (i == Word) {
            ++Counter;
        }
    }
    std::cout << "The word '" << Word << "' appears " << Counter << " times.\n\n";
    InputCopy.close();
    return Counter;
}

int FileReader::CountAlpha(char Alpha) {
    std::ifstream InputCopy{FilePath}; // make copy of Input because .get() moves
    int Counter{};

    while (InputCopy.good()) {
        Character = InputCopy.get();
        if (Character == Alpha) {
            ++Counter;
        }
    }
    std::cout << "The character '" << Alpha << "' appears " << Counter << " times.\n\n";
    InputCopy.close();
    return Counter;
} 

int FileReader::CountString(std::string String) {
    std::ifstream InputCopy{FilePath}; // make copy of Input because .get() moves
    int Counter{};

    while (InputCopy.good()) {
        Character = InputCopy.get();
        if (Character != ' ' && Character != '\n') {
            Buffer += Character;
        }
        else {
            if (!Buffer.empty()) {
                if (Buffer == String) {
                    ++Counter;
                }
                Buffer.clear();
            }
        }
    }
    std::cout << "The string '" << String << "' appears " << Counter << " times.\n\n";
    InputCopy.close();
    return Counter;    
}

/*

void FileReader::GrabDigitsTS() {
    std::ifstream InputCopy{FilePath}; // make copy of Input because .get() moves
    while (InputCopy.good()) {
        Character = InputCopy.get();
        if (isdigit(Character)) {
            Buffer += Character;
        }
        else {
            if (!Buffer.empty()) {
                DigitsContainer.emplace_back(std::stoi(Buffer));
                Buffer.clear();
            }
        }
    }
}

void FileReader::GrabDigitsTNL() {
    std::ifstream InputCopy{FilePath}; // make copy of Input because .get() moves
    while (InputCopy.good()) {
        Character = InputCopy.get();
        if (isdigit(Character)) {
            Buffer += Character;
        }
        else if (Character == '\n') {
            if (!Buffer.empty()) {
                DigitsContainer.emplace_back(std::stoi(Buffer));
                Buffer.clear();
            }
        }
    }
}

void FileReader::GrabDigitsTSNL() {
    std::ifstream InputCopy{FilePath}; // make copy of Input because .get() moves
    while (InputCopy.good()) {
        Character = InputCopy.get();
        if (isdigit(Character)) {
            Buffer += Character;
        }
        else if (Character == ' ' || Character == '\n') {
            if (!Buffer.empty()) {
                DigitsContainer.emplace_back(std::stoi(Buffer));
                Buffer.clear();
            }
        }
    }
}
*/