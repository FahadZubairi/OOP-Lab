#include <iostream>
using namespace std;

class Student {
private:
    const int roll_no;  
    
public:
    Student(int roll) : roll_no(roll) {}

    void display() {
        cout << "Student Roll No: " << roll_no << endl;
    }
};

int main() {
    int rollNumber;
  
    cout << "Enter the student's roll number: ";
    cin >> rollNumber;

    Student student(rollNumber);
    
    student.display();

    return 0;
}
