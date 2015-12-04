#include <stdio.h>
#include <string.h>

void p(char b[]);

int main()
{
	char a[1000];
	scanf("%s", a);
	p(a);
	return 0;
}

void p(char b[])
{
	char c[1000];
	char deleted[100];		/*这个数组存储已经处理过的字符的列表*/
	int pDeleted = 0;
	int len, flag;
	int i, j, k = 0, l;
	len = strlen(b);
	for (i = 0; i < len; ++i)	/*第一次遍历，将需要被“压缩”掉的字符用空字符0替换*/
	{
		if (b[i] != ' ')		/*空格直接跳过*/
		{
			flag = 0;
			for (j = 0; j < pDeleted; ++j)		/*判断这个字符是否已经处理过*/
				if (b[i] == deleted[pDeleted])
					flag = 1;
			if (!flag)
			{
				deleted[pDeleted++] = b[i];		/*记录这个字符，避免重复操作*/
				l = 0;
				for (j = i; j < len ; ++j)
				{
					if (b[j] == b[i])
					{
						l++;
						if (l != 1 && l != 3 && l != 6)
							b[j] = 0;
					}
				}
			}
		}
	}
	for (i = 0; i < len; ++i)	/*这个循环进行拷贝*/
		if (b[i] != 0)
			c[k++] = b[i];
	c[k] = 0;
	printf("%s", c);
}
