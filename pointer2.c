#include<stdio.h>

void inc(int* p)
{
	*p = *p + 1; 

}

int main()
{
	int a = 1;
	inc(&a);
	printf("%d", a);

}

/*
	HOme work
	write a function to decrement the value of
	a variable in main function.
*/