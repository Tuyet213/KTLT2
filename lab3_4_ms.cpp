#include<stdio.h>
void move(int n, char from, char mid, char to){
	if(n==1) {
		printf("\nChuyen 1 dia tu %c sang %c",from, to);
		return ;
	}
	else{
		move(n-1,from,to,mid);
		move(1,from,mid,to);
		move(n-1,mid,from,to);
	}
} 
int main(){
	int n;
	char a='A',b='B',c='C';
	printf("Nhap n: ");
	scanf("%d",&n);
	move(n,a,b,c);
	return 1;
}
