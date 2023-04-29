#include<stdio.h>

int kq[10];
int t[10];
int best_sum=10000;
int sum=0;
int phi[10][10];
int n;

void DocFile(){
	FILE *f=fopen("lab4_5.inp","rt");
	if(f==NULL) printf("Khong mo duoc file.");
	else{
		fscanf(f,"%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				fscanf(f,"%d",&phi[i][j]);
		fclose(f);
	}
}

void GhiFile(){
	FILE *f=fopen("lab4_5.out","wt");
	if(f==NULL) printf("Khong mo duoc file.");
	else{
		for(int i=2;i<n;i++) fprintf(f,"TP%d->",kq[i]);
		fprintf(f,"TP%d",kq[n]);
		fprintf(f,"\nTong chi phi la: %d",best_sum);
		fclose(f);
	}	
}

void hanhtrinh(int i){
	
	
}

int main(){
	DocFile();
	hanhtrinh(1);
	GhiFile();
	return 1;
}











 
