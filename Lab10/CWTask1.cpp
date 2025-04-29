#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Encryptor {
private:
    string filename;

    string encrypt(const string& text) {
        string result = text;
        int len = text.length();
        for (int i = 0; i < len; ++i) {
            result[i] = text[i] + len + i;
        }
        return result;
    }

    string decrypt(const string& text) {
        string result = text;
        int len = text.length();
        for (int i = 0; i < len; ++i) {
            result[i] = text[i] - len - i;
        }
        return result;
    }

public:
    Encryptor(string fname) : filename(fname) {}

    void writeEncrypted(string input) {
        ofstream file(filename);
        string enc = encrypt(input);
        file << enc;
        file.close();
    }

    string readDecrypted() {
        ifstream file(filename);
        string content;
        getline(file, content);
        file.close();
        return decrypt(content);
    }
};

int main() {
    Encryptor e("encrypted.txt");
    string input;
    getline(cin, input);
    e.writeEncrypted(input);
    string decrypted = e.readDecrypted();
    cout << decrypted << endl;
    return 0;
}
