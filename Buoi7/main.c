#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <string.h>
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

int main() {
	int n;
	char tim[100];

	sach *sv = nhap(&n, "input.txt");

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