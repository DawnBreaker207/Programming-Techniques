#include <stdio.h>
#include <math.h>
// Function


// Excercise

// Factorial
long factorial(int n) {
	long factorial = 1;
	for(int i =1; i <= n; i++) factorial*=i;
	return factorial;
}

void createFactorial() {
	int a;
	printf("Nhap 1 so nguyen: ");
	scanf("%d",&a);
	printf("%d! = %ld",a, factorial(a));
}

void calculate() {
	int x,y;
	char type;

	printf("Enter x: ");
	scanf("%d", &x);
	printf("Enter y: ");
	scanf("%d", &y);
	printf("Enter type: ");
	scanf(" %c", &type);
	switch(type) {
		case '+':
			printf("%d", x+y);
			break;
		case '-':
			printf("%d", x-y);
			break;
		case '*':
			printf("%d", x*y);
			break;
		case '/':
			printf("%d", x/y);
			break;
		case '^':
			printf("%f", pow(x,y));
			break;
		default:
			printf("Try Again");
			break;
	}
}


void findMax() {
	float a,b,c;

	printf("First number: ");
	scanf("%f", &a);
	printf("Second number: ");
	scanf("%f", &b);
	printf("Third number: ");
	scanf("%f", &c);


	float max  = a;
	if(b> max) {
		max = b;

	}
	if(c > max) {
		max = c;
	}

	printf("Max number is %.2f \n", max);

}
double calDistance(double x1, double x2, double y1, double y2) {
	double distance;
	distance = sqrt(pow(x2-x1,2)+ pow(y2-y1,2));
	return distance;
}
void findDistance() {
	double x1,x2,y1,y2;

	printf("Enter localtion A(x1 , y1):");
	printf("x1 = ");
	scanf("%lf", &x1);
	printf("y1 = ");
	scanf("%lf", &y1);

	printf("Enter localtion B(x2 , y2):");
	printf("x2 = ");
	scanf("%lf", &x2);
	printf("y2 = ");
	scanf("%lf", &y2);



	printf("\nDistance between A and B was: %.4f", calDistance(x1,x2,y1,y2));

}

void calAcreage() {
	double x1,x2,x3,y1,y2,y3;

	printf("Enter localtion A(x1 , y1):");
	printf("x1 = ");
	scanf("%lf", &x1);
	printf("y1 = ");
	scanf("%lf", &y1);

	printf("Enter localtion B(x2 , y2):");
	printf("x2 = ");
	scanf("%lf", &x2);
	printf("y2 = ");
	scanf("%lf", &y2);

	printf("Enter localtion C(x3 , y3):");
	printf("x3 = ");
	scanf("%lf", &x3);
	printf("y3 = ");
	scanf("%lf", &y3);


	double a = calDistance(x1,y1,x2,y2);
	double b = calDistance(x2,y2,x3,y3);
	double c = calDistance(x3,y3,x1,y1);

//	Check condition
	if(a + b > c && a +c >b && b + c > a) {
		double p = (a+b+c) /2.0;
		printf("\nAcreage ABC was: %.4lf\n",  sqrt(p * (p-a)*(p-b)*(p-c)) );
	} else {
		printf("\nThree point enter not match to create a triangle!\n");
	}
}


void calStepEquation() {
	float a,b,c;
	printf("ax^2 + bx + c = 0 \n");
	printf("Enter a: ");
	scanf("%f", &a);
	printf("Enter b: ");
	scanf("%f", &b);
	printf("Enter c: ");
	scanf("%f", &c);

	if(a==0) {
		if(b==0) {
			if(c==0) printf("Equation have lots of point");
			else printf("Equation don't have point");
		} else {
			printf("Equation have one point: x= %.2f\n", -c/b);
		}
	} else {
		float delta = b*b -4 *a*c;
		if(delta < 0) {
			printf("Equation don't have any point\n");
		} else if(delta = 0) {
			float x = -b /(2*a);
			printf("Equation have double point: x = %.2f\n ",x);
		} else {
			float x1  = (-b + sqrt(delta)) / (2*a);
			float x2  = (-b - sqrt(delta)) / (2*a);
			printf("Equation have two difference point \n");
			printf("x1= %.2f\n",x1);
			printf("x2= %.2f\n",x2);
		}
	}

}

void checkPrime() {
	int n;
	printf("Enter number to check prime: ");
	scanf("%d", &n);

	if(n < 2) {
		printf("Number is not a prime\n");
		return;
	}
	for(int i =2; i<= sqrt(n); i++) {
		if(n % i == 0) {
			printf("Number is not a prime\n");
			return;
		}
	}

	printf("Number is a prime\n");
}

void checkPerfect() {
	int n;
	printf("Enter number to check perfect: ");
	scanf("%d", &n);

	if(n <= 0) {
		printf("Number is not perfect\n");
		return;
	}
	int sum = 0;
	for(int i =1; i<= n /2; i++) {
		if(n%i == 0)sum += i;
	}

	printf("Number is perfect");
}

void calFibonacci() {
	int n;
	printf("\nEnter n to find Fibonacci: ");
	scanf("%d", &n);
	if(n <= 0) {
		printf("N wasn't right\n");
		return;
	}
	if(n == 1) {
		printf("N wasn't right\n");
		return;
	}
	long long a =0, b=1, temp;
	for(int i =2; i<= 0; i++) {
		temp = a+b;
		a = b;
		b= temp;
	}
	printf("So Fibonacci number %d was %lld\n", n, b);
}

void calDoubleSquare() {
	double n;
	printf("\nEnter number to calculate double square: ");
	scanf("%lf", &n);
	if(n< 0) {
		printf("Wrong number\n");
		return;
	}
	printf("Double square of %.2f was %.4f\n",n, sqrt(n));
}
int main() {
//	createFactorial();
//	calculate();
//	findMax();
//	findDistance();
//	calAcreage();
//	calStepEquation();
//	checkPrime();
//	checkPerfect();
//	calFibonacci();
	calDoubleSquare();
	return 0;
}
