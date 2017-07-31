#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, c, root1, root2, det;

	printf("a = ");
	scanf("%lf", &a);

	printf("b = ");
	scanf("%lf", &b);

	printf("c = ");
	scanf("%lf", &c);

	if (a != 0) {
		det = (b * b) - (4 * a * c);
		if (det >= 0.0) {
			root1 = (-b + sqrt(det)) / (2 * a);
			root2 = (-b - sqrt(det)) / (2 * a);
			printf("The roots are %.2lf and %.2lf\n", root1, root2);
		}
		else {
			printf("Undetermined.\n");
		}
	}
	else {
		root1 = -c / b;
		printf("The root is %.2lf\n", root1);
	}
	return 0;
}
