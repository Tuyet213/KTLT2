#include<stdio.h>

int x[100];//luu nghiem
int n=5;
int s[100];//luu tong cac phan tu truoc i

void inkq(int p){
	for(int i=1;i<p;i++){
		printf("%d + ",x[i]);
	}
	printf("%d\n",x[p]);
}

void GhiFile(int p){
	FILE *f=fopen("lab4_4.out","wt");
	if(f==NULL) printf("Khong mo duoc file");
	else{
		for(int i=1;i<p;i++){
		fprintf(f,"%d + ",x[i]);
		}
		fprintf(f,"%d\n",x[p]);
		fclose(f);
	}
}

void phantichSo(int i){
	for(int j=x[i-1];j<=n-s[i-1];j++){
		x[i]=j;
		s[i]=s[i-1]+j;
		if(s[i]==n) inkq(i);
		else phantichSo(i+1);
	}
}

int main(){
	x[0]=1;
	s[0]=0;
	phantichSo(1);
	return 1;
}
