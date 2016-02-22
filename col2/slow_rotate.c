#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void swap_vec(char *vec1, char *vec2, int length)
{
	for(int i = 0; i < length; i++)
	{
		vec1[i] ^= vec2[i];
		vec2[i] ^= vec1[i];
		vec1[i] ^= vec2[i];
	}
}

void rotate_vec_recursive(char *vec, size_t size, size_t rot)
{
	// Recursively swap sections of a vec so that it is in effect rotated to the left rot times.
	// if we want to rotate the vec rot times, we can break if into two segments, a and b, where a is rot
	// items long. Now there are four cases for the size of b:
	// 1. len(b) = 0. No rotation is necessary
	// 2. len(b) = len(a). Swap and we are done
	// 3. len(a) > len(b).
	//   1. Split up a into a_l and a_r, where len(a_r) = len(b)
	//   2. Swap a_l and b. b is in its final place
	//   3. Now [a_r, a_l] must be rotated (recurse)
	// 4. len(a) < len(b).
	//   1. Split up b into b_l and b_r, where len(b_r) = len(a).
	//   2. Swap a and b_r. a is in its final place
	//   3. Now [b_r, b_l] must be rotated (recurse)
	printf("Rotating %.*s to the left by %d\n", (int)size, vec, (int)rot);
	rot = rot % size; // Rotating by more than the full length will just loop around
	if(rot == 0) // Case 1
	{
		return;
	}
	else if (rot * 2 == size) // Case 2
	{
		swap_vec(vec, vec + rot, rot);
	}
	else if(rot * 2 > size) // Case 3
	{
		// Swap a_l with b
		swap_vec(vec, vec + rot, size - rot);
		// Now rotate [a_r, a_l] by 2 * rot - size
		rotate_vec_recursive(vec + size - rot, rot, 2 * rot - size);
	} else { // Case 4
		// Swap a with b_r
		swap_vec(vec, vec + size - rot, rot);
		// Now rotate [b_r, b_l] by rot
		rotate_vec_recursive(vec, size - rot, rot);
	}

}

int main(int argc, char*argv[])
{
	char vec[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', '\0'};
	int n = 4;
	int l = strlen(vec);

	rotate_vec(vec, l, n);
	printf("%s\n", vec);
	rotate_vec(vec, l, l-n);
	printf("%s\n", vec);

	// Should be back to normal now
	rotate_vec_recursive(vec, l, n);
	printf("%s\n", vec);
	rotate_vec_recursive(vec, l, l-n);
	printf("%s\n", vec);
}
