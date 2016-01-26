#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
	int temp;
	while (b != 0)
	{
		temp = a % b;

		a = b;
		b = temp;
	}
	return a;
}

void rotate_vec(char *vec, size_t size, size_t rot)
{
	int i, j, from_index, to_index;
	// We have so do the whole shuffle gcd(size, rot) times
	for(int i = 0; i < gcd(size, rot); i++) {
		char temp = vec[i];
		to_index = i;
		from_index = i;
		do {
			to_index = from_index;
			from_index = (to_index + rot) % size;

			if(from_index == i) // If we've looped pack to the temp
			{
				vec[to_index] = temp;
				break;
			} else {
				vec[to_index] = vec[from_index];
			}
			to_index = from_index;
		} while(1);
	}
}

int main(int argc, char*argv[])
{
	char vec1[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', '\0'};
	size_t n = sizeof(vec1)-1; // -1 to account for the null byte
	size_t i = 3;

	printf("%s\n", vec1);
	rotate_vec(vec1, n, i);
	printf("%s\n", vec1);
}
