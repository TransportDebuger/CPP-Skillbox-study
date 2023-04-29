#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
//#include <fstream>
#include <ctime>

//#define BASEFILE "data.bin"

using namespace std;

struct baseRecord {
    time_t birthday;
    string fullname;
};

enum command {
    ADD = 0,
    LIST,
    EXIT,
    UNKNOWN
};

command getCommandCode(const string &cl) {
    if (cl=="add") return ADD;
    if (cl=="list") return LIST;
    if (cl=="exit") return EXIT;
    return UNKNOWN;
}

//void readBase(fstream &bfile, vector<baseRecord> &bl) {
//    while (!bfile.eof()) {
//        baseRecord br;
//        int ssize;
//        bfile.read((char*)&br.birthday, sizeof(time_t));
//        bfile.read((char*)&ssize, sizeof(int));
//        char *fn;
//        bfile.read(fn, ssize);
//        br.fullname = fn;
//        bl.push_back(br);
//    }
//}

void printReminder(const vector<baseRecord> &bl) {
    cout << "Birthdays:" << endl;
    time_t now = time(nullptr);
    struct tm pNow = *localtime(&now);
    cout << "Date       Full Name" << endl;
    for (int ind=0; ind<bl.size(); ind++) {
        struct tm pBdate = *localtime(&bl[ind].birthday);
        if (pNow.tm_mon == pBdate.tm_mon &&
            pNow.tm_mday <= pBdate.tm_mday)
            cout << pBdate.tm_mday << "/" << pBdate.tm_mon+1 << "/" << pBdate.tm_year << "  " << bl[ind].fullname << endl;
        else if (pNow.tm_mon < pBdate.tm_mon)
            cout << pBdate.tm_mday << "/" << pBdate.tm_mon+1 << "/" << pBdate.tm_year << "  " << bl[ind].fullname << endl;
    }
    cout << endl;
}

void addRecord(vector<baseRecord> &bl) {
    baseRecord br;
    string sbdate, sfullname;
    cout << "Enter birthdate (DD/MM/YYYY): ";
    struct tm tmdate = {0};
    cin >> get_time(&tmdate, "%d/%m/%Y");
    br.birthday = mktime(&tmdate);
    cout << "Enter full name: ";
    cin >> br.fullname;
    bl.push_back(br);
}

void sortList(vector<baseRecord> &bl) {
    if (bl.size()==1) return;
    const double factor = 1.247;
    double step = bl.size() - 1;
    while (step>=1) {
        for (int ind = 0; ind+step < bl.size(); ++ind) {
            struct tm leftValue = *localtime(&bl[ind].birthday);
            struct tm rightValue = *localtime(&bl[ind+step].birthday);
            baseRecord br;
            if (leftValue.tm_mon>rightValue.tm_mon ||
                (leftValue.tm_mon==rightValue.tm_mon && leftValue.tm_mday>rightValue.tm_mday)) {
                br = bl[ind+step];
                bl[ind+step] = bl[ind];
                bl[ind] = br;
            }
        }
        step = int(step / factor);
    }
}

int main() {
    cout << "Birthday Reminder!" << endl;
    vector<baseRecord> baseList;
//    fstream baseFile;
//    baseFile.open(BASEFILE, ios::binary);
//    if (baseFile) {
//        readBase(baseFile, baseList);
//    }
    command cmd;
    do {
        string cmdline;
        cout << "CL > ";
        cin >> cmdline;
        cmd = getCommandCode(cmdline);
        if (cmd==UNKNOWN) cout << "Unknown command!" << endl;
        else if (cmd==ADD) {
            addRecord(baseList);
            sortList(baseList);
        } else if (cmd==LIST) {
            printReminder(baseList);
        }
    } while (cmd!=EXIT);

//    baseFile.close();
    return 0;
}
