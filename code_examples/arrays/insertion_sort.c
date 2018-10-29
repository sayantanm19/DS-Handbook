//
// DS Handbook
// Insertion Sort
//

#include<stdio.h>

int main()
{
	int data[100],n,temp,i,j;
	printf("Enter number of elements to be sorted:");
	scanf("%d",&n);
	printf("Enter elements: ");
	for(i = 0; i < n; i++)
		scanf("%d",&data[i]);
	for(i = 1; i < n; i++)
	{
		temp = data[i];
		j = i - 1;
		while(temp < data[j] && j>=0)
		{
			data[j + 1] = data[j];
			j = j - 1;
		}
		data[j + 1]=temp;
	}
	printf("Sorted array: ");
	for(i = 0; i < n; i++)
		printf("%d  ",data[i]);
    return 0;
}
