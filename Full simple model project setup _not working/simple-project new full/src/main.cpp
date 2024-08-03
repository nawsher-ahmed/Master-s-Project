#include <iostream>
#include <fstream>
#include <string>
#include <regex>

void extractStructs(const std::string& filePath) {
    std::ifstream inFile(filePath);
    if (!inFile) {
        std::cerr << "Error opening input file: " << filePath << std::endl;
        return;
    }

    std::ofstream outFile("extracted_data.txt");
    if (!outFile) {
        std::cerr << "Error opening output file: extracted_data.txt" << std::endl;
        return;
    }

    std::string line;
    std::string currentStructName;
    bool inStruct = false;
    while (std::getline(inFile, line)) {
        std::smatch match;
        std::regex structStartRegex(R"(typedef\s+struct\s*\{)");
        std::regex structEndRegex(R"(\}\s*(\w+);)");
        std::regex fieldRegex(R"((\w+)\s+(\w+);)");

        if (std::regex_search(line, match, structStartRegex)) {
            inStruct = true;
        } else if (inStruct && std::regex_search(line, match, structEndRegex)) {
            currentStructName = match[1];
            outFile << "Struct: " << currentStructName << "\n";
            inStruct = false;
        } else if (inStruct && std::regex_search(line, match, fieldRegex)) {
            outFile << match[2] << " : " << match[1] << "\n";
        }
    }

    inFile.close();
    outFile.close();
}

int main(int argc, char **argv) {
    if (argc > 1) {
        extractStructs(argv[1]);
    } else {
        std::cerr << "Usage: FindNamedStructTool <source-file>" << std::endl;
    }
    return 0;
}


