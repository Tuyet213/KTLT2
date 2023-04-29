#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]){
	if(argc==4){
		int kq;
		int x = atoi(argv[2]);
		int y = atoi(argv[4]);
//		if(argv[3]=='+') 
		kq = x + y;
//		if(argv[3]=='-')  kq = x - y;
//		if(argv[3]=='*')  kq = x * y;
//		if(argv[3]=='/')  kq = x / y;
		printf("%d %c %d = %d", x, argv[3], y, kq);
	}
	else
		printf("NHap sai.");
}
