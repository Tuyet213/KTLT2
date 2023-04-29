#include<stdio.h>
#include<math.h>

int ktSNT(int n){
	if(n < 2) return 0;
	int m = sqrt(n);
	for(int i = 2; i <= m; i++)
		if(n % i == 0) return 0;
	return 1;
}

int main(){
	int n;
	int dem = 0;
	printf("Nhap gia tri n: ");
	scanf("%d", &n);
	while(n <= 0 || n > 10000){
		printf("Nhap lai gia tri n: ");
		scanf("%d", &n);
	}
	for(int i = 2; i < n; i++)
		if(ktSNT(i)) dem++;
	printf("So cac so nguyen to nho hon %d la: %d", n, dem);
	return 1;
}
