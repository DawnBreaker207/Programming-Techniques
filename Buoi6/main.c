#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

// Allocate Memory & Struct & Excercise

// 1.1
void ReadFileEx11(float **a,float **b, int *n, int *m, char *fileName) {
	FILE *f;
	int i;

	if((f=fopen(fileName,"rt")) == NULL) {
		printf("Check again, can not find file %s",fileName);
		getch();
		exit(1);
	}
	fscanf(f,"%d%d", n,m); //Read first line
	if((*a = (float*)calloc(*n+1,sizeof(float)))==NULL) {
		printf("Allocate Memory Error");
		getch();
		exit(1);
	}

	for(i=0; i<=*n; i++) fscanf(f, "%f", *a+i);


	if((*b = (float*)calloc(*m+1,sizeof(float)))==NULL) {
		printf("Allocate Memory Error");
		getch();
		exit(1);
	}

	for(i=0; i<=*m; i++) fscanf(f, "%f", *b+i);
	fclose(f);

}

//
void WriteEx11(float *a, int n, char P) {
	printf("\nDa thuc %c(x)= %.1f",P, (*a));
	for(int i=1; i<=n; i++) printf(" + %.1fx^%d", (*a+i), i);

}
//
float calValueEx11(float *a, int n, float d) {
	int i;
	float P = a[0];
	for(i = 1; i<= n; i++) P = P + a[i]*pow(d,i);
	return P;
}

//
void ex11() {
// 1
	float *a, *b, P, Q, d1, d2, *c;
	int n,m, k;
	ReadFileEx11(&a, &b, &n,&m, "input.txt");

	WriteEx11(&a,n, 'P');
	WriteEx11(&b,m, 'Q');

//	2
	printf("\nInput d1 and d2: ");
	scanf("%f%f", &d1, &d2);
	P = calValueEx11(a, n,d1);
	Q = calValueEx11(b, m,d2);

	if(Q == 0) printf("Can not cal S because Q(d2) = 0\n");
	else printf("S = %.3f\n", P / Q);

// 3 R(x)= P(x) - Q(x)
	if(n>m) {
		k=n;
		c= ((float*)calloc(k+1,sizeof(float)));
		for(int i=0; i<=m; i++) c[i]=a[i] - b[i];
		for(int i=m+1; i<=k; i++) c[i]=a[i];
		printf("\nValue point R(x)=P(x)-Q(x):");
		WriteEx11(c, k,'R');
	}
	if(m>n) {
		k=m;
		c= ((float*)calloc(k+1,sizeof(float)));
		for(int i=0; i<=n; i++) c[i]=a[i] - b[i];
		for(int i=n+1; i<=k; i++) c[i]= -b[i];
		printf("\nValue point R(x)=P(x)-Q(x):");
		WriteEx11(c, k,'R');
	}
	if(n==m) {
		c= ((float*)calloc(n+1,sizeof(float)));
		for(int i=0; i<=n; i++) c[i]= a[i] - b[i];
		k=0;
		for(int i=0; i<=n; i++)
			if(c[i]!= 0) k=i;
		printf("\nValue point R(x)=P(x)-Q(x):");
		WriteEx11(c, k,'R');
	}
}


int main() {
	ex11();
}
