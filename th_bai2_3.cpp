#include<stdio.h>
#include<stdlib.h>
#define MAX 50

void GhiFile(char *tentaptin){
	FILE *f=fopen(tentaptin,"wt");
	if(f==NULL) printf("Khong mo duoc file.\n");
	else{
		int n;
		do{
			printf("Nhap cap ma tran: ");
			scanf("%d",&n);
		}while(n<2||n>50);
		fprintf(f,"%d\n",n);
		int x;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				x=rand()%1000;
				fprintf(f,"%d ",x);
			}
			fprintf(f,"\n");
		}
		fclose(f);
	}
}

void DocFile(char *tentaptin, int a[][MAX], int &n){
	FILE *f=fopen(tentaptin,"rt");
	if(f==NULL) printf("Khong mo duoc file.\n");
	else{
		fscanf(f,"%d",&n);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				fscanf(f,"%d",&a[i][j]);
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
		fclose(f);
	}
}

int main(){
	char *tentaptin="Lab2_3.dat";
	int a[MAX][MAX];
	int n;
	GhiFile(tentaptin);
	DocFile(tentaptin, a,n);
	return 1;
}
