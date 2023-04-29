#include<stdio.h>

//b
void DocFile(char *tentaptin, float a[], int &n){//////////////&n
	FILE *f=fopen(tentaptin, "rt");
	if(f==NULL) printf("Err!");
	else{
		fscanf(f,"%d",&n);
		for(int i=0;i<n;i++){
			fscanf(f,"%f",&a[i]);
		}
	}
	fclose(f);
}
//c
int dem_am(float a[], int n){
	if(n==0) return 0;
	if(a[n-1]<0) return dem_am(a,n-1)+1;
	return dem_am(a,n-1);
}
 
//d
int max(float a, float b){
	if(a>b) return a;
	return b;
}
int phatu_max(float a[], int n){
	if(n==1) return a[0];
	return max(a[n-1], phatu_max(a,n-1));
}
///////////////////////////////////////////
float Max(float a[], int n){
	if(n==1) return a[n-1];
	else
		if(a[n-1]>Max(a,n-1)) return a[n-1];
		else return Max(a,n-1);
}

void ghi_max(char *tentaptin, float a[], int n){
	FILE *f=fopen(tentaptin,"at");
	if(f==NULL) printf("Err!");
	else{
		int max=phatu_max(a,n);
		fprintf(f,"\n");
		fprintf(f,"%d",max);
		fclose(f);
	}
}
//e

int main(){
	char *tentaptin="lab3_2.inp";
	int n;
	float a[50];
	DocFile(tentaptin,a,n);
	for(int i=0;i<n;i++) printf("%.1f ",a[i]);
	printf("\nSo phan tu am la %d",dem_am(a,n));
	printf("\nPhan tu lon nhat: %d ",phatu_max(a,n));
	ghi_max(tentaptin,a,n);
}


