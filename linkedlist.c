#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node_t{
    int value;
    struct node_t* next;
} node_t;

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

void add_list(node_t** head_ref, int value){
    node_t* new_node = create_node(value);
    if (*head_ref == NULL){
        *head_ref = new_node;
    }
    else{
        node_t* ptr = *head_ref;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
}

int pop_list(node_t** head_ref){
    assert(*head_ref != NULL);
    node_t* ptr = *head_ref;
    *head_ref = (*head_ref)->next;
    int value = ptr->value;
    free(ptr);
    return value;
}

int get_nth(node_t** head_ref, int n){
    assert(*head_ref != NULL);
    assert(n >= 0);
    int counter = 0;
    node_t* ptr = *head_ref;
    while (ptr != NULL && counter < n){
        counter++;
        ptr = ptr->next;
    }
    assert(ptr != NULL);
    return ptr->value;
}

int remove_nth(node_t** head_ref, int n){
    assert(*head_ref != NULL);
    assert(n >= 0);
    int counter = 0;
    node_t* prev = NULL;
    node_t* current = *head_ref;
    node_t* next = current->next;
    while (current != NULL && counter < n){
        counter++;
        prev = current;
        current = next;
        if (current != NULL){
            next = current->next;
        }
    }
    assert(current != NULL);
    int value = current->value;
    free(current);
    if (prev == NULL){
        if (next == NULL){
            *head_ref = NULL;
        }
        else {
            *head_ref = next;
        }
    }
    else { 
        if (next == NULL){
            prev->next = NULL;
        }
        else{
            prev->next = next;
        }
    }
    return value;
}

void test_add_list(node_t** head_ref){
    assert(get_length(*head_ref) == 0);
    add_list(head_ref, 5);
    assert(get_length(*head_ref) == 1);   
    add_list(head_ref, 9);
    assert(get_length(*head_ref) == 2);
    add_list(head_ref, 11);
    assert(get_length(*head_ref) == 3);
    traverse_list(*head_ref);
}

void test_get_nth(node_t** head_ref){
    assert(get_nth(head_ref, 0) == 5);
    assert(get_nth(head_ref, 1) == 9);
    assert(get_nth(head_ref, 2) == 11);
}

void test_pop_list(node_t** head_ref){
    assert(pop_list(head_ref) == 5);
    assert(pop_list(head_ref) == 9);
    assert(pop_list(head_ref) == 11);
    assert(get_length(*head_ref) == 0);
}

void test_remove_nth(node_t** head_ref){
    test_add_list(head_ref);
    assert(remove_nth(head_ref, 1) == 9);  
    assert(remove_nth(head_ref, 0) == 5);    
    assert(remove_nth(head_ref, 0) == 11);
}

int main(){
    node_t** head_ref;
    *head_ref = NULL;
    test_add_list(head_ref);
    test_get_nth(head_ref);  
    test_pop_list(head_ref);
    test_remove_nth(head_ref);
    return 0;
}