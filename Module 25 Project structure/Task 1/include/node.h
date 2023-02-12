//
// Created by Artem on 31.01.2023.
//

#ifndef OPERATION_SIMULATOR_NODE_H
#define OPERATION_SIMULATOR_NODE_H

struct node {
public:
    int x;
    int y;
    node* next;

    node(int valx, int valy);
};

#endif //OPERATION_SIMULATOR_NODE_H
