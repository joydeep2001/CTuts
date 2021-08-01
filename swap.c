#include<stdio.h>
void change(int x, int y);
int main()
{

	int x, y;
	
	x = 5;
	y = 6;
	
	int z;
	z = x;
	x = y;
	y = z;
	
	printf("x = %d and y = %d", x, y); //output

}

void swap(int x, int y) //here b is parameter
{
	
}
//10