#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    virtual double getTuition(string status, int creditHours) = 0;
};

class GraduateStudent : public Student {
    string researchTopic;
public:
    void setResearchTopic(string topic) {
        researchTopic = topic;
    }
    string getResearchTopic() {
        return researchTopic;
    }

    double getTuition(string status, int creditHours) {
        if (status == "undergraduate") return creditHours * 200;
        else if (status == "graduate") return creditHours * 300;
        else if (status == "doctoral") return creditHours * 400;
        return 0;
    }
};

int main() {
    GraduateStudent g;
    g.setResearchTopic("Artificial Intelligence");
    cout << "Research Topic: " << g.getResearchTopic() << endl;
    cout << "Graduate Tuition (9 credits): $" << g.getTuition("graduate", 9) << endl;
    cout << "Doctoral Tuition (6 credits): $" << g.getTuition("doctoral", 6) << endl;
    return 0;
}
