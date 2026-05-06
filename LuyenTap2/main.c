#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <string.h>


float** readFile(char *FileName, int *m, int *n) {
	FILE *f = fopen(FileName, "r");

	fscanf(f, "%d %d",m,n);
	float **a = (float **)malloc((*m) * sizeof(float *));

	for(int i = 0; i < *m; i++) {
		a[i] = (float *)malloc((*n) * sizeof(float));
		for(int j = 0; j < *n; j++)	fscanf(f, "%f ", &a[i][j]);
	}
	fclose(f);
	return a;
}

void writeFile(float **a, int m, int n) {
	for(int i =0; i < m; i++) {
		for(int j =0; j <n; j++) printf("%.2f ", a[i][j]);
		printf("\n");
	}
}

float tbAm(float **a, int m, int n) {
	float t = 0;
	int dem = 0;
	for(int i = 0; i< m; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i][j]<0) {
				t+= a[i][j];
				dem++;
			}
		}
	}
	return (dem > 0) ? (t / dem): 0;
}

void timAm(float **a, int m, int n) {
	float max;
	int r = -1, c= -1;
	for(int i = 0; i< m; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i][j] <0) {
				if(r == -1  || a[i][j] > max) {
					max = a[i][j];
					r = i;
					c = j;
				}
			}
		}
	}
	if(r != -1 ) printf("Max by %.2f in row %d at column %d\n", max, r, c);
	else printf("Dont have negative number");
}

void runEx1() {
	int n, m;
	float **a = readFile("inputEx1.txt",&m, &n);
	writeFile(a, m, n);
	float tbc = tbAm(a, m, n);
	printf("TBC phan tu: %.2f\n",tbc);

	timAm(a, m, n);
}
//
typedef struct {
	char TenSach[50];
	int	NamXB;
	float Gia;
} sach;

void *nhap(int *n, char* FileName) {
	FILE *f = fopen(FileName, "r");
	fscanf(f, "%d\n", n);
	sach *sv = (sach*) malloc(sizeof(sach)* (*n+1));

	for(int i  = 0; i< *n; i++) {
		fscanf(f, " %[^\n]\n",sv[i].TenSach);
		fscanf(f, " %d\n", &sv[i].NamXB);
		fscanf(f, " %f\n", &sv[i].Gia);

	}
	fclose(f);
	return sv;
}

void xuat(sach *sv, int n, FILE *f) {
	for(int i = 0; i< n; i++) {
		fprintf(f, "%d  | %s  |%.2f\n", sv[i].NamXB, sv[i].TenSach, sv[i].Gia);
	}
}

void timKiem(sach *sv, int n,  char *timKiem) {
	int check = 0;
	for( int i = 0; i< n; i++) {
		if(strstr(sv[i].TenSach, timKiem) != NULL) {
			printf("%d  | %s  | %.2f\n", sv[i].NamXB, sv[i].TenSach, sv[i].Gia);
			check = 1;
		}
	}
	if(check == 0) printf("Khong tim thay sach can tim");
}

float trungBinh(sach *ds, int n) {
	float t = 0;
	int dem = 0;
	for(int i = 0; i< n; i++) {
		if(ds[i].NamXB >= 2011 && ds[i].NamXB <=2013) {
			t += ds[i].Gia;
			dem++;
		}
	}
	if(dem == 0) return 0;
	return t / dem;
}

void runEx2() {
	int n;
	char tim[100];

	sach *sv = nhap(&n, "inputEx2.txt");
	xuat(sv, n, stdout);

	printf("Nhap ten NXB can tim:");
	fflush(stdin);
	scanf("%[^\n]", tim);
	timKiem(sv, n, tim);

	float bc = trungBinh(sv, n);
	printf("\nTrung binh gia (2011 -2013): %.2f\n", bc);


	//
	FILE *f = fopen("output.txt", "w");
	fprintf(f, "So luong sach: %d\n", n);
	xuat(sv, n,f);
	fclose(f);

	free(sv);
}


int main() {
	runEx1();
	runEx2();
}