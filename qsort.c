#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void quick_sort(int*, int, int);
void swap(int*, int*);

int main()
{
	int a[20];
	int n = 0;
	int i = 0;
	do
	{
		scanf("%d",&a[n++]);
	}
	while(a[n - 1] != 0);
	n--;
	quick_sort(a, 0, n - 1);
	for(; i < n; i++)
		printf("%d\t", a[i]);
	return 0;
}

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void quick_sort(int arr[], int begin, int end)
{
	int m = arr[end];
	int left, right;
	left = begin;
	right = end - 1;
	if (begin >= end)
		return;
	while (left < right)
	{
		while (arr[left] < m && left < right)
		{
			left++;
		}
		while (arr[right] >= m && left < right)
		{
			right--;
		}
		swap(&arr[left], &arr[right]);
	}

	if (arr[left] >= arr[end])
		swap(&arr[left], &arr[end]);
	else
		left++;

	quick_sort(arr, begin, left - 1);
	quick_sort(arr, left + 1, end);
}
