// assign during initialization
int marks[10] = {5, 10, 20, 30, 40, 60};

// assign after initialization
int marks[10];

marks[0] = 5;
marks[1] = 10;

// garbage values
int ages[10];

// accessing array without assigning elements first
for(int i = 0; i < 10; i++)
	printf("\n arr[%d] = %d", i, ages[i]);

// access elements forloop
for(int i = 0; i < arraySize; i++)
	printf("\n arr[%d] = %d", i, arr[i]);
}

// assign and display
int id[10];

// assigning values using a loop

for (int i = 0; i < 10; i++) {
	printf("\nEnter an id: ");
	scanf("%d", &id[i]);
}

// displaying the entered ids

for (int i = 0; i < 10; i++) {
	printf("\n id[%d] = %d", i, id[i]);
}

// inserting and deleting elements
void insert_position(int arr[]) {
    int i = 0, pos, num;
    printf("Enter the number to be inserted : ");
    scanf("%d", &num);
    printf("Enter position at which the number is to be added :");
    scanf("%d", &pos);
    for (i = n-1; i>= pos; i--)
        arr[i+1] = arr[i];
    arr[pos] = num;
    n = n + 1;	// increase total number of used positions
    display_array(arr);
}

void delete_position(int arr[]) {
    int i, pos;
    printf("\nEnter the position from which the number has to be deleted : ");
    scanf("%d", &pos);
    for (i = pos; i<n-1; i++)
        arr[i] = arr[i+1];
    n = n - 1;	// decrease total number of used positions
    display_array(arr);
}


