#include<stdio.h>  
#include<stdlib.h>  
  
struct Node  
{  
    int data;  
    struct Node* next;  
};  
  

void display_MID(struct Node *head)  
{  
    struct Node *p = head;  
    struct Node *q = head;  
  
    if (head!=NULL)  {  
        while (q != NULL && q->next != NULL)  {  
            q = q->next->next;  
            p = p->next;  
        }  
        printf("MID %d\n", p->data);  
    }  
}  
  
void pushMid(struct Node** head, int data_baru)  {  
   
    struct Node* node_baru =  (Node*) malloc(sizeof(Node));  
    node_baru->data = data_baru;  
    node_baru->next = (*head);  
    (*head) = node_baru;  
}  
  
 
void display_Node(struct Node *p)  {  
    while (p != NULL)  {  
        printf("%d->", p->data);  
        p = p->next;  
    }  
    printf("NULL\n");  
}  
  
int main()  {  
    struct Node* head = NULL;  
        pushMid(&head, 10);
        pushMid(&head, 20);   
        pushMid(&head, 32); 
        pushMid(&head, 42); 
        pushMid(&head, 12); 
        pushMid(&head, 19); 
        pushMid(&head, 34); 
        display_Node(head);  
        display_MID(head);  
    return 0;  
}  
