#include<stdio.h>
#define MAX(a,b) (a>b)?a:b
int a[]={0,25,22,9,33,21,50,41,60,90,70};
int n=sizeof(a)/sizeof(a[0]);
int L[100];
int T[100];


int Try(int i){
	int Max=0;
	int nho;
	for(int j=0;j<i;j++)
		if(a[i]>a[j])
			if(Max<1+L[j]){
				nho=j;
				Max=1+L[j];
			}
	L[i]=Max;
	T[i]=nho;
	if(i<n-1) Try(i+1);
}

int main(){
	L[0]=1;
	T[0]=0;
	Try(1);
	int dodai=0;
	for(int i=0;i<n;i++) if(dodai<L[i]) dodai=L[i];
	printf("Day con don dieu tang dai nhat: %d\n",dodai);
	for(int i=0;i<n;i++) printf("%d ",L[i]);
	printf("\n");
	for(int i=0;i<n;i++) printf("%d ",T[i]);
	return 1;
}
