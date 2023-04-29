#include<stdio.h>

//a

int S(int a, int l, int r){
	if(l==r) return a;
	int m=(l+r)/2;
	return S(a,l,m) * S(a,m+1,r);
}

//b

int S1(int l, int r){
	if(l==r) return l*l;
	int m=(l+r)/2;
	return S1(l,m) + S1(m+1,r);
}

//c

int S2(int a[], int l, int r){
	if(l==r) return a[l];
	int m=(l+r)/2;
	return S2(a,l,m) + S2(a,m+1,r);
}


int main(){
//	int a, n;
//	printf("Nhap a: ");
//	scanf("%d", &a);
//	printf("Nhap n: ");
//	scanf("%d", &n);
	//printf("%d^%d= %d", a, n, S(a,1,n));
//	printf("%d",S1(1,n));
	int a[]={1,4,5,6,8,9};
	int n=sizeof(a)/sizeof(a[0]);
	printf("%d",S2(a,0,n-1));
	return 1;
}
