#include "../include/node.h"

node_t* create_node(int value){
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void traverse_list(node_t* node){
    node_t* ptr = node;
    while (ptr != NULL) {
        printf("%d->", ptr->value);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int get_length(node_t* head){
    int counter = 0;
    node_t* ptr = head;
    while (ptr != NULL) {
        counter++;
        ptr = ptr->next;
    }
    return counter;
}