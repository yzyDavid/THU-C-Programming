#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node
{
	int n;
	struct node *p;
} stu;

int main()
{
	int m, n;
	int i;
	stu *head = NULL;
	stu *next = NULL;
	stu *cache = NULL;
	scanf("%d%d", &n, &m);
	head = (stu*) malloc(sizeof(stu));
	head -> n = 1;
	next = head;
	assert(head);
	assert(head -> n);
	assert(!head -> p);
	for (i = 2; i <= n; i++)
	{
		next -> p = (stu*) malloc(sizeof(stu));
		next -> p -> n = i;
		assert(next);
		assert(next -> p);
		next = next -> p;
	}
	next -> p = head;
	assert(head);
	assert(next);
	assert(next -> p);
	assert(head -> p);

	i = 0;

	while (next -> p != next)
	{
		i++;
		if (i == m)
		{
			i = 1;
			cache = next -> p -> p;
			free(next -> p);
			next -> p = cache;
		}
		next = next -> p;
	}

	printf("%d\n", next -> n);

	return 0;
}
