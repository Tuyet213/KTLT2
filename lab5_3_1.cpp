#include<stdio.h>
#define MAX 50
#define SWAP(a, b, c){c=a; a=b; b=c;}

float v[]={4,7,10,2};//gia tri tung mon hang
float w[]={5,3,6,4};//trong luong tung mon hang
float p[MAX];//don gia tung mon hang = v/w
int x[MAX]; //nghiem cua bai toan (so luong vat thu i)
int n=sizeof(v)/sizeof(v[0]);
float T;
float s=9;//trong luong cai tui

void innghiem(){
	for(int i=0;i<n;i++)
		if(x[i]>0){
			printf("%d do vat co trong luong %f gia tri %f",x[i],w[i],v[i]);
		}
}

void init(){
	T=s;
	//tinh don gia
	for(int i=0;i<n;i++) p[i]=v[i]/w[i];
	//sap xep chieu giam dan
	float temp;
	for(int i=0;i<n-1;i++)
	for(int j=i+1;j<n;j++)
		if(p[i]<p[j]){
			SWAP(p[i],p[j],temp);
			SWAP(v[i],v[j],temp);
			SWAP(w[i],w[j],temp);
		}
}



void Greedy(){
	int i=0; //vat thu i
	while(T>0 && i<n){
		//chon ung vien tot nhat
		if(T>=w[i]){
			x[i]++;
			T-=w[i];
		} else i++;
	}
	innghiem();
}

int main(){
	init();
	Greedy();
	return 1;
}
