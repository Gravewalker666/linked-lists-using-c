// Implementing polynomial function using c

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
	if (newNode) {
		newNode->coefficient = coefficient;
		newNode->power = power;
		newNode->next = NULL;
	} else {
		printf("Overflow error, Couldn't allocate memory\n");
		exit(1);
	}
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

int main() {
	struct node* start = create(4, 3);
	struct node* secondNode = create(2, 2);
	struct node* thirdNode = create(-1, 1);
	struct node* fourthNode = create(3, 0);

	start->next = secondNode;
	secondNode->next = thirdNode;
	thirdNode->next = fourthNode;

	display(start);

	free(start);
	free(secondNode);
	free(thirdNode);
	free(fourthNode);
	return 0;
}