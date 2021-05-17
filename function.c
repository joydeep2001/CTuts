#include<stdio.h>

int powerCal(int a, int p)
{
	int result = 1;
	int i;
	for(i = 1;i <= p;i++)
		result = result * a;

	return result;
}

int main()
{
	int a;
	int power;
	printf("Enter a number: ");
	scanf("%d", &a);
	printf("Enter the power: ");
	scanf("%d", &power);
	
	int result = powerCal(a, power);

	result += 5;
	int result2 = powerCal(result, power);

	printf("Result is: %d", result2);
	return 0;
}

