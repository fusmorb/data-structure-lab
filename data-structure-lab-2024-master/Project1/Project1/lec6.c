// 목표: 2의 거듭제곱 계산하기 //

#include <stdio.h>
#include <time.h>

double power(double x, int n) {
	double result = 1.0;
	for (int i = 0; i < n; i++) {
		result = result * x;
	}
	return result;
}

double power2(double x, int n) {
	if (n == 0) return 1;
	else if (n % 2 == 0) return power2(x * x, n / 2);
	else return x * power2(x * x, (n - 1) / 2);
}

int main(void) {
	double x = 2.0;
	int n = 1000;
	clock_t start, stop;
	double duration;
	int iter = 100000;

	start = clock();
	for (int i = 0; i < iter; i++) {
		double ret = power(x, n);
	}
	stop = clock();
	duration = (double)(stop - start) / CLOCKS_PER_SEC * 1000; // ms
	printf("%f\n\n", duration);


	start = clock();
	for (int i = 0; i < iter; i++) {
		double ret = power2(x, n);
	}
	stop = clock();
	duration = (double)(stop - start) / CLOCKS_PER_SEC * 1000; // ms
	printf("%f\n\n", duration);

	return 0;
}