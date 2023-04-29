#include<stdio.h>
//top_down
int nWay(int n){
	if(n==1) return 1;
	if(n==2) return 2;
	int k1=1, k2=2, k;
	for(int i=3;i<=n;i++){
		k=k1+k2;
		k1=k2;
		k2=k;
	}
	return k2;
}

//bottom-up
int nWay1(int n){
	if(n==1) return 1;
	if(n==2) return 2;
	return nWay1(n-1)+nWay1(n-2);
}



int main(){
	int n;
	printf("Nhap so m: "); scanf("%d",&n);
	printf("Co %d cach di.",nWay(n));
	printf("\nCo %d cach di.",nWay1(n));
}
