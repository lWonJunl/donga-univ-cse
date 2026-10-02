#include <stdio.h>

int main()
{
	const float FSCORE = 589.73456F;

	printf("fscore: %f\n", FSCORE);
	printf("fscore: %.2f\n", FSCORE);
	printf("fscore: %e\n", FSCORE);
	printf("fscore: %E\n", FSCORE);

	return 0;
}