#include<stdio.h>
//global variable
int a, b, c;

void sum()
{
	//local variable
	int z;
	
	c = a + b;
}
int main()
{
	//local variable
	int d;
	
	printf("Enter the value of a: ");
	
	scanf("%d", &a);

	printf("Enter the value of b: ");
	scanf("%d", &b);

	sum();
	printf("The sum is: %d", c);

}