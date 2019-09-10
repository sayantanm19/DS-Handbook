//
// DS Handbook
// Singly Linked List Operations
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
   newNode->data = value;
   if(head == NULL)
   {
      newNode->next = NULL;
      head = newNode;
   }
   else
   {
      newNode->next = head;
      head = newNode;
   }
   printf("\nNode inserted successfully at beginning\n");
}

void insertAtEnd(int value)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   newNode->next = NULL;
   if(head == NULL)
      head = newNode;
   else
   {
      struct Node *temp = head;
      while(temp->next != NULL)
	temp = temp->next;
      temp->next = newNode;
   }
   printf("\nNode inserted successfully at end\n");
}

void insertPosition(int value, int pos)
{
   int i = 0;
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   if(head == NULL)
   {
      newNode->next = NULL;
      head = newNode;
   }
   else {
        struct Node *temp = head;
        for (i = 0; i < pos - 1; i++) {
            temp = temp-> next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
   }

   printf("\nNode inserted successfully\n");
}

void removeBeginning()
{
   if(head == NULL)
	printf("\n\nList is Empty");
   else
   {
      struct Node *temp = head;
      if(head->next == NULL)
      {
	      head = NULL;
	      free(temp);
      }
      else
      {
         head = temp->next;
         free(temp);
         printf("\nNode deleted at the beginning\n\n");
      }
   }
}

void removeEnd()
{
   if(head == NULL)
   {
      printf("\nList is Empty\n");
   }
   else
   {
      struct Node *temp1 = head,*temp2;
      if(head->next == NULL)
         head = NULL;
      else
      {
         while(temp1->next != NULL)
         {
             temp2 = temp1;
             temp1 = temp1->next;
         }
         temp2->next = NULL;
      }
      free(temp1);
      printf("\nNode deleted at the end\n\n");
   }
}

void removePosition(int pos)
{
   int i,flag = 1;

   if (head==NULL)
        printf("List is empty");
   else {
       struct Node *temp1 = head, *temp2;
       if (pos == 1) {
            head = temp1->next;
            free(temp1);
            printf("\nNode deleted\n\n");
       }
       else {
           for (i = 0; i < pos - 1; i++)
           {
             if (temp1 -> next != NULL) {
                 temp2 = temp1;
                 temp1 = temp1 -> next;
             }
             else {
                flag = 0;
                break;
             }
           }
           if (flag) {
               temp2 -> next = temp1 -> next;
               free(temp1);
               printf("\nNode deleted\n\n");
           }
           else {
               printf("Position exceeds number of elements in linked list. Please try again");
           }
       }
    }
}

void search(int key)
{
    while (head != NULL)
    {
        if (head->data == key)
        {
            printf("The key is found in the list\n");
            return;
        }
        head = head->next;
    }
    printf("The Key is not found in the list\n");
}

void display()
{
   if(head == NULL)
   {
      printf("\nList is Empty\n");
   }
   else
   {
      struct Node *temp = head;
      printf("\n\nList elements are - \n");
      while(temp->next != NULL)
      {
	 printf("%d --->",temp->data);
	 temp = temp->next;
      }
      printf("%d --->NULL",temp->data);
   }
}


int main()
{
   int choice,value,choice1,pos,del,key;
   while(1){
   printf("\n\nSingly Linked List Operations\n");
   printf("1. Insert at beginning\n2. Insert at End\n3. Insert at location\n4. Delete at beginning\n5. Delete at End\n6. Delete at location\n7. Search\n8. Display\n9. Exit\n\nEnter your choice:  ");
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
                printf("Enter the position after which you want to insert: ");
                scanf("%d",&pos);
                insertPosition(value,pos);
                break;
      case 4: 	removeBeginning();
                break;
      case 5: 	removeEnd();
                break;
      case 6:   printf("Enter the value which you want to delete: ");
                scanf("%d",&pos);
				removePosition(pos);
				break;
	  case 7:   printf("Enter the value which you want to search: ");
                scanf("%d",&key);
				search(key);
				break;
      case 8:   display();
                break;
      case 9:   exit(0);
      default: printf("\nWrong Choice, Please try again\n\n");
            }
        }
}

