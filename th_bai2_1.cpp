#include<stdio.h>
#pragma pack(1)
#define MAX 20
#include<math.h>

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

void XuatMang(int a[], int &n){
	printf("So phan tu trong mang la: %d\n", n);
	for(int i = 0; i < n; i++) printf("%d ", a[i]);
}

bool ktraChinhPhuong(int n){
	int t = sqrt(n);
	if(n == t * t) return 1;
	return 0;
}

void Ghi_SCP_File(char *tentaptin, int n, int a[]){
	FILE *f = fopen(tentaptin,"wt");
	if(f == NULL) printf("Khong mo duoc file.\n");
	else {
		int count = 0;
		for(int i = 0; i < n; i++){
			if(ktraChinhPhuong(a[i])) {
				fprintf(f, "%d ", a[i]);
				count++;
			}
		}
		if(count == 0) fprintf(f, "%d", -1);
		fclose(f);
	}
}

//else{
//	int i;
//	bool kt=false;
//	for(i=0;i<n;i++){
//		if(ktraChinhPhuong(a[i])){
//			fprintf(f,"%d ",a[i]);
//			kt=true;
//		}
//	}
//	if(kt==false) fprintf(f,"%d",-1);
//}


int main(){
	int a[MAX];
	int n;
	char *doc = "Lab2_1.inp";
	char *ghi = "Lab2_1.out";
	DocFile(doc, n, a);
	XuatMang(a, n);
	Ghi_SCP_File(ghi, n, a);
	return 1;
}
