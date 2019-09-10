//
// DS Handbook
// Doubly Linked List Operations
//

#include<stdio.h>
#include<stdlib.h>

struct Node
{
   int data;
   struct Node *previous, *next;
}*head = NULL;

void insertAtBeginning(int value)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = value;
    newNode -> previous = NULL;
    if(head == NULL)
    {
       newNode -> next = NULL;
       head = newNode;
    }
    else
    {
       newNode -> next = head;
       head -> previous = newNode;
       head = newNode;
    }
    printf("\nInsertion successful");
}

void insertAtEnd(int value)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode -> data = value;
   newNode -> next = NULL;
   if(head == NULL)
   {
      newNode -> previous = NULL;
      head = newNode;
   }
   else
   {
      struct Node *temp = head;
      while(temp -> next != NULL)
         temp = temp -> next;
      temp -> next = newNode;
      newNode -> previous = temp;
   }
   printf("\nInsertion successful");
}

void insertAfter(int value, int pos)
{
   int i, flag = 1;
   struct Node *newNode, *temp = head;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode -> data = value;
   if(head == NULL)
   {
      newNode -> previous = newNode -> next = NULL;
      head = newNode;
   }
   else
   {
    for (i = 0; i < pos - 1; i++) {
        temp = temp -> next;
        if (temp -> next == NULL) {
            flag = 0;
            break;
        }
    }

    if (flag) {
        newNode -> next = temp -> next;
        temp -> next -> previous = newNode;
        temp -> next = newNode;
        newNode -> previous = temp;
        printf("\nInsertion successful\n");
    }
    else
        printf("Number of elements is less than position entered");
   }
}

void deleteBeginning()
{
   if(head == NULL)
      printf("List is Empty");
   else
   {
      struct Node *temp = head;
      if(temp -> previous == temp -> next)
      {
         head = NULL;
         free(temp);
      }
      else{
         head = temp -> next;
         head -> previous = NULL;
         free(temp);
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
      struct Node *temp = head;
      if(temp -> previous == temp -> next)
      {
         head = NULL;
         free(temp);
      }
      else{
         while(temp -> next != NULL)
            temp = temp -> next;
         temp -> previous -> next = NULL;
         free(temp);
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
      struct Node *temp = head;
      while(temp -> data != delValue)
      {
         if(temp -> next == NULL)
         {
            printf("\nGiven node is not found in the list");
         }
         else
         {
            temp = temp -> next;
         }
      }
      if(temp == head)
      {
         head = NULL;
         free(temp);
      }
      else
      {
         temp -> previous -> next = temp -> next;
         free(temp);
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
      printf("NULL <--- ");
      while(temp -> next != NULL)
      {
         printf("%d <===> ",temp -> data);
         temp = temp -> next;
      }
      printf("%d ---> NULL", temp -> data);
   }
}


int main()
{
   int choice, value, pos;
   while(1)
   {
      printf("\nDoubly Linked List Operations\n");
      printf("1. Insert at beginning\n2. Insert at End\n3. Insert at location\n4. Delete at beginning\n5. Delete at End\n6. Delete specific node\n7. Display\n8. Exit\n\nEnter your choice:  ");
      scanf("%d",&choice);
      switch(choice)
      {
         case 1: printf("Enter the value to be inserted: ");
         		 scanf("%d",&value);
         		 insertAtBeginning(value);
                 break;
         case 2: printf("Enter the value to be inserted: ");
         		 scanf("%d",&value);
                 insertAtEnd(value);
                 break;
         case 3: printf("Enter the value to be inserted: ");
         		 scanf("%d",&value);
                 printf("Enter the position after which you want to insert: ");
                 scanf("%d",&pos);
                 insertAfter(value,pos);
                 break;
         case 4: deleteBeginning();
                 break;
         case 5: deleteEnd();
                 break;
         case 6: printf("Enter the Node value to be deleted: ");
                 scanf("%d",&pos);
                 deleteSpecific(pos);
                 break;
         case 7: display();
                 break;
         case 8: exit(0);
		 default: printf("\nWrong Choice, Please try again\n\n");
      }
   }
}

