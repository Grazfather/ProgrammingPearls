// Sort a bunch of numbers in memory
#include <stdio.h>
#include <stdlib.h>

int nums[10000000];

int cmp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

int main(int argc, char* argv[])
{
	int i = 0;

	while(scanf("%d", &nums[i]) != EOF)
	{
		i++;
	}

	qsort(nums, sizeof(nums)/sizeof(int), sizeof(int), cmp);

	for(i = 0; i < sizeof(nums)/sizeof(int); i++)
	{
		printf("%d\n", nums[i]);
	}
	return 0;
}
