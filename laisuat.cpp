#include<stdio.h>

float T(int n){
	if(n==0)
	return 100;
	return T(n-1)*1.06;
	
}
int main(){
	int n;
	printf("Nhap so nam:");
	scanf("%d",&n);
	printf("So tien lai sau %d nam la:%f", n, T(n));
	return 0;
}
