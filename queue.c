#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 8

typedef int Element;
Element data[MAX_SIZE];

int front;
int rear;

void init_queue() { front = rear = 0; }
int size() { return (rear-front+MAX_SIZE)%MAX_SIZE; }
int is_empty() { return front == rear; }
int is_full() { return ((front%MAX_SIZE) == ((rear + 1) % MAX_SIZE)); }

void enqueue(Element e)
{
	if (is_full())
		printf("Queue is full!\n");
	else
	{
		rear = (rear + 1) % MAX_SIZE;
		data[rear] = e;
	}
}

Element dequeue()
{
	if (is_empty())
	{
		printf("Queue is empty!");
		return -100;
	}
	front = (front + 1) % MAX_SIZE;
	return data[front];
}

Element peek()
{
	if (is_empty())
	{
		printf("Queue is empty!");
		return -100;
	}
	return data[(front + 1)%MAX_SIZE];
}

void print_queue(char msg[])
{
	int i,start,finish;
	printf("%s[%d] =\t", msg, size());
	start = (front + 1) % MAX_SIZE;
	finish = rear;

	if (is_empty())
		printf("Queue is empty!\n");

	else if (start > finish)
	{
		for (i = start; i <MAX_SIZE ; i++)
		{
			printf("%2d\t", data[i]);
		}
		for(i=0;i<=finish;i++)
			printf("%2d\t", data[i]);

		printf("\n");
	}
	
	else
	{
		for (i = start; i <=finish ; i++)
		{
			printf("%2d\t", data[i]);
		}
		printf("\n");
	}
}

int main(void)
{
	int i, num;
	init_queue();
	print_queue("Current Queue");
	for (i = 0; i < 7; i++)
		enqueue(i+1);
	print_queue("Current Queue");
	printf("front=%d, rear= %d\n", front,rear);
	printf("Fist dequeue : %d\n", dequeue());
	printf("Second dequeue : %d\n", dequeue());
	print_queue("After dequeue twice");
	printf("Enter the number :");
	scanf("%d", &num);
	getchar();
	enqueue(num);
	print_queue("Queue");

	printf("Enter the number :");
	scanf("%d", &num);
	getchar();
	enqueue(num);
	print_queue("Queue");

	printf("Enter the number :");
	scanf("%d", &num);
	getchar();
	enqueue(num);
	print_queue("Queue");

	getchar();

	return 0;
}
