#include<stdio.h>
#include<stdlib.h>

//a
void nhapmang(int a[], int &n){///////&n
	do{
		printf("Nhap so luong phan tu: ");
		scanf("%d",&n);
	}while(n<=2||n>=100);
	for(int i=0;i<n;i++) a[i]=rand()%100;
}

//b
int tong(int a[], int n){
	if(n==1) return a[0];
	return tong(a,n-1)+a[n-1];
}

//c
void ghi(int a[], int n){
	int flag=1;
	for(int i=0;i<n;i++) if(a[i]<0) {
		flag=0;
		break; 
	}
	if(flag==1){
		FILE *f=fopen("lab3_3.inp","wt");
		if(f==NULL) printf("Err!");
		else{
			fprintf(f,"%d\n",n);
			for(int i=0;i<n;i++){
				fprintf(f,"%d ",a[i]);
			}
			fclose(f);
		}
	}
}

int main(){
	int a[100];
	int n;
	nhapmang(a,n);
	for(int i=0;i<n;i++) printf("%d ",a[i]);
	printf("\nTong: %d",tong(a,n));
	ghi(a,n);
	return 1;
}





