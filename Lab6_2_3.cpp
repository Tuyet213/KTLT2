#include<stdio.h>

int L[100][100];//gia tri lon nhat tu vat 1 den vat dong co trong luong <= cot
int M;
int w[100];
int v[100];
int n;

void DocFile(){
	FILE *f=fopen("lab6_2.inp","rt");
	if(f==NULL) printf("Khong mo duoc file!!!");
	else{
		fscanf(f,"%d",&n);
		fscanf(f,"%d",&M);
		for(int i=0;i<n;i++) fscanf(f,"%d",&v[i]);
		for(int i=0;i<n;i++) fscanf(f,"%d",&w[i]);
		fclose(f);
	}	
}

void GhiFile(){
	FILE *f=fopen("lab6_2.txt","wt");
	if(f==NULL) printf("Khong mo duoc file !!!!");
	else{
		for(int i=0;i<n;i++) if(L[i][M]!=0){
			fprintf(f,"Vat thu: %d, gia tri: %d, trong luong: %d\n",i+1,v[i],w[i]);
		}
		
	}
}

void khoitao(){
	for(int i=0;i<=M;i++) L[0][i]=0;
	for(int i=0;i<n;i++) L[i][0]=0;
}

void Try(){
	for(int i=1;i<n;i++)
		for(int j=1;j<=M;j++){
			if(w[i-1]<=j-w[i] )
				if(L[i-1][j-w[i]]+v[i]>L[i][j]) L[i][j]=L[i-1][j-w[i]]+v[i];
			else L[i][j]=L[i-1][j];
		}		
}

int main(){
	DocFile();
	khoitao();
	Try();
	GhiFile();
	return 1;
}
