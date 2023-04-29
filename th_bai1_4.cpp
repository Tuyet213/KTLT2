#include<stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define HOANVI(a,b) {a^=b;b^=a;a^=b;}
//#define HOANVI(a,b) (a^=b,b^=a,a^=b)
//#define HOANVI(a,b) (a=a+b,b=a-b,b=a-b)
//#define HOANVI(a,b) {int temp=a; a=b; b=temp;})
// neu muon dung temp thi 3 tham so
inline int Tich(int a, int b){
	return a*b;
}
int tich(int a, int b){
	return a*b;
}
float tich(float a, float b){
	return a*b;
}
int main(){
	int a, b, cu, d;
	printf("Nhap gia tri a, b, c, d: ");
	scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("So lon nhat trong 4 so la: %d",MAX(MAX(a,b),MAX(c,d)));
	HOANVI(a,b);
	printf("\nHoan doi vi tri a va b: %d %d",a,b);
	printf("\nTich cua %d va %d la: %d",c,d,Tich(c,d));
	printf("\nTich 2 so nguyen: %d",tich(2,3));
	printf("\nTich 2 so thuc: %.2f",tich(2.5f,3.0f)); //them f vao de ra float, khong thi mac dinh la double
	return 1;
}
