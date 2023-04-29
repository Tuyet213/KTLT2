#include<stdio.h>
float DTB(float dqt, float dgk, float dck,float tlqt=0.3, float tlgk=0.3){
	return dqt*tlqt + dgk*tlgk + dck*(1-tlqt-tlgk);
}
int main(){
//	float tlqt, tlgk;
//	float dqt, dgk, dck;
//	printf("Nhap ti le diem qua trinh: ");
//	scanf("%f",&tlqt);
//	printf("Nhap ti le diem giua ky: ");
//	scanf("%f",&tlgk);
//	printf("Nhap diem qua trinh: ");
//	scanf("%f",&dqt);
//	printf("Nhap diem giua ky: ");
//	scanf("%f",&dgk);
//	printf("Nhap diem cuoi ky: ");
//	scanf("%f",&dck);
//	printf("Diem trung binh la: %.3f",DTB(dqt,dgk,dck,tlqt,tlgk));
	printf("Diem trung binh la: %.3f",DTB(10,10,5,0.2));
	return 1;
}
