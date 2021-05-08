#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 10
typedef int Element;
int front;
int rear;
Element data[MAX_SIZE];

void init_deque() { front = rear = 0; }
int size() { return (rear - front + MAX_SIZE) % MAX_SIZE; }
int is_empty() { return (front == rear); }
int is_full() { return (front == ((rear + 1) % MAX_SIZE)); }

void add_front(Element e)
{
	if (is_full())
		printf("Deque is full!\n");
	else
	{
		data[front] = e;
		front = (front - 1+MAX_SIZE) % MAX_SIZE;
	}
}

void add_rear(Element e)
{
	if (is_full())
		printf("Deque is full!\n");
	else
	{
		rear = (rear + 1) % MAX_SIZE;
		data[rear] = e;
	}
}

Element delete_front()
{
	if (is_empty())
	{
		printf("Deque is empty!\n");
		return -100;
	}
	else
	{
		front = (front + 1) % MAX_SIZE;
		return data[front];
	}
}

Element delete_rear()
{
	Element ret;
	if (is_empty())
	{
		printf("Deque is empty!\n");
		return -100;
	}
	else
	{
		ret = rear;
		rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
		return data[ret];
	}
}

Element get_front()
{
	if (is_empty())
	{
		printf("Deque is empty!\n");
		return -100;
	}
	else
	{
		return data[(front+1)%MAX_SIZE];
	}
}

Element get_rear()
{
	if (is_empty())
	{
		printf("Deque is empty!\n");
		return -100;
	}
	else
	{
		return data[rear];
	}
}

void print_deque(char msg[])
{
	int i, start;
	start = (front + 1) % MAX_SIZE;
	printf("%s[%d] =\t", msg, size());
	if (is_empty())
		printf("Deque is empty!\n");
	else if (start > rear)
	{
		for (i = start; i < MAX_SIZE; i++)
			printf("%2d\t", data[i]);
		for (i = 0; i <= rear; i++)
			printf("%2d\t", data[i]);
		printf("\n");
	}
	else
	{
		for (i = start; i <=rear; i++)
			printf("%2d\t", data[i]);
		printf("\n");
	}
}

int main(void)
{
	int i, num;
	init_deque();
	for (i = 1; i < 10; i++)
	{
		if (i % 2 == 0)
			add_rear(i);
		else
			add_front(i);
	}
	print_deque("Current Queue");

	printf("Delete Front : %d\n", delete_front());
	printf("Delete Rear : %d\n", delete_rear());
	print_deque("Current Queue");
	printf("First Element : %d\n", get_front());
	printf("Last Element : %d\n", get_rear());

	printf("Enter the number : ");
	scanf("%d", &num);
	getchar();
	add_front(num);
	add_rear(num);
	print_deque("Current Queue");
	getchar();
	return 0;
}
