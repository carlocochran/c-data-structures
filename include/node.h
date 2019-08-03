#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node_t{
    int value;
    struct node_t* next;
} node_t;

node_t* create_node(int value);

void traverse_list(node_t* node);

int get_length(node_t* head);

#endif /* NODE_H */