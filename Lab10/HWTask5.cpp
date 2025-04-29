#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class Task {
public:
    string title;
    string status;

    Task(string t, string s) : title(t), status(s) {}

    string toString() {
        return title + "," + status;
    }

    static Task fromString(string line) {
        stringstream ss(line);
        string title, status;
        getline(ss, title, ',');
        getline(ss, status, ',');
        return Task(title, status);
    }
};

void saveTasks(vector<Task> tasks, string filename) {
    ofstream file(filename);
    for (auto& task : tasks) {
        file << task.toString() << endl;
    }
    file.close();
}

vector<Task> loadTasks(string filename) {
    ifstream file(filename);
    vector<Task> tasks;
    string line;
    while (getline(file, line)) {
        tasks.push_back(Task::fromString(line));
    }
    file.close();
    return tasks;
}

int main() {
    string filename = "todo.txt";
    vector<Task> tasks = loadTasks(filename);

    int choice;
    do {
        cout << "1. Add Task\n2. Mark Complete\n3. View Tasks\n4. Exit\nChoose: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string title;
            cout << "Enter task title: ";
            getline(cin, title);
            tasks.push_back(Task(title, "pending"));
        } else if (choice == 2) {
            int index;
            cout << "Enter task number to mark complete: ";
            cin >> index;
            if (index > 0 && index <= tasks.size()) {
                tasks[index - 1].status = "completed";
            }
        } else if (choice == 3) {
            for (int i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". " << tasks[i].title << " [" << tasks[i].status << "]" << endl;
            }
        }

        saveTasks(tasks, filename);

    } while (choice != 4);

    return 0;
}
