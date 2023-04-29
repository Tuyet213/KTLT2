#include<stdio.h>
#define N 30

struct Sach{
	char ten[50],tgia[40],nxb[50];
	int namxb;
};

void Ghi_File();
void Doc_File(Sach ds[],int &n);
void Xuat(Sach s);
void Xuat_DS(Sach ds[],int n);
void Xuat_i(int p);
void Ghi_File_KQ(Sach ds[],int n);

int main(){
	int n,i;
	Sach ds[N];
	Ghi_File();
	Doc_File(ds,n);
	Xuat_DS(ds,n);
	Xuat_i(1);
	Ghi_File_KQ(ds,n);
}

void Ghi_File(){
	Sach s;
	int n,i;
	FILE *f=fopen("Sach.txt","wb");
	if(f==NULL)
		printf("Err!");
	else{
		do{
			printf("nhap n:");
			scanf("%d",&n);
		}while (n<2 || n>30);
		for(i=0;i<n;i++){
			fflush(stdin);
			printf("nhap ten sach:");
			gets(s.ten);
			fflush(stdin);
			printf("nhap ten tac gia:");
			gets(s.tgia);
			fflush(stdin);
			printf("nhap nha xuat ban:");
			gets(s.nxb);		
			printf("nhap nam xuat ban:");
			scanf("%d",&s.namxb);
			fwrite(&s,sizeof(Sach),1,f);
		}
		fclose(f);
	}
}

void Doc_File(Sach ds[],int &n){
	FILE *f=fopen("Sach.txt","rb");
	if(f==NULL)
		printf("Err!");
	else{
		int i=0;
		while(!feof(f)){
			fread(&ds[i],sizeof(Sach),1,f);
			i++;
		}
		n=i-1;
		fclose(f);
	}
}

void Xuat(Sach s){
	printf("%s\t",s.ten);
	printf("%s\t",s.tgia);
	printf("%s\t",s.nxb);
	printf("%d\n",s.namxb);
}

void Xuat_DS(Sach ds[],int n){
	printf("\nSo sach %d, Danh sach:\n",n);
	for(int i=0;i<n;i++)
		Xuat(ds[i]);
}

void Xuat_i(int p){
	FILE *f=fopen("Sach.txt","rb");
	if(f==NULL)
		printf("Err!");
	else{
		Sach s;
		fseek(f,p*sizeof(Sach),SEEK_SET);
		fread(&s,sizeof(Sach),1,f);
		printf("\nSach thu i trong file:\n");
		Xuat(s);
	}
}

void Ghi_File_KQ(Sach ds[],int n){
	FILE *f=fopen("Lab2_5.out","w");
	if(f==NULL)
		printf("Err!");
	else{
		int i,c=0;
		for(i=0;i<n;i++)
			if(ds[i].namxb>2010)
				c++;
		if(c==0)
			fprintf(f,"%d",-1);
		else
			fprintf(f,"%d",c);
	}
}
