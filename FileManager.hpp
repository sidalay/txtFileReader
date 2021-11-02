#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>

// Parameter inputs for Clear function
enum class Storage {Input, All, Digits, Words, Alpha};
// Paramater inputs for Grab functions [ Til-Space, Til-New-Line, Til-Space-or-New-Line ]
enum class Modifier {TS, TNL, TSNL};

class FileReader {
private:
    std::ifstream Input{};
    std::string FilePath{};
    std::string Fill{};
    std::string Buffer{};
    std::vector<std::string> AllContainer{};
    std::vector<int> DigitsContainer{};
    std::vector<std::string> WordsContainer{};
    std::vector<std::string> AlphaContainer{};
    char Character{};
    // Grabs line by line and stores it in vector<string> Container
    std::vector<std::string> GrabLines(std::ifstream File);
public:
    FileReader(const std::string FileName);
    FileReader(const FileReader& ref) = delete;
    FileReader(FileReader&& ref) = default;
    FileReader& operator=(const FileReader& ref) = delete;
    FileReader& operator=(FileReader&& ref) = default;
    ~FileReader();

    // Print Container based on enum Storage type passed in [ Input, AlphaNum, Digits, Words, Alpha ]
    void Print(Storage ContainerType = Storage::Input);
    // Clear Container based on type passed in [ AlphaNum, Digits, Words, Alpha ]
    void Clear(Storage ContainerType);
    
    // Grab digits based on enum Modifier type passed in [ TS, TNL, TSNL ]
    void GrabDigits(Modifier Type);
    // Grab words based on enum Modifier type passed in [ TS, TNL, TSNL ]
    void GrabWords(Modifier Type);
    // Grab chars based on specified filter & enum Modifier type passed in [ TS, TNL, TSNL ]
    void GrabAlpha(char Alpha, Modifier Type);

    // Returns how many times int Number appears in DigitsContainer 
    int CountDigits(int Number); 
    // Returns how many times string Word appears in WordsContainer
    int CountWords(std::string Word); 
    // Returns how many times char Alpha appears in Input
    int CountAlpha(char Alpha);
    // Returns how many times string String appears in Input
    int CountString(std::string String);

    // grab with specified filter
    // grab with digits and alphas filtered separately

};

#endif



/*
    // Grab digit Til-Space and stores it in vec<int> DigitsContainer
    void GrabDigitsTS();
    // Grab digit Til-New-Line and stores it in vec<int> DigitsContainer
    void GrabDigitsTNL();
    // Grab digit Til-Space-or-New-Line and stores it in vec<int> DigitsContainer
    void GrabDigitsTSNL();
*/