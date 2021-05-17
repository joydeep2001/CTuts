#include<stdio.h>

int main()
{
	/*
	1
	23
	456
	78910
	*/
	int counter = 1;
	int i, j;
	for(i = 1;i <= 4;i++)
	{
		for(j = 1; j <= i;j++)
		{
			printf("%d", counter);
			counter++;
		}
		
		printf("\n");
	}
}
