
#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

void add_node(struct Node** head, int data_baru){
	
	struct Node* node_baru = (Node*) malloc(sizeof(Node));
	node_baru->data = data_baru;
	node_baru->next = (*head);	
	(*head) = node_baru;
}


void display_node(struct Node *node){
	while (node!=NULL)
	{
	printf("%d ", node->data);
	node = node->next;
	}
} 

Node* remove(Node* head) {
		if (head == nullptr) {
            return nullptr;
        }
		if (head->next == nullptr) {
            return head;
        }

		if (head->data == head->next->data) {
			Node *temp;
			temp = head->next;
			head->next = head->next->next;
			free(temp);
			return remove(head);
		} else {
			head->next = remove(head->next);
			return head;
		}
	}

int main(){
	
	struct Node* head = NULL;

	
	add_node(&head, 23);
	add_node(&head, 23);
	add_node(&head, 43); 
	add_node(&head, 43);
	add_node(&head, 43);
	add_node(&head, 43);								 
	printf("Link List: ");
	display_node(head);
	head = remove(head); 

	printf("Delete List: ");		 
	display_node(head);		
	return 0;
}
