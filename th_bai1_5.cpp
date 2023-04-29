#include<stdio.h>
#include<math.h>
#define FOR(i,a,b) for(i=a; i<b;i++)
void Nhap(int *a, int &n){
	printf("Nhap so luong phan tu: "); 
	scanf("%d",&n);
	while(n<=3||n>=50){
		printf("Nhap lai so luong phan tu: "); 
		scanf("%d",&n);
	}
	int i;
	FOR(i,0,n) scanf("%d",&a[i]);
	
}
int kt_chinhphuong(int n){
	int temp=sqrt(n);
	if(temp*temp==n) return 1;
	return 0;
}
int cp_min(int *a, int n){
	int i;
	int min=-1;
	int flag; //flag=-1;
	FOR(i,0,n){
		if(kt_chinhphuong(a[i])){  // if(kt_chinhphuong(a[i])==1&&a[i]<min) min=a[i] flag=i; .....if(flag>-1) return min; else return ;
			min=a[i];
			flag=i;
			break;
		}
	}
	
	if(min>-1){
		FOR(i,flag,n){
		if(kt_chinhphuong(a[i])==1&&a[i]<min) min=a[i];
		}
	}
	
	return min;
}
//thay vi dung return dung co hieu
int kt_tangdan(int *a, int n){
	int flag=1;
	int i;
	FOR(i,0,n-1){
		if(a[i]>a[i+1]) {
			flag=0;
			break;
		}
	}
	return flag;
}

int main(){
	int n;
	int a[100];
	Nhap(a,n);
	if(cp_min(a,n)>0) printf("So chinh phuong nho nhat trong mang la: %d",cp_min(a,n));
	else printf("Khong co so chinh phuong trong mang.");
	if(kt_tangdan(a,n)) printf("\nMang tang dan.");
	else printf("\nMang khong tang dan.");
	return 1;
	
	
}
