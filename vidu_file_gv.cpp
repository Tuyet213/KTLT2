//doc ghi tap tin voi mang gom n so nguyen
#include<stdio.h>
#include<stdlib.h> //su dung ham sinh so ngau nhien
#define MAX 50

//doc ghi file van ban
void WriteFile(char *s);
void ReadFile(char *s,int a[],int &n);

//doc ghi file nhi phan
void WriteFileB(char *s);
void ReadFileB(char *s,int a[],int &n);

void ReadPos(char *s,int p);//doc phan tu thu p trong file
void PrintArr(int a[],int n);//in mang ra man hinh

int main(){
	int a[MAX],n;
//	char *s="D:\\BT-KTLT\\Dulieu.inp"; //duong dan tuyet doi
	char *s="Data.inp";//duong dan tuong doi
//	WriteFileB(s);	
	ReadFileB(s,a,n)	;
	PrintArr(a,n);
	ReadPos(s,3);
}
//nhap n so nguyen tu ban phim ghi vao file van ban
//cau truc file: dong dau tien ghi gia tri n
//dong sau ghi cac gia tri trong day so
void WriteFile(char *s){
	int n;
	printf("nhap n:");
	scanf("%d",&n);
	FILE* f=fopen(s,"w");
	if(f!=NULL){ //neu mo duoc file
		fprintf(f,"%d\n",n);//ghi n vao file
		int i,x;
		for(i=0;i<n;i++){
			printf("nhap phan tu thu %d:",i);
			scanf("%d",&x);
			fprintf(f,"%d ",x);//ghi gia tri thu i vao file
		}
		fclose(f);//dong file
	}		
	else
		printf("Not open file!");
}
//doc n so nguyen tu file van ban vao chuong trinh luu trong a[]
void ReadFile(char *s,int a[],int &n){
	FILE* f=fopen(s,"r");
	if(f!=NULL){
		fscanf(f,"%d",&n);//doc phan tu dau tien trong file luu vao n
		int i;
		for(i=0;i<n;i++)
			fscanf(f,"%d",&a[i]);//doc cac phan tu tiep theo lan luot luu vao a[i]
		fclose(f);
	}		
	else
		printf("Not open file!");
}
//tao n so ngau nhien va ghi vao file nhi phan
//cau truc file: so n sau do la n so ngau nhien
void WriteFileB(char *s){
	int n,r;
	printf("nhap n:");
	scanf("%d",&n);
	//srand((int)time(0));
	FILE* f=fopen(s,"wb");
	if(f!=NULL){
		fwrite(&n,sizeof(int),1,f);//ghi gia tri n vao file
		int i;
		for(i=0;i<n;i++){
			r = rand();//sinh so ngau nhien
			fwrite(&r,sizeof(int),1,f);	//ghi so ngau nhien thu i vao file		
		}
		fclose(f);
	}		
	else
		printf("Not open file!");
}
//doc n so nguyen tu file nhi phan vao chuong trinh luu trong a[]
void ReadFileB(char *s,int a[],int &n){
	FILE* f=fopen(s,"rb");
	if(f!=NULL){
		fread(&n,sizeof(int),1,f);//doc phan tu dau tien luu trong n
		int i;
		for(i=0;i<n;i++)
			fread(&a[i],sizeof(int),1,f);//doc cac phan tu tiep theo luu trong a[i]
		fclose(f);
	}		
	else
		printf("Not open file!");
}
//lay phan tu tai vi tri p trong file nhi phan
void ReadPos(char *s,int p){
	FILE* f=fopen(s,"rb");
	int x;
	if(f!=NULL){
		fseek(f,p*sizeof(int),SEEK_SET);//dua con tro chi vi toi phan tu thu p
		fread(&x,sizeof(int),1,f);//doc phan tu thu p trong file luu vao x
		//in ra man hinh
		printf("\nphan tu thu %d:%d",p,x);
		}		
	else
		printf("Not open file!");
}
//xuat day so luu trong a[] ra man hinh
void PrintArr(int a[],int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d  ",a[i]);
}
