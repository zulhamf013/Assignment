#include <stdio.h>  
#include<stdlib.h>

struct node{  
    int data;  
    struct node *next;  
};      
   
struct node *head, *tail = NULL;  
    
void add_node(int data) {  
    struct node *newNode = (node*)malloc(sizeof(node));  
    newNode->data = data;  
    newNode->next = NULL;  
    if(head == NULL) {   
        head = newNode;  
        tail = newNode;  
    }  
    else {  
        tail->next = newNode;  
        tail = newNode;  
    }  
}  
   
void MIN() {  
    struct node *NODE = head;  
    int min;  
      
    if(head == NULL) {  
        printf("List is empty \n");  
    }  
    else {  
        min = head->data;  
          
        while(NODE != NULL){  
             if(min > NODE->data) {  
                 min = NODE->data;  
             }  
             NODE= NODE->next;  
        }          
        printf("MIN: %d\n", min);  
    }  
}  
      
void MAX() {  
    struct node *NODE = head;  
    int max;  
      
    if(head == NULL) {  
        printf("List is empty \n");  
    }  
    else {  
        
        max = head->data;  
          
        while(NODE != NULL){  
              
             if(max < NODE->data) {  
                 max = NODE->data;  
             }  
             NODE = NODE->next;  
        }               
        printf("MAX: %d\n", max);  
    }  
}  
      
int main()  
{  
    add_node(10);  
    add_node(2);  
    add_node(6);  
    add_node(90);
    add_node(13);  
    add_node(17);  
    add_node(29);  
    add_node(99);  
    MIN();   
    MAX();  
          
    return 0;  
}  