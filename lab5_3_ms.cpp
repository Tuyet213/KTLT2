#include<stdio.h>
#define MAX 5
#define SWAP(a,b,c){c=a;a=b;b=c;}
float v[MAX];
//={4,7,10,2};//luu gia tri cac mon hang
float w[MAX];
//={5,3,6,4};//luu trong luong cac mon hang
float p[MAX];//luu don gia cac mon hang
int x[MAX];//nghiem
int n=4;//so luong cac mon hang
float S=9;

void innghiem(){
    for(int i=0;i<n;i++){
        if(x[i]>-1) printf("\nLay %d vat co trong luong %f gia tri %f",x[i],w[i],v[i]);
    }
}

void xuatmang(float a[], int n){
    printf("\n");
    for(int i=0;i<n;i++) printf("%f ",a[i]);
}

void nhapmang(float a[], int &n){
	for(int i=0;i<n;i++) scanf("%f",&a[i]);
}
void Greedy(){
    for(int i=0;i<n;i++) p[i]=v[i]/w[i];
    float temp;
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(p[i]<p[j]){
                SWAP(p[i],p[j],temp)
                SWAP(v[i],v[j],temp)
                SWAP(w[i],w[j],temp)
            }
    int i=0;
    float T=S;
    while(i<n&&T>0){
        int sl=0;
        if(T>=w[i]){
            sl=(int)T/w[i];
          //  x[i]=sl;
        }
        x[i]=sl;
        i++;
    }
    innghiem();
}



int main(){
 
 nhapmang(v,n);
 nhapmang(w,n);
   Greedy();
// for(int i=0;i<n;i++) p[i]=v[i]/w[i];
   xuatmang(v,n);
   xuatmang(w,n);
   xuatmang(p,n);
    return 1;
}
