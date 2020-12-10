#include <stdio.h>
#include <stdlib.h>

struct Node{            //For Linked List
	int data;
	struct Node* next;
	struct Node* prev;
};

void push(struct Node** head_ref, int new_data){            //To add data at the beginning
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;

	new_node->next = (*head_ref);
	new_node->prev = NULL;

	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	(*head_ref) = new_node;
}

void insertAfter(struct Node* prev_node, int new_data){         //To add data after the current iterator
	if (prev_node == NULL){
		printf("the given previous node cannot be NULL");
		return;
	}

	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
	new_node->prev = prev_node;

	if (new_node->next != NULL)
		new_node->next->prev = new_node;
}

void append(struct Node** head_ref, int new_data){              //To add data at the last
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node* last = *head_ref;
	new_node->data = new_data;
	new_node->next = NULL;

	if (*head_ref == NULL) {
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	}

	while (last->next != NULL)
		last = last->next;

	last->next = new_node;
	new_node->prev = last;

	return;
}

void printList(struct Node* node){              //To print the linked list
	struct Node* last;
	printf("\nTraversal in forward direction \n");
	while (node != NULL) {
		printf(" %d ", node->data);
		last = node;
		node = node->next;
	}
}

void primeFactorial(struct Node* node){         //To print the primes and factorial of the largest prime
    if(node == NULL){
        printf("Empty list, returning!");
        return;
    }
    
    int num, flag, max=0, fact=1;
	while (node != NULL) {
        flag=0;
		num = node->data;
        for (int i = 2; i <= num / 2; ++i) {
            if (num % i == 0) {
                flag = 1;
                break;
            }
        }
        if(flag==0){
            if(max<num)
                max = num;
            printf("%d ", num);
        }
		node = node->next;
	}

    if(max>0){
        for (int i = 1; i <= max; ++i)
            fact *= i;
        printf("\nFactorial of maximum number is: %d\n", fact);
    }
    else
        printf("\nThere are no prime numbers!");
    
}

int main(){
    int choice, value;
	struct Node* head = NULL;
    while(1){
        printf("\nChoose your option: \n1. Append\n2. Push\n3. Insert after last iterator\n4. Print\n5. Print PRIME and FACTORIAL\n6. Exit\n");
        scanf("%d", &choice);

        switch (choice){
        case 1: printf("\nEnter the value:");
                scanf("%d", &value);
                append(&head, value);
                break;
        case 2: printf("\nEnter the value:");
                scanf("%d", &value);
                push(&head, value);
                break;
        case 3: printf("\nEnter the value:");
                scanf("%d", &value);
                insertAfter(head->next, value);
                break;
        case 4: printf("\nThe list is: ");
                printList(head);
                break;
        case 5: primeFactorial(head);
                break;
        case 6: exit(1);
    
        default: printf("\nIncorrect option, please try again.");
                break;
        }
    }

	return 0;
}
