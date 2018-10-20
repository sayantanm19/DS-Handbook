//
// DS Handbook
// Various Array Operations
//

#include <stdio.h>
#include <stdlib.h>

int n = 0; // global variable to hold number of elements currently in array

void display_array(int arr[100])
{
  int i;
  if (n == 0) {
    printf("There are no elements currently in the array\n\n");
  }
  else {
      printf("The array currently is: ");
      for(i = 0; i < n; i++)
        printf("\n arr[%d] = %d", i, arr[i]);
      printf("\n\n");
  }
}

void insert_position(int arr[]) {
    int i = 0, pos, num;
    printf("Enter the number to be inserted : ");
    scanf("%d", &num);
    printf("Enter position at which the number is to be added :");
    scanf("%d", &pos);
    for (i = n-1; i>= pos; i--)
        arr[i+1] = arr[i];
    arr[pos] = num;
    n = n + 1;
    display_array(arr);
}

void delete_position(int arr[]) {
    int i, pos;
    printf("\nEnter the position from which the number has to be deleted : ");
    scanf("%d", &pos);
    for (i = pos; i<n-1; i++)
        arr[i] = arr[i+1];
    n = n - 1; // decrease total number of used elements
    display_array(arr);
}


int main() {
    int ch, arr[100];
    while (1) {
        printf("\n\n1D Array Operations Menu\n");
        printf("1. Insert into position\n2. Delete from position\n3. Display the Array\n4. Exit\n\n");
        scanf("%d", &ch);
        switch(ch){
            case 1: insert_position(arr);
                    break;
            case 2: delete_position(arr);
                    break;
            case 3: display_array(arr);
                    break;
            case 4: exit(0);
            default: printf("Wrong choice, please try again");
        }
    }
    return 0;
}

