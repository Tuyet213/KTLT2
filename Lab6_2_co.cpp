#include<stdio.h>
#define Max(a,b) {a>b?a:b}
#define max 100
int n;      //so luong mon hang
int m;      //trong luong cua ba lo
int v[max];     //luu gia tri cua cac do vat
int w[max];     //luu trong luong cua cac do vat 
int L[max][max];        //luu tru ket qua cua cac buoc thuc hien

void ReadFile(){
    FILE *p = fopen("balo.txt", "r");
    if(p==NULL)
        printf("khong mo duoc file");
    else{
        fscanf(p,"%d",&n);
        fscanf(p, "%d ", &m);
        for(int i = 1; i <= n; i++)
            fscanf(p, "%d", &v[i]);
        for(int j = 1; j <= n; j++)
            fscanf(p, "%d", &w[j]);
        fclose(p);
    }
}

void Dynammic2(){
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=m; j++){
            if(w[i]<=j)
                L[i][j] = Max(L[i-1][j], L[i-1][j-w[i]] + v[i]);
            else
                L[i][j] = L[i-1][j];
        }
}

void Result(){
    int j = m;
    for(int i = n; i>0; i--)
        if(L[i][j] != L[i-1][j]){
            printf("vat thu: %d, gia tri: %d, trong luong: %d",i,v[i],w[i]);
            j = j - w[i];
        }
}

void in(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) printf("%d ");
		printf("\n");
	}
}
// void ghifile(int i){
//     FILE *p = fopen("D:\\NhutTrung_63135935\\lap1.txt", "w");
//     if(p==NULL)
//         printf("khong mo duoc file");
//     else{
        
//         fprintf(p, "vat thu: %d, gia tri: %d, trong luong %d")
//     }
// }

int main(){
    ReadFile();
    Dynammic2();
  //  Result();
  in();
    return 1;
}
