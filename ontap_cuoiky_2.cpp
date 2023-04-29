#include<stdio.h>

int tt[30];
int dem=0;
int k;
int n;
void inkq(){
	FILE *f=fopen("tuyet.txt","r+t");
	if(f==NULL) printf("Khong mo duoc file!!!");
	else{
		int flag=1;
		for(int i=0;i<n-1;i++)
			if(tt[i]==0&&tt[i+1]==0) {
				flag=0;
				break;
			}
		
		if(flag){
			int S=0;
			for(int i=0;i<n;i++) S+=tt[i];
			if(S>=k){
				dem++;
				fseek(f,0,SEEK_SET);
				fprintf(f,"%d\n",dem);
				fseek(f,0,SEEK_END);
				for(int i=0;i<n;i++)
					if(tt[i]) fprintf(f,"X");
					else fprintf(f,"_");
				fprintf(f,"\n");	
			}
		}
		if(dem==0) fprintf(f,"-1");
	fclose(f);
	}	
}

void thu(int i){
	for(int j=0;j<=1;j++){
		tt[i]=j;
		if(i<n) thu(i+1);
		else inkq();
		tt[i]=0;
	}
}

int main(){
	printf("Nhap n: ");
	scanf("%d",&n);
	printf("Nhap k: ");
	scanf("%d",&k);
	thu(0);
	return 1;
}

