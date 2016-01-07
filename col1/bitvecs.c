#include <stdio.h>

int bitfield[2];

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
	bitfield[0] = 0xFFAABB00;
	bitfield[1] = 0xDEADBABE;
	// Expected: 00000000110111010101010111111111
	for(int i = 0; i < (sizeof(bitfield) << 3); i++)
	{
		printf("%d", getbit(i));
	}
	return 0;
}
