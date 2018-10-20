//
// DS Handbook
// Queue Implemented Using Linked Lists
//

#include<stdio.h>

struct Node
{
   int data;
   struct Node *next;
}*front = NULL,*rear = NULL;

void enQueue(int value)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   newNode -> next = NULL;
   if(front == NULL)
      front = rear = newNode;
   else{
      rear -> next = newNode;
      rear = newNode;
   }
   printf("\nInsertion is Successful\n");
}

void deQueue()
{
   if(front == NULL)
      printf("\nUnderflow. Queue is Empty\n");
   else{
      struct Node *temp = front;
      front = front -> next;
      printf("\nDeleted element: %d\n", temp->data);
      free(temp);
   }
}

void display()
{
   if(front == NULL)
      printf("\nQueue is Empty!\n");
   else{
      struct Node *temp = front;
      while(temp->next != NULL){
	 printf("%d--->",temp->data);
	 temp = temp -> next;
      }
      printf("%d--->NULL\n",temp->data);
   }
}

void main()
{
   int choice, value;
   while(1){
      printf("\nQueue Implemented using Linked List\n");
      printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice){
	 case 1: printf("Enter the value to be inserted: ");
             scanf("%d", &value);
             enQueue(value);
             break;
	 case 2: deQueue();
             break;
	 case 3: display();
             break;
	 case 4: exit(0);
	 default: printf("\nWrong choice. Please try again\n\n");
      }
   }
}

