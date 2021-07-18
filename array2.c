#include<stdio.h>
int main()
{

	int a[5];
	//a[0],a[1]...a[4]
	printf("%u\n", &a[0]); //222
	printf("%u\n", &a[1]); //226
	printf("%u\n", &a[2]); //230
	return 0;

}
