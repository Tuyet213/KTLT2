#include<stdio.h>
#define MAX 30

int n; //so thanh pho
int maxc=10000;//so lon nhat
int c[MAX][MAX]; //ma tran chi phi
int x[MAX]; //nghiem dang xet
int chuaxet[MAX];
int sum=0;//chi phi hanh trinh tot nhat

void docfile(){
	FILE *f=fopen("lab5_4.txt","r");
	if(f!=NULL){
		fscanf(f,"%d\n",&n);	
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++)
				fscanf(f,"%d",&c[i][j]);				
			fscanf(f,"\n");
		}		
	}
	fclose(f);
	//thanh pho xuat phat là 1
	x[1]=1;
	//danh dau cac thanh pho chua xet
	for(int i=2; i<=n; i++)
		chuaxet[i]=1;
}

void ghifile(){
	FILE *f=fopen("lab5_4_out.txt","w");
	if(f!=NULL){
		fputs("TP1 -> ", f);	
		for(int i=2; i<=n; i++)
			fprintf(f, "TP%d -> ", x[i]);
			fputs("TP1\n", f);
			fprintf(f,"Tong chi phi la: %d",sum);
	}
	fclose(f);
}

void Greedy(){
	int i, xi, tot;
	x[1]=1;
	chuaxet[1]=0;
	i=1;
	while(i<n){
		i++;
		//chon ung vien tot nhat
		tot=maxc; //tot la chi phi nho nhat tren moi chang duong
		for(int j=2;j<=n;j++)
			if(chuaxet[j]&&c[x[i-1]][j]<tot){
				xi=j;
				tot=c[x[i-1]][j];
			}
		x[i]=xi;
		chuaxet[xi]=0;
		sum=sum+c[x[i-1]][x[i]];
	}
	sum=sum+=c[x[i]][1];
	ghifile();
}

int main(){
	docfile();
	Greedy();
}
