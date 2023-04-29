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
//		v[0]=0;
//		w[0]=0;
		for(int i=1;i<=n;i++) fscanf(f,"%d",&v[i]);
		for(int i=1;i<=n;i++) fscanf(f,"%d",&w[i]);
		fclose(f);
	}	
}

void GhiFile(){
	FILE *f=fopen("lab6_2.txt","wt");
	if(f==NULL) printf("Khong mo duoc file !!!!");
	else{
		for(int i=1;i<=n;i++) if(L[i][1]!=0){
			fprintf(f,"Vat thu: %d, gia tri: %d, trong luong: %d\n",i,v[i],w[i]);
		}
		
	}
}

//void khoitao(){
//	for(int i=0;i<=M;i++) L[0][i]=0;
//	for(int i=0;i<=n;i++) L[i][0]=0;
//} trong C khong khoi gan thi mac dinh bang 0;

void Try(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=M;j++){
			if(w[i]>j ){
				if(L[i-1][j-w[i]]+v[i]>L[i][j]) L[i][j]=L[i-1][j-w[i]]+v[i];
				else L[i][j]=L[i-1][j];
			}else L[i][j]=L[i-1][j];
		}		
}



int main(){
	DocFile();
//	khoitao();
	Try();
	for(int i=n;i>=1;i--){
		for(int j=M;j>=1;j--) printf("%d ",L[i][j]);
		printf("\n");
	}
	GhiFile();
	return 1;
}
