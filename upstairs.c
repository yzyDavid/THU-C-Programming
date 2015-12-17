#include <stdio.h>

int f(int);

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", f(n));
	return 0;
}

int f(int n)
{
	switch (n)
	{
		case 1:
			return 1;
		case 2:
			return 2;
		case 3:
			return 4;
		default:
			return f(n - 1) + f(n - 2) + f(n - 3);
	}
}
