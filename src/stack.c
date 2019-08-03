#include "../include/node.h"
#include <assert.h>

const int STACK_SIZE = 5;

void push(node_t** node_ptr, int x){
    if (*node_ptr == NULL){
        *node_ptr = create_node(x);
    }
    else{
        node_t* ptr = *node_ptr;
        int counter = 1;
        while (ptr->next != NULL){
            ptr = ptr->next;
            counter++;
        }
        assert(counter < STACK_SIZE);
        ptr->next = create_node(x);
    }
}

int pop(node_t** node_ptr){
    assert (*node_ptr != NULL);
    node_t* ptr = *node_ptr;
    node_t* previous = NULL;
    while (ptr->next != NULL){
        previous = ptr;
        ptr = ptr->next;
    }
    int value = ptr->value;
    free(ptr);
    if (previous != NULL){
        previous->next = NULL;
    }
    else{
        *node_ptr = NULL;
    }
    return value;
}

void test_push(node_t** head_ref){
    push(head_ref, 3);
    push(head_ref, 2);
    push(head_ref, 1);
    push(head_ref, 5);
    traverse_list(*head_ref);
    assert(get_length(*head_ref) == 4);
}

void test_pop(node_t** head_ref){
    assert(pop(head_ref) == 5);
    assert(pop(head_ref) == 1);
    assert(pop(head_ref) == 2);
    assert(pop(head_ref) == 3);
    traverse_list(*head_ref);
    assert(get_length(*head_ref) == 0);
}

int main(){
    node_t** head_ref;
    *head_ref = NULL;
    test_push(head_ref);
    test_pop(head_ref);
    return 0;
}