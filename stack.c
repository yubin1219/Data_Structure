#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 8
typedef int Element;
int top ;
Element data[MAX_SIZE];

void init_stack() { top = -1; }
int is_empty() { return (top == -1); }
int is_full() { return (top == MAX_SIZE - 1); }
int size() { return top+1; }

void push(Element e)
{
	if (is_full())
		printf("Stack is full");
	else
	{
		data[++top] = e;
	}
}

Element pop()
{
	if (is_empty())
		return -100;
	return data[top--];
}

Element peek()
{
	if (is_empty())
		return -100;
	return data[top];
}	

void print_stack(char msg[])
{
	int i;
	printf("%s[%d] = ", msg, size());
	for (i = 0; i < size(); i++)
	{
		printf("%2d\t", data[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, num;
	init_stack();
	for (i = 0; i < MAX_SIZE; i++)
		push(i + 1);
	print_stack("Stack Push 8");
	printf("First pop() : %d\n", pop());
	printf("Second pop() : %d\n", pop());
	print_stack("After pop twice");
	printf("Enter the number :");
	scanf("%d", &num);
	getchar();
	push(num);
	print_stack("Stack data");

	getchar();
	return 0;
}
