#include <stdio.h>
# Arrays
void binary() {
	int n;
	printf("Nhap so: ");
	scanf("%d",&n);

	if(n ==0) {
		printf("0\n");
		return;
	}

	int binary[32];
	int i = 0;

	while(n > 0) {
		binary[i++] = n % 2;
		n /= 2;
	}

	for(int j = i -1; j >= 0; j--) {
		printf("%d", binary[j]);
	}
}

int isPrime(int n) {
	if(n<2) return 0;
	for(int i =2; i* i <= n; i++) {
		if(n%i == 0) return 0;

	}
	return 1;
}

void firstNPrimes() {
	int n;
	printf("Nhap N: ");
	scanf("%d",&n);

	int count = 0,num = 2;

	while(count < n) {
		if(isPrime(num)) {
			printf("%d ",num);
			count++;
		}
		num++;
	}
	printf("\n");
}


void count() {
	int x,y,z;
	int count = 0;
	
	for(z = 0; z<=40; z++) {
		for(y=0; y<=100; y++) {
			int remain = 200 - 5*z -2*y;
			if(remain >=0) {
				x= remain;
				printf("x=%d, y=%d z=%d\n",x,y,z);
				count++;
			}
		}
	}
	printf("Tong so phuong an: %d\n",count);

}
int main() {

	int choice;

	do {
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				binary();
				break;
			case 2:
				firstNPrimes();
				break;
			case 3:
				count();
				break;
			case 0:
				break;
			default:
				printf("Selected Again !!!");
		}
	} while(choice != 0);
	return 0;
}


