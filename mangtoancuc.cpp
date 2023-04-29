#include<stdio.h>
int a[5]={1,2,3,4};
int n=sizeof(a)/sizeof(a[0]);
int main(){
	
	for(int i=0;i<n;i++) printf("%d ",a[i]);
}
