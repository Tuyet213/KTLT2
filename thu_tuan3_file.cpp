#include<stdio.h>
void Ghi_File(FILE *f, int &n, int a[100]){
		printf("Nhap gia tri n: ");
		scanf("%d",&n);
		for(int i=0;i<n;i++){
		printf("Nhap so nguyen thu %d: ",i+1);
		scanf("%d",&a[i]);
		fprintf(f,"%d",a[i]);
	}
	
} 

void Doc_File(FILE *f, int n, int a[100]){
		for(int i=0;i<n;i++){
		fscanf(f,"%d",&a[i]);
	}
	
}

void In_File(FILE *f, int n, int a[100]){
	Doc_File(f,n,a);
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}

int Tong(FILE *f, int n, int a[100]){
	Doc_File(f,n,a);
	int S=0;
	for(int i=0;i<n;i++) 
		S+=a[i];
	return S;
}

int main(){
	int n;
	int a[100];
	char *tentaptin="dulieu(1).txt";
	FILE *f=fopen(tentaptin,"rt");
	if(f==NULL) printf("Khong mo duoc file.\n");
	else{
		Ghi_File(f,n,a);
		Doc_File(f,n,a);
		In_File(f,n,a);
		printf("\nTong cua %d so nguyen la: %d",n,Tong(f,n,a));
	}
	fclose(f);
	return 0;
}


















