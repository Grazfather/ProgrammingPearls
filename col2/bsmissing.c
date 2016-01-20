#include <stdio.h>
#include <stdlib.h>

int measure_halves(char*, int, int);

int main(int argc, char* argv[])
{
	printf("Missing number: %d\n", measure_halves("nums.txt", 0, 0));
}

int measure_halves(char* fn, int n, int missing)
{
	int num;
	int l = 0;
	int r = 0;
	char fl_name[10];
	char fr_name[10];
	snprintf(fl_name, 10, "l-%d.txt", n);
	snprintf(fr_name, 10, "r-%d.txt", n);
	FILE *f = fopen(fn, "r");
	FILE *fl = fopen(fl_name, "w");
	FILE *fr = fopen(fr_name, "w");

	// For each number read, split it based on the nth bit
	while(fscanf(f, "%d", &num) != EOF)
	{
		// If doesn't matter if I check the high bit or low bit.
		// I'll check the low bit so I can test on a smaller data set.
		if(num & 0x1 << n) {
			fprintf(fl, "%d\n", num);
			l++;
		} else {
			fprintf(fr, "%d\n", num);
			r++;
		}

	}
	fclose(f);
	fclose(fl);
	fclose(fr);

	// The smaller half contains the missing number. Set the corresponding
	// bit in the solution and continue checking that side.
	if(l > r) {
		printf("Left is bigger than right\n");
		printf("%d\n", missing);
		missing = measure_halves(fr_name, n+1, missing);
	} else if(r > l) {
		printf("Right is bigger than left\n");
		printf("%d\n", missing);
		missing = measure_halves(fl_name, n+1, missing | (1 << n));
	} else {
		printf("Both halves are even! %d\n", l);
	}

	return missing;
}
