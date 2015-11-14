#include<stdio.h>

int main()
{
	int a[20];
	int n,i=0;
	while(1)
	{
		scanf("%d",&n);
		if(0==n)
			break;
		a[i]=n;
		i++;
	}
	i--;
	for(;i>=0;i--)
	{
		printf("%d",a[i]);
		if(i!=0)
			printf(" ");
	}
	return 0;
}
