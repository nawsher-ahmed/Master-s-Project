#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

struct StructField {
    std::string name;
    std::string type;
};

struct StructInfo {
    std::string name;
    std::vector<StructField> fields;
};

std::vector<StructInfo> parseExtractedData(const std::string& filePath) {
    std::ifstream inFile(filePath);
    if (!inFile) {
        std::cerr << "Error opening input file: " << filePath << std::endl;
        return {};
    }

    std::vector<StructInfo> structs;
    std::string line;
    StructInfo currentStruct;

    while (std::getline(inFile, line)) {
        if (line.find("Struct: ") == 0) {
            if (!currentStruct.name.empty()) {
                structs.push_back(currentStruct);
                currentStruct = StructInfo();
            }
            currentStruct.name = line.substr(8);
        } else {
            std::istringstream iss(line);
            StructField field;
            iss >> field.name >> field.type;
            currentStruct.fields.push_back(field);
        }
    }
    if (!currentStruct.name.empty()) {
        structs.push_back(currentStruct);
    }

    inFile.close();
    return structs;
}

void generateAdapterFiles(const std::vector<StructInfo>& structs) {
    std::ofstream headerFile("adapter.h");
    std::ofstream sourceFile("adapter.c");

    if (!headerFile || !sourceFile) {
        std::cerr << "Error opening output files." << std::endl;
        return;
    }

    headerFile << "#ifndef ADAPTER_H_\n#define ADAPTER_H_\n\n";
    headerFile << "#include \"Model2.h\"\n\n";

    sourceFile << "#include \"adapter.h\"\n#include <string.h>\n\n";

    for (const auto& structInfo : structs) {
        std::string writeFuncName = "write_to_buffer_" + structInfo.name;
        std::string readFuncName = "read_from_buffer_" + structInfo.name;

        // Write function
        headerFile << "void " << writeFuncName << "(const struct " << structInfo.name << " *data, char *buffer);\n";
        sourceFile << "void " << writeFuncName << "(const struct " << structInfo.name << " *data, char *buffer) {\n";
        size_t offset = 0;
        for (const auto& field : structInfo.fields) {
            sourceFile << "    memcpy(buffer + " << offset << ", &data->" << field.name << ", sizeof(" << field.type << "));\n";
            offset += 8;  // Assuming 8-byte alignment for simplicity
        }
        sourceFile << "}\n\n";

        // Read function
        headerFile << "void " << readFuncName << "(struct " << structInfo.name << " *data, const char *buffer);\n";
        sourceFile << "void " << readFuncName << "(struct " << structInfo.name << " *data, const char *buffer) {\n";
        offset = 0;
        for (const auto& field : structInfo.fields) {
            sourceFile << "    memcpy(&data->" << field.name << ", buffer + " << offset << ", sizeof(" << field.type << "));\n";
            offset += 8;  // Assuming 8-byte alignment for simplicity
        }
        sourceFile << "}\n\n";
    }

    headerFile << "\n#endif /* ADAPTER_H_ */\n";
    headerFile.close();
    sourceFile.close();
}

int main() {
    const std::string extractedDataPath = "../build/extracted_data.txt"; // Look for the file in the build directory
    auto structs = parseExtractedData(extractedDataPath);
    generateAdapterFiles(structs);
    return 0;
}

