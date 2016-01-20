#include <stdio.h>

void reverse_vec(char *vec, int len)
{
	for(int i = 0; i < len/2; i++)
	{
		// XOR Swap
		vec[i] ^= vec[len-i-1];
		vec[len-i-1] ^= vec[i];
		vec[i] ^= vec[len-i-1];
	}
}

void rotate_vec(char* vec, int len, int rot)
{
	// First reverse vec[0..rot-1]
	reverse_vec(vec, rot);
	// Then reverse vec[rot..len-1]
	reverse_vec(&vec[rot], len-rot);
	// Finally reverse vec[0..len-1] (whole vector)
	reverse_vec(vec, len);

}

int main(int argc, char* argv[])
{
	char vec[9] = "abcdefgh";

	printf("Vector first: %s\n", vec);
	rotate_vec(vec, sizeof(vec) -1, 3);
	printf("Vector after: %s\n", vec);

	return 0;
}
