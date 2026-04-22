#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

// Allocate Memory & Struct & Excercise

// 1.1
void ReadFileEx11(float **a,float **b, int *n, int *m, char *fileName) {
	FILE *f;
	int i;

	if((f=fopen(fileName,"rt"))==NULL) {
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

void WriteEx11(float **a, int n, char P) {
	printf("\nDa thuc %c(x)= %.1f",P, *(*a));
	for(int i=1; i<=n; i++) printf(" + %.1fx^%d", *(*a+i), i);
}

void ex11() {
	float *a, *b;
	int n,m;
	ReadFileEx11(&a, &b, &n,&m, "input.txt");

	WriteEx11(&a,n, 'P');
	WriteEx11(&b,m, 'Q');
}


int main() {
	ex11();
}
