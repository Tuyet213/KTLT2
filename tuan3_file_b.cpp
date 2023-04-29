#include<stdio.h>
#pragma pack(1)
void Ghi_File(char *tentaptin, int &n, int a[100]){
	FILE *f=fopen(tentaptin, "wb");
	if(f==NULL) printf("Khong mo duoc file.\n");
	else{
		printf("Nhap gia tri n: ");
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			printf("Nhap phan tu thu %d: ",i+1);
			scanf("%d",&a[i]);
			fwrite(&a[i],sizeof(int),1,f);
		}
		fclose(f);
	}
}

void Doc_File(char *tentaptin, int n, int a[100]){
	FILE *f=fopen(tentaptin, "rb");
	if(f==NULL) printf("Khong mo duoc file.\n");
	else{
		for(int i=0;i<n;i++){
			fread(&a[i],sizeof(int),1,f);
		}
		fclose(f);
	}
}

void In_File(char *tentaptin, int n, int a[100]){
	Doc_File(tentaptin,n,a);
	for(int i=0;i<n;i++) printf("%d ",a[i]);
}

int Tong(char *tentaptin, int n, int a[100]){
	Doc_File(tentaptin,n,a);
	int S=0;
	for(int i=0;i<n;i++){
		S+=a[i];
	}
	return S;
}

int main(){
	int n;
	char *tentaptin="Ddulieu(2).txt";
	int a[100];
	Ghi_File(tentaptin, n, a);
	Doc_File(tentaptin, n, a);
	In_File(tentaptin, n, a);
	printf("\nTong cua %d so nguyen la: %d ",n,Tong(tentaptin, n,a));
	return 1;
}











