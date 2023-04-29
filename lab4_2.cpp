#include<stdio.h>

//a

int a[100];
int n;
int tt[100]={0};
void inKQ(int a[], int n){
	for(int i=1;i<=n;i++) printf("%d",a[i]);
	printf("\n");
}

void lietke(int i){
	for(int j=0;j<=1;j++){
		a[i]=j;
		if(i==n) inKQ(a,n);
		else lietke(i+1);
	}
}

//b: khong lap lai nen ko can xoa trang thai
//khoi tao a[0]=0
void lietke_tohop(int i, int k, int m){
	for(int j=a[i-1]+1;j<=m-k+i;j++){
		a[i]=j;
		if(i==k) inKQ(a,k);
		else lietke_tohop(i+1,k,m);
	}
}




void lietke_tohop_1(int i, int k, int n){
	for(int j=a[i-1]+1;j<=n-k+i;j++){
		a[i]=j;
		if(i==k) inKQ(a,k);
		else lietke_tohop_1(i+1,k,n);
	}
}

//c

void lietke_chinhhop(int i, int k, int m){
	for(int j=1;j<=m;j++){
		if(tt[j]==0){
			tt[j]=1;
			a[i]=j;
			if(i<k) lietke_chinhhop(i+1,k,m);
			else inKQ(a,k);
			a[i]=0;
			tt[j]=0; 
		}	
	}
}

void lietke_chinhhop_1(int i, int k, int m){
	for(int j=1;j<=m;j++){
		if(tt[j]==0){
			tt[j]=1;
			a[i]=j;
			if(i<=k) lietke_chinhhop_1(i+1, k, n);
			else inKQ(a,k);
			tt[j]=0;
			a[i]=0;
		}
	}
}

int main(){
//	do{
//		printf("Nhap chieu dai chuoi: ");
//		scanf("%d",&n);
//	}while(n<=0||n>10);
//	lietke(1);
//	printf("\n");
	lietke_tohop(1,4,6);
//	printf("\n");
//	lietke_chinhhop(1,3,4);
	return 1;
	
	
	
	
}
