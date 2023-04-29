#include<stdio.h>
/////mang moi khoi tao co cac phan tu bang 0;
int a[100];
int n;
int t[100];

void in(int a[], int n){
	for(int i=1;i<=n;i++) printf("%d",a[i]);
	printf("\n");
}

void lietke(int i){
	for(int j=0;j<=1;j++){
		a[i]=j;
		if(i==n) in(a,n);
		else lietke(i+1);
	}
}

void tohop(int i, int k, int m){
	for(int j=a[i-1]+1;j<=m-k+i;j++){
		a[i]=j;
		if(i==k) in(a,k);
		else tohop(i+1,k,m);
	}
}

void chinhhop(int i, int k, int m){
	for(int j=1;j<=m;j++){
		if(t[j]==0){
			t[j]=1;
			a[i]=j;
			if(i==k) in(a,k);
			else chinhhop(i+1, k, m);
			t[j]=0;
		//	a[i]=0;
		}
	}
}

int main(){
	tohop(1,2,3);
//	lietke(1);
//	chinhhop(1,3,4);
}
