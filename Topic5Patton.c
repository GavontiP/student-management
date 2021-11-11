#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdbool.h>
/*
 * Author: Gavonti Patton
 * Purpose: Regis University record management 
 * system for students with the capability to create new records and display the list of current records.
 * Language:  C
 */
struct Student
{
    int id;
    int currentyear;
    char name[50];
    char grade[50];
    struct Student *next;
  
}* head;
// inserts stsudents on to the list
void insert(int id, char* name, char* grade, int p)
{
  
    struct Student * student = (struct Student *) malloc(sizeof(struct Student));
    student->id = id;
    strcpy(student->name, name);
    strcpy(student->grade, grade);
    student->currentyear=p;
    student->next = NULL;
  
    if(head==NULL){
        head = student;
    }
    else{
        student->next = head;
        head = student;
    }
  
}
//enables users to search the linked list for a student using id.
void search(int id)
{
    struct Student * temp = head;
    while(temp!=NULL){
        if(temp->id==id){
            printf("Id Number: %d\n", temp->id);
            printf("Name: %s\n", temp->name);
            printf("grade: %s\n", temp->grade);
            printf("currentyear: %d\n", temp->currentyear);
            return;
        }
        temp = temp->next;
    }
    printf("Student with id %d is not found !!!\n", id);
}
// checks if the id given already exists l.l
bool unique(int id)
{
	bool verified = false;
    struct Student * temp = head;
    while(temp!=NULL){
        if(temp->id==id){
           
            verified=true;
        }
        temp = temp->next;
    }
    return verified;
}
// allows user to change the information associated with an ID number
void update(int r)
{
  
    struct Student * temp = head;
    while(temp!=NULL)
     {
        if(temp->id==r){
            printf("Record with id %d Found !!!\n", r);
            printf("Enter new name: ");
            scanf("%s", temp->name);
            printf("Enter new grade number: ");
            scanf("%s", temp->grade);
            printf("Enter currentyear ");
            scanf("%d",&temp->currentyear);
            printf("Updation Successful!!!\n");
            return;
        }
        temp = temp->next;
      
    }
    printf("Student with id number %d is not found !!!\n", r);
  
}
// Allows user to delete students from the system and frees memory
void Delete(int r)
{
    struct Student * temp1 = head;
    struct Student * temp2 = head;
    while(temp1!=NULL){
      
        if(temp1->id==r){
          
            printf("Record with id number %d Found !!!\n", r);
          
            if(temp1==temp2){
                // this condition will run if
                // the record that we need to delete is the first node
                // of the linked list
                head = head->next;
                free(temp1);
            }
            else{
                // temp1 is the node we need to delete
                // temp2 is the node previous to temp1
                temp2->next = temp1->next;
                free(temp1);
            }
          
            printf("Record Successfully Deleted !!!\n");
            return;
          
        }
        temp2 = temp1;
        temp1 = temp1->next;
      
    }
    printf("Student with id number %d is not found !!!\n", r);
  
}
// displays all of the students in the system
void display()
{
    struct Student * temp = head;
    while(temp!=NULL){
      
        printf("id Number:%d;", temp->id);
        printf("Name:%s;", temp->name);
        printf("grade:%s;", temp->grade);
        printf("currentyear:%d;\n", temp->currentyear);
        temp = temp->next;
      
    }
    printf("\n");
}
int main()
{
    head = NULL;
    int choice;
    char name[10];
    char grade[10];
    int idnumber;
    int currentyear;
    do
    {
    	printf("Welcome to RU record management system\n");
    	printf("0 to exit\t\n1 to create a new Sudent Record\n2 to search for student details\t\n3 to delete student details\t\n4 to update student details\t\n5 to display all student details\n\n");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
    {
            case 1:
                printf("Enter id number: ");
                scanf("%d", &idnumber);
                 if(unique(idnumber))
			{
				  printf("This id number already exists\n\n");
				  break;
            }
            
            	else
            	fflush(stdin);
               printf("Enter name: ");
                scanf("%[^\n]", name);
                printf("Enter average grade of student:");
                 fflush(stdin);
                scanf("%s", grade);
                printf("Enter year of Student: ");
                 fflush(stdin);
				 scanf("%d", &currentyear);
				 printf("\n\n");
				 insert(idnumber, name, grade, currentyear);
                break;
            case 2:
                printf("Enter id number to search: ");
                scanf("%d", &idnumber);
                search(idnumber);
                break;
            case 3:
                printf("Enter id number to delete: ");
                scanf("%d", &idnumber);
                Delete(idnumber);
                break;
            case 4:
                printf("Enter id number to update: ");
                scanf("%d", &idnumber);
                update(idnumber);
                break;
            case 5:
                display();
                break;
        }
      
    } while (choice != 0);
}
