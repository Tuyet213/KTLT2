#include<stdio.h>
#define Tru(x,y)(x)-(y)

int main(){
	int a, b;
	printf("Nhap vao hai so a va b: ");
	scanf("%d%d", &a, &b);
	printf("%d", Tru( a + 2, b + 1));
	return 1;
}
