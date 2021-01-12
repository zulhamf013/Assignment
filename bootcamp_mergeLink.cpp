#include<stdio.h> 
#include<stdlib.h> 
#include<assert.h> 
  
/* Link list node */
struct Node 
{ 
    int data; 
    struct Node* next; 
}; 
  

void tukar(struct Node** D, struct Node** S); 

struct Node* MergeSort(struct Node* x, struct Node* y) { 
    struct Node temp; 
    struct Node *tail = &temp;
    temp.next = NULL; 
    while (1) { 
        if (x == NULL) { 
            tail->next = y; 
            break; 
        } else if (y == NULL) { 
            tail->next = x; 
            break; 
        } 

        if (x->data <= y->data) {
            tukar(&(tail->next), &x);
        } else {
            tukar(&(tail->next), &y);
        } 
  
        tail = tail->next; 
    } 
    return(temp.next); 
} 
  
void tukar(struct Node** D, struct Node** S) { 
    struct Node* node_baru = *S; 
    assert(node_baru != NULL); 
    *S = node_baru->next; 
    node_baru->next = *D; 
    *D = node_baru; 
} 
  
  
void addNode(struct Node** head, int data_baru) { 
    /* mengalokasikan node */
    struct Node* node_baru = (struct Node*) malloc(sizeof(struct Node)); 
    /* menaruh di dalam data  */
    node_baru->data  = data_baru; 
    /* menaruh data lama ke yang baru */
    node_baru->next = (*head); 
    /* memindah head ke node baru */
    (*head)    = node_baru; 
} 
  

void printList(struct Node *node) { 
    while (node!=NULL) 
    { 
        printf("%d -> ", node->data); 
        node = node->next; 
    } 
    puts("NULL");
} 
  

int main() { 
    
    struct Node* node = NULL; 
    struct Node* x = NULL; 
    struct Node* y = NULL; 
  
    addNode(&x, 25); 
    addNode(&x, 17); 
    addNode(&x, 13); 
  
    addNode(&y, 40); 
    addNode(&y, 5); 
    addNode(&y, 1); 
  
    node = MergeSort(x, y); 
  
    printf("Merge Link List: \n"); 
    printList(node); 
  
    return 0; 
} 