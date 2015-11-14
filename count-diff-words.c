#include<stdio.h>
#include<string.h>

int main()
{
	char in[120];
	char word[100][100];
	int p=0;
	int i,j;
	int len;
	int start=0,end;
	int count=0;

	gets(in);
	len=strlen(in);
	for(i=0;i<=len;++i)
	{
		if(in[i]==' '||in[i]=='\0')
		{
			end=i;
			strncpy(word[p],in+sizeof(char)*start,end-start);
			start=i+1;
			++p;
		}
	}
	count=p;
	for(i=0;i<p;++i)
	{
		if(!strcmp(word[i],""))
			continue;
		for(j=i+1;j<=p;j++)
		{
			if(!strcmp(word[i],word[j]))
			{
				--count;
				strcpy(word[j],"");
			}
		}
	}
	printf("%d",count);
	return 0;
}

