#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef struct node
{
	int n;
	struct node *p;
} num;

num* create(char *in);
num* add(num *a, num *b);
void print(num *o);

int main()
{
	char a[110], b[110];
	num *na, *nb;
	scanf("%s%s", a, b);
	na = create(a);
	nb = create(b);
	print(add(na, nb));
	return 0;
}

num* create(char *in)
{
	num *last = NULL;
	num *next = NULL;
	int len = strlen(in);
	int i;
	last = (num*) malloc(sizeof(num));
	next = last;
	for (i = 0; i < len; i++)
	{
		next -> n = (int) in[len-i-1] - '0';
		if (i != len - 1)
			next -> p = (num*) malloc(sizeof(num));
		next = next -> p;
	}
	return last;
}

num* add(num *a, num *b)
{
	num *pa = a;
	num *pb = b;
	num *result = (num*) malloc(sizeof(num));
	num *cur = result;
	int tmp, flag = 0;
	while (pa != NULL && pb != NULL)
	{
		tmp = pa -> n + pb -> n;
		if (flag == 1)
			tmp++;
		flag = tmp / 10 ? 1 : 0;
		tmp %= 10;
		cur -> n = tmp;
		pa = pa -> p;
		pb = pb -> p;
		if (pa != NULL && pb != NULL)
		{
			cur -> p = (num*) malloc(sizeof(num));
			cur = cur -> p;
		}
	}
	if (pa == NULL && pb == NULL)
	{
		if (flag)
		{
			cur -> p = (num*) malloc(sizeof(num));
			cur -> p -> n = 1;
		}
		return result;
	}

	cur -> p = pa == NULL ? pb : pa;
	cur = cur -> p;
	while (flag)
	{
		if (cur -> p == NULL)
			cur -> p = (num*) malloc(sizeof(num));
		cur = cur -> p;
		cur -> n++;
		if (cur -> n == 10)
		{
			cur -> n = 0;
			flag = 1;
		}
		else
		{
			flag = 0;
		}
	}
	return result;
}

void print(num *o)
{
	char rev[110];
	char res[110];
	int i = 0;
	int len;
	num *cur = o;
	do
	{
		rev[i++] = cur -> n + '0';
	}
	while (cur = cur -> p);
	rev[i] = 0;
	len = strlen(rev);
	for (i = 0; i < len; i++)
	{
		res[i] = rev[len-i-1];
	}
	res[i] = 0;
	printf("%s",res);
}
