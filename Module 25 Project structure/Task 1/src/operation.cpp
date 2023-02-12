//
// Created by Artem on 01.02.2023.
//

#include <iostream>
#include <vector>
#include <string>
#include "operation.h"
#include "node.h"

opercmd convertcmd(const std::string cmd) {
    if (cmd == "scalpel") return opercmd::SCALPEL;
    if (cmd == "hemostat") return opercmd::HEMOSTAT;
    if (cmd == "tweezers") return opercmd::TWEEZERS;
    if (cmd == "suture") return opercmd::SUTURE;
    if (cmd == "exit") return opercmd::ENDOPER;
    return opercmd::UNKNOWN;
}

node* addpoint() {
    int x, y;
    std::cout << "Enter coordinates (x y): ";
    std::cin >> x >> y;
    node *point = new node(x, y);
    return point;
}

bool execute(std::vector<lognode> &olog, opercmd cmd) {
    if (cmd == opercmd::UNKNOWN) {
        std::cout << "Unknown command. Try again.\n";
        return false;
    }
    if (cmd == opercmd::ENDOPER && !(olog.size())) {
        std::cout << "Operation isn't started!\n";
        return false;
    }
    if (!(olog.size()) && cmd != opercmd::SCALPEL) {
        std::cout << "Initial operation have to be \"scalpel\"\n";
        return false;
    }
    if (cmd  == opercmd::ENDOPER && olog[olog.size()-1].ccode != opercmd::SUTURE) {
        std::cout << "You can't finish operation\n";
        return false;
    }
    if (cmd  == opercmd::ENDOPER && olog[olog.size()-1].ccode == opercmd::SUTURE) {
        std::cout << "Operation finished\n";
    } else {
        int index = olog.size();
        olog.resize(index + 1);
        olog[index].ccode = cmd;
        olog[index].fnode = addpoint();
        if (cmd == opercmd::SCALPEL || cmd == opercmd::SUTURE) {
            olog[index].fnode->next = addpoint();
        }
    }
    return true;
}

void operate() {
    std::vector<lognode> operlog;
    std::string command;
    bool step;
    do {
        std::cout << "CLI> ";
        std::cin >> command;
        step = execute(operlog, convertcmd(command));
    } while (!step || (step && command != "exit"));
    for (int i=operlog.size()-1; i>=0; i--) {
        node* pn = operlog[i].fnode;
        if (pn->next == nullptr) {
            delete pn;
        } else {
            node* sn = pn->next;
            delete sn;
            delete pn;
        }
        operlog.pop_back();
    }
    std::cout << "End\n";
};
