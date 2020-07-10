// Multiplication of two polynomials using linked lists

#include <stdio.h>
#include <stdlib.h>

struct node {
	int coefficient;
	int power;
	struct node* next;
};

void display (struct node* start) {
	while (start) {
		printf("(%dx^%d)", start->coefficient, start->power);
		start = start->next;
		if (start) printf(" + ");
	}
	printf("\n");
}

struct node* createNode (int coefficient, int power) {
	struct node* newNode;
	newNode = malloc(sizeof(struct node));
	while (!newNode) {
		printf("Overflow error, Couldn't allocate memory\n");
		exit(1);
	}
	newNode->coefficient = coefficient;
	newNode->power = power;
	newNode->next = NULL;
	return newNode;
}

struct node* add (struct node* ptr1, struct node* ptr2) {
	struct node* head = NULL;
	struct node* current = NULL;
	while (ptr1 && ptr2) {
		if (ptr1->power == ptr2->power) {
			struct node* newNode = createNode(ptr1->coefficient + ptr2->coefficient, ptr1->power);
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

	while (ptr1) {
		struct node* newNode = createNode(ptr1->coefficient, ptr1->power);
			if (!head) {
				current = newNode;
				head = current;
			} else {
				current->next = newNode;
				current = newNode;
			}
			ptr1 = ptr1->next;
	}

	while (ptr2) {
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
	return head;
}

struct node* multiply (struct node* ptr1, struct node* ptr2) {
	struct node* head = NULL;
	while (ptr1) {
		struct node* tempHead = NULL;
		struct node* tempCurrent = NULL;
		struct node* tempPtr2 = ptr2;
		while (tempPtr2) {
			struct node* newNode = createNode(ptr1->coefficient * tempPtr2->coefficient, ptr1->power + tempPtr2->power);
			if (!tempHead) {
				tempCurrent = newNode;
				tempHead = tempCurrent;
			} else {
				tempCurrent->next = newNode;
				tempCurrent = newNode;
			}
			tempPtr2 = tempPtr2->next;
		}
		head = add(head, tempHead);
		ptr1 = ptr1->next;
	}
	return head;
}

int main () {
	struct node* head1 = createNode(1, 1);
	struct node* second1 = createNode(1, 0);
	head1->next = second1;

	struct node* head2 = createNode(1, 3);
	struct node* second2 = createNode(2, 1);
	head2->next = second2;

	struct node* oneIntoTwo = multiply(head1, head2);
	struct node* onePlusTwo = add(head1, head2);

	printf("Polynomial 1: "); display(head1);
	printf("Polynomial 2: "); display(head2);
	printf("P1 + P2 :"); display(onePlusTwo);
	printf("P1 * P2 :"); display(oneIntoTwo);
	return 0;
}
