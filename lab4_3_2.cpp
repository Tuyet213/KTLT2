#include<stdio.h>

int n;
int s;
int a[100];
int t[100];
int dem=0; 
void DocFile(){
	FILE *f = fopen("lab4_3.inp","rt");
	if(f==NULL) printf("Khong mo duoc file.");
	else {
		fscanf(f,"%d",&n);
		if(n>=30) printf("Khong thoa yeu cau.");
		else{
			fscanf(f,"%d",&s);
			for(int i=1;i<=n;i++){
				fscanf(f,"%d",&a[i]); 
			}
		}
		fclose(f); 
	}
}

void in(){
	int sum=0;
	for(int i=1;i<=n;i++) sum+=a[i]*t[i];
	if(sum==s) {
		dem++ ;
		printf("\nC%d: ",dem);
		for(int i=1;i<=n;i++) if(t[i]==1) printf("(%d)%d\t",i,a[i]); 
	} 
} 
void ATM(int i){
	for(int j=0;j<=1;j++){
		t[i]=j;
		if(i==n){
			in(); 
		}
		else ATM(i+1); 
	} 
} 

int main(){
	DocFile();
	ATM(1);
	return 1; 
} 











