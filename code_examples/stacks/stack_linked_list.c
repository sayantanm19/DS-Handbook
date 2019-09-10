//
// DS Handbook
// Stack Implemented Using Linked List
//

#include<stdio.h>
#include<stdlib.h>

struct Node
{
   int data;
   struct Node *next;
} *top = NULL;

void push(int value)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   if(top == NULL)
      newNode->next = NULL;
   else
      newNode->next = top;
   top = newNode;
   printf("\nInsertion is Successful\n");
}

void pop()
{
   if(top == NULL)
      printf("\nUnderflow. Stack is empty\n");
   else{
      struct Node *temp = top;
      printf("\nDeleted element is: %d", temp->data);
      top = temp->next;
      free(temp);
   }
}

void display()
{
   if(top == NULL)
      printf("\nStack is Empty\n");
   else{
      struct Node *temp = top;
      while(temp->next != NULL){
	 printf("%d--->",temp->data);
	 temp = temp -> next;
      }
      printf("%d--->NULL",temp->data);
   }
}

int main()
{
   int choice, value;
   printf("\nStack using Linked Lists\n");
   while(1){
      printf("\nStack Using Linked List\n");
      printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice){
         case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &value);
            push(value);
            break;
         case 2: 
            pop();
            break;
         case 3:    
            display();
            break;
         case 4:    
            exit(0);
         default: printf("\nWrong Choice, Please try again\n\n");
      }
   }
}
