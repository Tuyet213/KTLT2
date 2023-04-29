#include<stdio.h>

int x[100];
int n=5;
int s[100];
int dem=0; 

void GhiFile(int p){
	FILE *f=fopen("lab4_4.out","at");
	if(f==NULL) printf("Khong mo duoc file.");
	else {
		if(dem) {
			for(int i=1;i<p;i++) fprintf(f,"%d + ",x[i]); 
			fprintf(f,"%d\n",x[p]); 
		}
		else fprintf(f,"-1"); 
		fclose(f); 
	}
} 

void PhantichSo(int i){
	for(int j=x[i-1];j<=n-s[i-1];j++){
		x[i]=j;
		s[i]=s[i-1]+j; 
		if(s[i]==n){
			dem++;
			GhiFile(i); 
		}
		else PhantichSo(i+1); 
	} 
} 

int main(){
	x[0]=1;
	s[0]=0; 
	PhantichSo(1); 
} 
