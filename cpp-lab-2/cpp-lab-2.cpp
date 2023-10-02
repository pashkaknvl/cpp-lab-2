#include <stdio.h>

long int fuctorial_2(long int x) {
	long int result = 1;

	for (int i = x; i > 0; i -= 2) {
		result *= i;
	}
	
	return result;
}

long double stepen(long double bs, int poww) {
	long double result = 1;

	for (int i = 0; i < poww; i++) {
		result *= bs;
	}

	return result;
}

long double getT(long double x) {
	long double znam = 0;

	for (int i = 0; i < 10; i++) {
		long double s_znam = fuctorial_2(i * 2);
		long double s_chis = stepen(x, 2 * i);
		znam += s_chis / s_znam;
	}
	long double chis = 0;

	for (int i = 0; i < 10; i++) {
		long double s_znam = fuctorial_2(i * 2 + 1);
		long double s_chis = stepen(x, 2 * i + 1);
		chis += s_chis / s_znam;
	}

	return chis / znam;
}

long double getRes(long double y) {
	long double znam = 6 - getT(y * y - 1);
	long double chis = 7 * getT(0.25) + 2 * getT(1 + y);
	
	return chis / znam;
}

int main() {
	long double y;
	printf("Enter y:");
	scanf("%Lf", &y);

	printf("Answer: %.10Lf", getRes(y));
}
