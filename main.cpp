#include <iostream>
#include <fstream>
#include "FileManager.hpp"


int main() {
    FileReader Input{"Input.txt"};

    Input.Print();

    Input.Print(Storage::All);

    // Emplace_back when hitting a space
    Input.GrabDigits(Modifier::TS);
    Input.Print(Storage::Digits);
    Input.Clear(Storage::Digits);

    // Emplace_back when hitting \n
    Input.GrabDigits(Modifier::TNL);
    Input.Print(Storage::Digits);
    Input.Clear(Storage::Digits);

    // Emplace_back when hitting space or \n
    Input.GrabDigits(Modifier::TSNL);
    Input.Print(Storage::Digits);
    Input.Clear(Storage::Digits);

    // Emplace_back when hitting a space
    Input.GrabWords(Modifier::TS);
    Input.Print(Storage::Words);
    Input.Clear(Storage::Words);

    // Emplace_back when hitting \n
    Input.GrabWords(Modifier::TNL);
    Input.Print(Storage::Words);
    Input.Clear(Storage::Words);

    // Emplace_back when hitting space or \n
    Input.GrabWords(Modifier::TSNL);
    Input.Print(Storage::Words);
    Input.Clear(Storage::Words);

    // Emplace_back when hitting a space
    Input.GrabAlpha('a', Modifier::TS);
    Input.Print(Storage::Alpha);
    Input.Clear(Storage::Alpha);

    // Emplace_back when hitting \n
    Input.GrabAlpha('a', Modifier::TNL);
    Input.Print(Storage::Alpha);
    Input.Clear(Storage::Alpha);

    // Emplace_back when hitting space or \n
    Input.GrabAlpha('a', Modifier::TSNL);
    Input.Print(Storage::Alpha);
    Input.Clear(Storage::Alpha);

    Input.GrabDigits(Modifier::TSNL);
    Input.GrabWords(Modifier::TSNL);
    Input.CountAlpha('a');
    Input.CountDigits(268);
    Input.CountWords("react");

    Input.CountString("h2e6l8lo");
    Input.CountString("w345orld");
    Input.CountString("///");
}