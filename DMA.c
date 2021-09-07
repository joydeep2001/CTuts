#include<stdio.h>
#include<stdlib.h>
int k;

int main() 
{
	int* p;
	
	int size;
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	p = (int*)malloc(size); //char p[5]
	printf("Enter the value of the elements: ");
	int i;

	for(i = 0;i < size;i++) {
		
		scanf("%d", (p + i)); 

	}
	printf("The values are : ");

	for(i = 0;i < size;i++){
		
		printf("\n%d", *(p + i)); //p[i] === *(p + i)
	}								
	return 0;
}


/*
Homework

1)Create and Array of size 10 using malloc.
2)Store 10 values in that array

*/