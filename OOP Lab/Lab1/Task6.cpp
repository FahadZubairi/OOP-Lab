#include <iostream>
#include <iomanip>
#include <string> 
using namespace std;

int main() {
    string firstName, lastName;
    double score1, score2, score3, score4, score5;

    cout << "Enter student name followed by five test scores: ";
    cin >> firstName >> lastName >> score1 >> score2 >> score3 >> score4 >> score5;

    double average = (score1 + score2 + score3 + score4 + score5) / 5.0;

    cout << "\nStudent name: " << firstName << " " << lastName << endl;
    cout << "Test scores: "
         << fixed << setprecision(2) << score1 << " "
         << fixed << setprecision(2) << score2 << " "
         << fixed << setprecision(2) << score3 << " "
         << fixed << setprecision(2) << score4 << " "
         << fixed << setprecision(2) << score5 << endl;
    cout << "Average test score: " << fixed << setprecision(2) << average << endl;

    return 0;
}
