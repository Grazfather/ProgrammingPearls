#include <stdio.h>

#define N 10000000

int bitfield[N / (sizeof(int) << 3)];

int getbit(int index)
{
	int word = index / (sizeof(int) << 3);
	int bit = index % (sizeof(int) << 3);

	return bitfield[word] >> bit & 1;
}

void setbit(int index)
{
	int word = index / (sizeof(int) << 3);
	int bit = index % (sizeof(int) << 3);
	bitfield[word] |= 1 << bit;
}

void clrbit(int index)
{
	int word = index / (sizeof(int) << 3);
	int bit = index % (sizeof(int) << 3);
	bitfield[word] &= ~(1 << bit);
}

int main(int argc, char* argv[])
{
	int num;
	// Clear the whole bitfield
	for(int i = 0; i < N; i++)
		clrbit(i);

	// For each number that comes in, set that bit
	while(scanf("%d", &num) != EOF)
	{
		setbit(num);
	}

	// For each bit, if it's set, print it out
	for(int i = 0; i < N; i++)
	{
		if(getbit(i)) {
			printf("%d\n", i);
		}
	}

	return 0;
}
