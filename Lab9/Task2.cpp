#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;

class Logger {
    deque<string> logs;
    const int maxLogs = 1000;

    void addLog(const string& severity, const string& message) {
        if (logs.size() == maxLogs) logs.pop_front();
        logs.push_back(severity + ": " + message);
    }

public:
    void logInfo(const string& msg) {
        addLog("INFO", msg);
    }

    void logWarning(const string& msg) {
        addLog("WARN", msg);
    }

    void logError(const string& msg) {
        addLog("ERROR", msg);
    }

    vector<string> retrieveLogs(const string& auditor) {
        if (auditor == "authorized") return vector<string>(logs.begin(), logs.end());
        return {};
    }
};

int main() {
    Logger logger;
    logger.logInfo("System started");
    logger.logWarning("Low disk space");
    logger.logError("Connection failed");

    vector<string> auditLogs = logger.retrieveLogs("authorized");
    for (const string& log : auditLogs) {
        cout << log << endl;
    }

    return 0;
}
