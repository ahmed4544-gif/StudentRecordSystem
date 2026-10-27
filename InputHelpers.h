#ifndef INPUTHELPERS_H
#define INPUTHELPERS_H

#include <string>

// Reads a whole number between minVal and maxVal. Keeps asking until valid.
int readInt(std::string prompt, int minVal, int maxVal);

// Reads a decimal number between minVal and maxVal. Keeps asking until valid.
float readFloat(std::string prompt, float minVal, float maxVal);

// Reads a non-empty line of text. Commas are replaced by spaces
// because commas separate the fields in the data file.
std::string readText(std::string prompt);

#endif
