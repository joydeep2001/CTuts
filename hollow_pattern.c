/*
1
12
1 3
1 4
12345
*/


/*
homework
    *
   **
  * *
 *  *
***** 


*/



#include<stdio.h>
int main()
{
	int i, j;
	int n = 20;
	for(i = 1;i <= n;i++)
	{
		for(j = 1;j <= i;j++)
		{
			if(i == n)
				printf("*");
			else if(j == 1 || j == i)
				printf("*");
			else 
				printf(" ");
		}
		printf("\n");
	}
}