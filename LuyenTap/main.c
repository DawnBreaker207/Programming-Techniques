#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <string.h>
// Bai 1
void ReadFile(float **a,float **b, int *n, int *m, char *fileName) {
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
void Write(float *a, int n, char P) {
	printf("\nDa thuc %c(x)= %.1f",P, (*a));
	for(int i=1; i<=n; i++) printf(" + %.1fx^%d", (*a+i), i);

}
//
float calValue(float *a, int n, float d) {
	int i;
	float P = a[0];
	for(i = 1; i<= n; i++) P = P + a[i]*pow(d,i);
	return P;
}

//
void runEx1() {
// 1
	float *a, *b, P, Q, d1, d2, *c;
	int n,m, k;
	ReadFile(&a, &b, &n,&m, "inputEx1.txt");

	Write(&a,n, 'P');
	Write(&b,m, 'Q');

//	2
	printf("\nInput d1 and d2: ");
	scanf("%f%f", &d1, &d2);
	P = calValue(a, n,d1);
	Q = calValue(b, m,d2);

	if(Q == 0) printf("Can not cal S because Q(d2) = 0\n");
	else printf("S = %.3f\n", P / Q);

// 3 R(x)= P(x) - Q(x)
	if(n>m) {
		k=n;
		c= ((float*)calloc(k+1,sizeof(float)));
		for(int i=0; i<=m; i++) c[i]=a[i] - b[i];
		for(int i=m+1; i<=k; i++) c[i]=a[i];
		printf("\nValue point R(x)=P(x)-Q(x):");
		Write(c, k,'R');
	}
	if(m>n) {
		k=m;
		c= ((float*)calloc(k+1,sizeof(float)));
		for(int i=0; i<=n; i++) c[i]=a[i] - b[i];
		for(int i=n+1; i<=k; i++) c[i]= -b[i];
		printf("\nValue point R(x)=P(x)-Q(x):");
		Write(c, k,'R');
	}
	if(n==m) {
		c= ((float*)calloc(n+1,sizeof(float)));
		for(int i=0; i<=n; i++) c[i]= a[i] - b[i];
		k=0;
		for(int i=0; i<=n; i++)
			if(c[i]!= 0) k=i;
		printf("\nValue point R(x)=P(x)-Q(x):");
		Write(c, k,'R');
	}
}



// Bai 2
typedef struct {
	float gia;
	char ts[50], nxb[50];
} sach;

void *nhap(int *n, char *FileName) {
	FILE *f=fopen(FileName, "r");
	fscanf(f, "%d\n", n);
	sach *sv = (sach*) malloc(sizeof(sach)*(*n+ 1));

	for(int i = 0; i< *n; i++) {
		fscanf(f, " %[^\n]\n", sv[i].ts);
		fscanf(f, " %[^\n]\n", sv[i].nxb);
		fscanf(f, "%f\n", &sv[i].gia);
	}
	fclose(f);
	return sv;
}

void xuat(sach *sv, int n, FILE *f) {
	for(int i = 0; i< n; i++) {
		fprintf(f, "%s | %s | %.2f\n", sv[i].ts, sv[i].nxb, sv[i].gia);
	}
}

int demNXB(int n, sach *sv, char s[]) {
	int d = 0;
	for(int i = 0; i < n; i++)
		if(strcmp(sv[i].nxb, s) == 0)
			d++;

	return d;
}
void sapXepGia(int n, sach *sv) {
	sach tmp;
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			if(sv[i].gia < sv[j].gia) {
				tmp = sv[i];
				sv[i] = sv[j];
				sv[j] = tmp;
			}
		}
	}
}

void runEx2() {
	int n;
	char tim[100];

	sach *sv = nhap(&n, "inputEx2.txt");

	// Yeu cau 2
	printf("Danh sach ban dau:\n");
	xuat(sv,n,stdout);

	// Yeu cau 1
	printf("Nhap ten Nha Xuat Ban can dem: ");
	fflush(stdin);
	scanf("%[^\n]", tim);
	printf("So luong sach cua NXB %s la: %d\n", tim, demNXB(n, sv, tim));

	// Yeu cau 2
	sapXepGia(n, sv);
	printf("\nDanh sach sach sau khi sap xep gia giam dan:\n");
	xuat(sv, n, stdout);

	// Yeu cau 3
	FILE *f = fopen("output.txt", "w");
	fprintf(f, "So luong sach: %d\n", n);
	xuat(sv, n, f);
	fclose(f);

	free(sv);
	return 0;
}

int main() {
	runEx1();
	runEx2();
}