#include<stdio.h>
#include<stdlib.h>

struct Node { 
    int data; 
    struct Node* next; 
}; 
  
void display(struct Node* head, int x) { 
    int L = 0, i; 
    struct Node* temp = head; 

    while (temp != NULL) { 
        temp = temp->next; 
        L++; 
    } 
    if (L < x) {
        return; 
    }
    temp = head; 
    for (i = 1; i < L - x + 1; i++) {
        temp = temp->next; 
    }
  
    printf("N'th Node: %d\n", temp->data); 
    return; 
} 
  
void add_node(struct Node** head, int data_baru) { 
    struct Node* node_baru  = new Node(); 
    node_baru ->data = data_baru;
    node_baru ->next = (*head); 
    (*head) = node_baru ; 
} 
  
int main() { 
    struct Node* head = NULL; 
   
    add_node(&head, 12); 
    add_node(&head, 43); 
    add_node(&head, 32); 
    add_node(&head, 87); 
    display(head, 4); 
    return 0; 
}