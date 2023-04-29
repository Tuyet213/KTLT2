#include<stdio.h>
#define MAX 50
#include<time.h>
#include<stdlib.h>
// srand((int)time(0));
// int x=rand()%1000;

void GhiFile(char *tentaptin){
	FILE *f = fopen(tentaptin,"wt");
	if(f == NULL) printf("Khong mo duoc file.\n");
	else{
		int n;
		int x;
		printf("Nhap so luong phan tu: ");
		scanf("%d", &n);
		fprintf(f, "%d\n", n);
		for(int i = 0; i < n; i++){
//			do{
//				printf("Nhap phan tu thu %d: ",i+1);
//				scanf("%d",&x);
//			}while(x<0||x>1000);
			x = rand()%1000; // co the giong nhau... muon khac nhau dung them tham so time
			fprintf(f, "%6d", x);
		}
		fclose(f);
	}
}

void DocFile(char *tentaptin, int &n, int a[]){
	FILE *f = fopen(tentaptin,"rt");
	if(f == NULL) printf("Khong mo duoc file.\n");
	else{
		fscanf(f, "%d", &n);
		for(int i = 0; i < n; i++){
			fscanf(f, "%d", &a[i]);
		}
		fclose(f);
	}
}

void xuatMang(int a[], int n){
	printf("So phan tu la: %d\n",n);
	for(int i = 0; i < n; i++){
		printf("%d\t", a[i]);
	}
}

void TBC(char *tentaptin1,char *tentaptin2, int n, int a[]){
	DocFile(tentaptin1,n,a);
	float tbc;
	int Sum=0;
	int count=0;
	for(int i=0;i<n;i++){
		if(a[i]%2==1) {
			Sum+=a[i];
			count ++;
		}
	}
	if(count>0) tbc=(float)Sum/count; 
	else tbc=0;
	FILE *f=fopen(tentaptin2,"wt");
	if(f==NULL) printf("Khong mo duoc file.\n");
	else {
		fprintf(f,"TBC: %f\n",tbc);
		fprintf(f,"So luong so le: %d",count);
		fclose(f);
	}
}

int Hoanvi(int &a, int &b){
	int temp=a;
	a=b;
	b=temp;
}

void sapxep( int a[], int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]) Hoanvi(a[i],a[j]);
		}
	}
}

void GhiFile2(char *tentaptin, int a[], int &n){
	sapxep(a,n);
	FILE *f=fopen(tentaptin,"at");
	if(f==NULL) printf("Khong mo duoc file.\n");
	else{
		fprintf(f,"\n");
		for(int i=0;i<n;i++){
			fprintf(f,"%d ",a[i]);
		}
		fclose(f);
	}
}

int main(){
	char *tentaptin1="Lab2_2.inp";
	char *tentaptin2="Lab2_2.out";
	int a[MAX];
	int n;
	GhiFile(tentaptin1);
	DocFile(tentaptin1,n,a);
	xuatMang(a,n);
	TBC(tentaptin1,tentaptin2,n,a);
	GhiFile2(tentaptin2,a,n);
	return 1;
}



