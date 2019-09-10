# include<stdio.h>
# define MAX 5

int deque_arr[MAX];
int left = -1;
int right = -1;

void insert_rear()
{
	int added_item;
	if ((left == 0 && right == MAX - 1) || (left == right + 1))
	{	printf("Queue Overflow\n");
		return;}
	if (left == -1)  /* if queue is initially empty */
	{	left = 0;
		right = 0;
	}
	else if(right == MAX - 1)  /*right is at last position of queue */
		right = 0;
	else
		right = right+1;
	printf("Input the element for adding in queue : ");
	scanf("%d", &added_item);
	deque_arr[right] = added_item;
}

void insert_front()
{	int added_item;
	if((left == 0 && right == MAX - 1) || (left == right + 1))
	{	printf("Queue Overflow \n");
		return;	 }
	if (left == -1)/*If queue is initially empty*/
	{	left = 0;
		right = 0;	 
	}
	else if(left== 0)
		left = MAX - 1;
	else
		left = left - 1;
	printf("Input the element for adding in queue : ");
	scanf("%d", &added_item);
	deque_arr[left] = added_item ;	 
}
 
void delete_front()
{	if (left == -1)
	{	printf("Queue Underflow\n");
		return ;	}
	printf("Element deleted from queue is : %d\n",deque_arr[left]);
	if(left == right) /*Queue has only one element */
	{	
		left = -1;
		right = -1;
	}
	else if(left == MAX-1)
		left = 0;
	else
		left = left+1;
}

void delete_rear()
{
if (left == -1)
	{
	printf("Queue Underflow\n");
		return ;
	}
	printf("Element deleted from queue is : %d\n", deque_arr[right]);
	if(left == right) /*queue has only one element*/
	{	
		left = -1;
		right=-1;	 
	}
	else if(right == 0)
		right = MAX - 1;
	else
		right = right - 1;	
}

void display_queue()
{	
	int front_pos = left,rear_pos = right;
	if(left == -1)
	{	
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements :\n");
	if (front_pos <= rear_pos)
	{	while(front_pos <= rear_pos)
		{	printf("%d ",deque_arr[front_pos]);
			front_pos++;
		}
	}
	else
	{	while(front_pos <= MAX-1)
		{	printf("%d ",deque_arr[front_pos]);
			front_pos++;	}
		front_pos = 0;
		while(front_pos <= rear_pos)
		{	printf("%d ",deque_arr[front_pos]);
			front_pos++;
		}
	}
	printf("\n");
}

main()
{	int choice;
	do
	{	printf("1.Insert at left\n");
		printf("2.Insert at right\n");
		printf("3.Delete from left\n");
		printf("4.Delete from right\n");
		printf("5.Display\n");
		printf("6.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{	
		case 1:
			insert_front();
			break;
		case 2:
			insert_rear();
			break;
		case 3:
			delete_front();
			break;
		case 4:
			delete_rear();
			break;
		case 5:
			display_queue();
            break;
        case 6:
        	exit(0);
        	break;
		default:
			printf("Wrong choice\n");
		}
	}while(choice!=5);
}
/*End of main*/
