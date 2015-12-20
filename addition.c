#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*	input example
 *	
 *	79846 2
 *
 */

unsigned long min = -1;
unsigned long len;
char n[30];

void f(int start, int m, unsigned long part)
{
	int i;
	char sub[30];
	unsigned long add;
	unsigned long partsum;
	if (m == 0)
	{
		if (start != len)
			return;
		if (part < min)
			min = part;
		return;
	}
	for (i = start; i < len - m + 1; i++)
	{
		strncpy(sub, &n[start], i - start + 1);
		sub[i-start+1] = 0;
		add = atoi(sub);
		partsum = part + add;
		f(i + 1, m - 1, partsum);
	}
}

int main()
{
	int m;
	scanf("%s%d", n, &m);
	len = strlen(n);
	f(0, m + 1, 0);
	printf("%lu", min);
	return 0;
}

