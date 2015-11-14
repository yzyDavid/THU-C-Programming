#include<stdio.h>

int main()
{
	char c[100];
	int count=1;
	int i=0;
	gets(c);
	while(c[i]!='\0')
	{
		if(' '==c[i])
			count++;
		i++;
	}
	printf("%d",count);
	return 0;
}
