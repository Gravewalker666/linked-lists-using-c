// Adding two polynomials using linked lists

#include <stdio.h>
#include <stdlib.h>

struct node {
	int coefficient;
	int power;
	struct node* next;
};

struct node* create (int coefficient, int power) {
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

void display (struct node* start) {
	while (start) {
		printf("(%dx^%d)", start->coefficient, start->power);
		start = start->next;
		if (start) printf(" + ");
	}
	printf("\n");
}

struct node* add (struct node* ptr1, struct node* ptr2) {
	struct node* head = NULL;
	struct node* current = NULL;
	while (ptr1 && ptr2) {
		if (ptr1->power == ptr2->power) {
			struct node* newNode = create(ptr1->coefficient + ptr2->coefficient, ptr1->power);
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
			struct node* newNode = create(ptr1->coefficient, ptr1->power);
			if (!head) {
				current = newNode;
				head = current;
			} else {
				current->next = newNode;
				current = newNode;
			}
			ptr1 = ptr1->next;
		} else if (ptr2->power > ptr1->power) {
			struct node* newNode = create(ptr2->coefficient, ptr2->power);
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
		struct node* newNode = create(ptr1->coefficient, ptr1->power);
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
		struct node* newNode = create(ptr2->coefficient, ptr2->power);
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

int main () {
	struct node* head1 = create(4, 3);
	struct node* second1 = create(2, 2);
	struct node* third1 = create(-1, 1);
	struct node* fourth1 = create(3, 0);

	head1->next = second1;
	second1->next = third1;
	third1->next = fourth1;

	struct node* head2 = create(4, 4);
	struct node* second2 = create(2, 3);
	struct node* third2 = create(-10, 0);

	head2->next = second2;
	second2->next = third2;

	struct node* onePlusTwo = add(head2, head1);

	printf("Polynomial 1: ");
	display(head1);
	printf("Polynomial 2: ");
	display(head2);

	printf("Polynomial 1 + Polynomial 2 :");
	display(onePlusTwo);

	return 0;
}
