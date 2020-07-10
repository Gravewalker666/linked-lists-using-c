// Subtracting one polinomial from another

#include <stdio.h>
#include <stdlib.h>

struct node {
	int coefficient;
	int power;
	struct node* next;
};

void display (struct node* start) {
	while (start) {
		printf("(%dX^%d) + ", start->coefficient, start->power);
		start = start->next;
	}
	printf("0\n");
}

struct node* createNode (int coefficient, int power) {
	struct node* newNode;
	newNode = malloc(sizeof(struct node));
	if (!newNode) {
		printf("Overflow error, Couldn't allocate memory\n");
		exit(1);
	}
	newNode->coefficient = coefficient;
	newNode->power = power;
	newNode->next = NULL;

	return newNode;
}

struct node* subtract (struct node* ptr1, struct node* ptr2) {
	struct node* head = NULL;
	struct node* current = NULL;
	while (ptr2 && ptr1) {
		if (ptr1->power == ptr2->power) {
			struct node* newNode = createNode(ptr1->coefficient - ptr2->coefficient, ptr1->power);
			if (!head) {
				current = newNode;
				head = current;
			} else {
				current->next = newNode;
				current = newNode;
			}
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		} else if (ptr1->power > ptr2->power) {
			struct node* newNode = createNode(ptr1->coefficient, ptr1->power);
			if (!head) {
				current = newNode;
				head = current;
			} else { 
				current->next = newNode;
				current = newNode;
			}
			ptr1 = ptr1->next;
		} else if (ptr2->power > ptr1->power) {
			struct node* newNode = createNode(ptr2->coefficient, ptr2->power);
			if (!head) {
				current = newNode;
				head = current;
			} else { 
				current->next = newNode;
				current = newNode;
			}
			ptr2 = ptr2->next;
		} 
	}
	return head;
}

int main () {
	struct node* ll1head = createNode(4, 3);
	struct node* ll1node2 = createNode(2, 2);
	struct node* ll1node3 = createNode(-1, 1);
	struct node* ll1node4 = createNode(3, 0);

	ll1head->next = ll1node2;
	ll1node2->next = ll1node3;
	ll1node3->next = ll1node4;

	struct node* ll2head = createNode(5, 1);
	struct node* ll2node2 = createNode(1, 0);

	ll2head->next = ll2node2;

	struct node* subtracted = subtract(ll1head, ll2head);
	display(subtracted);

	return 0;
}



