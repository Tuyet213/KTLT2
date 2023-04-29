#include<stdio.h>
#define Max(a,b) {a>b?a:b}
#define N 30
int a[] = {2,3,4,5,8,7};
int n;      //so luong phan tu
int L[N];   //luu do dai mang con tai vi tri i
int t[N];   //su dung mang t de luu vet
int p;

//khoi tao
void Init(){
    n = sizeof(a)/sizeof(a[0]);
    for(int i = 0; i<n; i++){
        L[i] = 1;
        t[i] = -1;
    }
}

//quy hoach dong
void Dynamic(){
    int lmax;
    for(int i = 0; i<n; i++){
        lmax = 0;
        for(int j = 0; j<i; j++)
            if(a[i] > a[j] && lmax < L[j]){
                lmax = L[j];
                t[i] = j;
            }
        L[i] = lmax + 1;
    }
}

//ket qua
void Result(){
    int m = L[0];
    p = 1;
    for(int i = 1; i<n; i++)
        if(m < L[i]){
            m = L[i];
            p = i;
        }
    printf("do dai lon nhat: %d\n", m);
    //cau b: lan nguoc
    while(p>=0){
        printf(" %d", a[p]); //gia tri phan tu toi chi so p
        p = t[p];
    }
}

//quet lai

int main(){
    Init();
    Dynamic();
    Result();
    return 0;
}
