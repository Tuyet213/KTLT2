#include<stdio.h>

int c[10][10];
int max_c=10000;
int n;//so thanh pho
int kq[10];//luu nghiem tot nhat
int x[20];// nghiem dang xet
int t[20];//chi phi tu x[1] den x[i]
int chuaxet[20];// danh dau thanh bo chua xet
int best_sum=max_c;//chi phi hanh trinh tot nhat... cho so lon nhat den gap chi phi nho hon thi cap nhat
int sum;

void DocFile(){
	FILE *f=fopen("lab4_5.inp", "rt");
	if(f==NULL) printf("Khong mo duoc file");
	else{
		fscanf(f,"%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) fscanf(f,"%d",&c[i][j]);
		fclose(f);
	}
	x[1]=1;
	t[1]=0;
	best_sum=max_c;
	for(int i=2;i<=n;i++) chuaxet[i]=1; //xuat phat tu tp1 nen buoc phai di qua no nen chuaxet[1] luon khac 1
}

void danhgia(){
	int s=sum;
	if(s<best_sum){
		best_sum=s;
		for(int i=1;i<=n;i++) kq[i]=x[i];
	} 
} 
void thu(int i){//i la thanh pho thu i
	if(sum<best_sum){
		for(int j=2;j<=n;j++)
		if(chuaxet[j]){
			x[i]=j;
			chuaxet[j]=0;
			sum=sum+c[x[i-1]][j];
			if(i==n) danhgia();
			else thu(i+1);
			sum=sum-c[x[i-1]][j];
			chuaxet[j]=1;
		}
	}
}


int main(){
	DocFile();
	thu(2);
	inketqua();
}







