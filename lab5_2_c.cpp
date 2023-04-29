#include<stdio.h>

int max_index(int a[], int l, int r, int &index){
	if(l==r){
		index=l;
		return a[l];
	}
	int m=(l+r)/2;
	int b,c;
	int max1=max_index(a,l,m,b);
	int max2=max_index(a,m+1,r,c);
	if(max1>max2) {
		index=b;
		return max1;
	}
	else {
		index=c;
		return max2;
	}
}

int main(){
	int a[]={2,7,9,3,5,0};
	int n=sizeof(a)/sizeof(a[0]);
	int index;
	max_index(a,0,n-1,index);
	printf("Phan tu lon nhat la %d o vi tri %d",max_index(a,0,n-1,index),index);
	return 1;
}
