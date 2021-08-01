#include<stdio.h>
void change(int x, int y);
int main()
{

	int x, y;
	
	x = 5;
	y = 6;
	
	x = x + y; 
	y = x - y; 
	x = x - y; 
	
	printf("x = %d and y = %d", x, y); //output

}

