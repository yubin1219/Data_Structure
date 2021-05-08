#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct LinkedNode {
	char data[81];
	struct LinkedNode* link;
}Node;

int is_empty(Node** phead)
{
	return (*phead == NULL);
}

int size(Node** phead)
{
	Node* p;
	int cnt = 0;
	for (p = *phead; p != NULL; p = p->link)
		cnt++;
	return cnt;
}

void print_list(Node** phead)
{
	Node* p;
	int i = 0;
	printf("\n");
	for (p = *phead; p != NULL; i++, p = p->link)
	{
		if (i<10)
			printf("0%d: %s\n", i, p->data);
		else
			printf("%d: %s\n", i, p->data);
	}
	if (i == 0)
		printf("Line is empty!");
	printf("\n");
}

Node* get_entry(Node** phead, int pos)
{
	Node* n = *phead;
	int i;
	for (i = 0; i < pos; i++, n = n->link)
	{
		if (n == NULL)
			return NULL;
	}
	return n;
}


void insert_next(Node* prev, Node* n)
{
	if (n != NULL)
	{
		n->link = prev->link;
		prev->link = n;
	}
}

void insert(Node** phead,int pos, char val[])
{
	Node* new_node, *prev;
	new_node = (Node*)malloc(sizeof(Node));
	new_node->link = NULL;
	strcpy(new_node->data, val);

	if (*phead == NULL)
		*phead = new_node;
	else
	{
		if (pos == 0)
		{
			new_node->link = *phead;
			*phead= new_node;
		}
		else
		{
			prev = get_entry(phead, pos - 1);
			if (prev != NULL)
				insert_next(prev, new_node);
		}
	}
}

Node* remove_next(Node* prev)
{
	Node* removed = prev->link;
	if (removed != NULL)
		prev->link = removed->link;
	return removed;
}

void delete(Node** phead, int pos)
{
	Node* prev, *removed;
	if (pos == 0 && is_empty(phead) == 0)
	{
		removed = *phead;
		*phead = (*phead) ->link;
		free(removed);
	}
	else
	{
		prev = get_entry(phead, pos - 1);
		if (prev != NULL)
		{
			removed = remove_next(prev);
			free(removed);
		}
	}
}

int main(void)
{
	char a[81];
	int num, pos, i;
	Node* head = NULL;
	
	while (1)
	{
		printf("[Menu 1.Display 2.Line Insert 3.Line Delete 0.Exit]: ");
		scanf("%d", &num);
		getchar();

		if (num == 1)
			print_list(&head);

		else if (num == 2)
		{
			printf(" Line Number : ");
			scanf("%d", &pos);
			getchar();

			if (size(&head) < pos)
				printf(" Wrong Line Number!!\n");
			else
			{
				printf(" Input Strings : ");
				fgets(a, sizeof(a), stdin);
				a[strlen(a) - 1] = '\0';
				insert(&head, pos, a);
			}
		}

		else if (num == 3)
		{
			if (is_empty(&head))
				printf(" Line is Emtpy!!\n");
			else
			{
				printf(" Line Number : ");
				scanf("%d", &pos);
				getchar();

				if (size(&head) <= pos)
					printf(" Wrong Line Number!!\n");
				else
					delete(&head, pos);
			}
		}

		else if (num == 0)
			break;
	}
	getchar();
	return 0;
}
