#include<stdio.h>

void nhapmang(int a[], int &n){
	do{
		printf("Nhap so luong phan tu: ");
		scanf("%d",&n);
	}while(n<=5||n>=100);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
}

void xuatmang(int a[], int n){
	for(int i=0;i<n;i++) printf("%d ",a[i]);
}

//a

int Tong_dq_dau(int a[], int n){
	if(n==1) return a[0];
	else return Tong_dq_dau(a,n-1)+a[n-1];
}
////dequy duoi co bieu thuc tinh toan va nam trong phan goi ham
int Tong_dq_duoi(int a[], int n, int sum=0){
	if(n==0) return sum;
	else return Tong_dq_duoi(a,n-1,sum+a[n-1]);
}

int Tong_dq_duoi_co(int a[], int n, int i, int sum){
	if(i>=n) return sum;
	return Tong_dq_duoi_co(a, n, i+1, sum+a[i]);
}
//b

float Tien_dq_dau(float tien, float laisuat, int nam){
	if(nam==0) return tien;
	else return Tien_dq_dau(tien, laisuat,nam-1)*(1+laisuat);
}

float Tien_dq_duoi(float tien, float laisuat, int nam){
	if(nam==0) return tien;
	else return Tien_dq_duoi(tien*(1+laisuat), laisuat, nam-1);
}

float Tien_dq_duoi_co(int i, int nam, float sum){
	if(i>nam) return sum;
	return Tien_dq_duoi_co(i+1, nam, sum*1.065);
}
int main(){
	int a[100];
	int n;
	int sum;
	nhapmang(a,n);
	xuatmang(a,n);
	printf("%d %d %d",Tong_dq_dau(a,n), Tong_dq_duoi(a,n,sum), Tong_dq_duoi_co(a,n,0,0));
	printf("\n%f %f %f",Tien_dq_dau(100000,0.065,n),Tien_dq_duoi(100000,0.065,n), Tien_dq_duoi_co(1,n,100000));
	return 0;
}














