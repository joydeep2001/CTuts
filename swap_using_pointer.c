/*What is data type?*/
#include<stdio.h>

void swap(int* k, int* m)
{
	int temp;
	temp = *k;
	
	*k = *m;
	*m = temp;

}

int main()
{

	int k, m;
	k = 8;
	m = 7;
	swap(&k, &m);
	printf("k = %d m = %d", k, m);
}
