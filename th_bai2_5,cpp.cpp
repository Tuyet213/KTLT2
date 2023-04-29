#include<stdio.h>
#include<string.h>

struct sach{
	char tensach[255];
	char tacgia[255];
	char nxb[255];
	int nam;
};

typedef struct sach SACH;

void GhiFile(char *tentaptin){
	FILE *f=fopen(tentaptin,"wb");
	if(f==NULL) printf("Khong mo duoc file.\n");
	else{
		int n;
		do{
		printf("Nhap so luong sach: ");
		scanf("%d",&n);
		}while(n<=2||n>=50);
	
		SACH a;
		fprintf(f,"%d\n",n);
		for(int i=0;i<n;i++){
			
			printf("\n");
		
			printf("Ten sach: ");
			fflush(stdin);
			fgets(a.tensach,255,stdin);
		//	fprintf(f,"\n");
			fputs(a.tensach,f);
			
			printf("Tac gia: ");
			fflush(stdin);
			fgets(a.tacgia,255,f);
		//	fprintf(f,"\n");
			fputs(a.tacgia,f);
	
			printf("Nha xuat ban: ");
			fflush(stdin);
			fgets(a.nxb,255,f);
		//	fprintf(f,"\n");
			fputs(a.nxb,f);
		
			printf("Nam xuat ban: ");
			fflush(stdin);
			scanf("%d",&a.nam);
			fprintf(f,"\n");
			fscanf(f,"%d\n",&a.nam);
		}
		fclose(f);
	}
}


int main(){
	int n;
	SACH a[100];
	char *tentaptin="Lab2_5.inp";
	GhiFile(tentaptin);
	return 1;
}
