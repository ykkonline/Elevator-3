#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
#define TOPFLOOR 15
#define BOTTOMFLOOR 0

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};



struct Node* ChangeFloor(struct Node* currentFloor) {
#define MAXFLOORSINPUT 16

	printf("\nHow many floors would you like to go to?\n");
	int myTargets[MAXFLOORSINPUT];
	int floorCount = NULL;
	while (TRUE) {
		int result = scanf("%d", &floorCount);
		while ((getchar()) != '\n');
		if (result == EOF || result == FALSE) {
			printf("\nPlease enter a valid integer\n");

		}
		else if (result == TRUE) {
			if (floorCount > MAXFLOORSINPUT || floorCount < 1) {
				printf("\nPlease enter a valid integer\n");
			}
			else {
				break;
			}
		}
	}

	int a;
	int input = NULL;

	for (a = 0; a < floorCount; a++) {
		printf("\nPlease enter a floor to go to\n");

		while (TRUE) {
			int result = scanf("%d", &input);
			while ((getchar()) != '\n');
			if (result == EOF || result == FALSE) {
				printf("\nPlease enter a valid number\n");
			}
			else if (result == TRUE) {
				if (input > TOPFLOOR || input < BOTTOMFLOOR) {
					printf("\nPlease enter a valid number\n");
				}
				else {
					if (a == 0) {
						myTargets[a] = input;
						break;
					}
					else {
						int z;
						int result2 = TRUE;
						for (z = 0; myTargets[z] != NULL || z < MAXFLOORSINPUT; z++) {
							if (myTargets[z] == input) {
								printf("\nYou have already inputted that floor, please enter a valid number.\n");
								result2 = FALSE;
								break;
							}
						}
						if (result2 == TRUE) {
							myTargets[a] = input;
							break;
						}
						
					}
					
				}
			}
		}
	}


	int b;
	for (b = 0; b < floorCount; b++) {
		

		if (myTargets[b] < currentFloor->data) {

			currentFloor = currentFloor->prev;
			while (TRUE) {

				if (currentFloor->data != myTargets[b]) {
					printf("%d", currentFloor->data);
					printf(" ");
					currentFloor = currentFloor->prev;
				}
				else if(currentFloor->data == myTargets[b]) {
					printf("%d", currentFloor->data);
					printf(" Ding!\n");
					break;
				}
			}
		}
		else if (myTargets[b]> currentFloor->data) {
			currentFloor = currentFloor->next;
			while (TRUE) {
				if (currentFloor->data != myTargets[b]) {
					printf("%d", currentFloor->data);
					printf(" ");
					currentFloor = currentFloor->next;
				}
				else if (currentFloor->data == myTargets[b]) {
					printf("%d", currentFloor->data);
					printf(" Ding!\n");
					break;
				}
			}
		}
		
	}
	return currentFloor;
}

void RepeatFloor(struct Node* currentFloor) {
#define MAXYESNO 4
	printf("\nWould you like to go to another floor?\n");
	printf("YES or NO\n");
	char str[MAXYESNO];
	
	fgets(str, MAXYESNO, stdin);
	
	if (strcmp(str, "YES") == 0) {
		ChangeFloor(currentFloor);
	}
	if (strcmp(str, "NO\n") == 0) {
		printf("hello");
		//break;
	}
	else {
		printf("\nPlease enter either YES or NO");
		RepeatFloor(currentFloor);
	}
	
}

void StartElevator() {
	int floors[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	int currentFloor = 0;
	printf("You are on floor ");
	printf("%d", currentFloor);
	ChangeFloor(currentFloor);
}


void print_list(struct Node* n)
{
	while (n != NULL) {
		printf("%d\n", n->data);
		
		if (n->next != NULL) {
			n = n->next;
		}
		else {
			break;
		}
	}
}
int main() {
	//int floors[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };


	struct Node* head = NULL;
	struct Node* last = NULL;
	struct Node* currentFloor = NULL;

	head = (struct Node*)malloc(sizeof(struct Node));
	last = (struct Node*)malloc(sizeof(struct Node));
	currentFloor = (struct Node*)malloc(sizeof(struct Node));
	
	head->data = BOTTOMFLOOR;



	currentFloor = head;


	int v;
	for (v = BOTTOMFLOOR; v <= TOPFLOOR; v++) {
		if (v == BOTTOMFLOOR){
			head->prev = NULL;
			last = head;
		}
		else if (v == TOPFLOOR) {
			struct Node* tail = (struct Node*)malloc(sizeof(struct Node));
			tail->data = v;
			tail->prev = last;
			tail->next = NULL;
			last->next = tail;
		}
		else {
			struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
			new_node->data = v;
			new_node->prev = last;
			last->next = new_node;
			last = new_node;

		}
	}

	//print_list(head);

	printf("You are on floor ");
	printf("%d", currentFloor->data);
	currentFloor = ChangeFloor(currentFloor);
	
	RepeatFloor(currentFloor);
	return 0;
}


