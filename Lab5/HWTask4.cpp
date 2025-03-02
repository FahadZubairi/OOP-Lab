#include <iostream>
#include <thread> 
#include <chrono> 

using namespace std;

class Blend {
public:
    void blendJuice() {
        cout << "Blending juice..." << endl;
        std::this_thread::sleep_for(std::chrono::seconds(4)); 
        cout << "Blending complete!" << endl;
    }
};

class Grind {
public:
    void grindJuice() {
        cout << "Grinding ingredients..." << endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));
        cout << "Grinding complete!" << endl;
    }
};

class JuiceMaker {
private:
    Blend blend;
    Grind grind;
public:
    void makeJuice() {
        cout << "Starting the juice-making process..." << endl;
        blend.blendJuice();
        grind.grindJuice();
        cout << "Juice is ready to serve!" << endl;
    }
};

int main() {
    JuiceMaker juiceMaker;
    juiceMaker.makeJuice();
    return 0;
}
