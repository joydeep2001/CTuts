#include<stdio.h>
void change(int x, int y);
int main()
{
	int a[7] = {5, 1, 4, 9, 6, 3, 7};


	//a[0] =1
	//a][1] =5
	//bubble sort
	//it1
	//1 4 5 6 3 7 9
	//it2
	//1 4 5 3 6 7 9
	//it3
	//1 4 3 5 6 7 9
	//it4
	//1 3 4 5 6 7 9
	//it5
	//1 3 6 7 9 
	int i, j, k;
	int n = 7;
	for(i = 0;i < n - 1;i++) {
		for(j = 0;j < n - (i + 1);j++) {
			if(a[j] > a[j + 1]) {
				int temp;
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
		for(k = 0;k < n;k++)
			printf("%d ", a[k]);
		printf("\n");
	}
	printf("Final Result: \n");
	for(i = 0;i < n;i++)
		printf("%d ", a[i]);
}



//10