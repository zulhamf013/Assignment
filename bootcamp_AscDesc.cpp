#include <stdio.h>
#include <stdlib.h>


struct Node {
	int data;
	struct Node *next;
};

void manipulate(struct Node** head){
	struct Node *node_bef = NULL;
	struct Node *node_af = *head;
	struct Node *next = NULL;
	while (node_af != NULL) {
		next = node_af->next;
		node_af->next = node_bef;
		node_bef = node_af;
		node_af = next;
	}
	*head = node_bef;
}

void add_node(struct Node** head, int data_baru){
	struct Node *node_baru
		= (struct Node*)malloc(sizeof(struct Node));
	node_baru->data = data_baru;
	node_baru->next = (*head);
	(*head) = node_baru;
}


void display(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL) {
		printf("%d ->", temp->data);
		temp = temp->next;
	}
    puts("NULL");
}


int main(){	
	struct Node *head = NULL;
	add_node(&head, 14);
	add_node(&head, 12);
	add_node(&head, 10);
	add_node(&head, 8);
    add_node(&head, 6);
	add_node(&head, 5);
	add_node(&head, 3);
	add_node(&head, 1);

	printf("Linked List: \n");
	display(head);
	manipulate(&head);
	printf("Sort:  \n");
	display(head);
	
}