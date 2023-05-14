#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

struct Bdata {
    time_t birthdate;
    string fullName;
};

enum command {
    EXIT = 0,
    WEEK,
    MONTH,
    YEAR,
    ADD,
    UNKNOWN
};

command getCmdCode(const string &cmd) {
    if (cmd == "add") return ADD;
    if (cmd == "week") return WEEK;
    if (cmd == "month") return MONTH;
    if (cmd == "year") return YEAR;
    if (cmd == "exit") return EXIT;
    return UNKNOWN;
}

void addRecord(map<time_t, vector<Bdata>> &dbi) {
    cout << "  Enter full name: ";
    Bdata record;
    getline(cin, record.fullName);
    cout << "  Enter birthdate (DD/MM/YYYY): ";
    string bdate;
    cin >> bdate;
    stringstream bs;
    bs << bdate;
    struct tm dateBuf = {0};
    bs >> get_time(&dateBuf, "%d/%m/%Y");
    cout << dateBuf.tm_year << " " << dateBuf.tm_mon << " " << dateBuf.tm_mday << endl;
    return;
};

void printList(map<time_t, vector<Bdata>> &dbi, const command &ccode = WEEK) {
    return;
}

int main() {
    cout << "Birthday Reminder!" << endl;
    time_t now = time(nullptr);
    tm* pNow = localtime(&now);
    map<time_t, vector<Bdata>> dbIndex;
    command cmdCode;
    cout << "Instruction:\n"
         << " - to add birthday record enter command \"add\"\n"
         << " - for remind about birthdays for a week enter \"week\"\n"
         << " - for remind about birthdays for month enter \"month\"\n"
         << " - for remind about birthdays for year enter \"year\"\n"
         << " - for exit enter \"exit\"\n";
    do {
        string lineCmd;
        cout << "CL> ";
        cin >> lineCmd;
        cmdCode = getCmdCode(lineCmd);
        if (cmdCode == ADD) addRecord(dbIndex);
        else if (cmdCode == WEEK || cmdCode == MONTH || cmdCode == YEAR) printList(dbIndex, cmdCode);
        else if (cmdCode == EXIT) cout << "Exit!\n";
        else cout << "Command unknown!\n";
    } while (cmdCode);
    return 0;
}