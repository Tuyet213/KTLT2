#include<stdio.h>

void docFile(int a[], int &n, int &s){
	FILE *f=fopen("lab4_3.inp","rt");
	if(f==NULL) printf("Khong mo duoc file.");
	else {
		fscanf(f,"%d",&n);
		if(n>=30) return ;
		fscanf(f,"%d",&s);
		for(int i=1;i<=n;i++) {
			fscanf(f,"%d",&a[i]);
		}
		fclose(f);
	}
}

void inkq(int a[], int n){
	for(int i=1;i<=n;i++){
		printf("(%d)%d\t",i,a[i]);
	}
}

void cachruttien(int a[], int n, int i, int s, int tt[], int t[]){
	int k=1;
	for(int j=1;j<=n;j++){
		int sum=0;
		if(tt[j]==0){
			tt[j]=1;
			sum+=t[j];
			a[i]=t[j];
			if(s==sum) {
				printf("\nC%d: ",k);
				k++;
				inkq(a,i);
				return;
			}
			else cachruttien(a,n,i+1,sum,tt,t);
			tt[j]=0;
			a[i]=0;
		}
	}
}

int main(){
	int a[30];
	int n;
	int t[30];
	int tt[30]={0};
	int s;
	docFile(t,n,s);
	cachruttien(a,n,1,s,tt,t);
	return 1;
}
