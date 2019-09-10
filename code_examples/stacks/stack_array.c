//
// DS Handbook
// Stack Implemented Using Array
//

#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

int stack[SIZE], top = -1;

void push(int value) {
   if(top == SIZE-1)
      printf("\nOverflow. Stack is Full");
   else{
      top++;
      stack[top] = value;
      printf("\nInsertion was successful");
   }
}

void pop() {
   if(top == -1)
      printf("\nUnderflow. Stack is empty");
   else{
      printf("\nDeleted : %d", stack[top]);
      top--;
   }
}

void peek() { 
   if(top == -1)
   {
      printf("\n The stack is empty");
      break;
   }
   else
      printf("%d", stack[top]);
}

void display() {
   if(top == -1)
      printf("\nStack is Empty!");
   else{
      int i;
      printf("\nStack elements are:\n");
      for(i = top; i >= 0; i--)
	 printf("%d\n", stack[i]);
   }
}

int main()
{
   int value, choice;
   while(1){
      printf("\n\nStack Using Array\n");
      printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit");
      printf("\nEnter your choice: ");
      scanf("%d",&choice);
      switch(choice){
	      case 1: 
            printf("Enter the value to be inserted: ");
            scanf("%d",&value);
            push(value);
            break;
	      case 2: 
            pop();
            break;
	      case 3: 
            peek();
		      break;
	      case 4: 
            display(0);
            break;
         case 5:
            exit(0);
         default: printf("\nWrong Choice, Please try again\n\n");
      }
   }
}
