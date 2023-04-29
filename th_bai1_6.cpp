#include<stdio.h>

void Nhap(int a[][100], int &n){
	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);
	while(n <= 2 || n >= 10){
		printf("Nhap lai so luong phan tu: ");
		scanf("%d", &n);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	}
} 

void diem_yenngua(int a[][100], int n){
	for(int i = 0; i < n; i++){
		int max = a[i][0];
		int flagd, flagc;
		for(int j = 0; j < n; j++){
			if(a[i][j] > max){
				max = a[i][j];
				flagd = i;
				flagc = j;
			}
		}
		int min = a[0][flagc];
		for(int j = 0; j < n; j++){
			if(a[j][flagc] < min){
				min = a[j][flagc];
			}
		}
		if(min == max) printf("\nPhan tu a[%d][%d]", flagd, flagc);
	}
}

void diemyenngua(int a[][100], int n){
	for(int i = 0; i < n; i++){
		int max = a[i][0];
		int flag=1;
		int flagd;
		int flagc;
		for(int j = 0; j < n; j++){
			if(a[i][j] > max){
				max = a[i][j];
				flagd=i;
				flagc=j;
			}
			
		}
		int min=a[flagd][flagc];
		for(int j=0;j<n;j++){
			if(a[j][flagc]<min){
				flag=0;
				break;
			}
		}
		if(flag) printf("\nPhan tu a[%d][%d]", flagd, flagc);
	}
} 

int main(){
	int a[100][100];
	int n;
	Nhap(a, n);
//	diem_yenngua(a, n);
	diemyenngua(a,n);
	return 1;
}








