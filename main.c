#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Added a comment 

struct node {
	struct node* prev;
	int id;
    int phno;
	float sal;
	char name[20], dept[10], desg[20];
	struct node* next;
} * head, *temp, *temp1, *temp2;

void create()
{
	int id;
	int phno;
	float sal;
	char name[20], dept[10], desg[20];
	temp = (struct node*)malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->next = NULL;
	printf("\nEnter the information to be inserted: \n");
    printf("ID =");
    scanf("%d", &id);
    printf("Name = ");
    scanf("%s", name);
    printf("Department = ");
    scanf("%s", dept);
    printf("Designation = ");
    scanf("%s", desg);
    printf("Salary = ");
    scanf("%f", &sal);
    printf("Phone no. = ");
    scanf("%d", &phno);
	temp->id= id;
	strcpy(temp->name, name);
	strcpy(temp->dept, dept);
	strcpy(temp->desg, desg);
	temp->sal = sal;
	temp->phno = phno;
}

void Insert_at_beg()
{
  if (head == NULL) {
		create();
		head = temp;
		temp1 = head;
    }
    else {
        create();
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}

void Insert_at_end()
{
	if (head == NULL) {
		create();
		head = temp;
		temp1 = head;
	}

	else {
		create();
		temp1->next = temp;
		temp->prev = temp1;
		temp1 = temp;
	}
}

void Traverse()
{
	temp2 = head;
	if (temp2 == NULL) {
		printf("\n The record list is empty. Please enter data using option '1'\n");
		return;
	}
	while (temp2 != NULL) {
		printf("%d %s %s %s %f %d\n", temp2->id, temp2->name, temp2->dept, temp2->desg, temp2->sal, temp2->phno);
		temp2 = temp2->next;
	}

}

int Delete_at_beg()
{
    struct node* temp;
    temp = head;
    if (temp == NULL) {
        printf("list is empty\n");
        return 0;
    }
    if (temp->next == NULL) {
		printf("Record to be deleted is:\n");
		printf("ID | Name | Department | Designation | Salary | Phone no.\n");
		printf("%d, %s, %s, %s, %f, %d\n", temp->id, temp->name, temp->dept, temp->desg, temp->sal, temp->phno);
		free(temp);
		head = NULL;
    }
    else {
        head=head->next;
        head->prev=NULL;
		printf("Record to be deleted is:\n");
		printf("ID | Name | Department | Designation | Salary | Phone no.\n");
		printf("%d %s %s %s %f %d\n", temp->id, temp->name, temp->dept, temp->desg, temp->sal, temp->phno);
		free(temp);
    }
    
    
}

int Delete_at_end()
{
	struct node* temp;
	temp = head;
	if (temp == NULL) {
		printf("list is empty\n");
		return 0;
	}
	if (temp->next == NULL) {
		printf("Record to be deleted is:\n");
		printf("ID | Name | Department | Designation | Salary | Phone no.\n");
		printf("%d, %s, %s, %s, %f, %d\n", temp->id, temp->name, temp->dept, temp->desg, temp->sal, temp->phno);
		free(temp);
		head = NULL;
	}
	else {
		temp = temp1;
		temp2 = temp1->prev;
		temp2->next = NULL;
		printf("Record to be deleted is:\n");
		printf("ID | Name | Department | Designation | Salary | Phone no.\n");
		printf("%d %s %s %s %f %d\n", temp->id, temp->name, temp->dept, temp->desg, temp->sal, temp->phno);
		free(temp);
		temp1 = temp2;
	}
	return 0;
}


int main()
{

	int choice, n;
	head = NULL;
	temp = temp1 = NULL;
	printf("--------Menu--------\n");
	printf("\n 1.Create a list of 'n' employees");
	printf("\n 2.Display the employee record");
	printf("\n 3.Insert at the beginning");
	printf("\n 4.Insert at the end");
	printf("\n 5.Delete at the beginning");
	printf("\n 6.Delete at the end");
	printf("\n 7.Exit\n");
	printf("\n");
	while (1) {
		printf("\nEnter choice : ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("\n Enter number of employees: ");
			scanf("%d", &n);
			for (int i = 0; i < n; i++)
				Insert_at_end();
			break;
		case 2:
			printf("ID | Name | Department | Designation | Salary | Phone no.\n");
			Traverse();
			break;
		case 3:
			Insert_at_beg();
			break;
		case 4:
			Insert_at_end();
			break;
		case 5:
			Delete_at_beg();
			break;
		case 6:
			Delete_at_end();
			break;
		case 7:
		    exit(0);
			
		default:
			printf("Wrong choice\n");
		}
	}

	return 0;
}
