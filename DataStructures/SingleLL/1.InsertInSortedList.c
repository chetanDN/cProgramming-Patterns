/*Tested on VS 2012  */
// DataStructure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>		//DMA


struct Node{
	int data;
	struct Node *next;
};

struct Node* InsertInSortedList(struct Node*,int);
void display(struct Node*);

int main()
{
	int choice,data;
	struct Node *head=NULL;
	
	while(true){
		printf("\n1. Add elements to list?\n");
		printf("2. Display List\n");
		printf("3. Quit\n");
		printf("Enter choice :");
		scanf_s("%d",&choice);

		switch(choice){
		case 1:
			printf("Enter the element to be inserted: ");
			scanf_s("%d",&data);
			head=InsertInSortedList(head,data);	
			break;
		case 2:
			display(head);
			break;
		case 3:
			//exit(0);
			return 0;
		default :
			printf("Wrong choice\n");
		}

	}

	getchar();
	return 0;
}

struct Node* InsertInSortedList(struct Node* head,int data){
	// adding requires one new temp Node to save new data, another current node to itterate over loop using head ptr
	struct Node * temp= (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	//temp->next , depends on where it will point later

	struct Node *current = head;
	//now only to calculate temp->next and head value

	//adding node @ beginning ie either head is null or temp node data is smaller than first node of list
	if( head == NULL || ( (temp->data) < (current->data) ) ){
		temp->next = head;
		return temp;
	}
	else{
		while(current != NULL){ //itterate till end of list using current = current->next;
			//when current node reaches end(this exp check first) or when new node data is smaller than current "next node"(if this is checked first, access violation, if current reached last)  
			if( (current->next == NULL ) || ( (temp-> data) < (current->next->data)) ){
				temp->next = current->next;
				current->next = temp;
				return head;
			}
			current = current->next;
		}//end while
	}// end else

}// end of InsertInSortedList

void display(struct Node*head){
	struct Node *current; // to itterate

	if(head == NULL){
		printf("List Empty");
		return;
	}else{
		current = head;

		while(current != NULL){
			printf("%d ",current->data);
			current = current->next;
		}//end of while
		printf("\n\n");
	}//end of else
}//end of display()

