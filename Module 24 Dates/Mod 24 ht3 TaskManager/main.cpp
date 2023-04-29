#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;

struct TaskInfo {
    string tName;
    time_t tStart = 0, tEnd = 0;
};

struct TaskNode {
public:
    TaskInfo tInfo;
    TaskNode* next;

    TaskNode(const TaskInfo ti) {
        this->tInfo = ti;
        this->next = nullptr;
    }
};

struct TaskStack {
public:
    TaskNode* head, * tail;
    int tCount;

    TaskStack() {
        this->head = this->tail = nullptr;
        this->tCount = 0;
    }

    ~TaskStack() {
        while (head != nullptr) pop_front();
    }

    void pop_front() {
        if (head == nullptr) return;
        if (head == tail) {
            delete tail;
            head = tail = nullptr;
            tCount--;
            return;
        }
        TaskNode* tNode = head;
        head = tNode->next;
        tCount--;
        delete tNode;
    }

    void push_front(TaskInfo ti) {
        TaskNode* tNode = new TaskNode(ti);
        tNode->next = head;
        head = tNode;
        if (tail == nullptr) tail = tNode;
        tCount++;
    }

    void print_list() {
        TaskNode* tNode = head;
        int tc = 0;
        cout << "TASK_NAME  START  STATUS  END  EXEC_TIME" << endl;
        while (head && tc<tCount) {
            time_t ltStart = tNode->tInfo.tStart, ltEnd = tNode->tInfo.tEnd;
            tm* ptTm = localtime(&ltStart);
            cout << tNode->tInfo.tName << "  " << put_time(ptTm, "%Y/%m/%d %H:%M:%S") << "  ";
            if (ltEnd != 0) {
                ptTm = localtime(&ltEnd);
                cout << "  STOPPED  " << put_time(ptTm, "%Y/%m/%d %H:%M:%S")<< "  " << ltEnd - ltStart << " sec";
            } else {
                cout << "  RUNNING";
            }
            cout << endl;
            tNode = tNode->next;
            tc++;
        }
        cout << "Task in list: " << tCount << endl;
    }
};

enum commands {
    EXIT = 0,
    BEGIN,
    END,
    STATUS,
    UNKNOWN
};

commands commandCode(const string &sc) {
    if (sc == "exit") return EXIT;
    if (sc == "begin") return BEGIN;
    if (sc == "end") return END;
    if (sc == "status") return STATUS;
    return UNKNOWN;
}

int main() {
    std::cout << "Task manager!" << std::endl;
    string sCommand;
    commands command;
    TaskStack tList;
    do {
       cout << "CL> ";
       cin >> sCommand;
       command = commandCode(sCommand);
       if (command == UNKNOWN) {cout << "Unknown command" << endl << endl;}
       else if (command == STATUS) {tList.print_list();}
       else if (command == BEGIN) {
           TaskInfo tInfo;
           cout << "Enter task name: ";
           cin >> tInfo.tName;
           time_t tnew = time(nullptr);
           tInfo.tStart = tnew;
           tInfo.tEnd = 0;
           if (tList.head != nullptr && !(tList.head->tInfo.tEnd)) tList.head->tInfo.tEnd = tnew;
           tList.push_front(tInfo);
           cout << "Add task to execution" << endl << endl;
       } else if (command == END) {
           TaskInfo tInfo;
           if (tList.head != nullptr) tList.head->tInfo.tEnd = time(nullptr);
           cout << "Task execution break" << endl << endl;
       }
    } while (command);
    while (tList.tCount) {
        tList.pop_front();
    }
    return 0;
}
