#include<stdio.h>

int a[100];//trang thai
int t[100];//menh gia
int n;
int s;

void docFile(int a[], int &n, int &s){
	FILE *f=fopen("lab4_3.inp","rt");
	if(f==NULL) printf("Khong mo duoc file.");
	else {
		fscanf(f,"%d",&n);
		if(n>=30) return ;
		fscanf(f,"%d",&s);
		for(int i=1;i<=n;i++) {
			fscanf(f,"%d",&t[i]);
		}
		fclose(f);
	}
}

void xuatnghiem(){
	int i;
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i]*t[i];
	}
	if(sum==s){
		for(int i=1;i<=n;i++)
			if(a[i]==1) printf("%d	",t[i]);
		printf("\n");
	}
}

//void ATM(int i){
//	if(i==n){
//		xuatnghiem();
//		return;
//	}
//	for(int j=0;j<=1;j++){
//		a[i]=j;
//		ATM(i+1);
//	}
//}

void ATM(int i){
	for(int j=0;j<=1;j++){
		a[i]=j;
		if(i==n){
		xuatnghiem();	
	}
	else
		ATM(i+1);
	}
}

int main(){
	docFile(t,n,s);
	ATM(1);
	return 1;
}
