#include<stdio.h>
//int n;
//int *a;
void Ghi_File(char *tentaptin, int &n, int a[100]){
	FILE *f=fopen(tentaptin,"wt");
	if(f==NULL) printf("Khong mo duoc file.\n");
	else{
		printf("Nhap gia tri n: ");
		scanf("%d",&n);
		for(int i=0;i<n;i++){
		printf("Nhap so nguyen thu %d: ",i+1);
		scanf("%d",&a[i]);
		fprintf(f,"%d ",a[i]);
		}
		fclose(f);
	}
	
} 

void Doc_File(char *tentaptin, int n, int a[100]){
	FILE *f=fopen(tentaptin,"rt");
	if(f==NULL) printf("Khong mo duoc file.\n");
	else{
		for(int i=0;i<n;i++){
		fscanf(f,"%d",&a[i]);
//		printf("%d ",a[i]);
	}
		fclose(f);
	}
	
}

void In_File(char *tentaptin, int n, int a[100]){
	Doc_File(tentaptin,n,a);
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}

int Tong(char *tentaptin, int n, int a[100]){
	Doc_File(tentaptin,n,a);
	int S=0;
	for(int i=0;i<n;i++) 
		S+=a[i];
	return S;	
}

int main(){
	int n;
	int a[100];
	char *tentaptin="dulieu(1).txt";
	Ghi_File(tentaptin,n,a);
	Doc_File(tentaptin,n,a);
	In_File(tentaptin,n,a);
	printf("\nTong cua %d so nguyen la: %d",n,Tong(tentaptin,n,a));
	return 0;
}


















