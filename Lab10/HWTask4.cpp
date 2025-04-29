#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

class Logger {
private:
    string baseFilename;
    int maxSize;
    int fileIndex;

    string currentLogFile() {
        return baseFilename + to_string(fileIndex) + ".txt";
    }

    void rotateFile() {
        fileIndex++;
    }

public:
    Logger(string base, int max) {
        baseFilename = base;
        maxSize = max;
        fileIndex = 1;
    }

    void log(string message) {
        string filename = currentLogFile();

        if (fs::exists(filename) && fs::file_size(filename) >= maxSize) {
            rotateFile();
            filename = currentLogFile();
        }

        ofstream outFile(filename, ios::app);
        outFile << message << endl;
        outFile.close();
    }
};

int main() {
    Logger logger("log", 1024);

    for (int i = 1; i <= 100; i++) {
        logger.log("Log message number " + to_string(i));
    }

    return 0;
}
