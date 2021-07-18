#include<stdio.h>
int phoneBook[200];
int ind;
void save(int);
void display();
int search(int);
void del(int);//prototype

int main()
{
	
	ind = 0;
	int choice;
	printf("Press 1 for Saving a new number\n");
	printf("Press 2 for Deleting a number\n");
	printf("Press 3 for Searching a number\n");
	printf("Press 4 for Displaying all numbers\n");
	
	
	while(1){
		printf("Enter your choice: ");
		scanf("%d", &choice);
		if(choice == 1)
		{
			int number;
			printf("Enter the phone number: ");
			scanf("%d", &number);
			int found = search(number);
			if(found == -1) 
			{
				save(number);
				printf("Saved successfully\n");
			}
			else
				printf("This number already exists\n");
		}
		else if(choice == 2)
		{
			int number;
			printf("Enter the number to be deleted: ");
			scanf("%d", &number);
			del(number);
		}
		else if (choice == 3) 
		{
			int number;
			printf("Enter the number to be search: ");
			scanf("%d", &number);
			int found = search(number);
			if(found != -1)
				printf("The number found\n");
			else
				printf("Number not found\n");
		}
		else if(choice == 4) 
		{
			display();
		}
		else if(choice == 5)
		{
			break;
		}
	}
	return 0;
}

void save(int number)
{
	//ind = 2
	phoneBook[ind] = number;
	ind++;
}
void display()
{
	//ind 2
	//0 1
	int i;
	for(i = 0;i < ind;i++)
		printf("%d\n", phoneBook[i]);
}

int search(int number) 
{
	int i;
	int flag = 0;
	for(i = 0;i < ind;i++)
	{
		if(phoneBook[i] == number)
		{
			return i;
		}
	}
	
	return -1;
		
}

void del(int number)
{
	int del_index = search(number); 
	if(del_index == -1)
	{
		printf("The number doesnot exists\n");
		return;
	}
	int i;
	for(i = del_index;i < ind - 1;i++) 
	{
		phoneBook[i] = phoneBook[i + 1];
	}
	ind--;
	printf("Deleted successfully\n");
}
