//
// DS Handbook
// Circular Linked List Operations
//

#include<stdio.h>
#include<stdlib.h>

struct Node
{
   int data;
   struct Node *next;
} *head = NULL;

void insertAtBeginning(int value)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = value;
    if(head == NULL)
    {
       head = newNode;
       newNode -> next = head;
    }
    else
    {
       struct Node *temp = head;
       while(temp -> next != head)
          temp = temp -> next;
       newNode -> next = head;
       head = newNode;
       temp -> next = head;
    }
    printf("\nInsertion successful");
}

void insertAtEnd(int value)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode -> data = value;
   if(head == NULL)
   {
      head = newNode;
      newNode -> next = head;
   }
   else
   {
      struct Node *temp = head;
      while(temp -> next != head)
         temp = temp -> next;
      temp -> next = newNode;
      newNode -> next = head;
   }
   printf("\nInsertion successful");
}

void insertAfter(int value, int location)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode -> data = value;
   if(head == NULL)
   {
      head = newNode;
      newNode -> next = head;
   }
   else
   {
      struct Node *temp = head;
      while(temp -> data != location)
      {
         if(temp -> next == head)
         {
            printf("Given node is not found in the list");
         }
         else
         {
            temp = temp -> next;
         }
      }
      newNode -> next = temp -> next;
      temp -> next = newNode;
      printf("\nInsertion successful");
   }
}

void deleteBeginning()
{
   if(head == NULL)
      printf("List is Empty");
   else
   {
      struct Node *temp = head, *last = NULL;
      if(temp -> next == head)
      {
         head = NULL;
         free(temp);
      }
      else{
        while(temp -> next != head)
            temp = temp -> next;
        last = temp;
        temp = head;
        head = head -> next;
        free(temp);
        last -> next = head;
      }
      printf("\nDeletion successful");
   }
}

void deleteEnd()
{
   if(head == NULL)
      printf("List is Empty");
   else
   {
      struct Node *temp1 = head, *temp2;
      if(temp1 -> next == head)
      {
         head = NULL;
         free(temp1);
      }
      else{
         while(temp1 -> next != head){
            temp2 = temp1;
            temp1 = temp1 -> next;
         }
         temp2 -> next = head;
         free(temp1);
      }
      printf("\nDeletion successful");
   }
}

void deleteSpecific(int delValue)
{
   if(head == NULL)
      printf("List is Empty");
   else
   {
      struct Node *temp1 = head, *temp2;
      while(temp1 -> data != delValue)
      {
         if(temp1 -> next == head)
         {
            printf("\nGiven node is not found in the list");
         }
         else
         {
            temp2 = temp1;
            temp1 = temp1 -> next;
         }
      }
      if(temp1 -> next == head){
         head = NULL;
         free(temp1);
      }
      else{
         if(temp1 == head)
         {
            temp2 = head;
            while(temp2 -> next != head)
               temp2 = temp2 -> next;
            head = head -> next;
            temp2 -> next = head;
            free(temp1);
         }
         else
         {
            if(temp1 -> next == head)
            {
               temp2 -> next = head;
            }
            else
            {
               temp2 -> next = temp1 -> next;
            }
            free(temp1);
         }
      }
      printf("\nDeletion successful");
   }
}

void display()
{
   if(head == NULL)
      printf("\nList is Empty");
   else
   {
      struct Node *temp = head;
      printf("\nList elements are: \n");
      while(temp -> next != head)
      {
         printf("%d ---> ",temp -> data);
         temp = temp -> next;
      }
      printf("%d ---> %d", temp -> data, head -> data);
   }
}

int main()
{
   int choice,value,choice1,pos,del;
   while(1){
   printf("\n\nCircular Linked List Operations\n");
   printf("1. Insert at beginning\n2. Insert at End\n3. Insert at location\n4. Delete at beginning\n5. Delete at End\n6. Delete at location\n7. Display\n8. Exit\n\nEnter your choice:  ");
   scanf("%d",&choice);
   switch(choice)
   {
      case 1: 	printf("Enter the value to be insert: ");
                scanf("%d",&value);
                insertAtBeginning(value);
                break;
      case 2: 	printf("Enter the value to be insert: ");
                scanf("%d",&value);
                insertAtEnd(value);
                break;
      case 3:   printf("Enter the value to be insert: ");
                scanf("%d",&value);
                printf("Enter the element after which you want to insert: ");
                scanf("%d",&pos);
                insertAfter(value,pos);
                break;
      case 4: 	deleteBeginning();
                break;
      case 5: 	deleteEnd();
                break;
      case 6:   printf("Enter the element after which you want to delete: ");
                scanf("%d",&pos);
				deleteSpecific(pos);
				break;
      case 7:   display();
                break;
      case 8:   exit(0);
      default: printf("\nWrong Choice, Please try again\n\n");
        }
    }
}

