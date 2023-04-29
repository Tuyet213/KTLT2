#include<stdio.h>
#define MAX 30
int n;//so thanh pho
int c[MAX][MAX];//ma tran chi phi
int x[MAX];//nghiem
int chuaxet[MAX];
int sum=0;
int tot;

void docfile(){
    FILE *f=fopen("vs_lab5_4.txt","rt");
    if(f==NULL) printf("Khong mo duoc file !!!!!!");
    else{
        fscanf(f,"%d",&n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                fscanf(f,"%d",&c[i][j]);
            fscanf(f,"\n");
        }
    }
    fclose(f);
}

void ghifile(){
    FILE *f=fopen("vs_lab5_4_out.txt","wt");
    if(f==NULL) printf("Khong mo duoc file!!!!!");
    else{
        for(int i=1;i<=n;i++) fprintf(f,"TP%d->",x[i]);
        fprintf(f,"TP1\n");
        fprintf(f,"Tong chi phi nho nhat la: %d", sum);
    }
    fclose(f);
}

void Greedy(){
    for(int j=1;j<=n;j++) chuaxet[j]=1;
    x[1]=1;
    chuaxet[1]=0;
    int i=2;
    while(i<=n){
        tot=10000;
        for(int j=2;j<=n;j++){//tong tu gan trang thai
            if(chuaxet[j]&&c[x[i-1]][j]<tot){
                x[i]=j;
                tot=c[x[i-1]][j];
            }
        }
        chuaxet[x[i]]=0;
        sum=sum+tot;
        i++;
    }
    sum=sum+c[x[n]][1];
    ghifile();
}

int main(){
    docfile();
    Greedy();
    return 1;
}
