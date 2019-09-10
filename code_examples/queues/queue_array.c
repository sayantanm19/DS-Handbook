//
// DS Handbook
// Queue Implemented Using Array
//

#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int queue[SIZE], front = -1, rear = -1;

void enQueue(int value) {
   if(rear == SIZE-1)
      printf("\nOverflow. Queue is Full.");
   else{
      if(front == -1)
	 front = 0;
      rear++;
      queue[rear] = value;
      printf("\nInsertion was successful");
   }
}

void deQueue() {
   if(front == rear)
      printf("\nUnderflow. Queue is Empty.");
   else{
      printf("\nDeleted item is: %d", queue[front]);
      front++;
      if(front == rear)
	 front = rear = -1;
   }
}

void display() {
   if(rear == -1)
      printf("\nQueue is Empty!");
   else{
      int i;
      printf("\nQueue elements are:\n");
      for(i = front; i<=rear; i++)
	 printf("%d\t",queue[i]);
   }
}

void main()
{
   int value, choice;
   while(1) {
      printf("\nQueue Using Arrays\n");
      printf("1. Insertion\n2. Deletion\n3. Display\n4. Exit");
      printf("\nEnter your choice: ");
      scanf("%d",&choice);
      switch(choice) {
         case 1: 
            printf("Enter the value to be inserted: ");
            scanf("%d",&value);
            enQueue(value);
            break;
         case 2: 
            deQueue();
            break;
         case 3: 
            display();
            break;
         case 4: exit(0);
         default: printf("\nWrong Choice, Please try again\n\n");
      }
   }
}
