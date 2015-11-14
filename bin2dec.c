#include <stdio.h>
#include <string.h>

int main()
{
	int n=0,i,l,m=1;
	char b[32];
	gets(b);
	l=strlen(b);
	for(i=l-1;i>=0;i--)
	{
		n+=m*(b[i]-'0');
		m*=2;
	}
	printf("%d",n);
	return 0;
}
