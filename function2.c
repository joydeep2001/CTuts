#include<stdio.h>
//function prototype
int increment(int p);


int main() {
	int a = 5;

	a = increment(a);//actual argument
	printf("%d", a);
	return 0;
}
//function defination
int increment(int p) { //formal parameter
	p++;
	return p;
}

