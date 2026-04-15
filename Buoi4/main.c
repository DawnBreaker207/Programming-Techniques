#include <stdio.h>
#include <math.h>
// Pointer

void swap(int *a, int *b) {
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

void implSwap() {
	int a= 10, b= 6;
	printf("Before: a=%d b=%d \n", a, b);
	swap(&a, &b);
	printf("After: a=%d b=%d \n", a, b);
}
void test(int *a, int b) {
	*a =b;
	*a+=b++;
}

void implTest() {
	int x,y;
	test(&x,y=2);
	printf("%d %d",x,y);
}


int stepEquation(float a,float b, float c, float *x1, float *x2) {
	float delta;
	if(a==0) {
		return -1;
	}
	delta = b*b -4 *a*c;
	if(delta < 0) {
		printf("Equation don't have any point\n");
		return 0;
	} else if(delta == 0) {
		*x1 = *x2 = -b/(2*a);
		return 1;
	} else {
		*x1  = (-b + sqrt(delta)) / (2*a);
		*x2  = (-b - sqrt(delta)) / (2*a);
		return 2;
	}

}

void implStepEquation() {
	float x,y,z,a,b;
	int result;
	printf("\nEnter input: \n");
	scanf("%f", &x);
	scanf("%f", &y);
	scanf("%f", &z);

	result = stepEquation(x,y,z, &a,&b);

	if(result < 0) {
		printf("Not a step equation");
	} else if(result == 0) {
		printf("Empty step equation");
	} else if( result == 1) {
		printf("Step equation have double value x1=x2=%.1f", a);

	} else if(result == 2) {
		printf("Step equation have two value x1=%.lf x2=%.1f", a, b);
	}

}
// Homework


void implRunSum() {
	int arr[] = {10, 20, 30, 40, 50};
	int n =5;
	int*ptr =arr;
	long sum = 0;

	for(int i =0; i< n; i++) {
		sum+= *(ptr +1);

		printf("Result: %ld\n\n", sum);
	}
}

void implPalidrome() {
	int arr[] = {1,2,3,2,1};
	int n = 5;
	int *ptr =arr;
	int isPalindrome = 1;
	for(int i= 0; i< n/2; i++) {
		if(*(ptr+i) != *(ptr + n -1 - i)) {
			isPalindrome = 0;
			break;
		}

		if(isPalindrome) {
			printf("Result");
		} else {
			printf("Result");
		}
	}
}


void implSelectionSort() {
	int arr[] = {64, 25, 12,22,11};
	int n = 5;

	int*ptr = arr;
	for(int i = 0; i< n -1; i++) {
		int min_idx = i;
		for(int j = i+ 1; i< n; j++) {
			if(*(ptr + j) < *(ptr + min_idx)) min_idx = j;
		}
		int temp = *(ptr + min_idx);
		*(ptr+ min_idx) = *(ptr + i);
		*(ptr + i) = temp;

	}

	for (int i = 0; i < n; i++) printf("%d ", *(ptr + i));
}


void implBubbleSort() {
	int arr[] = {5,1,4,2,8};
	int n = 5;
	int *ptr =arr;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (*(ptr + j) > *(ptr + j + 1)) {
				int temp = *(ptr + j);
				*(ptr + j) = *(ptr + j + 1);
				*(ptr + j + 1) = temp;
			}
		}
	}
	for (int i = 0; i < n; i++) printf("%d ", *(ptr + i));
}

void implBinaryInsertionSort() {
	int arr[] = {37, 23, 0, 17, 12, 72, 31, 46, 100, 88};
	int n = 10;
	int *ptr = arr;

	for (int i = 1; i < n; i++) {
		int key = *(ptr + i);
		int left = 0, right = i - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (key < *(ptr + mid)) right = mid - 1;
			else left = mid + 1;
		}
		for (int j = i - 1; j >= left; j--) {
			*(ptr + j + 1) = *(ptr + j);
		}
		*(ptr + left) = key;
	}
	for (int i = 0; i < n; i++) printf("%d ", *(ptr + i));
}

void implVector5D() {
	double v1[5] = {1.5, 2.0, 3.0, 1.2, 0.5};
	double v2[5] = {2.0, 1.0, 0.5, 3.0, 4.0};
	double sumV[5];
	double dotProduct = 0, magnitudeV1 = 0;

	for (int i = 0; i < 5; i++) {
		sumV[i] = v1[i] + v2[i];
		dotProduct += v1[i] * v2[i];
		magnitudeV1 += v1[i] * v1[i];
	}
	for(int i=0; i<5; i++) printf("%.1f ", sumV[i]);
	printf("\nDot Product: %.2f", dotProduct);
	printf("\nMagnitude of V1: %.2f\n\n", sqrt(magnitudeV1));
}
int main() {
//	implSwap();
//	implTest();
//	implStepEquation();
//	implSelectionSort();
//	implBubbleSort();
//	implBinaryInsertionSort();
//	implVector5D();
}