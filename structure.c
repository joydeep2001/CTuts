#include<stdio.h>

struct Student {
	char sec;
	int roll;
	float marks;
};
typedef struct Student student;

int main() {
	student s;
	s.sec = 65;
	s.roll = 10;
	s.marks = 80.50;

	printf("Sect: %c ", s.sec);
	printf("Roll: %d ", s.roll);
	printf("Marks: %.2f ", s.marks);



}
//booking id : int
//price : float
//Rating : char
